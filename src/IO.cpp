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

/*CPUState GetState(){
  CPUState cpu;
  asm volatile ("mov %%eax, %[VAR]" : [VAR] "=r" (cpu.eax));
  asm volatile ("mov %%ebx, %[VAR]" : [VAR] "=r" (cpu.ebx));
  asm volatile ("mov %%ecx, %[VAR]" : [VAR] "=r" (cpu.ecx));
  asm volatile ("mov %%edx, %[VAR]" : [VAR] "=r" (cpu.edx));
 
  asm volatile ("mov %%esi, %[VAR]" : [VAR] "=r" (cpu.esi));
  asm volatile ("mov %%edi, %[VAR]" : [VAR] "=r" (cpu.edi));
  asm volatile ("mov %%ebp, %[VAR]" : [VAR] "=r" (cpu.ebp));

        //common::uint32_t gs;
        //common::uint32_t fs;
        //common::uint32_t es;
        //common::uint32_t ds;
        
  asm volatile ("mov %%cr0, %[VAR]" : [VAR] "=r" (cpu.cr0));
  asm volatile ("mov %%cr2, %[VAR]" : [VAR] "=r" (cpu.cr2));
  asm volatile ("mov %%cr3, %[VAR]" : [VAR] "=r" (cpu.cr3));
    
  asm volatile ("mov %%error, %[VAR]" : [VAR] "=r" (cpu.error));

  asm volatile ("mov %%eip, %[VAR]" : [VAR] "=r" (cpu.eip));
  asm volatile ("mov %%cs, %[VAR]" : [VAR] "=r" (cpu.cs));
  asm volatile ("mov %%eflags, %[VAR]" : [VAR] "=r" (cpu.eflags));
  asm volatile ("mov %%esp, %[VAR]" : [VAR] "=r" (cpu.esp));
  asm volatile ("mov %%ss, %[VAR]" : [VAR] "=r" (cpu.ss));
  return cpu;
}*/

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

void restart(){

    outb(0x64, 0xfe);

    asm("hlt");
}
