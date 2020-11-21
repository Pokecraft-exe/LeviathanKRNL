#include "H/vga.h"

void WriteRegisters(uint8* registers){
    outb(0x3C2, *(registers++));
    for(uint8 i = 0; i < 5; i++){
        outb(0x3C4, i);
        outb(0x3C5, *(registers++));
    }
    outb(0x3d4, 0x03);
    outb(0x3d5, inb(0x3d5) | 0x80);
    outb(0x3d4, 0x11);
    outb(0x3d5,  inb(0x3d5) & ~0x80);

    registers[0x03] = registers[0x03] | 0x80;
    registers[0x11] = registers[0x11] & ~0x80;

    for(uint8 i = 0; i < 25; i++){
        outb(0x3d4, i);
        outb(0x3d5, *(registers++));
    }

    for(uint8 i = 0; i < 9; i++){
        outb(0x3ce, i);
        outb(0x3cf, *(registers++));
    }

    for(uint8 i = 0; i < 21; i++){
        inb(0x3da);
        outb(0x3c0, i);
        outb(0x3c0, *(registers++));
    }

    inb(0x3da);
    outb(0x3c0, 0x20);

}

bool SupportsMode(uint32 width, uint32 height, uint32 colordepth){
    return width == 320 && height == 200 && colordepth == 8;
}

bool SetMode(uint32 width, uint32 height, uint32 colordepth){
    if(!SupportsMode(width, height, colordepth)) return false;
    unsigned char g_320x200x256[] =
    {
            0x63,
            0x03, 0x01, 0x0F, 0x00, 0x0E,
            0x5F, 0x4F, 0x50, 0x82, 0x54, 0x80, 0xBF, 0x1F,
            0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x9C, 0x0E, 0x8F, 0x28, 0x40, 0x96, 0xB9, 0xA3,
            0xFF,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x05, 0x0F,
            0xFF,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
            0x41, 0x00, 0x0F, 0x00, 0x00
    };
    WriteRegisters(g_320x200x256);
    return true;
}

char * GetFrameBufferSegment(){
    outb(0x3c0, 0x06);
    int segmentNumber = inb(0x3cf) & (3<<2);
    switch(segmentNumber){
        case 0<<2: return (char*)0x00000;
        case 1<<2: return (char*)0xA0000;
        case 2<<2: return (char*)0xB0000;
        case 3<<2: return (char*)0xB8000;
    }
}

char* pixel = (char*)0xA0000; //GetFrameBufferSegment();

void putPixel(uint32 x, uint32 y,  uint8 colorIndex){
    pixel = (char*)0xA0000; //GetFrameBufferSegment();
    pixel[320*y+x] = colorIndex;
}

uint8 getColorIndex(uint8 r, uint8 g, uint8 b){
    if(r == 0x00, g == 0x00, b == 0xA8) return 0x01;
    if(r == 0x00, g == 0xA8, b == 0x00) return 0x02;
    return 0x00;
}

void putPixel(uint32 x, uint32 y,  uint8 r, uint8 g, uint8 b){
    putPixel(x,y, getColorIndex(r,g,b));
}

void DRect(int px, int py, int fx, int fy, uint8 r, uint8 g, uint8 b){
    int x = px;
    int y = py;
    while (x != fx && y != fy){
        for (y = 320; y < fy; y++){putPixel(x, fy, r, g, b);}
        y = py;
        x++;
        for (y = 320; y < fy; y++){putPixel(x, fy, r, g, b);}
        //if(x == fx){
        //    y = fy;
        //    x = fx;
        //}else{
        y = py;
        x++;
        //}
    }
    
}

void line(int locationX, int locationY, int size, int color)
{
    char * vga = (char*)0xA0000;
    vga += locationX + (locationY * 640);    
    int offset = 0;

    for (int i = 0; i < size; i++)
    {
        for (int a = 0; a < size; a++)
        {
            vga[offset] = color;
            offset++;
        }

        offset += 320;
    }
}

void Box(int locationX, int locationY, int size, int color)
{
    char * vga = (char*)0xA0000;
    vga += locationX + (locationY * 640);    
    int offset = 0;

    for (int i = 0; i < size; i++)
    {
        for (int a = 0; a < size; a++)
        {
            vga[offset] = color;
            offset++;
        }

        offset += 310;
    }
}

void Rect(int locationX, int locationY, int sizeX, int sizeY, int color)
{
    char * vga = (char*)0xA0000;
    vga += locationX + (locationY * 320);    
    int offset = 0;

    for (int i = 0; i < sizeY; i++)
    {
        for (int a = 0; a < sizeX; a++)
        {
            vga[320*a+i] = color; //205
        }
    }
}

void window(int locationX, int locationY, int sizeX, int sizeY){
    Rect(locationX, locationY, sizeX, sizeY, 15);
}