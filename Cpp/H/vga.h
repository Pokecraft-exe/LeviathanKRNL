#include "IO.h"
#include "typedefs.h"

void WriteRegisters(uint8* registers);
bool SupportsMode(uint32 width, uint32 height, uint32 colordepth);
bool SetMode(uint32 width, uint32 height, uint32 colordepth);
extern uint8* GetFrameBufferSegment();
void putPixel(uint32 x, uint32 y,  uint8 colorIndex);
void putPixel(uint32 x, uint32 y,  uint8 r, uint8 g, uint8 b);
