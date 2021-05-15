#pragma once
#include "IO.h"
#include "typedefs.h"
#include "Font.h"
#include "3D.h"
#include "math.h"
#include "IDT.h"
#include "printf.h"
#include "serial.h"
#include "mouse.h"
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

struct ButtonProperty{
    char* text;
    int x;
    int y;
    int xend=9;
    int yend=9;
    bool Click = 0;
    int Color;
    int* OnClick;
};

struct WindowProperty{
    //ButtonProperty Button[100];
    char* handle;
    char* name;
    int top;
    int left;
    int bottom;
    int right;
    bool Closable = 1;
    bool focus = 0;
};

struct TextProperty{
    char* text;
    int x;
    int y;
    int xend=9;
    int yend=9;
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
        if( x > 360 || x < 0 || y > 200 || y < 0 ) return;
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
void draw_char(unsigned char c, int x, int y/*, int fgcolor*/);
bool GetLeftClick();
bool GetRightClick();
bool GetClick();
bool GetMouseUp();
bool GetMouseDown();
bool GetMouseLeft();
bool GetMouseRight();
int GetMouseX();
int GetMouseY();
int GetMouseVelocityX();
int GetMouseVelocityY();

class Window{
private:
    WindowProperty Windows[100];
    WindowProperty EmptyWindow;
    ButtonProperty Buttons[100];
    ButtonProperty EmptyButton;
    int button = 0;
    int windows = 0;
public:
    WindowProperty* NewWindow(int X, int Y, int SizeX, int SizeY, char* NewName, bool Closable=1){
        WindowProperty w;
        w.name = NewName;
        w.top = Y;
        w.left = X;
        w.bottom = SizeY;
        w.right = SizeX;
        w.handle = NewName;
        w.Closable = Closable;
        windows = windows + 1;
        Windows[windows+1] = w;
        WindowProperty* w2 =  &Windows[windows+1];
        return w2;
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

    void Button(/*char* Text, */int x, int y, int xend, int yend, int fgcolor/*, void* OnClick*/){
        ButtonProperty b;
        b.x=x;
        b.y=y;
        b.xend=xend;
        b.yend=yend;
        b.Color=fgcolor;
        button+=1;
        Buttons[button]=b;
        }

   void ButtonMananger(){
        for(uint64 i = 0; i < 100; i++){
            int x = Buttons[i].x;
            int y = Buttons[i].y;
            int xend = Buttons[i].xend;
            int yend = Buttons[i].yend;
            int fgcolor = Buttons[i].Color;
            Rect(x,y,xend,yend,fgcolor);
            if (GetMouseX() >= x &&
            xend >= GetMouseX() &&
            GetMouseY() >= y &&
            yend>= GetMouseY() &&
            GetLeftClick()) Buttons[i].Click=1;// OnClick();
        }
    }

    bool CompareWindows(WindowProperty w1, WindowProperty w2){
        if (w1.name == w2.name &&
        w1.top==w2.top&&
        w1.left==w2.left&&
        w1.bottom==w2.bottom&&
        w1.right==w2.right&&
        w1.handle==w2.handle) return 1;
        return 0;
    }

    void SeeChar(char Text, int x, int y){
        draw_char(Text, x, y);
    }
    void Close(){
        return;
    }
    void Refresh(){

        DeskColor(GRAY);
        int n=100;
        for(uint64 i = 0; i < n; i++)
        {
            if (!CompareWindows(Windows[i],EmptyWindow)){
                if (GetMouseX() >= Windows[i].left && Windows[i].right >= GetMouseX() && GetMouseY() >= Windows[i].top && Windows[i].bottom >= GetMouseY() && /*GetLeftClick()*/ GetMouseRight()){
                    Windows[i].left = Windows[i].left + GetMouseVelocityX();
                }else{
                if (GetMouseX() >= Windows[i].left && Windows[i].right >= GetMouseX() && GetMouseY() >= Windows[i].top && Windows[i].bottom >= GetMouseY() && /*GetLeftClick()*/ GetMouseLeft()){
                    Windows[i].left = Windows[i].left - GetMouseVelocityX();
                }else{
                if (GetMouseX() >= Windows[i].left && Windows[i].right >= GetMouseX() && GetMouseY() >= Windows[i].top && Windows[i].bottom >= GetMouseY() && /*GetLeftClick()*/ GetMouseUp()){
                    Windows[i].top = Windows[i].top - GetMouseVelocityY();
                }else{
                if (GetMouseX() >= Windows[i].left && Windows[i].right >= GetMouseX() && GetMouseY() >= Windows[i].top && Windows[i].bottom >= GetMouseY() && /*GetLeftClick()*/ GetMouseDown()){
                    Windows[i].top = Windows[i].top + GetMouseVelocityY();
                }}}}
                Rect(Windows[i].left, Windows[i].top, Windows[i].right, Windows[i].bottom, WHITE);
                int placeX=Windows[i].right+1;//+Windows[i].left;
                //puts("placing rectangle at X");puts(IntToStr(placeX-9));puts(", Y");puts(IntToStr(Windows[i].top));
                if(Windows[i].Closable){
                    Rect(placeX, Windows[i].top,9,9, RED);
                    if (GetMouseX() >= placeX && placeX+9 >= GetMouseX() && GetMouseY() >= Windows[i].top && Windows[i].top+9>= GetMouseY() && GetLeftClick())Windows[i]= EmptyWindow;
                }
                //Label(Windows[i].name, Windows[i].left, Windows[i].top);
                //Button(/*(char*)"",*/placeX-9,Windows[i].top,9,9,RED/*, Close*/);
                //ButtonMananger();
            }
        }
   }
};

extern Window WindowMananger;