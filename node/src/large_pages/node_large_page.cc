// Copyright (C) 2018 Intel Corporation
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom
// the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
// OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.
//
// SPDX-License-Identifier: MIT

#include "node_large_page.h"

#include <cerrno>   // NOLINT(build/include)

// Besides returning ENOTSUP at runtime we do nothing if this define is missing.
#if defined(NODE_ENABLE_LARGE_CODE_PAGES) && NODE_ENABLE_LARGE_CODE_PAGES
#include "util.h"
#include "uv.h"

#include <fcntl.h>  // _O_RDWR
#include <sys/types.h>
#include <sys/mman.h>
#if defined(__FreeBSD__)
#include <sys/sysctl.h>
#include <sys/user.h>
#elif defined(__APPLE__)
#include <mach/vm_map.h>
#endif
#include <unistd.h>  // readlink

#include <climits>  // PATH_MAX
#include <clocale>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

// The functions in this file map the text segment of node into 2M pages.
// The algorithm is simple
// Find the text region of node binary in memory
// 1: Examine the /proc/self/maps to determine the currently mapped text
// region and obtain the start and end
// Modify the start to point to the very beginning of node text segment
// (from variable nodetext setup in ld.script)
// Align the address of start and end to Large Page Boundaries
//
// 2: Move the text region to large pages
// Map a new area and copy the original code there
// Use mmap using the start address with MAP_FIXED so we get exactly the
// same virtual address
// Use madvise with MADV_HUGEPAGE to use Anonymous 2M Pages
// If successful copy the code there and unmap the original region.

#if defined(__linux__)
extern "C" {
// This symbol must be declared weak because this file becomes part of all
// Node.js targets (like node_mksnapshot, node_mkcodecache, and cctest) and
// those files do not supply the symbol.
extern char __attribute__((weak)) __node_text_start;
extern char __start_lpstub;
}  // extern "C"
#endif  // defined(__linux__)

#endif  // defined(NODE_ENABLE_LARGE_CODE_PAGES) && NODE_ENABLE_LARGE_CODE_PAGES
namespace node {
#if defined(NODE_ENABLE_LARGE_CODE_PAGES) && NODE_ENABLE_LARGE_CODE_PAGES

namespace {

struct text_region {
  char* from;
  char* to;
  int   total_hugepages;
  bool  found_text_region;
};

static const size_t hps = 2L * 1024 * 1024;

static void PrintWarning(const char* warn) {
  fprintf(stderr, "Hugepages WARNING: %s\n", warn);
}

static void PrintSystemError(int error) {
  PrintWarning(strerror(error));
}

inline uintptr_t hugepage_align_up(uintptr_t addr) {
  return (((addr) + (hps) - 1) & ~((hps) - 1));
}

inline uintptr_t hugepage_align_down(uintptr_t addr) {
  return ((addr) & ~((hps) - 1));
}

// The format of the maps file is the following
// address           perms offset  dev   inode       pathname
// 00400000-00452000 r-xp 00000000 08:02 173521      /usr/bin/dbus-daemon
// This is also handling the case where the first line is not the binary.

struct text_region FindNodeTextRegion() {
  struct text_region nregion;
  nregion.found_text_region = false;
#if defined(__linux__)
  std::ifstream ifs;
  std::string map_line;
  std::string permission;
  std::string dev;
  char dash;
  uintptr_t start, end, offset, inode;
  uintptr_t node_text_start = reinterpret_cast<uintptr_t>(&__node_text_start);
  uintptr_t lpstub_start = reinterpret_cast<uintptr_t>(&__start_lpstub);

  ifs.open("/proc/self/maps");
  if (!ifs) {
    PrintWarning("could not open /proc/self/maps");
    return nregion;
  }

  while (std::getline(ifs, map_line)) {
    std::istringstream iss(map_line);
    iss >> std::hex >> start;
    iss >> dash;
    iss >> std::hex >> end;
    iss >> permission;
    iss >> offset;
    iss >> dev;
    iss >> inode;

    if (inode == 0)
      continue;

    std::string pathname;
    iss >> pathname;

    if (permission != "r-xp")
      continue;

    if (node_text_start < start || node_text_start >= end)
      continue;

    start = node_text_start;
    if (lpstub_start > start && lpstub_start <= end)
      end = lpstub_start;

    char* from = reinterpret_cast<char*>(hugepage_align_up(start));
    char* to = reinterpret_cast<char*>(hugepage_align_down(end));

    if (from >= to)
      break;

    size_t size = to - from;
    nregion.found_text_region = true;
    nregion.from = from;
    nregion.to = to;
    nregion.total_hugepages = size / hps;

    break;
  }

