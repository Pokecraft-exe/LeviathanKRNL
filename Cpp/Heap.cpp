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

void* calloc(uint_64 size) {
    void* mallocVal = malloc(size);
    memset(mallocVal, 0, size);
    return mallocVal;
}

void* calloc(uint_64 num, uint_64 size) {
    return calloc(num * size);
}

void* realloc(void* address, uint_64 newSize){
    MemorySegmentHeader* oldSegmentHeader;
    AlignedMemorySegmentHeader* AMSH = (AlignedMemorySegmentHeader*)address - 1;
    if (AMSH->IsAligned){
        oldSegmentHeader = (MemorySegmentHeader*)(uint_64)AMSH->MemorySegmentHeaderAddress;
    }else{
        oldSegmentHeader = ((MemorySegmentHeader*)address) - 1;
    }
    uint_64 smallersize = newSize;
    if (oldSegmentHeader->MemoryLength < newSize) smallersize = oldSegmentHeader->MemoryLength;
    void* newMem = malloc(newSize);
    memcpy(newMem, address, smallersize);
    free(address);
    return newMem;
}

void* malloc(uint_64 size) {
    uint_64 remainder = size % 8;
    size -= remainder;
    if (remainder != 0) size += 8;

    MemorySegmentHeader* currentMemorySegment = FirstFreeMemorySegment;

    while(true) {
        if (currentMemorySegment->MemoryLength >= size) {
            if (currentMemorySegment->MemoryLength > size + sizeof(MemorySegmentHeader)) {
                MemorySegmentHeader* NewSegmentHeader = (MemorySegmentHeader*)((uint_64)currentMemorySegment + sizeof(MemorySegmentHeader) + size);

                NewSegmentHeader->Free = true;
                NewSegmentHeader->MemoryLength = ((uint_64)currentMemorySegment->MemoryLength) - (sizeof(MemorySegmentHeader) + size);
                NewSegmentHeader->NextFreeSegment = currentMemorySegment->NextFreeSegment;
                NewSegmentHeader->NextSegment = currentMemorySegment->NextSegment;
                NewSegmentHeader->PreviousSegment = currentMemorySegment;
                NewSegmentHeader->PreviousFreeSegment = currentMemorySegment->PreviousFreeSegment;

                currentMemorySegment->NextFreeSegment = NewSegmentHeader;
                currentMemorySegment->NextSegment = NewSegmentHeader;
                currentMemorySegment->MemoryLength = size;
            }
            if (currentMemorySegment == FirstFreeMemorySegment) {
                FirstFreeMemorySegment = currentMemorySegment->NextFreeSegment;
            }
            currentMemorySegment->Free = false;
            if (currentMemorySegment->PreviousFreeSegment != 0) currentMemorySegment->PreviousFreeSegment->NextFreeSegment = currentMemorySegment->NextFreeSegment;
            if (currentMemorySegment->NextFreeSegment != 0 ) currentMemorySegment->NextFreeSegment->PreviousFreeSegment = currentMemorySegment->PreviousFreeSegment;
            if (currentMemorySegment->PreviousSegment != 0) currentMemorySegment->PreviousSegment->NextFreeSegment = currentMemorySegment->NextFreeSegment;
            if (currentMemorySegment->NextSegment != 0) currentMemorySegment->NextSegment->PreviousFreeSegment = currentMemorySegment->PreviousFreeSegment;
            
            return currentMemorySegment + 1;//sizeof(MemorySegmentHeader);
        }
        if (currentMemorySegment->NextFreeSegment == 0){
            return 0; //No memory

        }
        currentMemorySegment = currentMemorySegment->NextFreeSegment;
    }
    return 0; // never go here
}

void CombineFreeSegments(MemorySegmentHeader* a, MemorySegmentHeader* b){
    if (a == 0) return;
    if (b == 0) return;
    if (a < b) {
        a->MemoryLength += b->MemoryLength + sizeof(MemorySegmentHeader);
        a->NextSegment = b->NextSegment;
        a->NextFreeSegment = b->NextFreeSegment;
        b->NextSegment->PreviousSegment = a;
        b->NextSegment->PreviousFreeSegment = a;
        b->NextFreeSegment->PreviousFreeSegment = a;
    }else{
        b->MemoryLength += a->MemoryLength + sizeof(MemorySegmentHeader);
        b->NextSegment = a->NextSegment;
        b->NextFreeSegment = a->NextFreeSegment;
        a->NextSegment->PreviousSegment = b;
        a->NextSegment->PreviousFreeSegment = b;
        a->NextFreeSegment->PreviousFreeSegment = b;
    }
}

void* aligned_Alloc(uint_64 alignment, uint_64 size){
    uint_64 alignmentReminder = alignment % 8;
    alignment -= alignmentReminder;
    if (alignmentReminder != 0) alignment += 8;

    uint_64 sizeReminder = size % 8;
    size -= sizeReminder;
    if (sizeReminder != 0) size += 8;

    uint_64 fullsize = size + alignment;

    void* mallocVal = malloc(fullsize);
    uint_64 address = (uint_64)mallocVal;

    uint_64 Reminder = address % alignment;
    address -= alignment;
    if (Reminder != 0) {
        address += alignment;

        AlignedMemorySegmentHeader* ASMH = (AlignedMemorySegmentHeader*)address - 1;
        ASMH->IsAligned = true;
        ASMH->MemorySegmentHeaderAddress = (uint_64)mallocVal - sizeof(MemorySegmentHeader);
    }
    return (void*)address;
}

void free(void* address) {
    MemorySegmentHeader* currentMemorySegment;
    AlignedMemorySegmentHeader* AMSH = (AlignedMemorySegmentHeader*)address - 1;
    if (AMSH->IsAligned){
        currentMemorySegment = (MemorySegmentHeader*)(uint_64)AMSH->MemorySegmentHeaderAddress;
    }else{
        currentMemorySegment = ((MemorySegmentHeader*)address) - 1;
    }
    currentMemorySegment->Free = true;

    if (currentMemorySegment < FirstFreeMemorySegment) FirstFreeMemorySegment = currentMemorySegment;

    if (currentMemorySegment->NextFreeSegment != 0){
        if (currentMemorySegment->NextFreeSegment->PreviousFreeSegment < currentMemorySegment){
            currentMemorySegment->NextFreeSegment->PreviousFreeSegment = currentMemorySegment;
        }
    }
    if (currentMemorySegment->PreviousFreeSegment != 0){
        if (currentMemorySegment->PreviousFreeSegment->NextFreeSegment > currentMemorySegment){
            currentMemorySegment->PreviousFreeSegment->NextFreeSegment = currentMemorySegment;
        }
    }
    if (currentMemorySegment->NextSegment != 0){
            currentMemorySegment->NextSegment->PreviousSegment = currentMemorySegment;
            if (currentMemorySegment->NextSegment->Free) CombineFreeSegments(currentMemorySegment, currentMemorySegment->NextFreeSegment);
    }
    if (currentMemorySegment->PreviousSegment != 0){
            currentMemorySegment->PreviousSegment->NextSegment = currentMemorySegment;
            if (currentMemorySegment->PreviousSegment->Free) CombineFreeSegments(currentMemorySegment, currentMemorySegment->PreviousFreeSegment);
    }
}