#include "IO.cpp"

extern IDT64 _idt[256];
extern uint_64 isr1;
extern uint_64 irq12;
extern "C" void LoadIDT();

int IRQ_offset = 80;

void(*MainKeyboardHandler)(uint_8 scanCode, uint_8 chr);

void InitIDT(){
	InitISR(1, &isr1, 0, 0x08, 0x8e);
	InitIRS(12, &irq12, 0, 0x08, 0x8e);
	RemapPic(IRQ_offset, IRQ_offset+8);
	outb(PIC1_DATA, 0b11111101);
	outb(PIC2_DATA, 0b11101111);
	LoadIDT();
}

void InitISR(uint8 num, void * handler, uint8 ist, uint16 selector, uint8 attributes){
  	_idt[num].zero = 0;
	_idt[num].offset_low = (uint16)(((uint64) handler & 0x000000000000ffff));
	_idt[num].offset_mid = (uint16)(((uint64) handler & 0x00000000ffff0000) >> 16);
	_idt[num].offset_high = (uint32)(((uint64) handler & 0xffffffff00000000) >> 32);
	_idt[num].ist = ist;
	_idt[num].selector = selector;
	_idt[num].types_attr = attributes;
	return;
}

void installIRQ(uint8 IRQ, void *handler, uint8 ist, uint16 selector, uint8 attributes)
{
	InitISR(IRQ+IRQ_offset, handler, ist, selector, attributes);
	return;
}

extern "C" void isr1_handler(){
	/*uint_8 scanCode = inb(0x60);
	uint_8 chr = 0;

	if (scanCode < 0x3A){
		chr = KBSet1::ScanCodeLookupTable[scanCode];
	}
	if (MainKeyboardHandler != 0) {
		MainKeyboardHandler(scanCode, chr);
	}

	outb(0x20, 0x20);
	outb(0xa0, 0x20);*/
}

extern "C" void irq12_handler(){
	//mouse
}
