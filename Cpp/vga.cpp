#include "H/vga.h"

WindowProperty Windows[100];

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

int CoordsToPosition(int x, int y){
    return y * 375 + x;
}

void dawchar(char c){
    for (int a = 0; a < 6; a++){
        for (int ii = 0; ii < 4; ii++){
            int i = 4*c+ii;
            if (Font[CoordsToPosition(i, a)] == '1'){
                puts('1');
            }else{
                puts('0');
	        }
        }
        puts('\n');
    }
}
