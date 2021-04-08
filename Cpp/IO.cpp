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

CPUState GetState(){
  CPUState CPU;
  CPU.eax = asm("eax");
  CPU.ebx = asm("abx");
  CPU.ecx = asm("ecx");
  CPU.edx = asm("edx");
  CPU.esi = asm("esi");
  CPU.edi = asm("edi");
  CPU.ebp = asm("abp");

  CPU.cr0 = asm("cr0");
  CPU.cr2 = asm("cr2");
  CPU.cr3 = asm("cr3");
    
  CPU.error = asm("error");

  CPU.eip = asm("eip");
  CPU.cs = asm("cs");
  CPU.eflags = asm("eflags");
  CPU.esp = asm("esp");
  CPU.ss = asm("ss");
  return CPU;
}

void RemapPic(uint8 master, uint8 slave){

    uint8 a1, a2;

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

void restart(){

    outb(0x64, 0xfe);

    asm("hlt");
}