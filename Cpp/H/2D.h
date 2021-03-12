#pragma once
#include "stddef.h"
#include "vga.h"
#include "math.h"
#include "serial.h"
#include "printf.h"

void initPhysics();

struct molecule
{
    int X;
    int Y;
    int color;
};

class physics{
private:
	int gravityCenterX;
	int gravityCenterY;
	bool planeGravity;
	int gravityForce;
	molecule mol[320];
	int molnum;
	molecule Emptymol;
public:
	physics(bool gravityMode=1, int Force=15)// 1 = plane mode, 0 = spheric mode (like earth)
	{
		/*if (gravityMode){
			planeGravity=1;
			gravityCenterX=160;
			gravityCenterY=200;
		}*/
        molnum=0;
        gravityForce=Force;
	}
	
	void SetGravity(int X,int Y, int Force){
		gravityCenterX = X;
		gravityCenterY = Y;
		gravityForce=Force;
	}
	
	void setWater(int X,int Y){
		mol[molnum].color=1;
		//mol[molnum].Type="Water";
		mol[molnum].X=X;
		mol[molnum].Y=Y;
		molnum++;
	}

	void write_seriall(char a) {
	while (is_transmit_empty() == 0);
	
	outb(PORT,a);
	}

	void putss(char* Text){
		int a=0;
		while(Text[a] != '\0'){
			write_seriall(Text[a]);
			a++;
		}
	}
	
	bool iterate(int number){
		if (number > 1){
			number = 1;
		}
        for (int i; i<number; i++){
            DeskColor(15);
            for (int ii = 0; ii < molnum; ii++)
            {
				char* buffer = (char*)0xA0000;
                buffer[320*mol[ii].Y+mol[ii].X] = mol[ii].color;
				int X = 160-mol[ii].X;
				int Y = 100-mol[ii].Y;
                mol[ii].X = set_operator('+',15/X);
                mol[ii].Y = set_operator('+',15/Y);
				putss(IntToStr(mol[ii].X));
				putss(IntToStr(mol[ii].Y));
            }
	    }
    }
};