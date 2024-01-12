#include "IDT.h"

IDTR idtTable;

__attribute__((aligned(0x10)))
IDT64 IDTs[256];
  
void InitIDT(){
    idtTable.address = (uint64_t)&IDTs[0];
    idtTable.size = 0x0fff;

    asm("lidt %0" :: "m"(idtTable));
    asm ("sti");

    RemapPic(0x20,0b00000001);
}
  
void add_IRQ(uint8_t IRQ, void(*function)(interrupt_frame* frame), uint8_t gate) {
  	IRQ_clear_mask(IRQ);
	IDT64* newInterrupt = &IDTs[IRQ];
	newInterrupt->types_attr = 0b10000000 | gate;
	newInterrupt->codeseg = 0x8;
}

void add_IRQ(uint8_t IRQ, void(*function)(), uint8_t gate) {
  	IRQ_clear_mask(IRQ);	
	IDTs[IRQ].offset_low  = (uint16_t)(((uint64_t)function & 0x000000000000ffff));
	IDTs[IRQ].offset_mid  = (uint16_t)(((uint64_t)function & 0x00000000ffff0000) >> 16);
	IDTs[IRQ].offset_high = (uint32_t)(((uint64_t)function & 0xffffffff00000000) >> 32);
	
	IDTs[IRQ].types_attr = 0b10000000 | gate;
	IDTs[IRQ].codeseg = 0x8;
}

__attribute__((interrupt)) extern "C" void Schedule(interrupt_frame* frame) {
    	DrawChar('a', 500, 500, 0x00FF, 2);
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
	uint64_t errorcode = *rsp;
	cls(0x0000FF);
	std::stdin cout;
	
	cout.color(0);
	cout << "General protection fault!\nError code: 0x" << std::hex(errorcode) << std::endl;
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
	std::stdin cout;
	cout << "\0m[\0\0\0]PageFault!" << std::endl;
	asm("mov %cr2, %rax");
	gregister(rax);
	uint64_t* memory = (uint64_t*)rax;
	cout << "cr2 = " << (void*)memory << std::endl;
	cout << "memory dump at " << (void*)memory << std::endl;
	cout << std::hex(*memory-8) << std::hex(*memory) << std::hex(*memory=8) << std::endl;
	while(1);
};

int panic(CPUState state){
	DrawString("Your computer will restart after pressing a key...", 0, 8, 0xFF, 3);
	while(1);
	restart();
	return 0;
}
