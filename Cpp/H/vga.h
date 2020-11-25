#pragma once
#ifndef VGA_H
#define VGA_H
#include "IO.h"
#include "typedefs.h"
#include "Font.h"

struct Vector{
    uint32 x;
    uint32 y;
    uint32 color : 15;
};
void WriteRegisters(uint8* registers);
bool SupportsMode(uint32 width, uint32 height, uint32 colordepth);
bool SetMode(uint32 width, uint32 height, uint32 colordepth);
extern char * GetFrameBufferSegment();
void putPixel(uint32 x, uint32 y,  uint8 colorIndex);
uint8 getColorIndex(uint8 r, uint8 g, uint8 b);
void putPixel(uint32 x, uint32 y,  uint8 r, uint8 g, uint8 b);
void Line(int x0, int y0, int x1, int y1, uint8 color);
void Rect(int locationX, int locationY, int sizeX, int sizeY, int color);
void window(int locationX, int locationY, int sizeX, int sizeY);
void ctmouse(int x, int y);
void drawchar(int c, int x, int y, int fgcolor);
void __BOOTSCREEN__();
#endif