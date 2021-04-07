#include "H/IDT.h"

void(*MainKeyboardHandler)(uint_8 scanCode, uint_8 chr);
__attribute__((interrupt)) void isr1_handler(struct interrupt_frame* frame){
	uint_8 scanCode = inb(0x60);
	uint_8 chr = 0;

	if (scanCode < 0x3A){
		chr = KBSet1::ScanCodeLookupTable[scanCode];
	}
	if (MainKeyboardHandler != 0) {
		MainKeyboardHandler(scanCode, chr);
	}
	DeskColor(CYAN);
	write_serial(chr);
	outb(0x20, 0x20);
	outb(0xa0, 0x20);
}