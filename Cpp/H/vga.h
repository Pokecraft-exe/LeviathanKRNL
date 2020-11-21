#include "IO.h"
#include "typedefs.h"

void WriteRegisters(uint8* registers);
bool SupportsMode(uint32 width, uint32 height, uint32 colordepth);
bool SetMode(uint32 width, uint32 height, uint32 colordepth);
extern char* GetFrameBufferSegment();
extern char* pixel;
void putPixel(uint32 x, uint32 y,  uint8 colorIndex);
uint8 getColorIndex(uint8 r, uint8 g, uint8 b);
void putPixel(uint32 x, uint32 y,  uint8 r, uint8 g, uint8 b);
void DRect(int px, int py, int fx, int fy, uint8 r, uint8 g, uint8 b);
void line(int locationX, int locationY, int size, int color);
void Box(int locationX, int locationY, int size, int color);
void Rect(int locationX, int locationY, int sizeX, int sizeY, int color);
void window(int locationX, int locationY, int sizeX, int sizeY);