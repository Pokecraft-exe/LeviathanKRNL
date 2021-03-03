#include "H/2D.h"

void initPhysics(){
    physics physics2;
    while(1){
        Physics.setWater(200,50);
	    Physics.setWater(201,51);
        physics2.iterate(1);
    }
}