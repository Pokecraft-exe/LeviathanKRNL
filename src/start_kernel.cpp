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
#include "algorythm"
#include "color.hpp"
#include "pit.hpp"

extern "C" void Draw(int, int, uint32_t);

extern "C" void DrawSquare(int x, int y, int size_x, int size_y, uint32_t color);

void delay(int clocks)
{
    asm("push %rax");
    for(uint64_t i = 0; i < clocks; i+=8){
        asm("xor %rax, %rax");
    }
    asm("pop %rax");
    return;
}

extern "C" void breakpoint(){
    puts("breakpoint\n\r");
    while (read_serial() != '\r');
}

uint16_t CursorPosition = 0;

extern "C" void hello();

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

bool sort(int a, int b) {
    return a < b;
}

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

    void* a = alloc(100);
    void* b = alloc(1);

    if (a == b - 100) {
        cout << "Allocator [\0m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;
    } else {
        cout << "Allocator [\0m[\xff\x00\x00]Error\x00m[\xff\xff\xff]]]" << std::endl;
    }

    //paging::editPages((uintptr_t*)&kernelStart, (kernelSize / 4096) + 1, PAGING_RESERVE_PAGE);

    cout << "\0m[\xff\xff\x00]\n";

    cout << "free memory: " << formatbytes(paging::getFreeMemory()) << getByteFormat(paging::getFreeMemory()) << std::endl;
    
    cout << "used memory: " << formatbytes(paging::getUsedMemory()) << getByteFormat(paging::getUsedMemory()) << std::endl;
    
    cout << "system memory: " << formatbytes(paging::getSystemMemory()) << getByteFormat(paging::getSystemMemory()) << std::endl;
    
    paging::pageTable* PML4 = (paging::pageTable*)paging::requestPage();
    
    cout << "PML4 = 0x" << (void*)PML4 << std::endl;
    
    
    memset(PML4, 0, 0x1000);

    /*{
        paging::pageManager::setPML4(PML4);

        for (size_t i = 0; i < memory_size - 0x2000; i += 0x1000) {
            paging::pageManager::mapMemory((void*)i, (void*)i);
        }
        asm ("mov %0, %%cr3" : : "r" (PML4));
    }*/

    cout.color(0xffffff);
    cout << "Paging [\0m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;

	DrawSquare(200, 200, 200, 300, 0xffff00);

    InitIDT();
    
    timer::PIT::init(1000);
     
    add_IRQ(ISA::PIT, pit_handler, IDT_IG);
    
    while(1);

cout << "HELL YEAH WE PASSED!!";

    add_IRQ(ISA::PIT, IRQ0_handler, 0x8e);

    //_hRAMDISK();
    //restart();
    while(1) {   //mainloop
        ;
	}
    return;
}
