#include "stdio.h"
#include "math.h"

float Q_rsqrt( float number ) // number = x*x + y*y + z*z
{
        int i;
        float x2, y;
        const float threehalfs = 1.5F;
 
        x2 = number * 0.5F;
        y  = number;
        i  = * ( int * ) &y;                       // evil floating point bit level hacking
        i  = 0x5f3759df - ( i >> 1 );               // what the ****?
        y  = * ( float * ) &i;
        y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

        return y;
}

void main() {
    printf("%f\n", Q_rsqrt(.04));
    int i;
    float f;
    f = 3.98;
    i = (int) f;
}