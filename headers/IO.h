#pragma once
#ifndef IO
#define IO

#include <stdint.h>

#define PIC1_COMMAND 0x20
#define PIC1_DATA (uint16_t)0x21
#define PIC2_COMMAND 0xA0
#define PIC2_DATA (uint16_t)0xA1

#define ICW1_INIT 0x10
#define ICW1_ICW4 0x01
#define ICW4_8086 0x01
#define StackP 0x7bff

#define gregister(x) register uint64_t x asm(#x)
#define sregister(x, y) asm("mov" %0 ", " #x : "r"(y))

extern "C" void pusha();
extern "C" void popa();

struct CPUState {
    	uint64_t rax;
        uint64_t rbx;
        uint64_t rcx;
        uint64_t rdx;
        
        uint16_t ax;
        uint16_t bx;
        uint16_t cx;
        uint16_t dx;

        uint64_t rsi;
        uint64_t rdi;
        uint64_t rbp;
        
        uint64_t cr0;
        uint64_t cr2;
        uint64_t cr3;
        uint64_t cr4;
        uint64_t cr8;
    
        uint64_t error;

        uint64_t rip;
        uint16_t cs;
        uint16_t ds;
		uint16_t es;
		uint16_t fs;
		uint16_t gs;
        uint64_t rflags;
        uint64_t rsp;
        uint16_t ss; 
} __attribute__((packed));

    
class Port8Bit{
private:
    uint16_t portnumber;
public:
    Port8Bit(uint16_t port);
    void Write(uint8_t data);
    uint8_t Read();
};

class Port8BitSlow{
private:
    uint16_t portnumber;
public:
    Port8BitSlow(uint16_t port);
    void Write(uint8_t data);
    uint8_t Read();
};

class Port16Bit{
private:
    uint16_t portnumber;
public:
    Port16Bit(uint16_t port);
    void Write(uint16_t data);
    uint16_t Read();
};

class Port32Bit{
private:
    uint16_t portnumber;
public:
    Port32Bit(uint16_t port);
    void Write(uint32_t data);
    uint32_t Read();
};


    
void outb(unsigned short port, unsigned char val);
unsigned char inb(unsigned short port);
void RemapPic(uint8_t master, uint8_t slave);
void IRQ_set_mask(unsigned char IRQline);
void IRQ_set_all();
void IRQ_clear_mask(unsigned char IRQline);
void IRQ_clear_all();
void restart();
void NMI_enable();
void NMI_disable();
extern "C" uint64_t gcr2();

#endif
