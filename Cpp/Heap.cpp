#include "H/Heap.h"

MemorySegmentHeader* FirstFreeMemorySegment;

void InitHeap (uint_64 HeapAdress, uint_64 HeapLength){
    FirstFreeMemorySegment = (MemorySegmentHeader*)HeapAdress;
    FirstFreeMemorySegment->MemoryLength = HeapLength - sizeof(MemorySegmentHeader);
    FirstFreeMemorySegment->NextSegment = 0;
    FirstFreeMemorySegment->PreviousSegment = 0;
    FirstFreeMemorySegment->NextFreeSegment = 0;
    FirstFreeMemorySegment->PreviousFreeSegment = 0;
}

void* malloc(uint_64 size) {
    uint_64 remainder = size % 8;
    size -= remainder;
    if (remainder != 0) size += 8;

    MemorySegmentHeader* currentMemorySegment = FirstFreeMemorySegment;

    while(true) {
        if (currentMemorySegment->MemoryLength >= size) {
            return currentMemorySegment + 1;//sizeof(MemorySegmentHeader);
        }
    }

}