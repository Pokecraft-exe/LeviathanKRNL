#include "H/IDT.h"

void printK(const char* a){
	unsigned int i = 0;
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
	NO_ERROR_MODE();
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

int NO_ERROR_MODE(){
    //__BOOTSCREEN__();

    WindowMananger.NewWindow(0, 190, 320, 10, (char*)"", 0);
    //double windowing test
    WindowMananger.NewWindow(10, 25, 50, 100, (char*)"\n\r");
    KBmouse.x = 160;
    KBmouse.y = 100;
    //ctmouse(160, 100);
    WindowMananger.Refresh();
    puts("Refresh\r\n");
    /*physics Physics;
    Physics.setWater(200,50);
	Physics.setWater(201,51);
    Physics.iterate(2);*/
    //restart();
    while(1) {   //mainloop
        uint_8 scanCode = inb(0x60);
		uint_8 chr = 0;

		if (scanCode < 0x3A){
			chr = KBSet1::ScanCodeLookupTable[scanCode];
		}
		if (MainKeyboardHandler != 0) {
			MainKeyboardHandler(scanCode, chr);
		}
		write_serial(chr);
/*
        PlaySound(1043,MasterVolume);for (int i = 0; i<200000;i++);{}
        PlaySound(1570,MasterVolume);for (int ii = 0; ii<200000;ii++);{}
        PlaySound(1969,MasterVolume);for (int iii = 0; iii<200000;iii++);{}
        PlaySound(1477,MasterVolume);for (int iiii = 0; iiii<200000;iiii++);{}*/
        
	}
    return 1;
}