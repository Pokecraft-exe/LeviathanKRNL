#pragma once
#include "typedefs.cpp"
#include "KBScanCodeSet1.cpp"
#include "IO.cpp"
#include "printf.cpp"

struct IDT64{
  uint_16 offset_low;
  uint_16 selector;
  uint_8 ist;
  uint_8 types_attr;
  uint_16 offset_mid;
  uint_32 offset_high;
  uint_32 zero;
};

extern IDT64 _idt[256];
extern uint_64 isr1;
extern "C" void LoadIDT();

void InitIDT(){
    for (int i = 0; i <= 256, i++ ;){
	    _idt[i].zero = 0;
	    _idt[i].offset_low = (uint_16)(((uint_64)&isr1 & 0x000000000000ffff));
	    _idt[i].offset_mid = (uint_16)(((uint_64)&isr1 & 0x00000000ffff0000) >> 16);
	    _idt[i].offset_high = (uint_32)(((uint_64)&isr1 & 0xffffffff00000000) >> 32);
	    _idt[i].ist = 0;
	    _idt[i].selector = 0x08;
	    _idt[i].types_attr = 0x8e;

	    RemapPic();
    }
	outb(0x21, 0xfd);
	outb(0xa1, 0xff);
	LoadIDT();
}

void(*MainKeyboardHandler)(uint_8 scanCode, uint_8 chr);

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

byte mouse_cycle=0;     
sbyte mouse_byte[3];    
sbyte mouse_x=0;        
sbyte mouse_y=0;         

//Mouse.inc by SANiK
//License: Use as you wish, except to cause damage

extern "C" void isr12_handler(){
  printf("hello");
  switch(mouse_cycle)
  {
    case 0:
      mouse_byte[0]=inb(0x60);
      mouse_cycle++;
      break;
    case 1:
      mouse_byte[1]=inb(0x60);
      mouse_cycle++;
      break;
    case 2:
      mouse_byte[2]=inb(0x60);
      
      
      mouse_x = mouse_byte[1];
      mouse_y = mouse_byte[2];
      mouse_cycle=0;
      break;
    default:
      break;
  }
    printf(IntToStr(mouse_x));
	outb(0x20, 0x20);
	outb(0xa0, 0x20);
}
