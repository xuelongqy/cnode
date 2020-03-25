cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)
cmake_policy(VERSION 2.8.8)
project(cctest)
set(configuration "Debug")
enable_language(ASM)
set(builddir "${CMAKE_CURRENT_BINARY_DIR}")
set(obj "${builddir}/obj")

set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)



#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_version#target
set(TARGET "v8_version")
set(TOOLSET "target")
add_custom_target(v8_version SOURCES)
set_target_properties(v8_version PROPERTIES EXCLUDE_FROM_ALL "FALSE")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_headers#target
set(TARGET "v8_headers")
set(TOOLSET "target")
list(APPEND v8_headers__other_srcs
  "deps/v8/include/v8-value-serializer-version.h"
  "deps/v8/include/v8-version-string.h"
  "deps/v8/include/v8-version.h")
add_custom_target(v8_headers SOURCES ${v8_headers__other_srcs})
set_target_properties(v8_headers PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(v8_headers
  v8_version
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_shared_internal_headers#target
set(TARGET "v8_shared_internal_headers")
set(TOOLSET "target")
list(APPEND v8_shared_internal_headers__other_srcs
  "deps/v8/include/v8-internal.h"
  "deps/v8/include/v8.h"
  "deps/v8/include/v8config.h"
  "deps/v8/include/v8-wasm-trap-handler-posix.h"
  "deps/v8/include/v8-wasm-trap-handler-win.h")
add_custom_target(v8_shared_internal_headers SOURCES ${v8_shared_internal_headers__other_srcs})
set_target_properties(v8_shared_internal_headers PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(v8_shared_internal_headers
  v8_headers
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_libbase#target
set(TARGET "v8_libbase")
set(TOOLSET "target")
list(APPEND v8_libbase__cxx_srcs
  "deps/v8/src/base/bits.cc"
  "deps/v8/src/base/bounded-page-allocator.cc"
  "deps/v8/src/base/cpu.cc"
  "deps/v8/src/base/debug/stack_trace.cc"
  "deps/v8/src/base/division-by-constant.cc"
  "deps/v8/src/base/file-utils.cc"
  "deps/v8/src/base/functional.cc"
  "deps/v8/src/base/ieee754.cc"
  "deps/v8/src/base/logging.cc"
  "deps/v8/src/base/once.cc"
  "deps/v8/src/base/page-allocator.cc"
  "deps/v8/src/base/platform/condition-variable.cc"
  "deps/v8/src/base/platform/mutex.cc"
  "deps/v8/src/base/platform/semaphore.cc"
  "deps/v8/src/base/platform/time.cc"
  "deps/v8/src/base/region-allocator.cc"
  "deps/v8/src/base/sys-info.cc"
  "deps/v8/src/base/utils/random-number-generator.cc"
  "deps/v8/src/base/vlq-base64.cc"
  "deps/v8/src/base/platform/platform-posix.cc"
  "deps/v8/src/base/platform/platform-posix-time.cc"
  "deps/v8/src/base/debug/stack_trace_posix.cc"
  "deps/v8/src/base/platform/platform-macos.cc")
list(APPEND v8_libbase__other_srcs
  "deps/v8/src/base/address-region.h"
  "deps/v8/src/base/atomic-utils.h"
  "deps/v8/src/base/atomicops.h"
  "deps/v8/src/base/atomicops_internals_atomicword_compat.h"
  "deps/v8/src/base/atomicops_internals_portable.h"
  "deps/v8/src/base/atomicops_internals_std.h"
  "deps/v8/src/base/base-export.h"
  "deps/v8/src/base/bits.h"
  "deps/v8/src/base/bounded-page-allocator.h"
  "deps/v8/src/base/build_config.h"
  "deps/v8/src/base/compiler-specific.h"
  "deps/v8/src/base/cpu.h"
  "deps/v8/src/base/debug/stack_trace.h"
  "deps/v8/src/base/division-by-constant.h"
  "deps/v8/src/base/enum-set.h"
  "deps/v8/src/base/export-template.h"
  "deps/v8/src/base/file-utils.h"
  "deps/v8/src/base/flags.h"
  "deps/v8/src/base/free_deleter.h"
  "deps/v8/src/base/functional.h"
  "deps/v8/src/base/hashmap-entry.h"
  "deps/v8/src/base/hashmap.h"
  "deps/v8/src/base/ieee754.h"
  "deps/v8/src/base/iterator.h"
  "deps/v8/src/base/lazy-instance.h"
  "deps/v8/src/base/list.h"
  "deps/v8/src/base/logging.h"
  "deps/v8/src/base/lsan.h"
  "deps/v8/src/base/macros.h"
  "deps/v8/src/base/memory.h"
  "deps/v8/src/base/once.h"
  "deps/v8/src/base/optional.h"
  "deps/v8/src/base/overflowing-math.h"
  "deps/v8/src/base/page-allocator.h"
  "deps/v8/src/base/platform/condition-variable.h"
  "deps/v8/src/base/platform/elapsed-timer.h"
  "deps/v8/src/base/platform/mutex.h"
  "deps/v8/src/base/platform/platform.h"
  "deps/v8/src/base/platform/semaphore.h"
  "deps/v8/src/base/platform/time.h"
  "deps/v8/src/base/region-allocator.h"
  "deps/v8/src/base/ring-buffer.h"
  "deps/v8/src/base/safe_conversions.h"
  "deps/v8/src/base/safe_conversions_impl.h"
  "deps/v8/src/base/small-vector.h"
  "deps/v8/src/base/sys-info.h"
  "deps/v8/src/base/template-utils.h"
  "deps/v8/src/base/timezone-cache.h"
  "deps/v8/src/base/type-traits.h"
  "deps/v8/src/base/utils/random-number-generator.h"
  "deps/v8/src/base/vlq-base64.h"
  "deps/v8/src/base/platform/platform-posix.h"
  "deps/v8/src/base/platform/platform-posix-time.h"
  "deps/v8/include/v8-internal.h"
  "deps/v8/include/v8.h"
  "deps/v8/include/v8config.h"
  "deps/v8/include/v8-wasm-trap-handler-posix.h"
  "deps/v8/include/v8-wasm-trap-handler-win.h")
add_library(v8_libbase STATIC ${v8_libbase__cxx_srcs} ${v8_libbase__other_srcs})
set_target_properties(v8_libbase PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${v8_libbase__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(v8_libbase PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(v8_libbase PROPERTIES PREFIX "lib")
set_target_properties(v8_libbase PROPERTIES ARCHIVE_OUTPUT_NAME "v8_libbase")
set_target_properties(v8_libbase PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libv8_libbase.a PROPERTIES GENERATED "TRUE")
list(APPEND v8_libbase__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include")
set_property(TARGET v8_libbase APPEND PROPERTY INCLUDE_DIRECTORIES ${v8_libbase__include_dirs})
set_target_properties(v8_libbase PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;BUILDING_V8_BASE_SHARED;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(v8_libbase PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(v8_libbase PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(v8_libbase
  v8_headers
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_libsampler#target
set(TARGET "v8_libsampler")
set(TOOLSET "target")
set(v8_libsampler__cxx_srcs "deps/v8/src/libsampler/sampler.cc")
set(v8_libsampler__other_srcs "deps/v8/src/libsampler/sampler.h")
add_library(v8_libsampler STATIC ${v8_libsampler__cxx_srcs} ${v8_libsampler__other_srcs})
set_target_properties(v8_libsampler PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${v8_libsampler__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(v8_libsampler PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(v8_libsampler PROPERTIES PREFIX "lib")
set_target_properties(v8_libsampler PROPERTIES ARCHIVE_OUTPUT_NAME "v8_libsampler")
set_target_properties(v8_libsampler PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libv8_libsampler.a PROPERTIES GENERATED "TRUE")
list(APPEND v8_libsampler__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include")
set_property(TARGET v8_libsampler APPEND PROPERTY INCLUDE_DIRECTORIES ${v8_libsampler__include_dirs})
set_target_properties(v8_libsampler PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(v8_libsampler PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(v8_libsampler PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_libplatform#target
set(TARGET "v8_libplatform")
set(TOOLSET "target")
list(APPEND v8_libplatform__cxx_srcs
  "deps/v8/src/libplatform/default-foreground-task-runner.cc"
  "deps/v8/src/libplatform/default-platform.cc"
  "deps/v8/src/libplatform/default-worker-threads-task-runner.cc"
  "deps/v8/src/libplatform/delayed-task-queue.cc"
  "deps/v8/src/libplatform/task-queue.cc"
  "deps/v8/src/libplatform/tracing/trace-buffer.cc"
  "deps/v8/src/libplatform/tracing/trace-config.cc"
  "deps/v8/src/libplatform/tracing/trace-object.cc"
  "deps/v8/src/libplatform/tracing/trace-writer.cc"
  "deps/v8/src/libplatform/tracing/tracing-controller.cc"
  "deps/v8/src/libplatform/worker-thread.cc")
list(APPEND v8_libplatform__other_srcs
  "deps/v8/base/trace_event/common/trace_event_common.h"
  "deps/v8/include/libplatform/libplatform-export.h"
  "deps/v8/include/libplatform/libplatform.h"
  "deps/v8/include/libplatform/v8-tracing.h"
  "deps/v8/src/libplatform/default-foreground-task-runner.h"
  "deps/v8/src/libplatform/default-platform.h"
  "deps/v8/src/libplatform/default-worker-threads-task-runner.h"
  "deps/v8/src/libplatform/delayed-task-queue.h"
  "deps/v8/src/libplatform/task-queue.h"
  "deps/v8/src/libplatform/tracing/trace-buffer.h"
  "deps/v8/src/libplatform/tracing/trace-writer.h"
  "deps/v8/src/libplatform/worker-thread.h")
add_library(v8_libplatform STATIC ${v8_libplatform__cxx_srcs} ${v8_libplatform__other_srcs})
set_target_properties(v8_libplatform PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${v8_libplatform__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(v8_libplatform PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(v8_libplatform PROPERTIES PREFIX "lib")
set_target_properties(v8_libplatform PROPERTIES ARCHIVE_OUTPUT_NAME "v8_libplatform")
set_target_properties(v8_libplatform PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libv8_libplatform.a PROPERTIES GENERATED "TRUE")
list(APPEND v8_libplatform__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include")
set_property(TARGET v8_libplatform APPEND PROPERTY INCLUDE_DIRECTORIES ${v8_libplatform__include_dirs})
set_target_properties(v8_libplatform PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(v8_libplatform PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(v8_libplatform PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:torque_base#target
set(TARGET "torque_base")
set(TOOLSET "target")
list(APPEND torque_base__cxx_srcs
  "deps/v8/src/torque/cfg.cc"
  "deps/v8/src/torque/class-debug-reader-generator.cc"
  "deps/v8/src/torque/csa-generator.cc"
  "deps/v8/src/torque/declarable.cc"
  "deps/v8/src/torque/declaration-visitor.cc"
  "deps/v8/src/torque/declarations.cc"
  "deps/v8/src/torque/earley-parser.cc"
  "deps/v8/src/torque/global-context.cc"
  "deps/v8/src/torque/implementation-visitor.cc"
  "deps/v8/src/torque/instance-type-generator.cc"
  "deps/v8/src/torque/instructions.cc"
  "deps/v8/src/torque/server-data.cc"
  "deps/v8/src/torque/source-positions.cc"
  "deps/v8/src/torque/torque-compiler.cc"
  "deps/v8/src/torque/torque-parser.cc"
  "deps/v8/src/torque/type-inference.cc"
  "deps/v8/src/torque/type-oracle.cc"
  "deps/v8/src/torque/type-visitor.cc"
  "deps/v8/src/torque/types.cc"
  "deps/v8/src/torque/utils.cc")
list(APPEND torque_base__other_srcs
  "deps/v8/src/torque/ast.h"
  "deps/v8/src/torque/cfg.h"
  "deps/v8/src/torque/constants.h"
  "deps/v8/src/torque/contextual.h"
  "deps/v8/src/torque/csa-generator.h"
  "deps/v8/src/torque/declarable.h"
  "deps/v8/src/torque/declaration-visitor.h"
  "deps/v8/src/torque/declarations.h"
  "deps/v8/src/torque/earley-parser.h"
  "deps/v8/src/torque/global-context.h"
  "deps/v8/src/torque/implementation-visitor.h"
  "deps/v8/src/torque/instructions.h"
  "deps/v8/src/torque/server-data.h"
  "deps/v8/src/torque/source-positions.h"
  "deps/v8/src/torque/torque-compiler.h"
  "deps/v8/src/torque/torque-parser.h"
  "deps/v8/src/torque/type-inference.h"
  "deps/v8/src/torque/type-oracle.h"
  "deps/v8/src/torque/type-visitor.h"
  "deps/v8/src/torque/types.h"
  "deps/v8/src/torque/utils.h"
  "deps/v8/src/common/globals.h")
add_library(torque_base STATIC ${torque_base__cxx_srcs} ${torque_base__other_srcs})
set_target_properties(torque_base PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${torque_base__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(torque_base PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(torque_base PROPERTIES PREFIX "lib")
set_target_properties(torque_base PROPERTIES ARCHIVE_OUTPUT_NAME "torque_base")
set_target_properties(torque_base PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libtorque_base.a PROPERTIES GENERATED "TRUE")
list(APPEND torque_base__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include")
set_property(TARGET torque_base APPEND PROPERTY INCLUDE_DIRECTORIES ${torque_base__include_dirs})
set_target_properties(torque_base PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(torque_base PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-strict-aliasing ")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "YES")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(torque_base PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(torque_base
  v8_shared_internal_headers
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:torque_ls_base#target
set(TARGET "torque_ls_base")
set(TOOLSET "target")
list(APPEND torque_ls_base__cxx_srcs
  "deps/v8/src/torque/ls/json-parser.cc"
  "deps/v8/src/torque/ls/json.cc"
  "deps/v8/src/torque/ls/message-handler.cc")
list(APPEND torque_ls_base__other_srcs
  "deps/v8/src/torque/ls/globals.h"
  "deps/v8/src/torque/ls/json-parser.h"
  "deps/v8/src/torque/ls/json.h"
  "deps/v8/src/torque/ls/message-handler.h"
  "deps/v8/src/torque/ls/message-macros.h"
  "deps/v8/src/torque/ls/message-pipe.h"
  "deps/v8/src/torque/ls/message.h")
add_library(torque_ls_base STATIC ${torque_ls_base__cxx_srcs} ${torque_ls_base__other_srcs})
set_target_properties(torque_ls_base PROPERTIES EXCLUDE_FROM_ALL "TRUE")
set_source_files_properties(${torque_ls_base__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(torque_ls_base PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(torque_ls_base PROPERTIES PREFIX "lib")
set_target_properties(torque_ls_base PROPERTIES ARCHIVE_OUTPUT_NAME "torque_ls_base")
set_target_properties(torque_ls_base PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libtorque_ls_base.a PROPERTIES GENERATED "TRUE")
list(APPEND torque_ls_base__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include")
set_property(TARGET torque_ls_base APPEND PROPERTY INCLUDE_DIRECTORIES ${torque_ls_base__include_dirs})
set_target_properties(torque_ls_base PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(torque_ls_base PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-strict-aliasing ")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "YES")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(torque_ls_base PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:torque-language-server#target
set(TARGET "torque-language-server")
set(TOOLSET "target")
set(torque-language-server__cxx_srcs "deps/v8/src/torque/ls/torque-language-server.cc")
add_executable(torque-language-server ${torque-language-server__cxx_srcs})
set_target_properties(torque-language-server PROPERTIES EXCLUDE_FROM_ALL "TRUE")
set_target_properties(torque-language-server PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(torque-language-server PROPERTIES PREFIX "")
set_target_properties(torque-language-server PROPERTIES RUNTIME_OUTPUT_NAME "torque-language-server")
set_target_properties(torque-language-server PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/torque-language-server PROPERTIES GENERATED "TRUE")
list(APPEND torque-language-server__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include")
set_property(TARGET torque-language-server APPEND PROPERTY INCLUDE_DIRECTORIES ${torque-language-server__include_dirs})
set_target_properties(torque-language-server PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(torque-language-server PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(torque-language-server PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(torque-language-server
  v8_shared_internal_headers
  v8_headers
  v8_version
)
target_link_libraries(torque-language-server
  torque_base
  torque_ls_base
  v8_libbase
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:torque#target
set(TARGET "torque")
set(TOOLSET "target")
set(torque__cxx_srcs "deps/v8/src/torque/torque.cc")
add_executable(torque ${torque__cxx_srcs})
set_target_properties(torque PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(torque PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(torque PROPERTIES PREFIX "")
set_target_properties(torque PROPERTIES RUNTIME_OUTPUT_NAME "torque")
set_target_properties(torque PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/torque PROPERTIES GENERATED "TRUE")
list(APPEND torque__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include")
set_property(TARGET torque APPEND PROPERTY INCLUDE_DIRECTORIES ${torque__include_dirs})
set_target_properties(torque PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(torque PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-strict-aliasing ")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "YES")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(torque PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(torque
  v8_shared_internal_headers
  v8_headers
  v8_version
)
target_link_libraries(torque
  torque_base
  v8_libbase
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:run_torque#target
set(TARGET "run_torque")
set(TOOLSET "target")
list(APPEND run_torque__run_torque_action__input
  "${builddir}/torque"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/arguments.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-copywithin.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-every.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-filter.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-find.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-findindex.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-foreach.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-join.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-lastindexof.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-map.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-of.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-reduce-right.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-reduce.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-reverse.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-shift.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-slice.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-some.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-splice.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array-unshift.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/array.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/base.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/bigint.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/boolean.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/collections.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/data-view.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/extras-utils.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/frames.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/growable-fixed-array.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/internal-coverage.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/iterator.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/math.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/object-fromentries.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/object.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/proxy-constructor.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/proxy-delete-property.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/proxy-get-property.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/proxy-get-prototype-of.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/proxy-has-property.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/proxy-is-extensible.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/proxy-prevent-extensions.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/proxy-revocable.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/proxy-revoke.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/proxy-set-property.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/proxy-set-prototype-of.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/proxy.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/reflect.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/regexp-exec.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/regexp-match-all.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/regexp-match.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/regexp-replace.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/regexp-search.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/regexp-source.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/regexp-split.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/regexp-test.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/regexp.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/string.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/string-endswith.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/string-html.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/string-iterator.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/string-pad.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/string-repeat.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/string-slice.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/string-startswith.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/string-substring.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/torque-internal.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/typed-array-createtypedarray.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/typed-array-every.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/typed-array-filter.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/typed-array-find.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/typed-array-findindex.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/typed-array-foreach.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/typed-array-reduce.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/typed-array-reduceright.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/typed-array-slice.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/typed-array-some.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/typed-array-subarray.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/builtins/typed-array.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/v8/builtins/array-sort.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/test/torque/test-torque.tq"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/intl-objects.tq")
list(APPEND run_torque__run_torque_action__output
  "${obj}/gen/torque-output-root/torque-generated/builtin-definitions-tq.h"
  "${obj}/gen/torque-output-root/torque-generated/interface-descriptors-tq.inc"
  "${obj}/gen/torque-output-root/torque-generated/field-offsets-tq.h"
  "${obj}/gen/torque-output-root/torque-generated/class-verifiers-tq.cc"
  "${obj}/gen/torque-output-root/torque-generated/class-verifiers-tq.h"
  "${obj}/gen/torque-output-root/torque-generated/objects-printer-tq.cc"
  "${obj}/gen/torque-output-root/torque-generated/class-definitions-tq.cc"
  "${obj}/gen/torque-output-root/torque-generated/class-definitions-tq-inl.h"
  "${obj}/gen/torque-output-root/torque-generated/class-definitions-tq.h"
  "${obj}/gen/torque-output-root/torque-generated/class-debug-readers-tq.cc"
  "${obj}/gen/torque-output-root/torque-generated/class-debug-readers-tq.h"
  "${obj}/gen/torque-output-root/torque-generated/exported-macros-assembler-tq.cc"
  "${obj}/gen/torque-output-root/torque-generated/exported-macros-assembler-tq.h"
  "${obj}/gen/torque-output-root/torque-generated/csa-types-tq.h"
  "${obj}/gen/torque-output-root/torque-generated/instance-types-tq.h"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/arguments-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-copywithin-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-every-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-filter-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-find-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-findindex-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-foreach-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-join-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-lastindexof-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-map-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-of-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-reduce-right-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-reduce-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-reverse-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-shift-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-slice-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-some-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-splice-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-unshift-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/base-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/bigint-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/boolean-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/collections-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/data-view-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/extras-utils-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/frames-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/growable-fixed-array-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/internal-coverage-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/iterator-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/math-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/object-fromentries-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/object-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-constructor-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-delete-property-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-get-property-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-get-prototype-of-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-has-property-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-is-extensible-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-prevent-extensions-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-revocable-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-revoke-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-set-property-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-set-prototype-of-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/reflect-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-exec-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-match-all-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-match-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-replace-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-search-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-source-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-split-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-test-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-endswith-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-html-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-iterator-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-pad-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-repeat-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-slice-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-startswith-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-substring-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/torque-internal-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-createtypedarray-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-every-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-filter-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-find-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-findindex-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-foreach-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-reduce-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-reduceright-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-slice-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-some-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-subarray-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/third_party/v8/builtins/array-sort-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/test/torque/test-torque-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/objects/intl-objects-tq-csa.cc")
add_custom_command(OUTPUT ${run_torque__run_torque_action__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/objects
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen/torque-output-root/torque-generated/../../deps/v8/third_party/v8/builtins
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen/torque-output-root/torque-generated
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen/torque-output-root/torque-generated/../../deps/v8/test/torque
  COMMAND "${builddir}/torque" ../../deps/v8/src/builtins/arguments.tq ../../deps/v8/src/builtins/array-copywithin.tq ../../deps/v8/src/builtins/array-every.tq ../../deps/v8/src/builtins/array-filter.tq ../../deps/v8/src/builtins/array-find.tq ../../deps/v8/src/builtins/array-findindex.tq ../../deps/v8/src/builtins/array-foreach.tq ../../deps/v8/src/builtins/array-join.tq ../../deps/v8/src/builtins/array-lastindexof.tq ../../deps/v8/src/builtins/array-map.tq ../../deps/v8/src/builtins/array-of.tq ../../deps/v8/src/builtins/array-reduce-right.tq ../../deps/v8/src/builtins/array-reduce.tq ../../deps/v8/src/builtins/array-reverse.tq ../../deps/v8/src/builtins/array-shift.tq ../../deps/v8/src/builtins/array-slice.tq ../../deps/v8/src/builtins/array-some.tq ../../deps/v8/src/builtins/array-splice.tq ../../deps/v8/src/builtins/array-unshift.tq ../../deps/v8/src/builtins/array.tq ../../deps/v8/src/builtins/base.tq ../../deps/v8/src/builtins/bigint.tq ../../deps/v8/src/builtins/boolean.tq ../../deps/v8/src/builtins/collections.tq ../../deps/v8/src/builtins/data-view.tq ../../deps/v8/src/builtins/extras-utils.tq ../../deps/v8/src/builtins/frames.tq ../../deps/v8/src/builtins/growable-fixed-array.tq ../../deps/v8/src/builtins/internal-coverage.tq ../../deps/v8/src/builtins/iterator.tq ../../deps/v8/src/builtins/math.tq ../../deps/v8/src/builtins/object-fromentries.tq ../../deps/v8/src/builtins/object.tq ../../deps/v8/src/builtins/proxy-constructor.tq ../../deps/v8/src/builtins/proxy-delete-property.tq ../../deps/v8/src/builtins/proxy-get-property.tq ../../deps/v8/src/builtins/proxy-get-prototype-of.tq ../../deps/v8/src/builtins/proxy-has-property.tq ../../deps/v8/src/builtins/proxy-is-extensible.tq ../../deps/v8/src/builtins/proxy-prevent-extensions.tq ../../deps/v8/src/builtins/proxy-revocable.tq ../../deps/v8/src/builtins/proxy-revoke.tq ../../deps/v8/src/builtins/proxy-set-property.tq ../../deps/v8/src/builtins/proxy-set-prototype-of.tq ../../deps/v8/src/builtins/proxy.tq ../../deps/v8/src/builtins/reflect.tq ../../deps/v8/src/builtins/regexp-exec.tq ../../deps/v8/src/builtins/regexp-match-all.tq ../../deps/v8/src/builtins/regexp-match.tq ../../deps/v8/src/builtins/regexp-replace.tq ../../deps/v8/src/builtins/regexp-search.tq ../../deps/v8/src/builtins/regexp-source.tq ../../deps/v8/src/builtins/regexp-split.tq ../../deps/v8/src/builtins/regexp-test.tq ../../deps/v8/src/builtins/regexp.tq ../../deps/v8/src/builtins/string.tq ../../deps/v8/src/builtins/string-endswith.tq ../../deps/v8/src/builtins/string-html.tq ../../deps/v8/src/builtins/string-iterator.tq ../../deps/v8/src/builtins/string-pad.tq ../../deps/v8/src/builtins/string-repeat.tq ../../deps/v8/src/builtins/string-slice.tq ../../deps/v8/src/builtins/string-startswith.tq ../../deps/v8/src/builtins/string-substring.tq ../../deps/v8/src/builtins/torque-internal.tq ../../deps/v8/src/builtins/typed-array-createtypedarray.tq ../../deps/v8/src/builtins/typed-array-every.tq ../../deps/v8/src/builtins/typed-array-filter.tq ../../deps/v8/src/builtins/typed-array-find.tq ../../deps/v8/src/builtins/typed-array-findindex.tq ../../deps/v8/src/builtins/typed-array-foreach.tq ../../deps/v8/src/builtins/typed-array-reduce.tq ../../deps/v8/src/builtins/typed-array-reduceright.tq ../../deps/v8/src/builtins/typed-array-slice.tq ../../deps/v8/src/builtins/typed-array-some.tq ../../deps/v8/src/builtins/typed-array-subarray.tq ../../deps/v8/src/builtins/typed-array.tq ../../deps/v8/third_party/v8/builtins/array-sort.tq ../../deps/v8/test/torque/test-torque.tq ../../deps/v8/src/objects/intl-objects.tq -o "${obj}/gen/torque-output-root/torque-generated" -v8-root ../../deps/v8
  DEPENDS ${run_torque__run_torque_action__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tools/v8_gypfiles
  COMMENT run_torque__run_torque_action
  VERBATIM
)
add_custom_target(run_torque__run_torque_action
  DEPENDS ${run_torque__run_torque_action__output}
  SOURCES ${run_torque__run_torque_action__input}
)
add_custom_target(run_torque SOURCES)
set_target_properties(run_torque PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(run_torque__run_torque_action PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(run_torque__run_torque_action
  torque
)
add_dependencies(run_torque
  torque
  run_torque__run_torque_action
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:postmortem-metadata#target
set(TARGET "postmortem-metadata")
set(TOOLSET "target")
list(APPEND postmortem-metadata__gen-postmortem-metadata__input
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/gen-postmortem-metadata.py"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/objects.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/objects-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/allocation-site-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/allocation-site.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/cell-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/cell.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/code-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/code.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/data-handler.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/data-handler-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/descriptor-array.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/descriptor-array-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/feedback-cell.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/feedback-cell-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/fixed-array-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/fixed-array.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/heap-number-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/heap-number.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/heap-object-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/heap-object.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/instance-type.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-array-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-array.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-array-buffer-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-array-buffer.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-objects-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-objects.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-promise-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-promise.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-regexp-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-regexp.cc"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-regexp.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-regexp-string-iterator-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-regexp-string-iterator.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/map.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/map.cc"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/map-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/js-objects.cc"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/name.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/name-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/oddball-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/oddball.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/primitive-heap-object.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/primitive-heap-object-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/scope-info.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/script.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/script-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/shared-function-info.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/shared-function-info-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/string.cc"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/string.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/string-comparator.cc"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/string-comparator.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/string-inl.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/struct.h"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/objects/struct-inl.h"
  "${obj}/gen/torque-output-root/torque-generated/instance-types-tq.h")
set(postmortem-metadata__gen-postmortem-metadata__output "${obj}/gen/debug-support.cc")
add_custom_command(OUTPUT ${postmortem-metadata__gen-postmortem-metadata__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen
  COMMAND python ../../deps/v8/tools/gen-postmortem-metadata.py "${obj}/gen/debug-support.cc" ../../deps/v8/src/objects/objects.h ../../deps/v8/src/objects/objects-inl.h ../../deps/v8/src/objects/allocation-site-inl.h ../../deps/v8/src/objects/allocation-site.h ../../deps/v8/src/objects/cell-inl.h ../../deps/v8/src/objects/cell.h ../../deps/v8/src/objects/code-inl.h ../../deps/v8/src/objects/code.h ../../deps/v8/src/objects/data-handler.h ../../deps/v8/src/objects/data-handler-inl.h ../../deps/v8/src/objects/descriptor-array.h ../../deps/v8/src/objects/descriptor-array-inl.h ../../deps/v8/src/objects/feedback-cell.h ../../deps/v8/src/objects/feedback-cell-inl.h ../../deps/v8/src/objects/fixed-array-inl.h ../../deps/v8/src/objects/fixed-array.h ../../deps/v8/src/objects/heap-number-inl.h ../../deps/v8/src/objects/heap-number.h ../../deps/v8/src/objects/heap-object-inl.h ../../deps/v8/src/objects/heap-object.h ../../deps/v8/src/objects/instance-type.h ../../deps/v8/src/objects/js-array-inl.h ../../deps/v8/src/objects/js-array.h ../../deps/v8/src/objects/js-array-buffer-inl.h ../../deps/v8/src/objects/js-array-buffer.h ../../deps/v8/src/objects/js-objects-inl.h ../../deps/v8/src/objects/js-objects.h ../../deps/v8/src/objects/js-promise-inl.h ../../deps/v8/src/objects/js-promise.h ../../deps/v8/src/objects/js-regexp-inl.h ../../deps/v8/src/objects/js-regexp.cc ../../deps/v8/src/objects/js-regexp.h ../../deps/v8/src/objects/js-regexp-string-iterator-inl.h ../../deps/v8/src/objects/js-regexp-string-iterator.h ../../deps/v8/src/objects/map.h ../../deps/v8/src/objects/map.cc ../../deps/v8/src/objects/map-inl.h ../../deps/v8/src/objects/js-objects.cc ../../deps/v8/src/objects/name.h ../../deps/v8/src/objects/name-inl.h ../../deps/v8/src/objects/oddball-inl.h ../../deps/v8/src/objects/oddball.h ../../deps/v8/src/objects/primitive-heap-object.h ../../deps/v8/src/objects/primitive-heap-object-inl.h ../../deps/v8/src/objects/scope-info.h ../../deps/v8/src/objects/script.h ../../deps/v8/src/objects/script-inl.h ../../deps/v8/src/objects/shared-function-info.h ../../deps/v8/src/objects/shared-function-info-inl.h ../../deps/v8/src/objects/string.cc ../../deps/v8/src/objects/string.h ../../deps/v8/src/objects/string-comparator.cc ../../deps/v8/src/objects/string-comparator.h ../../deps/v8/src/objects/string-inl.h ../../deps/v8/src/objects/struct.h ../../deps/v8/src/objects/struct-inl.h "${obj}/gen/torque-output-root/torque-generated/instance-types-tq.h"
  DEPENDS ${postmortem-metadata__gen-postmortem-metadata__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tools/v8_gypfiles
  COMMENT postmortem-metadata__gen-postmortem-metadata
  VERBATIM
)
add_custom_target(postmortem-metadata__gen-postmortem-metadata
  DEPENDS ${postmortem-metadata__gen-postmortem-metadata__output}
  SOURCES ${postmortem-metadata__gen-postmortem-metadata__input}
)
add_custom_target(postmortem-metadata SOURCES)
set_target_properties(postmortem-metadata PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(postmortem-metadata__gen-postmortem-metadata PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(postmortem-metadata__gen-postmortem-metadata
  run_torque
)
add_dependencies(postmortem-metadata
  run_torque
  postmortem-metadata__gen-postmortem-metadata
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:bytecode_builtins_list_generator#target
set(TARGET "bytecode_builtins_list_generator")
set(TOOLSET "target")
list(APPEND bytecode_builtins_list_generator__cxx_srcs
  "deps/v8/src/builtins/generate-bytecodes-builtins-list.cc"
  "deps/v8/src/interpreter/bytecode-operands.cc"
  "deps/v8/src/interpreter/bytecodes.cc")
list(APPEND bytecode_builtins_list_generator__other_srcs
  "deps/v8/src/interpreter/bytecode-operands.h"
  "deps/v8/src/interpreter/bytecodes.h")
add_executable(bytecode_builtins_list_generator ${bytecode_builtins_list_generator__cxx_srcs} ${bytecode_builtins_list_generator__other_srcs})
set_target_properties(bytecode_builtins_list_generator PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${bytecode_builtins_list_generator__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(bytecode_builtins_list_generator PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(bytecode_builtins_list_generator PROPERTIES PREFIX "")
set_target_properties(bytecode_builtins_list_generator PROPERTIES RUNTIME_OUTPUT_NAME "bytecode_builtins_list_generator")
set_target_properties(bytecode_builtins_list_generator PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/bytecode_builtins_list_generator PROPERTIES GENERATED "TRUE")
list(APPEND bytecode_builtins_list_generator__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include")
set_property(TARGET bytecode_builtins_list_generator APPEND PROPERTY INCLUDE_DIRECTORIES ${bytecode_builtins_list_generator__include_dirs})
set_target_properties(bytecode_builtins_list_generator PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(bytecode_builtins_list_generator PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(bytecode_builtins_list_generator PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(bytecode_builtins_list_generator
  v8_headers
  v8_version
)
target_link_libraries(bytecode_builtins_list_generator
  v8_libbase
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:generate_bytecode_builtins_list#target
set(TARGET "generate_bytecode_builtins_list")
set(TOOLSET "target")
set(generate_bytecode_builtins_list__generate_bytecode_builtins_list_action__input "${builddir}/bytecode_builtins_list_generator")
set(generate_bytecode_builtins_list__generate_bytecode_builtins_list_action__output "${obj}/gen/generate-bytecode-output-root/builtins-generated/bytecodes-builtins-list.h")
add_custom_command(OUTPUT ${generate_bytecode_builtins_list__generate_bytecode_builtins_list_action__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen/generate-bytecode-output-root/builtins-generated
  COMMAND python ../../deps/v8/tools/run.py "${builddir}/bytecode_builtins_list_generator" "${obj}/gen/generate-bytecode-output-root/builtins-generated/bytecodes-builtins-list.h"
  DEPENDS ${generate_bytecode_builtins_list__generate_bytecode_builtins_list_action__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tools/v8_gypfiles
  COMMENT generate_bytecode_builtins_list__generate_bytecode_builtins_list_action
  VERBATIM
)
add_custom_target(generate_bytecode_builtins_list__generate_bytecode_builtins_list_action
  DEPENDS ${generate_bytecode_builtins_list__generate_bytecode_builtins_list_action__output}
  SOURCES ${generate_bytecode_builtins_list__generate_bytecode_builtins_list_action__input}
)
add_custom_target(generate_bytecode_builtins_list SOURCES)
set_target_properties(generate_bytecode_builtins_list PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(generate_bytecode_builtins_list__generate_bytecode_builtins_list_action PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(generate_bytecode_builtins_list__generate_bytecode_builtins_list_action
  bytecode_builtins_list_generator
)
add_dependencies(generate_bytecode_builtins_list
  bytecode_builtins_list_generator
  generate_bytecode_builtins_list__generate_bytecode_builtins_list_action
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icu_uconfig_target#target
set(TARGET "icu_uconfig_target")
set(TOOLSET "target")
add_custom_target(icu_uconfig_target SOURCES)
set_target_properties(icu_uconfig_target PROPERTIES EXCLUDE_FROM_ALL "FALSE")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icu_uconfig#target
set(TARGET "icu_uconfig")
set(TOOLSET "target")
add_custom_target(icu_uconfig SOURCES)
set_target_properties(icu_uconfig PROPERTIES EXCLUDE_FROM_ALL "FALSE")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icu_uconfig#host
set(TARGET "icu_uconfig")
set(TOOLSET "host")
add_custom_target(icu_uconfig_host SOURCES)
set_target_properties(icu_uconfig_host PROPERTIES EXCLUDE_FROM_ALL "FALSE")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icu_implementation#target
set(TARGET "icu_implementation")
set(TOOLSET "target")
add_custom_target(icu_implementation SOURCES)
set_target_properties(icu_implementation PROPERTIES EXCLUDE_FROM_ALL "FALSE")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icuucx#target
set(TARGET "icuucx")
set(TOOLSET "target")
list(APPEND icuucx__cxx_srcs
  "deps/icu-small/source/common/uniset.cpp"
  "deps/icu-small/source/common/dictbe.cpp"
  "deps/icu-small/source/common/chariter.cpp"
  "deps/icu-small/source/common/utf_impl.cpp"
  "deps/icu-small/source/common/uhash.cpp"
  "deps/icu-small/source/common/ushape.cpp"
  "deps/icu-small/source/common/ucnvsel.cpp"
  "deps/icu-small/source/common/uarrsort.cpp"
  "deps/icu-small/source/common/ucnv_set.cpp"
  "deps/icu-small/source/common/uniset_props.cpp"
  "deps/icu-small/source/common/caniter.cpp"
  "deps/icu-small/source/common/ubidiwrt.cpp"
  "deps/icu-small/source/common/ucnvscsu.cpp"
  "deps/icu-small/source/common/cstr.cpp"
  "deps/icu-small/source/common/wintz.cpp"
  "deps/icu-small/source/common/ubiditransform.cpp"
  "deps/icu-small/source/common/dictionarydata.cpp"
  "deps/icu-small/source/common/loclikelysubtags.cpp"
  "deps/icu-small/source/common/stringtriebuilder.cpp"
  "deps/icu-small/source/common/util.cpp"
  "deps/icu-small/source/common/cstring.cpp"
  "deps/icu-small/source/common/localeprioritylist.cpp"
  "deps/icu-small/source/common/uinit.cpp"
  "deps/icu-small/source/common/ucharstrieiterator.cpp"
  "deps/icu-small/source/common/unisetspan.cpp"
  "deps/icu-small/source/common/icuplug.cpp"
  "deps/icu-small/source/common/ucnv_ext.cpp"
  "deps/icu-small/source/common/servnotf.cpp"
  "deps/icu-small/source/common/locid.cpp"
  "deps/icu-small/source/common/ustr_cnv.cpp"
  "deps/icu-small/source/common/unames.cpp"
  "deps/icu-small/source/common/filterednormalizer2.cpp"
  "deps/icu-small/source/common/loclikely.cpp"
  "deps/icu-small/source/common/uscript_props.cpp"
  "deps/icu-small/source/common/bytestrieiterator.cpp"
  "deps/icu-small/source/common/propsvec.cpp"
  "deps/icu-small/source/common/ucnv_u32.cpp"
  "deps/icu-small/source/common/punycode.cpp"
  "deps/icu-small/source/common/ubidiln.cpp"
  "deps/icu-small/source/common/putil.cpp"
  "deps/icu-small/source/common/bytestrie.cpp"
  "deps/icu-small/source/common/resource.cpp"
  "deps/icu-small/source/common/uvector.cpp"
  "deps/icu-small/source/common/ucase.cpp"
  "deps/icu-small/source/common/rbbi.cpp"
  "deps/icu-small/source/common/locutil.cpp"
  "deps/icu-small/source/common/servls.cpp"
  "deps/icu-small/source/common/ucnvdisp.cpp"
  "deps/icu-small/source/common/ucnv_err.cpp"
  "deps/icu-small/source/common/unistr_titlecase_brkiter.cpp"
  "deps/icu-small/source/common/uloc_tag.cpp"
  "deps/icu-small/source/common/icudataver.cpp"
  "deps/icu-small/source/common/uenum.cpp"
  "deps/icu-small/source/common/rbbisetb.cpp"
  "deps/icu-small/source/common/filteredbrk.cpp"
  "deps/icu-small/source/common/ubrk.cpp"
  "deps/icu-small/source/common/ucnv_bld.cpp"
  "deps/icu-small/source/common/brkeng.cpp"
  "deps/icu-small/source/common/charstr.cpp"
  "deps/icu-small/source/common/uloc_keytype.cpp"
  "deps/icu-small/source/common/ucnv_ct.cpp"
  "deps/icu-small/source/common/bytestriebuilder.cpp"
  "deps/icu-small/source/common/ubidi.cpp"
  "deps/icu-small/source/common/ucnv_u8.cpp"
  "deps/icu-small/source/common/locdispnames.cpp"
  "deps/icu-small/source/common/ucnv_cb.cpp"
  "deps/icu-small/source/common/ustr_titlecase_brkiter.cpp"
  "deps/icu-small/source/common/locdistance.cpp"
  "deps/icu-small/source/common/static_unicode_sets.cpp"
  "deps/icu-small/source/common/bmpset.cpp"
  "deps/icu-small/source/common/uniset_closure.cpp"
  "deps/icu-small/source/common/locdspnm.cpp"
  "deps/icu-small/source/common/bytesinkutil.cpp"
  "deps/icu-small/source/common/rbbi_cache.cpp"
  "deps/icu-small/source/common/ucharstriebuilder.cpp"
  "deps/icu-small/source/common/utrie2.cpp"
  "deps/icu-small/source/common/unifiedcache.cpp"
  "deps/icu-small/source/common/servlkf.cpp"
  "deps/icu-small/source/common/schriter.cpp"
  "deps/icu-small/source/common/locbased.cpp"
  "deps/icu-small/source/common/udatamem.cpp"
  "deps/icu-small/source/common/umutablecptrie.cpp"
  "deps/icu-small/source/common/patternprops.cpp"
  "deps/icu-small/source/common/localebuilder.cpp"
  "deps/icu-small/source/common/unistr_props.cpp"
  "deps/icu-small/source/common/ucnv.cpp"
  "deps/icu-small/source/common/stringpiece.cpp"
  "deps/icu-small/source/common/ulist.cpp"
  "deps/icu-small/source/common/ustrtrns.cpp"
  "deps/icu-small/source/common/uiter.cpp"
  "deps/icu-small/source/common/cmemory.cpp"
  "deps/icu-small/source/common/resbund_cnv.cpp"
  "deps/icu-small/source/common/uvectr64.cpp"
  "deps/icu-small/source/common/unistr_case.cpp"
  "deps/icu-small/source/common/ustr_wcs.cpp"
  "deps/icu-small/source/common/ucnvlat1.cpp"
  "deps/icu-small/source/common/simpleformatter.cpp"
  "deps/icu-small/source/common/uts46.cpp"
  "deps/icu-small/source/common/ucnvmbcs.cpp"
  "deps/icu-small/source/common/locresdata.cpp"
  "deps/icu-small/source/common/pluralmap.cpp"
  "deps/icu-small/source/common/uprops.cpp"
  "deps/icu-small/source/common/usetiter.cpp"
  "deps/icu-small/source/common/propname.cpp"
  "deps/icu-small/source/common/rbbistbl.cpp"
  "deps/icu-small/source/common/ucat.cpp"
  "deps/icu-small/source/common/unifilt.cpp"
  "deps/icu-small/source/common/utrie_swap.cpp"
  "deps/icu-small/source/common/uresdata.cpp"
  "deps/icu-small/source/common/umapfile.cpp"
  "deps/icu-small/source/common/messagepattern.cpp"
  "deps/icu-small/source/common/locavailable.cpp"
  "deps/icu-small/source/common/ustrcase.cpp"
  "deps/icu-small/source/common/cwchar.cpp"
  "deps/icu-small/source/common/rbbiscan.cpp"
  "deps/icu-small/source/common/umath.cpp"
  "deps/icu-small/source/common/uset.cpp"
  "deps/icu-small/source/common/ucln_cmn.cpp"
  "deps/icu-small/source/common/ures_cnv.cpp"
  "deps/icu-small/source/common/normlzr.cpp"
  "deps/icu-small/source/common/ucmndata.cpp"
  "deps/icu-small/source/common/servlk.cpp"
  "deps/icu-small/source/common/edits.cpp"
  "deps/icu-small/source/common/ucnvbocu.cpp"
  "deps/icu-small/source/common/ustrfmt.cpp"
  "deps/icu-small/source/common/parsepos.cpp"
  "deps/icu-small/source/common/loadednormalizer2impl.cpp"
  "deps/icu-small/source/common/udata.cpp"
  "deps/icu-small/source/common/errorcode.cpp"
  "deps/icu-small/source/common/uchriter.cpp"
  "deps/icu-small/source/common/ucnv_lmb.cpp"
  "deps/icu-small/source/common/ucurr.cpp"
  "deps/icu-small/source/common/udataswp.cpp"
  "deps/icu-small/source/common/restrace.cpp"
  "deps/icu-small/source/common/ustrcase_locale.cpp"
  "deps/icu-small/source/common/localematcher.cpp"
  "deps/icu-small/source/common/unistr.cpp"
  "deps/icu-small/source/common/ucnvhz.cpp"
  "deps/icu-small/source/common/normalizer2.cpp"
  "deps/icu-small/source/common/sharedobject.cpp"
  "deps/icu-small/source/common/resbund.cpp"
  "deps/icu-small/source/common/uhash_us.cpp"
  "deps/icu-small/source/common/serv.cpp"
  "deps/icu-small/source/common/utrie.cpp"
  "deps/icu-small/source/common/umutex.cpp"
  "deps/icu-small/source/common/unorm.cpp"
  "deps/icu-small/source/common/uidna.cpp"
  "deps/icu-small/source/common/servrbf.cpp"
  "deps/icu-small/source/common/ucnv_u7.cpp"
  "deps/icu-small/source/common/ruleiter.cpp"
  "deps/icu-small/source/common/uset_props.cpp"
  "deps/icu-small/source/common/appendable.cpp"
  "deps/icu-small/source/common/lsr.cpp"
  "deps/icu-small/source/common/utypes.cpp"
  "deps/icu-small/source/common/ucasemap.cpp"
  "deps/icu-small/source/common/usc_impl.cpp"
  "deps/icu-small/source/common/uresbund.cpp"
  "deps/icu-small/source/common/rbbidata.cpp"
  "deps/icu-small/source/common/unormcmp.cpp"
  "deps/icu-small/source/common/ucptrie.cpp"
  "deps/icu-small/source/common/ubidi_props.cpp"
  "deps/icu-small/source/common/uchar.cpp"
  "deps/icu-small/source/common/normalizer2impl.cpp"
  "deps/icu-small/source/common/ucnvisci.cpp"
  "deps/icu-small/source/common/unistr_cnv.cpp"
  "deps/icu-small/source/common/rbbirb.cpp"
  "deps/icu-small/source/common/unifunct.cpp"
  "deps/icu-small/source/common/characterproperties.cpp"
  "deps/icu-small/source/common/ustack.cpp"
  "deps/icu-small/source/common/uinvchar.cpp"
  "deps/icu-small/source/common/ucasemap_titlecase_brkiter.cpp"
  "deps/icu-small/source/common/bytestream.cpp"
  "deps/icu-small/source/common/ustring.cpp"
  "deps/icu-small/source/common/usprep.cpp"
  "deps/icu-small/source/common/servslkf.cpp"
  "deps/icu-small/source/common/rbbitblb.cpp"
  "deps/icu-small/source/common/ucnv_u16.cpp"
  "deps/icu-small/source/common/util_props.cpp"
  "deps/icu-small/source/common/uloc.cpp"
  "deps/icu-small/source/common/ustrenum.cpp"
  "deps/icu-small/source/common/ucnv_io.cpp"
  "deps/icu-small/source/common/unistr_case_locale.cpp"
  "deps/icu-small/source/common/uobject.cpp"
  "deps/icu-small/source/common/ucnv_cnv.cpp"
  "deps/icu-small/source/common/ucnv2022.cpp"
  "deps/icu-small/source/common/ucol_swp.cpp"
  "deps/icu-small/source/common/dtintrv.cpp"
  "deps/icu-small/source/common/rbbinode.cpp"
  "deps/icu-small/source/common/ucharstrie.cpp"
  "deps/icu-small/source/common/uscript.cpp"
  "deps/icu-small/source/common/utext.cpp"
  "deps/icu-small/source/common/locmap.cpp"
  "deps/icu-small/source/common/utrie2_builder.cpp"
  "deps/icu-small/source/common/uvectr32.cpp"
  "deps/icu-small/source/common/utrace.cpp"
  "deps/icu-small/source/common/brkiter.cpp")
list(APPEND icuucx__other_srcs
  "deps/icu-small/source/common/rbbi_cache.h"
  "deps/icu-small/source/common/unisetspan.h"
  "deps/icu-small/source/common/localeprioritylist.h"
  "deps/icu-small/source/common/ureslocs.h"
  "deps/icu-small/source/common/propsvec.h"
  "deps/icu-small/source/common/rbbinode.h"
  "deps/icu-small/source/common/udatamem.h"
  "deps/icu-small/source/common/ucol_swp.h"
  "deps/icu-small/source/common/umutex.h"
  "deps/icu-small/source/common/locmap.h"
  "deps/icu-small/source/common/uvector.h"
  "deps/icu-small/source/common/uvectr32.h"
  "deps/icu-small/source/common/servnotf.h"
  "deps/icu-small/source/common/locdistance.h"
  "deps/icu-small/source/common/ustr_imp.h"
  "deps/icu-small/source/common/servloc.h"
  "deps/icu-small/source/common/ucln.h"
  "deps/icu-small/source/common/unormimp.h"
  "deps/icu-small/source/common/unifiedcache.h"
  "deps/icu-small/source/common/loclikelysubtags.h"
  "deps/icu-small/source/common/pluralmap.h"
  "deps/icu-small/source/common/uchar_props_data.h"
  "deps/icu-small/source/common/uresdata.h"
  "deps/icu-small/source/common/cpputils.h"
  "deps/icu-small/source/common/rbbidata.h"
  "deps/icu-small/source/common/uassert.h"
  "deps/icu-small/source/common/usc_impl.h"
  "deps/icu-small/source/common/uelement.h"
  "deps/icu-small/source/common/utrie2.h"
  "deps/icu-small/source/common/dictbe.h"
  "deps/icu-small/source/common/ucol_data.h"
  "deps/icu-small/source/common/locbased.h"
  "deps/icu-small/source/common/cmemory.h"
  "deps/icu-small/source/common/patternprops.h"
  "deps/icu-small/source/common/uresimp.h"
  "deps/icu-small/source/common/ubidi_props_data.h"
  "deps/icu-small/source/common/utracimp.h"
  "deps/icu-small/source/common/norm2allmodes.h"
  "deps/icu-small/source/common/ucptrie_impl.h"
  "deps/icu-small/source/common/msvcres.h"
  "deps/icu-small/source/common/utypeinfo.h"
  "deps/icu-small/source/common/ucnv_cnv.h"
  "deps/icu-small/source/common/static_unicode_sets.h"
  "deps/icu-small/source/common/sprpimpl.h"
  "deps/icu-small/source/common/cwchar.h"
  "deps/icu-small/source/common/umapfile.h"
  "deps/icu-small/source/common/ulocimp.h"
  "deps/icu-small/source/common/charstr.h"
  "deps/icu-small/source/common/ubidi_props.h"
  "deps/icu-small/source/common/ulayout_props.h"
  "deps/icu-small/source/common/punycode.h"
  "deps/icu-small/source/common/uposixdefs.h"
  "deps/icu-small/source/common/localsvc.h"
  "deps/icu-small/source/common/udataswp.h"
  "deps/icu-small/source/common/cstring.h"
  "deps/icu-small/source/common/propname.h"
  "deps/icu-small/source/common/uenumimp.h"
  "deps/icu-small/source/common/ulist.h"
  "deps/icu-small/source/common/dictionarydata.h"
  "deps/icu-small/source/common/sharedobject.h"
  "deps/icu-small/source/common/serv.h"
  "deps/icu-small/source/common/rbbiscan.h"
  "deps/icu-small/source/common/ucln_imp.h"
  "deps/icu-small/source/common/rbbisetb.h"
  "deps/icu-small/source/common/norm2_nfc_data.h"
  "deps/icu-small/source/common/propname_data.h"
  "deps/icu-small/source/common/ubidiimp.h"
  "deps/icu-small/source/common/ucnvmbcs.h"
  "deps/icu-small/source/common/uvectr64.h"
  "deps/icu-small/source/common/ucmndata.h"
  "deps/icu-small/source/common/rbbirb.h"
  "deps/icu-small/source/common/ubrkimpl.h"
  "deps/icu-small/source/common/ucnv_io.h"
  "deps/icu-small/source/common/util.h"
  "deps/icu-small/source/common/resource.h"
  "deps/icu-small/source/common/bmpset.h"
  "deps/icu-small/source/common/ustr_cnv.h"
  "deps/icu-small/source/common/utrie2_impl.h"
  "deps/icu-small/source/common/ucurrimp.h"
  "deps/icu-small/source/common/ucnv_ext.h"
  "deps/icu-small/source/common/ucase_props_data.h"
  "deps/icu-small/source/common/ucnv_bld.h"
  "deps/icu-small/source/common/normalizer2impl.h"
  "deps/icu-small/source/common/ustrfmt.h"
  "deps/icu-small/source/common/ustrenum.h"
  "deps/icu-small/source/common/uprops.h"
  "deps/icu-small/source/common/ucase.h"
  "deps/icu-small/source/common/unistrappender.h"
  "deps/icu-small/source/common/icuplugimp.h"
  "deps/icu-small/source/common/bytesinkutil.h"
  "deps/icu-small/source/common/brkeng.h"
  "deps/icu-small/source/common/uset_imp.h"
  "deps/icu-small/source/common/mutex.h"
  "deps/icu-small/source/common/rbbitblb.h"
  "deps/icu-small/source/common/locutil.h"
  "deps/icu-small/source/common/ucasemap_imp.h"
  "deps/icu-small/source/common/putilimp.h"
  "deps/icu-small/source/common/restrace.h"
  "deps/icu-small/source/common/rbbirpt.h"
  "deps/icu-small/source/common/uhash.h"
  "deps/icu-small/source/common/utrie.h"
  "deps/icu-small/source/common/ucnv_imp.h"
  "deps/icu-small/source/common/messageimpl.h"
  "deps/icu-small/source/common/capi_helper.h"
  "deps/icu-small/source/common/hash.h"
  "deps/icu-small/source/common/uarrsort.h"
  "deps/icu-small/source/common/cstr.h"
  "deps/icu-small/source/common/ruleiter.h"
  "deps/icu-small/source/common/ucln_cmn.h"
  "deps/icu-small/source/common/uinvchar.h"
  "deps/icu-small/source/common/wintz.h"
  "deps/icu-small/source/common/lsr.h")
add_library(icuucx STATIC ${icuucx__cxx_srcs} ${icuucx__other_srcs})
set_target_properties(icuucx PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${icuucx__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(icuucx PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/icu")
set_target_properties(icuucx PROPERTIES PREFIX "lib")
set_target_properties(icuucx PROPERTIES ARCHIVE_OUTPUT_NAME "icuucx")
set_target_properties(icuucx PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/icu/libicuucx.a PROPERTIES GENERATED "TRUE")
set(icuucx__include_dirs "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET icuucx APPEND PROPERTY INCLUDE_DIRECTORIES ${icuucx__include_dirs})
set_target_properties(icuucx PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;U_COMMON_IMPLEMENTATION=1;U_ATTRIBUTE_DEPRECATED=;_CRT_SECURE_NO_DEPRECATE=;U_STATIC_IMPLEMENTATION=1;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(icuucx PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-exceptions -fno-strict-aliasing ")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "YES")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(icuucx PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(icuucx
  icu_implementation
  icu_uconfig
  icu_uconfig_target
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icui18n#target
set(TARGET "icui18n")
set(TOOLSET "target")
list(APPEND icui18n__cxx_srcs
  "deps/icu-small/source/i18n/nultrans.cpp"
  "deps/icu-small/source/i18n/uspoof_conf.cpp"
  "deps/icu-small/source/i18n/japancal.cpp"
  "deps/icu-small/source/i18n/tmunit.cpp"
  "deps/icu-small/source/i18n/decimfmt.cpp"
  "deps/icu-small/source/i18n/taiwncal.cpp"
  "deps/icu-small/source/i18n/formattedval_iterimpl.cpp"
  "deps/icu-small/source/i18n/transreg.cpp"
  "deps/icu-small/source/i18n/number_rounding.cpp"
  "deps/icu-small/source/i18n/collationweights.cpp"
  "deps/icu-small/source/i18n/smpdtfst.cpp"
  "deps/icu-small/source/i18n/collationruleparser.cpp"
  "deps/icu-small/source/i18n/decNumber.cpp"
  "deps/icu-small/source/i18n/fmtable_cnv.cpp"
  "deps/icu-small/source/i18n/regeximp.cpp"
  "deps/icu-small/source/i18n/collation.cpp"
  "deps/icu-small/source/i18n/number_patternmodifier.cpp"
  "deps/icu-small/source/i18n/collationsets.cpp"
  "deps/icu-small/source/i18n/number_decimalquantity.cpp"
  "deps/icu-small/source/i18n/number_asformat.cpp"
  "deps/icu-small/source/i18n/numrange_impl.cpp"
  "deps/icu-small/source/i18n/usearch.cpp"
  "deps/icu-small/source/i18n/ucoleitr.cpp"
  "deps/icu-small/source/i18n/double-conversion-fast-dtoa.cpp"
  "deps/icu-small/source/i18n/number_decimfmtprops.cpp"
  "deps/icu-small/source/i18n/number_scientific.cpp"
  "deps/icu-small/source/i18n/measure.cpp"
  "deps/icu-small/source/i18n/persncal.cpp"
  "deps/icu-small/source/i18n/ztrans.cpp"
  "deps/icu-small/source/i18n/dtfmtsym.cpp"
  "deps/icu-small/source/i18n/ucsdet.cpp"
  "deps/icu-small/source/i18n/collationdatawriter.cpp"
  "deps/icu-small/source/i18n/formatted_string_builder.cpp"
  "deps/icu-small/source/i18n/regextxt.cpp"
  "deps/icu-small/source/i18n/coleitr.cpp"
  "deps/icu-small/source/i18n/csrutf8.cpp"
  "deps/icu-small/source/i18n/uitercollationiterator.cpp"
  "deps/icu-small/source/i18n/tznames.cpp"
  "deps/icu-small/source/i18n/collationfcd.cpp"
  "deps/icu-small/source/i18n/tzrule.cpp"
  "deps/icu-small/source/i18n/gender.cpp"
  "deps/icu-small/source/i18n/number_formatimpl.cpp"
  "deps/icu-small/source/i18n/msgfmt.cpp"
  "deps/icu-small/source/i18n/scientificnumberformatter.cpp"
  "deps/icu-small/source/i18n/toupptrn.cpp"
  "deps/icu-small/source/i18n/sortkey.cpp"
  "deps/icu-small/source/i18n/alphaindex.cpp"
  "deps/icu-small/source/i18n/collationkeys.cpp"
  "deps/icu-small/source/i18n/number_affixutils.cpp"
  "deps/icu-small/source/i18n/collationfastlatin.cpp"
  "deps/icu-small/source/i18n/choicfmt.cpp"
  "deps/icu-small/source/i18n/gregocal.cpp"
  "deps/icu-small/source/i18n/unumsys.cpp"
  "deps/icu-small/source/i18n/sharedbreakiterator.cpp"
  "deps/icu-small/source/i18n/numparse_parsednumber.cpp"
  "deps/icu-small/source/i18n/format.cpp"
  "deps/icu-small/source/i18n/scriptset.cpp"
  "deps/icu-small/source/i18n/utf16collationiterator.cpp"
  "deps/icu-small/source/i18n/uspoof_build.cpp"
  "deps/icu-small/source/i18n/casetrn.cpp"
  "deps/icu-small/source/i18n/nfrs.cpp"
  "deps/icu-small/source/i18n/csdetect.cpp"
  "deps/icu-small/source/i18n/numparse_symbols.cpp"
  "deps/icu-small/source/i18n/umsg.cpp"
  "deps/icu-small/source/i18n/gregoimp.cpp"
  "deps/icu-small/source/i18n/dtitvfmt.cpp"
  "deps/icu-small/source/i18n/collationsettings.cpp"
  "deps/icu-small/source/i18n/regexst.cpp"
  "deps/icu-small/source/i18n/number_fluent.cpp"
  "deps/icu-small/source/i18n/translit.cpp"
  "deps/icu-small/source/i18n/plurfmt.cpp"
  "deps/icu-small/source/i18n/dtitvinf.cpp"
  "deps/icu-small/source/i18n/upluralrules.cpp"
  "deps/icu-small/source/i18n/collationdatareader.cpp"
  "deps/icu-small/source/i18n/dtptngen.cpp"
  "deps/icu-small/source/i18n/number_padding.cpp"
  "deps/icu-small/source/i18n/fmtable.cpp"
  "deps/icu-small/source/i18n/chnsecal.cpp"
  "deps/icu-small/source/i18n/uregex.cpp"
  "deps/icu-small/source/i18n/dtrule.cpp"
  "deps/icu-small/source/i18n/ulocdata.cpp"
  "deps/icu-small/source/i18n/tridpars.cpp"
  "deps/icu-small/source/i18n/cpdtrans.cpp"
  "deps/icu-small/source/i18n/collationbuilder.cpp"
  "deps/icu-small/source/i18n/number_grouping.cpp"
  "deps/icu-small/source/i18n/standardplural.cpp"
  "deps/icu-small/source/i18n/ethpccal.cpp"
  "deps/icu-small/source/i18n/olsontz.cpp"
  "deps/icu-small/source/i18n/rbt_rule.cpp"
  "deps/icu-small/source/i18n/collationtailoring.cpp"
  "deps/icu-small/source/i18n/collationfastlatinbuilder.cpp"
  "deps/icu-small/source/i18n/csrucode.cpp"
  "deps/icu-small/source/i18n/astro.cpp"
  "deps/icu-small/source/i18n/numfmt.cpp"
  "deps/icu-small/source/i18n/rbt.cpp"
  "deps/icu-small/source/i18n/udatpg.cpp"
  "deps/icu-small/source/i18n/numparse_validators.cpp"
  "deps/icu-small/source/i18n/strrepl.cpp"
  "deps/icu-small/source/i18n/ucal.cpp"
  "deps/icu-small/source/i18n/double-conversion-cached-powers.cpp"
  "deps/icu-small/source/i18n/timezone.cpp"
  "deps/icu-small/source/i18n/quant.cpp"
  "deps/icu-small/source/i18n/bocsu.cpp"
  "deps/icu-small/source/i18n/erarules.cpp"
  "deps/icu-small/source/i18n/currpinf.cpp"
  "deps/icu-small/source/i18n/number_notation.cpp"
  "deps/icu-small/source/i18n/windtfmt.cpp"
  "deps/icu-small/source/i18n/funcrepl.cpp"
  "deps/icu-small/source/i18n/calendar.cpp"
  "deps/icu-small/source/i18n/number_multiplier.cpp"
  "deps/icu-small/source/i18n/smpdtfmt.cpp"
  "deps/icu-small/source/i18n/ulistformatter.cpp"
  "deps/icu-small/source/i18n/uregion.cpp"
  "deps/icu-small/source/i18n/number_compact.cpp"
  "deps/icu-small/source/i18n/rulebasedcollator.cpp"
  "deps/icu-small/source/i18n/name2uni.cpp"
  "deps/icu-small/source/i18n/number_longnames.cpp"
  "deps/icu-small/source/i18n/stsearch.cpp"
  "deps/icu-small/source/i18n/strmatch.cpp"
  "deps/icu-small/source/i18n/ucln_in.cpp"
  "deps/icu-small/source/i18n/zrule.cpp"
  "deps/icu-small/source/i18n/coll.cpp"
  "deps/icu-small/source/i18n/numrange_fluent.cpp"
  "deps/icu-small/source/i18n/quantityformatter.cpp"
  "deps/icu-small/source/i18n/selfmt.cpp"
  "deps/icu-small/source/i18n/collationrootelements.cpp"
  "deps/icu-small/source/i18n/double-conversion-strtod.cpp"
  "deps/icu-small/source/i18n/numparse_decimal.cpp"
  "deps/icu-small/source/i18n/nounit.cpp"
  "deps/icu-small/source/i18n/cecal.cpp"
  "deps/icu-small/source/i18n/titletrn.cpp"
  "deps/icu-small/source/i18n/double-conversion-double-to-string.cpp"
  "deps/icu-small/source/i18n/nfsubs.cpp"
  "deps/icu-small/source/i18n/numparse_affixes.cpp"
  "deps/icu-small/source/i18n/vzone.cpp"
  "deps/icu-small/source/i18n/numsys.cpp"
  "deps/icu-small/source/i18n/dcfmtsym.cpp"
  "deps/icu-small/source/i18n/number_currencysymbols.cpp"
  "deps/icu-small/source/i18n/collationiterator.cpp"
  "deps/icu-small/source/i18n/fphdlimp.cpp"
  "deps/icu-small/source/i18n/hebrwcal.cpp"
  "deps/icu-small/source/i18n/csrsbcs.cpp"
  "deps/icu-small/source/i18n/rbt_pars.cpp"
  "deps/icu-small/source/i18n/csr2022.cpp"
  "deps/icu-small/source/i18n/search.cpp"
  "deps/icu-small/source/i18n/zonemeta.cpp"
  "deps/icu-small/source/i18n/reldtfmt.cpp"
  "deps/icu-small/source/i18n/number_output.cpp"
  "deps/icu-small/source/i18n/inputext.cpp"
  "deps/icu-small/source/i18n/double-conversion-bignum-dtoa.cpp"
  "deps/icu-small/source/i18n/ufieldpositer.cpp"
  "deps/icu-small/source/i18n/winnmfmt.cpp"
  "deps/icu-small/source/i18n/utf8collationiterator.cpp"
  "deps/icu-small/source/i18n/anytrans.cpp"
  "deps/icu-small/source/i18n/collationdata.cpp"
  "deps/icu-small/source/i18n/unesctrn.cpp"
  "deps/icu-small/source/i18n/ucol_sit.cpp"
  "deps/icu-small/source/i18n/remtrans.cpp"
  "deps/icu-small/source/i18n/nortrans.cpp"
  "deps/icu-small/source/i18n/islamcal.cpp"
  "deps/icu-small/source/i18n/numparse_scientific.cpp"
  "deps/icu-small/source/i18n/dangical.cpp"
  "deps/icu-small/source/i18n/formattedvalue.cpp"
  "deps/icu-small/source/i18n/currfmt.cpp"
  "deps/icu-small/source/i18n/tmutfmt.cpp"
  "deps/icu-small/source/i18n/number_skeletons.cpp"
  "deps/icu-small/source/i18n/ucol.cpp"
  "deps/icu-small/source/i18n/currunit.cpp"
  "deps/icu-small/source/i18n/uspoof.cpp"
  "deps/icu-small/source/i18n/collationroot.cpp"
  "deps/icu-small/source/i18n/number_integerwidth.cpp"
  "deps/icu-small/source/i18n/decContext.cpp"
  "deps/icu-small/source/i18n/number_utils.cpp"
  "deps/icu-small/source/i18n/double-conversion-bignum.cpp"
  "deps/icu-small/source/i18n/rbt_set.cpp"
  "deps/icu-small/source/i18n/number_capi.cpp"
  "deps/icu-small/source/i18n/tzfmt.cpp"
  "deps/icu-small/source/i18n/uregexc.cpp"
  "deps/icu-small/source/i18n/measfmt.cpp"
  "deps/icu-small/source/i18n/brktrans.cpp"
  "deps/icu-small/source/i18n/tmutamt.cpp"
  "deps/icu-small/source/i18n/coptccal.cpp"
  "deps/icu-small/source/i18n/wintzimpl.cpp"
  "deps/icu-small/source/i18n/indiancal.cpp"
  "deps/icu-small/source/i18n/number_mapper.cpp"
  "deps/icu-small/source/i18n/basictz.cpp"
  "deps/icu-small/source/i18n/region.cpp"
  "deps/icu-small/source/i18n/dayperiodrules.cpp"
  "deps/icu-small/source/i18n/csrmbcs.cpp"
  "deps/icu-small/source/i18n/number_modifiers.cpp"
  "deps/icu-small/source/i18n/rbnf.cpp"
  "deps/icu-small/source/i18n/esctrn.cpp"
  "deps/icu-small/source/i18n/ucol_res.cpp"
  "deps/icu-small/source/i18n/regexcmp.cpp"
  "deps/icu-small/source/i18n/plurrule.cpp"
  "deps/icu-small/source/i18n/double-conversion-string-to-double.cpp"
  "deps/icu-small/source/i18n/string_segment.cpp"
  "deps/icu-small/source/i18n/csmatch.cpp"
  "deps/icu-small/source/i18n/simpletz.cpp"
  "deps/icu-small/source/i18n/formattedval_sbimpl.cpp"
  "deps/icu-small/source/i18n/compactdecimalformat.cpp"
  "deps/icu-small/source/i18n/tznames_impl.cpp"
  "deps/icu-small/source/i18n/numparse_currency.cpp"
  "deps/icu-small/source/i18n/fpositer.cpp"
  "deps/icu-small/source/i18n/nfrule.cpp"
  "deps/icu-small/source/i18n/numparse_compositions.cpp"
  "deps/icu-small/source/i18n/utmscale.cpp"
  "deps/icu-small/source/i18n/utrans.cpp"
  "deps/icu-small/source/i18n/listformatter.cpp"
  "deps/icu-small/source/i18n/curramt.cpp"
  "deps/icu-small/source/i18n/measunit.cpp"
  "deps/icu-small/source/i18n/buddhcal.cpp"
  "deps/icu-small/source/i18n/udateintervalformat.cpp"
  "deps/icu-small/source/i18n/uspoof_impl.cpp"
  "deps/icu-small/source/i18n/tzgnames.cpp"
  "deps/icu-small/source/i18n/rematch.cpp"
  "deps/icu-small/source/i18n/datefmt.cpp"
  "deps/icu-small/source/i18n/reldatefmt.cpp"
  "deps/icu-small/source/i18n/vtzone.cpp"
  "deps/icu-small/source/i18n/tztrans.cpp"
  "deps/icu-small/source/i18n/collationdatabuilder.cpp"
  "deps/icu-small/source/i18n/repattrn.cpp"
  "deps/icu-small/source/i18n/collationcompare.cpp"
  "deps/icu-small/source/i18n/rbt_data.cpp"
  "deps/icu-small/source/i18n/csrecog.cpp"
  "deps/icu-small/source/i18n/number_patternstring.cpp"
  "deps/icu-small/source/i18n/udat.cpp"
  "deps/icu-small/source/i18n/tolowtrn.cpp"
  "deps/icu-small/source/i18n/numparse_impl.cpp"
  "deps/icu-small/source/i18n/unum.cpp"
  "deps/icu-small/source/i18n/rbtz.cpp"
  "deps/icu-small/source/i18n/uni2name.cpp")
list(APPEND icui18n__other_srcs
  "deps/icu-small/source/i18n/anytrans.h"
  "deps/icu-small/source/i18n/zrule.h"
  "deps/icu-small/source/i18n/decNumberLocal.h"
  "deps/icu-small/source/i18n/japancal.h"
  "deps/icu-small/source/i18n/rbt.h"
  "deps/icu-small/source/i18n/taiwncal.h"
  "deps/icu-small/source/i18n/tridpars.h"
  "deps/icu-small/source/i18n/collationcompare.h"
  "deps/icu-small/source/i18n/double-conversion-ieee.h"
  "deps/icu-small/source/i18n/chnsecal.h"
  "deps/icu-small/source/i18n/erarules.h"
  "deps/icu-small/source/i18n/csrucode.h"
  "deps/icu-small/source/i18n/decNumber.h"
  "deps/icu-small/source/i18n/number_longnames.h"
  "deps/icu-small/source/i18n/nfrule.h"
  "deps/icu-small/source/i18n/toupptrn.h"
  "deps/icu-small/source/i18n/sharedpluralrules.h"
  "deps/icu-small/source/i18n/dtitv_impl.h"
  "deps/icu-small/source/i18n/casetrn.h"
  "deps/icu-small/source/i18n/numrange_impl.h"
  "deps/icu-small/source/i18n/collationbuilder.h"
  "deps/icu-small/source/i18n/double-conversion-cached-powers.h"
  "deps/icu-small/source/i18n/zonemeta.h"
  "deps/icu-small/source/i18n/uspoof_impl.h"
  "deps/icu-small/source/i18n/scriptset.h"
  "deps/icu-small/source/i18n/number_multiplier.h"
  "deps/icu-small/source/i18n/ucol_imp.h"
  "deps/icu-small/source/i18n/collationfcd.h"
  "deps/icu-small/source/i18n/numparse_currency.h"
  "deps/icu-small/source/i18n/winnmfmt.h"
  "deps/icu-small/source/i18n/cecal.h"
  "deps/icu-small/source/i18n/collationdatabuilder.h"
  "deps/icu-small/source/i18n/numparse_decimal.h"
  "deps/icu-small/source/i18n/nortrans.h"
  "deps/icu-small/source/i18n/number_mapper.h"
  "deps/icu-small/source/i18n/gregoimp.h"
  "deps/icu-small/source/i18n/remtrans.h"
  "deps/icu-small/source/i18n/ethpccal.h"
  "deps/icu-small/source/i18n/uni2name.h"
  "deps/icu-small/source/i18n/number_roundingutils.h"
  "deps/icu-small/source/i18n/csdetect.h"
  "deps/icu-small/source/i18n/collationkeys.h"
  "deps/icu-small/source/i18n/sharedbreakiterator.h"
  "deps/icu-small/source/i18n/cpdtrans.h"
  "deps/icu-small/source/i18n/funcrepl.h"
  "deps/icu-small/source/i18n/quant.h"
  "deps/icu-small/source/i18n/umsg_imp.h"
  "deps/icu-small/source/i18n/regexcmp.h"
  "deps/icu-small/source/i18n/collationdatareader.h"
  "deps/icu-small/source/i18n/double-conversion-utils.h"
  "deps/icu-small/source/i18n/number_patternmodifier.h"
  "deps/icu-small/source/i18n/selfmtimpl.h"
  "deps/icu-small/source/i18n/nfsubs.h"
  "deps/icu-small/source/i18n/quantityformatter.h"
  "deps/icu-small/source/i18n/double-conversion-bignum.h"
  "deps/icu-small/source/i18n/collationtailoring.h"
  "deps/icu-small/source/i18n/titletrn.h"
  "deps/icu-small/source/i18n/dt_impl.h"
  "deps/icu-small/source/i18n/ucln_in.h"
  "deps/icu-small/source/i18n/number_affixutils.h"
  "deps/icu-small/source/i18n/unesctrn.h"
  "deps/icu-small/source/i18n/rbt_rule.h"
  "deps/icu-small/source/i18n/numparse_utils.h"
  "deps/icu-small/source/i18n/vzone.h"
  "deps/icu-small/source/i18n/numparse_affixes.h"
  "deps/icu-small/source/i18n/smpdtfst.h"
  "deps/icu-small/source/i18n/inputext.h"
  "deps/icu-small/source/i18n/numparse_symbols.h"
  "deps/icu-small/source/i18n/number_formatimpl.h"
  "deps/icu-small/source/i18n/utf8collationiterator.h"
  "deps/icu-small/source/i18n/fmtableimp.h"
  "deps/icu-small/source/i18n/decContext.h"
  "deps/icu-small/source/i18n/regexst.h"
  "deps/icu-small/source/i18n/uitercollationiterator.h"
  "deps/icu-small/source/i18n/collationsettings.h"
  "deps/icu-small/source/i18n/number_currencysymbols.h"
  "deps/icu-small/source/i18n/numparse_types.h"
  "deps/icu-small/source/i18n/fphdlimp.h"
  "deps/icu-small/source/i18n/wintzimpl.h"
  "deps/icu-small/source/i18n/region_impl.h"
  "deps/icu-small/source/i18n/csrecog.h"
  "deps/icu-small/source/i18n/ztrans.h"
  "deps/icu-small/source/i18n/double-conversion-bignum-dtoa.h"
  "deps/icu-small/source/i18n/standardplural.h"
  "deps/icu-small/source/i18n/double-conversion-fast-dtoa.h"
  "deps/icu-small/source/i18n/collationdata.h"
  "deps/icu-small/source/i18n/collationfastlatinbuilder.h"
  "deps/icu-small/source/i18n/rbt_pars.h"
  "deps/icu-small/source/i18n/numparse_compositions.h"
  "deps/icu-small/source/i18n/number_microprops.h"
  "deps/icu-small/source/i18n/number_decnum.h"
  "deps/icu-small/source/i18n/csmatch.h"
  "deps/icu-small/source/i18n/persncal.h"
  "deps/icu-small/source/i18n/sharedcalendar.h"
  "deps/icu-small/source/i18n/csrutf8.h"
  "deps/icu-small/source/i18n/double-conversion.h"
  "deps/icu-small/source/i18n/regeximp.h"
  "deps/icu-small/source/i18n/regexcst.h"
  "deps/icu-small/source/i18n/formatted_string_builder.h"
  "deps/icu-small/source/i18n/strrepl.h"
  "deps/icu-small/source/i18n/formattedval_impl.h"
  "deps/icu-small/source/i18n/double-conversion-double-to-string.h"
  "deps/icu-small/source/i18n/bocsu.h"
  "deps/icu-small/source/i18n/esctrn.h"
  "deps/icu-small/source/i18n/collationweights.h"
  "deps/icu-small/source/i18n/buddhcal.h"
  "deps/icu-small/source/i18n/rbt_data.h"
  "deps/icu-small/source/i18n/string_segment.h"
  "deps/icu-small/source/i18n/nfrlist.h"
  "deps/icu-small/source/i18n/collationsets.h"
  "deps/icu-small/source/i18n/number_scientific.h"
  "deps/icu-small/source/i18n/transreg.h"
  "deps/icu-small/source/i18n/number_utypes.h"
  "deps/icu-small/source/i18n/olsontz.h"
  "deps/icu-small/source/i18n/dayperiodrules.h"
  "deps/icu-small/source/i18n/sharednumberformat.h"
  "deps/icu-small/source/i18n/collationrootelements.h"
  "deps/icu-small/source/i18n/indiancal.h"
  "deps/icu-small/source/i18n/uspoof_conf.h"
  "deps/icu-small/source/i18n/collationiterator.h"
  "deps/icu-small/source/i18n/utf16collationiterator.h"
  "deps/icu-small/source/i18n/csrsbcs.h"
  "deps/icu-small/source/i18n/strmatch.h"
  "deps/icu-small/source/i18n/islamcal.h"
  "deps/icu-small/source/i18n/number_patternstring.h"
  "deps/icu-small/source/i18n/usrchimp.h"
  "deps/icu-small/source/i18n/tzgnames.h"
  "deps/icu-small/source/i18n/tznames_impl.h"
  "deps/icu-small/source/i18n/csrmbcs.h"
  "deps/icu-small/source/i18n/dtptngen_impl.h"
  "deps/icu-small/source/i18n/number_decimalquantity.h"
  "deps/icu-small/source/i18n/nfrs.h"
  "deps/icu-small/source/i18n/number_modifiers.h"
  "deps/icu-small/source/i18n/msgfmt_impl.h"
  "deps/icu-small/source/i18n/numsys_impl.h"
  "deps/icu-small/source/i18n/name2uni.h"
  "deps/icu-small/source/i18n/numparse_scientific.h"
  "deps/icu-small/source/i18n/double-conversion-string-to-double.h"
  "deps/icu-small/source/i18n/number_types.h"
  "deps/icu-small/source/i18n/nultrans.h"
  "deps/icu-small/source/i18n/dangical.h"
  "deps/icu-small/source/i18n/tolowtrn.h"
  "deps/icu-small/source/i18n/collunsafe.h"
  "deps/icu-small/source/i18n/windtfmt.h"
  "deps/icu-small/source/i18n/coptccal.h"
  "deps/icu-small/source/i18n/shareddateformatsymbols.h"
  "deps/icu-small/source/i18n/regextxt.h"
  "deps/icu-small/source/i18n/collationruleparser.h"
  "deps/icu-small/source/i18n/number_decimfmtprops.h"
  "deps/icu-small/source/i18n/numparse_impl.h"
  "deps/icu-small/source/i18n/number_skeletons.h"
  "deps/icu-small/source/i18n/reldtfmt.h"
  "deps/icu-small/source/i18n/number_utils.h"
  "deps/icu-small/source/i18n/rbt_set.h"
  "deps/icu-small/source/i18n/collationdatawriter.h"
  "deps/icu-small/source/i18n/plurrule_impl.h"
  "deps/icu-small/source/i18n/currfmt.h"
  "deps/icu-small/source/i18n/hebrwcal.h"
  "deps/icu-small/source/i18n/brktrans.h"
  "deps/icu-small/source/i18n/csr2022.h"
  "deps/icu-small/source/i18n/double-conversion-strtod.h"
  "deps/icu-small/source/i18n/double-conversion-diy-fp.h"
  "deps/icu-small/source/i18n/number_asformat.h"
  "deps/icu-small/source/i18n/collation.h"
  "deps/icu-small/source/i18n/numparse_validators.h"
  "deps/icu-small/source/i18n/number_compact.h"
  "deps/icu-small/source/i18n/astro.h"
  "deps/icu-small/source/i18n/collationfastlatin.h"
  "deps/icu-small/source/i18n/collationroot.h")
add_library(icui18n STATIC ${icui18n__cxx_srcs} ${icui18n__other_srcs})
set_target_properties(icui18n PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${icui18n__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(icui18n PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/icu")
set_target_properties(icui18n PROPERTIES PREFIX "lib")
set_target_properties(icui18n PROPERTIES ARCHIVE_OUTPUT_NAME "icui18n")
set_target_properties(icui18n PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/icu/libicui18n.a PROPERTIES GENERATED "TRUE")
list(APPEND icui18n__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET icui18n APPEND PROPERTY INCLUDE_DIRECTORIES ${icui18n__include_dirs})
set_target_properties(icui18n PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;U_I18N_IMPLEMENTATION=1;U_ATTRIBUTE_DEPRECATED=;_CRT_SECURE_NO_DEPRECATE=;U_STATIC_IMPLEMENTATION=1;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(icui18n PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-exceptions -fno-strict-aliasing ")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "YES")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(icui18n PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(icui18n
  icu_implementation
  icu_uconfig
  icu_uconfig_target
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icustubdata#target
set(TARGET "icustubdata")
set(TOOLSET "target")
set(icustubdata__cxx_srcs "deps/icu-small/source/stubdata/stubdata.cpp")
add_library(icustubdata STATIC ${icustubdata__cxx_srcs})
set_target_properties(icustubdata PROPERTIES EXCLUDE_FROM_ALL "TRUE")
set_target_properties(icustubdata PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/icu")
set_target_properties(icustubdata PROPERTIES PREFIX "lib")
set_target_properties(icustubdata PROPERTIES ARCHIVE_OUTPUT_NAME "icustubdata")
set_target_properties(icustubdata PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/icu/libicustubdata.a PROPERTIES GENERATED "TRUE")
set(icustubdata__include_dirs "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET icustubdata APPEND PROPERTY INCLUDE_DIRECTORIES ${icustubdata__include_dirs})
set_target_properties(icustubdata PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;U_ATTRIBUTE_DEPRECATED=;_CRT_SECURE_NO_DEPRECATE=;U_STATIC_IMPLEMENTATION=1;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(icustubdata PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-exceptions -fno-strict-aliasing ")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "YES")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(icustubdata PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(icustubdata
  icu_implementation
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icu_implementation#host
set(TARGET "icu_implementation")
set(TOOLSET "host")
add_custom_target(icu_implementation_host SOURCES)
set_target_properties(icu_implementation_host PROPERTIES EXCLUDE_FROM_ALL "FALSE")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icutools#host
set(TARGET "icutools")
set(TOOLSET "host")
list(APPEND icutools_host__cxx_srcs
  "deps/icu-small/source/tools/toolutil/collationinfo.cpp"
  "deps/icu-small/source/tools/toolutil/ppucd.cpp"
  "deps/icu-small/source/tools/toolutil/pkg_genc.cpp"
  "deps/icu-small/source/tools/toolutil/ucbuf.cpp"
  "deps/icu-small/source/tools/toolutil/pkg_icu.cpp"
  "deps/icu-small/source/tools/toolutil/swapimpl.cpp"
  "deps/icu-small/source/tools/toolutil/filestrm.cpp"
  "deps/icu-small/source/tools/toolutil/uoptions.cpp"
  "deps/icu-small/source/tools/toolutil/writesrc.cpp"
  "deps/icu-small/source/tools/toolutil/flagparser.cpp"
  "deps/icu-small/source/tools/toolutil/uparse.cpp"
  "deps/icu-small/source/tools/toolutil/pkgitems.cpp"
  "deps/icu-small/source/tools/toolutil/denseranges.cpp"
  "deps/icu-small/source/tools/toolutil/ucm.cpp"
  "deps/icu-small/source/tools/toolutil/pkg_gencmn.cpp"
  "deps/icu-small/source/tools/toolutil/ucmstate.cpp"
  "deps/icu-small/source/tools/toolutil/xmlparser.cpp"
  "deps/icu-small/source/tools/toolutil/filetools.cpp"
  "deps/icu-small/source/tools/toolutil/toolutil.cpp"
  "deps/icu-small/source/tools/toolutil/package.cpp"
  "deps/icu-small/source/tools/toolutil/ucln_tu.cpp"
  "deps/icu-small/source/tools/toolutil/unewdata.cpp"
  "deps/icu-small/source/common/uniset.cpp"
  "deps/icu-small/source/common/dictbe.cpp"
  "deps/icu-small/source/common/chariter.cpp"
  "deps/icu-small/source/common/utf_impl.cpp"
  "deps/icu-small/source/common/uhash.cpp"
  "deps/icu-small/source/common/ushape.cpp"
  "deps/icu-small/source/common/ucnvsel.cpp"
  "deps/icu-small/source/common/uarrsort.cpp"
  "deps/icu-small/source/common/ucnv_set.cpp"
  "deps/icu-small/source/common/uniset_props.cpp"
  "deps/icu-small/source/common/caniter.cpp"
  "deps/icu-small/source/common/ubidiwrt.cpp"
  "deps/icu-small/source/common/ucnvscsu.cpp"
  "deps/icu-small/source/common/cstr.cpp"
  "deps/icu-small/source/common/wintz.cpp"
  "deps/icu-small/source/common/ubiditransform.cpp"
  "deps/icu-small/source/common/dictionarydata.cpp"
  "deps/icu-small/source/common/loclikelysubtags.cpp"
  "deps/icu-small/source/common/stringtriebuilder.cpp"
  "deps/icu-small/source/common/util.cpp"
  "deps/icu-small/source/common/cstring.cpp"
  "deps/icu-small/source/common/localeprioritylist.cpp"
  "deps/icu-small/source/common/uinit.cpp"
  "deps/icu-small/source/common/ucharstrieiterator.cpp"
  "deps/icu-small/source/common/unisetspan.cpp"
  "deps/icu-small/source/common/icuplug.cpp"
  "deps/icu-small/source/common/ucnv_ext.cpp"
  "deps/icu-small/source/common/servnotf.cpp"
  "deps/icu-small/source/common/locid.cpp"
  "deps/icu-small/source/common/ustr_cnv.cpp"
  "deps/icu-small/source/common/unames.cpp"
  "deps/icu-small/source/common/filterednormalizer2.cpp"
  "deps/icu-small/source/common/loclikely.cpp"
  "deps/icu-small/source/common/uscript_props.cpp"
  "deps/icu-small/source/common/bytestrieiterator.cpp"
  "deps/icu-small/source/common/propsvec.cpp"
  "deps/icu-small/source/common/ucnv_u32.cpp"
  "deps/icu-small/source/common/punycode.cpp"
  "deps/icu-small/source/common/ubidiln.cpp"
  "deps/icu-small/source/common/putil.cpp"
  "deps/icu-small/source/common/bytestrie.cpp"
  "deps/icu-small/source/common/resource.cpp"
  "deps/icu-small/source/common/uvector.cpp"
  "deps/icu-small/source/common/ucase.cpp"
  "deps/icu-small/source/common/rbbi.cpp"
  "deps/icu-small/source/common/locutil.cpp"
  "deps/icu-small/source/common/servls.cpp"
  "deps/icu-small/source/common/ucnvdisp.cpp"
  "deps/icu-small/source/common/ucnv_err.cpp"
  "deps/icu-small/source/common/unistr_titlecase_brkiter.cpp"
  "deps/icu-small/source/common/uloc_tag.cpp"
  "deps/icu-small/source/common/icudataver.cpp"
  "deps/icu-small/source/common/uenum.cpp"
  "deps/icu-small/source/common/rbbisetb.cpp"
  "deps/icu-small/source/common/filteredbrk.cpp"
  "deps/icu-small/source/common/ubrk.cpp"
  "deps/icu-small/source/common/ucnv_bld.cpp"
  "deps/icu-small/source/common/brkeng.cpp"
  "deps/icu-small/source/common/charstr.cpp"
  "deps/icu-small/source/common/uloc_keytype.cpp"
  "deps/icu-small/source/common/ucnv_ct.cpp"
  "deps/icu-small/source/common/bytestriebuilder.cpp"
  "deps/icu-small/source/common/ubidi.cpp"
  "deps/icu-small/source/common/ucnv_u8.cpp"
  "deps/icu-small/source/common/locdispnames.cpp"
  "deps/icu-small/source/common/ucnv_cb.cpp"
  "deps/icu-small/source/common/ustr_titlecase_brkiter.cpp"
  "deps/icu-small/source/common/locdistance.cpp"
  "deps/icu-small/source/common/static_unicode_sets.cpp"
  "deps/icu-small/source/common/bmpset.cpp"
  "deps/icu-small/source/common/uniset_closure.cpp"
  "deps/icu-small/source/common/locdspnm.cpp"
  "deps/icu-small/source/common/bytesinkutil.cpp"
  "deps/icu-small/source/common/rbbi_cache.cpp"
  "deps/icu-small/source/common/ucharstriebuilder.cpp"
  "deps/icu-small/source/common/utrie2.cpp"
  "deps/icu-small/source/common/unifiedcache.cpp"
  "deps/icu-small/source/common/servlkf.cpp"
  "deps/icu-small/source/common/schriter.cpp"
  "deps/icu-small/source/common/locbased.cpp"
  "deps/icu-small/source/common/udatamem.cpp"
  "deps/icu-small/source/common/umutablecptrie.cpp"
  "deps/icu-small/source/common/patternprops.cpp"
  "deps/icu-small/source/common/localebuilder.cpp"
  "deps/icu-small/source/common/unistr_props.cpp"
  "deps/icu-small/source/common/ucnv.cpp"
  "deps/icu-small/source/common/stringpiece.cpp"
  "deps/icu-small/source/common/ulist.cpp"
  "deps/icu-small/source/common/ustrtrns.cpp"
  "deps/icu-small/source/common/uiter.cpp"
  "deps/icu-small/source/common/cmemory.cpp"
  "deps/icu-small/source/common/resbund_cnv.cpp"
  "deps/icu-small/source/common/uvectr64.cpp"
  "deps/icu-small/source/common/unistr_case.cpp"
  "deps/icu-small/source/common/ustr_wcs.cpp"
  "deps/icu-small/source/common/ucnvlat1.cpp"
  "deps/icu-small/source/common/simpleformatter.cpp"
  "deps/icu-small/source/common/uts46.cpp"
  "deps/icu-small/source/common/ucnvmbcs.cpp"
  "deps/icu-small/source/common/locresdata.cpp"
  "deps/icu-small/source/common/pluralmap.cpp"
  "deps/icu-small/source/common/uprops.cpp"
  "deps/icu-small/source/common/usetiter.cpp"
  "deps/icu-small/source/common/propname.cpp"
  "deps/icu-small/source/common/rbbistbl.cpp"
  "deps/icu-small/source/common/ucat.cpp"
  "deps/icu-small/source/common/unifilt.cpp"
  "deps/icu-small/source/common/utrie_swap.cpp"
  "deps/icu-small/source/common/uresdata.cpp"
  "deps/icu-small/source/common/umapfile.cpp"
  "deps/icu-small/source/common/messagepattern.cpp"
  "deps/icu-small/source/common/locavailable.cpp"
  "deps/icu-small/source/common/ustrcase.cpp"
  "deps/icu-small/source/common/cwchar.cpp"
  "deps/icu-small/source/common/rbbiscan.cpp"
  "deps/icu-small/source/common/umath.cpp"
  "deps/icu-small/source/common/uset.cpp"
  "deps/icu-small/source/common/ucln_cmn.cpp"
  "deps/icu-small/source/common/ures_cnv.cpp"
  "deps/icu-small/source/common/normlzr.cpp"
  "deps/icu-small/source/common/ucmndata.cpp"
  "deps/icu-small/source/common/servlk.cpp"
  "deps/icu-small/source/common/edits.cpp"
  "deps/icu-small/source/common/ucnvbocu.cpp"
  "deps/icu-small/source/common/ustrfmt.cpp"
  "deps/icu-small/source/common/parsepos.cpp"
  "deps/icu-small/source/common/loadednormalizer2impl.cpp"
  "deps/icu-small/source/common/udata.cpp"
  "deps/icu-small/source/common/errorcode.cpp"
  "deps/icu-small/source/common/uchriter.cpp"
  "deps/icu-small/source/common/ucnv_lmb.cpp"
  "deps/icu-small/source/common/ucurr.cpp"
  "deps/icu-small/source/common/udataswp.cpp"
  "deps/icu-small/source/common/restrace.cpp"
  "deps/icu-small/source/common/ustrcase_locale.cpp"
  "deps/icu-small/source/common/localematcher.cpp"
  "deps/icu-small/source/common/unistr.cpp"
  "deps/icu-small/source/common/ucnvhz.cpp"
  "deps/icu-small/source/common/normalizer2.cpp"
  "deps/icu-small/source/common/sharedobject.cpp"
  "deps/icu-small/source/common/resbund.cpp"
  "deps/icu-small/source/common/uhash_us.cpp"
  "deps/icu-small/source/common/serv.cpp"
  "deps/icu-small/source/common/utrie.cpp"
  "deps/icu-small/source/common/umutex.cpp"
  "deps/icu-small/source/common/unorm.cpp"
  "deps/icu-small/source/common/uidna.cpp"
  "deps/icu-small/source/common/servrbf.cpp"
  "deps/icu-small/source/common/ucnv_u7.cpp"
  "deps/icu-small/source/common/ruleiter.cpp"
  "deps/icu-small/source/common/uset_props.cpp"
  "deps/icu-small/source/common/appendable.cpp"
  "deps/icu-small/source/common/lsr.cpp"
  "deps/icu-small/source/common/utypes.cpp"
  "deps/icu-small/source/common/ucasemap.cpp"
  "deps/icu-small/source/common/usc_impl.cpp"
  "deps/icu-small/source/common/uresbund.cpp"
  "deps/icu-small/source/common/rbbidata.cpp"
  "deps/icu-small/source/common/unormcmp.cpp"
  "deps/icu-small/source/common/ucptrie.cpp"
  "deps/icu-small/source/common/ubidi_props.cpp"
  "deps/icu-small/source/common/uchar.cpp"
  "deps/icu-small/source/common/normalizer2impl.cpp"
  "deps/icu-small/source/common/ucnvisci.cpp"
  "deps/icu-small/source/common/unistr_cnv.cpp"
  "deps/icu-small/source/common/rbbirb.cpp"
  "deps/icu-small/source/common/unifunct.cpp"
  "deps/icu-small/source/common/characterproperties.cpp"
  "deps/icu-small/source/common/ustack.cpp"
  "deps/icu-small/source/common/uinvchar.cpp"
  "deps/icu-small/source/common/ucasemap_titlecase_brkiter.cpp"
  "deps/icu-small/source/common/bytestream.cpp"
  "deps/icu-small/source/common/ustring.cpp"
  "deps/icu-small/source/common/usprep.cpp"
  "deps/icu-small/source/common/servslkf.cpp"
  "deps/icu-small/source/common/rbbitblb.cpp"
  "deps/icu-small/source/common/ucnv_u16.cpp"
  "deps/icu-small/source/common/util_props.cpp"
  "deps/icu-small/source/common/uloc.cpp"
  "deps/icu-small/source/common/ustrenum.cpp"
  "deps/icu-small/source/common/ucnv_io.cpp"
  "deps/icu-small/source/common/unistr_case_locale.cpp"
  "deps/icu-small/source/common/uobject.cpp"
  "deps/icu-small/source/common/ucnv_cnv.cpp"
  "deps/icu-small/source/common/ucnv2022.cpp"
  "deps/icu-small/source/common/ucol_swp.cpp"
  "deps/icu-small/source/common/dtintrv.cpp"
  "deps/icu-small/source/common/rbbinode.cpp"
  "deps/icu-small/source/common/ucharstrie.cpp"
  "deps/icu-small/source/common/uscript.cpp"
  "deps/icu-small/source/common/utext.cpp"
  "deps/icu-small/source/common/locmap.cpp"
  "deps/icu-small/source/common/utrie2_builder.cpp"
  "deps/icu-small/source/common/uvectr32.cpp"
  "deps/icu-small/source/common/utrace.cpp"
  "deps/icu-small/source/common/brkiter.cpp"
  "deps/icu-small/source/i18n/nultrans.cpp"
  "deps/icu-small/source/i18n/uspoof_conf.cpp"
  "deps/icu-small/source/i18n/japancal.cpp"
  "deps/icu-small/source/i18n/tmunit.cpp"
  "deps/icu-small/source/i18n/decimfmt.cpp"
  "deps/icu-small/source/i18n/taiwncal.cpp"
  "deps/icu-small/source/i18n/formattedval_iterimpl.cpp"
  "deps/icu-small/source/i18n/transreg.cpp"
  "deps/icu-small/source/i18n/number_rounding.cpp"
  "deps/icu-small/source/i18n/collationweights.cpp"
  "deps/icu-small/source/i18n/smpdtfst.cpp"
  "deps/icu-small/source/i18n/collationruleparser.cpp"
  "deps/icu-small/source/i18n/decNumber.cpp"
  "deps/icu-small/source/i18n/fmtable_cnv.cpp"
  "deps/icu-small/source/i18n/regeximp.cpp"
  "deps/icu-small/source/i18n/collation.cpp"
  "deps/icu-small/source/i18n/number_patternmodifier.cpp"
  "deps/icu-small/source/i18n/collationsets.cpp"
  "deps/icu-small/source/i18n/number_decimalquantity.cpp"
  "deps/icu-small/source/i18n/number_asformat.cpp"
  "deps/icu-small/source/i18n/numrange_impl.cpp"
  "deps/icu-small/source/i18n/usearch.cpp"
  "deps/icu-small/source/i18n/ucoleitr.cpp"
  "deps/icu-small/source/i18n/double-conversion-fast-dtoa.cpp"
  "deps/icu-small/source/i18n/number_decimfmtprops.cpp"
  "deps/icu-small/source/i18n/number_scientific.cpp"
  "deps/icu-small/source/i18n/measure.cpp"
  "deps/icu-small/source/i18n/persncal.cpp"
  "deps/icu-small/source/i18n/ztrans.cpp"
  "deps/icu-small/source/i18n/dtfmtsym.cpp"
  "deps/icu-small/source/i18n/ucsdet.cpp"
  "deps/icu-small/source/i18n/collationdatawriter.cpp"
  "deps/icu-small/source/i18n/formatted_string_builder.cpp"
  "deps/icu-small/source/i18n/regextxt.cpp"
  "deps/icu-small/source/i18n/coleitr.cpp"
  "deps/icu-small/source/i18n/csrutf8.cpp"
  "deps/icu-small/source/i18n/uitercollationiterator.cpp"
  "deps/icu-small/source/i18n/tznames.cpp"
  "deps/icu-small/source/i18n/collationfcd.cpp"
  "deps/icu-small/source/i18n/tzrule.cpp"
  "deps/icu-small/source/i18n/gender.cpp"
  "deps/icu-small/source/i18n/number_formatimpl.cpp"
  "deps/icu-small/source/i18n/msgfmt.cpp"
  "deps/icu-small/source/i18n/scientificnumberformatter.cpp"
  "deps/icu-small/source/i18n/toupptrn.cpp"
  "deps/icu-small/source/i18n/sortkey.cpp"
  "deps/icu-small/source/i18n/alphaindex.cpp"
  "deps/icu-small/source/i18n/collationkeys.cpp"
  "deps/icu-small/source/i18n/number_affixutils.cpp"
  "deps/icu-small/source/i18n/collationfastlatin.cpp"
  "deps/icu-small/source/i18n/choicfmt.cpp"
  "deps/icu-small/source/i18n/gregocal.cpp"
  "deps/icu-small/source/i18n/unumsys.cpp"
  "deps/icu-small/source/i18n/sharedbreakiterator.cpp"
  "deps/icu-small/source/i18n/numparse_parsednumber.cpp"
  "deps/icu-small/source/i18n/format.cpp"
  "deps/icu-small/source/i18n/scriptset.cpp"
  "deps/icu-small/source/i18n/utf16collationiterator.cpp"
  "deps/icu-small/source/i18n/uspoof_build.cpp"
  "deps/icu-small/source/i18n/casetrn.cpp"
  "deps/icu-small/source/i18n/nfrs.cpp"
  "deps/icu-small/source/i18n/csdetect.cpp"
  "deps/icu-small/source/i18n/numparse_symbols.cpp"
  "deps/icu-small/source/i18n/umsg.cpp"
  "deps/icu-small/source/i18n/gregoimp.cpp"
  "deps/icu-small/source/i18n/dtitvfmt.cpp"
  "deps/icu-small/source/i18n/collationsettings.cpp"
  "deps/icu-small/source/i18n/regexst.cpp"
  "deps/icu-small/source/i18n/number_fluent.cpp"
  "deps/icu-small/source/i18n/translit.cpp"
  "deps/icu-small/source/i18n/plurfmt.cpp"
  "deps/icu-small/source/i18n/dtitvinf.cpp"
  "deps/icu-small/source/i18n/upluralrules.cpp"
  "deps/icu-small/source/i18n/collationdatareader.cpp"
  "deps/icu-small/source/i18n/dtptngen.cpp"
  "deps/icu-small/source/i18n/number_padding.cpp"
  "deps/icu-small/source/i18n/fmtable.cpp"
  "deps/icu-small/source/i18n/chnsecal.cpp"
  "deps/icu-small/source/i18n/uregex.cpp"
  "deps/icu-small/source/i18n/dtrule.cpp"
  "deps/icu-small/source/i18n/ulocdata.cpp"
  "deps/icu-small/source/i18n/tridpars.cpp"
  "deps/icu-small/source/i18n/cpdtrans.cpp"
  "deps/icu-small/source/i18n/collationbuilder.cpp"
  "deps/icu-small/source/i18n/number_grouping.cpp"
  "deps/icu-small/source/i18n/standardplural.cpp"
  "deps/icu-small/source/i18n/ethpccal.cpp"
  "deps/icu-small/source/i18n/olsontz.cpp"
  "deps/icu-small/source/i18n/rbt_rule.cpp"
  "deps/icu-small/source/i18n/collationtailoring.cpp"
  "deps/icu-small/source/i18n/collationfastlatinbuilder.cpp"
  "deps/icu-small/source/i18n/csrucode.cpp"
  "deps/icu-small/source/i18n/astro.cpp"
  "deps/icu-small/source/i18n/numfmt.cpp"
  "deps/icu-small/source/i18n/rbt.cpp"
  "deps/icu-small/source/i18n/udatpg.cpp"
  "deps/icu-small/source/i18n/numparse_validators.cpp"
  "deps/icu-small/source/i18n/strrepl.cpp"
  "deps/icu-small/source/i18n/ucal.cpp"
  "deps/icu-small/source/i18n/double-conversion-cached-powers.cpp"
  "deps/icu-small/source/i18n/timezone.cpp"
  "deps/icu-small/source/i18n/quant.cpp"
  "deps/icu-small/source/i18n/bocsu.cpp"
  "deps/icu-small/source/i18n/erarules.cpp"
  "deps/icu-small/source/i18n/currpinf.cpp"
  "deps/icu-small/source/i18n/number_notation.cpp"
  "deps/icu-small/source/i18n/windtfmt.cpp"
  "deps/icu-small/source/i18n/funcrepl.cpp"
  "deps/icu-small/source/i18n/calendar.cpp"
  "deps/icu-small/source/i18n/number_multiplier.cpp"
  "deps/icu-small/source/i18n/smpdtfmt.cpp"
  "deps/icu-small/source/i18n/ulistformatter.cpp"
  "deps/icu-small/source/i18n/uregion.cpp"
  "deps/icu-small/source/i18n/number_compact.cpp"
  "deps/icu-small/source/i18n/rulebasedcollator.cpp"
  "deps/icu-small/source/i18n/name2uni.cpp"
  "deps/icu-small/source/i18n/number_longnames.cpp"
  "deps/icu-small/source/i18n/stsearch.cpp"
  "deps/icu-small/source/i18n/strmatch.cpp"
  "deps/icu-small/source/i18n/ucln_in.cpp"
  "deps/icu-small/source/i18n/zrule.cpp"
  "deps/icu-small/source/i18n/coll.cpp"
  "deps/icu-small/source/i18n/numrange_fluent.cpp"
  "deps/icu-small/source/i18n/quantityformatter.cpp"
  "deps/icu-small/source/i18n/selfmt.cpp"
  "deps/icu-small/source/i18n/collationrootelements.cpp"
  "deps/icu-small/source/i18n/double-conversion-strtod.cpp"
  "deps/icu-small/source/i18n/numparse_decimal.cpp"
  "deps/icu-small/source/i18n/nounit.cpp"
  "deps/icu-small/source/i18n/cecal.cpp"
  "deps/icu-small/source/i18n/titletrn.cpp"
  "deps/icu-small/source/i18n/double-conversion-double-to-string.cpp"
  "deps/icu-small/source/i18n/nfsubs.cpp"
  "deps/icu-small/source/i18n/numparse_affixes.cpp"
  "deps/icu-small/source/i18n/vzone.cpp"
  "deps/icu-small/source/i18n/numsys.cpp"
  "deps/icu-small/source/i18n/dcfmtsym.cpp"
  "deps/icu-small/source/i18n/number_currencysymbols.cpp"
  "deps/icu-small/source/i18n/collationiterator.cpp"
  "deps/icu-small/source/i18n/fphdlimp.cpp"
  "deps/icu-small/source/i18n/hebrwcal.cpp"
  "deps/icu-small/source/i18n/csrsbcs.cpp"
  "deps/icu-small/source/i18n/rbt_pars.cpp"
  "deps/icu-small/source/i18n/csr2022.cpp"
  "deps/icu-small/source/i18n/search.cpp"
  "deps/icu-small/source/i18n/zonemeta.cpp"
  "deps/icu-small/source/i18n/reldtfmt.cpp"
  "deps/icu-small/source/i18n/number_output.cpp"
  "deps/icu-small/source/i18n/inputext.cpp"
  "deps/icu-small/source/i18n/double-conversion-bignum-dtoa.cpp"
  "deps/icu-small/source/i18n/ufieldpositer.cpp"
  "deps/icu-small/source/i18n/winnmfmt.cpp"
  "deps/icu-small/source/i18n/utf8collationiterator.cpp"
  "deps/icu-small/source/i18n/anytrans.cpp"
  "deps/icu-small/source/i18n/collationdata.cpp"
  "deps/icu-small/source/i18n/unesctrn.cpp"
  "deps/icu-small/source/i18n/ucol_sit.cpp"
  "deps/icu-small/source/i18n/remtrans.cpp"
  "deps/icu-small/source/i18n/nortrans.cpp"
  "deps/icu-small/source/i18n/islamcal.cpp"
  "deps/icu-small/source/i18n/numparse_scientific.cpp"
  "deps/icu-small/source/i18n/dangical.cpp"
  "deps/icu-small/source/i18n/formattedvalue.cpp"
  "deps/icu-small/source/i18n/currfmt.cpp"
  "deps/icu-small/source/i18n/tmutfmt.cpp"
  "deps/icu-small/source/i18n/number_skeletons.cpp"
  "deps/icu-small/source/i18n/ucol.cpp"
  "deps/icu-small/source/i18n/currunit.cpp"
  "deps/icu-small/source/i18n/uspoof.cpp"
  "deps/icu-small/source/i18n/collationroot.cpp"
  "deps/icu-small/source/i18n/number_integerwidth.cpp"
  "deps/icu-small/source/i18n/decContext.cpp"
  "deps/icu-small/source/i18n/number_utils.cpp"
  "deps/icu-small/source/i18n/double-conversion-bignum.cpp"
  "deps/icu-small/source/i18n/rbt_set.cpp"
  "deps/icu-small/source/i18n/number_capi.cpp"
  "deps/icu-small/source/i18n/tzfmt.cpp"
  "deps/icu-small/source/i18n/uregexc.cpp"
  "deps/icu-small/source/i18n/measfmt.cpp"
  "deps/icu-small/source/i18n/brktrans.cpp"
  "deps/icu-small/source/i18n/tmutamt.cpp"
  "deps/icu-small/source/i18n/coptccal.cpp"
  "deps/icu-small/source/i18n/wintzimpl.cpp"
  "deps/icu-small/source/i18n/indiancal.cpp"
  "deps/icu-small/source/i18n/number_mapper.cpp"
  "deps/icu-small/source/i18n/basictz.cpp"
  "deps/icu-small/source/i18n/region.cpp"
  "deps/icu-small/source/i18n/dayperiodrules.cpp"
  "deps/icu-small/source/i18n/csrmbcs.cpp"
  "deps/icu-small/source/i18n/number_modifiers.cpp"
  "deps/icu-small/source/i18n/rbnf.cpp"
  "deps/icu-small/source/i18n/esctrn.cpp"
  "deps/icu-small/source/i18n/ucol_res.cpp"
  "deps/icu-small/source/i18n/regexcmp.cpp"
  "deps/icu-small/source/i18n/plurrule.cpp"
  "deps/icu-small/source/i18n/double-conversion-string-to-double.cpp"
  "deps/icu-small/source/i18n/string_segment.cpp"
  "deps/icu-small/source/i18n/csmatch.cpp"
  "deps/icu-small/source/i18n/simpletz.cpp"
  "deps/icu-small/source/i18n/formattedval_sbimpl.cpp"
  "deps/icu-small/source/i18n/compactdecimalformat.cpp"
  "deps/icu-small/source/i18n/tznames_impl.cpp"
  "deps/icu-small/source/i18n/numparse_currency.cpp"
  "deps/icu-small/source/i18n/fpositer.cpp"
  "deps/icu-small/source/i18n/nfrule.cpp"
  "deps/icu-small/source/i18n/numparse_compositions.cpp"
  "deps/icu-small/source/i18n/utmscale.cpp"
  "deps/icu-small/source/i18n/utrans.cpp"
  "deps/icu-small/source/i18n/listformatter.cpp"
  "deps/icu-small/source/i18n/curramt.cpp"
  "deps/icu-small/source/i18n/measunit.cpp"
  "deps/icu-small/source/i18n/buddhcal.cpp"
  "deps/icu-small/source/i18n/udateintervalformat.cpp"
  "deps/icu-small/source/i18n/uspoof_impl.cpp"
  "deps/icu-small/source/i18n/tzgnames.cpp"
  "deps/icu-small/source/i18n/rematch.cpp"
  "deps/icu-small/source/i18n/datefmt.cpp"
  "deps/icu-small/source/i18n/reldatefmt.cpp"
  "deps/icu-small/source/i18n/vtzone.cpp"
  "deps/icu-small/source/i18n/tztrans.cpp"
  "deps/icu-small/source/i18n/collationdatabuilder.cpp"
  "deps/icu-small/source/i18n/repattrn.cpp"
  "deps/icu-small/source/i18n/collationcompare.cpp"
  "deps/icu-small/source/i18n/rbt_data.cpp"
  "deps/icu-small/source/i18n/csrecog.cpp"
  "deps/icu-small/source/i18n/number_patternstring.cpp"
  "deps/icu-small/source/i18n/udat.cpp"
  "deps/icu-small/source/i18n/tolowtrn.cpp"
  "deps/icu-small/source/i18n/numparse_impl.cpp"
  "deps/icu-small/source/i18n/unum.cpp"
  "deps/icu-small/source/i18n/rbtz.cpp"
  "deps/icu-small/source/i18n/uni2name.cpp"
  "deps/icu-small/source/stubdata/stubdata.cpp")
list(APPEND icutools_host__other_srcs
  "deps/icu-small/source/tools/toolutil/swapimpl.h"
  "deps/icu-small/source/tools/toolutil/unewdata.h"
  "deps/icu-small/source/tools/toolutil/denseranges.h"
  "deps/icu-small/source/tools/toolutil/xmlparser.h"
  "deps/icu-small/source/tools/toolutil/filestrm.h"
  "deps/icu-small/source/tools/toolutil/pkg_icu.h"
  "deps/icu-small/source/tools/toolutil/ucbuf.h"
  "deps/icu-small/source/tools/toolutil/pkg_genc.h"
  "deps/icu-small/source/tools/toolutil/flagparser.h"
  "deps/icu-small/source/tools/toolutil/package.h"
  "deps/icu-small/source/tools/toolutil/filetools.h"
  "deps/icu-small/source/tools/toolutil/uparse.h"
  "deps/icu-small/source/tools/toolutil/toolutil.h"
  "deps/icu-small/source/tools/toolutil/writesrc.h"
  "deps/icu-small/source/tools/toolutil/ppucd.h"
  "deps/icu-small/source/tools/toolutil/pkg_imp.h"
  "deps/icu-small/source/tools/toolutil/uoptions.h"
  "deps/icu-small/source/tools/toolutil/pkg_gencmn.h"
  "deps/icu-small/source/tools/toolutil/collationinfo.h"
  "deps/icu-small/source/tools/toolutil/ucm.h"
  "deps/icu-small/source/common/rbbi_cache.h"
  "deps/icu-small/source/common/unisetspan.h"
  "deps/icu-small/source/common/localeprioritylist.h"
  "deps/icu-small/source/common/ureslocs.h"
  "deps/icu-small/source/common/propsvec.h"
  "deps/icu-small/source/common/rbbinode.h"
  "deps/icu-small/source/common/udatamem.h"
  "deps/icu-small/source/common/ucol_swp.h"
  "deps/icu-small/source/common/umutex.h"
  "deps/icu-small/source/common/locmap.h"
  "deps/icu-small/source/common/uvector.h"
  "deps/icu-small/source/common/uvectr32.h"
  "deps/icu-small/source/common/servnotf.h"
  "deps/icu-small/source/common/locdistance.h"
  "deps/icu-small/source/common/ustr_imp.h"
  "deps/icu-small/source/common/servloc.h"
  "deps/icu-small/source/common/ucln.h"
  "deps/icu-small/source/common/unormimp.h"
  "deps/icu-small/source/common/unifiedcache.h"
  "deps/icu-small/source/common/loclikelysubtags.h"
  "deps/icu-small/source/common/pluralmap.h"
  "deps/icu-small/source/common/uchar_props_data.h"
  "deps/icu-small/source/common/uresdata.h"
  "deps/icu-small/source/common/cpputils.h"
  "deps/icu-small/source/common/rbbidata.h"
  "deps/icu-small/source/common/uassert.h"
  "deps/icu-small/source/common/usc_impl.h"
  "deps/icu-small/source/common/uelement.h"
  "deps/icu-small/source/common/utrie2.h"
  "deps/icu-small/source/common/dictbe.h"
  "deps/icu-small/source/common/ucol_data.h"
  "deps/icu-small/source/common/locbased.h"
  "deps/icu-small/source/common/cmemory.h"
  "deps/icu-small/source/common/patternprops.h"
  "deps/icu-small/source/common/uresimp.h"
  "deps/icu-small/source/common/ubidi_props_data.h"
  "deps/icu-small/source/common/utracimp.h"
  "deps/icu-small/source/common/norm2allmodes.h"
  "deps/icu-small/source/common/ucptrie_impl.h"
  "deps/icu-small/source/common/msvcres.h"
  "deps/icu-small/source/common/utypeinfo.h"
  "deps/icu-small/source/common/ucnv_cnv.h"
  "deps/icu-small/source/common/static_unicode_sets.h"
  "deps/icu-small/source/common/sprpimpl.h"
  "deps/icu-small/source/common/cwchar.h"
  "deps/icu-small/source/common/umapfile.h"
  "deps/icu-small/source/common/ulocimp.h"
  "deps/icu-small/source/common/charstr.h"
  "deps/icu-small/source/common/ubidi_props.h"
  "deps/icu-small/source/common/ulayout_props.h"
  "deps/icu-small/source/common/punycode.h"
  "deps/icu-small/source/common/uposixdefs.h"
  "deps/icu-small/source/common/localsvc.h"
  "deps/icu-small/source/common/udataswp.h"
  "deps/icu-small/source/common/cstring.h"
  "deps/icu-small/source/common/propname.h"
  "deps/icu-small/source/common/uenumimp.h"
  "deps/icu-small/source/common/ulist.h"
  "deps/icu-small/source/common/dictionarydata.h"
  "deps/icu-small/source/common/sharedobject.h"
  "deps/icu-small/source/common/serv.h"
  "deps/icu-small/source/common/rbbiscan.h"
  "deps/icu-small/source/common/ucln_imp.h"
  "deps/icu-small/source/common/rbbisetb.h"
  "deps/icu-small/source/common/norm2_nfc_data.h"
  "deps/icu-small/source/common/propname_data.h"
  "deps/icu-small/source/common/ubidiimp.h"
  "deps/icu-small/source/common/ucnvmbcs.h"
  "deps/icu-small/source/common/uvectr64.h"
  "deps/icu-small/source/common/ucmndata.h"
  "deps/icu-small/source/common/rbbirb.h"
  "deps/icu-small/source/common/ubrkimpl.h"
  "deps/icu-small/source/common/ucnv_io.h"
  "deps/icu-small/source/common/util.h"
  "deps/icu-small/source/common/resource.h"
  "deps/icu-small/source/common/bmpset.h"
  "deps/icu-small/source/common/ustr_cnv.h"
  "deps/icu-small/source/common/utrie2_impl.h"
  "deps/icu-small/source/common/ucurrimp.h"
  "deps/icu-small/source/common/ucnv_ext.h"
  "deps/icu-small/source/common/ucase_props_data.h"
  "deps/icu-small/source/common/ucnv_bld.h"
  "deps/icu-small/source/common/normalizer2impl.h"
  "deps/icu-small/source/common/ustrfmt.h"
  "deps/icu-small/source/common/ustrenum.h"
  "deps/icu-small/source/common/uprops.h"
  "deps/icu-small/source/common/ucase.h"
  "deps/icu-small/source/common/unistrappender.h"
  "deps/icu-small/source/common/icuplugimp.h"
  "deps/icu-small/source/common/bytesinkutil.h"
  "deps/icu-small/source/common/brkeng.h"
  "deps/icu-small/source/common/uset_imp.h"
  "deps/icu-small/source/common/mutex.h"
  "deps/icu-small/source/common/rbbitblb.h"
  "deps/icu-small/source/common/locutil.h"
  "deps/icu-small/source/common/ucasemap_imp.h"
  "deps/icu-small/source/common/putilimp.h"
  "deps/icu-small/source/common/restrace.h"
  "deps/icu-small/source/common/rbbirpt.h"
  "deps/icu-small/source/common/uhash.h"
  "deps/icu-small/source/common/utrie.h"
  "deps/icu-small/source/common/ucnv_imp.h"
  "deps/icu-small/source/common/messageimpl.h"
  "deps/icu-small/source/common/capi_helper.h"
  "deps/icu-small/source/common/hash.h"
  "deps/icu-small/source/common/uarrsort.h"
  "deps/icu-small/source/common/cstr.h"
  "deps/icu-small/source/common/ruleiter.h"
  "deps/icu-small/source/common/ucln_cmn.h"
  "deps/icu-small/source/common/uinvchar.h"
  "deps/icu-small/source/common/wintz.h"
  "deps/icu-small/source/common/lsr.h"
  "deps/icu-small/source/i18n/anytrans.h"
  "deps/icu-small/source/i18n/zrule.h"
  "deps/icu-small/source/i18n/decNumberLocal.h"
  "deps/icu-small/source/i18n/japancal.h"
  "deps/icu-small/source/i18n/rbt.h"
  "deps/icu-small/source/i18n/taiwncal.h"
  "deps/icu-small/source/i18n/tridpars.h"
  "deps/icu-small/source/i18n/collationcompare.h"
  "deps/icu-small/source/i18n/double-conversion-ieee.h"
  "deps/icu-small/source/i18n/chnsecal.h"
  "deps/icu-small/source/i18n/erarules.h"
  "deps/icu-small/source/i18n/csrucode.h"
  "deps/icu-small/source/i18n/decNumber.h"
  "deps/icu-small/source/i18n/number_longnames.h"
  "deps/icu-small/source/i18n/nfrule.h"
  "deps/icu-small/source/i18n/toupptrn.h"
  "deps/icu-small/source/i18n/sharedpluralrules.h"
  "deps/icu-small/source/i18n/dtitv_impl.h"
  "deps/icu-small/source/i18n/casetrn.h"
  "deps/icu-small/source/i18n/numrange_impl.h"
  "deps/icu-small/source/i18n/collationbuilder.h"
  "deps/icu-small/source/i18n/double-conversion-cached-powers.h"
  "deps/icu-small/source/i18n/zonemeta.h"
  "deps/icu-small/source/i18n/uspoof_impl.h"
  "deps/icu-small/source/i18n/scriptset.h"
  "deps/icu-small/source/i18n/number_multiplier.h"
  "deps/icu-small/source/i18n/ucol_imp.h"
  "deps/icu-small/source/i18n/collationfcd.h"
  "deps/icu-small/source/i18n/numparse_currency.h"
  "deps/icu-small/source/i18n/winnmfmt.h"
  "deps/icu-small/source/i18n/cecal.h"
  "deps/icu-small/source/i18n/collationdatabuilder.h"
  "deps/icu-small/source/i18n/numparse_decimal.h"
  "deps/icu-small/source/i18n/nortrans.h"
  "deps/icu-small/source/i18n/number_mapper.h"
  "deps/icu-small/source/i18n/gregoimp.h"
  "deps/icu-small/source/i18n/remtrans.h"
  "deps/icu-small/source/i18n/ethpccal.h"
  "deps/icu-small/source/i18n/uni2name.h"
  "deps/icu-small/source/i18n/number_roundingutils.h"
  "deps/icu-small/source/i18n/csdetect.h"
  "deps/icu-small/source/i18n/collationkeys.h"
  "deps/icu-small/source/i18n/sharedbreakiterator.h"
  "deps/icu-small/source/i18n/cpdtrans.h"
  "deps/icu-small/source/i18n/funcrepl.h"
  "deps/icu-small/source/i18n/quant.h"
  "deps/icu-small/source/i18n/umsg_imp.h"
  "deps/icu-small/source/i18n/regexcmp.h"
  "deps/icu-small/source/i18n/collationdatareader.h"
  "deps/icu-small/source/i18n/double-conversion-utils.h"
  "deps/icu-small/source/i18n/number_patternmodifier.h"
  "deps/icu-small/source/i18n/selfmtimpl.h"
  "deps/icu-small/source/i18n/nfsubs.h"
  "deps/icu-small/source/i18n/quantityformatter.h"
  "deps/icu-small/source/i18n/double-conversion-bignum.h"
  "deps/icu-small/source/i18n/collationtailoring.h"
  "deps/icu-small/source/i18n/titletrn.h"
  "deps/icu-small/source/i18n/dt_impl.h"
  "deps/icu-small/source/i18n/ucln_in.h"
  "deps/icu-small/source/i18n/number_affixutils.h"
  "deps/icu-small/source/i18n/unesctrn.h"
  "deps/icu-small/source/i18n/rbt_rule.h"
  "deps/icu-small/source/i18n/numparse_utils.h"
  "deps/icu-small/source/i18n/vzone.h"
  "deps/icu-small/source/i18n/numparse_affixes.h"
  "deps/icu-small/source/i18n/smpdtfst.h"
  "deps/icu-small/source/i18n/inputext.h"
  "deps/icu-small/source/i18n/numparse_symbols.h"
  "deps/icu-small/source/i18n/number_formatimpl.h"
  "deps/icu-small/source/i18n/utf8collationiterator.h"
  "deps/icu-small/source/i18n/fmtableimp.h"
  "deps/icu-small/source/i18n/decContext.h"
  "deps/icu-small/source/i18n/regexst.h"
  "deps/icu-small/source/i18n/uitercollationiterator.h"
  "deps/icu-small/source/i18n/collationsettings.h"
  "deps/icu-small/source/i18n/number_currencysymbols.h"
  "deps/icu-small/source/i18n/numparse_types.h"
  "deps/icu-small/source/i18n/fphdlimp.h"
  "deps/icu-small/source/i18n/wintzimpl.h"
  "deps/icu-small/source/i18n/region_impl.h"
  "deps/icu-small/source/i18n/csrecog.h"
  "deps/icu-small/source/i18n/ztrans.h"
  "deps/icu-small/source/i18n/double-conversion-bignum-dtoa.h"
  "deps/icu-small/source/i18n/standardplural.h"
  "deps/icu-small/source/i18n/double-conversion-fast-dtoa.h"
  "deps/icu-small/source/i18n/collationdata.h"
  "deps/icu-small/source/i18n/collationfastlatinbuilder.h"
  "deps/icu-small/source/i18n/rbt_pars.h"
  "deps/icu-small/source/i18n/numparse_compositions.h"
  "deps/icu-small/source/i18n/number_microprops.h"
  "deps/icu-small/source/i18n/number_decnum.h"
  "deps/icu-small/source/i18n/csmatch.h"
  "deps/icu-small/source/i18n/persncal.h"
  "deps/icu-small/source/i18n/sharedcalendar.h"
  "deps/icu-small/source/i18n/csrutf8.h"
  "deps/icu-small/source/i18n/double-conversion.h"
  "deps/icu-small/source/i18n/regeximp.h"
  "deps/icu-small/source/i18n/regexcst.h"
  "deps/icu-small/source/i18n/formatted_string_builder.h"
  "deps/icu-small/source/i18n/strrepl.h"
  "deps/icu-small/source/i18n/formattedval_impl.h"
  "deps/icu-small/source/i18n/double-conversion-double-to-string.h"
  "deps/icu-small/source/i18n/bocsu.h"
  "deps/icu-small/source/i18n/esctrn.h"
  "deps/icu-small/source/i18n/collationweights.h"
  "deps/icu-small/source/i18n/buddhcal.h"
  "deps/icu-small/source/i18n/rbt_data.h"
  "deps/icu-small/source/i18n/string_segment.h"
  "deps/icu-small/source/i18n/nfrlist.h"
  "deps/icu-small/source/i18n/collationsets.h"
  "deps/icu-small/source/i18n/number_scientific.h"
  "deps/icu-small/source/i18n/transreg.h"
  "deps/icu-small/source/i18n/number_utypes.h"
  "deps/icu-small/source/i18n/olsontz.h"
  "deps/icu-small/source/i18n/dayperiodrules.h"
  "deps/icu-small/source/i18n/sharednumberformat.h"
  "deps/icu-small/source/i18n/collationrootelements.h"
  "deps/icu-small/source/i18n/indiancal.h"
  "deps/icu-small/source/i18n/uspoof_conf.h"
  "deps/icu-small/source/i18n/collationiterator.h"
  "deps/icu-small/source/i18n/utf16collationiterator.h"
  "deps/icu-small/source/i18n/csrsbcs.h"
  "deps/icu-small/source/i18n/strmatch.h"
  "deps/icu-small/source/i18n/islamcal.h"
  "deps/icu-small/source/i18n/number_patternstring.h"
  "deps/icu-small/source/i18n/usrchimp.h"
  "deps/icu-small/source/i18n/tzgnames.h"
  "deps/icu-small/source/i18n/tznames_impl.h"
  "deps/icu-small/source/i18n/csrmbcs.h"
  "deps/icu-small/source/i18n/dtptngen_impl.h"
  "deps/icu-small/source/i18n/number_decimalquantity.h"
  "deps/icu-small/source/i18n/nfrs.h"
  "deps/icu-small/source/i18n/number_modifiers.h"
  "deps/icu-small/source/i18n/msgfmt_impl.h"
  "deps/icu-small/source/i18n/numsys_impl.h"
  "deps/icu-small/source/i18n/name2uni.h"
  "deps/icu-small/source/i18n/numparse_scientific.h"
  "deps/icu-small/source/i18n/double-conversion-string-to-double.h"
  "deps/icu-small/source/i18n/number_types.h"
  "deps/icu-small/source/i18n/nultrans.h"
  "deps/icu-small/source/i18n/dangical.h"
  "deps/icu-small/source/i18n/tolowtrn.h"
  "deps/icu-small/source/i18n/collunsafe.h"
  "deps/icu-small/source/i18n/windtfmt.h"
  "deps/icu-small/source/i18n/coptccal.h"
  "deps/icu-small/source/i18n/shareddateformatsymbols.h"
  "deps/icu-small/source/i18n/regextxt.h"
  "deps/icu-small/source/i18n/collationruleparser.h"
  "deps/icu-small/source/i18n/number_decimfmtprops.h"
  "deps/icu-small/source/i18n/numparse_impl.h"
  "deps/icu-small/source/i18n/number_skeletons.h"
  "deps/icu-small/source/i18n/reldtfmt.h"
  "deps/icu-small/source/i18n/number_utils.h"
  "deps/icu-small/source/i18n/rbt_set.h"
  "deps/icu-small/source/i18n/collationdatawriter.h"
  "deps/icu-small/source/i18n/plurrule_impl.h"
  "deps/icu-small/source/i18n/currfmt.h"
  "deps/icu-small/source/i18n/hebrwcal.h"
  "deps/icu-small/source/i18n/brktrans.h"
  "deps/icu-small/source/i18n/csr2022.h"
  "deps/icu-small/source/i18n/double-conversion-strtod.h"
  "deps/icu-small/source/i18n/double-conversion-diy-fp.h"
  "deps/icu-small/source/i18n/number_asformat.h"
  "deps/icu-small/source/i18n/collation.h"
  "deps/icu-small/source/i18n/numparse_validators.h"
  "deps/icu-small/source/i18n/number_compact.h"
  "deps/icu-small/source/i18n/astro.h"
  "deps/icu-small/source/i18n/collationfastlatin.h"
  "deps/icu-small/source/i18n/collationroot.h")
add_library(icutools_host STATIC ${icutools_host__cxx_srcs} ${icutools_host__other_srcs})
set_target_properties(icutools_host PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${icutools_host__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(icutools_host PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/icu")
set_target_properties(icutools_host PROPERTIES PREFIX "lib")
set_target_properties(icutools_host PROPERTIES ARCHIVE_OUTPUT_NAME "icutools")
set_target_properties(icutools_host PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/icu/libicutools.a PROPERTIES GENERATED "TRUE")
list(APPEND icutools_host__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/tools/toolutil")
set_property(TARGET icutools_host APPEND PROPERTY INCLUDE_DIRECTORIES ${icutools_host__include_dirs})
set_target_properties(icutools_host PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;U_COMMON_IMPLEMENTATION=1;U_I18N_IMPLEMENTATION=1;U_IO_IMPLEMENTATION=1;U_TOOLUTIL_IMPLEMENTATION=1;U_ATTRIBUTE_DEPRECATED=;_CRT_SECURE_NO_DEPRECATE=;U_STATIC_IMPLEMENTATION=1;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(icutools_host PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-exceptions -fno-strict-aliasing ")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "YES")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(icutools_host PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(icutools_host
  icu_implementation_host
  icu_uconfig_host
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icuuc#host
set(TARGET "icuuc")
set(TOOLSET "host")
add_custom_target(icuuc_host SOURCES)
set_target_properties(icuuc_host PROPERTIES EXCLUDE_FROM_ALL "TRUE")
add_dependencies(icuuc_host
  icutools_host
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icupkg#host
set(TARGET "icupkg")
set(TOOLSET "host")
list(APPEND icupkg_host__cxx_srcs
  "deps/icu-small/source/tools/icupkg/icupkg.cpp"
  "tools/icu/no-op.cc")
add_executable(icupkg_host ${icupkg_host__cxx_srcs})
set_target_properties(icupkg_host PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(icupkg_host PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(icupkg_host PROPERTIES PREFIX "")
set_target_properties(icupkg_host PROPERTIES RUNTIME_OUTPUT_NAME "icupkg")
set_target_properties(icupkg_host PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/icupkg PROPERTIES GENERATED "TRUE")
list(APPEND icupkg_host__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/tools/toolutil")
set_property(TARGET icupkg_host APPEND PROPERTY INCLUDE_DIRECTORIES ${icupkg_host__include_dirs})
set_target_properties(icupkg_host PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(icupkg_host PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(icupkg_host PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(icupkg_host
  icu_implementation_host
  icu_uconfig_host
)
target_link_libraries(icupkg_host
  icutools_host
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:iculslocs#host
set(TARGET "iculslocs")
set(TOOLSET "host")
list(APPEND iculslocs_host__cxx_srcs
  "tools/icu/iculslocs.cc"
  "tools/icu/no-op.cc")
add_executable(iculslocs_host ${iculslocs_host__cxx_srcs})
set_target_properties(iculslocs_host PROPERTIES EXCLUDE_FROM_ALL "TRUE")
set_target_properties(iculslocs_host PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(iculslocs_host PROPERTIES PREFIX "")
set_target_properties(iculslocs_host PROPERTIES RUNTIME_OUTPUT_NAME "iculslocs")
set_target_properties(iculslocs_host PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/iculslocs PROPERTIES GENERATED "TRUE")
list(APPEND iculslocs_host__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/tools/toolutil")
set_property(TARGET iculslocs_host APPEND PROPERTY INCLUDE_DIRECTORIES ${iculslocs_host__include_dirs})
set_target_properties(iculslocs_host PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(iculslocs_host PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(iculslocs_host PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(iculslocs_host
  icu_implementation_host
  icu_uconfig_host
)
target_link_libraries(iculslocs_host
  icutools_host
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icui18n#host
set(TARGET "icui18n")
set(TOOLSET "host")
add_custom_target(icui18n_host SOURCES)
set_target_properties(icui18n_host PROPERTIES EXCLUDE_FROM_ALL "TRUE")
add_dependencies(icui18n_host
  icutools_host
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:genrb#host
set(TARGET "genrb")
set(TOOLSET "host")
list(APPEND genrb_host__c_srcs
  "deps/icu-small/source/tools/genrb/errmsg.c"
  "deps/icu-small/source/tools/genrb/read.c"
  "deps/icu-small/source/tools/genrb/ustr.c"
  "deps/icu-small/source/tools/genrb/rle.c"
  "deps/icu-small/source/tools/genrb/rbutil.c")
list(APPEND genrb_host__cxx_srcs
  "deps/icu-small/source/tools/genrb/parse.cpp"
  "deps/icu-small/source/tools/genrb/reslist.cpp"
  "deps/icu-small/source/tools/genrb/genrb.cpp"
  "deps/icu-small/source/tools/genrb/filterrb.cpp"
  "deps/icu-small/source/tools/genrb/wrtjava.cpp"
  "deps/icu-small/source/tools/genrb/prscmnts.cpp"
  "deps/icu-small/source/tools/genrb/wrtxml.cpp")
list(APPEND genrb_host__other_srcs
  "deps/icu-small/source/tools/genrb/ustr.h"
  "deps/icu-small/source/tools/genrb/rle.h"
  "deps/icu-small/source/tools/genrb/prscmnts.h"
  "deps/icu-small/source/tools/genrb/rbutil.h"
  "deps/icu-small/source/tools/genrb/reslist.h"
  "deps/icu-small/source/tools/genrb/parse.h"
  "deps/icu-small/source/tools/genrb/genrb.h"
  "deps/icu-small/source/tools/genrb/read.h"
  "deps/icu-small/source/tools/genrb/filterrb.h"
  "deps/icu-small/source/tools/genrb/errmsg.h")
add_executable(genrb_host ${genrb_host__c_srcs} ${genrb_host__cxx_srcs} ${genrb_host__other_srcs})
set_target_properties(genrb_host PROPERTIES EXCLUDE_FROM_ALL "TRUE")
set_source_files_properties(${genrb_host__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(genrb_host PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(genrb_host PROPERTIES PREFIX "")
set_target_properties(genrb_host PROPERTIES RUNTIME_OUTPUT_NAME "genrb")
set_target_properties(genrb_host PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/genrb PROPERTIES GENERATED "TRUE")
list(APPEND genrb_host__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/tools/toolutil")
set_property(TARGET genrb_host APPEND PROPERTY INCLUDE_DIRECTORIES ${genrb_host__include_dirs})
set_target_properties(genrb_host PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_source_files_properties(${genrb_host__c_srcs} PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -fno-strict-aliasing ")
set_source_files_properties(${genrb_host__cxx_srcs} PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(genrb_host PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(genrb_host
  icu_implementation_host
  icu_uconfig_host
)
target_link_libraries(genrb_host
  icutools_host
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:genccode#host
set(TARGET "genccode")
set(TOOLSET "host")
set(genccode_host__c_srcs "deps/icu-small/source/tools/genccode/genccode.c")
set(genccode_host__cxx_srcs "tools/icu/no-op.cc")
add_executable(genccode_host ${genccode_host__c_srcs} ${genccode_host__cxx_srcs})
set_target_properties(genccode_host PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(genccode_host PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(genccode_host PROPERTIES PREFIX "")
set_target_properties(genccode_host PROPERTIES RUNTIME_OUTPUT_NAME "genccode")
set_target_properties(genccode_host PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/genccode PROPERTIES GENERATED "TRUE")
list(APPEND genccode_host__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/tools/toolutil")
set_property(TARGET genccode_host APPEND PROPERTY INCLUDE_DIRECTORIES ${genccode_host__include_dirs})
set_target_properties(genccode_host PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_source_files_properties(${genccode_host__c_srcs} PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -fno-strict-aliasing ")
set_source_files_properties(${genccode_host__cxx_srcs} PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(genccode_host PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(genccode_host
  icu_implementation_host
  icu_uconfig_host
)
target_link_libraries(genccode_host
  icutools_host
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icudata#target
set(TARGET "icudata")
set(TOOLSET "target")
set(icudata__icupkg__input "${CMAKE_CURRENT_LIST_DIR}/deps/icu-tmp/icudt65l.dat")
set(icudata__icupkg__output "${obj}/gen/icudt65l.dat")
add_custom_command(OUTPUT ${icudata__icupkg__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen
  COMMAND "${builddir}/icupkg" -tl ../../deps/icu-tmp/icudt65l.dat "${obj}/gen/icudt65l.dat"
  DEPENDS ${icudata__icupkg__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tools/icu
  COMMENT icudata__icupkg
  VERBATIM
)
add_custom_target(icudata__icupkg
  DEPENDS ${icudata__icupkg__output}
  SOURCES ${icudata__icupkg__input}
)
set(icudata__copy__input "${obj}/gen/icudt65l.dat")
set(icudata__copy__output "${obj}/gen/icudt65.dat")
add_custom_command(OUTPUT ${icudata__copy__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen
  COMMAND cp "${obj}/gen/icudt65l.dat" "${obj}/gen/icudt65.dat"
  DEPENDS ${icudata__copy__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tools/icu
  COMMENT icudata__copy
  VERBATIM
)
add_custom_target(icudata__copy
  DEPENDS ${icudata__copy__output}
  SOURCES ${icudata__copy__input}
)
set(icudata__icudata__input "${obj}/gen/icudt65.dat")
set(icudata__icudata__output "${obj}/gen/icudt65_dat.S")
add_custom_command(OUTPUT ${icudata__icudata__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen
  COMMAND "${builddir}/genccode" -e icudt65 -d "${obj}/gen" -a gcc-darwin -f icudt65_dat "${obj}/gen/icudt65.dat"
  DEPENDS ${icudata__icudata__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tools/icu
  COMMENT icudata__icudata
  VERBATIM
)
add_custom_target(icudata__icudata
  DEPENDS ${icudata__icudata__output}
  SOURCES ${icudata__icudata__input}
)
set(icudata__asm_srcs "${obj}/gen/icudt65_dat.S")
add_library(icudata STATIC ${icudata__asm_srcs})
set_target_properties(icudata PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(icudata__icupkg PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(icudata__copy PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(icudata__icudata PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(icudata PROPERTIES LINKER_LANGUAGE "C")
set_target_properties(icudata PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/icu")
set_target_properties(icudata PROPERTIES PREFIX "lib")
set_target_properties(icudata PROPERTIES ARCHIVE_OUTPUT_NAME "icudata")
set_target_properties(icudata PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/icu/libicudata.a PROPERTIES GENERATED "TRUE")
set(icudata__include_dirs "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET icudata APPEND PROPERTY INCLUDE_DIRECTORIES ${icudata__include_dirs})
set_target_properties(icudata PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;U_ATTRIBUTE_DEPRECATED=;_CRT_SECURE_NO_DEPRECATE=;U_STATIC_IMPLEMENTATION=1;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(icudata PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "YES")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(icudata PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(icudata__icupkg
  genccode_host
  icupkg_host
  icu_implementation_host
  icu_uconfig
)
add_dependencies(icudata__copy
  genccode_host
  icupkg_host
  icu_implementation_host
  icu_uconfig
)
add_dependencies(icudata__icudata
  genccode_host
  icupkg_host
  icu_implementation_host
  icu_uconfig
)
add_dependencies(icudata
  genccode_host
  icupkg_host
  icu_implementation_host
  icu_uconfig
  icudata__icupkg
  icudata__copy
  icudata__icudata
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/icu/icu-generic.gyp:icuuc#target
set(TARGET "icuuc")
set(TOOLSET "target")
add_custom_target(icuuc SOURCES)
set_target_properties(icuuc PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(icuuc
  icuucx
  icudata
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_maybe_icu#target
set(TARGET "v8_maybe_icu")
set(TOOLSET "target")
add_custom_target(v8_maybe_icu SOURCES)
set_target_properties(v8_maybe_icu PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(v8_maybe_icu
  icuuc
  icui18n
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_nosnapshot#target
set(TARGET "v8_nosnapshot")
set(TOOLSET "target")
list(APPEND v8_nosnapshot__cxx_srcs
  "tools/v8_gypfiles/extras-libraries.cc"
  "deps/v8/src/snapshot/embedded/embedded-empty.cc"
  "deps/v8/src/snapshot/snapshot-empty.cc")
set(v8_nosnapshot__other_srcs "${obj}/gen/generate-bytecode-output-root/builtins-generated/bytecodes-builtins-list.h")
add_library(v8_nosnapshot STATIC ${v8_nosnapshot__cxx_srcs} ${v8_nosnapshot__other_srcs})
set_target_properties(v8_nosnapshot PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${v8_nosnapshot__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(v8_nosnapshot PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(v8_nosnapshot PROPERTIES PREFIX "lib")
set_target_properties(v8_nosnapshot PROPERTIES ARCHIVE_OUTPUT_NAME "v8_nosnapshot")
set_target_properties(v8_nosnapshot PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libv8_nosnapshot.a PROPERTIES GENERATED "TRUE")
list(APPEND v8_nosnapshot__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${obj}/gen/generate-bytecode-output-root"
  "${obj}/gen/torque-output-root"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET v8_nosnapshot APPEND PROPERTY INCLUDE_DIRECTORIES ${v8_nosnapshot__include_dirs})
set_target_properties(v8_nosnapshot PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(v8_nosnapshot PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(v8_nosnapshot PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(v8_nosnapshot
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_compiler_opt#target
set(TARGET "v8_compiler_opt")
set(TOOLSET "target")
list(APPEND v8_compiler_opt__cxx_srcs
  "deps/v8/src/compiler/access-builder.cc"
  "deps/v8/src/compiler/access-info.cc"
  "deps/v8/src/compiler/all-nodes.cc"
  "deps/v8/src/compiler/backend/code-generator.cc"
  "deps/v8/src/compiler/backend/frame-elider.cc"
  "deps/v8/src/compiler/backend/gap-resolver.cc"
  "deps/v8/src/compiler/backend/instruction-scheduler.cc"
  "deps/v8/src/compiler/backend/instruction-selector.cc"
  "deps/v8/src/compiler/backend/instruction.cc"
  "deps/v8/src/compiler/backend/jump-threading.cc"
  "deps/v8/src/compiler/backend/live-range-separator.cc"
  "deps/v8/src/compiler/backend/move-optimizer.cc"
  "deps/v8/src/compiler/backend/register-allocator-verifier.cc"
  "deps/v8/src/compiler/backend/register-allocator.cc"
  "deps/v8/src/compiler/basic-block-instrumentor.cc"
  "deps/v8/src/compiler/branch-elimination.cc"
  "deps/v8/src/compiler/bytecode-analysis.cc"
  "deps/v8/src/compiler/bytecode-graph-builder.cc"
  "deps/v8/src/compiler/bytecode-liveness-map.cc"
  "deps/v8/src/compiler/c-linkage.cc"
  "deps/v8/src/compiler/checkpoint-elimination.cc"
  "deps/v8/src/compiler/code-assembler.cc"
  "deps/v8/src/compiler/common-node-cache.cc"
  "deps/v8/src/compiler/common-operator-reducer.cc"
  "deps/v8/src/compiler/common-operator.cc"
  "deps/v8/src/compiler/compilation-dependencies.cc"
  "deps/v8/src/compiler/compiler-source-position-table.cc"
  "deps/v8/src/compiler/constant-folding-reducer.cc"
  "deps/v8/src/compiler/control-equivalence.cc"
  "deps/v8/src/compiler/control-flow-optimizer.cc"
  "deps/v8/src/compiler/csa-load-elimination.cc"
  "deps/v8/src/compiler/dead-code-elimination.cc"
  "deps/v8/src/compiler/decompression-elimination.cc"
  "deps/v8/src/compiler/effect-control-linearizer.cc"
  "deps/v8/src/compiler/escape-analysis-reducer.cc"
  "deps/v8/src/compiler/escape-analysis.cc"
  "deps/v8/src/compiler/feedback-source.cc"
  "deps/v8/src/compiler/frame-states.cc"
  "deps/v8/src/compiler/frame.cc"
  "deps/v8/src/compiler/graph-assembler.cc"
  "deps/v8/src/compiler/graph-reducer.cc"
  "deps/v8/src/compiler/graph-trimmer.cc"
  "deps/v8/src/compiler/graph-visualizer.cc"
  "deps/v8/src/compiler/graph.cc"
  "deps/v8/src/compiler/int64-lowering.cc"
  "deps/v8/src/compiler/js-call-reducer.cc"
  "deps/v8/src/compiler/js-context-specialization.cc"
  "deps/v8/src/compiler/js-create-lowering.cc"
  "deps/v8/src/compiler/js-generic-lowering.cc"
  "deps/v8/src/compiler/js-graph.cc"
  "deps/v8/src/compiler/js-heap-broker.cc"
  "deps/v8/src/compiler/js-heap-copy-reducer.cc"
  "deps/v8/src/compiler/js-inlining-heuristic.cc"
  "deps/v8/src/compiler/js-inlining.cc"
  "deps/v8/src/compiler/js-intrinsic-lowering.cc"
  "deps/v8/src/compiler/js-native-context-specialization.cc"
  "deps/v8/src/compiler/js-operator.cc"
  "deps/v8/src/compiler/js-type-hint-lowering.cc"
  "deps/v8/src/compiler/js-typed-lowering.cc"
  "deps/v8/src/compiler/linkage.cc"
  "deps/v8/src/compiler/load-elimination.cc"
  "deps/v8/src/compiler/loop-analysis.cc"
  "deps/v8/src/compiler/loop-peeling.cc"
  "deps/v8/src/compiler/loop-variable-optimizer.cc"
  "deps/v8/src/compiler/machine-graph-verifier.cc"
  "deps/v8/src/compiler/machine-graph.cc"
  "deps/v8/src/compiler/machine-operator-reducer.cc"
  "deps/v8/src/compiler/machine-operator.cc"
  "deps/v8/src/compiler/map-inference.cc"
  "deps/v8/src/compiler/memory-lowering.cc"
  "deps/v8/src/compiler/memory-optimizer.cc"
  "deps/v8/src/compiler/node-cache.cc"
  "deps/v8/src/compiler/node-marker.cc"
  "deps/v8/src/compiler/node-matchers.cc"
  "deps/v8/src/compiler/node-origin-table.cc"
  "deps/v8/src/compiler/node-properties.cc"
  "deps/v8/src/compiler/node.cc"
  "deps/v8/src/compiler/opcodes.cc"
  "deps/v8/src/compiler/operation-typer.cc"
  "deps/v8/src/compiler/operator-properties.cc"
  "deps/v8/src/compiler/operator.cc"
  "deps/v8/src/compiler/osr.cc"
  "deps/v8/src/compiler/pipeline-statistics.cc"
  "deps/v8/src/compiler/pipeline.cc"
  "deps/v8/src/compiler/property-access-builder.cc"
  "deps/v8/src/compiler/raw-machine-assembler.cc"
  "deps/v8/src/compiler/redundancy-elimination.cc"
  "deps/v8/src/compiler/refs-map.cc"
  "deps/v8/src/compiler/representation-change.cc"
  "deps/v8/src/compiler/schedule.cc"
  "deps/v8/src/compiler/scheduler.cc"
  "deps/v8/src/compiler/select-lowering.cc"
  "deps/v8/src/compiler/serializer-for-background-compilation.cc"
  "deps/v8/src/compiler/simd-scalar-lowering.cc"
  "deps/v8/src/compiler/simplified-lowering.cc"
  "deps/v8/src/compiler/simplified-operator-reducer.cc"
  "deps/v8/src/compiler/simplified-operator.cc"
  "deps/v8/src/compiler/state-values-utils.cc"
  "deps/v8/src/compiler/store-store-elimination.cc"
  "deps/v8/src/compiler/add-type-assertions-reducer.cc"
  "deps/v8/src/compiler/type-cache.cc"
  "deps/v8/src/compiler/type-narrowing-reducer.cc"
  "deps/v8/src/compiler/typed-optimization.cc"
  "deps/v8/src/compiler/typer.cc"
  "deps/v8/src/compiler/types.cc"
  "deps/v8/src/compiler/value-numbering-reducer.cc"
  "deps/v8/src/compiler/verifier.cc"
  "deps/v8/src/compiler/wasm-compiler.cc"
  "deps/v8/src/compiler/zone-stats.cc")
list(APPEND v8_compiler_opt__other_srcs
  "deps/v8/src/compiler/access-builder.h"
  "deps/v8/src/compiler/access-info.h"
  "deps/v8/src/compiler/all-nodes.h"
  "deps/v8/src/compiler/allocation-builder-inl.h"
  "deps/v8/src/compiler/allocation-builder.h"
  "deps/v8/src/compiler/backend/code-generator-impl.h"
  "deps/v8/src/compiler/backend/code-generator.h"
  "deps/v8/src/compiler/backend/frame-elider.h"
  "deps/v8/src/compiler/backend/gap-resolver.h"
  "deps/v8/src/compiler/backend/instruction-codes.h"
  "deps/v8/src/compiler/backend/instruction-scheduler.h"
  "deps/v8/src/compiler/backend/instruction-selector-impl.h"
  "deps/v8/src/compiler/backend/instruction-selector.h"
  "deps/v8/src/compiler/backend/instruction.h"
  "deps/v8/src/compiler/backend/jump-threading.h"
  "deps/v8/src/compiler/backend/live-range-separator.h"
  "deps/v8/src/compiler/backend/move-optimizer.h"
  "deps/v8/src/compiler/backend/register-allocator-verifier.h"
  "deps/v8/src/compiler/backend/register-allocator.h"
  "deps/v8/src/compiler/backend/unwinding-info-writer.h"
  "deps/v8/src/compiler/basic-block-instrumentor.h"
  "deps/v8/src/compiler/branch-elimination.h"
  "deps/v8/src/compiler/bytecode-analysis.h"
  "deps/v8/src/compiler/bytecode-graph-builder.h"
  "deps/v8/src/compiler/bytecode-liveness-map.h"
  "deps/v8/src/compiler/checkpoint-elimination.h"
  "deps/v8/src/compiler/code-assembler.h"
  "deps/v8/src/compiler/common-node-cache.h"
  "deps/v8/src/compiler/common-operator-reducer.h"
  "deps/v8/src/compiler/common-operator.h"
  "deps/v8/src/compiler/compilation-dependencies.h"
  "deps/v8/src/compiler/compiler-source-position-table.h"
  "deps/v8/src/compiler/constant-folding-reducer.h"
  "deps/v8/src/compiler/control-equivalence.h"
  "deps/v8/src/compiler/control-flow-optimizer.h"
  "deps/v8/src/compiler/csa-load-elimination.h"
  "deps/v8/src/compiler/dead-code-elimination.h"
  "deps/v8/src/compiler/decompression-elimination.h"
  "deps/v8/src/compiler/diamond.h"
  "deps/v8/src/compiler/effect-control-linearizer.h"
  "deps/v8/src/compiler/escape-analysis-reducer.h"
  "deps/v8/src/compiler/escape-analysis.h"
  "deps/v8/src/compiler/feedback-source.h"
  "deps/v8/src/compiler/frame-states.h"
  "deps/v8/src/compiler/frame.h"
  "deps/v8/src/compiler/functional-list.h"
  "deps/v8/src/compiler/graph-assembler.h"
  "deps/v8/src/compiler/graph-reducer.h"
  "deps/v8/src/compiler/graph-trimmer.h"
  "deps/v8/src/compiler/graph-visualizer.h"
  "deps/v8/src/compiler/graph.h"
  "deps/v8/src/compiler/int64-lowering.h"
  "deps/v8/src/compiler/js-call-reducer.h"
  "deps/v8/src/compiler/js-context-specialization.h"
  "deps/v8/src/compiler/js-create-lowering.h"
  "deps/v8/src/compiler/js-generic-lowering.h"
  "deps/v8/src/compiler/js-graph.h"
  "deps/v8/src/compiler/js-heap-broker.h"
  "deps/v8/src/compiler/js-heap-copy-reducer.h"
  "deps/v8/src/compiler/js-inlining-heuristic.h"
  "deps/v8/src/compiler/js-inlining.h"
  "deps/v8/src/compiler/js-intrinsic-lowering.h"
  "deps/v8/src/compiler/js-native-context-specialization.h"
  "deps/v8/src/compiler/js-operator.h"
  "deps/v8/src/compiler/js-type-hint-lowering.h"
  "deps/v8/src/compiler/js-typed-lowering.h"
  "deps/v8/src/compiler/linkage.h"
  "deps/v8/src/compiler/load-elimination.h"
  "deps/v8/src/compiler/loop-analysis.h"
  "deps/v8/src/compiler/loop-peeling.h"
  "deps/v8/src/compiler/loop-variable-optimizer.h"
  "deps/v8/src/compiler/machine-graph-verifier.h"
  "deps/v8/src/compiler/machine-graph.h"
  "deps/v8/src/compiler/machine-operator-reducer.h"
  "deps/v8/src/compiler/machine-operator.h"
  "deps/v8/src/compiler/map-inference.h"
  "deps/v8/src/compiler/memory-lowering.h"
  "deps/v8/src/compiler/memory-optimizer.h"
  "deps/v8/src/compiler/node-aux-data.h"
  "deps/v8/src/compiler/node-cache.h"
  "deps/v8/src/compiler/node-marker.h"
  "deps/v8/src/compiler/node-matchers.h"
  "deps/v8/src/compiler/node-origin-table.h"
  "deps/v8/src/compiler/node-properties.h"
  "deps/v8/src/compiler/node.h"
  "deps/v8/src/compiler/opcodes.h"
  "deps/v8/src/compiler/operation-typer.h"
  "deps/v8/src/compiler/operator-properties.h"
  "deps/v8/src/compiler/operator.h"
  "deps/v8/src/compiler/osr.h"
  "deps/v8/src/compiler/per-isolate-compiler-cache.h"
  "deps/v8/src/compiler/persistent-map.h"
  "deps/v8/src/compiler/pipeline-statistics.h"
  "deps/v8/src/compiler/pipeline.h"
  "deps/v8/src/compiler/property-access-builder.h"
  "deps/v8/src/compiler/raw-machine-assembler.h"
  "deps/v8/src/compiler/redundancy-elimination.h"
  "deps/v8/src/compiler/refs-map.h"
  "deps/v8/src/compiler/representation-change.h"
  "deps/v8/src/compiler/schedule.h"
  "deps/v8/src/compiler/scheduler.h"
  "deps/v8/src/compiler/select-lowering.h"
  "deps/v8/src/compiler/serializer-for-background-compilation.h"
  "deps/v8/src/compiler/simd-scalar-lowering.h"
  "deps/v8/src/compiler/simplified-lowering.h"
  "deps/v8/src/compiler/simplified-operator-reducer.h"
  "deps/v8/src/compiler/simplified-operator.h"
  "deps/v8/src/compiler/state-values-utils.h"
  "deps/v8/src/compiler/store-store-elimination.h"
  "deps/v8/src/compiler/add-type-assertions-reducer.h"
  "deps/v8/src/compiler/type-cache.h"
  "deps/v8/src/compiler/type-narrowing-reducer.h"
  "deps/v8/src/compiler/typed-optimization.h"
  "deps/v8/src/compiler/typer.h"
  "deps/v8/src/compiler/types.h"
  "deps/v8/src/compiler/value-numbering-reducer.h"
  "deps/v8/src/compiler/verifier.h"
  "deps/v8/src/compiler/wasm-compiler.h"
  "deps/v8/src/compiler/write-barrier-kind.h"
  "deps/v8/src/compiler/zone-stats.h"
  "${obj}/gen/generate-bytecode-output-root/builtins-generated/bytecodes-builtins-list.h")
add_library(v8_compiler_opt STATIC ${v8_compiler_opt__cxx_srcs} ${v8_compiler_opt__other_srcs})
set_target_properties(v8_compiler_opt PROPERTIES EXCLUDE_FROM_ALL "TRUE")
set_source_files_properties(${v8_compiler_opt__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(v8_compiler_opt PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(v8_compiler_opt PROPERTIES PREFIX "lib")
set_target_properties(v8_compiler_opt PROPERTIES ARCHIVE_OUTPUT_NAME "v8_compiler_opt")
set_target_properties(v8_compiler_opt PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libv8_compiler_opt.a PROPERTIES GENERATED "TRUE")
list(APPEND v8_compiler_opt__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${obj}/gen/generate-bytecode-output-root"
  "${obj}/gen/torque-output-root"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET v8_compiler_opt APPEND PROPERTY INCLUDE_DIRECTORIES ${v8_compiler_opt__include_dirs})
set_target_properties(v8_compiler_opt PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(v8_compiler_opt PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(v8_compiler_opt PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(v8_compiler_opt
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_compiler#target
set(TARGET "v8_compiler")
set(TOOLSET "target")
list(APPEND v8_compiler__cxx_srcs
  "deps/v8/src/compiler/access-builder.cc"
  "deps/v8/src/compiler/access-info.cc"
  "deps/v8/src/compiler/all-nodes.cc"
  "deps/v8/src/compiler/backend/code-generator.cc"
  "deps/v8/src/compiler/backend/frame-elider.cc"
  "deps/v8/src/compiler/backend/gap-resolver.cc"
  "deps/v8/src/compiler/backend/instruction-scheduler.cc"
  "deps/v8/src/compiler/backend/instruction-selector.cc"
  "deps/v8/src/compiler/backend/instruction.cc"
  "deps/v8/src/compiler/backend/jump-threading.cc"
  "deps/v8/src/compiler/backend/live-range-separator.cc"
  "deps/v8/src/compiler/backend/move-optimizer.cc"
  "deps/v8/src/compiler/backend/register-allocator-verifier.cc"
  "deps/v8/src/compiler/backend/register-allocator.cc"
  "deps/v8/src/compiler/basic-block-instrumentor.cc"
  "deps/v8/src/compiler/branch-elimination.cc"
  "deps/v8/src/compiler/bytecode-analysis.cc"
  "deps/v8/src/compiler/bytecode-graph-builder.cc"
  "deps/v8/src/compiler/bytecode-liveness-map.cc"
  "deps/v8/src/compiler/c-linkage.cc"
  "deps/v8/src/compiler/checkpoint-elimination.cc"
  "deps/v8/src/compiler/code-assembler.cc"
  "deps/v8/src/compiler/common-node-cache.cc"
  "deps/v8/src/compiler/common-operator-reducer.cc"
  "deps/v8/src/compiler/common-operator.cc"
  "deps/v8/src/compiler/compilation-dependencies.cc"
  "deps/v8/src/compiler/compiler-source-position-table.cc"
  "deps/v8/src/compiler/constant-folding-reducer.cc"
  "deps/v8/src/compiler/control-equivalence.cc"
  "deps/v8/src/compiler/control-flow-optimizer.cc"
  "deps/v8/src/compiler/csa-load-elimination.cc"
  "deps/v8/src/compiler/dead-code-elimination.cc"
  "deps/v8/src/compiler/decompression-elimination.cc"
  "deps/v8/src/compiler/effect-control-linearizer.cc"
  "deps/v8/src/compiler/escape-analysis-reducer.cc"
  "deps/v8/src/compiler/escape-analysis.cc"
  "deps/v8/src/compiler/feedback-source.cc"
  "deps/v8/src/compiler/frame-states.cc"
  "deps/v8/src/compiler/frame.cc"
  "deps/v8/src/compiler/graph-assembler.cc"
  "deps/v8/src/compiler/graph-reducer.cc"
  "deps/v8/src/compiler/graph-trimmer.cc"
  "deps/v8/src/compiler/graph-visualizer.cc"
  "deps/v8/src/compiler/graph.cc"
  "deps/v8/src/compiler/int64-lowering.cc"
  "deps/v8/src/compiler/js-call-reducer.cc"
  "deps/v8/src/compiler/js-context-specialization.cc"
  "deps/v8/src/compiler/js-create-lowering.cc"
  "deps/v8/src/compiler/js-generic-lowering.cc"
  "deps/v8/src/compiler/js-graph.cc"
  "deps/v8/src/compiler/js-heap-broker.cc"
  "deps/v8/src/compiler/js-heap-copy-reducer.cc"
  "deps/v8/src/compiler/js-inlining-heuristic.cc"
  "deps/v8/src/compiler/js-inlining.cc"
  "deps/v8/src/compiler/js-intrinsic-lowering.cc"
  "deps/v8/src/compiler/js-native-context-specialization.cc"
  "deps/v8/src/compiler/js-operator.cc"
  "deps/v8/src/compiler/js-type-hint-lowering.cc"
  "deps/v8/src/compiler/js-typed-lowering.cc"
  "deps/v8/src/compiler/linkage.cc"
  "deps/v8/src/compiler/load-elimination.cc"
  "deps/v8/src/compiler/loop-analysis.cc"
  "deps/v8/src/compiler/loop-peeling.cc"
  "deps/v8/src/compiler/loop-variable-optimizer.cc"
  "deps/v8/src/compiler/machine-graph-verifier.cc"
  "deps/v8/src/compiler/machine-graph.cc"
  "deps/v8/src/compiler/machine-operator-reducer.cc"
  "deps/v8/src/compiler/machine-operator.cc"
  "deps/v8/src/compiler/map-inference.cc"
  "deps/v8/src/compiler/memory-lowering.cc"
  "deps/v8/src/compiler/memory-optimizer.cc"
  "deps/v8/src/compiler/node-cache.cc"
  "deps/v8/src/compiler/node-marker.cc"
  "deps/v8/src/compiler/node-matchers.cc"
  "deps/v8/src/compiler/node-origin-table.cc"
  "deps/v8/src/compiler/node-properties.cc"
  "deps/v8/src/compiler/node.cc"
  "deps/v8/src/compiler/opcodes.cc"
  "deps/v8/src/compiler/operation-typer.cc"
  "deps/v8/src/compiler/operator-properties.cc"
  "deps/v8/src/compiler/operator.cc"
  "deps/v8/src/compiler/osr.cc"
  "deps/v8/src/compiler/pipeline-statistics.cc"
  "deps/v8/src/compiler/pipeline.cc"
  "deps/v8/src/compiler/property-access-builder.cc"
  "deps/v8/src/compiler/raw-machine-assembler.cc"
  "deps/v8/src/compiler/redundancy-elimination.cc"
  "deps/v8/src/compiler/refs-map.cc"
  "deps/v8/src/compiler/representation-change.cc"
  "deps/v8/src/compiler/schedule.cc"
  "deps/v8/src/compiler/scheduler.cc"
  "deps/v8/src/compiler/select-lowering.cc"
  "deps/v8/src/compiler/serializer-for-background-compilation.cc"
  "deps/v8/src/compiler/simd-scalar-lowering.cc"
  "deps/v8/src/compiler/simplified-lowering.cc"
  "deps/v8/src/compiler/simplified-operator-reducer.cc"
  "deps/v8/src/compiler/simplified-operator.cc"
  "deps/v8/src/compiler/state-values-utils.cc"
  "deps/v8/src/compiler/store-store-elimination.cc"
  "deps/v8/src/compiler/add-type-assertions-reducer.cc"
  "deps/v8/src/compiler/type-cache.cc"
  "deps/v8/src/compiler/type-narrowing-reducer.cc"
  "deps/v8/src/compiler/typed-optimization.cc"
  "deps/v8/src/compiler/typer.cc"
  "deps/v8/src/compiler/types.cc"
  "deps/v8/src/compiler/value-numbering-reducer.cc"
  "deps/v8/src/compiler/verifier.cc"
  "deps/v8/src/compiler/wasm-compiler.cc"
  "deps/v8/src/compiler/zone-stats.cc")
list(APPEND v8_compiler__other_srcs
  "deps/v8/src/compiler/access-builder.h"
  "deps/v8/src/compiler/access-info.h"
  "deps/v8/src/compiler/all-nodes.h"
  "deps/v8/src/compiler/allocation-builder-inl.h"
  "deps/v8/src/compiler/allocation-builder.h"
  "deps/v8/src/compiler/backend/code-generator-impl.h"
  "deps/v8/src/compiler/backend/code-generator.h"
  "deps/v8/src/compiler/backend/frame-elider.h"
  "deps/v8/src/compiler/backend/gap-resolver.h"
  "deps/v8/src/compiler/backend/instruction-codes.h"
  "deps/v8/src/compiler/backend/instruction-scheduler.h"
  "deps/v8/src/compiler/backend/instruction-selector-impl.h"
  "deps/v8/src/compiler/backend/instruction-selector.h"
  "deps/v8/src/compiler/backend/instruction.h"
  "deps/v8/src/compiler/backend/jump-threading.h"
  "deps/v8/src/compiler/backend/live-range-separator.h"
  "deps/v8/src/compiler/backend/move-optimizer.h"
  "deps/v8/src/compiler/backend/register-allocator-verifier.h"
  "deps/v8/src/compiler/backend/register-allocator.h"
  "deps/v8/src/compiler/backend/unwinding-info-writer.h"
  "deps/v8/src/compiler/basic-block-instrumentor.h"
  "deps/v8/src/compiler/branch-elimination.h"
  "deps/v8/src/compiler/bytecode-analysis.h"
  "deps/v8/src/compiler/bytecode-graph-builder.h"
  "deps/v8/src/compiler/bytecode-liveness-map.h"
  "deps/v8/src/compiler/checkpoint-elimination.h"
  "deps/v8/src/compiler/code-assembler.h"
  "deps/v8/src/compiler/common-node-cache.h"
  "deps/v8/src/compiler/common-operator-reducer.h"
  "deps/v8/src/compiler/common-operator.h"
  "deps/v8/src/compiler/compilation-dependencies.h"
  "deps/v8/src/compiler/compiler-source-position-table.h"
  "deps/v8/src/compiler/constant-folding-reducer.h"
  "deps/v8/src/compiler/control-equivalence.h"
  "deps/v8/src/compiler/control-flow-optimizer.h"
  "deps/v8/src/compiler/csa-load-elimination.h"
  "deps/v8/src/compiler/dead-code-elimination.h"
  "deps/v8/src/compiler/decompression-elimination.h"
  "deps/v8/src/compiler/diamond.h"
  "deps/v8/src/compiler/effect-control-linearizer.h"
  "deps/v8/src/compiler/escape-analysis-reducer.h"
  "deps/v8/src/compiler/escape-analysis.h"
  "deps/v8/src/compiler/feedback-source.h"
  "deps/v8/src/compiler/frame-states.h"
  "deps/v8/src/compiler/frame.h"
  "deps/v8/src/compiler/functional-list.h"
  "deps/v8/src/compiler/graph-assembler.h"
  "deps/v8/src/compiler/graph-reducer.h"
  "deps/v8/src/compiler/graph-trimmer.h"
  "deps/v8/src/compiler/graph-visualizer.h"
  "deps/v8/src/compiler/graph.h"
  "deps/v8/src/compiler/int64-lowering.h"
  "deps/v8/src/compiler/js-call-reducer.h"
  "deps/v8/src/compiler/js-context-specialization.h"
  "deps/v8/src/compiler/js-create-lowering.h"
  "deps/v8/src/compiler/js-generic-lowering.h"
  "deps/v8/src/compiler/js-graph.h"
  "deps/v8/src/compiler/js-heap-broker.h"
  "deps/v8/src/compiler/js-heap-copy-reducer.h"
  "deps/v8/src/compiler/js-inlining-heuristic.h"
  "deps/v8/src/compiler/js-inlining.h"
  "deps/v8/src/compiler/js-intrinsic-lowering.h"
  "deps/v8/src/compiler/js-native-context-specialization.h"
  "deps/v8/src/compiler/js-operator.h"
  "deps/v8/src/compiler/js-type-hint-lowering.h"
  "deps/v8/src/compiler/js-typed-lowering.h"
  "deps/v8/src/compiler/linkage.h"
  "deps/v8/src/compiler/load-elimination.h"
  "deps/v8/src/compiler/loop-analysis.h"
  "deps/v8/src/compiler/loop-peeling.h"
  "deps/v8/src/compiler/loop-variable-optimizer.h"
  "deps/v8/src/compiler/machine-graph-verifier.h"
  "deps/v8/src/compiler/machine-graph.h"
  "deps/v8/src/compiler/machine-operator-reducer.h"
  "deps/v8/src/compiler/machine-operator.h"
  "deps/v8/src/compiler/map-inference.h"
  "deps/v8/src/compiler/memory-lowering.h"
  "deps/v8/src/compiler/memory-optimizer.h"
  "deps/v8/src/compiler/node-aux-data.h"
  "deps/v8/src/compiler/node-cache.h"
  "deps/v8/src/compiler/node-marker.h"
  "deps/v8/src/compiler/node-matchers.h"
  "deps/v8/src/compiler/node-origin-table.h"
  "deps/v8/src/compiler/node-properties.h"
  "deps/v8/src/compiler/node.h"
  "deps/v8/src/compiler/opcodes.h"
  "deps/v8/src/compiler/operation-typer.h"
  "deps/v8/src/compiler/operator-properties.h"
  "deps/v8/src/compiler/operator.h"
  "deps/v8/src/compiler/osr.h"
  "deps/v8/src/compiler/per-isolate-compiler-cache.h"
  "deps/v8/src/compiler/persistent-map.h"
  "deps/v8/src/compiler/pipeline-statistics.h"
  "deps/v8/src/compiler/pipeline.h"
  "deps/v8/src/compiler/property-access-builder.h"
  "deps/v8/src/compiler/raw-machine-assembler.h"
  "deps/v8/src/compiler/redundancy-elimination.h"
  "deps/v8/src/compiler/refs-map.h"
  "deps/v8/src/compiler/representation-change.h"
  "deps/v8/src/compiler/schedule.h"
  "deps/v8/src/compiler/scheduler.h"
  "deps/v8/src/compiler/select-lowering.h"
  "deps/v8/src/compiler/serializer-for-background-compilation.h"
  "deps/v8/src/compiler/simd-scalar-lowering.h"
  "deps/v8/src/compiler/simplified-lowering.h"
  "deps/v8/src/compiler/simplified-operator-reducer.h"
  "deps/v8/src/compiler/simplified-operator.h"
  "deps/v8/src/compiler/state-values-utils.h"
  "deps/v8/src/compiler/store-store-elimination.h"
  "deps/v8/src/compiler/add-type-assertions-reducer.h"
  "deps/v8/src/compiler/type-cache.h"
  "deps/v8/src/compiler/type-narrowing-reducer.h"
  "deps/v8/src/compiler/typed-optimization.h"
  "deps/v8/src/compiler/typer.h"
  "deps/v8/src/compiler/types.h"
  "deps/v8/src/compiler/value-numbering-reducer.h"
  "deps/v8/src/compiler/verifier.h"
  "deps/v8/src/compiler/wasm-compiler.h"
  "deps/v8/src/compiler/write-barrier-kind.h"
  "deps/v8/src/compiler/zone-stats.h"
  "${obj}/gen/generate-bytecode-output-root/builtins-generated/bytecodes-builtins-list.h")
add_library(v8_compiler STATIC ${v8_compiler__cxx_srcs} ${v8_compiler__other_srcs})
set_target_properties(v8_compiler PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${v8_compiler__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(v8_compiler PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(v8_compiler PROPERTIES PREFIX "lib")
set_target_properties(v8_compiler PROPERTIES ARCHIVE_OUTPUT_NAME "v8_compiler")
set_target_properties(v8_compiler PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libv8_compiler.a PROPERTIES GENERATED "TRUE")
list(APPEND v8_compiler__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${obj}/gen/generate-bytecode-output-root"
  "${obj}/gen/torque-output-root"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET v8_compiler APPEND PROPERTY INCLUDE_DIRECTORIES ${v8_compiler__include_dirs})
set_target_properties(v8_compiler PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(v8_compiler PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(v8_compiler PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(v8_compiler
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_compiler_for_mksnapshot#target
set(TARGET "v8_compiler_for_mksnapshot")
set(TOOLSET "target")
set(v8_compiler_for_mksnapshot__other_srcs "${obj}/gen/generate-bytecode-output-root/builtins-generated/bytecodes-builtins-list.h")
add_custom_target(v8_compiler_for_mksnapshot SOURCES ${v8_compiler_for_mksnapshot__other_srcs})
set_target_properties(v8_compiler_for_mksnapshot PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(v8_compiler_for_mksnapshot
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  v8_compiler
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:torque_generated_initializers#target
set(TARGET "torque_generated_initializers")
set(TOOLSET "target")
set(torque_generated_initializers__other_srcs "${obj}/gen/generate-bytecode-output-root/builtins-generated/bytecodes-builtins-list.h")
add_custom_target(torque_generated_initializers SOURCES ${torque_generated_initializers__other_srcs})
set_target_properties(torque_generated_initializers PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(torque_generated_initializers
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_initializers#target
set(TARGET "v8_initializers")
set(TOOLSET "target")
list(APPEND v8_initializers__cxx_srcs
  "deps/v8/src/builtins/builtins-arguments-gen.cc"
  "deps/v8/src/builtins/builtins-array-gen.cc"
  "deps/v8/src/builtins/builtins-async-function-gen.cc"
  "deps/v8/src/builtins/builtins-async-gen.cc"
  "deps/v8/src/builtins/builtins-async-generator-gen.cc"
  "deps/v8/src/builtins/builtins-async-iterator-gen.cc"
  "deps/v8/src/builtins/builtins-bigint-gen.cc"
  "deps/v8/src/builtins/builtins-boolean-gen.cc"
  "deps/v8/src/builtins/builtins-call-gen.cc"
  "deps/v8/src/builtins/builtins-collections-gen.cc"
  "deps/v8/src/builtins/builtins-console-gen.cc"
  "deps/v8/src/builtins/builtins-constructor-gen.cc"
  "deps/v8/src/builtins/builtins-conversion-gen.cc"
  "deps/v8/src/builtins/builtins-date-gen.cc"
  "deps/v8/src/builtins/builtins-debug-gen.cc"
  "deps/v8/src/builtins/builtins-function-gen.cc"
  "deps/v8/src/builtins/builtins-generator-gen.cc"
  "deps/v8/src/builtins/builtins-global-gen.cc"
  "deps/v8/src/builtins/builtins-handler-gen.cc"
  "deps/v8/src/builtins/builtins-ic-gen.cc"
  "deps/v8/src/builtins/builtins-internal-gen.cc"
  "deps/v8/src/builtins/builtins-interpreter-gen.cc"
  "deps/v8/src/builtins/builtins-intl-gen.cc"
  "deps/v8/src/builtins/builtins-iterator-gen.cc"
  "deps/v8/src/builtins/builtins-lazy-gen.cc"
  "deps/v8/src/builtins/builtins-math-gen.cc"
  "deps/v8/src/builtins/builtins-microtask-queue-gen.cc"
  "deps/v8/src/builtins/builtins-number-gen.cc"
  "deps/v8/src/builtins/builtins-object-gen.cc"
  "deps/v8/src/builtins/builtins-promise-gen.cc"
  "deps/v8/src/builtins/builtins-proxy-gen.cc"
  "deps/v8/src/builtins/builtins-reflect-gen.cc"
  "deps/v8/src/builtins/builtins-regexp-gen.cc"
  "deps/v8/src/builtins/builtins-sharedarraybuffer-gen.cc"
  "deps/v8/src/builtins/builtins-string-gen.cc"
  "deps/v8/src/builtins/builtins-symbol-gen.cc"
  "deps/v8/src/builtins/builtins-typed-array-gen.cc"
  "deps/v8/src/builtins/builtins-wasm-gen.cc"
  "deps/v8/src/builtins/growable-fixed-array-gen.cc"
  "deps/v8/src/builtins/setup-builtins-internal.cc"
  "deps/v8/src/codegen/code-stub-assembler.cc"
  "deps/v8/src/heap/setup-heap-internal.cc"
  "deps/v8/src/ic/accessor-assembler.cc"
  "deps/v8/src/ic/binary-op-assembler.cc"
  "deps/v8/src/ic/keyed-store-generic.cc"
  "deps/v8/src/interpreter/interpreter-assembler.cc"
  "deps/v8/src/interpreter/interpreter-generator.cc"
  "deps/v8/src/interpreter/interpreter-intrinsics-generator.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/arguments-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-copywithin-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-every-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-filter-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-find-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-findindex-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-foreach-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-join-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-lastindexof-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-map-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-of-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-reduce-right-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-reduce-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-reverse-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-shift-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-slice-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-some-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-splice-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-unshift-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/array-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/base-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/bigint-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/boolean-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/collections-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/data-view-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/extras-utils-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/frames-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/growable-fixed-array-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/internal-coverage-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/iterator-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/math-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/object-fromentries-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/object-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-constructor-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-delete-property-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-get-property-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-get-prototype-of-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-has-property-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-is-extensible-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-prevent-extensions-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-revocable-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-revoke-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-set-property-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-set-prototype-of-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/proxy-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/reflect-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-exec-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-match-all-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-match-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-replace-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-search-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-source-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-split-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-test-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/regexp-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-endswith-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-html-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-iterator-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-pad-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-repeat-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-slice-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-startswith-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/string-substring-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/torque-internal-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-createtypedarray-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-every-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-filter-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-find-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-findindex-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-foreach-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-reduce-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-reduceright-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-slice-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-some-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-subarray-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/builtins/typed-array-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/third_party/v8/builtins/array-sort-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/test/torque/test-torque-tq-csa.cc"
  "${obj}/gen/torque-output-root/torque-generated/../../deps/v8/src/objects/intl-objects-tq-csa.cc"
  "deps/v8/src/builtins/x64/builtins-x64.cc"
  "${obj}/gen/torque-output-root/torque-generated/exported-macros-assembler-tq.cc")
list(APPEND v8_initializers__other_srcs
  "deps/v8/src/builtins/builtins-arguments-gen.h"
  "deps/v8/src/builtins/builtins-array-gen.h"
  "deps/v8/src/builtins/builtins-async-gen.h"
  "deps/v8/src/builtins/builtins-bigint-gen.h"
  "deps/v8/src/builtins/builtins-call-gen.h"
  "deps/v8/src/builtins/builtins-constructor-gen.h"
  "deps/v8/src/builtins/builtins-constructor.h"
  "deps/v8/src/builtins/builtins-data-view-gen.h"
  "deps/v8/src/builtins/builtins-iterator-gen.h"
  "deps/v8/src/builtins/builtins-lazy-gen.h"
  "deps/v8/src/builtins/builtins-math-gen.h"
  "deps/v8/src/builtins/builtins-promise-gen.h"
  "deps/v8/src/builtins/builtins-proxy-gen.h"
  "deps/v8/src/builtins/builtins-regexp-gen.h"
  "deps/v8/src/builtins/builtins-string-gen.h"
  "deps/v8/src/builtins/builtins-typed-array-gen.h"
  "deps/v8/src/builtins/builtins-utils-gen.h"
  "deps/v8/src/builtins/growable-fixed-array-gen.h"
  "deps/v8/src/codegen/code-stub-assembler.h"
  "deps/v8/src/ic/accessor-assembler.h"
  "deps/v8/src/ic/binary-op-assembler.h"
  "deps/v8/src/ic/keyed-store-generic.h"
  "deps/v8/src/interpreter/interpreter-assembler.h"
  "deps/v8/src/interpreter/interpreter-generator.h"
  "deps/v8/src/interpreter/interpreter-intrinsics-generator.h"
  "${obj}/gen/torque-output-root/torque-generated/exported-macros-assembler-tq.h"
  "${obj}/gen/torque-output-root/torque-generated/csa-types-tq.h")
add_library(v8_initializers STATIC ${v8_initializers__cxx_srcs} ${v8_initializers__other_srcs})
set_target_properties(v8_initializers PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${v8_initializers__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(v8_initializers PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(v8_initializers PROPERTIES PREFIX "lib")
set_target_properties(v8_initializers PROPERTIES ARCHIVE_OUTPUT_NAME "v8_initializers")
set_target_properties(v8_initializers PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libv8_initializers.a PROPERTIES GENERATED "TRUE")
list(APPEND v8_initializers__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${obj}/gen/torque-output-root"
  "${obj}/gen/generate-bytecode-output-root"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET v8_initializers APPEND PROPERTY INCLUDE_DIRECTORIES ${v8_initializers__include_dirs})
set_target_properties(v8_initializers PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(v8_initializers PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(v8_initializers PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(v8_initializers
  torque_generated_initializers
  icuuc
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_init#target
set(TARGET "v8_init")
set(TOOLSET "target")
set(v8_init__cxx_srcs "deps/v8/src/init/setup-isolate-full.cc")
set(v8_init__other_srcs "${obj}/gen/generate-bytecode-output-root/builtins-generated/bytecodes-builtins-list.h")
add_library(v8_init STATIC ${v8_init__cxx_srcs} ${v8_init__other_srcs})
set_target_properties(v8_init PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${v8_init__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(v8_init PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(v8_init PROPERTIES PREFIX "lib")
set_target_properties(v8_init PROPERTIES ARCHIVE_OUTPUT_NAME "v8_init")
set_target_properties(v8_init PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libv8_init.a PROPERTIES GENERATED "TRUE")
list(APPEND v8_init__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${obj}/gen/generate-bytecode-output-root"
  "${obj}/gen/torque-output-root"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET v8_init APPEND PROPERTY INCLUDE_DIRECTORIES ${v8_init__include_dirs})
set_target_properties(v8_init PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(v8_init PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(v8_init PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(v8_init
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:torque_generated_definitions#target
set(TARGET "torque_generated_definitions")
set(TOOLSET "target")
set(torque_generated_definitions__other_srcs "${obj}/gen/generate-bytecode-output-root/builtins-generated/bytecodes-builtins-list.h")
add_custom_target(torque_generated_definitions SOURCES ${torque_generated_definitions__other_srcs})
set_target_properties(torque_generated_definitions PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(torque_generated_definitions
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:gen-regexp-special-case#target
set(TARGET "gen-regexp-special-case")
set(TOOLSET "target")
set(gen-regexp-special-case__cxx_srcs "deps/v8/src/regexp/gen-regexp-special-case.cc")
add_executable(gen-regexp-special-case ${gen-regexp-special-case__cxx_srcs})
set_target_properties(gen-regexp-special-case PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(gen-regexp-special-case PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(gen-regexp-special-case PROPERTIES PREFIX "")
set_target_properties(gen-regexp-special-case PROPERTIES RUNTIME_OUTPUT_NAME "gen-regexp-special-case")
set_target_properties(gen-regexp-special-case PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/gen-regexp-special-case PROPERTIES GENERATED "TRUE")
list(APPEND gen-regexp-special-case__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET gen-regexp-special-case APPEND PROPERTY INCLUDE_DIRECTORIES ${gen-regexp-special-case__include_dirs})
set_target_properties(gen-regexp-special-case PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(gen-regexp-special-case PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(gen-regexp-special-case PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(gen-regexp-special-case
  v8_maybe_icu
  v8_headers
  v8_version
  icu_implementation
  icu_uconfig
  icu_uconfig_target
  icuuc
  icu_implementation_host
)
target_link_libraries(gen-regexp-special-case
  v8_libbase
  icui18n
  icuucx
  icudata
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:run_gen-regexp-special-case#target
set(TARGET "run_gen-regexp-special-case")
set(TOOLSET "target")
set(run_gen-regexp-special-case__run_gen-regexp-special-case_action__input "${builddir}/gen-regexp-special-case")
set(run_gen-regexp-special-case__run_gen-regexp-special-case_action__output "${obj}/gen/src/regexp/special-case.cc")
add_custom_command(OUTPUT ${run_gen-regexp-special-case__run_gen-regexp-special-case_action__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen/src/regexp
  COMMAND python ../../deps/v8/tools/run.py "${builddir}/gen-regexp-special-case" "${obj}/gen/src/regexp/special-case.cc"
  DEPENDS ${run_gen-regexp-special-case__run_gen-regexp-special-case_action__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tools/v8_gypfiles
  COMMENT run_gen-regexp-special-case__run_gen-regexp-special-case_action
  VERBATIM
)
add_custom_target(run_gen-regexp-special-case__run_gen-regexp-special-case_action
  DEPENDS ${run_gen-regexp-special-case__run_gen-regexp-special-case_action__output}
  SOURCES ${run_gen-regexp-special-case__run_gen-regexp-special-case_action__input}
)
add_custom_target(run_gen-regexp-special-case SOURCES)
set_target_properties(run_gen-regexp-special-case PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(run_gen-regexp-special-case__run_gen-regexp-special-case_action PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(run_gen-regexp-special-case__run_gen-regexp-special-case_action
  gen-regexp-special-case
)
add_dependencies(run_gen-regexp-special-case
  gen-regexp-special-case
  run_gen-regexp-special-case__run_gen-regexp-special-case_action
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_base_without_compiler#target
set(TARGET "v8_base_without_compiler")
set(TOOLSET "target")
set(v8_base_without_compiler__protocol_compatibility__input "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include/js_protocol.pdl")
set(v8_base_without_compiler__protocol_compatibility__output "${obj}/gen/inspector-generated-output-root/src/js_protocol.stamp")
add_custom_command(OUTPUT ${v8_base_without_compiler__protocol_compatibility__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen/inspector-generated-output-root/src
  COMMAND python ../../deps/v8/third_party/inspector_protocol/check_protocol_compatibility.py --stamp "${obj}/gen/inspector-generated-output-root/src/js_protocol.stamp" ../../deps/v8/include/js_protocol.pdl
  DEPENDS ${v8_base_without_compiler__protocol_compatibility__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tools/v8_gypfiles
  COMMENT Checking inspector protocol compatibility
  VERBATIM
)
add_custom_target(v8_base_without_compiler__protocol_compatibility
  DEPENDS ${v8_base_without_compiler__protocol_compatibility__output}
  SOURCES ${v8_base_without_compiler__protocol_compatibility__input}
)
list(APPEND v8_base_without_compiler__protocol_generated_sources__input
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include/js_protocol.pdl"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/src/inspector/inspector_protocol_config.json"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/base_string_adapter_cc.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/base_string_adapter_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/DispatcherBase_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/DispatcherBase_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/ErrorSupport_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/ErrorSupport_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/Forward_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/FrontendChannel_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/Object_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/Object_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/Parser_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/Parser_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/Protocol_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/ValueConversions_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/Values_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/lib/Values_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/templates/Exported_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/templates/Imported_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/templates/TypeBuilder_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/templates/TypeBuilder_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol/code_generator.py")
list(APPEND v8_base_without_compiler__protocol_generated_sources__output
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Forward.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Protocol.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Protocol.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Console.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Console.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Debugger.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Debugger.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/HeapProfiler.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/HeapProfiler.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Profiler.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Profiler.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Runtime.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Runtime.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Schema.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Schema.h"
  "${obj}/gen/inspector-generated-output-root/include/inspector/Debugger.h"
  "${obj}/gen/inspector-generated-output-root/include/inspector/Runtime.h"
  "${obj}/gen/inspector-generated-output-root/include/inspector/Schema.h")
add_custom_command(OUTPUT ${v8_base_without_compiler__protocol_generated_sources__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen/inspector-generated-output-root/src/inspector/protocol
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen/inspector-generated-output-root/include/inspector
  COMMAND python ../../deps/v8/third_party/inspector_protocol/code_generator.py --jinja_dir ../../deps/v8/third_party --output_base "${obj}/gen/inspector-generated-output-root/src/inspector" --config ../../deps/v8/src/inspector/inspector_protocol_config.json --inspector_protocol_dir ../../deps/v8/third_party/inspector_protocol
  DEPENDS ${v8_base_without_compiler__protocol_generated_sources__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tools/v8_gypfiles
  COMMENT Generating inspector protocol sources from protocol json
  VERBATIM
)
add_custom_target(v8_base_without_compiler__protocol_generated_sources
  DEPENDS ${v8_base_without_compiler__protocol_generated_sources__output}
  SOURCES ${v8_base_without_compiler__protocol_generated_sources__input}
)
list(APPEND v8_base_without_compiler__cxx_srcs
  "deps/v8/src/api/api-arguments.cc"
  "deps/v8/src/api/api-natives.cc"
  "deps/v8/src/api/api.cc"
  "deps/v8/src/asmjs/asm-js.cc"
  "deps/v8/src/asmjs/asm-parser.cc"
  "deps/v8/src/asmjs/asm-scanner.cc"
  "deps/v8/src/asmjs/asm-types.cc"
  "deps/v8/src/ast/ast-function-literal-id-reindexer.cc"
  "deps/v8/src/ast/ast-value-factory.cc"
  "deps/v8/src/ast/ast.cc"
  "deps/v8/src/ast/modules.cc"
  "deps/v8/src/ast/prettyprinter.cc"
  "deps/v8/src/ast/scopes.cc"
  "deps/v8/src/ast/source-range-ast-visitor.cc"
  "deps/v8/src/ast/variables.cc"
  "deps/v8/src/builtins/accessors.cc"
  "deps/v8/src/builtins/builtins-api.cc"
  "deps/v8/src/builtins/builtins-array.cc"
  "deps/v8/src/builtins/builtins-arraybuffer.cc"
  "deps/v8/src/builtins/builtins-async-module.cc"
  "deps/v8/src/builtins/builtins-bigint.cc"
  "deps/v8/src/builtins/builtins-call.cc"
  "deps/v8/src/builtins/builtins-callsite.cc"
  "deps/v8/src/builtins/builtins-collections.cc"
  "deps/v8/src/builtins/builtins-console.cc"
  "deps/v8/src/builtins/builtins-dataview.cc"
  "deps/v8/src/builtins/builtins-date.cc"
  "deps/v8/src/builtins/builtins-error.cc"
  "deps/v8/src/builtins/builtins-extras-utils.cc"
  "deps/v8/src/builtins/builtins-function.cc"
  "deps/v8/src/builtins/builtins-global.cc"
  "deps/v8/src/builtins/builtins-internal.cc"
  "deps/v8/src/builtins/builtins-intl.cc"
  "deps/v8/src/builtins/builtins-json.cc"
  "deps/v8/src/builtins/builtins-number.cc"
  "deps/v8/src/builtins/builtins-object.cc"
  "deps/v8/src/builtins/builtins-promise.cc"
  "deps/v8/src/builtins/builtins-reflect.cc"
  "deps/v8/src/builtins/builtins-regexp.cc"
  "deps/v8/src/builtins/builtins-sharedarraybuffer.cc"
  "deps/v8/src/builtins/builtins-string.cc"
  "deps/v8/src/builtins/builtins-symbol.cc"
  "deps/v8/src/builtins/builtins-trace.cc"
  "deps/v8/src/builtins/builtins-typed-array.cc"
  "deps/v8/src/builtins/builtins-weak-refs.cc"
  "deps/v8/src/builtins/builtins.cc"
  "deps/v8/src/builtins/constants-table-builder.cc"
  "deps/v8/src/codegen/assembler.cc"
  "deps/v8/src/codegen/bailout-reason.cc"
  "deps/v8/src/codegen/code-comments.cc"
  "deps/v8/src/codegen/code-desc.cc"
  "deps/v8/src/codegen/code-factory.cc"
  "deps/v8/src/codegen/code-reference.cc"
  "deps/v8/src/codegen/compilation-cache.cc"
  "deps/v8/src/codegen/compiler.cc"
  "deps/v8/src/codegen/constant-pool.cc"
  "deps/v8/src/codegen/external-reference-table.cc"
  "deps/v8/src/codegen/external-reference.cc"
  "deps/v8/src/codegen/flush-instruction-cache.cc"
  "deps/v8/src/codegen/handler-table.cc"
  "deps/v8/src/codegen/interface-descriptors.cc"
  "deps/v8/src/codegen/machine-type.cc"
  "deps/v8/src/codegen/optimized-compilation-info.cc"
  "deps/v8/src/codegen/pending-optimization-table.cc"
  "deps/v8/src/codegen/register-configuration.cc"
  "deps/v8/src/codegen/register.cc"
  "deps/v8/src/codegen/reloc-info.cc"
  "deps/v8/src/codegen/safepoint-table.cc"
  "deps/v8/src/codegen/source-position-table.cc"
  "deps/v8/src/codegen/source-position.cc"
  "deps/v8/src/codegen/string-constants.cc"
  "deps/v8/src/codegen/tick-counter.cc"
  "deps/v8/src/codegen/turbo-assembler.cc"
  "deps/v8/src/codegen/unoptimized-compilation-info.cc"
  "deps/v8/src/common/assert-scope.cc"
  "deps/v8/src/compiler-dispatcher/compiler-dispatcher.cc"
  "deps/v8/src/compiler-dispatcher/optimizing-compile-dispatcher.cc"
  "deps/v8/src/date/date.cc"
  "deps/v8/src/date/dateparser.cc"
  "deps/v8/src/debug/debug-coverage.cc"
  "deps/v8/src/debug/debug-evaluate.cc"
  "deps/v8/src/debug/debug-frames.cc"
  "deps/v8/src/debug/debug-property-iterator.cc"
  "deps/v8/src/debug/debug-scope-iterator.cc"
  "deps/v8/src/debug/debug-scopes.cc"
  "deps/v8/src/debug/debug-stack-trace-iterator.cc"
  "deps/v8/src/debug/debug-type-profile.cc"
  "deps/v8/src/debug/debug.cc"
  "deps/v8/src/debug/liveedit.cc"
  "deps/v8/src/deoptimizer/deoptimize-reason.cc"
  "deps/v8/src/deoptimizer/deoptimizer.cc"
  "deps/v8/src/diagnostics/basic-block-profiler.cc"
  "deps/v8/src/diagnostics/compilation-statistics.cc"
  "deps/v8/src/diagnostics/disassembler.cc"
  "deps/v8/src/diagnostics/eh-frame.cc"
  "deps/v8/src/diagnostics/gdb-jit.cc"
  "deps/v8/src/diagnostics/objects-debug.cc"
  "deps/v8/src/diagnostics/objects-printer.cc"
  "deps/v8/src/diagnostics/perf-jit.cc"
  "deps/v8/src/diagnostics/unwinder.cc"
  "deps/v8/src/execution/arguments.cc"
  "deps/v8/src/execution/execution.cc"
  "deps/v8/src/execution/frames.cc"
  "deps/v8/src/execution/futex-emulation.cc"
  "deps/v8/src/execution/interrupts-scope.cc"
  "deps/v8/src/execution/isolate.cc"
  "deps/v8/src/execution/messages.cc"
  "deps/v8/src/execution/microtask-queue.cc"
  "deps/v8/src/execution/protectors.cc"
  "deps/v8/src/execution/runtime-profiler.cc"
  "deps/v8/src/execution/simulator-base.cc"
  "deps/v8/src/execution/stack-guard.cc"
  "deps/v8/src/execution/thread-id.cc"
  "deps/v8/src/execution/thread-local-top.cc"
  "deps/v8/src/execution/v8threads.cc"
  "deps/v8/src/extensions/cputracemark-extension.cc"
  "deps/v8/src/extensions/externalize-string-extension.cc"
  "deps/v8/src/extensions/free-buffer-extension.cc"
  "deps/v8/src/extensions/gc-extension.cc"
  "deps/v8/src/extensions/ignition-statistics-extension.cc"
  "deps/v8/src/extensions/statistics-extension.cc"
  "deps/v8/src/extensions/trigger-failure-extension.cc"
  "deps/v8/src/flags/flags.cc"
  "deps/v8/src/handles/global-handles.cc"
  "deps/v8/src/handles/handles.cc"
  "deps/v8/src/heap/array-buffer-collector.cc"
  "deps/v8/src/heap/array-buffer-tracker.cc"
  "deps/v8/src/heap/basic-memory-chunk.cc"
  "deps/v8/src/heap/code-stats.cc"
  "deps/v8/src/heap/combined-heap.cc"
  "deps/v8/src/heap/concurrent-marking.cc"
  "deps/v8/src/heap/embedder-tracing.cc"
  "deps/v8/src/heap/factory.cc"
  "deps/v8/src/heap/gc-idle-time-handler.cc"
  "deps/v8/src/heap/gc-tracer.cc"
  "deps/v8/src/heap/heap-controller.cc"
  "deps/v8/src/heap/heap.cc"
  "deps/v8/src/heap/incremental-marking-job.cc"
  "deps/v8/src/heap/incremental-marking.cc"
  "deps/v8/src/heap/invalidated-slots.cc"
  "deps/v8/src/heap/item-parallel-job.cc"
  "deps/v8/src/heap/mark-compact.cc"
  "deps/v8/src/heap/marking.cc"
  "deps/v8/src/heap/memory-measurement.cc"
  "deps/v8/src/heap/memory-reducer.cc"
  "deps/v8/src/heap/object-stats.cc"
  "deps/v8/src/heap/objects-visiting.cc"
  "deps/v8/src/heap/read-only-heap.cc"
  "deps/v8/src/heap/scavenge-job.cc"
  "deps/v8/src/heap/scavenger.cc"
  "deps/v8/src/heap/slot-set.cc"
  "deps/v8/src/heap/spaces.cc"
  "deps/v8/src/heap/stress-marking-observer.cc"
  "deps/v8/src/heap/stress-scavenge-observer.cc"
  "deps/v8/src/heap/sweeper.cc"
  "deps/v8/src/ic/call-optimization.cc"
  "deps/v8/src/ic/handler-configuration.cc"
  "deps/v8/src/ic/ic-stats.cc"
  "deps/v8/src/ic/ic.cc"
  "deps/v8/src/ic/stub-cache.cc"
  "deps/v8/src/init/bootstrapper.cc"
  "deps/v8/src/init/icu_util.cc"
  "deps/v8/src/init/isolate-allocator.cc"
  "deps/v8/src/init/startup-data-util.cc"
  "deps/v8/src/init/v8.cc"
  "deps/v8/src/interpreter/bytecode-array-accessor.cc"
  "deps/v8/src/interpreter/bytecode-array-builder.cc"
  "deps/v8/src/interpreter/bytecode-array-iterator.cc"
  "deps/v8/src/interpreter/bytecode-array-random-iterator.cc"
  "deps/v8/src/interpreter/bytecode-array-writer.cc"
  "deps/v8/src/interpreter/bytecode-decoder.cc"
  "deps/v8/src/interpreter/bytecode-flags.cc"
  "deps/v8/src/interpreter/bytecode-generator.cc"
  "deps/v8/src/interpreter/bytecode-label.cc"
  "deps/v8/src/interpreter/bytecode-node.cc"
  "deps/v8/src/interpreter/bytecode-operands.cc"
  "deps/v8/src/interpreter/bytecode-register-optimizer.cc"
  "deps/v8/src/interpreter/bytecode-register.cc"
  "deps/v8/src/interpreter/bytecode-source-info.cc"
  "deps/v8/src/interpreter/bytecodes.cc"
  "deps/v8/src/interpreter/constant-array-builder.cc"
  "deps/v8/src/interpreter/control-flow-builders.cc"
  "deps/v8/src/interpreter/handler-table-builder.cc"
  "deps/v8/src/interpreter/interpreter-intrinsics.cc"
  "deps/v8/src/interpreter/interpreter.cc"
  "deps/v8/src/json/json-parser.cc"
  "deps/v8/src/json/json-stringifier.cc"
  "deps/v8/src/logging/counters.cc"
  "deps/v8/src/logging/log-utils.cc"
  "deps/v8/src/logging/log.cc"
  "deps/v8/src/numbers/bignum-dtoa.cc"
  "deps/v8/src/numbers/bignum.cc"
  "deps/v8/src/numbers/cached-powers.cc"
  "deps/v8/src/numbers/conversions.cc"
  "deps/v8/src/numbers/diy-fp.cc"
  "deps/v8/src/numbers/dtoa.cc"
  "deps/v8/src/numbers/fast-dtoa.cc"
  "deps/v8/src/numbers/fixed-dtoa.cc"
  "deps/v8/src/numbers/math-random.cc"
  "deps/v8/src/numbers/strtod.cc"
  "deps/v8/src/objects/backing-store.cc"
  "deps/v8/src/objects/bigint.cc"
  "deps/v8/src/objects/code.cc"
  "deps/v8/src/objects/contexts.cc"
  "deps/v8/src/objects/debug-objects.cc"
  "deps/v8/src/objects/elements-kind.cc"
  "deps/v8/src/objects/elements.cc"
  "deps/v8/src/objects/embedder-data-array.cc"
  "deps/v8/src/objects/feedback-vector.cc"
  "deps/v8/src/objects/field-type.cc"
  "deps/v8/src/objects/intl-objects.cc"
  "deps/v8/src/objects/js-array-buffer.cc"
  "deps/v8/src/objects/js-break-iterator.cc"
  "deps/v8/src/objects/js-collator.cc"
  "deps/v8/src/objects/js-date-time-format.cc"
  "deps/v8/src/objects/js-list-format.cc"
  "deps/v8/src/objects/js-locale.cc"
  "deps/v8/src/objects/js-number-format.cc"
  "deps/v8/src/objects/js-objects.cc"
  "deps/v8/src/objects/js-plural-rules.cc"
  "deps/v8/src/objects/js-regexp.cc"
  "deps/v8/src/objects/js-relative-time-format.cc"
  "deps/v8/src/objects/js-segment-iterator.cc"
  "deps/v8/src/objects/js-segmenter.cc"
  "deps/v8/src/objects/keys.cc"
  "deps/v8/src/objects/layout-descriptor.cc"
  "deps/v8/src/objects/literal-objects.cc"
  "deps/v8/src/objects/lookup-cache.cc"
  "deps/v8/src/objects/lookup.cc"
  "deps/v8/src/objects/managed.cc"
  "deps/v8/src/objects/map-updater.cc"
  "deps/v8/src/objects/map.cc"
  "deps/v8/src/objects/module.cc"
  "deps/v8/src/objects/objects.cc"
  "deps/v8/src/objects/ordered-hash-table.cc"
  "deps/v8/src/objects/osr-optimized-code-cache.cc"
  "deps/v8/src/objects/property-descriptor.cc"
  "deps/v8/src/objects/property.cc"
  "deps/v8/src/objects/scope-info.cc"
  "deps/v8/src/objects/source-text-module.cc"
  "deps/v8/src/objects/stack-frame-info.cc"
  "deps/v8/src/objects/string-comparator.cc"
  "deps/v8/src/objects/string.cc"
  "deps/v8/src/objects/synthetic-module.cc"
  "deps/v8/src/objects/tagged-impl.cc"
  "deps/v8/src/objects/template-objects.cc"
  "deps/v8/src/objects/transitions.cc"
  "deps/v8/src/objects/type-hints.cc"
  "deps/v8/src/objects/value-serializer.cc"
  "deps/v8/src/objects/visitors.cc"
  "deps/v8/src/parsing/expression-scope-reparenter.cc"
  "deps/v8/src/parsing/func-name-inferrer.cc"
  "deps/v8/src/parsing/literal-buffer.cc"
  "deps/v8/src/parsing/parse-info.cc"
  "deps/v8/src/parsing/parser.cc"
  "deps/v8/src/parsing/parsing.cc"
  "deps/v8/src/parsing/pending-compilation-error-handler.cc"
  "deps/v8/src/parsing/preparse-data.cc"
  "deps/v8/src/parsing/preparser.cc"
  "deps/v8/src/parsing/rewriter.cc"
  "deps/v8/src/parsing/scanner-character-streams.cc"
  "deps/v8/src/parsing/scanner.cc"
  "deps/v8/src/parsing/token.cc"
  "deps/v8/src/profiler/allocation-tracker.cc"
  "deps/v8/src/profiler/cpu-profiler.cc"
  "deps/v8/src/profiler/heap-profiler.cc"
  "deps/v8/src/profiler/heap-snapshot-generator.cc"
  "deps/v8/src/profiler/profile-generator.cc"
  "deps/v8/src/profiler/profiler-listener.cc"
  "deps/v8/src/profiler/sampling-heap-profiler.cc"
  "deps/v8/src/profiler/strings-storage.cc"
  "deps/v8/src/profiler/tick-sample.cc"
  "deps/v8/src/profiler/tracing-cpu-profiler.cc"
  "deps/v8/src/regexp/property-sequences.cc"
  "deps/v8/src/regexp/regexp-ast.cc"
  "deps/v8/src/regexp/regexp-bytecode-generator.cc"
  "deps/v8/src/regexp/regexp-bytecode-peephole.cc"
  "deps/v8/src/regexp/regexp-bytecodes.cc"
  "deps/v8/src/regexp/regexp-compiler-tonode.cc"
  "deps/v8/src/regexp/regexp-compiler.cc"
  "deps/v8/src/regexp/regexp-dotprinter.cc"
  "deps/v8/src/regexp/regexp-interpreter.cc"
  "deps/v8/src/regexp/regexp-macro-assembler-tracer.cc"
  "deps/v8/src/regexp/regexp-macro-assembler.cc"
  "deps/v8/src/regexp/regexp-parser.cc"
  "deps/v8/src/regexp/regexp-stack.cc"
  "deps/v8/src/regexp/regexp-utils.cc"
  "deps/v8/src/regexp/regexp.cc"
  "deps/v8/src/roots/roots.cc"
  "deps/v8/src/runtime/runtime-array.cc"
  "deps/v8/src/runtime/runtime-atomics.cc"
  "deps/v8/src/runtime/runtime-bigint.cc"
  "deps/v8/src/runtime/runtime-classes.cc"
  "deps/v8/src/runtime/runtime-collections.cc"
  "deps/v8/src/runtime/runtime-compiler.cc"
  "deps/v8/src/runtime/runtime-date.cc"
  "deps/v8/src/runtime/runtime-debug.cc"
  "deps/v8/src/runtime/runtime-forin.cc"
  "deps/v8/src/runtime/runtime-function.cc"
  "deps/v8/src/runtime/runtime-futex.cc"
  "deps/v8/src/runtime/runtime-generator.cc"
  "deps/v8/src/runtime/runtime-internal.cc"
  "deps/v8/src/runtime/runtime-interpreter.cc"
  "deps/v8/src/runtime/runtime-intl.cc"
  "deps/v8/src/runtime/runtime-literals.cc"
  "deps/v8/src/runtime/runtime-module.cc"
  "deps/v8/src/runtime/runtime-numbers.cc"
  "deps/v8/src/runtime/runtime-object.cc"
  "deps/v8/src/runtime/runtime-operators.cc"
  "deps/v8/src/runtime/runtime-promise.cc"
  "deps/v8/src/runtime/runtime-proxy.cc"
  "deps/v8/src/runtime/runtime-regexp.cc"
  "deps/v8/src/runtime/runtime-scopes.cc"
  "deps/v8/src/runtime/runtime-strings.cc"
  "deps/v8/src/runtime/runtime-symbol.cc"
  "deps/v8/src/runtime/runtime-test.cc"
  "deps/v8/src/runtime/runtime-typedarray.cc"
  "deps/v8/src/runtime/runtime-wasm.cc"
  "deps/v8/src/runtime/runtime.cc"
  "deps/v8/src/sanitizer/lsan-page-allocator.cc"
  "deps/v8/src/snapshot/code-serializer.cc"
  "deps/v8/src/snapshot/deserializer-allocator.cc"
  "deps/v8/src/snapshot/deserializer.cc"
  "deps/v8/src/snapshot/embedded/embedded-data.cc"
  "deps/v8/src/snapshot/natives-common.cc"
  "deps/v8/src/snapshot/object-deserializer.cc"
  "deps/v8/src/snapshot/partial-deserializer.cc"
  "deps/v8/src/snapshot/partial-serializer.cc"
  "deps/v8/src/snapshot/read-only-deserializer.cc"
  "deps/v8/src/snapshot/read-only-serializer.cc"
  "deps/v8/src/snapshot/roots-serializer.cc"
  "deps/v8/src/snapshot/serializer-allocator.cc"
  "deps/v8/src/snapshot/serializer-common.cc"
  "deps/v8/src/snapshot/serializer.cc"
  "deps/v8/src/snapshot/snapshot-common.cc"
  "deps/v8/src/snapshot/snapshot-source-sink.cc"
  "deps/v8/src/snapshot/startup-deserializer.cc"
  "deps/v8/src/snapshot/startup-serializer.cc"
  "deps/v8/src/strings/char-predicates.cc"
  "deps/v8/src/strings/string-builder.cc"
  "deps/v8/src/strings/string-case.cc"
  "deps/v8/src/strings/string-stream.cc"
  "deps/v8/src/strings/unicode-decoder.cc"
  "deps/v8/src/strings/unicode.cc"
  "deps/v8/src/strings/uri.cc"
  "deps/v8/src/tasks/cancelable-task.cc"
  "deps/v8/src/tasks/task-utils.cc"
  "deps/v8/src/third_party/siphash/halfsiphash.cc"
  "deps/v8/src/tracing/trace-event.cc"
  "deps/v8/src/tracing/traced-value.cc"
  "deps/v8/src/tracing/tracing-category-observer.cc"
  "deps/v8/src/trap-handler/handler-inside.cc"
  "deps/v8/src/trap-handler/handler-outside.cc"
  "deps/v8/src/trap-handler/handler-shared.cc"
  "deps/v8/src/utils/address-map.cc"
  "deps/v8/src/utils/allocation.cc"
  "deps/v8/src/utils/bit-vector.cc"
  "deps/v8/src/utils/detachable-vector.cc"
  "deps/v8/src/utils/identity-map.cc"
  "deps/v8/src/utils/memcopy.cc"
  "deps/v8/src/utils/ostreams.cc"
  "deps/v8/src/utils/utils.cc"
  "deps/v8/src/utils/version.cc"
  "deps/v8/src/wasm/baseline/liftoff-assembler.cc"
  "deps/v8/src/wasm/baseline/liftoff-compiler.cc"
  "deps/v8/src/wasm/function-body-decoder.cc"
  "deps/v8/src/wasm/function-compiler.cc"
  "deps/v8/src/wasm/graph-builder-interface.cc"
  "deps/v8/src/wasm/jump-table-assembler.cc"
  "deps/v8/src/wasm/local-decl-encoder.cc"
  "deps/v8/src/wasm/memory-tracing.cc"
  "deps/v8/src/wasm/module-compiler.cc"
  "deps/v8/src/wasm/module-decoder.cc"
  "deps/v8/src/wasm/module-instantiate.cc"
  "deps/v8/src/wasm/signature-map.cc"
  "deps/v8/src/wasm/streaming-decoder.cc"
  "deps/v8/src/wasm/wasm-code-manager.cc"
  "deps/v8/src/wasm/wasm-debug.cc"
  "deps/v8/src/wasm/wasm-engine.cc"
  "deps/v8/src/wasm/wasm-external-refs.cc"
  "deps/v8/src/wasm/wasm-features.cc"
  "deps/v8/src/wasm/wasm-import-wrapper-cache.cc"
  "deps/v8/src/wasm/wasm-interpreter.cc"
  "deps/v8/src/wasm/wasm-js.cc"
  "deps/v8/src/wasm/wasm-module-builder.cc"
  "deps/v8/src/wasm/wasm-module-sourcemap.cc"
  "deps/v8/src/wasm/wasm-module.cc"
  "deps/v8/src/wasm/wasm-objects.cc"
  "deps/v8/src/wasm/wasm-opcodes.cc"
  "deps/v8/src/wasm/wasm-result.cc"
  "deps/v8/src/wasm/wasm-serialization.cc"
  "deps/v8/src/wasm/wasm-text.cc"
  "deps/v8/src/zone/accounting-allocator.cc"
  "deps/v8/src/zone/zone-segment.cc"
  "deps/v8/src/zone/zone.cc"
  "deps/v8/src/inspector/custom-preview.cc"
  "deps/v8/src/inspector/injected-script.cc"
  "deps/v8/src/inspector/inspected-context.cc"
  "deps/v8/src/inspector/remote-object-id.cc"
  "deps/v8/src/inspector/search-util.cc"
  "deps/v8/src/inspector/string-16.cc"
  "deps/v8/src/inspector/string-util.cc"
  "deps/v8/src/inspector/test-interface.cc"
  "deps/v8/src/inspector/v8-console.cc"
  "deps/v8/src/inspector/v8-console-agent-impl.cc"
  "deps/v8/src/inspector/v8-console-message.cc"
  "deps/v8/src/inspector/v8-debugger.cc"
  "deps/v8/src/inspector/v8-debugger-agent-impl.cc"
  "deps/v8/src/inspector/v8-debugger-script.cc"
  "deps/v8/src/inspector/v8-heap-profiler-agent-impl.cc"
  "deps/v8/src/inspector/v8-inspector-impl.cc"
  "deps/v8/src/inspector/v8-inspector-protocol-encoding.cc"
  "deps/v8/src/inspector/v8-inspector-session-impl.cc"
  "deps/v8/src/inspector/v8-profiler-agent-impl.cc"
  "deps/v8/src/inspector/v8-regex.cc"
  "deps/v8/src/inspector/v8-runtime-agent-impl.cc"
  "deps/v8/src/inspector/v8-schema-agent-impl.cc"
  "deps/v8/src/inspector/v8-stack-trace-impl.cc"
  "deps/v8/src/inspector/v8-value-utils.cc"
  "deps/v8/src/inspector/value-mirror.cc"
  "deps/v8/src/inspector/wasm-translation.cc"
  "deps/v8/src/inspector/v8-string-conversions.cc"
  "deps/v8/third_party/inspector_protocol/encoding/encoding.cc"
  "deps/v8/third_party/inspector_protocol/bindings/bindings.cc"
  "deps/v8/src/codegen/x64/assembler-x64.cc"
  "deps/v8/src/codegen/x64/cpu-x64.cc"
  "deps/v8/src/codegen/x64/interface-descriptors-x64.cc"
  "deps/v8/src/codegen/x64/macro-assembler-x64.cc"
  "deps/v8/src/compiler/backend/x64/code-generator-x64.cc"
  "deps/v8/src/compiler/backend/x64/instruction-scheduler-x64.cc"
  "deps/v8/src/compiler/backend/x64/instruction-selector-x64.cc"
  "deps/v8/src/compiler/backend/x64/unwinding-info-writer-x64.cc"
  "deps/v8/src/debug/x64/debug-x64.cc"
  "deps/v8/src/deoptimizer/x64/deoptimizer-x64.cc"
  "deps/v8/src/diagnostics/x64/disasm-x64.cc"
  "deps/v8/src/diagnostics/x64/eh-frame-x64.cc"
  "deps/v8/src/execution/x64/frame-constants-x64.cc"
  "deps/v8/src/regexp/x64/regexp-macro-assembler-x64.cc"
  "deps/v8/src/trap-handler/handler-inside-posix.cc"
  "deps/v8/src/trap-handler/handler-outside-posix.cc"
  "${obj}/gen/src/regexp/special-case.cc"
  "${obj}/gen/torque-output-root/torque-generated/class-definitions-tq.cc"
  "${obj}/gen/torque-output-root/torque-generated/class-verifiers-tq.cc"
  "${obj}/gen/torque-output-root/torque-generated/objects-printer-tq.cc"
  "${obj}/gen/debug-support.cc"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Protocol.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Console.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Debugger.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/HeapProfiler.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Profiler.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Runtime.cpp"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Schema.cpp")
list(APPEND v8_base_without_compiler__other_srcs
  "${obj}/gen/generate-bytecode-output-root/builtins-generated/bytecodes-builtins-list.h"
  "deps/v8/include/v8-inspector-protocol.h"
  "deps/v8/include/v8-inspector.h"
  "deps/v8/include/v8-internal.h"
  "deps/v8/include/v8-platform.h"
  "deps/v8/include/v8-profiler.h"
  "deps/v8/include/v8-testing.h"
  "deps/v8/include/v8-util.h"
  "deps/v8/include/v8-wasm-trap-handler-posix.h"
  "deps/v8/include/v8.h"
  "deps/v8/include/v8config.h"
  "deps/v8/src/api/api-arguments-inl.h"
  "deps/v8/src/api/api-arguments.h"
  "deps/v8/src/api/api-natives.h"
  "deps/v8/src/api/api.h"
  "deps/v8/src/asmjs/asm-js.h"
  "deps/v8/src/asmjs/asm-names.h"
  "deps/v8/src/asmjs/asm-parser.h"
  "deps/v8/src/asmjs/asm-scanner.h"
  "deps/v8/src/asmjs/asm-types.h"
  "deps/v8/src/ast/ast-function-literal-id-reindexer.h"
  "deps/v8/src/ast/ast-source-ranges.h"
  "deps/v8/src/ast/ast-traversal-visitor.h"
  "deps/v8/src/ast/ast-value-factory.h"
  "deps/v8/src/ast/ast.h"
  "deps/v8/src/ast/modules.h"
  "deps/v8/src/ast/prettyprinter.h"
  "deps/v8/src/ast/scopes.h"
  "deps/v8/src/ast/source-range-ast-visitor.h"
  "deps/v8/src/ast/variables.h"
  "deps/v8/src/builtins/accessors.h"
  "deps/v8/src/builtins/builtins-constructor.h"
  "deps/v8/src/builtins/builtins-definitions.h"
  "deps/v8/src/builtins/builtins-descriptors.h"
  "deps/v8/src/builtins/builtins-promise.h"
  "deps/v8/src/builtins/builtins-utils-inl.h"
  "deps/v8/src/builtins/builtins-utils.h"
  "deps/v8/src/builtins/builtins.h"
  "deps/v8/src/builtins/constants-table-builder.h"
  "deps/v8/src/codegen/assembler-arch.h"
  "deps/v8/src/codegen/assembler-inl.h"
  "deps/v8/src/codegen/assembler.h"
  "deps/v8/src/codegen/bailout-reason.h"
  "deps/v8/src/codegen/callable.h"
  "deps/v8/src/codegen/code-comments.h"
  "deps/v8/src/codegen/code-desc.h"
  "deps/v8/src/codegen/code-factory.h"
  "deps/v8/src/codegen/code-reference.h"
  "deps/v8/src/codegen/compilation-cache.h"
  "deps/v8/src/codegen/compiler.h"
  "deps/v8/src/codegen/constant-pool.h"
  "deps/v8/src/codegen/constants-arch.h"
  "deps/v8/src/codegen/cpu-features.h"
  "deps/v8/src/codegen/external-reference-table.h"
  "deps/v8/src/codegen/external-reference.h"
  "deps/v8/src/codegen/flush-instruction-cache.h"
  "deps/v8/src/codegen/handler-table.h"
  "deps/v8/src/codegen/interface-descriptors.h"
  "deps/v8/src/codegen/label.h"
  "deps/v8/src/codegen/machine-type.h"
  "deps/v8/src/codegen/macro-assembler-inl.h"
  "deps/v8/src/codegen/macro-assembler.h"
  "deps/v8/src/codegen/optimized-compilation-info.h"
  "deps/v8/src/codegen/pending-optimization-table.h"
  "deps/v8/src/codegen/register-arch.h"
  "deps/v8/src/codegen/register-configuration.h"
  "deps/v8/src/codegen/register.h"
  "deps/v8/src/codegen/reglist.h"
  "deps/v8/src/codegen/reloc-info.h"
  "deps/v8/src/codegen/safepoint-table.h"
  "deps/v8/src/codegen/signature.h"
  "deps/v8/src/codegen/source-position-table.h"
  "deps/v8/src/codegen/source-position.h"
  "deps/v8/src/codegen/string-constants.h"
  "deps/v8/src/codegen/tick-counter.h"
  "deps/v8/src/codegen/tnode.h"
  "deps/v8/src/codegen/turbo-assembler.h"
  "deps/v8/src/codegen/unoptimized-compilation-info.h"
  "deps/v8/src/common/assert-scope.h"
  "deps/v8/src/common/checks.h"
  "deps/v8/src/common/message-template.h"
  "deps/v8/src/common/ptr-compr-inl.h"
  "deps/v8/src/common/ptr-compr.h"
  "deps/v8/src/compiler-dispatcher/compiler-dispatcher.h"
  "deps/v8/src/compiler-dispatcher/optimizing-compile-dispatcher.h"
  "deps/v8/src/date/date.h"
  "deps/v8/src/date/dateparser-inl.h"
  "deps/v8/src/date/dateparser.h"
  "deps/v8/src/debug/debug-coverage.h"
  "deps/v8/src/debug/debug-evaluate.h"
  "deps/v8/src/debug/debug-frames.h"
  "deps/v8/src/debug/debug-interface.h"
  "deps/v8/src/debug/debug-property-iterator.h"
  "deps/v8/src/debug/debug-scope-iterator.h"
  "deps/v8/src/debug/debug-scopes.h"
  "deps/v8/src/debug/debug-stack-trace-iterator.h"
  "deps/v8/src/debug/debug-type-profile.h"
  "deps/v8/src/debug/debug.h"
  "deps/v8/src/debug/interface-types.h"
  "deps/v8/src/debug/liveedit.h"
  "deps/v8/src/deoptimizer/deoptimize-reason.h"
  "deps/v8/src/deoptimizer/deoptimizer.h"
  "deps/v8/src/diagnostics/basic-block-profiler.h"
  "deps/v8/src/diagnostics/code-tracer.h"
  "deps/v8/src/diagnostics/compilation-statistics.h"
  "deps/v8/src/diagnostics/disasm.h"
  "deps/v8/src/diagnostics/disassembler.h"
  "deps/v8/src/diagnostics/eh-frame.h"
  "deps/v8/src/diagnostics/gdb-jit.h"
  "deps/v8/src/diagnostics/perf-jit.h"
  "deps/v8/src/execution/arguments-inl.h"
  "deps/v8/src/execution/arguments.h"
  "deps/v8/src/execution/execution.h"
  "deps/v8/src/execution/frame-constants.h"
  "deps/v8/src/execution/frames-inl.h"
  "deps/v8/src/execution/frames.h"
  "deps/v8/src/execution/futex-emulation.h"
  "deps/v8/src/execution/interrupts-scope.h"
  "deps/v8/src/execution/isolate-data.h"
  "deps/v8/src/execution/isolate-inl.h"
  "deps/v8/src/execution/isolate-utils.h"
  "deps/v8/src/execution/isolate.h"
  "deps/v8/src/execution/messages.h"
  "deps/v8/src/execution/microtask-queue.h"
  "deps/v8/src/execution/protectors-inl.h"
  "deps/v8/src/execution/protectors.h"
  "deps/v8/src/execution/runtime-profiler.h"
  "deps/v8/src/execution/simulator-base.h"
  "deps/v8/src/execution/simulator.h"
  "deps/v8/src/execution/stack-guard.h"
  "deps/v8/src/execution/thread-id.h"
  "deps/v8/src/execution/thread-local-top.h"
  "deps/v8/src/execution/v8threads.h"
  "deps/v8/src/execution/vm-state-inl.h"
  "deps/v8/src/execution/vm-state.h"
  "deps/v8/src/extensions/cputracemark-extension.h"
  "deps/v8/src/extensions/externalize-string-extension.h"
  "deps/v8/src/extensions/free-buffer-extension.h"
  "deps/v8/src/extensions/gc-extension.h"
  "deps/v8/src/extensions/ignition-statistics-extension.h"
  "deps/v8/src/extensions/statistics-extension.h"
  "deps/v8/src/extensions/trigger-failure-extension.h"
  "deps/v8/src/flags/flag-definitions.h"
  "deps/v8/src/flags/flags.h"
  "deps/v8/src/handles/global-handles.h"
  "deps/v8/src/handles/handles-inl.h"
  "deps/v8/src/handles/handles.h"
  "deps/v8/src/handles/maybe-handles-inl.h"
  "deps/v8/src/handles/maybe-handles.h"
  "deps/v8/src/heap/array-buffer-collector.h"
  "deps/v8/src/heap/array-buffer-tracker-inl.h"
  "deps/v8/src/heap/array-buffer-tracker.h"
  "deps/v8/src/heap/barrier.h"
  "deps/v8/src/heap/basic-memory-chunk.h"
  "deps/v8/src/heap/code-stats.h"
  "deps/v8/src/heap/combined-heap.h"
  "deps/v8/src/heap/concurrent-marking.h"
  "deps/v8/src/heap/embedder-tracing.h"
  "deps/v8/src/heap/factory-inl.h"
  "deps/v8/src/heap/factory.h"
  "deps/v8/src/heap/gc-idle-time-handler.h"
  "deps/v8/src/heap/gc-tracer.h"
  "deps/v8/src/heap/heap-controller.h"
  "deps/v8/src/heap/heap-inl.h"
  "deps/v8/src/heap/heap-write-barrier-inl.h"
  "deps/v8/src/heap/heap-write-barrier.h"
  "deps/v8/src/heap/heap.h"
  "deps/v8/src/heap/incremental-marking-inl.h"
  "deps/v8/src/heap/incremental-marking-job.h"
  "deps/v8/src/heap/incremental-marking.h"
  "deps/v8/src/heap/invalidated-slots-inl.h"
  "deps/v8/src/heap/invalidated-slots.h"
  "deps/v8/src/heap/item-parallel-job.h"
  "deps/v8/src/heap/local-allocator-inl.h"
  "deps/v8/src/heap/local-allocator.h"
  "deps/v8/src/heap/mark-compact-inl.h"
  "deps/v8/src/heap/mark-compact.h"
  "deps/v8/src/heap/marking.h"
  "deps/v8/src/heap/memory-measurement.h"
  "deps/v8/src/heap/memory-reducer.h"
  "deps/v8/src/heap/object-stats.h"
  "deps/v8/src/heap/objects-visiting-inl.h"
  "deps/v8/src/heap/objects-visiting.h"
  "deps/v8/src/heap/read-only-heap-inl.h"
  "deps/v8/src/heap/read-only-heap.h"
  "deps/v8/src/heap/remembered-set.h"
  "deps/v8/src/heap/scavenge-job.h"
  "deps/v8/src/heap/scavenger-inl.h"
  "deps/v8/src/heap/scavenger.h"
  "deps/v8/src/heap/slot-set.h"
  "deps/v8/src/heap/spaces-inl.h"
  "deps/v8/src/heap/spaces.h"
  "deps/v8/src/heap/stress-marking-observer.h"
  "deps/v8/src/heap/stress-scavenge-observer.h"
  "deps/v8/src/heap/sweeper.h"
  "deps/v8/src/heap/worklist.h"
  "deps/v8/src/ic/call-optimization.h"
  "deps/v8/src/ic/handler-configuration-inl.h"
  "deps/v8/src/ic/handler-configuration.h"
  "deps/v8/src/ic/ic-inl.h"
  "deps/v8/src/ic/ic-stats.h"
  "deps/v8/src/ic/ic.h"
  "deps/v8/src/ic/stub-cache.h"
  "deps/v8/src/init/bootstrapper.h"
  "deps/v8/src/init/heap-symbols.h"
  "deps/v8/src/init/icu_util.h"
  "deps/v8/src/init/isolate-allocator.h"
  "deps/v8/src/init/setup-isolate.h"
  "deps/v8/src/init/startup-data-util.h"
  "deps/v8/src/init/v8.h"
  "deps/v8/src/interpreter/block-coverage-builder.h"
  "deps/v8/src/interpreter/bytecode-array-accessor.h"
  "deps/v8/src/interpreter/bytecode-array-builder.h"
  "deps/v8/src/interpreter/bytecode-array-iterator.h"
  "deps/v8/src/interpreter/bytecode-array-random-iterator.h"
  "deps/v8/src/interpreter/bytecode-array-writer.h"
  "deps/v8/src/interpreter/bytecode-decoder.h"
  "deps/v8/src/interpreter/bytecode-flags.h"
  "deps/v8/src/interpreter/bytecode-generator.h"
  "deps/v8/src/interpreter/bytecode-jump-table.h"
  "deps/v8/src/interpreter/bytecode-label.h"
  "deps/v8/src/interpreter/bytecode-node.h"
  "deps/v8/src/interpreter/bytecode-operands.h"
  "deps/v8/src/interpreter/bytecode-register-allocator.h"
  "deps/v8/src/interpreter/bytecode-register-optimizer.h"
  "deps/v8/src/interpreter/bytecode-register.h"
  "deps/v8/src/interpreter/bytecode-source-info.h"
  "deps/v8/src/interpreter/bytecode-traits.h"
  "deps/v8/src/interpreter/bytecodes.h"
  "deps/v8/src/interpreter/constant-array-builder.h"
  "deps/v8/src/interpreter/control-flow-builders.h"
  "deps/v8/src/interpreter/handler-table-builder.h"
  "deps/v8/src/interpreter/interpreter-generator.h"
  "deps/v8/src/interpreter/interpreter-intrinsics.h"
  "deps/v8/src/interpreter/interpreter.h"
  "deps/v8/src/json/json-parser.h"
  "deps/v8/src/json/json-stringifier.h"
  "deps/v8/src/logging/code-events.h"
  "deps/v8/src/logging/counters-definitions.h"
  "deps/v8/src/logging/counters-inl.h"
  "deps/v8/src/logging/counters.h"
  "deps/v8/src/logging/log-inl.h"
  "deps/v8/src/logging/log-utils.h"
  "deps/v8/src/logging/log.h"
  "deps/v8/src/numbers/bignum-dtoa.h"
  "deps/v8/src/numbers/bignum.h"
  "deps/v8/src/numbers/cached-powers.h"
  "deps/v8/src/numbers/conversions-inl.h"
  "deps/v8/src/numbers/conversions.h"
  "deps/v8/src/numbers/diy-fp.h"
  "deps/v8/src/numbers/double.h"
  "deps/v8/src/numbers/dtoa.h"
  "deps/v8/src/numbers/fast-dtoa.h"
  "deps/v8/src/numbers/fixed-dtoa.h"
  "deps/v8/src/numbers/hash-seed-inl.h"
  "deps/v8/src/numbers/math-random.h"
  "deps/v8/src/numbers/strtod.h"
  "deps/v8/src/objects/allocation-site-inl.h"
  "deps/v8/src/objects/allocation-site-scopes-inl.h"
  "deps/v8/src/objects/allocation-site-scopes.h"
  "deps/v8/src/objects/allocation-site.h"
  "deps/v8/src/objects/api-callbacks-inl.h"
  "deps/v8/src/objects/api-callbacks.h"
  "deps/v8/src/objects/arguments-inl.h"
  "deps/v8/src/objects/arguments.h"
  "deps/v8/src/objects/backing-store.h"
  "deps/v8/src/objects/bigint.h"
  "deps/v8/src/objects/cell-inl.h"
  "deps/v8/src/objects/cell.h"
  "deps/v8/src/objects/code-inl.h"
  "deps/v8/src/objects/code.h"
  "deps/v8/src/objects/compilation-cache-inl.h"
  "deps/v8/src/objects/compilation-cache.h"
  "deps/v8/src/objects/compressed-slots-inl.h"
  "deps/v8/src/objects/compressed-slots.h"
  "deps/v8/src/objects/contexts-inl.h"
  "deps/v8/src/objects/contexts.h"
  "deps/v8/src/objects/data-handler.h"
  "deps/v8/src/objects/debug-objects-inl.h"
  "deps/v8/src/objects/debug-objects.h"
  "deps/v8/src/objects/descriptor-array-inl.h"
  "deps/v8/src/objects/descriptor-array.h"
  "deps/v8/src/objects/dictionary-inl.h"
  "deps/v8/src/objects/dictionary.h"
  "deps/v8/src/objects/elements-inl.h"
  "deps/v8/src/objects/elements-kind.h"
  "deps/v8/src/objects/elements.h"
  "deps/v8/src/objects/embedder-data-array-inl.h"
  "deps/v8/src/objects/embedder-data-array.h"
  "deps/v8/src/objects/embedder-data-slot-inl.h"
  "deps/v8/src/objects/embedder-data-slot.h"
  "deps/v8/src/objects/feedback-cell-inl.h"
  "deps/v8/src/objects/feedback-cell.h"
  "deps/v8/src/objects/feedback-vector-inl.h"
  "deps/v8/src/objects/feedback-vector.h"
  "deps/v8/src/objects/field-index-inl.h"
  "deps/v8/src/objects/field-index.h"
  "deps/v8/src/objects/field-type.h"
  "deps/v8/src/objects/fixed-array-inl.h"
  "deps/v8/src/objects/fixed-array.h"
  "deps/v8/src/objects/frame-array-inl.h"
  "deps/v8/src/objects/frame-array.h"
  "deps/v8/src/objects/function-kind.h"
  "deps/v8/src/objects/hash-table-inl.h"
  "deps/v8/src/objects/hash-table.h"
  "deps/v8/src/objects/heap-number-inl.h"
  "deps/v8/src/objects/heap-number.h"
  "deps/v8/src/objects/heap-object-inl.h"
  "deps/v8/src/objects/heap-object.h"
  "deps/v8/src/objects/instance-type-inl.h"
  "deps/v8/src/objects/instance-type.h"
  "deps/v8/src/objects/internal-index.h"
  "deps/v8/src/objects/intl-objects.h"
  "deps/v8/src/objects/js-array-buffer-inl.h"
  "deps/v8/src/objects/js-array-buffer.h"
  "deps/v8/src/objects/js-array-inl.h"
  "deps/v8/src/objects/js-array.h"
  "deps/v8/src/objects/js-break-iterator-inl.h"
  "deps/v8/src/objects/js-break-iterator.h"
  "deps/v8/src/objects/js-collator-inl.h"
  "deps/v8/src/objects/js-collator.h"
  "deps/v8/src/objects/js-collection-inl.h"
  "deps/v8/src/objects/js-collection-iterator.h"
  "deps/v8/src/objects/js-collection.h"
  "deps/v8/src/objects/js-date-time-format-inl.h"
  "deps/v8/src/objects/js-date-time-format.h"
  "deps/v8/src/objects/js-generator-inl.h"
  "deps/v8/src/objects/js-generator.h"
  "deps/v8/src/objects/js-list-format-inl.h"
  "deps/v8/src/objects/js-list-format.h"
  "deps/v8/src/objects/js-locale-inl.h"
  "deps/v8/src/objects/js-locale.h"
  "deps/v8/src/objects/js-number-format-inl.h"
  "deps/v8/src/objects/js-number-format.h"
  "deps/v8/src/objects/js-objects-inl.h"
  "deps/v8/src/objects/js-objects.h"
  "deps/v8/src/objects/js-plural-rules-inl.h"
  "deps/v8/src/objects/js-plural-rules.h"
  "deps/v8/src/objects/js-promise-inl.h"
  "deps/v8/src/objects/js-promise.h"
  "deps/v8/src/objects/js-proxy-inl.h"
  "deps/v8/src/objects/js-proxy.h"
  "deps/v8/src/objects/js-regexp-inl.h"
  "deps/v8/src/objects/js-regexp-string-iterator-inl.h"
  "deps/v8/src/objects/js-regexp-string-iterator.h"
  "deps/v8/src/objects/js-regexp.h"
  "deps/v8/src/objects/js-relative-time-format-inl.h"
  "deps/v8/src/objects/js-relative-time-format.h"
  "deps/v8/src/objects/js-segment-iterator-inl.h"
  "deps/v8/src/objects/js-segment-iterator.h"
  "deps/v8/src/objects/js-segmenter-inl.h"
  "deps/v8/src/objects/js-segmenter.h"
  "deps/v8/src/objects/js-weak-refs-inl.h"
  "deps/v8/src/objects/js-weak-refs.h"
  "deps/v8/src/objects/keys.h"
  "deps/v8/src/objects/layout-descriptor-inl.h"
  "deps/v8/src/objects/layout-descriptor.h"
  "deps/v8/src/objects/literal-objects-inl.h"
  "deps/v8/src/objects/literal-objects.h"
  "deps/v8/src/objects/lookup-cache-inl.h"
  "deps/v8/src/objects/lookup-cache.h"
  "deps/v8/src/objects/lookup-inl.h"
  "deps/v8/src/objects/lookup.h"
  "deps/v8/src/objects/managed.h"
  "deps/v8/src/objects/map-inl.h"
  "deps/v8/src/objects/map-updater.h"
  "deps/v8/src/objects/map.h"
  "deps/v8/src/objects/maybe-object-inl.h"
  "deps/v8/src/objects/maybe-object.h"
  "deps/v8/src/objects/microtask-inl.h"
  "deps/v8/src/objects/microtask.h"
  "deps/v8/src/objects/module-inl.h"
  "deps/v8/src/objects/module.h"
  "deps/v8/src/objects/name-inl.h"
  "deps/v8/src/objects/name.h"
  "deps/v8/src/objects/object-list-macros.h"
  "deps/v8/src/objects/object-macros-undef.h"
  "deps/v8/src/objects/object-macros.h"
  "deps/v8/src/objects/objects-body-descriptors-inl.h"
  "deps/v8/src/objects/objects-body-descriptors.h"
  "deps/v8/src/objects/objects-inl.h"
  "deps/v8/src/objects/objects.h"
  "deps/v8/src/objects/oddball-inl.h"
  "deps/v8/src/objects/oddball.h"
  "deps/v8/src/objects/ordered-hash-table-inl.h"
  "deps/v8/src/objects/ordered-hash-table.h"
  "deps/v8/src/objects/osr-optimized-code-cache-inl.h"
  "deps/v8/src/objects/osr-optimized-code-cache.h"
  "deps/v8/src/objects/primitive-heap-object-inl.h"
  "deps/v8/src/objects/primitive-heap-object.h"
  "deps/v8/src/objects/promise-inl.h"
  "deps/v8/src/objects/promise.h"
  "deps/v8/src/objects/property-array-inl.h"
  "deps/v8/src/objects/property-array.h"
  "deps/v8/src/objects/property-cell-inl.h"
  "deps/v8/src/objects/property-cell.h"
  "deps/v8/src/objects/property-descriptor-object-inl.h"
  "deps/v8/src/objects/property-descriptor-object.h"
  "deps/v8/src/objects/property-descriptor.h"
  "deps/v8/src/objects/property-details.h"
  "deps/v8/src/objects/property.h"
  "deps/v8/src/objects/prototype-info-inl.h"
  "deps/v8/src/objects/prototype-info.h"
  "deps/v8/src/objects/prototype.h"
  "deps/v8/src/objects/regexp-match-info.h"
  "deps/v8/src/objects/scope-info.h"
  "deps/v8/src/objects/script-inl.h"
  "deps/v8/src/objects/script.h"
  "deps/v8/src/objects/shared-function-info-inl.h"
  "deps/v8/src/objects/shared-function-info.h"
  "deps/v8/src/objects/slots-atomic-inl.h"
  "deps/v8/src/objects/slots-inl.h"
  "deps/v8/src/objects/slots.h"
  "deps/v8/src/objects/source-text-module.h"
  "deps/v8/src/objects/stack-frame-info-inl.h"
  "deps/v8/src/objects/stack-frame-info.h"
  "deps/v8/src/objects/string-comparator.h"
  "deps/v8/src/objects/string-inl.h"
  "deps/v8/src/objects/string-table-inl.h"
  "deps/v8/src/objects/string-table.h"
  "deps/v8/src/objects/string.h"
  "deps/v8/src/objects/struct-inl.h"
  "deps/v8/src/objects/struct.h"
  "deps/v8/src/objects/synthetic-module.h"
  "deps/v8/src/objects/tagged-field-inl.h"
  "deps/v8/src/objects/tagged-field.h"
  "deps/v8/src/objects/tagged-impl-inl.h"
  "deps/v8/src/objects/tagged-impl.h"
  "deps/v8/src/objects/tagged-value-inl.h"
  "deps/v8/src/objects/tagged-value.h"
  "deps/v8/src/objects/template-objects-inl.h"
  "deps/v8/src/objects/template-objects.h"
  "deps/v8/src/objects/templates-inl.h"
  "deps/v8/src/objects/templates.h"
  "deps/v8/src/objects/transitions-inl.h"
  "deps/v8/src/objects/transitions.h"
  "deps/v8/src/objects/type-hints.h"
  "deps/v8/src/objects/value-serializer.h"
  "deps/v8/src/objects/visitors.h"
  "deps/v8/src/parsing/expression-scope-reparenter.h"
  "deps/v8/src/parsing/expression-scope.h"
  "deps/v8/src/parsing/func-name-inferrer.h"
  "deps/v8/src/parsing/literal-buffer.h"
  "deps/v8/src/parsing/parse-info.h"
  "deps/v8/src/parsing/parser-base.h"
  "deps/v8/src/parsing/parser.h"
  "deps/v8/src/parsing/parsing.h"
  "deps/v8/src/parsing/pending-compilation-error-handler.h"
  "deps/v8/src/parsing/preparse-data-impl.h"
  "deps/v8/src/parsing/preparse-data.h"
  "deps/v8/src/parsing/preparser-logger.h"
  "deps/v8/src/parsing/preparser.h"
  "deps/v8/src/parsing/rewriter.h"
  "deps/v8/src/parsing/scanner-character-streams.h"
  "deps/v8/src/parsing/scanner.h"
  "deps/v8/src/parsing/token.h"
  "deps/v8/src/profiler/allocation-tracker.h"
  "deps/v8/src/profiler/circular-queue-inl.h"
  "deps/v8/src/profiler/circular-queue.h"
  "deps/v8/src/profiler/cpu-profiler-inl.h"
  "deps/v8/src/profiler/cpu-profiler.h"
  "deps/v8/src/profiler/heap-profiler.h"
  "deps/v8/src/profiler/heap-snapshot-generator-inl.h"
  "deps/v8/src/profiler/heap-snapshot-generator.h"
  "deps/v8/src/profiler/profile-generator-inl.h"
  "deps/v8/src/profiler/profile-generator.h"
  "deps/v8/src/profiler/profiler-listener.h"
  "deps/v8/src/profiler/sampling-heap-profiler.h"
  "deps/v8/src/profiler/strings-storage.h"
  "deps/v8/src/profiler/tick-sample.h"
  "deps/v8/src/profiler/tracing-cpu-profiler.h"
  "deps/v8/src/regexp/property-sequences.h"
  "deps/v8/src/regexp/regexp-ast.h"
  "deps/v8/src/regexp/regexp-bytecode-generator-inl.h"
  "deps/v8/src/regexp/regexp-bytecode-generator.h"
  "deps/v8/src/regexp/regexp-bytecode-peephole.h"
  "deps/v8/src/regexp/regexp-bytecodes.h"
  "deps/v8/src/regexp/regexp-compiler.h"
  "deps/v8/src/regexp/regexp-dotprinter.h"
  "deps/v8/src/regexp/regexp-interpreter.h"
  "deps/v8/src/regexp/regexp-macro-assembler-arch.h"
  "deps/v8/src/regexp/regexp-macro-assembler-tracer.h"
  "deps/v8/src/regexp/regexp-macro-assembler.h"
  "deps/v8/src/regexp/regexp-nodes.h"
  "deps/v8/src/regexp/regexp-parser.h"
  "deps/v8/src/regexp/regexp-stack.h"
  "deps/v8/src/regexp/regexp-utils.h"
  "deps/v8/src/regexp/regexp.h"
  "deps/v8/src/regexp/special-case.h"
  "deps/v8/src/roots/roots-inl.h"
  "deps/v8/src/roots/roots.h"
  "deps/v8/src/runtime/runtime-utils.h"
  "deps/v8/src/runtime/runtime.h"
  "deps/v8/src/sanitizer/asan.h"
  "deps/v8/src/sanitizer/lsan-page-allocator.h"
  "deps/v8/src/sanitizer/msan.h"
  "deps/v8/src/sanitizer/tsan.h"
  "deps/v8/src/snapshot/code-serializer.h"
  "deps/v8/src/snapshot/deserializer-allocator.h"
  "deps/v8/src/snapshot/deserializer.h"
  "deps/v8/src/snapshot/embedded/embedded-data.h"
  "deps/v8/src/snapshot/natives.h"
  "deps/v8/src/snapshot/object-deserializer.h"
  "deps/v8/src/snapshot/partial-deserializer.h"
  "deps/v8/src/snapshot/partial-serializer.h"
  "deps/v8/src/snapshot/read-only-deserializer.h"
  "deps/v8/src/snapshot/read-only-serializer.h"
  "deps/v8/src/snapshot/references.h"
  "deps/v8/src/snapshot/roots-serializer.h"
  "deps/v8/src/snapshot/serializer-allocator.h"
  "deps/v8/src/snapshot/serializer-common.h"
  "deps/v8/src/snapshot/serializer.h"
  "deps/v8/src/snapshot/snapshot-source-sink.h"
  "deps/v8/src/snapshot/snapshot.h"
  "deps/v8/src/snapshot/startup-deserializer.h"
  "deps/v8/src/snapshot/startup-serializer.h"
  "deps/v8/src/strings/char-predicates-inl.h"
  "deps/v8/src/strings/char-predicates.h"
  "deps/v8/src/strings/string-builder-inl.h"
  "deps/v8/src/strings/string-case.h"
  "deps/v8/src/strings/string-hasher-inl.h"
  "deps/v8/src/strings/string-hasher.h"
  "deps/v8/src/strings/string-search.h"
  "deps/v8/src/strings/string-stream.h"
  "deps/v8/src/strings/unicode-decoder.h"
  "deps/v8/src/strings/unicode-inl.h"
  "deps/v8/src/strings/unicode.h"
  "deps/v8/src/strings/uri.h"
  "deps/v8/src/tasks/cancelable-task.h"
  "deps/v8/src/tasks/task-utils.h"
  "deps/v8/src/third_party/siphash/halfsiphash.h"
  "deps/v8/src/third_party/utf8-decoder/utf8-decoder.h"
  "deps/v8/src/tracing/trace-event.h"
  "deps/v8/src/tracing/traced-value.h"
  "deps/v8/src/tracing/tracing-category-observer.h"
  "deps/v8/src/trap-handler/trap-handler-internal.h"
  "deps/v8/src/trap-handler/trap-handler.h"
  "deps/v8/src/utils/address-map.h"
  "deps/v8/src/utils/allocation.h"
  "deps/v8/src/utils/bit-vector.h"
  "deps/v8/src/utils/boxed-float.h"
  "deps/v8/src/utils/detachable-vector.h"
  "deps/v8/src/utils/identity-map.h"
  "deps/v8/src/utils/locked-queue-inl.h"
  "deps/v8/src/utils/locked-queue.h"
  "deps/v8/src/utils/memcopy.h"
  "deps/v8/src/utils/ostreams.h"
  "deps/v8/src/utils/pointer-with-payload.h"
  "deps/v8/src/utils/utils-inl.h"
  "deps/v8/src/utils/utils.h"
  "deps/v8/src/utils/vector.h"
  "deps/v8/src/utils/version.h"
  "deps/v8/src/wasm/baseline/liftoff-assembler-defs.h"
  "deps/v8/src/wasm/baseline/liftoff-assembler.h"
  "deps/v8/src/wasm/baseline/liftoff-compiler.h"
  "deps/v8/src/wasm/baseline/liftoff-register.h"
  "deps/v8/src/wasm/compilation-environment.h"
  "deps/v8/src/wasm/decoder.h"
  "deps/v8/src/wasm/function-body-decoder-impl.h"
  "deps/v8/src/wasm/function-body-decoder.h"
  "deps/v8/src/wasm/function-compiler.h"
  "deps/v8/src/wasm/graph-builder-interface.h"
  "deps/v8/src/wasm/jump-table-assembler.h"
  "deps/v8/src/wasm/leb-helper.h"
  "deps/v8/src/wasm/local-decl-encoder.h"
  "deps/v8/src/wasm/memory-tracing.h"
  "deps/v8/src/wasm/module-compiler.h"
  "deps/v8/src/wasm/module-decoder.h"
  "deps/v8/src/wasm/module-instantiate.h"
  "deps/v8/src/wasm/object-access.h"
  "deps/v8/src/wasm/signature-map.h"
  "deps/v8/src/wasm/streaming-decoder.h"
  "deps/v8/src/wasm/value-type.h"
  "deps/v8/src/wasm/wasm-arguments.h"
  "deps/v8/src/wasm/wasm-code-manager.h"
  "deps/v8/src/wasm/wasm-constants.h"
  "deps/v8/src/wasm/wasm-engine.h"
  "deps/v8/src/wasm/wasm-external-refs.h"
  "deps/v8/src/wasm/wasm-feature-flags.h"
  "deps/v8/src/wasm/wasm-features.h"
  "deps/v8/src/wasm/wasm-import-wrapper-cache.h"
  "deps/v8/src/wasm/wasm-interpreter.h"
  "deps/v8/src/wasm/wasm-js.h"
  "deps/v8/src/wasm/wasm-limits.h"
  "deps/v8/src/wasm/wasm-linkage.h"
  "deps/v8/src/wasm/wasm-module-builder.h"
  "deps/v8/src/wasm/wasm-module-sourcemap.h"
  "deps/v8/src/wasm/wasm-module.h"
  "deps/v8/src/wasm/wasm-objects-inl.h"
  "deps/v8/src/wasm/wasm-objects.h"
  "deps/v8/src/wasm/wasm-opcodes.h"
  "deps/v8/src/wasm/wasm-result.h"
  "deps/v8/src/wasm/wasm-serialization.h"
  "deps/v8/src/wasm/wasm-text.h"
  "deps/v8/src/wasm/wasm-tier.h"
  "deps/v8/src/wasm/wasm-value.h"
  "deps/v8/src/zone/accounting-allocator.h"
  "deps/v8/src/zone/zone-allocator.h"
  "deps/v8/src/zone/zone-chunk-list.h"
  "deps/v8/src/zone/zone-containers.h"
  "deps/v8/src/zone/zone-handle-set.h"
  "deps/v8/src/zone/zone-list-inl.h"
  "deps/v8/src/zone/zone-segment.h"
  "deps/v8/src/zone/zone.h"
  "deps/v8/src/inspector/custom-preview.h"
  "deps/v8/src/inspector/injected-script.h"
  "deps/v8/src/inspector/inspected-context.h"
  "deps/v8/src/inspector/remote-object-id.h"
  "deps/v8/src/inspector/search-util.h"
  "deps/v8/src/inspector/string-16.h"
  "deps/v8/src/inspector/string-util.h"
  "deps/v8/src/inspector/test-interface.h"
  "deps/v8/src/inspector/v8-console.h"
  "deps/v8/src/inspector/v8-console-agent-impl.h"
  "deps/v8/src/inspector/v8-console-message.h"
  "deps/v8/src/inspector/v8-debugger.h"
  "deps/v8/src/inspector/v8-debugger-agent-impl.h"
  "deps/v8/src/inspector/v8-debugger-script.h"
  "deps/v8/src/inspector/v8-heap-profiler-agent-impl.h"
  "deps/v8/src/inspector/v8-inspector-impl.h"
  "deps/v8/src/inspector/v8-inspector-protocol-encoding.h"
  "deps/v8/src/inspector/v8-inspector-session-impl.h"
  "deps/v8/src/inspector/v8-profiler-agent-impl.h"
  "deps/v8/src/inspector/v8-regex.h"
  "deps/v8/src/inspector/v8-runtime-agent-impl.h"
  "deps/v8/src/inspector/v8-schema-agent-impl.h"
  "deps/v8/src/inspector/v8-stack-trace-impl.h"
  "deps/v8/src/inspector/v8-value-utils.h"
  "deps/v8/src/inspector/value-mirror.h"
  "deps/v8/src/inspector/wasm-translation.h"
  "deps/v8/src/inspector/v8-string-conversions.h"
  "deps/v8/third_party/inspector_protocol/encoding/encoding.h"
  "deps/v8/third_party/inspector_protocol/bindings/bindings.h"
  "deps/v8/src/codegen/x64/assembler-x64-inl.h"
  "deps/v8/src/codegen/x64/assembler-x64.h"
  "deps/v8/src/codegen/x64/constants-x64.h"
  "deps/v8/src/codegen/x64/macro-assembler-x64.h"
  "deps/v8/src/codegen/x64/register-x64.h"
  "deps/v8/src/codegen/x64/sse-instr.h"
  "deps/v8/src/compiler/backend/x64/instruction-codes-x64.h"
  "deps/v8/src/compiler/backend/x64/unwinding-info-writer-x64.h"
  "deps/v8/src/execution/x64/frame-constants-x64.h"
  "deps/v8/src/regexp/x64/regexp-macro-assembler-x64.h"
  "deps/v8/src/third_party/valgrind/valgrind.h"
  "deps/v8/src/wasm/baseline/x64/liftoff-assembler-x64.h"
  "deps/v8/src/trap-handler/handler-inside-posix.h"
  "${obj}/gen/torque-output-root/torque-generated/class-verifiers-tq.h"
  "deps/v8/include/v8-wasm-trap-handler-win.h"
  "deps/v8/src/common/globals.h"
  "deps/v8/include/v8-value-serializer-version.h"
  "deps/v8/include/v8-version-string.h"
  "deps/v8/include/v8-version.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Forward.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Protocol.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Console.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Debugger.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/HeapProfiler.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Profiler.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Runtime.h"
  "${obj}/gen/inspector-generated-output-root/src/inspector/protocol/Schema.h"
  "${obj}/gen/inspector-generated-output-root/include/inspector/Debugger.h"
  "${obj}/gen/inspector-generated-output-root/include/inspector/Runtime.h"
  "${obj}/gen/inspector-generated-output-root/include/inspector/Schema.h")
add_library(v8_base_without_compiler STATIC ${v8_base_without_compiler__cxx_srcs} ${v8_base_without_compiler__other_srcs})
set_target_properties(v8_base_without_compiler PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(v8_base_without_compiler__protocol_compatibility PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(v8_base_without_compiler__protocol_generated_sources PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${v8_base_without_compiler__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(v8_base_without_compiler PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(v8_base_without_compiler PROPERTIES PREFIX "lib")
set_target_properties(v8_base_without_compiler PROPERTIES ARCHIVE_OUTPUT_NAME "v8_base_without_compiler")
set_target_properties(v8_base_without_compiler PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libv8_base_without_compiler.a PROPERTIES GENERATED "TRUE")
list(APPEND v8_base_without_compiler__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${obj}/gen/inspector-generated-output-root"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/third_party/inspector_protocol"
  "${obj}/gen/torque-output-root"
  "${obj}/gen/generate-bytecode-output-root"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET v8_base_without_compiler APPEND PROPERTY INCLUDE_DIRECTORIES ${v8_base_without_compiler__include_dirs})
set_target_properties(v8_base_without_compiler PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;ICU_UTIL_DATA_IMPL=ICU_UTIL_DATA_STATIC;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(v8_base_without_compiler PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(v8_base_without_compiler PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(v8_base_without_compiler__protocol_compatibility
  torque_generated_definitions
  v8_headers
  v8_shared_internal_headers
  v8_version
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  run_gen-regexp-special-case
  postmortem-metadata
)
add_dependencies(v8_base_without_compiler__protocol_generated_sources
  torque_generated_definitions
  v8_headers
  v8_shared_internal_headers
  v8_version
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  run_gen-regexp-special-case
  postmortem-metadata
)
add_dependencies(v8_base_without_compiler
  torque_generated_definitions
  v8_headers
  v8_shared_internal_headers
  v8_version
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  run_gen-regexp-special-case
  postmortem-metadata
  v8_base_without_compiler__protocol_compatibility
  v8_base_without_compiler__protocol_generated_sources
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_base#target
set(TARGET "v8_base")
set(TOOLSET "target")
add_custom_target(v8_base SOURCES)
set_target_properties(v8_base PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(v8_base
  v8_base_without_compiler
  v8_compiler
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:mksnapshot#target
set(TARGET "mksnapshot")
set(TOOLSET "target")
list(APPEND mksnapshot__cxx_srcs
  "deps/v8/src/snapshot/embedded/embedded-file-writer.cc"
  "deps/v8/src/snapshot/embedded/platform-embedded-file-writer-aix.cc"
  "deps/v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc"
  "deps/v8/src/snapshot/embedded/platform-embedded-file-writer-generic.cc"
  "deps/v8/src/snapshot/embedded/platform-embedded-file-writer-mac.cc"
  "deps/v8/src/snapshot/embedded/platform-embedded-file-writer-win.cc"
  "deps/v8/src/snapshot/mksnapshot.cc")
list(APPEND mksnapshot__other_srcs
  "deps/v8/src/snapshot/embedded/embedded-file-writer.h"
  "deps/v8/src/snapshot/embedded/platform-embedded-file-writer-aix.h"
  "deps/v8/src/snapshot/embedded/platform-embedded-file-writer-base.h"
  "deps/v8/src/snapshot/embedded/platform-embedded-file-writer-generic.h"
  "deps/v8/src/snapshot/embedded/platform-embedded-file-writer-mac.h"
  "deps/v8/src/snapshot/embedded/platform-embedded-file-writer-win.h")
add_executable(mksnapshot ${mksnapshot__cxx_srcs} ${mksnapshot__other_srcs})
set_target_properties(mksnapshot PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${mksnapshot__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(mksnapshot PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(mksnapshot PROPERTIES PREFIX "")
set_target_properties(mksnapshot PROPERTIES RUNTIME_OUTPUT_NAME "mksnapshot")
set_target_properties(mksnapshot PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/mksnapshot PROPERTIES GENERATED "TRUE")
list(APPEND mksnapshot__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${obj}/gen/generate-bytecode-output-root"
  "${obj}/gen/torque-output-root"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET mksnapshot APPEND PROPERTY INCLUDE_DIRECTORIES ${mksnapshot__include_dirs})
set_target_properties(mksnapshot PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(mksnapshot PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(mksnapshot PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(mksnapshot
  v8_compiler_for_mksnapshot
  v8_maybe_icu
  torque_generated_definitions
  generate_bytecode_builtins_list
  run_torque
  icu_implementation
  icu_uconfig
  icu_uconfig_target
  icuuc
  icu_implementation_host
  v8_headers
  v8_version
  v8_shared_internal_headers
  run_gen-regexp-special-case
  postmortem-metadata
  torque_generated_initializers
)
target_link_libraries(mksnapshot
  v8_base_without_compiler
  v8_init
  v8_libbase
  v8_libplatform
  v8_nosnapshot
  icui18n
  icuucx
  icudata
  v8_libsampler
  v8_compiler
  v8_initializers
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_snapshot#target
set(TARGET "v8_snapshot")
set(TOOLSET "target")
set(v8_snapshot__run_mksnapshot__input "${builddir}/mksnapshot")
list(APPEND v8_snapshot__run_mksnapshot__output
  "${obj}.${TOOLSET}/${TARGET}/geni/snapshot.cc"
  "${obj}.${TOOLSET}/${TARGET}/geni/embedded.S")
add_custom_command(OUTPUT ${v8_snapshot__run_mksnapshot__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}.${TOOLSET}/${TARGET}/geni
  COMMAND "${builddir}/mksnapshot" --turbo_instruction_scheduling "--target_os=mac" "--target_arch=x64" --startup_src "${obj}.${TOOLSET}/${TARGET}/geni/snapshot.cc" --embedded_variant Default --embedded_src "${obj}.${TOOLSET}/${TARGET}/geni/embedded.S" --no-native-code-counters
  DEPENDS ${v8_snapshot__run_mksnapshot__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tools/v8_gypfiles
  COMMENT generating: "${obj}.${TOOLSET}/${TARGET}/geni/snapshot.cc" "${obj}.${TOOLSET}/${TARGET}/geni/embedded.S"
  VERBATIM
)
add_custom_target(v8_snapshot__run_mksnapshot
  DEPENDS ${v8_snapshot__run_mksnapshot__output}
  SOURCES ${v8_snapshot__run_mksnapshot__input}
)
set(v8_snapshot__asm_srcs "${obj}.${TOOLSET}/${TARGET}/geni/embedded.S")
list(APPEND v8_snapshot__cxx_srcs
  "deps/v8/src/init/setup-isolate-deserialize.cc"
  "tools/v8_gypfiles/extras-libraries.cc"
  "${obj}.${TOOLSET}/${TARGET}/geni/snapshot.cc")
set(v8_snapshot__other_srcs "${obj}/gen/generate-bytecode-output-root/builtins-generated/bytecodes-builtins-list.h")
add_library(v8_snapshot STATIC ${v8_snapshot__asm_srcs} ${v8_snapshot__cxx_srcs} ${v8_snapshot__other_srcs})
set_target_properties(v8_snapshot PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(v8_snapshot__run_mksnapshot PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${v8_snapshot__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(v8_snapshot PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(v8_snapshot PROPERTIES PREFIX "lib")
set_target_properties(v8_snapshot PROPERTIES ARCHIVE_OUTPUT_NAME "v8_snapshot")
set_target_properties(v8_snapshot PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libv8_snapshot.a PROPERTIES GENERATED "TRUE")
list(APPEND v8_snapshot__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${obj}/gen/generate-bytecode-output-root"
  "${obj}/gen/torque-output-root"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common")
set_property(TARGET v8_snapshot APPEND PROPERTY INCLUDE_DIRECTORIES ${v8_snapshot__include_dirs})
set_target_properties(v8_snapshot PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_source_files_properties(${v8_snapshot__asm_srcs} PROPERTIES COMPILE_FLAGS "-O3 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter ")
set_source_files_properties(${v8_snapshot__cxx_srcs} PROPERTIES COMPILE_FLAGS "-O3 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_GCC_GENERATE_DEBUGGING_SYMBOLS "NO")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(v8_snapshot PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(v8_snapshot__run_mksnapshot
  generate_bytecode_builtins_list
  run_torque
  mksnapshot
  v8_maybe_icu
  v8_compiler_for_mksnapshot
)
add_dependencies(v8_snapshot
  generate_bytecode_builtins_list
  run_torque
  mksnapshot
  v8_maybe_icu
  v8_compiler_for_mksnapshot
  v8_snapshot__run_mksnapshot
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8_maybe_snapshot#target
set(TARGET "v8_maybe_snapshot")
set(TOOLSET "target")
add_custom_target(v8_maybe_snapshot SOURCES)
set_target_properties(v8_maybe_snapshot PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(v8_maybe_snapshot
  v8_base
  v8_snapshot
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/tools/v8_gypfiles/v8.gyp:v8#target
set(TARGET "v8")
set(TOOLSET "target")
set(v8__v8_dump_build_config__input "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/testrunner/utils/dump_build_config_gyp.py")
set(v8__v8_dump_build_config__output "${builddir}/v8_build_config.json")
add_custom_command(OUTPUT ${v8__v8_dump_build_config__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${builddir}
  COMMAND python ../../deps/v8/tools/testrunner/utils/dump_build_config_gyp.py "${builddir}/v8_build_config.json" "dcheck_always_on=0" "is_android=0" "is_asan=0" "is_cfi=0" "is_clang=1" "is_component_build=static_library" "is_debug=${configuration}" "is_gcov_coverage=0" "is_msan=0" "is_tsan=0" "is_ubsan_vptr=0" "target_cpu=x64" "v8_enable_i18n_support=1" "v8_enable_verify_predictable=0" "v8_target_cpu=x64" "v8_use_siphash=1" "v8_enable_embedded_builtins=1" "v8_enable_verify_csa=0" "v8_enable_lite_mode=0" "v8_enable_pointer_compression=0"
  DEPENDS ${v8__v8_dump_build_config__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tools/v8_gypfiles
  COMMENT v8__v8_dump_build_config
  VERBATIM
)
add_custom_target(v8__v8_dump_build_config
  DEPENDS ${v8__v8_dump_build_config__output}
  SOURCES ${v8__v8_dump_build_config__input}
)
add_library(v8 STATIC)
set_target_properties(v8 PROPERTIES EXCLUDE_FROM_ALL "TRUE")
set_target_properties(v8__v8_dump_build_config PROPERTIES EXCLUDE_FROM_ALL "TRUE")
set_target_properties(v8 PROPERTIES LINKER_LANGUAGE "C")
set_target_properties(v8 PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/tools/v8_gypfiles")
set_target_properties(v8 PROPERTIES PREFIX "lib")
set_target_properties(v8 PROPERTIES ARCHIVE_OUTPUT_NAME "v8")
set_target_properties(v8 PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/tools/v8_gypfiles/libv8.a PROPERTIES GENERATED "TRUE")
list(APPEND v8__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include")
set_property(TARGET v8 APPEND PROPERTY INCLUDE_DIRECTORIES ${v8__include_dirs})
set_target_properties(v8 PROPERTIES COMPILE_DEFINITIONS "V8_GYP_BUILD;V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;V8_TARGET_ARCH_X64;V8_EMBEDDER_STRING=\"-node.29\";ENABLE_DISASSEMBLER;V8_PROMISE_INTERNAL_FIELD_COUNT=1;ENABLE_MINOR_MC;V8_INTL_SUPPORT;V8_CONCURRENT_MARKING;V8_ENABLE_LAZY_SOURCE_POSITIONS;V8_EMBEDDED_BUILTINS;V8_USE_SIPHASH;DISABLE_UNTRUSTED_CODE_MITIGATIONS;V8_WIN64_UNWINDING_INFO;V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH;DEBUG;_DEBUG;V8_ENABLE_CHECKS;OBJECT_PRINT;VERIFY_HEAP;V8_TRACE_MAPS;V8_ENABLE_ALLOCATION_TIMEOUT;V8_ENABLE_FORCE_SLOW_PATH;ENABLE_HANDLE_ZAPPING;")
set_target_properties(v8 PROPERTIES COMPILE_FLAGS "-O3 -gdwarf-2 -fstrict-aliasing -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "3")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_GCC_STRICT_ALIASING "YES")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(v8 PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
add_dependencies(v8__v8_dump_build_config
  v8_maybe_snapshot
)
add_dependencies(v8
  v8_maybe_snapshot
  v8__v8_dump_build_config
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/node.gyp:specialize_node_d#target
set(TARGET "specialize_node_d")
set(TOOLSET "target")
set(specialize_node_d__specialize_node_d__input "${CMAKE_CURRENT_LIST_DIR}/src/node.d")
set(specialize_node_d__specialize_node_d__output "${builddir}/node.d")
add_custom_command(OUTPUT ${specialize_node_d__specialize_node_d__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${builddir}
  COMMAND tools/specialize_node_d.py "${builddir}/node.d" src/node.d mac x64
  DEPENDS ${specialize_node_d__specialize_node_d__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
  COMMENT specialize_node_d__specialize_node_d
  VERBATIM
)
add_custom_target(specialize_node_d__specialize_node_d
  DEPENDS ${specialize_node_d__specialize_node_d__output}
  SOURCES ${specialize_node_d__specialize_node_d__input}
)
add_custom_target(specialize_node_d SOURCES)
set_target_properties(specialize_node_d PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(specialize_node_d__specialize_node_d PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(specialize_node_d
  specialize_node_d__specialize_node_d
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/node.gyp:node_text_start#target
set(TARGET "node_text_start")
set(TOOLSET "target")
add_custom_target(node_text_start SOURCES)
set_target_properties(node_text_start PROPERTIES EXCLUDE_FROM_ALL "FALSE")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/node.gyp:node_etw#target
set(TARGET "node_etw")
set(TOOLSET "target")
add_custom_target(node_etw SOURCES)
set_target_properties(node_etw PROPERTIES EXCLUDE_FROM_ALL "FALSE")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/node.gyp:node_dtrace_ustack#target
set(TARGET "node_dtrace_ustack")
set(TOOLSET "target")
add_custom_target(node_dtrace_ustack SOURCES)
set_target_properties(node_dtrace_ustack PROPERTIES EXCLUDE_FROM_ALL "FALSE")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/node.gyp:node_dtrace_provider#target
set(TARGET "node_dtrace_provider")
set(TOOLSET "target")
add_custom_target(node_dtrace_provider SOURCES)
set_target_properties(node_dtrace_provider PROPERTIES EXCLUDE_FROM_ALL "FALSE")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/node.gyp:node_dtrace_header#target
set(TARGET "node_dtrace_header")
set(TOOLSET "target")
set(node_dtrace_header__node_dtrace_header__input "${CMAKE_CURRENT_LIST_DIR}/src/node_provider.d")
set(node_dtrace_header__node_dtrace_header__output "${obj}/gen/node_provider.h")
add_custom_command(OUTPUT ${node_dtrace_header__node_dtrace_header__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen
  COMMAND dtrace -h -xnolibs -s src/node_provider.d -o "${obj}/gen/node_provider.h"
  DEPENDS ${node_dtrace_header__node_dtrace_header__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
  COMMENT node_dtrace_header__node_dtrace_header
  VERBATIM
)
add_custom_target(node_dtrace_header__node_dtrace_header
  DEPENDS ${node_dtrace_header__node_dtrace_header__output}
  SOURCES ${node_dtrace_header__node_dtrace_header__input}
)
add_custom_target(node_dtrace_header SOURCES)
set_target_properties(node_dtrace_header PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(node_dtrace_header__node_dtrace_header PROPERTIES EXCLUDE_FROM_ALL "FALSE")
add_dependencies(node_dtrace_header
  node_dtrace_header__node_dtrace_header
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/deps/zlib/zlib.gyp:zlib#target
set(TARGET "zlib")
set(TOOLSET "target")
list(APPEND zlib__c_srcs
  "deps/zlib/adler32.c"
  "deps/zlib/compress.c"
  "deps/zlib/crc32.c"
  "deps/zlib/deflate.c"
  "deps/zlib/gzclose.c"
  "deps/zlib/gzlib.c"
  "deps/zlib/gzread.c"
  "deps/zlib/gzwrite.c"
  "deps/zlib/infback.c"
  "deps/zlib/inffast.c"
  "deps/zlib/inftrees.c"
  "deps/zlib/trees.c"
  "deps/zlib/uncompr.c"
  "deps/zlib/zutil.c"
  "deps/zlib/adler32_simd.c"
  "deps/zlib/contrib/optimizations/inffast_chunk.c"
  "deps/zlib/contrib/optimizations/inflate.c"
  "deps/zlib/crc32_simd.c"
  "deps/zlib/crc_folding.c"
  "deps/zlib/fill_window_sse.c"
  "deps/zlib/x86.c")
list(APPEND zlib__other_srcs
  "deps/zlib/contrib/optimizations/insert_string.h"
  "deps/zlib/crc32.h"
  "deps/zlib/deflate.h"
  "deps/zlib/gzguts.h"
  "deps/zlib/inffast.h"
  "deps/zlib/inffixed.h"
  "deps/zlib/inflate.h"
  "deps/zlib/inftrees.h"
  "deps/zlib/trees.h"
  "deps/zlib/x86.h"
  "deps/zlib/zconf.h"
  "deps/zlib/zlib.h"
  "deps/zlib/zutil.h"
  "deps/zlib/adler32_simd.h"
  "deps/zlib/contrib/optimizations/chunkcopy.h"
  "deps/zlib/contrib/optimizations/inffast_chunk.h"
  "deps/zlib/crc32_simd.h")
add_library(zlib STATIC ${zlib__c_srcs} ${zlib__other_srcs})
set_target_properties(zlib PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${zlib__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(zlib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/deps/zlib")
set_target_properties(zlib PROPERTIES PREFIX "lib")
set_target_properties(zlib PROPERTIES ARCHIVE_OUTPUT_NAME "zlib")
set_target_properties(zlib PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/deps/zlib/libzlib.a PROPERTIES GENERATED "TRUE")
set(zlib__include_dirs "${CMAKE_CURRENT_LIST_DIR}/deps/zlib")
set_property(TARGET zlib APPEND PROPERTY INCLUDE_DIRECTORIES ${zlib__include_dirs})
set_target_properties(zlib PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;HAVE_HIDDEN;USE_FILE32API;ADLER32_SIMD_SSSE3;INFLATE_CHUNK_SIMD_SSE2;CRC32_SIMD_SSE42_PCLMUL;INFLATE_CHUNK_READ_64LE;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(zlib PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -fno-strict-aliasing -mssse3 -msse4.2 -mpclmul ")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing -mssse3 -msse4.2 -mpclmul ")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(zlib PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/deps/uv/uv.gyp:libuv#target
set(TARGET "libuv")
set(TOOLSET "target")
list(APPEND libuv__c_srcs
  "deps/uv/src/fs-poll.c"
  "deps/uv/src/idna.c"
  "deps/uv/src/inet.c"
  "deps/uv/src/random.c"
  "deps/uv/src/strscpy.c"
  "deps/uv/src/threadpool.c"
  "deps/uv/src/timer.c"
  "deps/uv/src/uv-data-getter-setters.c"
  "deps/uv/src/uv-common.c"
  "deps/uv/src/version.c"
  "deps/uv/src/unix/async.c"
  "deps/uv/src/unix/core.c"
  "deps/uv/src/unix/dl.c"
  "deps/uv/src/unix/fs.c"
  "deps/uv/src/unix/getaddrinfo.c"
  "deps/uv/src/unix/getnameinfo.c"
  "deps/uv/src/unix/loop.c"
  "deps/uv/src/unix/loop-watcher.c"
  "deps/uv/src/unix/pipe.c"
  "deps/uv/src/unix/poll.c"
  "deps/uv/src/unix/process.c"
  "deps/uv/src/unix/random-devurandom.c"
  "deps/uv/src/unix/signal.c"
  "deps/uv/src/unix/stream.c"
  "deps/uv/src/unix/tcp.c"
  "deps/uv/src/unix/thread.c"
  "deps/uv/src/unix/tty.c"
  "deps/uv/src/unix/udp.c"
  "deps/uv/src/unix/proctitle.c"
  "deps/uv/src/unix/darwin.c"
  "deps/uv/src/unix/fsevents.c"
  "deps/uv/src/unix/darwin-proctitle.c"
  "deps/uv/src/unix/random-getentropy.c"
  "deps/uv/src/unix/bsd-ifaddrs.c"
  "deps/uv/src/unix/kqueue.c")
list(APPEND libuv__other_srcs
  "deps/uv/common.gypi"
  "deps/uv/include/uv.h"
  "deps/uv/include/uv/tree.h"
  "deps/uv/include/uv/errno.h"
  "deps/uv/include/uv/threadpool.h"
  "deps/uv/include/uv/version.h"
  "deps/uv/src/heap-inl.h"
  "deps/uv/src/idna.h"
  "deps/uv/src/queue.h"
  "deps/uv/src/strscpy.h"
  "deps/uv/src/uv-common.h"
  "deps/uv/include/uv/unix.h"
  "deps/uv/include/uv/linux.h"
  "deps/uv/include/uv/sunos.h"
  "deps/uv/include/uv/darwin.h"
  "deps/uv/include/uv/bsd.h"
  "deps/uv/include/uv/aix.h"
  "deps/uv/src/unix/atomic-ops.h"
  "deps/uv/src/unix/internal.h"
  "deps/uv/src/unix/spinlock.h")
add_library(libuv STATIC ${libuv__c_srcs} ${libuv__other_srcs})
set_target_properties(libuv PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${libuv__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(libuv PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/deps/uv")
set_target_properties(libuv PROPERTIES PREFIX "lib")
set_target_properties(libuv PROPERTIES ARCHIVE_OUTPUT_NAME "uv")
set_target_properties(libuv PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/deps/uv/libuv.a PROPERTIES GENERATED "TRUE")
list(APPEND libuv__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/uv/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/uv/src")
set_property(TARGET libuv APPEND PROPERTY INCLUDE_DIRECTORIES ${libuv__include_dirs})
set_target_properties(libuv PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;_LARGEFILE_SOURCE;_FILE_OFFSET_BITS=64;_DARWIN_UNLIMITED_SELECT=1;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(libuv PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -fvisibility=hidden -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -Wall -Wextra -Wno-unused-parameter -Wstrict-prototypes -fno-strict-aliasing -g --std=gnu89 ")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing -g --std=gnu89 ")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter -Wall -Wextra -Wno-unused-parameter -Wstrict-prototypes ")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(libuv PROPERTIES XCODE_ATTRIBUTE_GCC_SYMBOLS_PRIVATE_EXTERN "YES")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/deps/uvwasi/uvwasi.gyp:uvwasi#target
set(TARGET "uvwasi")
set(TOOLSET "target")
list(APPEND uvwasi__c_srcs
  "deps/uvwasi/src/clocks.c"
  "deps/uvwasi/src/fd_table.c"
  "deps/uvwasi/src/uv_mapping.c"
  "deps/uvwasi/src/uvwasi.c"
  "deps/uvwasi/src/wasi_rights.c")
add_library(uvwasi STATIC ${uvwasi__c_srcs})
set_target_properties(uvwasi PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(uvwasi PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/deps/uvwasi")
set_target_properties(uvwasi PROPERTIES PREFIX "lib")
set_target_properties(uvwasi PROPERTIES ARCHIVE_OUTPUT_NAME "uvwasi")
set_target_properties(uvwasi PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/deps/uvwasi/libuvwasi.a PROPERTIES GENERATED "TRUE")
list(APPEND uvwasi__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/uvwasi/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/uv/include")
set_property(TARGET uvwasi APPEND PROPERTY INCLUDE_DIRECTORIES ${uvwasi__include_dirs})
set_target_properties(uvwasi PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;_LARGEFILE_SOURCE;_FILE_OFFSET_BITS=64;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(uvwasi PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -fvisibility=hidden -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -fno-strict-aliasing ")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(uvwasi PROPERTIES XCODE_ATTRIBUTE_GCC_SYMBOLS_PRIVATE_EXTERN "YES")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/deps/openssl/openssl.gyp:openssl#target
set(TARGET "openssl")
set(TOOLSET "target")
list(APPEND openssl__asm_srcs
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/aes/aesni-mb-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/aes/aesni-sha1-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/aes/aesni-sha256-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/aes/aesni-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/aes/vpaes-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/bn/rsaz-avx2.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/bn/rsaz-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/bn/x86_64-gf2m.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/bn/x86_64-mont.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/bn/x86_64-mont5.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/camellia/cmll-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/chacha/chacha-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/ec/ecp_nistz256-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/ec/x25519-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/md5/md5-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/modes/aesni-gcm-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/modes/ghash-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/poly1305/poly1305-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/rc4/rc4-md5-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/rc4/rc4-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/sha/keccak1600-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/sha/sha1-mb-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/sha/sha1-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/sha/sha256-mb-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/sha/sha256-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/sha/sha512-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/whrlpool/wp-x86_64.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/x86_64cpuid.s"
  "deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/engines/e_padlock-x86_64.s")
list(APPEND openssl__c_srcs
  "deps/openssl/openssl/ssl/bio_ssl.c"
  "deps/openssl/openssl/ssl/d1_lib.c"
  "deps/openssl/openssl/ssl/d1_msg.c"
  "deps/openssl/openssl/ssl/d1_srtp.c"
  "deps/openssl/openssl/ssl/methods.c"
  "deps/openssl/openssl/ssl/packet.c"
  "deps/openssl/openssl/ssl/pqueue.c"
  "deps/openssl/openssl/ssl/record/dtls1_bitmap.c"
  "deps/openssl/openssl/ssl/record/rec_layer_d1.c"
  "deps/openssl/openssl/ssl/record/rec_layer_s3.c"
  "deps/openssl/openssl/ssl/record/ssl3_buffer.c"
  "deps/openssl/openssl/ssl/record/ssl3_record.c"
  "deps/openssl/openssl/ssl/record/ssl3_record_tls13.c"
  "deps/openssl/openssl/ssl/s3_cbc.c"
  "deps/openssl/openssl/ssl/s3_enc.c"
  "deps/openssl/openssl/ssl/s3_lib.c"
  "deps/openssl/openssl/ssl/s3_msg.c"
  "deps/openssl/openssl/ssl/ssl_asn1.c"
  "deps/openssl/openssl/ssl/ssl_cert.c"
  "deps/openssl/openssl/ssl/ssl_ciph.c"
  "deps/openssl/openssl/ssl/ssl_conf.c"
  "deps/openssl/openssl/ssl/ssl_err.c"
  "deps/openssl/openssl/ssl/ssl_init.c"
  "deps/openssl/openssl/ssl/ssl_lib.c"
  "deps/openssl/openssl/ssl/ssl_mcnf.c"
  "deps/openssl/openssl/ssl/ssl_rsa.c"
  "deps/openssl/openssl/ssl/ssl_sess.c"
  "deps/openssl/openssl/ssl/ssl_stat.c"
  "deps/openssl/openssl/ssl/ssl_txt.c"
  "deps/openssl/openssl/ssl/ssl_utst.c"
  "deps/openssl/openssl/ssl/statem/extensions.c"
  "deps/openssl/openssl/ssl/statem/extensions_clnt.c"
  "deps/openssl/openssl/ssl/statem/extensions_cust.c"
  "deps/openssl/openssl/ssl/statem/extensions_srvr.c"
  "deps/openssl/openssl/ssl/statem/statem.c"
  "deps/openssl/openssl/ssl/statem/statem_clnt.c"
  "deps/openssl/openssl/ssl/statem/statem_dtls.c"
  "deps/openssl/openssl/ssl/statem/statem_lib.c"
  "deps/openssl/openssl/ssl/statem/statem_srvr.c"
  "deps/openssl/openssl/ssl/t1_enc.c"
  "deps/openssl/openssl/ssl/t1_lib.c"
  "deps/openssl/openssl/ssl/t1_trce.c"
  "deps/openssl/openssl/ssl/tls13_enc.c"
  "deps/openssl/openssl/ssl/tls_srp.c"
  "deps/openssl/openssl/crypto/aes/aes_cbc.c"
  "deps/openssl/openssl/crypto/aes/aes_cfb.c"
  "deps/openssl/openssl/crypto/aes/aes_core.c"
  "deps/openssl/openssl/crypto/aes/aes_ecb.c"
  "deps/openssl/openssl/crypto/aes/aes_ige.c"
  "deps/openssl/openssl/crypto/aes/aes_misc.c"
  "deps/openssl/openssl/crypto/aes/aes_ofb.c"
  "deps/openssl/openssl/crypto/aes/aes_wrap.c"
  "deps/openssl/openssl/crypto/aria/aria.c"
  "deps/openssl/openssl/crypto/asn1/a_bitstr.c"
  "deps/openssl/openssl/crypto/asn1/a_d2i_fp.c"
  "deps/openssl/openssl/crypto/asn1/a_digest.c"
  "deps/openssl/openssl/crypto/asn1/a_dup.c"
  "deps/openssl/openssl/crypto/asn1/a_gentm.c"
  "deps/openssl/openssl/crypto/asn1/a_i2d_fp.c"
  "deps/openssl/openssl/crypto/asn1/a_int.c"
  "deps/openssl/openssl/crypto/asn1/a_mbstr.c"
  "deps/openssl/openssl/crypto/asn1/a_object.c"
  "deps/openssl/openssl/crypto/asn1/a_octet.c"
  "deps/openssl/openssl/crypto/asn1/a_print.c"
  "deps/openssl/openssl/crypto/asn1/a_sign.c"
  "deps/openssl/openssl/crypto/asn1/a_strex.c"
  "deps/openssl/openssl/crypto/asn1/a_strnid.c"
  "deps/openssl/openssl/crypto/asn1/a_time.c"
  "deps/openssl/openssl/crypto/asn1/a_type.c"
  "deps/openssl/openssl/crypto/asn1/a_utctm.c"
  "deps/openssl/openssl/crypto/asn1/a_utf8.c"
  "deps/openssl/openssl/crypto/asn1/a_verify.c"
  "deps/openssl/openssl/crypto/asn1/ameth_lib.c"
  "deps/openssl/openssl/crypto/asn1/asn1_err.c"
  "deps/openssl/openssl/crypto/asn1/asn1_gen.c"
  "deps/openssl/openssl/crypto/asn1/asn1_item_list.c"
  "deps/openssl/openssl/crypto/asn1/asn1_lib.c"
  "deps/openssl/openssl/crypto/asn1/asn1_par.c"
  "deps/openssl/openssl/crypto/asn1/asn_mime.c"
  "deps/openssl/openssl/crypto/asn1/asn_moid.c"
  "deps/openssl/openssl/crypto/asn1/asn_mstbl.c"
  "deps/openssl/openssl/crypto/asn1/asn_pack.c"
  "deps/openssl/openssl/crypto/asn1/bio_asn1.c"
  "deps/openssl/openssl/crypto/asn1/bio_ndef.c"
  "deps/openssl/openssl/crypto/asn1/d2i_pr.c"
  "deps/openssl/openssl/crypto/asn1/d2i_pu.c"
  "deps/openssl/openssl/crypto/asn1/evp_asn1.c"
  "deps/openssl/openssl/crypto/asn1/f_int.c"
  "deps/openssl/openssl/crypto/asn1/f_string.c"
  "deps/openssl/openssl/crypto/asn1/i2d_pr.c"
  "deps/openssl/openssl/crypto/asn1/i2d_pu.c"
  "deps/openssl/openssl/crypto/asn1/n_pkey.c"
  "deps/openssl/openssl/crypto/asn1/nsseq.c"
  "deps/openssl/openssl/crypto/asn1/p5_pbe.c"
  "deps/openssl/openssl/crypto/asn1/p5_pbev2.c"
  "deps/openssl/openssl/crypto/asn1/p5_scrypt.c"
  "deps/openssl/openssl/crypto/asn1/p8_pkey.c"
  "deps/openssl/openssl/crypto/asn1/t_bitst.c"
  "deps/openssl/openssl/crypto/asn1/t_pkey.c"
  "deps/openssl/openssl/crypto/asn1/t_spki.c"
  "deps/openssl/openssl/crypto/asn1/tasn_dec.c"
  "deps/openssl/openssl/crypto/asn1/tasn_enc.c"
  "deps/openssl/openssl/crypto/asn1/tasn_fre.c"
  "deps/openssl/openssl/crypto/asn1/tasn_new.c"
  "deps/openssl/openssl/crypto/asn1/tasn_prn.c"
  "deps/openssl/openssl/crypto/asn1/tasn_scn.c"
  "deps/openssl/openssl/crypto/asn1/tasn_typ.c"
  "deps/openssl/openssl/crypto/asn1/tasn_utl.c"
  "deps/openssl/openssl/crypto/asn1/x_algor.c"
  "deps/openssl/openssl/crypto/asn1/x_bignum.c"
  "deps/openssl/openssl/crypto/asn1/x_info.c"
  "deps/openssl/openssl/crypto/asn1/x_int64.c"
  "deps/openssl/openssl/crypto/asn1/x_long.c"
  "deps/openssl/openssl/crypto/asn1/x_pkey.c"
  "deps/openssl/openssl/crypto/asn1/x_sig.c"
  "deps/openssl/openssl/crypto/asn1/x_spki.c"
  "deps/openssl/openssl/crypto/asn1/x_val.c"
  "deps/openssl/openssl/crypto/async/arch/async_null.c"
  "deps/openssl/openssl/crypto/async/arch/async_posix.c"
  "deps/openssl/openssl/crypto/async/arch/async_win.c"
  "deps/openssl/openssl/crypto/async/async.c"
  "deps/openssl/openssl/crypto/async/async_err.c"
  "deps/openssl/openssl/crypto/async/async_wait.c"
  "deps/openssl/openssl/crypto/bf/bf_cfb64.c"
  "deps/openssl/openssl/crypto/bf/bf_ecb.c"
  "deps/openssl/openssl/crypto/bf/bf_enc.c"
  "deps/openssl/openssl/crypto/bf/bf_ofb64.c"
  "deps/openssl/openssl/crypto/bf/bf_skey.c"
  "deps/openssl/openssl/crypto/bio/b_addr.c"
  "deps/openssl/openssl/crypto/bio/b_dump.c"
  "deps/openssl/openssl/crypto/bio/b_print.c"
  "deps/openssl/openssl/crypto/bio/b_sock.c"
  "deps/openssl/openssl/crypto/bio/b_sock2.c"
  "deps/openssl/openssl/crypto/bio/bf_buff.c"
  "deps/openssl/openssl/crypto/bio/bf_lbuf.c"
  "deps/openssl/openssl/crypto/bio/bf_nbio.c"
  "deps/openssl/openssl/crypto/bio/bf_null.c"
  "deps/openssl/openssl/crypto/bio/bio_cb.c"
  "deps/openssl/openssl/crypto/bio/bio_err.c"
  "deps/openssl/openssl/crypto/bio/bio_lib.c"
  "deps/openssl/openssl/crypto/bio/bio_meth.c"
  "deps/openssl/openssl/crypto/bio/bss_acpt.c"
  "deps/openssl/openssl/crypto/bio/bss_bio.c"
  "deps/openssl/openssl/crypto/bio/bss_conn.c"
  "deps/openssl/openssl/crypto/bio/bss_dgram.c"
  "deps/openssl/openssl/crypto/bio/bss_fd.c"
  "deps/openssl/openssl/crypto/bio/bss_file.c"
  "deps/openssl/openssl/crypto/bio/bss_log.c"
  "deps/openssl/openssl/crypto/bio/bss_mem.c"
  "deps/openssl/openssl/crypto/bio/bss_null.c"
  "deps/openssl/openssl/crypto/bio/bss_sock.c"
  "deps/openssl/openssl/crypto/blake2/blake2b.c"
  "deps/openssl/openssl/crypto/blake2/blake2s.c"
  "deps/openssl/openssl/crypto/blake2/m_blake2b.c"
  "deps/openssl/openssl/crypto/blake2/m_blake2s.c"
  "deps/openssl/openssl/crypto/bn/asm/x86_64-gcc.c"
  "deps/openssl/openssl/crypto/bn/bn_add.c"
  "deps/openssl/openssl/crypto/bn/bn_blind.c"
  "deps/openssl/openssl/crypto/bn/bn_const.c"
  "deps/openssl/openssl/crypto/bn/bn_ctx.c"
  "deps/openssl/openssl/crypto/bn/bn_depr.c"
  "deps/openssl/openssl/crypto/bn/bn_dh.c"
  "deps/openssl/openssl/crypto/bn/bn_div.c"
  "deps/openssl/openssl/crypto/bn/bn_err.c"
  "deps/openssl/openssl/crypto/bn/bn_exp.c"
  "deps/openssl/openssl/crypto/bn/bn_exp2.c"
  "deps/openssl/openssl/crypto/bn/bn_gcd.c"
  "deps/openssl/openssl/crypto/bn/bn_gf2m.c"
  "deps/openssl/openssl/crypto/bn/bn_intern.c"
  "deps/openssl/openssl/crypto/bn/bn_kron.c"
  "deps/openssl/openssl/crypto/bn/bn_lib.c"
  "deps/openssl/openssl/crypto/bn/bn_mod.c"
  "deps/openssl/openssl/crypto/bn/bn_mont.c"
  "deps/openssl/openssl/crypto/bn/bn_mpi.c"
  "deps/openssl/openssl/crypto/bn/bn_mul.c"
  "deps/openssl/openssl/crypto/bn/bn_nist.c"
  "deps/openssl/openssl/crypto/bn/bn_prime.c"
  "deps/openssl/openssl/crypto/bn/bn_print.c"
  "deps/openssl/openssl/crypto/bn/bn_rand.c"
  "deps/openssl/openssl/crypto/bn/bn_recp.c"
  "deps/openssl/openssl/crypto/bn/bn_shift.c"
  "deps/openssl/openssl/crypto/bn/bn_sqr.c"
  "deps/openssl/openssl/crypto/bn/bn_sqrt.c"
  "deps/openssl/openssl/crypto/bn/bn_srp.c"
  "deps/openssl/openssl/crypto/bn/bn_word.c"
  "deps/openssl/openssl/crypto/bn/bn_x931p.c"
  "deps/openssl/openssl/crypto/bn/rsaz_exp.c"
  "deps/openssl/openssl/crypto/buffer/buf_err.c"
  "deps/openssl/openssl/crypto/buffer/buffer.c"
  "deps/openssl/openssl/crypto/camellia/cmll_cfb.c"
  "deps/openssl/openssl/crypto/camellia/cmll_ctr.c"
  "deps/openssl/openssl/crypto/camellia/cmll_ecb.c"
  "deps/openssl/openssl/crypto/camellia/cmll_misc.c"
  "deps/openssl/openssl/crypto/camellia/cmll_ofb.c"
  "deps/openssl/openssl/crypto/cast/c_cfb64.c"
  "deps/openssl/openssl/crypto/cast/c_ecb.c"
  "deps/openssl/openssl/crypto/cast/c_enc.c"
  "deps/openssl/openssl/crypto/cast/c_ofb64.c"
  "deps/openssl/openssl/crypto/cast/c_skey.c"
  "deps/openssl/openssl/crypto/cmac/cm_ameth.c"
  "deps/openssl/openssl/crypto/cmac/cm_pmeth.c"
  "deps/openssl/openssl/crypto/cmac/cmac.c"
  "deps/openssl/openssl/crypto/cms/cms_asn1.c"
  "deps/openssl/openssl/crypto/cms/cms_att.c"
  "deps/openssl/openssl/crypto/cms/cms_cd.c"
  "deps/openssl/openssl/crypto/cms/cms_dd.c"
  "deps/openssl/openssl/crypto/cms/cms_enc.c"
  "deps/openssl/openssl/crypto/cms/cms_env.c"
  "deps/openssl/openssl/crypto/cms/cms_err.c"
  "deps/openssl/openssl/crypto/cms/cms_ess.c"
  "deps/openssl/openssl/crypto/cms/cms_io.c"
  "deps/openssl/openssl/crypto/cms/cms_kari.c"
  "deps/openssl/openssl/crypto/cms/cms_lib.c"
  "deps/openssl/openssl/crypto/cms/cms_pwri.c"
  "deps/openssl/openssl/crypto/cms/cms_sd.c"
  "deps/openssl/openssl/crypto/cms/cms_smime.c"
  "deps/openssl/openssl/crypto/conf/conf_api.c"
  "deps/openssl/openssl/crypto/conf/conf_def.c"
  "deps/openssl/openssl/crypto/conf/conf_err.c"
  "deps/openssl/openssl/crypto/conf/conf_lib.c"
  "deps/openssl/openssl/crypto/conf/conf_mall.c"
  "deps/openssl/openssl/crypto/conf/conf_mod.c"
  "deps/openssl/openssl/crypto/conf/conf_sap.c"
  "deps/openssl/openssl/crypto/conf/conf_ssl.c"
  "deps/openssl/openssl/crypto/cpt_err.c"
  "deps/openssl/openssl/crypto/cryptlib.c"
  "deps/openssl/openssl/crypto/ct/ct_b64.c"
  "deps/openssl/openssl/crypto/ct/ct_err.c"
  "deps/openssl/openssl/crypto/ct/ct_log.c"
  "deps/openssl/openssl/crypto/ct/ct_oct.c"
  "deps/openssl/openssl/crypto/ct/ct_policy.c"
  "deps/openssl/openssl/crypto/ct/ct_prn.c"
  "deps/openssl/openssl/crypto/ct/ct_sct.c"
  "deps/openssl/openssl/crypto/ct/ct_sct_ctx.c"
  "deps/openssl/openssl/crypto/ct/ct_vfy.c"
  "deps/openssl/openssl/crypto/ct/ct_x509v3.c"
  "deps/openssl/openssl/crypto/ctype.c"
  "deps/openssl/openssl/crypto/cversion.c"
  "deps/openssl/openssl/crypto/des/cbc_cksm.c"
  "deps/openssl/openssl/crypto/des/cbc_enc.c"
  "deps/openssl/openssl/crypto/des/cfb64ede.c"
  "deps/openssl/openssl/crypto/des/cfb64enc.c"
  "deps/openssl/openssl/crypto/des/cfb_enc.c"
  "deps/openssl/openssl/crypto/des/des_enc.c"
  "deps/openssl/openssl/crypto/des/ecb3_enc.c"
  "deps/openssl/openssl/crypto/des/ecb_enc.c"
  "deps/openssl/openssl/crypto/des/fcrypt.c"
  "deps/openssl/openssl/crypto/des/fcrypt_b.c"
  "deps/openssl/openssl/crypto/des/ofb64ede.c"
  "deps/openssl/openssl/crypto/des/ofb64enc.c"
  "deps/openssl/openssl/crypto/des/ofb_enc.c"
  "deps/openssl/openssl/crypto/des/pcbc_enc.c"
  "deps/openssl/openssl/crypto/des/qud_cksm.c"
  "deps/openssl/openssl/crypto/des/rand_key.c"
  "deps/openssl/openssl/crypto/des/set_key.c"
  "deps/openssl/openssl/crypto/des/str2key.c"
  "deps/openssl/openssl/crypto/des/xcbc_enc.c"
  "deps/openssl/openssl/crypto/dh/dh_ameth.c"
  "deps/openssl/openssl/crypto/dh/dh_asn1.c"
  "deps/openssl/openssl/crypto/dh/dh_check.c"
  "deps/openssl/openssl/crypto/dh/dh_depr.c"
  "deps/openssl/openssl/crypto/dh/dh_err.c"
  "deps/openssl/openssl/crypto/dh/dh_gen.c"
  "deps/openssl/openssl/crypto/dh/dh_kdf.c"
  "deps/openssl/openssl/crypto/dh/dh_key.c"
  "deps/openssl/openssl/crypto/dh/dh_lib.c"
  "deps/openssl/openssl/crypto/dh/dh_meth.c"
  "deps/openssl/openssl/crypto/dh/dh_pmeth.c"
  "deps/openssl/openssl/crypto/dh/dh_prn.c"
  "deps/openssl/openssl/crypto/dh/dh_rfc5114.c"
  "deps/openssl/openssl/crypto/dh/dh_rfc7919.c"
  "deps/openssl/openssl/crypto/dsa/dsa_ameth.c"
  "deps/openssl/openssl/crypto/dsa/dsa_asn1.c"
  "deps/openssl/openssl/crypto/dsa/dsa_depr.c"
  "deps/openssl/openssl/crypto/dsa/dsa_err.c"
  "deps/openssl/openssl/crypto/dsa/dsa_gen.c"
  "deps/openssl/openssl/crypto/dsa/dsa_key.c"
  "deps/openssl/openssl/crypto/dsa/dsa_lib.c"
  "deps/openssl/openssl/crypto/dsa/dsa_meth.c"
  "deps/openssl/openssl/crypto/dsa/dsa_ossl.c"
  "deps/openssl/openssl/crypto/dsa/dsa_pmeth.c"
  "deps/openssl/openssl/crypto/dsa/dsa_prn.c"
  "deps/openssl/openssl/crypto/dsa/dsa_sign.c"
  "deps/openssl/openssl/crypto/dsa/dsa_vrf.c"
  "deps/openssl/openssl/crypto/dso/dso_dl.c"
  "deps/openssl/openssl/crypto/dso/dso_dlfcn.c"
  "deps/openssl/openssl/crypto/dso/dso_err.c"
  "deps/openssl/openssl/crypto/dso/dso_lib.c"
  "deps/openssl/openssl/crypto/dso/dso_openssl.c"
  "deps/openssl/openssl/crypto/dso/dso_vms.c"
  "deps/openssl/openssl/crypto/dso/dso_win32.c"
  "deps/openssl/openssl/crypto/ebcdic.c"
  "deps/openssl/openssl/crypto/ec/curve25519.c"
  "deps/openssl/openssl/crypto/ec/curve448/arch_32/f_impl.c"
  "deps/openssl/openssl/crypto/ec/curve448/curve448.c"
  "deps/openssl/openssl/crypto/ec/curve448/curve448_tables.c"
  "deps/openssl/openssl/crypto/ec/curve448/eddsa.c"
  "deps/openssl/openssl/crypto/ec/curve448/f_generic.c"
  "deps/openssl/openssl/crypto/ec/curve448/scalar.c"
  "deps/openssl/openssl/crypto/ec/ec2_oct.c"
  "deps/openssl/openssl/crypto/ec/ec2_smpl.c"
  "deps/openssl/openssl/crypto/ec/ec_ameth.c"
  "deps/openssl/openssl/crypto/ec/ec_asn1.c"
  "deps/openssl/openssl/crypto/ec/ec_check.c"
  "deps/openssl/openssl/crypto/ec/ec_curve.c"
  "deps/openssl/openssl/crypto/ec/ec_cvt.c"
  "deps/openssl/openssl/crypto/ec/ec_err.c"
  "deps/openssl/openssl/crypto/ec/ec_key.c"
  "deps/openssl/openssl/crypto/ec/ec_kmeth.c"
  "deps/openssl/openssl/crypto/ec/ec_lib.c"
  "deps/openssl/openssl/crypto/ec/ec_mult.c"
  "deps/openssl/openssl/crypto/ec/ec_oct.c"
  "deps/openssl/openssl/crypto/ec/ec_pmeth.c"
  "deps/openssl/openssl/crypto/ec/ec_print.c"
  "deps/openssl/openssl/crypto/ec/ecdh_kdf.c"
  "deps/openssl/openssl/crypto/ec/ecdh_ossl.c"
  "deps/openssl/openssl/crypto/ec/ecdsa_ossl.c"
  "deps/openssl/openssl/crypto/ec/ecdsa_sign.c"
  "deps/openssl/openssl/crypto/ec/ecdsa_vrf.c"
  "deps/openssl/openssl/crypto/ec/eck_prn.c"
  "deps/openssl/openssl/crypto/ec/ecp_mont.c"
  "deps/openssl/openssl/crypto/ec/ecp_nist.c"
  "deps/openssl/openssl/crypto/ec/ecp_nistp224.c"
  "deps/openssl/openssl/crypto/ec/ecp_nistp256.c"
  "deps/openssl/openssl/crypto/ec/ecp_nistp521.c"
  "deps/openssl/openssl/crypto/ec/ecp_nistputil.c"
  "deps/openssl/openssl/crypto/ec/ecp_nistz256.c"
  "deps/openssl/openssl/crypto/ec/ecp_oct.c"
  "deps/openssl/openssl/crypto/ec/ecp_smpl.c"
  "deps/openssl/openssl/crypto/ec/ecx_meth.c"
  "deps/openssl/openssl/crypto/engine/eng_all.c"
  "deps/openssl/openssl/crypto/engine/eng_cnf.c"
  "deps/openssl/openssl/crypto/engine/eng_ctrl.c"
  "deps/openssl/openssl/crypto/engine/eng_dyn.c"
  "deps/openssl/openssl/crypto/engine/eng_err.c"
  "deps/openssl/openssl/crypto/engine/eng_fat.c"
  "deps/openssl/openssl/crypto/engine/eng_init.c"
  "deps/openssl/openssl/crypto/engine/eng_lib.c"
  "deps/openssl/openssl/crypto/engine/eng_list.c"
  "deps/openssl/openssl/crypto/engine/eng_openssl.c"
  "deps/openssl/openssl/crypto/engine/eng_pkey.c"
  "deps/openssl/openssl/crypto/engine/eng_rdrand.c"
  "deps/openssl/openssl/crypto/engine/eng_table.c"
  "deps/openssl/openssl/crypto/engine/tb_asnmth.c"
  "deps/openssl/openssl/crypto/engine/tb_cipher.c"
  "deps/openssl/openssl/crypto/engine/tb_dh.c"
  "deps/openssl/openssl/crypto/engine/tb_digest.c"
  "deps/openssl/openssl/crypto/engine/tb_dsa.c"
  "deps/openssl/openssl/crypto/engine/tb_eckey.c"
  "deps/openssl/openssl/crypto/engine/tb_pkmeth.c"
  "deps/openssl/openssl/crypto/engine/tb_rand.c"
  "deps/openssl/openssl/crypto/engine/tb_rsa.c"
  "deps/openssl/openssl/crypto/err/err.c"
  "deps/openssl/openssl/crypto/err/err_all.c"
  "deps/openssl/openssl/crypto/err/err_prn.c"
  "deps/openssl/openssl/crypto/evp/bio_b64.c"
  "deps/openssl/openssl/crypto/evp/bio_enc.c"
  "deps/openssl/openssl/crypto/evp/bio_md.c"
  "deps/openssl/openssl/crypto/evp/bio_ok.c"
  "deps/openssl/openssl/crypto/evp/c_allc.c"
  "deps/openssl/openssl/crypto/evp/c_alld.c"
  "deps/openssl/openssl/crypto/evp/cmeth_lib.c"
  "deps/openssl/openssl/crypto/evp/digest.c"
  "deps/openssl/openssl/crypto/evp/e_aes.c"
  "deps/openssl/openssl/crypto/evp/e_aes_cbc_hmac_sha1.c"
  "deps/openssl/openssl/crypto/evp/e_aes_cbc_hmac_sha256.c"
  "deps/openssl/openssl/crypto/evp/e_aria.c"
  "deps/openssl/openssl/crypto/evp/e_bf.c"
  "deps/openssl/openssl/crypto/evp/e_camellia.c"
  "deps/openssl/openssl/crypto/evp/e_cast.c"
  "deps/openssl/openssl/crypto/evp/e_chacha20_poly1305.c"
  "deps/openssl/openssl/crypto/evp/e_des.c"
  "deps/openssl/openssl/crypto/evp/e_des3.c"
  "deps/openssl/openssl/crypto/evp/e_idea.c"
  "deps/openssl/openssl/crypto/evp/e_null.c"
  "deps/openssl/openssl/crypto/evp/e_old.c"
  "deps/openssl/openssl/crypto/evp/e_rc2.c"
  "deps/openssl/openssl/crypto/evp/e_rc4.c"
  "deps/openssl/openssl/crypto/evp/e_rc4_hmac_md5.c"
  "deps/openssl/openssl/crypto/evp/e_rc5.c"
  "deps/openssl/openssl/crypto/evp/e_seed.c"
  "deps/openssl/openssl/crypto/evp/e_sm4.c"
  "deps/openssl/openssl/crypto/evp/e_xcbc_d.c"
  "deps/openssl/openssl/crypto/evp/encode.c"
  "deps/openssl/openssl/crypto/evp/evp_cnf.c"
  "deps/openssl/openssl/crypto/evp/evp_enc.c"
  "deps/openssl/openssl/crypto/evp/evp_err.c"
  "deps/openssl/openssl/crypto/evp/evp_key.c"
  "deps/openssl/openssl/crypto/evp/evp_lib.c"
  "deps/openssl/openssl/crypto/evp/evp_pbe.c"
  "deps/openssl/openssl/crypto/evp/evp_pkey.c"
  "deps/openssl/openssl/crypto/evp/m_md2.c"
  "deps/openssl/openssl/crypto/evp/m_md4.c"
  "deps/openssl/openssl/crypto/evp/m_md5.c"
  "deps/openssl/openssl/crypto/evp/m_md5_sha1.c"
  "deps/openssl/openssl/crypto/evp/m_mdc2.c"
  "deps/openssl/openssl/crypto/evp/m_null.c"
  "deps/openssl/openssl/crypto/evp/m_ripemd.c"
  "deps/openssl/openssl/crypto/evp/m_sha1.c"
  "deps/openssl/openssl/crypto/evp/m_sha3.c"
  "deps/openssl/openssl/crypto/evp/m_sigver.c"
  "deps/openssl/openssl/crypto/evp/m_wp.c"
  "deps/openssl/openssl/crypto/evp/names.c"
  "deps/openssl/openssl/crypto/evp/p5_crpt.c"
  "deps/openssl/openssl/crypto/evp/p5_crpt2.c"
  "deps/openssl/openssl/crypto/evp/p_dec.c"
  "deps/openssl/openssl/crypto/evp/p_enc.c"
  "deps/openssl/openssl/crypto/evp/p_lib.c"
  "deps/openssl/openssl/crypto/evp/p_open.c"
  "deps/openssl/openssl/crypto/evp/p_seal.c"
  "deps/openssl/openssl/crypto/evp/p_sign.c"
  "deps/openssl/openssl/crypto/evp/p_verify.c"
  "deps/openssl/openssl/crypto/evp/pbe_scrypt.c"
  "deps/openssl/openssl/crypto/evp/pmeth_fn.c"
  "deps/openssl/openssl/crypto/evp/pmeth_gn.c"
  "deps/openssl/openssl/crypto/evp/pmeth_lib.c"
  "deps/openssl/openssl/crypto/ex_data.c"
  "deps/openssl/openssl/crypto/getenv.c"
  "deps/openssl/openssl/crypto/hmac/hm_ameth.c"
  "deps/openssl/openssl/crypto/hmac/hm_pmeth.c"
  "deps/openssl/openssl/crypto/hmac/hmac.c"
  "deps/openssl/openssl/crypto/idea/i_cbc.c"
  "deps/openssl/openssl/crypto/idea/i_cfb64.c"
  "deps/openssl/openssl/crypto/idea/i_ecb.c"
  "deps/openssl/openssl/crypto/idea/i_ofb64.c"
  "deps/openssl/openssl/crypto/idea/i_skey.c"
  "deps/openssl/openssl/crypto/init.c"
  "deps/openssl/openssl/crypto/kdf/hkdf.c"
  "deps/openssl/openssl/crypto/kdf/kdf_err.c"
  "deps/openssl/openssl/crypto/kdf/scrypt.c"
  "deps/openssl/openssl/crypto/kdf/tls1_prf.c"
  "deps/openssl/openssl/crypto/lhash/lh_stats.c"
  "deps/openssl/openssl/crypto/lhash/lhash.c"
  "deps/openssl/openssl/crypto/md4/md4_dgst.c"
  "deps/openssl/openssl/crypto/md4/md4_one.c"
  "deps/openssl/openssl/crypto/md5/md5_dgst.c"
  "deps/openssl/openssl/crypto/md5/md5_one.c"
  "deps/openssl/openssl/crypto/mdc2/mdc2_one.c"
  "deps/openssl/openssl/crypto/mdc2/mdc2dgst.c"
  "deps/openssl/openssl/crypto/mem.c"
  "deps/openssl/openssl/crypto/mem_dbg.c"
  "deps/openssl/openssl/crypto/mem_sec.c"
  "deps/openssl/openssl/crypto/modes/cbc128.c"
  "deps/openssl/openssl/crypto/modes/ccm128.c"
  "deps/openssl/openssl/crypto/modes/cfb128.c"
  "deps/openssl/openssl/crypto/modes/ctr128.c"
  "deps/openssl/openssl/crypto/modes/cts128.c"
  "deps/openssl/openssl/crypto/modes/gcm128.c"
  "deps/openssl/openssl/crypto/modes/ocb128.c"
  "deps/openssl/openssl/crypto/modes/ofb128.c"
  "deps/openssl/openssl/crypto/modes/wrap128.c"
  "deps/openssl/openssl/crypto/modes/xts128.c"
  "deps/openssl/openssl/crypto/o_dir.c"
  "deps/openssl/openssl/crypto/o_fips.c"
  "deps/openssl/openssl/crypto/o_fopen.c"
  "deps/openssl/openssl/crypto/o_init.c"
  "deps/openssl/openssl/crypto/o_str.c"
  "deps/openssl/openssl/crypto/o_time.c"
  "deps/openssl/openssl/crypto/objects/o_names.c"
  "deps/openssl/openssl/crypto/objects/obj_dat.c"
  "deps/openssl/openssl/crypto/objects/obj_err.c"
  "deps/openssl/openssl/crypto/objects/obj_lib.c"
  "deps/openssl/openssl/crypto/objects/obj_xref.c"
  "deps/openssl/openssl/crypto/ocsp/ocsp_asn.c"
  "deps/openssl/openssl/crypto/ocsp/ocsp_cl.c"
  "deps/openssl/openssl/crypto/ocsp/ocsp_err.c"
  "deps/openssl/openssl/crypto/ocsp/ocsp_ext.c"
  "deps/openssl/openssl/crypto/ocsp/ocsp_ht.c"
  "deps/openssl/openssl/crypto/ocsp/ocsp_lib.c"
  "deps/openssl/openssl/crypto/ocsp/ocsp_prn.c"
  "deps/openssl/openssl/crypto/ocsp/ocsp_srv.c"
  "deps/openssl/openssl/crypto/ocsp/ocsp_vfy.c"
  "deps/openssl/openssl/crypto/ocsp/v3_ocsp.c"
  "deps/openssl/openssl/crypto/pem/pem_all.c"
  "deps/openssl/openssl/crypto/pem/pem_err.c"
  "deps/openssl/openssl/crypto/pem/pem_info.c"
  "deps/openssl/openssl/crypto/pem/pem_lib.c"
  "deps/openssl/openssl/crypto/pem/pem_oth.c"
  "deps/openssl/openssl/crypto/pem/pem_pk8.c"
  "deps/openssl/openssl/crypto/pem/pem_pkey.c"
  "deps/openssl/openssl/crypto/pem/pem_sign.c"
  "deps/openssl/openssl/crypto/pem/pem_x509.c"
  "deps/openssl/openssl/crypto/pem/pem_xaux.c"
  "deps/openssl/openssl/crypto/pem/pvkfmt.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_add.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_asn.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_attr.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_crpt.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_crt.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_decr.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_init.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_key.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_kiss.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_mutl.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_npas.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_p8d.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_p8e.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_sbag.c"
  "deps/openssl/openssl/crypto/pkcs12/p12_utl.c"
  "deps/openssl/openssl/crypto/pkcs12/pk12err.c"
  "deps/openssl/openssl/crypto/pkcs7/bio_pk7.c"
  "deps/openssl/openssl/crypto/pkcs7/pk7_asn1.c"
  "deps/openssl/openssl/crypto/pkcs7/pk7_attr.c"
  "deps/openssl/openssl/crypto/pkcs7/pk7_doit.c"
  "deps/openssl/openssl/crypto/pkcs7/pk7_lib.c"
  "deps/openssl/openssl/crypto/pkcs7/pk7_mime.c"
  "deps/openssl/openssl/crypto/pkcs7/pk7_smime.c"
  "deps/openssl/openssl/crypto/pkcs7/pkcs7err.c"
  "deps/openssl/openssl/crypto/poly1305/poly1305.c"
  "deps/openssl/openssl/crypto/poly1305/poly1305_ameth.c"
  "deps/openssl/openssl/crypto/poly1305/poly1305_pmeth.c"
  "deps/openssl/openssl/crypto/rand/drbg_ctr.c"
  "deps/openssl/openssl/crypto/rand/drbg_lib.c"
  "deps/openssl/openssl/crypto/rand/rand_egd.c"
  "deps/openssl/openssl/crypto/rand/rand_err.c"
  "deps/openssl/openssl/crypto/rand/rand_lib.c"
  "deps/openssl/openssl/crypto/rand/rand_unix.c"
  "deps/openssl/openssl/crypto/rand/rand_vms.c"
  "deps/openssl/openssl/crypto/rand/rand_win.c"
  "deps/openssl/openssl/crypto/rand/randfile.c"
  "deps/openssl/openssl/crypto/rc2/rc2_cbc.c"
  "deps/openssl/openssl/crypto/rc2/rc2_ecb.c"
  "deps/openssl/openssl/crypto/rc2/rc2_skey.c"
  "deps/openssl/openssl/crypto/rc2/rc2cfb64.c"
  "deps/openssl/openssl/crypto/rc2/rc2ofb64.c"
  "deps/openssl/openssl/crypto/ripemd/rmd_dgst.c"
  "deps/openssl/openssl/crypto/ripemd/rmd_one.c"
  "deps/openssl/openssl/crypto/rsa/rsa_ameth.c"
  "deps/openssl/openssl/crypto/rsa/rsa_asn1.c"
  "deps/openssl/openssl/crypto/rsa/rsa_chk.c"
  "deps/openssl/openssl/crypto/rsa/rsa_crpt.c"
  "deps/openssl/openssl/crypto/rsa/rsa_depr.c"
  "deps/openssl/openssl/crypto/rsa/rsa_err.c"
  "deps/openssl/openssl/crypto/rsa/rsa_gen.c"
  "deps/openssl/openssl/crypto/rsa/rsa_lib.c"
  "deps/openssl/openssl/crypto/rsa/rsa_meth.c"
  "deps/openssl/openssl/crypto/rsa/rsa_mp.c"
  "deps/openssl/openssl/crypto/rsa/rsa_none.c"
  "deps/openssl/openssl/crypto/rsa/rsa_oaep.c"
  "deps/openssl/openssl/crypto/rsa/rsa_ossl.c"
  "deps/openssl/openssl/crypto/rsa/rsa_pk1.c"
  "deps/openssl/openssl/crypto/rsa/rsa_pmeth.c"
  "deps/openssl/openssl/crypto/rsa/rsa_prn.c"
  "deps/openssl/openssl/crypto/rsa/rsa_pss.c"
  "deps/openssl/openssl/crypto/rsa/rsa_saos.c"
  "deps/openssl/openssl/crypto/rsa/rsa_sign.c"
  "deps/openssl/openssl/crypto/rsa/rsa_ssl.c"
  "deps/openssl/openssl/crypto/rsa/rsa_x931.c"
  "deps/openssl/openssl/crypto/rsa/rsa_x931g.c"
  "deps/openssl/openssl/crypto/seed/seed.c"
  "deps/openssl/openssl/crypto/seed/seed_cbc.c"
  "deps/openssl/openssl/crypto/seed/seed_cfb.c"
  "deps/openssl/openssl/crypto/seed/seed_ecb.c"
  "deps/openssl/openssl/crypto/seed/seed_ofb.c"
  "deps/openssl/openssl/crypto/sha/sha1_one.c"
  "deps/openssl/openssl/crypto/sha/sha1dgst.c"
  "deps/openssl/openssl/crypto/sha/sha256.c"
  "deps/openssl/openssl/crypto/sha/sha512.c"
  "deps/openssl/openssl/crypto/siphash/siphash.c"
  "deps/openssl/openssl/crypto/siphash/siphash_ameth.c"
  "deps/openssl/openssl/crypto/siphash/siphash_pmeth.c"
  "deps/openssl/openssl/crypto/sm2/sm2_crypt.c"
  "deps/openssl/openssl/crypto/sm2/sm2_err.c"
  "deps/openssl/openssl/crypto/sm2/sm2_pmeth.c"
  "deps/openssl/openssl/crypto/sm2/sm2_sign.c"
  "deps/openssl/openssl/crypto/sm3/m_sm3.c"
  "deps/openssl/openssl/crypto/sm3/sm3.c"
  "deps/openssl/openssl/crypto/sm4/sm4.c"
  "deps/openssl/openssl/crypto/srp/srp_lib.c"
  "deps/openssl/openssl/crypto/srp/srp_vfy.c"
  "deps/openssl/openssl/crypto/stack/stack.c"
  "deps/openssl/openssl/crypto/store/loader_file.c"
  "deps/openssl/openssl/crypto/store/store_err.c"
  "deps/openssl/openssl/crypto/store/store_init.c"
  "deps/openssl/openssl/crypto/store/store_lib.c"
  "deps/openssl/openssl/crypto/store/store_register.c"
  "deps/openssl/openssl/crypto/store/store_strings.c"
  "deps/openssl/openssl/crypto/threads_none.c"
  "deps/openssl/openssl/crypto/threads_pthread.c"
  "deps/openssl/openssl/crypto/threads_win.c"
  "deps/openssl/openssl/crypto/ts/ts_asn1.c"
  "deps/openssl/openssl/crypto/ts/ts_conf.c"
  "deps/openssl/openssl/crypto/ts/ts_err.c"
  "deps/openssl/openssl/crypto/ts/ts_lib.c"
  "deps/openssl/openssl/crypto/ts/ts_req_print.c"
  "deps/openssl/openssl/crypto/ts/ts_req_utils.c"
  "deps/openssl/openssl/crypto/ts/ts_rsp_print.c"
  "deps/openssl/openssl/crypto/ts/ts_rsp_sign.c"
  "deps/openssl/openssl/crypto/ts/ts_rsp_utils.c"
  "deps/openssl/openssl/crypto/ts/ts_rsp_verify.c"
  "deps/openssl/openssl/crypto/ts/ts_verify_ctx.c"
  "deps/openssl/openssl/crypto/txt_db/txt_db.c"
  "deps/openssl/openssl/crypto/ui/ui_err.c"
  "deps/openssl/openssl/crypto/ui/ui_lib.c"
  "deps/openssl/openssl/crypto/ui/ui_null.c"
  "deps/openssl/openssl/crypto/ui/ui_openssl.c"
  "deps/openssl/openssl/crypto/ui/ui_util.c"
  "deps/openssl/openssl/crypto/uid.c"
  "deps/openssl/openssl/crypto/whrlpool/wp_dgst.c"
  "deps/openssl/openssl/crypto/x509/by_dir.c"
  "deps/openssl/openssl/crypto/x509/by_file.c"
  "deps/openssl/openssl/crypto/x509/t_crl.c"
  "deps/openssl/openssl/crypto/x509/t_req.c"
  "deps/openssl/openssl/crypto/x509/t_x509.c"
  "deps/openssl/openssl/crypto/x509/x509_att.c"
  "deps/openssl/openssl/crypto/x509/x509_cmp.c"
  "deps/openssl/openssl/crypto/x509/x509_d2.c"
  "deps/openssl/openssl/crypto/x509/x509_def.c"
  "deps/openssl/openssl/crypto/x509/x509_err.c"
  "deps/openssl/openssl/crypto/x509/x509_ext.c"
  "deps/openssl/openssl/crypto/x509/x509_lu.c"
  "deps/openssl/openssl/crypto/x509/x509_meth.c"
  "deps/openssl/openssl/crypto/x509/x509_obj.c"
  "deps/openssl/openssl/crypto/x509/x509_r2x.c"
  "deps/openssl/openssl/crypto/x509/x509_req.c"
  "deps/openssl/openssl/crypto/x509/x509_set.c"
  "deps/openssl/openssl/crypto/x509/x509_trs.c"
  "deps/openssl/openssl/crypto/x509/x509_txt.c"
  "deps/openssl/openssl/crypto/x509/x509_v3.c"
  "deps/openssl/openssl/crypto/x509/x509_vfy.c"
  "deps/openssl/openssl/crypto/x509/x509_vpm.c"
  "deps/openssl/openssl/crypto/x509/x509cset.c"
  "deps/openssl/openssl/crypto/x509/x509name.c"
  "deps/openssl/openssl/crypto/x509/x509rset.c"
  "deps/openssl/openssl/crypto/x509/x509spki.c"
  "deps/openssl/openssl/crypto/x509/x509type.c"
  "deps/openssl/openssl/crypto/x509/x_all.c"
  "deps/openssl/openssl/crypto/x509/x_attrib.c"
  "deps/openssl/openssl/crypto/x509/x_crl.c"
  "deps/openssl/openssl/crypto/x509/x_exten.c"
  "deps/openssl/openssl/crypto/x509/x_name.c"
  "deps/openssl/openssl/crypto/x509/x_pubkey.c"
  "deps/openssl/openssl/crypto/x509/x_req.c"
  "deps/openssl/openssl/crypto/x509/x_x509.c"
  "deps/openssl/openssl/crypto/x509/x_x509a.c"
  "deps/openssl/openssl/crypto/x509v3/pcy_cache.c"
  "deps/openssl/openssl/crypto/x509v3/pcy_data.c"
  "deps/openssl/openssl/crypto/x509v3/pcy_lib.c"
  "deps/openssl/openssl/crypto/x509v3/pcy_map.c"
  "deps/openssl/openssl/crypto/x509v3/pcy_node.c"
  "deps/openssl/openssl/crypto/x509v3/pcy_tree.c"
  "deps/openssl/openssl/crypto/x509v3/v3_addr.c"
  "deps/openssl/openssl/crypto/x509v3/v3_admis.c"
  "deps/openssl/openssl/crypto/x509v3/v3_akey.c"
  "deps/openssl/openssl/crypto/x509v3/v3_akeya.c"
  "deps/openssl/openssl/crypto/x509v3/v3_alt.c"
  "deps/openssl/openssl/crypto/x509v3/v3_asid.c"
  "deps/openssl/openssl/crypto/x509v3/v3_bcons.c"
  "deps/openssl/openssl/crypto/x509v3/v3_bitst.c"
  "deps/openssl/openssl/crypto/x509v3/v3_conf.c"
  "deps/openssl/openssl/crypto/x509v3/v3_cpols.c"
  "deps/openssl/openssl/crypto/x509v3/v3_crld.c"
  "deps/openssl/openssl/crypto/x509v3/v3_enum.c"
  "deps/openssl/openssl/crypto/x509v3/v3_extku.c"
  "deps/openssl/openssl/crypto/x509v3/v3_genn.c"
  "deps/openssl/openssl/crypto/x509v3/v3_ia5.c"
  "deps/openssl/openssl/crypto/x509v3/v3_info.c"
  "deps/openssl/openssl/crypto/x509v3/v3_int.c"
  "deps/openssl/openssl/crypto/x509v3/v3_lib.c"
  "deps/openssl/openssl/crypto/x509v3/v3_ncons.c"
  "deps/openssl/openssl/crypto/x509v3/v3_pci.c"
  "deps/openssl/openssl/crypto/x509v3/v3_pcia.c"
  "deps/openssl/openssl/crypto/x509v3/v3_pcons.c"
  "deps/openssl/openssl/crypto/x509v3/v3_pku.c"
  "deps/openssl/openssl/crypto/x509v3/v3_pmaps.c"
  "deps/openssl/openssl/crypto/x509v3/v3_prn.c"
  "deps/openssl/openssl/crypto/x509v3/v3_purp.c"
  "deps/openssl/openssl/crypto/x509v3/v3_skey.c"
  "deps/openssl/openssl/crypto/x509v3/v3_sxnet.c"
  "deps/openssl/openssl/crypto/x509v3/v3_tlsf.c"
  "deps/openssl/openssl/crypto/x509v3/v3_utl.c"
  "deps/openssl/openssl/crypto/x509v3/v3err.c"
  "deps/openssl/openssl/engines/e_capi.c"
  "deps/openssl/openssl/engines/e_padlock.c")
add_library(openssl STATIC ${openssl__asm_srcs} ${openssl__c_srcs})
set_target_properties(openssl PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(openssl PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/deps/openssl")
set_target_properties(openssl PROPERTIES PREFIX "lib")
set_target_properties(openssl PROPERTIES ARCHIVE_OUTPUT_NAME "openssl")
set_target_properties(openssl PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/deps/openssl/libopenssl.a PROPERTIES GENERATED "TRUE")
list(APPEND openssl__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/crypto"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/crypto/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/crypto/modes"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/crypto/ec/curve448"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/crypto/ec/curve448/arch_32"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/config"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/config/archs/darwin64-x86_64-cc/asm_avx2/crypto/include/internal")
set_property(TARGET openssl APPEND PROPERTY INCLUDE_DIRECTORIES ${openssl__include_dirs})
set_target_properties(openssl PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;OPENSSL_NO_HW;NDEBUG;L_ENDIAN;OPENSSL_PIC;OPENSSL_CPUID_OBJ;OPENSSL_IA32_SSE2;OPENSSL_BN_ASM_MONT;OPENSSL_BN_ASM_MONT5;OPENSSL_BN_ASM_GF2m;SHA1_ASM;SHA256_ASM;SHA512_ASM;KECCAK1600_ASM;RC4_ASM;MD5_ASM;VPAES_ASM;GHASH_ASM;ECP_NISTZ256_ASM;X25519_ASM;POLY1305_ASM;OPENSSLDIR=\"/System/Library/OpenSSL/\";ENGINESDIR=\"/dev/null\";DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_source_files_properties(${openssl__asm_srcs} PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -Wno-missing-field-initializers ")
set_source_files_properties(${openssl__c_srcs} PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -Wno-missing-field-initializers -fno-strict-aliasing ")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter -Wno-missing-field-initializers ")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(openssl PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/deps/openssl/openssl.gyp:openssl-cli#target
set(TARGET "openssl-cli")
set(TOOLSET "target")
list(APPEND openssl-cli__c_srcs
  "deps/openssl/openssl/apps/asn1pars.c"
  "deps/openssl/openssl/apps/ca.c"
  "deps/openssl/openssl/apps/ciphers.c"
  "deps/openssl/openssl/apps/cms.c"
  "deps/openssl/openssl/apps/crl.c"
  "deps/openssl/openssl/apps/crl2p7.c"
  "deps/openssl/openssl/apps/dgst.c"
  "deps/openssl/openssl/apps/dhparam.c"
  "deps/openssl/openssl/apps/dsa.c"
  "deps/openssl/openssl/apps/dsaparam.c"
  "deps/openssl/openssl/apps/ec.c"
  "deps/openssl/openssl/apps/ecparam.c"
  "deps/openssl/openssl/apps/enc.c"
  "deps/openssl/openssl/apps/engine.c"
  "deps/openssl/openssl/apps/errstr.c"
  "deps/openssl/openssl/apps/gendsa.c"
  "deps/openssl/openssl/apps/genpkey.c"
  "deps/openssl/openssl/apps/genrsa.c"
  "deps/openssl/openssl/apps/nseq.c"
  "deps/openssl/openssl/apps/ocsp.c"
  "deps/openssl/openssl/apps/openssl.c"
  "deps/openssl/openssl/apps/passwd.c"
  "deps/openssl/openssl/apps/pkcs12.c"
  "deps/openssl/openssl/apps/pkcs7.c"
  "deps/openssl/openssl/apps/pkcs8.c"
  "deps/openssl/openssl/apps/pkey.c"
  "deps/openssl/openssl/apps/pkeyparam.c"
  "deps/openssl/openssl/apps/pkeyutl.c"
  "deps/openssl/openssl/apps/prime.c"
  "deps/openssl/openssl/apps/rand.c"
  "deps/openssl/openssl/apps/rehash.c"
  "deps/openssl/openssl/apps/req.c"
  "deps/openssl/openssl/apps/rsa.c"
  "deps/openssl/openssl/apps/rsautl.c"
  "deps/openssl/openssl/apps/s_client.c"
  "deps/openssl/openssl/apps/s_server.c"
  "deps/openssl/openssl/apps/s_time.c"
  "deps/openssl/openssl/apps/sess_id.c"
  "deps/openssl/openssl/apps/smime.c"
  "deps/openssl/openssl/apps/speed.c"
  "deps/openssl/openssl/apps/spkac.c"
  "deps/openssl/openssl/apps/srp.c"
  "deps/openssl/openssl/apps/storeutl.c"
  "deps/openssl/openssl/apps/ts.c"
  "deps/openssl/openssl/apps/verify.c"
  "deps/openssl/openssl/apps/version.c"
  "deps/openssl/openssl/apps/x509.c"
  "deps/openssl/openssl/apps/app_rand.c"
  "deps/openssl/openssl/apps/apps.c"
  "deps/openssl/openssl/apps/bf_prefix.c"
  "deps/openssl/openssl/apps/opt.c"
  "deps/openssl/openssl/apps/s_cb.c"
  "deps/openssl/openssl/apps/s_socket.c")
add_executable(openssl-cli ${openssl-cli__c_srcs})
set_target_properties(openssl-cli PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(openssl-cli PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(openssl-cli PROPERTIES PREFIX "")
set_target_properties(openssl-cli PROPERTIES RUNTIME_OUTPUT_NAME "openssl-cli")
set_target_properties(openssl-cli PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/openssl-cli PROPERTIES GENERATED "TRUE")
list(APPEND openssl-cli__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/crypto"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/crypto/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/crypto/modes"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/crypto/ec/curve448"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/crypto/ec/curve448/arch_32"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/config"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/config/archs/darwin64-x86_64-cc/asm/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/include")
set_property(TARGET openssl-cli APPEND PROPERTY INCLUDE_DIRECTORIES ${openssl-cli__include_dirs})
set_target_properties(openssl-cli PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;NDEBUG;L_ENDIAN;OPENSSL_PIC;OPENSSL_CPUID_OBJ;OPENSSL_IA32_SSE2;OPENSSL_BN_ASM_MONT;OPENSSL_BN_ASM_MONT5;OPENSSL_BN_ASM_GF2m;SHA1_ASM;SHA256_ASM;SHA512_ASM;KECCAK1600_ASM;RC4_ASM;MD5_ASM;VPAES_ASM;GHASH_ASM;ECP_NISTZ256_ASM;X25519_ASM;POLY1305_ASM;OPENSSLDIR=\"/System/Library/OpenSSL/\";ENGINESDIR=\"/dev/null\";DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(openssl-cli PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -Wno-missing-field-initializers -fno-strict-aliasing ")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(openssl-cli PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter -Wno-missing-field-initializers ")
target_link_libraries(openssl-cli
  openssl
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/deps/nghttp2/nghttp2.gyp:nghttp2#target
set(TARGET "nghttp2")
set(TOOLSET "target")
list(APPEND nghttp2__c_srcs
  "deps/nghttp2/lib/nghttp2_buf.c"
  "deps/nghttp2/lib/nghttp2_callbacks.c"
  "deps/nghttp2/lib/nghttp2_debug.c"
  "deps/nghttp2/lib/nghttp2_frame.c"
  "deps/nghttp2/lib/nghttp2_hd.c"
  "deps/nghttp2/lib/nghttp2_hd_huffman.c"
  "deps/nghttp2/lib/nghttp2_hd_huffman_data.c"
  "deps/nghttp2/lib/nghttp2_helper.c"
  "deps/nghttp2/lib/nghttp2_http.c"
  "deps/nghttp2/lib/nghttp2_map.c"
  "deps/nghttp2/lib/nghttp2_mem.c"
  "deps/nghttp2/lib/nghttp2_npn.c"
  "deps/nghttp2/lib/nghttp2_option.c"
  "deps/nghttp2/lib/nghttp2_outbound_item.c"
  "deps/nghttp2/lib/nghttp2_pq.c"
  "deps/nghttp2/lib/nghttp2_priority_spec.c"
  "deps/nghttp2/lib/nghttp2_queue.c"
  "deps/nghttp2/lib/nghttp2_rcbuf.c"
  "deps/nghttp2/lib/nghttp2_session.c"
  "deps/nghttp2/lib/nghttp2_stream.c"
  "deps/nghttp2/lib/nghttp2_submit.c"
  "deps/nghttp2/lib/nghttp2_version.c")
add_library(nghttp2 STATIC ${nghttp2__c_srcs})
set_target_properties(nghttp2 PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(nghttp2 PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/deps/nghttp2")
set_target_properties(nghttp2 PROPERTIES PREFIX "lib")
set_target_properties(nghttp2 PROPERTIES ARCHIVE_OUTPUT_NAME "nghttp2")
set_target_properties(nghttp2 PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/deps/nghttp2/libnghttp2.a PROPERTIES GENERATED "TRUE")
set(nghttp2__include_dirs "${CMAKE_CURRENT_LIST_DIR}/deps/nghttp2/lib/includes")
set_property(TARGET nghttp2 APPEND PROPERTY INCLUDE_DIRECTORIES ${nghttp2__include_dirs})
set_target_properties(nghttp2 PROPERTIES COMPILE_DEFINITIONS "_U_=;V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;BUILDING_NGHTTP2;NGHTTP2_STATICLIB;HAVE_CONFIG_H;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(nghttp2 PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -fno-strict-aliasing ")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(nghttp2 PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/deps/llhttp/llhttp.gyp:llhttp#target
set(TARGET "llhttp")
set(TOOLSET "target")
list(APPEND llhttp__c_srcs
  "deps/llhttp/src/llhttp.c"
  "deps/llhttp/src/api.c"
  "deps/llhttp/src/http.c")
add_library(llhttp STATIC ${llhttp__c_srcs})
set_target_properties(llhttp PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(llhttp PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/deps/llhttp")
set_target_properties(llhttp PROPERTIES PREFIX "lib")
set_target_properties(llhttp PROPERTIES ARCHIVE_OUTPUT_NAME "llhttp")
set_target_properties(llhttp PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/deps/llhttp/libllhttp.a PROPERTIES GENERATED "TRUE")
list(APPEND llhttp__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/llhttp"
  "${CMAKE_CURRENT_LIST_DIR}/deps/llhttp/include")
set_property(TARGET llhttp APPEND PROPERTY INCLUDE_DIRECTORIES ${llhttp__include_dirs})
set_target_properties(llhttp PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(llhttp PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -fno-strict-aliasing ")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(llhttp PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/deps/histogram/histogram.gyp:histogram#target
set(TARGET "histogram")
set(TOOLSET "target")
set(histogram__c_srcs "deps/histogram/src/hdr_histogram.c")
add_library(histogram STATIC ${histogram__c_srcs})
set_target_properties(histogram PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(histogram PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/deps/histogram")
set_target_properties(histogram PROPERTIES PREFIX "lib")
set_target_properties(histogram PROPERTIES ARCHIVE_OUTPUT_NAME "histogram")
set_target_properties(histogram PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/deps/histogram/libhistogram.a PROPERTIES GENERATED "TRUE")
set(histogram__include_dirs "${CMAKE_CURRENT_LIST_DIR}/deps/histogram/src")
set_property(TARGET histogram APPEND PROPERTY INCLUDE_DIRECTORIES ${histogram__include_dirs})
set_target_properties(histogram PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(histogram PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -fvisibility=hidden -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -fno-strict-aliasing ")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(histogram PROPERTIES XCODE_ATTRIBUTE_GCC_SYMBOLS_PRIVATE_EXTERN "YES")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/deps/cares/cares.gyp:cares#target
set(TARGET "cares")
set(TOOLSET "target")
list(APPEND cares__c_srcs
  "deps/cares/src/ares_android.c"
  "deps/cares/src/ares_cancel.c"
  "deps/cares/src/ares__close_sockets.c"
  "deps/cares/src/ares_create_query.c"
  "deps/cares/src/ares_data.c"
  "deps/cares/src/ares_destroy.c"
  "deps/cares/src/ares_expand_name.c"
  "deps/cares/src/ares_expand_string.c"
  "deps/cares/src/ares_fds.c"
  "deps/cares/src/ares_free_hostent.c"
  "deps/cares/src/ares_free_string.c"
  "deps/cares/src/ares_gethostbyaddr.c"
  "deps/cares/src/ares_gethostbyname.c"
  "deps/cares/src/ares__get_hostent.c"
  "deps/cares/src/ares_getnameinfo.c"
  "deps/cares/src/ares_getopt.c"
  "deps/cares/src/ares_getsock.c"
  "deps/cares/src/ares_init.c"
  "deps/cares/src/ares_library_init.c"
  "deps/cares/src/ares_llist.c"
  "deps/cares/src/ares_mkquery.c"
  "deps/cares/src/ares_nowarn.c"
  "deps/cares/src/ares_options.c"
  "deps/cares/src/ares_parse_aaaa_reply.c"
  "deps/cares/src/ares_parse_a_reply.c"
  "deps/cares/src/ares_parse_mx_reply.c"
  "deps/cares/src/ares_parse_naptr_reply.c"
  "deps/cares/src/ares_parse_ns_reply.c"
  "deps/cares/src/ares_parse_ptr_reply.c"
  "deps/cares/src/ares_parse_soa_reply.c"
  "deps/cares/src/ares_parse_srv_reply.c"
  "deps/cares/src/ares_parse_txt_reply.c"
  "deps/cares/src/ares_process.c"
  "deps/cares/src/ares_query.c"
  "deps/cares/src/ares__read_line.c"
  "deps/cares/src/ares_search.c"
  "deps/cares/src/ares_send.c"
  "deps/cares/src/ares_strcasecmp.c"
  "deps/cares/src/ares_strdup.c"
  "deps/cares/src/ares_strerror.c"
  "deps/cares/src/ares_strsplit.c"
  "deps/cares/src/ares_timeout.c"
  "deps/cares/src/ares__timeval.c"
  "deps/cares/src/ares_version.c"
  "deps/cares/src/ares_writev.c"
  "deps/cares/src/bitncmp.c"
  "deps/cares/src/inet_net_pton.c"
  "deps/cares/src/inet_ntop.c")
list(APPEND cares__other_srcs
  "deps/cares/include/ares.h"
  "deps/cares/include/ares_rules.h"
  "deps/cares/include/ares_version.h"
  "deps/cares/include/nameser.h"
  "deps/cares/src/ares_data.h"
  "deps/cares/src/ares_dns.h"
  "deps/cares/src/ares_getenv.h"
  "deps/cares/src/ares_getopt.h"
  "deps/cares/src/ares_ipv6.h"
  "deps/cares/src/ares_library_init.h"
  "deps/cares/src/ares_llist.h"
  "deps/cares/src/ares_nowarn.h"
  "deps/cares/src/ares_platform.h"
  "deps/cares/src/ares_private.h"
  "deps/cares/src/ares_setup.h"
  "deps/cares/src/ares_strcasecmp.h"
  "deps/cares/src/ares_strdup.h"
  "deps/cares/src/ares_writev.h"
  "deps/cares/src/bitncmp.h"
  "deps/cares/src/ares_inet_net_pton.h"
  "deps/cares/src/setup_once.h"
  "deps/cares/config/darwin/ares_config.h")
add_library(cares STATIC ${cares__c_srcs} ${cares__other_srcs})
set_target_properties(cares PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${cares__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(cares PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/deps/cares")
set_target_properties(cares PROPERTIES PREFIX "lib")
set_target_properties(cares PROPERTIES ARCHIVE_OUTPUT_NAME "cares")
set_target_properties(cares PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/deps/cares/libcares.a PROPERTIES GENERATED "TRUE")
list(APPEND cares__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/deps/cares/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/cares/src"
  "${CMAKE_CURRENT_LIST_DIR}/deps/cares/config/darwin")
set_property(TARGET cares APPEND PROPERTY INCLUDE_DIRECTORIES ${cares__include_dirs})
set_target_properties(cares PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;_LARGEFILE_SOURCE;_FILE_OFFSET_BITS=64;_GNU_SOURCE;OPENSSL_THREADS;CARES_STATICLIB;HAVE_CONFIG_H;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(cares PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -fno-strict-aliasing ")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(cares PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/deps/brotli/brotli.gyp:brotli#target
set(TARGET "brotli")
set(TOOLSET "target")
list(APPEND brotli__c_srcs
  "deps/brotli/c/common/dictionary.c"
  "deps/brotli/c/common/transform.c"
  "deps/brotli/c/dec/bit_reader.c"
  "deps/brotli/c/dec/decode.c"
  "deps/brotli/c/dec/huffman.c"
  "deps/brotli/c/dec/state.c"
  "deps/brotli/c/enc/backward_references.c"
  "deps/brotli/c/enc/backward_references_hq.c"
  "deps/brotli/c/enc/bit_cost.c"
  "deps/brotli/c/enc/block_splitter.c"
  "deps/brotli/c/enc/brotli_bit_stream.c"
  "deps/brotli/c/enc/cluster.c"
  "deps/brotli/c/enc/compress_fragment.c"
  "deps/brotli/c/enc/compress_fragment_two_pass.c"
  "deps/brotli/c/enc/dictionary_hash.c"
  "deps/brotli/c/enc/encode.c"
  "deps/brotli/c/enc/encoder_dict.c"
  "deps/brotli/c/enc/entropy_encode.c"
  "deps/brotli/c/enc/histogram.c"
  "deps/brotli/c/enc/literal_cost.c"
  "deps/brotli/c/enc/memory.c"
  "deps/brotli/c/enc/metablock.c"
  "deps/brotli/c/enc/static_dict.c"
  "deps/brotli/c/enc/utf8_util.c")
add_library(brotli STATIC ${brotli__c_srcs})
set_target_properties(brotli PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(brotli PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${obj}.${TOOLSET}/deps/brotli")
set_target_properties(brotli PROPERTIES PREFIX "lib")
set_target_properties(brotli PROPERTIES ARCHIVE_OUTPUT_NAME "brotli")
set_target_properties(brotli PROPERTIES SUFFIX ".a")
set_source_files_properties(${obj}.${TOOLSET}/deps/brotli/libbrotli.a PROPERTIES GENERATED "TRUE")
set(brotli__include_dirs "${CMAKE_CURRENT_LIST_DIR}/deps/brotli/c/include")
set_property(TARGET brotli APPEND PROPERTY INCLUDE_DIRECTORIES ${brotli__include_dirs})
set_target_properties(brotli PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;OS_MACOSX;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(brotli PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -fno-strict-aliasing ")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter ")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(brotli PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/node.gyp:libnode#target
set(TARGET "libnode")
set(TOOLSET "target")
list(APPEND libnode__node_js2c__input
  "${CMAKE_CURRENT_LIST_DIR}/tools/js2c.py"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/bootstrap/environment.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/bootstrap/loaders.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/bootstrap/node.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/bootstrap/pre_execution.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/bootstrap/switches/does_own_process_state.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/bootstrap/switches/does_not_own_process_state.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/bootstrap/switches/is_main_thread.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/bootstrap/switches/is_not_main_thread.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/per_context/primordials.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/per_context/domexception.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/per_context/messageport.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/async_hooks.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/assert.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/buffer.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/child_process.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/console.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/constants.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/crypto.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/cluster.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/dgram.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/dns.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/domain.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/events.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/fs.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/http.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/http2.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_http_agent.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_http_client.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_http_common.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_http_incoming.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_http_outgoing.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_http_server.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/https.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/inspector.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/module.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/net.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/os.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/path.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/perf_hooks.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/process.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/punycode.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/querystring.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/readline.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/repl.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/stream.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_stream_readable.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_stream_writable.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_stream_duplex.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_stream_transform.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_stream_passthrough.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_stream_wrap.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/string_decoder.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/sys.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/timers.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/tls.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_tls_common.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/_tls_wrap.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/trace_events.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/tty.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/url.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/util.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/v8.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/vm.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/wasi.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/worker_threads.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/zlib.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/assert.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/assert/assertion_error.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/async_hooks.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/buffer.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/cli_table.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/child_process.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/child_process/serialization.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/cluster/child.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/cluster/master.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/cluster/round_robin_handle.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/cluster/shared_handle.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/cluster/utils.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/cluster/worker.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/console/constructor.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/console/global.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/crypto/certificate.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/crypto/cipher.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/crypto/diffiehellman.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/crypto/hash.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/crypto/keygen.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/crypto/keys.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/crypto/pbkdf2.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/crypto/random.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/crypto/scrypt.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/crypto/sig.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/crypto/util.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/constants.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/dgram.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/dns/promises.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/dns/utils.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/dtrace.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/encoding.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/errors.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/error-serdes.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/fixed_queue.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/freelist.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/freeze_intrinsics.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/fs/dir.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/fs/promises.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/fs/read_file_context.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/fs/rimraf.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/fs/streams.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/fs/sync_write_stream.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/fs/utils.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/fs/watchers.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/http.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/heap_utils.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/histogram.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/idna.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/inspector_async_hook.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/js_stream_socket.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/linkedlist.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/main/check_syntax.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/main/eval_string.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/main/eval_stdin.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/main/inspect.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/main/print_help.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/main/prof_process.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/main/repl.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/main/run_main_module.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/main/run_third_party_main.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/main/worker_thread.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/modules/run_main.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/modules/cjs/helpers.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/modules/cjs/loader.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/modules/esm/loader.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/modules/esm/create_dynamic_module.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/modules/esm/get_format.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/modules/esm/get_source.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/modules/esm/module_job.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/modules/esm/module_map.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/modules/esm/resolve.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/modules/esm/transform_source.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/modules/esm/translators.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/net.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/options.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/policy/manifest.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/policy/sri.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/priority_queue.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/process/esm_loader.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/process/execution.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/process/per_thread.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/process/policy.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/process/promises.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/process/warning.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/process/worker_thread_only.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/process/report.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/process/signal.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/process/task_queues.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/querystring.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/readline/utils.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/repl.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/repl/await.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/repl/history.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/repl/utils.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/socket_list.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/source_map/prepare_stack_trace.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/source_map/source_map.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/source_map/source_map_cache.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/test/binding.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/timers.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/tls.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/trace_events_async_hooks.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/tty.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/url.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/util.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/util/comparisons.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/util/debuglog.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/util/inspect.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/util/inspector.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/util/types.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/http2/core.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/http2/compat.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/http2/util.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/v8_prof_polyfill.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/v8_prof_processor.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/validators.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/stream_base_commons.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/vm/module.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/worker.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/worker/io.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/watchdog.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/streams/lazy_transform.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/streams/async_iterator.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/streams/buffer_list.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/streams/duplexpair.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/streams/from.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/streams/legacy.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/streams/destroy.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/streams/state.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/streams/pipeline.js"
  "${CMAKE_CURRENT_LIST_DIR}/lib/internal/streams/end-of-stream.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/splaytree.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/codemap.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/consarray.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/csvparser.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/profile.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/profile_view.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/logreader.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/arguments.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/tickprocessor.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/SourceMap.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/tools/tickprocessor-driver.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/node-inspect/lib/_inspect.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/node-inspect/lib/internal/inspect_client.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/node-inspect/lib/internal/inspect_repl.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/acorn/acorn/dist/acorn.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/acorn/acorn-walk/dist/walk.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/acorn-plugins/acorn-class-fields/index.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/acorn-plugins/acorn-numeric-separator/index.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/acorn-plugins/acorn-private-class-elements/index.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/acorn-plugins/acorn-private-methods/index.js"
  "${CMAKE_CURRENT_LIST_DIR}/deps/acorn-plugins/acorn-static-class-features/index.js"
  "${CMAKE_CURRENT_LIST_DIR}/config.gypi")
set(libnode__node_js2c__output "${obj}/gen/node_javascript.cc")
add_custom_command(OUTPUT ${libnode__node_js2c__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen
  COMMAND python tools/js2c.py lib/internal/bootstrap/environment.js lib/internal/bootstrap/loaders.js lib/internal/bootstrap/node.js lib/internal/bootstrap/pre_execution.js lib/internal/bootstrap/switches/does_own_process_state.js lib/internal/bootstrap/switches/does_not_own_process_state.js lib/internal/bootstrap/switches/is_main_thread.js lib/internal/bootstrap/switches/is_not_main_thread.js lib/internal/per_context/primordials.js lib/internal/per_context/domexception.js lib/internal/per_context/messageport.js lib/async_hooks.js lib/assert.js lib/buffer.js lib/child_process.js lib/console.js lib/constants.js lib/crypto.js lib/cluster.js lib/dgram.js lib/dns.js lib/domain.js lib/events.js lib/fs.js lib/http.js lib/http2.js lib/_http_agent.js lib/_http_client.js lib/_http_common.js lib/_http_incoming.js lib/_http_outgoing.js lib/_http_server.js lib/https.js lib/inspector.js lib/module.js lib/net.js lib/os.js lib/path.js lib/perf_hooks.js lib/process.js lib/punycode.js lib/querystring.js lib/readline.js lib/repl.js lib/stream.js lib/_stream_readable.js lib/_stream_writable.js lib/_stream_duplex.js lib/_stream_transform.js lib/_stream_passthrough.js lib/_stream_wrap.js lib/string_decoder.js lib/sys.js lib/timers.js lib/tls.js lib/_tls_common.js lib/_tls_wrap.js lib/trace_events.js lib/tty.js lib/url.js lib/util.js lib/v8.js lib/vm.js lib/wasi.js lib/worker_threads.js lib/zlib.js lib/internal/assert.js lib/internal/assert/assertion_error.js lib/internal/async_hooks.js lib/internal/buffer.js lib/internal/cli_table.js lib/internal/child_process.js lib/internal/child_process/serialization.js lib/internal/cluster/child.js lib/internal/cluster/master.js lib/internal/cluster/round_robin_handle.js lib/internal/cluster/shared_handle.js lib/internal/cluster/utils.js lib/internal/cluster/worker.js lib/internal/console/constructor.js lib/internal/console/global.js lib/internal/crypto/certificate.js lib/internal/crypto/cipher.js lib/internal/crypto/diffiehellman.js lib/internal/crypto/hash.js lib/internal/crypto/keygen.js lib/internal/crypto/keys.js lib/internal/crypto/pbkdf2.js lib/internal/crypto/random.js lib/internal/crypto/scrypt.js lib/internal/crypto/sig.js lib/internal/crypto/util.js lib/internal/constants.js lib/internal/dgram.js lib/internal/dns/promises.js lib/internal/dns/utils.js lib/internal/dtrace.js lib/internal/encoding.js lib/internal/errors.js lib/internal/error-serdes.js lib/internal/fixed_queue.js lib/internal/freelist.js lib/internal/freeze_intrinsics.js lib/internal/fs/dir.js lib/internal/fs/promises.js lib/internal/fs/read_file_context.js lib/internal/fs/rimraf.js lib/internal/fs/streams.js lib/internal/fs/sync_write_stream.js lib/internal/fs/utils.js lib/internal/fs/watchers.js lib/internal/http.js lib/internal/heap_utils.js lib/internal/histogram.js lib/internal/idna.js lib/internal/inspector_async_hook.js lib/internal/js_stream_socket.js lib/internal/linkedlist.js lib/internal/main/check_syntax.js lib/internal/main/eval_string.js lib/internal/main/eval_stdin.js lib/internal/main/inspect.js lib/internal/main/print_help.js lib/internal/main/prof_process.js lib/internal/main/repl.js lib/internal/main/run_main_module.js lib/internal/main/run_third_party_main.js lib/internal/main/worker_thread.js lib/internal/modules/run_main.js lib/internal/modules/cjs/helpers.js lib/internal/modules/cjs/loader.js lib/internal/modules/esm/loader.js lib/internal/modules/esm/create_dynamic_module.js lib/internal/modules/esm/get_format.js lib/internal/modules/esm/get_source.js lib/internal/modules/esm/module_job.js lib/internal/modules/esm/module_map.js lib/internal/modules/esm/resolve.js lib/internal/modules/esm/transform_source.js lib/internal/modules/esm/translators.js lib/internal/net.js lib/internal/options.js lib/internal/policy/manifest.js lib/internal/policy/sri.js lib/internal/priority_queue.js lib/internal/process/esm_loader.js lib/internal/process/execution.js lib/internal/process/per_thread.js lib/internal/process/policy.js lib/internal/process/promises.js lib/internal/process/warning.js lib/internal/process/worker_thread_only.js lib/internal/process/report.js lib/internal/process/signal.js lib/internal/process/task_queues.js lib/internal/querystring.js lib/internal/readline/utils.js lib/internal/repl.js lib/internal/repl/await.js lib/internal/repl/history.js lib/internal/repl/utils.js lib/internal/socket_list.js lib/internal/source_map/prepare_stack_trace.js lib/internal/source_map/source_map.js lib/internal/source_map/source_map_cache.js lib/internal/test/binding.js lib/internal/timers.js lib/internal/tls.js lib/internal/trace_events_async_hooks.js lib/internal/tty.js lib/internal/url.js lib/internal/util.js lib/internal/util/comparisons.js lib/internal/util/debuglog.js lib/internal/util/inspect.js lib/internal/util/inspector.js lib/internal/util/types.js lib/internal/http2/core.js lib/internal/http2/compat.js lib/internal/http2/util.js lib/internal/v8_prof_polyfill.js lib/internal/v8_prof_processor.js lib/internal/validators.js lib/internal/stream_base_commons.js lib/internal/vm/module.js lib/internal/worker.js lib/internal/worker/io.js lib/internal/watchdog.js lib/internal/streams/lazy_transform.js lib/internal/streams/async_iterator.js lib/internal/streams/buffer_list.js lib/internal/streams/duplexpair.js lib/internal/streams/from.js lib/internal/streams/legacy.js lib/internal/streams/destroy.js lib/internal/streams/state.js lib/internal/streams/pipeline.js lib/internal/streams/end-of-stream.js deps/v8/tools/splaytree.js deps/v8/tools/codemap.js deps/v8/tools/consarray.js deps/v8/tools/csvparser.js deps/v8/tools/profile.js deps/v8/tools/profile_view.js deps/v8/tools/logreader.js deps/v8/tools/arguments.js deps/v8/tools/tickprocessor.js deps/v8/tools/SourceMap.js deps/v8/tools/tickprocessor-driver.js deps/node-inspect/lib/_inspect.js deps/node-inspect/lib/internal/inspect_client.js deps/node-inspect/lib/internal/inspect_repl.js deps/acorn/acorn/dist/acorn.js deps/acorn/acorn-walk/dist/walk.js deps/acorn-plugins/acorn-class-fields/index.js deps/acorn-plugins/acorn-numeric-separator/index.js deps/acorn-plugins/acorn-private-class-elements/index.js deps/acorn-plugins/acorn-private-methods/index.js deps/acorn-plugins/acorn-static-class-features/index.js config.gypi --target "${obj}/gen/node_javascript.cc"
  DEPENDS ${libnode__node_js2c__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
  COMMENT libnode__node_js2c
  VERBATIM
)
add_custom_target(libnode__node_js2c
  DEPENDS ${libnode__node_js2c__output}
  SOURCES ${libnode__node_js2c__input}
)
set(libnode__convert_node_protocol_to_json__input "${CMAKE_CURRENT_LIST_DIR}/src/inspector/node_protocol.pdl")
set(libnode__convert_node_protocol_to_json__output "${obj}/gen/src/node_protocol.json")
add_custom_command(OUTPUT ${libnode__convert_node_protocol_to_json__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen/src
  COMMAND python tools/inspector_protocol/convert_protocol_to_json.py src/inspector/node_protocol.pdl "${obj}/gen/src/node_protocol.json"
  DEPENDS ${libnode__convert_node_protocol_to_json__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
  COMMENT libnode__convert_node_protocol_to_json
  VERBATIM
)
add_custom_target(libnode__convert_node_protocol_to_json
  DEPENDS ${libnode__convert_node_protocol_to_json__output}
  SOURCES ${libnode__convert_node_protocol_to_json__input}
)
list(APPEND libnode__node_protocol_generated_sources__input
  "${CMAKE_CURRENT_LIST_DIR}/src/inspector/node_protocol_config.json"
  "${obj}/gen/src/node_protocol.json"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/Allocator_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/Array_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/base_string_adapter_cc.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/base_string_adapter_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/DispatcherBase_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/DispatcherBase_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/encoding_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/encoding_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/ErrorSupport_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/ErrorSupport_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/Forward_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/FrontendChannel_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/Maybe_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/Object_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/Object_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/Parser_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/Parser_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/Protocol_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/ValueConversions_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/Values_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/lib/Values_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/templates/Exported_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/templates/Imported_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/templates/TypeBuilder_cpp.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/templates/TypeBuilder_h.template"
  "${CMAKE_CURRENT_LIST_DIR}/tools/inspector_protocol/code_generator.py")
list(APPEND libnode__node_protocol_generated_sources__output
  "${obj}/gen/src/node/inspector/protocol/Forward.h"
  "${obj}/gen/src/node/inspector/protocol/Protocol.cpp"
  "${obj}/gen/src/node/inspector/protocol/Protocol.h"
  "${obj}/gen/src/node/inspector/protocol/NodeWorker.cpp"
  "${obj}/gen/src/node/inspector/protocol/NodeWorker.h"
  "${obj}/gen/src/node/inspector/protocol/NodeTracing.cpp"
  "${obj}/gen/src/node/inspector/protocol/NodeTracing.h"
  "${obj}/gen/src/node/inspector/protocol/NodeRuntime.cpp"
  "${obj}/gen/src/node/inspector/protocol/NodeRuntime.h")
add_custom_command(OUTPUT ${libnode__node_protocol_generated_sources__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen/src/node/inspector/protocol
  COMMAND python tools/inspector_protocol/code_generator.py --jinja_dir tools/inspector_protocol --output_base "${obj}/gen/src/" --config src/inspector/node_protocol_config.json
  DEPENDS ${libnode__node_protocol_generated_sources__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
  COMMENT Generating node protocol sources from protocol json
  VERBATIM
)
add_custom_target(libnode__node_protocol_generated_sources
  DEPENDS ${libnode__node_protocol_generated_sources__output}
  SOURCES ${libnode__node_protocol_generated_sources__input}
)
list(APPEND libnode__concatenate_protocols__input
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include/js_protocol.pdl"
  "${obj}/gen/src/node_protocol.json")
set(libnode__concatenate_protocols__output "${obj}/gen/concatenated_protocol.json")
add_custom_command(OUTPUT ${libnode__concatenate_protocols__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen
  COMMAND python tools/inspector_protocol/concatenate_protocols.py deps/v8/include/js_protocol.pdl "${obj}/gen/src/node_protocol.json" "${obj}/gen/concatenated_protocol.json"
  DEPENDS ${libnode__concatenate_protocols__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
  COMMENT libnode__concatenate_protocols
  VERBATIM
)
add_custom_target(libnode__concatenate_protocols
  DEPENDS ${libnode__concatenate_protocols__output}
  SOURCES ${libnode__concatenate_protocols__input}
)
set(libnode__v8_inspector_compress_protocol_json__input "${obj}/gen/concatenated_protocol.json")
set(libnode__v8_inspector_compress_protocol_json__output "${obj}/gen/v8_inspector_protocol_json.h")
add_custom_command(OUTPUT ${libnode__v8_inspector_compress_protocol_json__output}
  COMMAND ${CMAKE_COMMAND} -E make_directory ${obj}/gen
  COMMAND python tools/compress_json.py "${obj}/gen/concatenated_protocol.json" "${obj}/gen/v8_inspector_protocol_json.h"
  DEPENDS ${libnode__v8_inspector_compress_protocol_json__input}
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
  COMMENT libnode__v8_inspector_compress_protocol_json
  VERBATIM
)
add_custom_target(libnode__v8_inspector_compress_protocol_json
  DEPENDS ${libnode__v8_inspector_compress_protocol_json__output}
  SOURCES ${libnode__v8_inspector_compress_protocol_json__input}
)
list(APPEND libnode__cxx_srcs
  "src/api/async_resource.cc"
  "src/api/callback.cc"
  "src/api/encoding.cc"
  "src/api/environment.cc"
  "src/api/exceptions.cc"
  "src/api/hooks.cc"
  "src/api/utils.cc"
  "src/async_wrap.cc"
  "src/cares_wrap.cc"
  "src/connect_wrap.cc"
  "src/connection_wrap.cc"
  "src/debug_utils.cc"
  "src/env.cc"
  "src/fs_event_wrap.cc"
  "src/handle_wrap.cc"
  "src/heap_utils.cc"
  "src/histogram.cc"
  "src/js_native_api_v8.cc"
  "src/js_stream.cc"
  "src/module_wrap.cc"
  "src/node.cc"
  "src/node_api.cc"
  "src/node_binding.cc"
  "src/node_buffer.cc"
  "src/node_config.cc"
  "src/node_constants.cc"
  "src/node_contextify.cc"
  "src/node_credentials.cc"
  "src/node_dir.cc"
  "src/node_domain.cc"
  "src/node_env_var.cc"
  "src/node_errors.cc"
  "src/node_file.cc"
  "src/node_http_parser.cc"
  "src/node_http2.cc"
  "src/node_i18n.cc"
  "src/node_main_instance.cc"
  "src/node_messaging.cc"
  "src/node_metadata.cc"
  "src/node_native_module.cc"
  "src/node_native_module_env.cc"
  "src/node_options.cc"
  "src/node_os.cc"
  "src/node_perf.cc"
  "src/node_platform.cc"
  "src/node_postmortem_metadata.cc"
  "src/node_process_events.cc"
  "src/node_process_methods.cc"
  "src/node_process_object.cc"
  "src/node_serdes.cc"
  "src/node_sockaddr.cc"
  "src/node_stat_watcher.cc"
  "src/node_symbols.cc"
  "src/node_task_queue.cc"
  "src/node_trace_events.cc"
  "src/node_types.cc"
  "src/node_url.cc"
  "src/node_util.cc"
  "src/node_v8.cc"
  "src/node_wasi.cc"
  "src/node_watchdog.cc"
  "src/node_worker.cc"
  "src/node_zlib.cc"
  "src/pipe_wrap.cc"
  "src/process_wrap.cc"
  "src/signal_wrap.cc"
  "src/spawn_sync.cc"
  "src/stream_base.cc"
  "src/stream_pipe.cc"
  "src/stream_wrap.cc"
  "src/string_bytes.cc"
  "src/string_decoder.cc"
  "src/tcp_wrap.cc"
  "src/timers.cc"
  "src/tracing/agent.cc"
  "src/tracing/node_trace_buffer.cc"
  "src/tracing/node_trace_writer.cc"
  "src/tracing/trace_event.cc"
  "src/tracing/traced_value.cc"
  "src/tty_wrap.cc"
  "src/udp_wrap.cc"
  "src/util.cc"
  "src/uv.cc"
  "src/c_node.cc"
  "src/large_pages/node_large_page.cc"
  "src/node_snapshot_stub.cc"
  "src/node_code_cache_stub.cc"
  "src/inspector_agent.cc"
  "src/inspector_io.cc"
  "src/inspector_profiler.cc"
  "src/inspector_js_api.cc"
  "src/inspector_socket.cc"
  "src/inspector_socket_server.cc"
  "src/inspector/main_thread_interface.cc"
  "src/inspector/node_string.cc"
  "src/inspector/runtime_agent.cc"
  "src/inspector/tracing_agent.cc"
  "src/inspector/worker_agent.cc"
  "src/inspector/worker_inspector.cc"
  "src/node_dtrace.cc"
  "src/node_crypto.cc"
  "src/node_crypto_common.cc"
  "src/node_crypto_bio.cc"
  "src/node_crypto_clienthello.cc"
  "src/tls_wrap.cc"
  "src/node_report.cc"
  "src/node_report_module.cc"
  "src/node_report_utils.cc"
  "${obj}/gen/node_javascript.cc"
  "${obj}/gen/src/node/inspector/protocol/Protocol.cpp"
  "${obj}/gen/src/node/inspector/protocol/NodeWorker.cpp"
  "${obj}/gen/src/node/inspector/protocol/NodeTracing.cpp"
  "${obj}/gen/src/node/inspector/protocol/NodeRuntime.cpp")
list(APPEND libnode__other_srcs
  "src/js_native_api.h"
  "src/js_native_api_types.h"
  "src/js_native_api_v8.h"
  "src/js_native_api_v8_internals.h"
  "src/aliased_buffer.h"
  "src/async_wrap.h"
  "src/async_wrap-inl.h"
  "src/base_object.h"
  "src/base_object-inl.h"
  "src/base64.h"
  "src/connect_wrap.h"
  "src/connection_wrap.h"
  "src/debug_utils.h"
  "src/debug_utils-inl.h"
  "src/env.h"
  "src/env-inl.h"
  "src/handle_wrap.h"
  "src/histogram.h"
  "src/histogram-inl.h"
  "src/js_stream.h"
  "src/large_pages/node_large_page.h"
  "src/memory_tracker.h"
  "src/memory_tracker-inl.h"
  "src/module_wrap.h"
  "src/node.h"
  "src/node_api.h"
  "src/node_api_types.h"
  "src/node_binding.h"
  "src/node_buffer.h"
  "src/node_constants.h"
  "src/node_context_data.h"
  "src/node_contextify.h"
  "src/node_dir.h"
  "src/node_errors.h"
  "src/node_file.h"
  "src/node_file-inl.h"
  "src/node_http_common.h"
  "src/node_http_common-inl.h"
  "src/node_http2.h"
  "src/node_http2_state.h"
  "src/node_i18n.h"
  "src/node_internals.h"
  "src/node_main_instance.h"
  "src/node_mem.h"
  "src/node_mem-inl.h"
  "src/node_messaging.h"
  "src/node_metadata.h"
  "src/node_mutex.h"
  "src/node_native_module.h"
  "src/node_native_module_env.h"
  "src/node_object_wrap.h"
  "src/node_options.h"
  "src/node_options-inl.h"
  "src/node_perf.h"
  "src/node_perf_common.h"
  "src/node_platform.h"
  "src/node_process.h"
  "src/node_revert.h"
  "src/node_root_certs.h"
  "src/node_sockaddr.h"
  "src/node_sockaddr-inl.h"
  "src/node_stat_watcher.h"
  "src/node_union_bytes.h"
  "src/node_url.h"
  "src/node_version.h"
  "src/node_v8_platform-inl.h"
  "src/node_wasi.h"
  "src/node_watchdog.h"
  "src/node_worker.h"
  "src/pipe_wrap.h"
  "src/req_wrap.h"
  "src/req_wrap-inl.h"
  "src/spawn_sync.h"
  "src/stream_base.h"
  "src/stream_base-inl.h"
  "src/stream_pipe.h"
  "src/stream_wrap.h"
  "src/string_bytes.h"
  "src/string_decoder.h"
  "src/string_decoder-inl.h"
  "src/string_search.h"
  "src/tcp_wrap.h"
  "src/tracing/agent.h"
  "src/tracing/node_trace_buffer.h"
  "src/tracing/node_trace_writer.h"
  "src/tracing/trace_event.h"
  "src/tracing/trace_event_common.h"
  "src/tracing/traced_value.h"
  "src/tty_wrap.h"
  "src/udp_wrap.h"
  "src/util.h"
  "src/util-inl.h"
  "src/c_node.h"
  "deps/v8/include/v8.h"
  "lib/internal/bootstrap/environment.js"
  "lib/internal/bootstrap/loaders.js"
  "lib/internal/bootstrap/node.js"
  "lib/internal/bootstrap/pre_execution.js"
  "lib/internal/bootstrap/switches/does_own_process_state.js"
  "lib/internal/bootstrap/switches/does_not_own_process_state.js"
  "lib/internal/bootstrap/switches/is_main_thread.js"
  "lib/internal/bootstrap/switches/is_not_main_thread.js"
  "lib/internal/per_context/primordials.js"
  "lib/internal/per_context/domexception.js"
  "lib/internal/per_context/messageport.js"
  "lib/async_hooks.js"
  "lib/assert.js"
  "lib/buffer.js"
  "lib/child_process.js"
  "lib/console.js"
  "lib/constants.js"
  "lib/crypto.js"
  "lib/cluster.js"
  "lib/dgram.js"
  "lib/dns.js"
  "lib/domain.js"
  "lib/events.js"
  "lib/fs.js"
  "lib/http.js"
  "lib/http2.js"
  "lib/_http_agent.js"
  "lib/_http_client.js"
  "lib/_http_common.js"
  "lib/_http_incoming.js"
  "lib/_http_outgoing.js"
  "lib/_http_server.js"
  "lib/https.js"
  "lib/inspector.js"
  "lib/module.js"
  "lib/net.js"
  "lib/os.js"
  "lib/path.js"
  "lib/perf_hooks.js"
  "lib/process.js"
  "lib/punycode.js"
  "lib/querystring.js"
  "lib/readline.js"
  "lib/repl.js"
  "lib/stream.js"
  "lib/_stream_readable.js"
  "lib/_stream_writable.js"
  "lib/_stream_duplex.js"
  "lib/_stream_transform.js"
  "lib/_stream_passthrough.js"
  "lib/_stream_wrap.js"
  "lib/string_decoder.js"
  "lib/sys.js"
  "lib/timers.js"
  "lib/tls.js"
  "lib/_tls_common.js"
  "lib/_tls_wrap.js"
  "lib/trace_events.js"
  "lib/tty.js"
  "lib/url.js"
  "lib/util.js"
  "lib/v8.js"
  "lib/vm.js"
  "lib/wasi.js"
  "lib/worker_threads.js"
  "lib/zlib.js"
  "lib/internal/assert.js"
  "lib/internal/assert/assertion_error.js"
  "lib/internal/async_hooks.js"
  "lib/internal/buffer.js"
  "lib/internal/cli_table.js"
  "lib/internal/child_process.js"
  "lib/internal/child_process/serialization.js"
  "lib/internal/cluster/child.js"
  "lib/internal/cluster/master.js"
  "lib/internal/cluster/round_robin_handle.js"
  "lib/internal/cluster/shared_handle.js"
  "lib/internal/cluster/utils.js"
  "lib/internal/cluster/worker.js"
  "lib/internal/console/constructor.js"
  "lib/internal/console/global.js"
  "lib/internal/crypto/certificate.js"
  "lib/internal/crypto/cipher.js"
  "lib/internal/crypto/diffiehellman.js"
  "lib/internal/crypto/hash.js"
  "lib/internal/crypto/keygen.js"
  "lib/internal/crypto/keys.js"
  "lib/internal/crypto/pbkdf2.js"
  "lib/internal/crypto/random.js"
  "lib/internal/crypto/scrypt.js"
  "lib/internal/crypto/sig.js"
  "lib/internal/crypto/util.js"
  "lib/internal/constants.js"
  "lib/internal/dgram.js"
  "lib/internal/dns/promises.js"
  "lib/internal/dns/utils.js"
  "lib/internal/dtrace.js"
  "lib/internal/encoding.js"
  "lib/internal/errors.js"
  "lib/internal/error-serdes.js"
  "lib/internal/fixed_queue.js"
  "lib/internal/freelist.js"
  "lib/internal/freeze_intrinsics.js"
  "lib/internal/fs/dir.js"
  "lib/internal/fs/promises.js"
  "lib/internal/fs/read_file_context.js"
  "lib/internal/fs/rimraf.js"
  "lib/internal/fs/streams.js"
  "lib/internal/fs/sync_write_stream.js"
  "lib/internal/fs/utils.js"
  "lib/internal/fs/watchers.js"
  "lib/internal/http.js"
  "lib/internal/heap_utils.js"
  "lib/internal/histogram.js"
  "lib/internal/idna.js"
  "lib/internal/inspector_async_hook.js"
  "lib/internal/js_stream_socket.js"
  "lib/internal/linkedlist.js"
  "lib/internal/main/check_syntax.js"
  "lib/internal/main/eval_string.js"
  "lib/internal/main/eval_stdin.js"
  "lib/internal/main/inspect.js"
  "lib/internal/main/print_help.js"
  "lib/internal/main/prof_process.js"
  "lib/internal/main/repl.js"
  "lib/internal/main/run_main_module.js"
  "lib/internal/main/run_third_party_main.js"
  "lib/internal/main/worker_thread.js"
  "lib/internal/modules/run_main.js"
  "lib/internal/modules/cjs/helpers.js"
  "lib/internal/modules/cjs/loader.js"
  "lib/internal/modules/esm/loader.js"
  "lib/internal/modules/esm/create_dynamic_module.js"
  "lib/internal/modules/esm/get_format.js"
  "lib/internal/modules/esm/get_source.js"
  "lib/internal/modules/esm/module_job.js"
  "lib/internal/modules/esm/module_map.js"
  "lib/internal/modules/esm/resolve.js"
  "lib/internal/modules/esm/transform_source.js"
  "lib/internal/modules/esm/translators.js"
  "lib/internal/net.js"
  "lib/internal/options.js"
  "lib/internal/policy/manifest.js"
  "lib/internal/policy/sri.js"
  "lib/internal/priority_queue.js"
  "lib/internal/process/esm_loader.js"
  "lib/internal/process/execution.js"
  "lib/internal/process/per_thread.js"
  "lib/internal/process/policy.js"
  "lib/internal/process/promises.js"
  "lib/internal/process/warning.js"
  "lib/internal/process/worker_thread_only.js"
  "lib/internal/process/report.js"
  "lib/internal/process/signal.js"
  "lib/internal/process/task_queues.js"
  "lib/internal/querystring.js"
  "lib/internal/readline/utils.js"
  "lib/internal/repl.js"
  "lib/internal/repl/await.js"
  "lib/internal/repl/history.js"
  "lib/internal/repl/utils.js"
  "lib/internal/socket_list.js"
  "lib/internal/source_map/prepare_stack_trace.js"
  "lib/internal/source_map/source_map.js"
  "lib/internal/source_map/source_map_cache.js"
  "lib/internal/test/binding.js"
  "lib/internal/timers.js"
  "lib/internal/tls.js"
  "lib/internal/trace_events_async_hooks.js"
  "lib/internal/tty.js"
  "lib/internal/url.js"
  "lib/internal/util.js"
  "lib/internal/util/comparisons.js"
  "lib/internal/util/debuglog.js"
  "lib/internal/util/inspect.js"
  "lib/internal/util/inspector.js"
  "lib/internal/util/types.js"
  "lib/internal/http2/core.js"
  "lib/internal/http2/compat.js"
  "lib/internal/http2/util.js"
  "lib/internal/v8_prof_polyfill.js"
  "lib/internal/v8_prof_processor.js"
  "lib/internal/validators.js"
  "lib/internal/stream_base_commons.js"
  "lib/internal/vm/module.js"
  "lib/internal/worker.js"
  "lib/internal/worker/io.js"
  "lib/internal/watchdog.js"
  "lib/internal/streams/lazy_transform.js"
  "lib/internal/streams/async_iterator.js"
  "lib/internal/streams/buffer_list.js"
  "lib/internal/streams/duplexpair.js"
  "lib/internal/streams/from.js"
  "lib/internal/streams/legacy.js"
  "lib/internal/streams/destroy.js"
  "lib/internal/streams/state.js"
  "lib/internal/streams/pipeline.js"
  "lib/internal/streams/end-of-stream.js"
  "deps/v8/tools/splaytree.js"
  "deps/v8/tools/codemap.js"
  "deps/v8/tools/consarray.js"
  "deps/v8/tools/csvparser.js"
  "deps/v8/tools/profile.js"
  "deps/v8/tools/profile_view.js"
  "deps/v8/tools/logreader.js"
  "deps/v8/tools/arguments.js"
  "deps/v8/tools/tickprocessor.js"
  "deps/v8/tools/SourceMap.js"
  "deps/v8/tools/tickprocessor-driver.js"
  "deps/node-inspect/lib/_inspect.js"
  "deps/node-inspect/lib/internal/inspect_client.js"
  "deps/node-inspect/lib/internal/inspect_repl.js"
  "deps/acorn/acorn/dist/acorn.js"
  "deps/acorn/acorn-walk/dist/walk.js"
  "deps/acorn-plugins/acorn-class-fields/index.js"
  "deps/acorn-plugins/acorn-numeric-separator/index.js"
  "deps/acorn-plugins/acorn-private-class-elements/index.js"
  "deps/acorn-plugins/acorn-private-methods/index.js"
  "deps/acorn-plugins/acorn-static-class-features/index.js"
  "common.gypi"
  "src/inspector_agent.h"
  "src/inspector_io.h"
  "src/inspector_profiler.h"
  "src/inspector_socket.h"
  "src/inspector_socket_server.h"
  "src/inspector/main_thread_interface.h"
  "src/inspector/node_string.h"
  "src/inspector/runtime_agent.h"
  "src/inspector/tracing_agent.h"
  "src/inspector/worker_agent.h"
  "src/inspector/worker_inspector.h"
  "src/node_dtrace.h"
  "src/node_crypto.h"
  "src/node_crypto_common.h"
  "src/node_crypto_bio.h"
  "src/node_crypto_clienthello.h"
  "src/node_crypto_clienthello-inl.h"
  "src/node_crypto_groups.h"
  "src/tls_wrap.h"
  "${obj}/gen/src/node/inspector/protocol/Forward.h"
  "${obj}/gen/src/node/inspector/protocol/Protocol.h"
  "${obj}/gen/src/node/inspector/protocol/NodeWorker.h"
  "${obj}/gen/src/node/inspector/protocol/NodeTracing.h"
  "${obj}/gen/src/node/inspector/protocol/NodeRuntime.h"
  "${obj}/gen/v8_inspector_protocol_json.h")
add_library(libnode SHARED ${libnode__cxx_srcs} ${libnode__other_srcs})
set_target_properties(libnode PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(libnode__node_js2c PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(libnode__convert_node_protocol_to_json PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(libnode__node_protocol_generated_sources PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(libnode__concatenate_protocols PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(libnode__v8_inspector_compress_protocol_json PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${libnode__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(libnode PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${builddir}/lib.${TOOLSET}")
set_target_properties(libnode PROPERTIES PREFIX "lib")
set_target_properties(libnode PROPERTIES LIBRARY_OUTPUT_NAME "node")
set_target_properties(libnode PROPERTIES SUFFIX ".79.dylib")
set_source_files_properties(${builddir}/lib.${TOOLSET}/libnode.79.dylib PROPERTIES GENERATED "TRUE")
list(APPEND libnode__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/src"
  "${obj}/gen"
  "${obj}/gen/include"
  "${obj}/gen/src"
  "${CMAKE_CURRENT_LIST_DIR}/deps/histogram/src"
  "${CMAKE_CURRENT_LIST_DIR}/deps/uvwasi/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common"
  "${CMAKE_CURRENT_LIST_DIR}/deps/zlib"
  "${CMAKE_CURRENT_LIST_DIR}/deps/llhttp/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/cares/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/uv/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/nghttp2/lib/includes"
  "${CMAKE_CURRENT_LIST_DIR}/deps/brotli/c/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/include")
set_property(TARGET libnode APPEND PROPERTY INCLUDE_DIRECTORIES ${libnode__include_dirs})
set_target_properties(libnode PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;NODE_ARCH=\"x64\";NODE_WANT_INTERNALS=1;V8_DEPRECATION_WARNINGS=1;NODE_OPENSSL_SYSTEM_CERT_PATH=\"\";HAVE_INSPECTOR=1;HAVE_DTRACE=1;NODE_REPORT;NODE_SHARED_MODE;__POSIX__;NODE_USE_V8_PLATFORM=1;NODE_HAVE_I18N_SUPPORT=1;NODE_PLATFORM=\"darwin\";HAVE_OPENSSL=1;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;_LARGEFILE_SOURCE;_FILE_OFFSET_BITS=64;NGHTTP2_STATICLIB;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(libnode PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -Werror=undefined-inline -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(libnode PROPERTIES LINK_FLAGS "-pthread ")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-force_load,${builddir}/libzlib.a -Wl,-force_load,${builddir}/libuv.a -Wl,-force_load,${builddir}/libv8_snapshot.a -Wl,-force_load,${builddir}/libopenssl.a -Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_LD_DYLIB_INSTALL_NAME "@rpath/libnode.79.dylib")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(libnode PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter -Werror=undefined-inline -Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(libnode__node_js2c
  histogram
  uvwasi
  v8_libplatform
  icui18n
  zlib
  llhttp
  cares
  libuv
  nghttp2
  brotli
  openssl
  v8_base_without_compiler
  icuucx
  icudata
  v8_libbase
  v8_libsampler
  v8_compiler
  v8_snapshot
  v8_initializers
  node_dtrace_header
  specialize_node_d
  v8_maybe_snapshot
  icuuc
  openssl-cli
  v8_base
  torque_generated_definitions
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  icu_implementation
  icu_uconfig
  icu_uconfig_target
  icu_implementation_host
  v8_headers
  v8_version
  v8_shared_internal_headers
  run_gen-regexp-special-case
  postmortem-metadata
  v8_compiler_for_mksnapshot
  torque_generated_initializers
)
add_dependencies(libnode__convert_node_protocol_to_json
  histogram
  uvwasi
  v8_libplatform
  icui18n
  zlib
  llhttp
  cares
  libuv
  nghttp2
  brotli
  openssl
  v8_base_without_compiler
  icuucx
  icudata
  v8_libbase
  v8_libsampler
  v8_compiler
  v8_snapshot
  v8_initializers
  node_dtrace_header
  specialize_node_d
  v8_maybe_snapshot
  icuuc
  openssl-cli
  v8_base
  torque_generated_definitions
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  icu_implementation
  icu_uconfig
  icu_uconfig_target
  icu_implementation_host
  v8_headers
  v8_version
  v8_shared_internal_headers
  run_gen-regexp-special-case
  postmortem-metadata
  v8_compiler_for_mksnapshot
  torque_generated_initializers
)
add_dependencies(libnode__node_protocol_generated_sources
  histogram
  uvwasi
  v8_libplatform
  icui18n
  zlib
  llhttp
  cares
  libuv
  nghttp2
  brotli
  openssl
  v8_base_without_compiler
  icuucx
  icudata
  v8_libbase
  v8_libsampler
  v8_compiler
  v8_snapshot
  v8_initializers
  node_dtrace_header
  specialize_node_d
  v8_maybe_snapshot
  icuuc
  openssl-cli
  v8_base
  torque_generated_definitions
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  icu_implementation
  icu_uconfig
  icu_uconfig_target
  icu_implementation_host
  v8_headers
  v8_version
  v8_shared_internal_headers
  run_gen-regexp-special-case
  postmortem-metadata
  v8_compiler_for_mksnapshot
  torque_generated_initializers
)
add_dependencies(libnode__concatenate_protocols
  histogram
  uvwasi
  v8_libplatform
  icui18n
  zlib
  llhttp
  cares
  libuv
  nghttp2
  brotli
  openssl
  v8_base_without_compiler
  icuucx
  icudata
  v8_libbase
  v8_libsampler
  v8_compiler
  v8_snapshot
  v8_initializers
  node_dtrace_header
  specialize_node_d
  v8_maybe_snapshot
  icuuc
  openssl-cli
  v8_base
  torque_generated_definitions
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  icu_implementation
  icu_uconfig
  icu_uconfig_target
  icu_implementation_host
  v8_headers
  v8_version
  v8_shared_internal_headers
  run_gen-regexp-special-case
  postmortem-metadata
  v8_compiler_for_mksnapshot
  torque_generated_initializers
)
add_dependencies(libnode__v8_inspector_compress_protocol_json
  histogram
  uvwasi
  v8_libplatform
  icui18n
  zlib
  llhttp
  cares
  libuv
  nghttp2
  brotli
  openssl
  v8_base_without_compiler
  icuucx
  icudata
  v8_libbase
  v8_libsampler
  v8_compiler
  v8_snapshot
  v8_initializers
  node_dtrace_header
  specialize_node_d
  v8_maybe_snapshot
  icuuc
  openssl-cli
  v8_base
  torque_generated_definitions
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  icu_implementation
  icu_uconfig
  icu_uconfig_target
  icu_implementation_host
  v8_headers
  v8_version
  v8_shared_internal_headers
  run_gen-regexp-special-case
  postmortem-metadata
  v8_compiler_for_mksnapshot
  torque_generated_initializers
)
add_dependencies(libnode
  node_dtrace_header
  specialize_node_d
  v8_maybe_snapshot
  icuuc
  openssl-cli
  v8_base
  torque_generated_definitions
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  icu_implementation
  icu_uconfig
  icu_uconfig_target
  icu_implementation_host
  v8_headers
  v8_version
  v8_shared_internal_headers
  run_gen-regexp-special-case
  postmortem-metadata
  v8_compiler_for_mksnapshot
  torque_generated_initializers
  libnode__node_js2c
  libnode__convert_node_protocol_to_json
  libnode__node_protocol_generated_sources
  libnode__concatenate_protocols
  libnode__v8_inspector_compress_protocol_json
)
target_link_libraries(libnode
  histogram
  uvwasi
  v8_libplatform
  icui18n
  zlib
  llhttp
  cares
  libuv
  nghttp2
  brotli
  openssl
  v8_base_without_compiler
  icuucx
  icudata
  v8_libbase
  v8_libsampler
  v8_compiler
  v8_snapshot
  v8_initializers
  "-framework CoreFoundation"
  "-lm"
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/node.gyp:node_mksnapshot#target
set(TARGET "node_mksnapshot")
set(TOOLSET "target")
list(APPEND node_mksnapshot__cxx_srcs
  "src/node_snapshot_stub.cc"
  "src/node_code_cache_stub.cc"
  "tools/snapshot/node_mksnapshot.cc"
  "tools/snapshot/snapshot_builder.cc")
set(node_mksnapshot__other_srcs "tools/snapshot/snapshot_builder.h")
add_executable(node_mksnapshot ${node_mksnapshot__cxx_srcs} ${node_mksnapshot__other_srcs})
set_target_properties(node_mksnapshot PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${node_mksnapshot__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(node_mksnapshot PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(node_mksnapshot PROPERTIES PREFIX "")
set_target_properties(node_mksnapshot PROPERTIES RUNTIME_OUTPUT_NAME "node_mksnapshot")
set_target_properties(node_mksnapshot PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/node_mksnapshot PROPERTIES GENERATED "TRUE")
list(APPEND node_mksnapshot__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/src"
  "${CMAKE_CURRENT_LIST_DIR}/tools/msvs/genfiles"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/cares/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/uv/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/uvwasi/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/histogram/src"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common"
  "${CMAKE_CURRENT_LIST_DIR}/deps/zlib"
  "${CMAKE_CURRENT_LIST_DIR}/deps/llhttp/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/nghttp2/lib/includes"
  "${CMAKE_CURRENT_LIST_DIR}/deps/brotli/c/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/include")
set_property(TARGET node_mksnapshot APPEND PROPERTY INCLUDE_DIRECTORIES ${node_mksnapshot__include_dirs})
set_target_properties(node_mksnapshot PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;NODE_WANT_INTERNALS=1;HAVE_OPENSSL=1;HAVE_INSPECTOR=1;NODE_SHARED_MODE;__POSIX__;NODE_USE_V8_PLATFORM=1;NODE_HAVE_I18N_SUPPORT=1;NODE_PLATFORM=\"darwin\";UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;_LARGEFILE_SOURCE;_FILE_OFFSET_BITS=64;NGHTTP2_STATICLIB;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(node_mksnapshot PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -Werror=undefined-inline -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(node_mksnapshot PROPERTIES LINK_FLAGS "-pthread ")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(node_mksnapshot PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter -Werror=undefined-inline -Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(node_mksnapshot
  v8_maybe_snapshot
  icuuc
  openssl-cli
  v8_base
  torque_generated_definitions
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  icu_implementation
  icu_uconfig
  icu_uconfig_target
  icu_implementation_host
  v8_headers
  v8_version
  v8_shared_internal_headers
  run_gen-regexp-special-case
  postmortem-metadata
  v8_compiler_for_mksnapshot
  torque_generated_initializers
)
target_link_libraries(node_mksnapshot
  histogram
  uvwasi
  v8_libplatform
  icui18n
  zlib
  llhttp
  cares
  libuv
  nghttp2
  brotli
  openssl
  v8_base_without_compiler
  icuucx
  icudata
  v8_libbase
  v8_libsampler
  v8_compiler
  v8_snapshot
  v8_initializers
  libnode
  "-framework CoreFoundation"
  "-lm"
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/node.gyp:node#target
set(TARGET "node")
set(TOOLSET "target")
list(APPEND node__cxx_srcs
  "src/node_main.cc"
  "src/node_code_cache_stub.cc"
  "src/node_snapshot_stub.cc")
add_executable(node ${node__cxx_srcs})
set_target_properties(node PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_target_properties(node PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(node PROPERTIES PREFIX "")
set_target_properties(node PROPERTIES RUNTIME_OUTPUT_NAME "node")
set_target_properties(node PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/node PROPERTIES GENERATED "TRUE")
list(APPEND node__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/src"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/histogram/src"
  "${CMAKE_CURRENT_LIST_DIR}/deps/uvwasi/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common"
  "${CMAKE_CURRENT_LIST_DIR}/deps/zlib"
  "${CMAKE_CURRENT_LIST_DIR}/deps/llhttp/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/cares/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/uv/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/nghttp2/lib/includes"
  "${CMAKE_CURRENT_LIST_DIR}/deps/brotli/c/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/include")
set_property(TARGET node APPEND PROPERTY INCLUDE_DIRECTORIES ${node__include_dirs})
set_target_properties(node PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;NODE_WANT_INTERNALS=1;NODE_REPORT;NODE_ARCH=\"x64\";NODE_SHARED_MODE;__POSIX__;NODE_USE_V8_PLATFORM=1;NODE_HAVE_I18N_SUPPORT=1;NODE_PLATFORM=\"darwin\";HAVE_OPENSSL=1;UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;_LARGEFILE_SOURCE;_FILE_OFFSET_BITS=64;NGHTTP2_STATICLIB;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(node PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -Werror=undefined-inline -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(node PROPERTIES LINK_FLAGS "-pthread ")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-rpath,@loader_path -Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(node PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter -Werror=undefined-inline -Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(node
  v8_maybe_snapshot
  icuuc
  openssl-cli
  v8_base
  torque_generated_definitions
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  icu_implementation
  icu_uconfig
  icu_uconfig_target
  icu_implementation_host
  v8_headers
  v8_version
  v8_shared_internal_headers
  run_gen-regexp-special-case
  postmortem-metadata
  v8_compiler_for_mksnapshot
  torque_generated_initializers
)
target_link_libraries(node
  histogram
  uvwasi
  v8_libplatform
  icui18n
  zlib
  llhttp
  cares
  libuv
  nghttp2
  brotli
  openssl
  v8_base_without_compiler
  icuucx
  icudata
  v8_libbase
  v8_libsampler
  v8_compiler
  v8_snapshot
  v8_initializers
  libnode
  "-framework CoreFoundation"
  "-lm"
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/node.gyp:mkcodecache#target
set(TARGET "mkcodecache")
set(TOOLSET "target")
list(APPEND mkcodecache__cxx_srcs
  "src/node_snapshot_stub.cc"
  "src/node_code_cache_stub.cc"
  "tools/code_cache/mkcodecache.cc"
  "tools/code_cache/cache_builder.cc")
set(mkcodecache__other_srcs "tools/code_cache/cache_builder.h")
add_executable(mkcodecache ${mkcodecache__cxx_srcs} ${mkcodecache__other_srcs})
set_target_properties(mkcodecache PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${mkcodecache__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(mkcodecache PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(mkcodecache PROPERTIES PREFIX "")
set_target_properties(mkcodecache PROPERTIES RUNTIME_OUTPUT_NAME "mkcodecache")
set_target_properties(mkcodecache PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/mkcodecache PROPERTIES GENERATED "TRUE")
list(APPEND mkcodecache__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/src"
  "${CMAKE_CURRENT_LIST_DIR}/tools/msvs/genfiles"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/cares/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/uv/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/uvwasi/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/histogram/src"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common"
  "${CMAKE_CURRENT_LIST_DIR}/deps/zlib"
  "${CMAKE_CURRENT_LIST_DIR}/deps/llhttp/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/nghttp2/lib/includes"
  "${CMAKE_CURRENT_LIST_DIR}/deps/brotli/c/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/include")
set_property(TARGET mkcodecache APPEND PROPERTY INCLUDE_DIRECTORIES ${mkcodecache__include_dirs})
set_target_properties(mkcodecache PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;NODE_WANT_INTERNALS=1;HAVE_OPENSSL=1;HAVE_INSPECTOR=1;NODE_SHARED_MODE;__POSIX__;NODE_USE_V8_PLATFORM=1;NODE_HAVE_I18N_SUPPORT=1;NODE_PLATFORM=\"darwin\";UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;_LARGEFILE_SOURCE;_FILE_OFFSET_BITS=64;NGHTTP2_STATICLIB;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(mkcodecache PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -Werror=undefined-inline -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(mkcodecache PROPERTIES LINK_FLAGS "-pthread ")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(mkcodecache PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter -Werror=undefined-inline -Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(mkcodecache
  v8_maybe_snapshot
  icuuc
  openssl-cli
  v8_base
  torque_generated_definitions
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  icu_implementation
  icu_uconfig
  icu_uconfig_target
  icu_implementation_host
  v8_headers
  v8_version
  v8_shared_internal_headers
  run_gen-regexp-special-case
  postmortem-metadata
  v8_compiler_for_mksnapshot
  torque_generated_initializers
)
target_link_libraries(mkcodecache
  histogram
  uvwasi
  v8_libplatform
  icui18n
  zlib
  llhttp
  cares
  libuv
  nghttp2
  brotli
  openssl
  v8_base_without_compiler
  icuucx
  icudata
  v8_libbase
  v8_libsampler
  v8_compiler
  v8_snapshot
  v8_initializers
  libnode
  "-framework CoreFoundation"
  "-lm"
)
unset(TOOLSET)
unset(TARGET)

#/Volumes/Data/Develop/JavaScript/cnode/node/node.gyp:cctest#target
set(TARGET "cctest")
set(TOOLSET "target")
list(APPEND cctest__cxx_srcs
  "src/node_snapshot_stub.cc"
  "src/node_code_cache_stub.cc"
  "test/cctest/gtest/gtest-all.cc"
  "test/cctest/gtest/gtest_main.cc"
  "test/cctest/node_test_fixture.cc"
  "test/cctest/test_aliased_buffer.cc"
  "test/cctest/test_base64.cc"
  "test/cctest/test_base_object_ptr.cc"
  "test/cctest/test_node_postmortem_metadata.cc"
  "test/cctest/test_environment.cc"
  "test/cctest/test_linked_binding.cc"
  "test/cctest/test_per_process.cc"
  "test/cctest/test_platform.cc"
  "test/cctest/test_sockaddr.cc"
  "test/cctest/test_traced_value.cc"
  "test/cctest/test_util.cc"
  "test/cctest/test_url.cc"
  "test/cctest/test_inspector_socket.cc"
  "test/cctest/test_inspector_socket_server.cc"
  "test/cctest/test_report_util.cc")
set(cctest__other_srcs "test/cctest/node_test_fixture.h")
add_executable(cctest ${cctest__cxx_srcs} ${cctest__other_srcs})
set_target_properties(cctest PROPERTIES EXCLUDE_FROM_ALL "FALSE")
set_source_files_properties(${cctest__other_srcs} PROPERTIES HEADER_FILE_ONLY "TRUE")
set_target_properties(cctest PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${builddir}")
set_target_properties(cctest PROPERTIES PREFIX "")
set_target_properties(cctest PROPERTIES RUNTIME_OUTPUT_NAME "cctest")
set_target_properties(cctest PROPERTIES SUFFIX "")
set_source_files_properties(${builddir}/cctest PROPERTIES GENERATED "TRUE")
list(APPEND cctest__include_dirs
  "${CMAKE_CURRENT_LIST_DIR}/src"
  "${CMAKE_CURRENT_LIST_DIR}/tools/msvs/genfiles"
  "${CMAKE_CURRENT_LIST_DIR}/deps/v8/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/cares/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/uv/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/uvwasi/include"
  "${CMAKE_CURRENT_LIST_DIR}/test/cctest"
  "${CMAKE_CURRENT_LIST_DIR}/deps/histogram/src"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/i18n"
  "${CMAKE_CURRENT_LIST_DIR}/deps/icu-small/source/common"
  "${CMAKE_CURRENT_LIST_DIR}/deps/zlib"
  "${CMAKE_CURRENT_LIST_DIR}/deps/llhttp/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/nghttp2/lib/includes"
  "${CMAKE_CURRENT_LIST_DIR}/deps/brotli/c/include"
  "${CMAKE_CURRENT_LIST_DIR}/deps/openssl/openssl/include")
set_property(TARGET cctest APPEND PROPERTY INCLUDE_DIRECTORIES ${cctest__include_dirs})
set_target_properties(cctest PROPERTIES COMPILE_DEFINITIONS "V8_DEPRECATION_WARNINGS;V8_IMMINENT_DEPRECATION_WARNINGS;_DARWIN_USE_64_BIT_INODE=1;OPENSSL_THREADS;NODE_WANT_INTERNALS=1;HAVE_OPENSSL=1;HAVE_INSPECTOR=1;NODE_REPORT;NODE_ARCH=\"x64\";NODE_SHARED_MODE;__POSIX__;NODE_USE_V8_PLATFORM=1;NODE_HAVE_I18N_SUPPORT=1;NODE_PLATFORM=\"darwin\";UCONFIG_NO_SERVICE=1;U_ENABLE_DYLOAD=0;U_STATIC_IMPLEMENTATION=1;U_HAVE_STD_STRING=1;UCONFIG_NO_BREAK_ITERATION=0;_LARGEFILE_SOURCE;_FILE_OFFSET_BITS=64;NGHTTP2_STATICLIB;DEBUG;_DEBUG;V8_ENABLE_CHECKS;")
set_target_properties(cctest PROPERTIES COMPILE_FLAGS "-O0 -gdwarf-2 -mmacosx-version-min=10.10 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -Werror=undefined-inline -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++1y -stdlib=libc++ -fno-rtti -fno-exceptions -fno-strict-aliasing ")
set_target_properties(cctest PROPERTIES LINK_FLAGS "-pthread ")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_OTHER_CFLAGS "-fno-strict-aliasing ")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++1y")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_OTHER_LDFLAGS "-Wl,-rpath,@loader_path -Wl,-no_pie -Wl,-search_paths_first ")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_PREBINDING "NO")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_USE_HEADERMAP "NO")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_GCC_OPTIMIZATION_LEVEL "0")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_ARCHS "x86_64 ")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_EXCEPTIONS "NO")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET "10.10")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_CPP_RTTI "NO")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_ALWAYS_SEARCH_USER_PATHS "NO")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_GCC_DYNAMIC_NO_PIC "NO")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_GCC_ENABLE_PASCAL_STRINGS "NO")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_GCC_CW_ASM_SYNTAX "NO")
set_target_properties(cctest PROPERTIES XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wall -Wendif-labels -W -Wno-unused-parameter -Werror=undefined-inline -Wall -Wendif-labels -W -Wno-unused-parameter ")
add_dependencies(cctest
  node_dtrace_header
  node_dtrace_ustack
  node_dtrace_provider
  v8_maybe_snapshot
  icuuc
  openssl-cli
  v8_base
  torque_generated_definitions
  generate_bytecode_builtins_list
  run_torque
  v8_maybe_icu
  icu_implementation
  icu_uconfig
  icu_uconfig_target
  icu_implementation_host
  v8_headers
  v8_version
  v8_shared_internal_headers
  run_gen-regexp-special-case
  postmortem-metadata
  v8_compiler_for_mksnapshot
  torque_generated_initializers
)
target_link_libraries(cctest
  histogram
  uvwasi
  v8_libplatform
  icui18n
  zlib
  llhttp
  cares
  libuv
  nghttp2
  brotli
  openssl
  v8_base_without_compiler
  icuucx
  icudata
  v8_libbase
  v8_libsampler
  v8_compiler
  v8_snapshot
  v8_initializers
  libnode
  "-framework CoreFoundation"
  "-lm"
)
unset(TOOLSET)
unset(TARGET)
