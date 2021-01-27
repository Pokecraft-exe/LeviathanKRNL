#include "H/sound.h"

void PlaySound(uint32 nFrequence) {
 	uint32 Div;
 	uint8 tmp;
 
 	Div = 1193180 / nFrequence;
 	outb(0x43, 0xb6);
 	outb(0x42, (uint8) (Div) );
 	outb(0x42, (uint8) (Div >> 8));
 
 	tmp = inb(0x61);
  	if (tmp != (tmp | 3)) {
 		outb(0x61, tmp | 3);
 	}
}

void noSound(){
 	uint8 tmp = inb(0x61) & 0xFC;
 
 	outb(0x61, tmp);
}

void beep(){
 	 PlaySound(1000);
	 delay(1000);
 	 noSound();
}