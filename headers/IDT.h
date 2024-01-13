#pragma once

#ifndef IDT
#define IDT

#include "IO.h"
#include "font.hpp"
#include "stdio"
#include "printf.h"
#include "allocator.hpp"
#include "KBscancodes.hpp"
#include "paging.hpp"
#define IDT_EntryCount 64
#define IDT_IG 0b00001110
#define IDT_TG 0b00001111

enum ISA {
	PIT = 32,
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
  uint16_t codeseg;
  uint8_t ist;
  uint8_t types_attr;
  uint16_t offset_mid;
  uint32_t offset_high;
  uint32_t zero;
}__attribute__((packed));


struct interrupt_frame
{
    uint16_t ip;
    uint16_t cs;
    uint16_t flags;
    uint16_t sp;
    uint16_t ss;
    uint64_t error;
};

struct IDTR{
  uint16_t size;
  uint64_t address;
}__attribute__((packed));

__attribute__((interrupt)) extern "C" void Schedule(interrupt_frame* frame);
extern "C" __attribute__((naked)) void irq1(interrupt_frame* frame);
extern "C" void isr1_handler(interrupt_frame* frame);
extern "C" void IRQ0_handler();
extern "C" void init_PIT();
  
void InitIDT();
void add_IRQ(uint8_t IRQ, void(*function)(interrupt_frame* frame), uint8_t gate);
void add_IRQ(uint8_t IRQ, void*function, uint8_t gate);
#endif
