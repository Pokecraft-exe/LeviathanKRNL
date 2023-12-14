#define PAGING_CPP_CODE
#include "paging.hpp"
#include "allocator.hpp"
#include "serial.h"
#include "IDT.h"
#include "printf.h"

uint64_t free_memory;
uint64_t used_memory;
uint64_t system_memory;

bitmap* pageBitmap;
size_t bitmapSize;

paging::pageTable* pml4;

void paging::ReadMemoryMap() {
	//finding the largest usable memory segment
	limine_memmap_entry largest = {
		0, 0, 0
	};
	limine_memmap_entry* addr;
	bool isfirst = true;
	for (size_t i = 0; i < memmap::memmap.entry_count; i++) {
		if (memmap::memmap.entries[i]->type == LIMINE_MEMMAP_USABLE) {
			if (memmap::memmap.entries[i]->length > largest.length ) {
				largest = *memmap::memmap.entries[i];
				addr = memmap::memmap.entries[i];
			}
		}
	}

	size_t memorySize = memmap::get_memory_size(LIMINE_MEMMAP_ALL);
	free_memory = memorySize;

	bitmapSize = memorySize / 4096 / 8 + 1;

	// init bitmap
	{
		pageBitmap = (bitmap*)addr->base;
		for (size_t i; i < bitmapSize; i++) {
			*((uint8_t*)(pageBitmap + i)) = 0;
		}
	}
	
	{
		editPages((uintptr_t*)pageBitmap, bitmapSize, PAGING_LOCK_PAGE);

		for (size_t i = 0; i < memmap::memmap.entry_count - 1; i++) {
			if (memmap::memmap.entries[i]->type != LIMINE_MEMMAP_USABLE) {
					editPages((uintptr_t*)memmap::memmap.entries[i]->base, (memmap::memmap.entries[i]->length/4096) + 1, PAGING_RESERVE_PAGE);
			}
		}
	}
}

uint64_t paging::getFreeMemory() { return free_memory; }
uint64_t paging::getUsedMemory() { return used_memory; }
uint64_t paging::getSystemMemory() { return system_memory; }

void paging::freePage(uintptr_t* ptr) {
	size_t index = (uint64_t)ptr / 4096;
	if (pageBitmap[index/8][index%8] == false) return;
	pageBitmap[index/8](index%8, false);
	free_memory += 4096;
	used_memory -= 4096;
}
void paging::lockPage(uintptr_t* ptr) {
	size_t index = (uint64_t)ptr / 4096;
	if (pageBitmap[index/8][index%8] == true) return;
	pageBitmap[index/8](index%8, true);
	free_memory -= 4096;
	used_memory += 4096;
}
void paging::unreservePage(uintptr_t* ptr) {
	size_t index = (uint64_t)ptr / 4096;
	if (pageBitmap[index/8][index%8] == false) return;
	pageBitmap[index/8](index%8, false);
	free_memory += 4096;
	system_memory -= 4096;
}
void paging::reservePage(uintptr_t* ptr) {
	size_t index = (uint64_t)ptr / 4096;
	if (pageBitmap[index/8][index%8] == true) return;
	pageBitmap[index/8](index%8, true);
	free_memory -= 4096;
	system_memory += 4096;
}
void paging::editPages(uintptr_t* ptr, size_t count, int status) {
	switch (status) {
		case PAGING_FREE_PAGE:
			for (size_t i = 0; i < count; i++) {
				freePage((uintptr_t*)(ptr + (i * 4096)));
			}
			break;
		case PAGING_LOCK_PAGE:
			for (size_t i = 0; i < count; i++) {
				lockPage((uintptr_t*)(ptr + (i * 4096)));
			}
			break;
		case PAGING_RESERVE_PAGE:
			for (size_t i = 0; i < count; i++) {
				reservePage((uintptr_t*)(ptr + (i * 4096)));
			}
			break;
		case PAGING_UNRESERVE_PAGE:
			for (size_t i = 0; i < count; i++) {
				unreservePage((uintptr_t*)(ptr + (i * 4096)));
			}
			break;
	}
}
uintptr_t* paging::requestPage() {
	for (size_t i = 1; i < bitmapSize * 8; i++) {
		if (pageBitmap[i/8][i%8] == false) {
			lockPage((uintptr_t*)(i * 4096));
			return (uintptr_t*)(i*4096);
		}
	}
	print("hello world!");
	while(1);
	return nullptr; // swap
}
paging::pageMapIndexer::pageMapIndexer(uint64_t address) {
	address >>= 12;
	P_i = address & 0x1ff;
	address >>= 9;
	PT_i = address & 0x1ff;
	address >>= 9;
	PD_i = address & 0x1ff;
	address >>= 9;
	PDP_i = address & 0x1ff;
}
void paging::pageManager::setPML4(paging::pageTable* PML4Address) {	pml4 = PML4Address; }
void paging::pageManager::mapMemory(void* vaddr, void* addr) {
	pageMapIndexer indexer((uint64_t)vaddr);
	page PDE;
	pageTable* PDP;
	pageTable* PD;
	pageTable* PT;

	{
		PDE = pml4->pageDirectory[indexer.PDP_i];
		if (!PDE.present) {
			PDP = (pageTable*)requestPage();
			//memset((void*)PDP, 0, 0x1000);
			PDE.address = (uint64_t)PDP >> 12;
			PDE.present = true;
			PDE.write = true;
			pml4->pageDirectory[indexer.PDP_i] = PDE;
		} else {
			PDP = (pageTable*)((uint64_t)PDE.address << 12);
		}
	}

	{
		PDE = PDP->pageDirectory[indexer.PD_i];
		if (!PDE.present) {
			PD = (pageTable*)requestPage();
			//memset((void*)PD, 0, 0x1000);
			PDE.address = (uint64_t)PD >> 12;
			PDE.present = true;
			PDE.write = true;
			PDP->pageDirectory[indexer.PD_i] = PDE;
		} else {
			PD = (pageTable*)((uint64_t)PDE.address << 12);
		}
	}

	{
		PDE = PDP->pageDirectory[indexer.PT_i];
		if (!PDE.present) {
			PT = (pageTable*)requestPage();
			//memset((void*)PT, 0, 0x1000);
			PDE.address = (uint64_t)PT >> 12;
			PDE.present = true;
			PDE.write = true;
			PD->pageDirectory[indexer.PT_i] = PDE;
		} else {
			PT = (pageTable*)((uint64_t)PDE.address << 12);
		}
	}

	{
		PDE = PT->pageDirectory[indexer.P_i];
		PDE.address = (uint64_t)addr >> 12;
		PDE.present = true;
		PDE.write = true;
		PT->pageDirectory[indexer.P_i] = PDE;
	}
}

