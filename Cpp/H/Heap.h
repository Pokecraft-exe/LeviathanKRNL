#pragma once
#include "typedefs.h"
#include "Memory.h"

struct MemorySegmentHeader {
    uint_64 MemoryLength;
    MemorySegmentHeader* NextSegment;
    MemorySegmentHeader* PreviousSegment;
    MemorySegmentHeader* NextFreeSegment;
    MemorySegmentHeader* PreviousFreeSegment;
    bool Free;

};

struct AlignedMemorySegmentHeader {
    uint_64 MemorySegmentHeaderAddress : 63;
    bool IsAligned : 1;

};

void InitHeap (uint_64 HeapAdress, uint_64 HeapLength);
void* calloc(uint_64 size);
void* calloc(uint_64 num, uint_64 size);
void* realloc(void* adress, uint_64 newSize);
void* malloc(uint_64 size);
void CombineFreeSegments(MemorySegmentHeader* a, MemorySegmentHeader* b);
void* aligned_Alloc(uint_64 alignment, uint_64 size);
void free (void* address);