  ifs.close();
#elif defined(__FreeBSD__)
  std::string exename;
  {
    char selfexe[PATH_MAX];
    size_t count = sizeof(selfexe);
    if (uv_exepath(selfexe, &count))
      return nregion;

    exename = std::string(selfexe, count);
  }

  size_t numpg;
  int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_VMMAP, getpid()};
  const size_t miblen = arraysize(mib);
  if (sysctl(mib, miblen, nullptr, &numpg, nullptr, 0) == -1) {
    return nregion;
  }

  // Enough for struct kinfo_vmentry.
  numpg = numpg * 4 / 3;
  auto alg = std::vector<char>(numpg);

  if (sysctl(mib, miblen, alg.data(), &numpg, nullptr, 0) == -1) {
    return nregion;
  }

  char* start = alg.data();
  char* end = start + numpg;

  while (start < end) {
    kinfo_vmentry* entry = reinterpret_cast<kinfo_vmentry*>(start);
    const size_t cursz = entry->kve_structsize;
    if (cursz == 0) {
      break;
    }

    if (entry->kve_path[0] == '\0') {
      continue;
    }
    bool excmapping = ((entry->kve_protection & KVME_PROT_READ) &&
     (entry->kve_protection & KVME_PROT_EXEC));

    if (!strcmp(exename.c_str(), entry->kve_path) && excmapping) {
      char* estart =
        reinterpret_cast<char*>(hugepage_align_up(entry->kve_start));
      char* eend =
        reinterpret_cast<char*>(hugepage_align_down(entry->kve_end));
      size_t size = eend - estart;
      nregion.found_text_region = true;
      nregion.from = estart;
      nregion.to = eend;
      nregion.total_hugepages = size / hps;
      break;
    }
    start += cursz;
  }
#elif defined(__APPLE__)
  struct vm_region_submap_info_64 map;
  mach_msg_type_number_t count = VM_REGION_SUBMAP_INFO_COUNT_64;
  vm_address_t addr = 0UL;
  vm_size_t size = 0;
  natural_t depth = 1;

  while (true) {
    if (vm_region_recurse_64(mach_task_self(), &addr, &size, &depth,
                             reinterpret_cast<vm_region_info_64_t>(&map),
                             &count) != KERN_SUCCESS) {
      break;
    }

    if (map.is_submap) {
      depth++;
    } else {
      char* start = reinterpret_cast<char*>(hugepage_align_up(addr));
      char* end = reinterpret_cast<char*>(hugepage_align_down(addr+size));
      size_t esize = end - start;

      if (end > start && (map.protection & VM_PROT_READ) != 0 &&
          (map.protection & VM_PROT_EXECUTE) != 0) {
        nregion.found_text_region = true;
        nregion.from = start;
        nregion.to = end;
        nregion.total_hugepages = esize / hps;
        break;
      }

      addr += size;
      size = 0;
    }
  }
#endif
  return nregion;
}

#if defined(__linux__)
bool IsTransparentHugePagesEnabled() {
  std::ifstream ifs;

  ifs.open("/sys/kernel/mm/transparent_hugepage/enabled");
  if (!ifs) {
    PrintWarning("could not open /sys/kernel/mm/transparent_hugepage/enabled");
    return false;
  }

  std::string always, madvise;
  if (ifs.is_open()) {
    while (ifs >> always >> madvise) {}
  }
  ifs.close();

  return always == "[always]" || madvise == "[madvise]";
}
#elif defined(__FreeBSD__)
static bool IsSuperPagesEnabled() {
  // It is enabled by default on amd64.
  unsigned int super_pages = 0;
  size_t super_pages_length = sizeof(super_pages);
  return sysctlbyname("vm.pmap.pg_ps_enabled",
                      &super_pages,
                      &super_pages_length,
                      nullptr,
                      0) != -1 &&
         super_pages >= 1;
}
#endif

}  // End of anonymous namespace

