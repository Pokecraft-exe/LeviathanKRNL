#pragma once
#include <stdint.h>
#include "memmap.hpp"
#include "bitmap.hpp"
#define PAGE_KEY_WRITE 0b010
#define PAGE_READ_ONLY 0b010
#define PAGING_FREE_PAGE 1
#define PAGING_LOCK_PAGE 2
#define PAGING_RESERVE_PAGE 3
#define PAGING_UNRESERVE_PAGE 4
typedef long unsigned int size_t;

namespace paging {

	class pageMapIndexer {
		public:
			pageMapIndexer(uint64_t virtualAddress);
			uint64_t PDP_i;
			uint64_t PD_i;
			uint64_t PT_i;
			uint64_t P_i;
	};

	struct page {
		bool present : 1;
		bool write : 1;
		bool user : 1;
		bool wrightThrough : 1;
		bool cacheDisabled : 1;
		bool accessed : 1;
		bool zero : 1;
		bool zero2 : 1;
		bool zero3 : 1;
		uint8_t avaliable : 3;
		uint64_t address : 53;
	};

	struct pageTable {
		page pageDirectory[512];
	}__attribute__((aligned(0x1000)));

	namespace pageManager {
		void setPML4(pageTable* PML4Address);
		void mapMemory(void* virtualAddress, void* physicalAddress);
	}

	void ReadMemoryMap();

	void freePage(uintptr_t* ptr);
	void lockPage(uintptr_t* ptr);
	void reservePage(uintptr_t* ptr);
	void unreservePage(uintptr_t* ptr);
	void editPages(uintptr_t* ptr, size_t count, int status);
	uintptr_t* requestPage();
	uint64_t getFreeMemory();
	uint64_t getUsedMemory();
	uint64_t getSystemMemory();
	extern "C" void disable_paging();
}