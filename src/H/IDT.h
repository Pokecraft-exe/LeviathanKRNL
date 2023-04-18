#pragma once

#ifndef IDT
#define IDT

#include "IO.h"
#include "printf.h"
#include "lalloc.h"
#define IDT_IG 0b10001110
#define IDT_TG 0b10001111

enum ISA {
	PIT,
	KEYBOARD,
	CASCADE,
	COM2,
	COM1,
	LPT2,
	FLOPPY,
	LPT1,
	CMOS,
	FFP1,
	FFP2,
	FFP3,
	PS2,
	FPU,
	PRIMARY_ATA,
	SECONDARY_ATA
};

struct IDT64{
  uint16_t offset_low;
  uint16_t selector;
  uint8_t ist;
  uint8_t types_attr;
  uint16_t offset_mid;
  uint32_t offset_high;
  uint32_t zero;
  void Set_Offset(uint64_t Offset){
    offset_low= (uint16_t)(Offset & 0x000000000000ffff);
    offset_mid= (uint16_t)((Offset & 0x00000000ffff0000) >> 16);
    offset_high= (uint32_t)((Offset & 0xffffffff00000000) >> 32);
  }
};

struct interrupt_frame;

struct IDTR{
  uint16_t size;
  uint64_t* address;
}__attribute__((packed));

__attribute__((interrupt)) void isr1_handler(interrupt_frame* frame);
__attribute__((interrupt)) void pagefault(interrupt_frame* frame);
  
void InitIDT();
  
void add_IRQ(char IRQ, void(*function)(interrupt_frame*), uint8_t gate);
#endif
