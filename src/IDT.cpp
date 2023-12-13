#include "IDT.h"

IDTR idtTable;
  
void InitIDT(){
    idtTable.address = (uint64_t*)paging::requestPage();
    idtTable.size = 0x0fff;
    
    asm ("lidt %0" :: "m"(idtTable));

    //RemapPic(0,0);
    
    //outb(0x21, 0xfd);//0b11111101);
    //outb(0xA1, 0xff);//0b11111111);
    
    //asm ("sti");
}
  
void add_IRQ(char IRQ, void(*function)(interrupt_frame* frame), uint8_t gate) {
  	//IRQ_clear_mask(IRQ);
	IDT64* newInterrupt = (IDT64*)(idtTable.address + IRQ * sizeof(IDT64));
	newInterrupt->Set_Offset((uint64_t)function);
	newInterrupt->types_attr = gate;
	newInterrupt->codeseg = 0x8;
}

__attribute__((interrupt)) void cmos(interrupt_frame* frame) {
	DrawChar('a', 500, 500, 0x00FF, 2);
	outb(0x20, 0x20);
	outb(0xa0, 0x20);
}
    
extern "C" __attribute__((naked)) void irq1(interrupt_frame* frame) {
	asm("push %rax \n\
    push %rbx\n\
    push %rcx\n\
    push %rdx\n\
    push %rbp\n\
    push %rdi\n\
    push %rsi\n\
    push %r8\n\
    push %r9\n\
    push %r10\n\
    push %r11\n\
    push %r12\n\
    push %r13\n\
    push %r14\n\
    push %r15\n\
    cld\n");
    isr1_handler(frame);
    asm("pop %r15\n\
	pop %r14\n\
	pop %r13\n\
	pop %r12\n\
	pop %r11\n\
	pop %r10\n\
	pop %r9\n\
	pop %r8\n\
	pop %rsi\n\
	pop %rdi\n\
	pop %rbp\n\
	pop %rdx\n\
	pop %rcx\n\
	pop %rbx\n\
	pop %rax\n\
    iretq");
}
    
extern "C" {
    void isr1_handler(interrupt_frame* frame){
        uint8_t scancode = inb(0x60);
		uint8_t chr = 0;
		
		if (scancode < 0x3A){
			chr = ScanCodeLookupTable[scancode];
		}
        //Keyboardhandler(scanCode);
        printchr(chr);
        outb(0x20, 0x20);
        outb(0xa0, 0x20);
    }
}


void print(char* str) {DrawString(str, 100, 100, 0xff, 2);}

__attribute__((interrupt)) void isr5(interrupt_frame* frame) {print("table overload");while(1);};
__attribute__((interrupt)) void isr6(interrupt_frame* frame) {
	cls(0x0000FF);
	DrawStringBackground("Fake instruction detected, abort!", 0, 8, 2, 0xFFFFFF, 0x0000FF, 1);
	while(1);
};
__attribute__((interrupt)) void isr7(interrupt_frame* frame) {print("FPU don't exist");while(1);};
__attribute__((interrupt)) void isr8(interrupt_frame* frame) {
	cls(0x0000FF);
	DrawStringBackground("Double fault!", 0, 8, 2, 0xFFFFFF, 0x0000FF, 1);
	DrawStringBackground("Error code:", 0, 24, 2, 0xFFFFFF, 0x0000FF, 1);
	DrawStringBackground(" 0x", 176, 24, 2, 0xFFFFFF, 0x0000FF, 1);
	DrawStringBackground(HexToString(frame->ip), 224, 24, 2, 0xFFFFFF, 0x0000FF, 1);
	while(1);
};
extern "C" __attribute__((naked)) void isr0xD(interrupt_frame* frame) {isr13(frame);};
void isr13(interrupt_frame* frame) {
	register uint64_t* rsp asm("rsp");
	cls(0x0000FF);
	DrawStringBackground("General protection fault!", 0, 8, 2, 0xFFFFFF, 0x0000FF, 1);
	DrawStringBackground("Error code:", 0, 24, 2, 0xFFFFFF, 0x0000FF, 1);
	DrawStringBackground(" 0x", 176, 24, 2, 0xFFFFFF, 0x0000FF, 1);
	DrawStringBackground(HexToString((uint64_t)*rsp), 224, 24, 2, 0xFFFFFF, 0x0000FF, 1);
	if (rsp != 0) {
		limine_memmap_entry* last = memmap::memmap.entries[0];
		for (size_t i = 1; i < memmap::memmap.entry_count; i++) {
			if ((uint64_t*)last->base < rsp && (uint64_t*)memmap::memmap.entries[i]->base > rsp) {
				DrawStringBackground(memmap::get_memory_type(last), 0, 48, 2, 0xFFFFFF, 0x0000FF, 1);
				break;
			}
		}
	}
	if(*rsp & 1) {
		DrawStringBackground("This error is external to the processor", 0, 40, 2, 0xFFFFFF, 0x0000FF, 1);
	} else {
	    DrawStringBackground("This error is internal to the processor", 0, 40, 2, 0xFFFFFF, 0x0000FF, 1);
	}
	while(inb(0x60) != 0x5E);
	restart();
};
__attribute__((interrupt)) void isr14(interrupt_frame* frame) {
	cls(0x0000FF);
	DrawStringBackground("Page fault!", 0, 8, 2, 0xFFFFFF, 0x0000FF, 1);
	asm("mov %cr2, %rax");
	gregister(rax);
	DrawStringBackground("cr2 =", 0, 24, 2, 0xFFFFFF, 0x0000FF, 1);
	DrawStringBackground(HexToString(rax), 224, 24, 2, 0xFFFFFF, 0x0000FF, 1);
	while(1);
};

int panic(CPUState state){
	DrawString("Your computer will restart after pressing a key...", 0, 8, 0xFF, 3);
	while(1);
	restart();
	return 0;
}
