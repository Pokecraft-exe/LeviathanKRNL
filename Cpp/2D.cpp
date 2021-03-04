#include "H/2D.h"

void initPhysics(){
    physics Physics(1, 15);
    Physics.setWater(200,50);
	Physics.setWater(201,51);
    while(1){
        Physics.iterate(1);
    }
}