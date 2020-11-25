#include "H/IDT.h"

extern IDT64 _idt[256];
extern uint_64 isr1;
extern uint_64 isr12;
extern "C" void LoadIDT();

void(*MainKeyboardHandler)(uint_8 scanCode, uint_8 chr);

void InitIDT(){
    //for (int i = 0; i <= 256, i++ ;){
	    _idt[1].zero = 0;
	    _idt[1].offset_low = (uint_16)(((uint_64)&isr1 & 0x000000000000ffff));
	    _idt[1].offset_mid = (uint_16)(((uint_64)&isr1 & 0x00000000ffff0000) >> 16);
	    _idt[1].offset_high = (uint_32)(((uint_64)&isr1 & 0xffffffff00000000) >> 32);
	    _idt[1].ist = 0;
	    _idt[1].selector = 0x08;
	    _idt[1].types_attr = 0x8e;
	    _idt[12].zero = 0;
	    _idt[12].offset_low = (uint_16)(((uint_64)&isr12 & 0x000000000000ffff));
	    _idt[12].offset_mid = (uint_16)(((uint_64)&isr12 & 0x00000000ffff0000) >> 16);
	    _idt[12].offset_high = (uint_32)(((uint_64)&isr12 & 0xffffffff00000000) >> 32);
	    _idt[12].ist = 0;
	    _idt[12].selector = 0x08;
	    _idt[12].types_attr = 0x8e;

	    RemapPic();
    //}
    outb(PIC1_DATA, 0b11111101);
    outb(PIC2_DATA, 0b11101111);
	LoadIDT();
}

extern "C" void isr1_handler(){
	uint_8 scanCode = inb(0x60);
	uint_8 chr = 0;

	if (scanCode < 0x3A){
		chr = KBSet1::ScanCodeLookupTable[scanCode];
	}
	if (MainKeyboardHandler != 0) {
		MainKeyboardHandler(scanCode, chr);
	}

	outb(0x20, 0x20);
	outb(0xa0, 0x20);
}

extern "C" void isr12_handler(){
    uint_8 offset = 0;
    uint_8 buttons = 0;
    uint_8 buffer[3];
    uint_8 status = inb(0x60);
    if(!(status & 0x20)){}
    static int8 x=40,y=12;
    buffer[offset] = inb(0x60);
    offset = (offset+1) % 3;
    if (offset == 0){
        x=buffer[1];
        if (x < 0) x = 0;
        if (x >= 80) x = 79;
        y=buffer[2];
        if (y < 0) y = 0;
        if (y >= 25) y = 24;
		ctmouse(x, y);
    }
	outb(0x20, 0x20);
	outb(0xa0, 0x20);
}
