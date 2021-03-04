#include "H/2D.h"

void initPhysics(){
    physics Physics;
    Physics.setWater(200,50);
	Physics.setWater(201,51);
    Physics.iterate(100);
}