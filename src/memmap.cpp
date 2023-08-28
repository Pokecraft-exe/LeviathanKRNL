#include "limine.h"

static volatile struct limine_memmap_request limine_memmap_request = {
    .id = LIMINE_MEMMAP_REQUEST,
    .revision = 0
};

struct limine_memmap_entry ** memmap;

bool memmap_request() {
	if (limine_memmap_request.response == nullptr
     || limine_memmap_request.response->entry_count < 1) {
        return 0;
    }
 
    memmap = limine_memmap_request.response->entries;
    return 1;
}
