#pragma once
#include "typedefs.h"

#define PIC1_COMMAND 0x20
#define PIC1_DATA (uint16_t)0x21
#define PIC2_COMMAND 0xA0
#define PIC2_DATA (uint16_t)0xA1

#define ICW1_INIT 0x10
#define ICW1_ICW4 0x01
#define ICW4_8086 0x01

struct CPUState
    {
        uint32_t eax;
        uint32_t ebx;
        uint32_t ecx;
        uint32_t edx;

        uint32_t esi;
        uint32_t edi;
        uint32_t ebp;

        /*
        common::uint32_t gs;
        common::uint32_t fs;
        common::uint32_t es;
        common::uint32_t ds;
        */
        uint32_t cr0;
        uint32_t cr2;
        uint32_t cr3;
    
        uint32_t error;

        uint32_t eip;
        uint32_t cs;
        uint32_t eflags;
        uint32_t esp;
        uint32_t ss;        
    } __attribute__((packed));
    
void outb(unsigned short port, unsigned char val);
unsigned char inb(unsigned short port);
void RemapPic(uint8 master, uint8 slave);
CPUState GetState();
void restart();

class Port8Bit{
private:
    uint16_t portnumber;
public:
    Port8Bit(uint16_t port){
        portnumber = port;
    }
    void Write(uint8_t data){
        asm volatile ("outb %0, %1" : : "a"(data), "Nd"(portnumber));
    }
    uint8_t Read(){
        uint8_t returnVal;
        asm volatile ("inb %1, %0"
        : "=a"(returnVal)
        : "Nd"(portnumber));
        return returnVal;
    }
};

class Port8BitSlow{
private:
    uint16_t portnumber;
public:
    Port8BitSlow(uint16_t port){
        portnumber = port;
    }
    void Write(uint8_t data){
        asm volatile ("outb %0, %1\njmp 1f\n1: jmp 1f\n1:" : : "a"(data), "Nd"(portnumber));
    }
    uint8_t Read(){
        uint8_t returnVal;
        asm volatile ("inb %1, %0"
        : "=a"(returnVal)
        : "Nd"(portnumber));
        return returnVal;
    }
};

class Port16Bit{
private:
    uint16_t portnumber;
public:
    Port16Bit(uint16_t port){
        portnumber = port;
    }
    void Write(uint16_t data){
        asm volatile ("outw %0, %1" : : "a"(data), "Nd"(portnumber));
    }
    uint16_t Read(){
        uint16_t returnVal;
        asm volatile ("inw %1, %0"
        : "=a"(returnVal)
        : "Nd"(portnumber));
        return returnVal;
    }
};

class Port32Bit{
private:
    uint16_t portnumber;
public:
    Port32Bit(uint16_t port){
        portnumber = port;
    }
    void Write(uint32_t data){
        asm volatile ("outl %0, %1" : : "a"(data), "Nd"(portnumber));
    }
    uint32_t Read(){
        uint32_t returnVal;
        asm volatile ("inl %1, %0"
        : "=a"(returnVal)
        : "Nd"(portnumber));
        return returnVal;
    }
};