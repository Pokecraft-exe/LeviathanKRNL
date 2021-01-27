#include "H/vga.h"

//extern unsigned char *FONT;
WindowProperty Windows[100];

class screen{
public:
    char buffer2[320*200];
    char* buffer = (char*)0xA0000;
    
    void swap() {
        char* vga = (char*)0xA0000;
        for (int i = 0; i < 320; i++)
        {
            for (int a = 0; a < 200; a++)
            {
                vga[320*a+i] = buffer2[320*a+i];
            }
        }
    }
    
    void putPixel(uint32 x, uint32 y,  int colorIndex){
        if( x > 360 ) return;
        if( x < 0 ) return;
        if( y > 200 ) return;
        if( y < 0 ) return;
        buffer2[320*y+x] = colorIndex;
    }

    int getColorIndex(int r, int g, int b){
        if(r == 0x00, g == 0x00, b == 0xA8) return 1;
        if(r == 0x00, g == 0xA8, b == 0x00) return 2;
        if(r == 0xA8, g == 0x00, b == 0x00) return 3;
        if(r == 0x00, g == 0x00, b == 0x00) return 0;
        if(r == 0xA8, g == 0xA8, b == 0xA8) return 15;
        return 0x00;
    }

    void putPixel(uint32 x, uint32 y,  int r, int g, int b){
        putPixel(x,y, getColorIndex(r,g,b));
    }
};

screen Screen1;
Window WindowMananger;

/*char* GetFrameBufferSegment(){
    outb(0x3c0, 0x06);
    int segmentNumber = inb(0x3cf) & (3<<2);
    switch(segmentNumber){
        case 0<<2: return (char*)0x00000;
        case 1<<2: return (char*)0xA0000;
        case 2<<2: return (char*)0xB0000;
        case 3<<2: return (char*)0xB8000;
    }
}*/

void Line(int x0, int y0, int x1, int y1, int color){
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
			Screen1.putPixel(x,y,color);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			Screen1.putPixel(x,y,color);
			p=p+2*dy;
		}
		x=x+1;
	}
}

void Rect(int locationX, int locationY, int sizeX, int sizeY, int color)
{
    char* vga = (char*)0xA0000;
    for (int i = locationX; i < locationX+sizeX; i++)
    {
        for (int a = locationY; a < locationY+sizeY; a++)
        {
            Screen1.putPixel(i,a,color);
        }
    }
}

void ctmouse(int x, int y){
    WindowMananger.Refresh();
    if (KBmouse.mouseLeftClick)Rect(315, 0, 5, 5, RED);
    if (KBmouse.mouseRightClick)Rect(315, 0, 5, 5, BLUE);
    Screen1.putPixel(x,y,BLACK);
    Screen1.putPixel(x,y+1,BLACK);Screen1.putPixel(x+1,y+1,BLACK);
    Screen1.putPixel(x,y+2,BLACK);Screen1.putPixel(x+1,y+2,RED);Screen1.putPixel(x+2,y+2,BLACK);
    Screen1.putPixel(x,y+3,BLACK);Screen1.putPixel(x+1,y+3,RED);Screen1.putPixel(x+2,y+3,RED);Screen1.putPixel(x+3,y+3,BLACK);
    Screen1.putPixel(x,y+4,BLACK);Screen1.putPixel(x+1,y+4,RED);Screen1.putPixel(x+2,y+4,BLACK);Screen1.putPixel(x+3,y+4,BLACK);Screen1.putPixel(x+4,y+4,BLACK);
    Screen1.putPixel(x,y+5,BLACK);Screen1.putPixel(x+1,y+5,RED);Screen1.putPixel(x+2,y+5,BLACK);
    Screen1.putPixel(x,y+6,BLACK);Screen1.putPixel(x+1,y+6,BLACK);Screen1.putPixel(x+2,y+6,BLACK);
    Screen1.swap();
}

void DeskColor(int color){
    Rect(0,0,320,200,color);
}

void Triangle(int x1, int y1, int x2, int y2, int x3, int y3, char color){
    Line(x1, y1, x2, y2, color);
    Line(x2, y2, x3, y3, color);
    Line(x3, y3, x1, y1, color);
}

void draw_char(unsigned char c, int x, int y)
{
    /*int cx, cy;
    int mask[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    unsigned char *glyph = FONT + (int)c*16;

    for (cy = 0; cy < 16; cy++){
        for (cx = 0; cx < 8; cx++){
            if (glyph[cy]&mask[cx])Screen1.putPixel(x+cx,y+cy,BLACK);
        }
    }*/
}

bool GetLeftClick(){
	return KBmouse.mouseLeftClick;
}
bool GetRightClick(){
	return KBmouse.mouseRightClick;
}
bool GetClick(){
	return KBmouse.mouseClick;
}
bool GetMouseUp(){
	return KBmouse.mouseUp;
}
bool GetMouseDown(){
	return KBmouse.mouseDown;
}
bool GetMouseLeft(){
	return KBmouse.mouseLeft;
}
bool GetMouseRight(){
	return KBmouse.mouseRight;
}
int GetMouseX(){
	return KBmouse.x;
}
int GetMouseY(){
	return KBmouse.y;
}