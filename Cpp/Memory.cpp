#include "H/Memory.h"

uint8 UsableMemoryRegionCount;
MemoryMapEntry* UsableMemoryRegions[10];

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

bool MemoryRegionsGot = false;

MemoryMapEntry** GetUsableMemoryRegions() {
    if (MemoryRegionsGot == true) return UsableMemoryRegions;
    uint8 UsableRegionsIndex;
    for(uint8 i = 0; i < MemoryRegionCount; i++) {
        MemoryMapEntry* memMap = (MemoryMapEntry*)0x5000;
        memMap += i;
        if (memMap->RegionType == 1) {
            UsableMemoryRegions[UsableRegionsIndex] = memMap;
            UsableRegionsIndex++;

        }
        UsableMemoryRegionCount = UsableRegionsIndex;
    }
    MemoryRegionsGot = true;
    return UsableMemoryRegions;

}
