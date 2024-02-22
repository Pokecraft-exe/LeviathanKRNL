#include "printf.h"
#include "font.hpp"
#include "IDT.h"
#include "allocator.hpp"
#include "ahci.hpp"
/*#include "sound.h"
#include "mouse.h"
#include "Time.h"*/
#include "serial.h"
#include "memmap.hpp"
#include "paging.hpp"
#include "kernel.h"
#include "stdio"
#include "lalgorythm"
#include "color.hpp"
#include "pit.hpp"
#include "pci.hpp"
#include "scheduler.hpp"
#include "shell.hpp"
using std::cout, std::cin;

extern IDTR idtTable;
extern IDT64 IDTs;

extern "C" void detectFPU();
extern "C" void detectSSE();
extern "C" void enableAVX();
extern "C" uint32_t fpuPresent;
extern "C" bool ssePresent;
extern "C" void hello();

uint16_t CursorPosition = 0;
bool CursorShown = false;

int cursorpos[2] = { 0, 0 };

bool sort(int a, int b) {
    return a < b;
}

int breakpoint(){ return 1; }

extern "C" void start_K(){

    VGA_WIDTH = framebuffer->width/16;

    cout.color(0XFFFFFF);

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
    
    detectFPU();
    if (fpuPresent == 0) {
        cout << "FPU [\0m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;
    } else {
        cout << "FPU [\0m[\xff\x00\x00]Not present or enabled\x00m[\xff\xff\xff]]]" << std::endl;
        while(1);
    }
    
    detectSSE();
    if (fpuPresent == 0) {
        cout << "SSE [\0m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;
    } else {
        cout << "SSE [\0m[\xff\x00\x00]Not present\x00m[\xff\xff\xff]]]" << std::endl;
        while(1);
    }
    
    //enableAVX();
	
	add_IRQ(0, (void*)&isr0, IDT_IG);
	add_IRQ(1, (void*)&isr1, IDT_IG);
	add_IRQ(2, (void*)&isr2, IDT_IG);
	add_IRQ(3, (void*)&isr3, IDT_IG);
	add_IRQ(4, (void*)&isr4, IDT_IG);
	add_IRQ(5, (void*)&isr5, IDT_IG);
	add_IRQ(6, (void*)&isr6, IDT_IG);
	add_IRQ(7, (void*)&isr7, IDT_IG);
	add_IRQ(8, (void*)&isr8, IDT_IG);
	add_IRQ(9, (void*)&isr9, IDT_IG);
	add_IRQ(10, (void*)&isr10, IDT_IG);
	add_IRQ(11, (void*)&isr11, IDT_IG);
	add_IRQ(12, (void*)&isr12, IDT_IG);
	add_IRQ(13, (void*)&isr13, IDT_IG);
	add_IRQ(14, (void*)&isr14, IDT_IG);
	add_IRQ(15, (void*)&isr16, IDT_IG);
	add_IRQ(17, (void*)&isr17, IDT_IG);
	add_IRQ(18, (void*)&isr18, IDT_IG);
	add_IRQ(19, (void*)&isr19, IDT_IG);
	add_IRQ(20, (void*)&isr20, IDT_IG);
	add_IRQ(21, (void*)&isr21, IDT_IG);
	add_IRQ(28, (void*)&isr28, IDT_IG);
	add_IRQ(29, (void*)&isr29, IDT_IG);
	add_IRQ(30, (void*)&isr30, IDT_IG);
    
    add_IRQ(ISA::PIT, (void*)&SchedulerHandler, IDT_IG);
    add_IRQ(ISA::KEYBOARD, (void*)keyboardHandler, IDT_IG);
    //add_IRQ(ISA::PS2, (void*)mouseHandler, IDT_IG);

    // mouse init
    /*outb(0xD4, 0x64);
    outb(0xF3, 0x60);
    while(!(inb(0x64) & 1));
    uint8_t ack = inb(0x60);
    outb(0xD4, 0x64);
    outb(100, 0x60);
    while(!(inb(0x64) & 1));
    ack = inb(0x60);

    if (ack == 0xFA) {
        cout << "Mouse [\0m[\x00\xff\x00]Correct\x00m[\xff\xff\xff]]]" << std::endl;
    } else {
        cout << "Mouse [\0m[\xff\x00\x00]Not present\x0 0m[\xff\xff\xff]]]" << std::endl;
    }*/

    cout << sizeof(TaskManager::Task) << std::endl;
    cout << (void*)&shell << std::endl;

    command.resize(100);

    //memset(TaskManager::tasks, 0, 409600);

    TaskManager::Task* initializeScheduler = TaskManager::Thread(nullptr, nullptr, 0); // init scheduling

    TaskManager::Task* shellThread = TaskManager::Thread((void*)&shell, nullptr, 0);
      
    InitIDT();

    timer::PIT::init(1);

    //initializeScheduler->abort();
    shellThread->start();

    //_hRAMDISK();

    shellThread->join();
}