#pragma once
#include "typedefs.h"

struct MemorySegmentHeader {
    uint_64 MemoryLength;
    MemorySegmentHeader* NextSegment;
    MemorySegmentHeader* PreviousSegment;
    MemorySegmentHeader* NextFreeSegment;
    MemorySegmentHeader* PreviousFreeSegment;
    bool Free;

};

void InitHeap (uint_64 HeapAdress, uint_64 HeapLength);
void* calloc(uint_64 size);
void* malloc(uint_64 size);
void CombineFreeSegments(MemorySegmentHeader* a, MemorySegmentHeader* b);
void free (void* address);