#include "IDT.h"

IDTR idtTable;
IDT64 IDTA[IDT_EntryCount];
  
void InitIDT(){
    idtTable.address = (uint64_t*)IDTA;
    idtTable.size = sizeof(IDT64) * IDT_EntryCount;
    
    asm ("lidt %0" :: "m"(idtTable));

    RemapPic(0,0);
    
    outb(0x21, 0xfd);//0b11111101);
    outb(0xA1, 0xff);//0b11111111);
    
    asm ("sti");
}
  
void add_IRQ(char IRQ, void(*function)(interrupt_frame*), uint8_t gate) {
  	IRQ_clear_mask(IRQ);
	IDTA[IRQ].Set_Offset((uint64_t)function);
	IDTA[IRQ].types_attr = gate;
	IDTA[IRQ].codeseg = 0x8;
}

__attribute__((interrupt)) void cmos(interrupt_frame* frame) {
	DrawChar('a', 500, 500, 0x00FF, 2);
	outb(0x20, 0x20);
	outb(0xa0, 0x20);
}

__attribute__((interrupt)) void isr1_handler(interrupt_frame* frame){
	uint8_t scanCode = inb(0x60);
	uint8_t chr = 0;
	
	if (scanCode < 0x3A){
		chr = ScanCodeLookupTable[scanCode];
	} else {
		Keyboardhandler(scanCode, chr);
	}
	DrawChar(chr, 0, 30, 0xFFFFFF, 2);
	outb(0x20, 0x20);
	outb(0xa0, 0x20);
	asm("iret");
}

void print(char* str) {DrawString(str, 100, 100, 0xff, 2);}

__attribute__((interrupt)) void isr0(interrupt_frame* frame) {print("div by 0");while(1);};
__attribute__((interrupt)) void isr4(interrupt_frame* frame) {print("overload");while(1);};
__attribute__((interrupt)) void isr5(interrupt_frame* frame) {print("table overload");while(1);};
__attribute__((interrupt)) void isr6(interrupt_frame* frame) {print("fake instruction");while(1);};
__attribute__((interrupt)) void isr7(interrupt_frame* frame) {print("FPU don't exist");while(1);};
__attribute__((interrupt)) void isr8(interrupt_frame* frame) {print("double fault");while(1);};
__attribute__((interrupt)) void isr13(interrupt_frame* frame) {print("GPF");while(1);};
__attribute__((interrupt)) void isr14(interrupt_frame* frame) {print("Page Fault");while(1);};

int panic(CPUState state){
	DrawString("Your computer will restart after pressing a key...", 0, 8, 0xFF, 3);
	//write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('▄');write_serial(' ');write_serial(' ');write_serial(' ');write_serial(' ');write_serial(' ');write_serial('▄');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▀');write_serial('█');write_serial('▄');write_serial('█');write_serial('▀');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▄');write_serial('▀');write_serial('█');write_serial(' ');write_serial(' ');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('█');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial('█');write_serial('█');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▀');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial(' ');write_serial(' ');write_serial('▄');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('█');write_serial('█');write_serial('█');write_serial(' ');write_serial('█');write_serial('\n');write_serial('\r');write_serial('█');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▀');write_serial('█');write_serial('▀');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('█');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('█');write_serial('\n');write_serial('\r');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('█');write_serial('▀');write_serial('▄');write_serial('█');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('▄');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('\n');write_serial('\r');write_serial('█');write_serial('▄');write_serial('▀');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('█');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('█');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('▀');write_serial('█');write_serial('▄');write_serial('▀');write_serial('█');write_serial('█');write_serial(' ');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial('▀');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▄');write_serial('█');write_serial('▄');write_serial('█');write_serial('▀');write_serial('█');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('▄');write_serial('█');write_serial(' ');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▀');write_serial('▀');write_serial(' ');write_serial('█');write_serial('▄');write_serial('▀');write_serial(' ');write_serial('\n');write_serial('\r');write_serial('▀');write_serial(' ');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▀');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('▀');write_serial(' ');write_serial('▀');write_serial('█');write_serial('█');write_serial('▄');write_serial(' ');write_serial('▄');write_serial('▀');write_serial(' ');write_serial('▀');write_serial('▀');write_serial('█');write_serial('▀');write_serial('▀');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('▀');write_serial('\n');write_serial('\r');write_serial('▀');write_serial('▄');write_serial('█');write_serial('▀');write_serial(' ');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('█');write_serial('▀');write_serial('█');write_serial(' ');write_serial('█');write_serial('▀');write_serial('▄');write_serial('█');write_serial('█');write_serial('▄');write_serial('█');write_serial('▄');write_serial('▀');write_serial('▀');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('▄');write_serial('▄');write_serial('▀');write_serial(' ');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial('█');write_serial('▄');write_serial('█');write_serial('▄');write_serial('▄');write_serial('▀');write_serial('▀');write_serial('▀');write_serial(' ');write_serial('▄');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('█');write_serial('▀');write_serial(' ');write_serial(' ');write_serial(' ');write_serial('█');write_serial('▀');write_serial('▀');write_serial('█');write_serial('▀');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▀');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('█');write_serial('█');write_serial('▄');write_serial('█');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('▄');write_serial('█');write_serial('▄');write_serial(' ');write_serial('█');write_serial('█');write_serial('▄');write_serial('█');write_serial('█');write_serial('▄');write_serial(' ');write_serial('▄');write_serial('█');write_serial('▄');write_serial('\n');write_serial('\r');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▀');write_serial('█');write_serial('█');write_serial('▄');write_serial('█');write_serial('█');write_serial('▀');write_serial('▄');write_serial('█');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('█');write_serial('█');write_serial('█');write_serial('▀');write_serial('▀');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▀');write_serial(' ');write_serial('█');write_serial('▀');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▀');write_serial(' ');write_serial('█');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▀');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial('█');write_serial('█');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('█');write_serial('▄');write_serial('█');write_serial('▄');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('▄');write_serial('▀');write_serial('▀');write_serial('▄');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('█');write_serial('█');write_serial('█');write_serial('▀');write_serial('\n');write_serial('\r');write_serial('█');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('█');write_serial(' ');write_serial('█');write_serial('▄');write_serial(' ');write_serial('█');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('█');write_serial('█');write_serial(' ');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('▄');write_serial('▄');write_serial('▀');write_serial('▄');write_serial('▀');write_serial(' ');write_serial('\n');write_serial('\r');
	while(1);
	restart();
	return 0;
}
