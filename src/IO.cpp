#define STRINGIFY(x) # x
#define CONCAT(x, y) STRINGIFY( x ## y )
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

    outb(PIC1_COMMAND, 0x11);
    outb(PIC2_COMMAND, 0x11);

    outb(PIC1_DATA, master);
    outb(PIC2_DATA, slave);

    outb(PIC1_DATA, 4);
    outb(PIC2_DATA, 2);

    outb(PIC1_DATA, 1);
    outb(PIC2_DATA, 1);


    outb(PIC1_DATA, 0);
    outb(PIC2_DATA, 0);

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

Port8Bit::Port8Bit(uint16_t port){
    portnumber = port;
}
void Port8Bit::Write(uint8_t data){
    asm volatile ("outb %0, %1" : : "a"(data), "Nd"(portnumber));
}
uint8_t Port8Bit::Read(){
    uint8_t returnVal;
    asm volatile ("inb %1, %0"
    : "=a"(returnVal)
    : "Nd"(portnumber));
    return returnVal;
}

Port8BitSlow::Port8BitSlow(uint16_t port){
    portnumber = port;
}
void Port8BitSlow::Write(uint8_t data){
    asm volatile ("outb %0, %1\njmp 1f\n1: jmp 1f\n1:" : : "a"(data), "Nd"(portnumber));
}
uint8_t Port8BitSlow::Read(){
    uint8_t returnVal;
    asm volatile ("inb %1, %0"
    : "=a"(returnVal)
    : "Nd"(portnumber));
    return returnVal;
}

Port16Bit::Port16Bit(uint16_t port){
    portnumber = port;
}
void Port16Bit::Write(uint16_t data){
    asm volatile ("outw %0, %1" : : "a"(data), "Nd"(portnumber));
}
uint16_t Port16Bit::Read(){
    uint16_t returnVal;
    asm volatile ("inw %1, %0"
    : "=a"(returnVal)
    : "Nd"(portnumber));
    return returnVal;
}

Port32Bit::Port32Bit(uint16_t port){
    portnumber = port;
}
void Port32Bit::Write(uint32_t data){
    asm volatile ("outl %0, %1" : : "a"(data), "Nd"(portnumber));
}
uint32_t Port32Bit::Read(){
    uint32_t returnVal;
    asm volatile ("inl %1, %0"
    : "=a"(returnVal)
    : "Nd"(portnumber));
    return returnVal;
}
