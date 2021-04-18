#include "H/IDT.h"

void printK(const char* a){
	unsigned int i;
	while (a[i] != '\0'){
		write_serial(a[i]);
		write_serial('c');
		i++;
	}
}

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

int panic(CPUState state){
	//for (int i=0;qrcode[i]!='\0';i++) write_serial(qrcode[i]
	printK("hello world!");
	write_serial('Y');
	write_serial('o');
	write_serial('u');
	write_serial('r');
	write_serial(' ');
	write_serial('c');
	write_serial('o');
	write_serial('m');
	write_serial('p');
	write_serial('u');
	write_serial('t');
	write_serial('e');
	write_serial('r');
	write_serial(' ');
	write_serial('w');
	write_serial('i');
	write_serial('l');
	write_serial('l');
	write_serial(' ');
	write_serial('r');
	write_serial('e');
	write_serial('s');
	write_serial('t');
	write_serial('a');
	write_serial('r');
	write_serial('t');
	write_serial(' ');
	write_serial('w');
	write_serial('h');
	write_serial('e');
	write_serial('n');
	write_serial(' ');
	write_serial('y');
	write_serial('o');
	write_serial('u');
	write_serial(' ');
	write_serial('p');
	write_serial('r');
	write_serial('e');
    write_serial('s');
	write_serial('s');
	write_serial(' ');
	write_serial('a');
	write_serial(' ');
	write_serial('k');
	write_serial('e');
	write_serial('y');
	write_serial('.');
	write_serial('.');
	write_serial('.');
	write_serial('\n');
	write_serial('\r');
	//write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('▄');write_serial(' ');write_serial(' ');write_serial(' ');write_serial(' ');write_serial(' ');write_serial('▄');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▀');write_serial('█');write_serial('▄');write_serial('█');write_serial('▀');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▄');write_serial('▀');write_serial('█');write_serial(' ');write_serial(' ');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('█');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial('█');write_serial('█');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▀');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial(' ');write_serial(' ');write_serial('▄');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('█');write_serial('█');write_serial('█');write_serial(' ');write_serial('█');write_serial('\n');write_serial('\r');write_serial('█');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▀');write_serial('█');write_serial('▀');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('█');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('█');write_serial('\n');write_serial('\r');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('█');write_serial('▀');write_serial('▄');write_serial('█');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('▄');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('\n');write_serial('\r');write_serial('█');write_serial('▄');write_serial('▀');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('█');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('█');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('▀');write_serial('█');write_serial('▄');write_serial('▀');write_serial('█');write_serial('█');write_serial(' ');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial('▀');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▄');write_serial('█');write_serial('▄');write_serial('█');write_serial('▀');write_serial('█');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('▄');write_serial('█');write_serial(' ');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▀');write_serial('▀');write_serial(' ');write_serial('█');write_serial('▄');write_serial('▀');write_serial(' ');write_serial('\n');write_serial('\r');write_serial('▀');write_serial(' ');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▀');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('▀');write_serial(' ');write_serial('▀');write_serial('█');write_serial('█');write_serial('▄');write_serial(' ');write_serial('▄');write_serial('▀');write_serial(' ');write_serial('▀');write_serial('▀');write_serial('█');write_serial('▀');write_serial('▀');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('▀');write_serial('\n');write_serial('\r');write_serial('▀');write_serial('▄');write_serial('█');write_serial('▀');write_serial(' ');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('█');write_serial('▀');write_serial('█');write_serial(' ');write_serial('█');write_serial('▀');write_serial('▄');write_serial('█');write_serial('█');write_serial('▄');write_serial('█');write_serial('▄');write_serial('▀');write_serial('▀');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('▄');write_serial('▄');write_serial('▀');write_serial(' ');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial('█');write_serial('▄');write_serial('█');write_serial('▄');write_serial('▄');write_serial('▀');write_serial('▀');write_serial('▀');write_serial(' ');write_serial('▄');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('█');write_serial('▀');write_serial(' ');write_serial(' ');write_serial(' ');write_serial('█');write_serial('▀');write_serial('▀');write_serial('█');write_serial('▀');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▀');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('█');write_serial('█');write_serial('▄');write_serial('█');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('▄');write_serial('█');write_serial('▄');write_serial(' ');write_serial('█');write_serial('█');write_serial('▄');write_serial('█');write_serial('█');write_serial('▄');write_serial(' ');write_serial('▄');write_serial('█');write_serial('▄');write_serial('\n');write_serial('\r');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▀');write_serial('█');write_serial('█');write_serial('▄');write_serial('█');write_serial('█');write_serial('▀');write_serial('▄');write_serial('█');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('█');write_serial('█');write_serial('█');write_serial('▀');write_serial('▀');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial(' ');write_serial('█');write_serial(' ');write_serial('▄');write_serial(' ');write_serial('▀');write_serial(' ');write_serial('█');write_serial('▀');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▀');write_serial(' ');write_serial('█');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▀');write_serial('\n');write_serial('\r');write_serial('█');write_serial(' ');write_serial('█');write_serial('█');write_serial('█');write_serial(' ');write_serial('█');write_serial(' ');write_serial('█');write_serial('▄');write_serial('█');write_serial('▄');write_serial('▄');write_serial(' ');write_serial(' ');write_serial('▄');write_serial('▀');write_serial('▀');write_serial('▄');write_serial('█');write_serial(' ');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('█');write_serial('█');write_serial('█');write_serial('▀');write_serial('\n');write_serial('\r');write_serial('█');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('▄');write_serial('█');write_serial(' ');write_serial('█');write_serial('▄');write_serial(' ');write_serial('█');write_serial(' ');write_serial(' ');write_serial('▀');write_serial('█');write_serial('█');write_serial(' ');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('▄');write_serial('▀');write_serial('▄');write_serial('▄');write_serial('▀');write_serial('▄');write_serial('▀');write_serial(' ');write_serial('\n');write_serial('\r');
	while(read_serial() == '\0')continue;
	restart();
	return 0;
}

__attribute__((interrupt)) void pagefault(struct interrupt_frame* frame){
	write_serial('\033');
	write_serial('[');
	write_serial('1');
	write_serial(';');
	write_serial('3');
	write_serial('1');
	write_serial('m');
	write_serial('p');
	write_serial('a');
	write_serial('g');
	write_serial('e');
	write_serial(' ');
	write_serial('f');
	write_serial('a');
	write_serial('u');
	write_serial('l');
	write_serial('t');
	write_serial('!');
	write_serial('\n');
	write_serial('\r');
	panic(GetState());
	while(true);
}