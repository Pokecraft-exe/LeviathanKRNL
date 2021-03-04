#include "H/2D.h"

void initPhysics(){
    while(1);
    physics Physics(1, 15);
    Physics.setWater(200,50);
	Physics.setWater(201,51);
    while(1){
        Physics.iterate(1);
    }
}