// Moving the text region to large pages. We need to be very careful.
// 1: This function itself should not be moved.
// We use a gcc attributes
// (__section__) to put it outside the ".text" section
// (__aligned__) to align it at 2M boundary
// (__noline__) to not inline this function
// 2: This function should not call any function(s) that might be moved.
// a. map a new area and copy the original code there
// b. mmap using the start address with MAP_FIXED so we get exactly
//    the same virtual address (except on macOS).
// c. madvise with MADV_HUGEPAGE
// d. If successful copy the code there and unmap the original region
int
#if !defined(__APPLE__)
__attribute__((__section__("lpstub")))
#else
__attribute__((__section__("__TEXT,__lpstub")))
#endif
__attribute__((__aligned__(hps)))
__attribute__((__noinline__))
MoveTextRegionToLargePages(const text_region& r) {
  void* nmem = nullptr;
  void* tmem = nullptr;
  int ret = 0;

  size_t size = r.to - r.from;
  void* start = r.from;

  // Allocate temporary region preparing for copy.
  nmem = mmap(nullptr, size,
              PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (nmem == MAP_FAILED) {
    PrintSystemError(errno);
    return -1;
  }

  memcpy(nmem, r.from, size);

#if defined(__linux__)
// We already know the original page is r-xp
// (PROT_READ, PROT_EXEC, MAP_PRIVATE)
// We want PROT_WRITE because we are writing into it.
// We want it at the fixed address and we use MAP_FIXED.
  tmem = mmap(start, size,
              PROT_READ | PROT_WRITE | PROT_EXEC,
              MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1 , 0);
  if (tmem == MAP_FAILED) {
    PrintSystemError(errno);
    return -1;
  }

  ret = madvise(tmem, size, 14 /* MADV_HUGEPAGE */);
  if (ret == -1) {
    PrintSystemError(errno);
    ret = munmap(tmem, size);
    if (ret == -1) {
      PrintSystemError(errno);
    }
    if (-1 == munmap(nmem, size)) PrintSystemError(errno);
    return -1;
  }
  memcpy(start, nmem, size);
#elif defined(__FreeBSD__)
  tmem = mmap(start, size,
              PROT_READ | PROT_WRITE | PROT_EXEC,
              MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED |
              MAP_ALIGNED_SUPER, -1 , 0);
  if (tmem == MAP_FAILED) {
    PrintSystemError(errno);
    if (-1 == munmap(nmem, size)) PrintSystemError(errno);
    return -1;
  }
#elif defined(__APPLE__)
  // There is not enough room to reserve the mapping close
  // to the region address so we content to give a hint
  // without forcing the new address being closed to.
  // We explicitally gives all permission since we plan
  // to write into it.
  tmem = mmap(start, size,
              PROT_READ | PROT_WRITE | PROT_EXEC,
              MAP_PRIVATE | MAP_ANONYMOUS,
              VM_FLAGS_SUPERPAGE_SIZE_2MB, 0);
  if (tmem == MAP_FAILED) {
    PrintSystemError(errno);
    if (-1 == munmap(nmem, size)) PrintSystemError(errno);
    return -1;
  }
  memcpy(tmem, nmem, size);
  ret = mprotect(start, size, PROT_READ | PROT_WRITE | PROT_EXEC);
  if (ret == -1) {
    PrintSystemError(errno);
    ret = munmap(tmem, size);
    if (ret == -1) {
      PrintSystemError(errno);
    }
    if (-1 == munmap(nmem, size)) PrintSystemError(errno);
    return -1;
  }
  memcpy(start, tmem, size);
#endif

  ret = mprotect(start, size, PROT_READ | PROT_EXEC);
  if (ret == -1) {
    PrintSystemError(errno);
    ret = munmap(tmem, size);
    if (ret == -1) {
      PrintSystemError(errno);
    }
    if (-1 == munmap(nmem, size)) PrintSystemError(errno);
    return -1;
  }
  if (-1 == munmap(nmem, size)) PrintSystemError(errno);
  return ret;
}
#endif  // defined(NODE_ENABLE_LARGE_CODE_PAGES) && NODE_ENABLE_LARGE_CODE_PAGES

// This is the primary API called from main.
int MapStaticCodeToLargePages() {
#if defined(NODE_ENABLE_LARGE_CODE_PAGES) && NODE_ENABLE_LARGE_CODE_PAGES
  bool have_thp = false;
#if defined(__linux__)
  have_thp = IsTransparentHugePagesEnabled();
#elif defined(__FreeBSD__)
  have_thp = IsSuperPagesEnabled();
#elif defined(__APPLE__)
  // pse-36 flag is present in recent mac x64 products.
  have_thp = true;
#endif
  if (!have_thp)
    return EACCES;

  struct text_region r = FindNodeTextRegion();
  if (r.found_text_region == false)
    return ENOENT;

#if defined(__FreeBSD__)
  if (r.from < reinterpret_cast<void*>(&MoveTextRegionToLargePages))
    return -1;
#endif

  return MoveTextRegionToLargePages(r);
#else
  return ENOTSUP;
#endif
}

const char* LargePagesError(int status) {
  switch (status) {
    case ENOTSUP:
      return "Mapping to large pages is not supported.";

    case EACCES:
      return "Large pages are not enabled.";

    case ENOENT:
      return "failed to find text region";

    case -1:
      return "Mapping code to large pages failed. Reverting to default page "
          "size.";

    case 0:
      return "OK";

    default:
      return "Unknown error";
  }
}

}  // namespace node
