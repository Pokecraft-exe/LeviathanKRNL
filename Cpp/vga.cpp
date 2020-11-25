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

char* layer1[307200];
char* layer2[307200];
char* layer3[307200];
char* layer4[307200];
char* layer5[307200];

void putPixel(uint32 x, uint32 y,  uint8 colorIndex){
    char* pixel = (char*)0xA0000; //GetFrameBufferSegment();
    pixel[320*y+x] = colorIndex;//*layer[320*y+x] = colorIndex;
    //layerToFb();
}

uint8 getColorIndex(uint8 r, uint8 g, uint8 b){
    if(r == 0x00, g == 0x00, b == 0xA8) return 0x01;
    if(r == 0x00, g == 0xA8, b == 0x00) return 0x02;
    return 0x00;
}

void putPixel(uint32 x, uint32 y,  uint8 r, uint8 g, uint8 b){
    putPixel(x,y, getColorIndex(r,g,b));
}

void Line(int x0, int y0, int x1, int y1, uint8 color){
    int dx, dy, p, x, y;
 
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
	while(x<x1)
	{
		if(p>=0)
		{
			putPixel(x,y,color);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			putPixel(x,y,color);
			p=p+2*dy;
		}
		x=x+1;
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

void ctmouse(int x, int y){
    Rect(x,y,5,10, 1);
}

string* font = LevFont;

int nullfunc(){
    return 0;
}
 
void drawchar(int c, int x, int y, int fgcolor){

    int xpos;
    int ypos;
    //void _assos['1'] = putPixel(xpos+x, ypos+y, fgcolor);
    //void _assos['0'] = nullfunc();
    //char chr = font[c[9*xpos+ypos]]
    for (xpos = 0; xpos <= 9; xpos++){
        for (ypos = 0; ypos <= 9; ypos++){
            //_assos[chr];
            //if (font[c[9*ypos+xpos]] == '1') putPixel(xpos+x, ypos+y, fgcolor);
        }
    }
}

void __BOOTSCREEN__(){
    float[][] projection = {
        {1, 0, 0},
        {0, 1, 0}
    };

    //matmul
    uint32[2] projected2D;
    projected2D[1] = (projection[1][1] * points0x) + (projection[1][2] * points0y) + (projection)

    uint32 points0x = 100; uint32 points0y = 100;
    uint32 points1x = 50; uint32 points1y = 100;
    uint32 points2x = 50; uint32 points2y = 50;
    uint32 points3x = 100; uint32 points3y = 50;

    /*putPixel(points0x ,points0y, 15);
    putPixel(points1x ,points1y, 15);
    putPixel(points2x ,points2y, 15);
    putPixel(points3x ,points3y, 15);*/

    while(1);
}