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

extern void InitHeap (uint_64 HeapAdress, uint_64 HeapLength);

extern void* malloc(uint_64 size);