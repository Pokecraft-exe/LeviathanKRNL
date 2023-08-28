#pragma once
#include <stdint.h>
#define PAGE_NO_KEY 0b000
#define PAGE_HAS_KEY 0b001
#define PAGE_KEY_WRITE 0b010
#define PAGE_READ_ONLY 0b010
#define PAGE_KEY_UINT64 0b100
#define PAGE_KEY_UINT32 0b000

struct page {
	bool present;
	bool write;
	bool user;
	bool zero1;
	bool zero2;
	bool size;
	uint8_t size1;
	uint8_t size2;
	uint8_t key;
	uint8_t XD;
};

#ifdef PAGING_CPP_CODE
extern "C" void enable_pae();
extern "C" void set_long_mode(void*);
extern "C" void enable_paging();
extern "C" void reloadCS();
#endif

extern "C" void disable_paging();
uint64_t* getPage();
void c_enablePaging();
