#include "IO.h"
#include "typedefs.h"

void WriteRegisters(uint8* registers);
bool SupportsMode(uint32 width, uint32 height, uint32 colordepth);
bool SetMode(uint32 width, uint32 height, uint32 colordepth);
extern uint8* GetFrameBufferSegment();
extern char* pixel;
void putPixel(uint32 x, uint32 y,  uint8 colorIndex);
uint8 getColorIndex(uint8 r, uint8 g, uint8 b);
void putPixel(uint32 x, uint32 y,  uint8 r, uint8 g, uint8 b);
void Box(unsigned int px, unsigned int py, unsigned int fx, unsigned int fy, int r, int g, int b);