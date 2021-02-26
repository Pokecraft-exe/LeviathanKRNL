#pragma once
#include "typedefs.h"
#include "printf.h"
#include "Heap.h"
#include "serial.h"

struct MemoryMapEntry{
    uint_64 BaseAddress;
    uint_64 RegionLength;
    uint_32 RegionType;
    uint_32 ExtendedAttributes;
};

extern uint_8 MemoryRegionCount;
extern uint8 UsableMemoryRegionCount;

void printMemMap(MemoryMapEntry* memoryMap);
MemoryMapEntry** GetUsableMemoryRegions();
void memset(const void* start, uint_64 value, uint_64 num);
void memcpy(const void* destination, const void* source, uint_64 num);