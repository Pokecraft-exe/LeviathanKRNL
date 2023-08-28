#include "IO.h"

void outb(unsigned short port, unsigned char val){
  asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

unsigned char inb(unsigned short port){
  unsigned char returnVal;
  asm volatile ("inb %1, %0"
  : "=a"(returnVal)
  : "Nd"(port));
  return returnVal;
}

void RemapPic(uint8_t master, uint8_t slave){

    uint8_t a1, a2;

    a1 = inb(PIC1_DATA);
    a2 = inb(PIC2_DATA);

    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);

    outb(PIC1_DATA, 0);
    outb(PIC2_DATA, 8);

    outb(PIC1_DATA, 4);
    outb(PIC2_DATA, 2);

    outb(PIC1_DATA, ICW4_8086);
    outb(PIC2_DATA, ICW4_8086);


    outb(PIC1_DATA, a1);
    outb(PIC2_DATA, a2);

    return;
}


void IRQ_set_mask(unsigned char IRQline) {
    uint16_t port;
    uint8_t value;
 
    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) | (1 << IRQline);
    outb(port, value);        
}
 
void IRQ_set_all(){
	for(int i = 0; i < 15; i++) {IRQ_set_mask(i);}
}
 
void IRQ_clear_mask(unsigned char IRQline) {
    uint16_t port;
    uint8_t value;
 
    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) & ~(1 << IRQline);
    outb(port, value);        
}

void IRQ_clear_all(){
	for(int i = 0; i < 15; i++) {IRQ_clear_mask(i);}
}

void NMI_enable() {
    outb(0x70, inb(0x70) & 0x7F);
    inb(0x71);
}
 
void NMI_disable() {
    outb(0x70, inb(0x70) | 0x80);
    inb(0x71);
}

void restart(){

    outb(0x64, 0xfe);

    asm("hlt");
}
