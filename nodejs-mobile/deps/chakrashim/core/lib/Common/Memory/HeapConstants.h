//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------
#pragma once

class HeapConstants
{
public:
#if defined(TARGET_32)
    static const uint MaxSmallObjectSize = 512;
#else
    static const uint MaxSmallObjectSize = 768;
#endif

#if SMALLBLOCK_MEDIUM_ALLOC
    static const uint MaxMediumObjectSize = 8 * 1024; // Maximum medium object size is 8K
#else
    static const uint MaxMediumObjectSize = 9216;
#endif

#if defined(TARGET_32)
    // Only if a pointer points to first 8k region of a large object, it will set the mark bit in the chunk->MarkBits
    // If the pointer points outside of that region, no mark bit will be set
    static const uint MaxLargeObjectMarkOffset = 8 * 1024; 
#endif

    static const uint ObjectAllocationShift = 4;        // 16
    static const uint ObjectGranularity = 1 << ObjectAllocationShift;
    static const uint BucketCount = (MaxSmallObjectSize >> ObjectAllocationShift);

#ifdef BUCKETIZE_MEDIUM_ALLOCATIONS
    static const uint MediumObjectGranularity = 256;
    static const uint MediumBucketCount = (MaxMediumObjectSize - MaxSmallObjectSize) / MediumObjectGranularity;
#endif
};

///
/// BlockAttributes are used to determine the allocation characteristics of a heap block
/// These include the number of pages to allocate, the object capacity of the block
/// and the shape of the object's bit vectors
/// Since the constants here are used while generating the ValidPointerMap constants
/// please remember to regenerate the ValidPointersMap by first switching to a dynamic VPM
/// as controlled by the USE_STATIC_VPM in HeapInfo.h, and then running GenValidPointers.cmd
///
class SmallAllocationBlockAttributes
{
public:
    static const size_t MinObjectSize = HeapConstants::ObjectGranularity;

    static const size_t PageCount = 1;
    static const size_t BitVectorCount = ((PageCount * AutoSystemInfo::PageSize) / HeapConstants::ObjectGranularity);
    static const ushort MaxAddressBit = BitVectorCount - 1;
    static const uint   BucketCount = HeapConstants::BucketCount;
    static const size_t BucketGranularity = HeapConstants::ObjectGranularity;
    static const uint   MaxObjectSize = HeapConstants::MaxSmallObjectSize;
    static const uint   MaxObjectCount = PageCount * AutoSystemInfo::PageSize / HeapConstants::ObjectGranularity;
    static const uint   MaxSmallObjectCount = MaxObjectCount;
    static const uint   ObjectCountPerPage = AutoSystemInfo::PageSize / HeapConstants::ObjectGranularity;

    // This is there for RecyclerSweep to distinguish which bucket index to use
    static const bool IsSmallBlock = true;
    static const bool IsMediumBlock = false;
    static const bool IsLargeBlock = false;

    static BOOL IsAlignedObjectSize(size_t sizeCat);
};

class MediumAllocationBlockAttributes
{
public:
#if defined(__IOS__)&&defined(_M_ARM64)
// iOS has 16K pageSize instead of the regular 4K expected on most systems.
    static const size_t PageCount = 2;
#else // defined(__IOS__)&&defined(_M_ARM64)
    static const size_t PageCount = 8;
#endif // defined(__IOS__)&&defined(_M_ARM64)
    static const size_t MinObjectSize = HeapConstants::MaxSmallObjectSize;
    static const ushort BitVectorCount = ((PageCount * AutoSystemInfo::PageSize) / HeapConstants::ObjectGranularity);
    static const size_t MaxAddressBit = (BitVectorCount - 1);
    static const uint   MaxObjectSize = HeapConstants::MaxMediumObjectSize;
    static const uint   BucketCount = HeapConstants::MediumBucketCount;
    static const size_t BucketGranularity = HeapConstants::MediumObjectGranularity;
    static const uint   MaxObjectCount = PageCount * AutoSystemInfo::PageSize / (MinObjectSize + BucketGranularity);
    static const uint   MaxSmallObjectCount = PageCount * AutoSystemInfo::PageSize / HeapConstants::ObjectGranularity;
    static const uint   ObjectCountPerPage = AutoSystemInfo::PageSize / MinObjectSize;

    // This is there for RecyclerSweep to distinguish which bucket index to use
    static const bool IsSmallBlock = false;
    static const bool IsMediumBlock = true;
    static const bool IsLargeBlock = false;

    static BOOL IsAlignedObjectSize(size_t sizeCat);
};

class LargeAllocationBlockAttributes
{
public:
    // This is there for RecyclerSweep to distinguish which bucket index to use
    static const bool IsSmallBlock = false;
    static const bool IsMediumBlock = false;
    static const bool IsLargeBlock = true;
};
