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

struct IDTR{
  uint16_t Limit;
  uint64_t Offset;
}__attribute__((packed));

__attribute__((interrupt)) void isr1_handler();

class IDT
{
private:
  IDTR idtr;
  Port8Bit PIC1_DATA(PIC1_DATA);
  Port8Bit PIC2_DATA(PIC2_DATA);
public:
  InitIDT(){
    idtr.Limit = 0x0FFF;
    idtr.Offset = malloc(4096);

    IDT64* Keyboard = (IDT64)(idtr.Offset + 0x21 * sizeof(IDT64));
    Keyboard->Set_Offset((uint64_t)isr1_handler);
    Keyboard->types_attr = IDT_IG;
    Keyboard->selector = 0x08;

    asm ("lidt %0" :: "m"(idtr));

    RemapPic(0,0);

    PIC1_DATA.Write((int)0b11111101);
    PIC2_DATA.Write((int)0b11111111);

    asm ("sti");
    asm ("cli");
  }
};


extern void(*MainKeyboardHandler)(uint_8 scanCode, uint_8 chr);

