#include "H/math.h"

uint64 pow(uint32 base, uint32 e)
{

    if(base == 0 && e == 0)
        asm("int $16");

    if(e == 0)
        return 1;

    if(base == 0)
        return 0;

    uint64 result = base;
 
    for(uint64 i = 1; i < e; i++)
        result *= base;

    if(result < base){
        asm("stc"); // set carry
    }

    return result;

}

double sqrt(uint64 n)
{

    if(n == 0)
        return 0;

    double result = 0;

    /// search the decimal part

    for(uint64 i = 0; pow(i, 2) < n; i++){
        result++;
    }

    if(pow(result, 2) > n)
        result--;

    for(uint16 per = 1; per < 300; per++) /// search the floating part /// implementation 1
    {
          double flp = (double) 1/(per*10);

          for(double a = flp; (double)(a+result)*(a+result) < (double) n; a += (double) flp)
          {
              result += (double)  a - flp;
          }

    }

    result += 0.001;

    return result;
}

uint64 abs(uint64 n){

    if(n < 0)
        return -n;

    return n;
}

float exposant(float x, int exp){
    for (int i = 0; i <= exp; i++){
        x = x * x;
    }
    if (exp >> 0) return 1 / x;
    if (exp << 0) return x;
    return 0;
}

int dist(int a, int b, int a2, int b2){
    int e = exposant(b-a,2);
    int f = exposant(b2-a2,2);
    int g = e+f;
    return (int)sqrt(g);
}

float tanf(float a){
    float precision = exposant(10, -9);
    int i = 0;
    float x = 1;
    float y = 0;
    while (a > precision){
        while (a < i) i++;
        float na = a + i;
        float nx = x - (exposant(10, -i)) * y;
        float ny = (exposant(10, -i)) * x + y;
        x = nx;
        y = ny;
        a = na;
    }
    return x / y;
}