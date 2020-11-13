#pragma once
#include "typedefs.cpp"
#include "printf.cpp"

struct MemoryMapEntry{
    uint_64 BaseAddress;
    uint_64 RegionLength;
    uint_32 RegionType;
    uint_32 ExtendedAttributes;
};

extern uint_8 MemoryRegionCount;
uint8 UsableMemoryRegionCount;

MemoryMapEntry* UsableMem[10];

void printMemMap(MemoryMapEntry* memoryMap, uint16 pos) {
    SetCursorPosition(pos);

    printf("Memory Base: "); printf(IntToStr(memoryMap->BaseAddress));
    SetCursorPosition(pos + 80);
    printf("Region Length: "); printf(IntToStr(memoryMap->RegionLength));
    printf("\n");
    printf("Memory Type: "); printf(IntToStr(memoryMap->RegionType));
    printf("\n");
    printf("Memory Attributes: "); printf(IntToStr(memoryMap->ExtendedAttributes));
    printf("\n\n");

}

bool MemGot = false;

// MemoryMapEntry** GetUsableMem(){if(MemGot){return UsableMem;}for(uint8 i=0;i<MemoryRegionCount;i++){MemoryMapEntry* memMap=(MemoryMapEntry*)0x5000;memMap+=i;if(memMap->RegionType==1){UsableMem[UsableRedionIndex]=memMap;UsableRegionIndex++;}}

// MemGot = true;
// return UsableMem;
// }
