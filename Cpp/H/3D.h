#pragma once
#include "vga.h"
#include "math.h"
#include "typedefs.h"

struct Vertice3D{
    float x, y, z;
};

struct triangle{
    Vertice3D p[3];
};

struct Mesh{
    triangle tris;
};

struct mat4x4{
    float m[4][4] = { 0 };
};

//void __BOOTSCREEN__();