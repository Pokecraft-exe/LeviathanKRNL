#define PAGING_CPP_CODE
#include "paging.hpp"
#include "allocator.hpp"

uint64_t pageDirectory[1024];
int pages = -1;

uint64_t* getPage(page p){
	uint64_t PD = 0;
	PD |= p.XD << 63;
	PD |= p.key << 60;
	PD |= p.size2 << 52;
	uintptr_t address;
	if (p.size) address = (uintptr_t)alloc(p.size2 | p.size1);
	else address = (uintptr_t)alloc(4104304); // 4MIB
	PD |= address << 30;
	PD |= p.size1 << 7;
	PD |= p.user << 2;
	PD |= p.write << 1;
	PD |= p.present;
	uint64_t* _page = &pageDirectory[pages++];
	pageDirectory[pages] = PD;
	return _page;
}

void c_enablePaging() {
	disable_paging();
	enable_pae();
	set_long_mode(&pageDirectory);
	enable_paging();

}
