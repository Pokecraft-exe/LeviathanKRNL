#include "allocator.hpp"
#include "stdio"

Chunk_List alloced_chunks;
uint8_t HEAP[HEAP_CAPACITY] = { 0 };

void* memcpy(void* dest, const void* src, size_t len)
{
    char* d = (char*)dest;
    const char* s = (const char*)src;
    while (len--)
        *d++ = *s++;
    return dest;
}

void* memclear(void* dest, size_t len)
{
    char* d = (char*)dest;
    while (len--)
        *d++ = 0;
    return dest;
}

template int std::quickSort<Chunk>(Chunk*, bool (*)(Chunk, Chunk), int, int);

bool sort(Chunk a, Chunk b){
    return a.start < b.start;
}

bool init_heap() {
    uint64_t totalMemsize = memmap::get_memory_size(LIMINE_MEMMAP_ALL);
    uint64_t realHeapCapacity = totalMemsize - (uintptr_t)&HEAP;
    
    for (int i = 0; i < CHUNK_LIST_CAP; i++) {
    	alloced_chunks[i] = { nullptr, 0 };
    }

    alloced_chunks.count = 2;
    alloced_chunks[0] = { (uintptr_t*)HEAP, 1 };
    alloced_chunks[1] = { (uintptr_t*)0xFFFFFFFFFFFFFFFF, 0 };
    
    //if (((uintptr_t)alloced_chunks[1].start + 1) - (uintptr_t)alloced_chunks[0].start == realHeapCapacity) return 1;
    return 1;
}

bool free(void* ptr) {
    // search the current chunk remove it,
    // clear it and sort the chunks
    if (ptr == (void*)0xFFFFFFFFFFFFFFFF) return 0;
    
    size_t j = -1;
    for (size_t i = 1; i < alloced_chunks.count; i++) {
        if (alloced_chunks[i].start == (uintptr_t*)ptr) {
            j = i;
            break;
        }
    }
    if (j == -1) return 0;
    alloced_chunks[j].start = 0;
    alloced_chunks[j].size = 0;
    // sort the alloced chuncks
    for (int i = j; i < alloced_chunks.count; i++) {
        alloced_chunks[i] = alloced_chunks[i+1];
    }
    alloced_chunks.count--;
    return 1;
}

void* realloc(void* ptr, size_t size) {
    // allocate new size
    // free last chunk
    if (size == 0) return nullptr;
    signed long long j = -1;
    for (size_t i = 0; i < alloced_chunks.count; i++) {
        if (alloced_chunks[i].start == (uintptr_t*)ptr) {
            j = i;
            break;
        }
    }
    if (j == -1) return nullptr;
    size_t i = j; // convert to unsigned
    uintptr_t* new_ptr = nullptr;
    Chunk* Last_chunk = &alloced_chunks[0];
    for (int i = 1; i < alloced_chunks.count; i++) {
        if (Last_chunk->start + Last_chunk->size != alloced_chunks[i].start) {
            // free chunk found
            size_t free_size = alloced_chunks[i].start - (Last_chunk->start + Last_chunk->size);
            if (free_size >= size) {
                new_ptr = (uintptr_t*)(Last_chunk->start) + Last_chunk->size + 1;
                alloced_chunks[alloced_chunks.count] = { new_ptr, size };
                alloced_chunks.count++;
                break;
            }
            Last_chunk = &alloced_chunks[i];
        }
    }
    // free the last chunk
    alloced_chunks[i].start = 0;
    alloced_chunks[i].size = 0;
    // sort the alloced chuncks
    std::quickSort<Chunk>(alloced_chunks.chunks, sort, 0, alloced_chunks.count);
    alloced_chunks.count--;
    // invert the last chunks
    for (int i = j-1; i < alloced_chunks.count - j;) {
        alloced_chunks[i] = alloced_chunks[i++];
    }
    return new_ptr;
}

void* alloc(size_t size) {
    // find a free chunk large enough and return the pointer
    
    if (size == 0) return nullptr;
    // no need to waste a chunk

    uintptr_t* ptr = nullptr;
    Chunk* Last_chunk = &alloced_chunks[0];
    std::stdin cout;

    // iterate through chunks
    for (int i = 1; i < alloced_chunks.count; i++) {
        // find a free chunk
        //cout << Last_chunk->start << std::endl;
        if (Last_chunk->start + Last_chunk->size < alloced_chunks[i].start) {
            size_t free_size = alloced_chunks[i].start - (Last_chunk->start + (Last_chunk->size*8));
            if (free_size >= size) {
                ptr = (uintptr_t*)(Last_chunk->start) + Last_chunk->size;
                alloced_chunks[alloced_chunks.count] = { ptr, size };
                alloced_chunks.count++;
                break;
            }
        }
        Last_chunk = &alloced_chunks[i];
    }
    std::quickSort<Chunk>(alloced_chunks.chunks, sort, 0, alloced_chunks.count - 1);
    return ptr;
}

void dumpChunks() {
    std::stdin cout;
    int i = 0;
    while (i < CHUNK_LIST_CAP) {
        if (alloced_chunks[i].start != nullptr) {
    	cout << '[' << i << "] : " << alloced_chunks[i].start << " : " << alloced_chunks[i].size << std::endl;
    	}
    	i++;
    }
}
