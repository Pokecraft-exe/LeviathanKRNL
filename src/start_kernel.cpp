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

    //print("");

    printNoReturn("Framebuffer [");
    printNoReturn("Correct", 0x00ff00);
    print("]");

    size_t memory_size = 0;
    if (memmap::memmap_request()) {
        printNoReturn("Memmap [");
        printNoReturn("Correct", 0x00ff00);
        print("]");
    	memory_size = memmap::get_memory_size(LIMINE_MEMMAP_ALL);
    } else {
        printNoReturn("Memmap [");
        printNoReturn("Error", 0xff0000);
        print("]");
        while(1);
    }

    paging::ReadMemoryMap();

    if (paging::getFreeMemory() +
        paging::getUsedMemory() +
        paging::getSystemMemory()
        == memory_size) {
        printNoReturn("Paging [");
        printNoReturn("Correct", 0x00ff00);
        print("]");
    } else {
        printNoReturn("Memmap [");
        printNoReturn("Error", 0xff0000);
        print("]");
        while(1);
    }

    //paging::editPages((uintptr_t*)&kernelStart, (kernelSize / 4096) + 1, PAGING_RESERVE_PAGE);

    printNoReturn("free memory: ");
	printNoReturn(IntToStr(formatbytes(paging::getFreeMemory())));
    print(getByteFormat(paging::getFreeMemory()));
    
    printNoReturn("used memory: ");
	printNoReturn(IntToStr(formatbytes(paging::getUsedMemory())));
    print(getByteFormat(paging::getUsedMemory()));
    
    printNoReturn("system memory: ");
	printNoReturn(IntToStr(formatbytes(paging::getSystemMemory())));
    print(getByteFormat(paging::getSystemMemory()));
    
    paging::pageTable* PML4 = (paging::pageTable*)paging::requestPage();
    
    
    hello();
    
    print(IntToStr(ret1()), 0x0000ff);
    print("hell", 0xffffff);
    
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

    IRQ_set_all();
    init_serial();
    
    InitIDT();
    add_IRQ(ISA::KEYBOARD, isr1_handler, IDT_IG);
	
	add_IRQ(0xD, isr0xD, IDT_TG);
	add_IRQ(14, isr14, IDT_TG);


    //initRAMDISK();
    //restart();
    while(1) {   //mainloop
        ;
	}
    return;
}
