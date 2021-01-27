#pragma once
#include "IO.h"
#include "typedefs.h"
#include "Font.h"
#include "3D.h"
#include "math.h"
#include "IDT.h"
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

class screen;

void Line(int x0, int y0, int x1, int y1, int color);
//void Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color);
void Rect(int locationX, int locationY, int sizeX, int sizeY, int color);
void ctmouse(int x, int y);
void DeskColor(int color);
void drawchar(int c, int x, int y, int fgcolor);
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
      }
   }
};