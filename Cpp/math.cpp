#include "H/math.h"

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

float pow(float x, int power){
    for (int i = 0; i <= power; i++){
        x = x * x;
    }
    if (power >> 0) return 1 / x;
    if (power << 0) return x;
    return 0;
}

int dist(int a, int b, int a2, int b2){
    int e = pow(b-a,2);
    int f = pow(b2-a2,2);
    int g = e+f;
    return (int)sqrt(g);
}

float tanf(float a){
    float precision = pow(10, -9);
    int i = 0;
    float x = 1;
    float y = 0;
    while (a > precision){
        while (a < i) i++;
        float na = a + i;
        float nx = x - (pow(10, -i)) * y;
        float ny = (pow(10, -i)) * x + y;
        x = nx;
        y = ny;
        a = na;
    }
    return x / y;
}

int set_operator(char operator_, int number){
    if (operator_ == '-'){
        if (number<0){
            number*=-2;
            return number/2
        }
    }
    }if (operator_ == '+'){
        if (number>0){
            number*=-2;
            return number/2
        }
    }
    return 0
}