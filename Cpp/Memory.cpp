#include "H/Memory.h"

uint_8 UsableMemoryRegionCount;
MemoryMapEntry* UsableMemoryRegions[10];

void memcpy(const void* destination, const void* source, uint_64 num){
    if (num <= 8) {
        uint8* valPtr = (uint8*)&source;
        for (uint8* ptr = (uint8*)destination; ptr < (uint8*)((uint_64)destination + num); ptr++) {
            *ptr = *valPtr;
            valPtr++;
        }
        return;
    }
    uint_64 proceedingBytes = num % 8;
    uint_64 newnum = num - proceedingBytes;
    uint_64* srcptr = (uint_64*)source;

    for (uint64* destptr = (uint64*)destination; destptr < (uint64*)((uint_64)destination + newnum); destptr++) {
        *destptr = *srcptr;
        srcptr++;
    }
    uint8* srcptr8 = (uint8*)((uint_64)source + newnum);
    for (uint8* destptr8 = (uint8*)((uint64)destination + newnum); destptr8 < (uint8*)((uint64)destination + newnum); destptr8++) {
        *destptr8 = *srcptr8;
        srcptr8++;
    }
}

void printMemMap(MemoryMapEntry* memoryMap) {
    /*debug("Memory Base: ",memoryMap->BaseAddress);
    debug("Region Length: ",memoryMap->RegionLength);
    debug("Memory Type: ",memoryMap->RegionType);
    debug("Memory Attributes: ",memoryMap->ExtendedAttributes);*/
    debug("Usable Memory Region count :", UsableMemoryRegionCount);
    debug("Memory Region count :",MemoryRegionCount);

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
        *ptr = *valPtr;
        valPtr++;
    }
}
