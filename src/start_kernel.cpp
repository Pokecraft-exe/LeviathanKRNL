//#include "H/KBscancodes.h"
#include "printf.h"
#include "font.hpp"
#include "IDT.h"
#include "allocator.hpp"
/*#include "sound.h"
#include "typedefs.h"
#include "mouse.h"
#include "errors.h"
//#include "Time.h"
#include "stddef.h"*/
#include "serial.h"
#include "memmap.hpp"
#include "paging.hpp"
#include "kernel.h"
#include "stdio"

void delay(int clocks)
{
    asm("push %rax");
    for(uint64_t i = 0; i < clocks; i+=8){
        asm("xor %rax, %rax");
    }
    asm("pop %rax");
    return;
}

uint16_t CursorPosition = 0;

extern "C" void hello();
extern "C" long long int ret1();

uint64_t formatbytes(uint64_t bytes) {
    if (bytes < 1024) {
        return bytes;
    }
    else {
        size_t size = 1024;
        for (size_t i = 0; bytes / size > 1024; i++) {
            size *= 1024;
        }
        return bytes / size;
    };
}

char* getByteFormat(uint64_t bytes) {
    char* arr[7] = { " B", " KB", " MB", "GB", " TB", " PB", " HB"};
    if (bytes < 1024) {
        return arr[0];
    }
    else {
        size_t size = 1024;
        size_t i = 1;
        for (i; bytes / size > 1024; i++) {
            size *= 1024;
        }
        return arr[i];
    };
}

int cursorpos[2] = { 0, 0 };

extern "C" void start_K(){
    //__BOOTSCREEN__();
    //MasterVolume = 100;
    //cls();
    //PlaySound(469,MasterVolume);

	{
        VGA_WIDTH = framebuffer->width/16;
	    KEY = (char*)alloc(1);
    }

    std::stdin cout;

    //print("");

    cout << "Framebuffer [\x00m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;

    size_t memory_size = 0;
    if (memmap::memmap_request()) {
        cout << "Memmap [\x00m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;
    	memory_size = memmap::get_memory_size(LIMINE_MEMMAP_ALL);
    } else {
        cout << "Memmap [\x00m[\xff\x00\x00]Error\x00m[\xff\xff\xff]]]" << std::endl;
        while(1);
    }

    if (init_heap()) {
        cout << "Heap [\x00m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;
    } else {
        cout << "Heap [\x00m[\xff\x00\x00]Error\x00m[\xff\xff\xff]]]" << std::endl;
        while(1);
    }

    paging::ReadMemoryMap();

    if (paging::getFreeMemory() +
        paging::getUsedMemory() +
        paging::getSystemMemory()
        == memory_size) {
        cout << "Paging Size [\x00m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;
    } else {
        cout << "Paging Size [\x00m[\xff\x00\x00]Error\x00m[\xff\xff\xff]]]" << std::endl;
        while(1);
    }

    //paging::editPages((uintptr_t*)&kernelStart, (kernelSize / 4096) + 1, PAGING_RESERVE_PAGE);

    cout << "free memory: " << formatbytes(paging::getFreeMemory()) << getByteFormat(paging::getFreeMemory()) << std::endl;
    
    cout << "used memory: " << formatbytes(paging::getUsedMemory()) << getByteFormat(paging::getUsedMemory()) << std::endl;
    
    cout << "system memory: " << formatbytes(paging::getSystemMemory()) << getByteFormat(paging::getSystemMemory()) << std::endl;

    /*InitIDT();

    register uint64_t rbx asm("rbx");
    rbx = 1;

    init_PIT();
    add_IRQ(ISA::PIT, IRQ0_handler, IDT_IG);*/

    void* a = alloc(100);
    void* b = alloc(20);

    bool allocCorrect = (a == b - 100);
    if (allocCorrect) {
        cout << "Allocator [\x00m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;
    } else {
        cout << "Allocator [\x00m[\xff\x00\x00]Error\x00m[\xff\xff\xff]]]" << std::endl;
    }

    free(a);
    void*c = alloc(20);
    if (a == c) {
        cout << "Free [\x00m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;
    } else {
        cout << "Free [\x00m[\xff\x00\x00]Error\x00m[\xff\xff\xff]]]" << std::endl;
        cout << "c = " << c << std::endl;
        cout << "a = " << a << std::endl;
    }

    while(1);

    
    paging::pageTable* PML4 = (paging::pageTable*)paging::requestPage();
    
    print(HexToString(PML4));
    
    memset(PML4, 0, 0x1000);

    {
        paging::pageManager::setPML4(PML4);

        for (size_t i = 0; i < memory_size; i += 0x1000) {
            paging::pageManager::mapMemory((void*)i, (void*)i);
        }

        for (size_t i = (uint64_t)framebuffer->address; i < framebuffer->width + 0x1000; i += 0x1000) {
            paging::pageManager::mapMemory((void*)i, (void*)i);
        }
        
        asm ("mov %0, %%cr3" : : "r" (PML4));
    }

    

    //_hRAMDISK();
    //restart();
    while(1) {   //mainloop
        ;
	}
    return;
}
