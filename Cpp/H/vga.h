#pragma once
#include "IO.h"
#include "typedefs.h"
#include "Font.h"
#include "3D.h"
#include "math.h"
#include "IDT.h"
#include "serial.h"
#define BLACK 0
#define WHITE 15
#define GREEN 2
#define BLUE 1
#define SKY 3
#define PURPLE 5
#define BROWN 6
#define LIGHT_GRAY 7
#define GRAY 8
#define LAPIS 9
#define LIME 10
#define CYAN 11
#define LIGHT_PURPLE 13
#define YELLOW 14
#define NULL_COLOR 16
#define NEW 16
#define RED 4

struct WindowProperty{
    int windows = 0;
    char* handle;
    char* name;
    int top;
    int left;
    int bottom;
    int right;
    bool focus = 0;
};

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
        /*if( x > 360 ) return;
        if( x < 0 ) return;
        if( y > 200 ) return;
        if( y < 0 ) return;*/
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

extern screen Screen1;

void Line(int x0, int y0, int x1, int y1, int color);
//void Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color);
void Rect(int locationX, int locationY, int sizeX, int sizeY, int color);
void ctmouse(int x, int y);
void DeskColor(int color);
void draw_char(unsigned char c, int x, int y);
bool GetLeftClick();
bool GetRightClick();
bool GetClick();
bool GetMouseUp();
bool GetMouseDown();
bool GetMouseLeft();
bool GetMouseRight();
int GetMouseX();
int GetMouseY();
extern WindowProperty Windows[100];
class Window{
public:
    int windows = 0;
    void NewWindow(int X, int Y, int SizeX, int SizeY, char* NewName){
        WindowProperty w;
        w.name = NewName;
        w.top = Y;
        w.left = X;
        w.bottom = SizeY;
        w.right = SizeX;
        w.handle = NewName;
        w.windows = windows + 1;
        Windows[windows] = w;
    }

    void Label(char* Text, int x, int y){
        uint_8* charPtr = (uint_8*)Text;
        while(*charPtr != 0)
        {
            draw_char(*charPtr, x, y);
            x=x+9;
            charPtr++;
        }
    }

    void SeeChar(char Text, int x, int y){
        draw_char(Text, x, y);
    }
    void Refresh(){

        DeskColor(GRAY);
        int n = 100;

   for(uint64 i = 0; i < n; i++)
  {
      if (GetMouseX() >= Windows[i].left && Windows[i].right >= GetMouseX() && GetMouseY() >= Windows[i].top && Windows[i].bottom >= GetMouseY() && GetLeftClick() && GetMouseRight()){
        Windows[i].left = Windows[i].left + 1;
      }else{
      if (GetMouseX() >= Windows[i].left && Windows[i].right >= GetMouseX() && GetMouseY() >= Windows[i].top && Windows[i].bottom >= GetMouseY() && GetLeftClick() && GetMouseLeft()){
        Windows[i].left = Windows[i].left - 1;
      }else{
      if (GetMouseX() >= Windows[i].left && Windows[i].right >= GetMouseX() && GetMouseY() >= Windows[i].top && Windows[i].bottom >= GetMouseY() && GetLeftClick() && GetMouseUp()){
        Windows[i].top = Windows[i].top - 1;
      }else{
      if (GetMouseX() >= Windows[i].left && Windows[i].right >= GetMouseX() && GetMouseY() >= Windows[i].top && Windows[i].bottom >= GetMouseY() && GetLeftClick() && GetMouseDown()){
        Windows[i].top = Windows[i].top + 1;
      }}}}
      Rect(Windows[i].left, Windows[i].top, Windows[i].right, Windows[i].top+Windows[i].bottom, WHITE);
      Label(Windows[i].name, Windows[i].left, Windows[i].top);
      }
   }
};

extern Window WindowMananger;