#pragma once
#include "stddef.h"
#include "KBScanCodeSet1.h"
#include "IO.h"
#include "Heap.h"
#include "printf.h"
#include "vga.h"
#define IDT_IG 0b10001110
#define IDT_CG 0b10001100
#define IDT_TG 0b10001111

class IDT64{
public:
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
  uint64_t Get_Offset(){
    uint64_t offset = 0;
    offset |= (uint64_t)offset_low;
    offset |= (uint64_t)(offset_mid << 16);
    offset |= (uint64_t)(offset_high << 32);
    return offset;
  }
};

struct interrupt_frame;
void* malloc(uint_64 size);

struct IDTR{
  uint16_t Limit;
  uint64_t Offset;
}__attribute__((packed));

__attribute__((interrupt)) void isr1_handler(interrupt_frame* frame);

class IDT
{
private:
  IDTR idtr;
public:
  void SetIDTGate(void* Handler, uint8_t offset, uint8_t type_attr, uint8_t selector){
    IDT64* idt = (IDT64*)(idtr.Offset + offset * sizeof(IDT64));
    idt->Set_Offset((uint64_t)Handler);
    idt->types_attr = type_attr;
    idt->selector = selector;
  }
  void InitIDT(){
    idtr.Limit = 0x0FFF;
    idtr.Offset = (uint64_t)malloc(4096);

    SetIDTGate((void*)isr1_handler, 0x21, IDT_IG, 0x08)

    asm ("lidt %0" :: "m"(idtr));

    RemapPic(0,0);

    outb(0x21, 0b11111101);
    outb(0xA1, 0b11111111);

    asm ("sti");
    asm ("cli");
  }
};


extern void(*MainKeyboardHandler)(uint_8 scanCode, uint_8 chr);

