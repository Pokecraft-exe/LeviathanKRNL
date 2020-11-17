#include "H/sound.h"
 //Play sound using built in speaker
 static void PlaySound(uint32 nFrequence) {
 	uint32 Div;
 	uint8 tmp;
 
        //Set the PIT to the desired frequency
 	Div = 1193180 / nFrequence;
 	outb(0x43, 0xb6);
 	outb(0x42, (uint8) (Div) );
 	outb(0x42, (uint8) (Div >> 8));
 
        //And play the sound usiinitPITng the PC speaker
 	tmp = inb(0x61);
  	if (tmp != (tmp | 3)) {
 		outb(0x61, tmp | 3);
 	}
 }
 
 //make it shutup
 static void noSound() {
 	uint8 tmp = inb(0x61) & 0xFC;
 
 	outb(0x61, tmp);
 }
 
 //Make a beep
 void beep(int time) {
 	 PlaySound(1000);
	 //slee(10);
 	 noSound();
          //set_PIT_2(old_frequency);
 }
