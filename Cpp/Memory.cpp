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

void memset(void* start, uint_64 value, uint_64 num){
    
    if (num <= 8) {
        uint8* valPtr = (uint8*)&value;
        for (uint8* ptr = (uint8*)start; ptr < (uint8*)((uint_64)start + num); ptr++) {
            *ptr = *valPtr;
            valPtr++;
        }
        return;
    }
    uint_64 proceedingBytes = num % 8;
    uint_64 newnum = num - proceedingBytes;

    for (uint64* ptr = (uint64*)start; ptr < (uint64*)((uint_64)start + newnum); ptr++) {
        *ptr = value;
    }
    uint8* valPtr = (uint8*)&value;
    for (uint8* ptr = (uint8*)((uint64)start + newnum); ptr < (uint8*)((uint64)start + newnum); ptr++) {
        *prt = *valPtr;
        valPtr++;
    }
}
