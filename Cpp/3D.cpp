#include "H/3D.h"
/*
void matrixMulVertices(Vertice3D &i,Vertice3D &o, mat4x4 &m){
    o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
    o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
    o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
    float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];

    if (w != 0.0) {
        o.x /= w; o.y /= w; o.z /= w;
    }
}

void __BOOTSCREEN__(){

    Mesh Cube1;
    mat4x4 matProj;

            Cube1.tris = {

		// SOUTH
		{ 0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 0.0f, 0.0f },

		// EAST                                                      
		{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 1.0f },

		// NORTH                                                     
		{ 1.0f, 0.0f, 1.0f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f },

		// WEST                                                      
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f },

		// TOP                                                       
		{ 0.0f, 1.0f, 0.0f,    0.0f, 1.0f, 1.0f,    1.0f, 1.0f, 1.0f },
		{ 0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, 0.0f },

		// BOTTOM                                                    
		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f },

		};

    float fnear = 0.1;
    float fFar = 1000.0;
    float fFov = 90.0; 
    float fAspect = (float)320 / (float)200;
    float fFovRad = 0.1 / tanf((fFov * 0.5 / 180.0 * 3,14159));

    matProj.m[0][0] = fAspect * fFovRad;
    matProj.m[0][0] = fFovRad;
    matProj.m[0][0] = fFar / (fFar - fnear);
    matProj.m[0][0] = (-fFar * fnear) / (fFar - fnear);
    matProj.m[0][0] = 1.0;
    matProj.m[0][0] = 0.0;

    for (auto tri : Cube1.tris){
        triangle triProjected;
        matrixMulVertices(tri.p[0], triProjected.p[0], matProj);
        matrixMulVertices(tri.p[1], triProjected.p[1], matProj);
        matrixMulVertices(tri.p[2], triProjected.p[2], matProj);
        Triangle(triProjected.p[0].x,triProjected.p[0].y,
            triProjected.p[1].x, triProjected.p[1].y,
            triProjected.p[2].x,triProjected.p[2].y, 15);
    }

    while(1);
}*/