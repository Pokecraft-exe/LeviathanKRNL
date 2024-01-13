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

extern IDTR idtTable;
extern IDT64 IDTs;
extern void** exception_handlers;

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

    VGA_WIDTH = framebuffer->width/16;
    
    std::stdin cout;

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
        cout << "Memory Size [\x00m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;
    } else {
        cout << "Memory Size [\x00m[\xff\x00\x00]Error\x00m[\xff\xff\xff]]]" << std::endl;
        while(1);
    }

    void* a = alloc(100);
    void* c = alloc(100);
    void* b = alloc(1);
    free(c);
    void* d = alloc(2);

    if (a == d - 800) {
        cout << "Allocator [\0m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;
        free(a);
        free(b);
        free(d);
    } else {
        cout << "Allocator [\0m[\xff\x00\x00]Error\x00m[\xff\xff\xff]]]" << std::endl;
        dumpChunks();
        extern Chunk_List alloced_chunks;
        cout << "chunks count: " << alloced_chunks.count;
        while(1);
    }
    
    KEY = (char*)alloc(1);

    cout << "\0m[\xff\xff\x00]\n";

    cout << "free memory: " << formatbytes(paging::getFreeMemory()) << getByteFormat(paging::getFreeMemory()) << std::endl;
    
    cout << "used memory: " << formatbytes(paging::getUsedMemory()) << getByteFormat(paging::getUsedMemory()) << std::endl;
    
    cout << "system memory: " << formatbytes(paging::getSystemMemory()) << getByteFormat(paging::getSystemMemory()) << std::endl;

	DrawSquare(200, 400, 200, 300, 0xffff00);
	
    for(int i = 0; i <= 31; i++) {
      add_IRQ(ISA::PIT, exception_handlers[i], IDT_TG);
    }
    
    add_IRQ(ISA::PIT, (void*)pit_handler, IDT_IG);

    InitIDT();
    
    //asm("int $0xe;");
      
    timer::PIT::init(1000);
    
    cout.color(0xffffff);
    cout << "hello to pit";

    //_hRAMDISK();
    while(1); //mainloop
}
