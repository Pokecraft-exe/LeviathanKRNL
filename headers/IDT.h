#pragma once

#ifndef IDT
#define IDT

#include "IO.h"
#include "font.hpp"
#include "stdio"
#include "printf.h"
#include "pit.hpp"
#include "serial.h"
#include "allocator.hpp"
#include "KBscancodes.hpp"
#include "scheduler.hpp"
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
    uint64_t rip;
    uint16_t cs;
    uint64_t rflags;
    uint64_t rsp;
    uint16_t ss;
};

struct IDTR{
  uint16_t size;
  uint64_t address;
}__attribute__((packed));

__attribute__((interrupt)) void Schedule(interrupt_frame* frame);
__attribute__((interrupt)) void keyboardHandler(interrupt_frame* frame);
extern "C" void init_PIT();
char pollKey(char* e);
  
void InitIDT();
void add_IRQ(uint8_t IRQ, void(*function)(interrupt_frame* frame), uint8_t gate);
void add_IRQ(uint8_t IRQ, void*function, uint8_t gate);

__attribute__((interrupt)) void isr0(interrupt_frame* frame);
__attribute__((interrupt)) void isr1(interrupt_frame* frame);
__attribute__((interrupt)) void isr2(interrupt_frame* frame);
__attribute__((interrupt)) void isr3(interrupt_frame* frame);
__attribute__((interrupt)) void isr4(interrupt_frame* frame);
__attribute__((interrupt)) void isr5(interrupt_frame* frame);
__attribute__((interrupt)) void isr6(interrupt_frame* frame);
__attribute__((interrupt)) void isr7(interrupt_frame* frame);
__attribute__((interrupt)) void isr8(interrupt_frame* frame);
__attribute__((interrupt)) void isr9(interrupt_frame* frame);
__attribute__((interrupt)) void isr10(interrupt_frame* frame);
__attribute__((interrupt)) void isr11(interrupt_frame* frame);
__attribute__((interrupt)) void isr12(interrupt_frame* frame);
__attribute__((interrupt)) void isr13(interrupt_frame* frame, unsigned long errorcode);
__attribute__((interrupt)) void isr14(interrupt_frame* frame);
__attribute__((interrupt)) void isr16(interrupt_frame* frame);
__attribute__((interrupt)) void isr17(interrupt_frame* frame);
__attribute__((interrupt)) void isr18(interrupt_frame* frame);
__attribute__((interrupt)) void isr19(interrupt_frame* frame);
__attribute__((interrupt)) void isr20(interrupt_frame* frame);
__attribute__((interrupt)) void isr21(interrupt_frame* frame);
__attribute__((interrupt)) void isr28(interrupt_frame* frame);
__attribute__((interrupt)) void isr29(interrupt_frame* frame);
__attribute__((interrupt)) void isr30(interrupt_frame* frame);
#endif
