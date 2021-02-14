#pragma once
#define PS2Leftbutton 0b00000001
#define PS2Middlebutton 0b00000010
#define PS2Rightbutton 0b00000100
#define PS2XSign 0b00010000
#define PS2YSign 0b00100000
#define PS2XOverflow 0b01000000
#define PS2YOverflow 0b10000000
#include "vga.h"
#include "IO.h"
#include "IDT.h"

struct mouse{
  int x = 160;
  int y = 100;
  int velox;
  int veloy;
  bool mouseLeft;
  bool mouseRight;
  bool mouseDown;
  bool mouseUp;
  bool mouseLeftClick;
  bool mouseRightClick;
  bool mouseClick;
};

extern mouse KBmouse;

void mouseinit();
void mouse_updater(uint8_t data);
void MousePacket();