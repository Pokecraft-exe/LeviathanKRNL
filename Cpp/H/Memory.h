#pragma once
#include "typedefs.h"
#include "printf.h"

struct MemoryMapEntry{
    uint_64 BaseAddress;
    uint_64 RegionLength;
    uint_32 RegionType;
    uint_32 ExtendedAttributes;
};

extern uint_8 MemoryRegionCount;
extern uint8 UsableMemoryRegionCount;

void printMemMap(MemoryMapEntry* memoryMap, uint16 pos);
MemoryMapEntry** GetUsableMemoryRegions();