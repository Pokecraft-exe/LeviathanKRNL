#include "H/IO.h"

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

void RemapPic(uint8 master, uint8 slave){

    uint8 a1, a2;

    a1 = inb(PIC1_DATA);
    a2 = inb(PIC2_DATA);

    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);

    outb(PIC1_DATA, master); // Remap the master pic (IRQs) to vector (master)
    outb(PIC2_DATA, slave); // Remap the slave pic (slave IRQs) to vector (slave)

    outb(PIC1_DATA, 4);
    outb(PIC2_DATA, 2);

    outb(PIC1_DATA, ICW4_8086);
    outb(PIC2_DATA, ICW4_8086);


    outb(PIC1_DATA, a1);
    outb(PIC2_DATA, a2);

    return;
}

void restart(void){

    outb(0x64, 0xfe);

    asm("hlt");
}