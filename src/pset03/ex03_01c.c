//
//  pr_pset03_01c.c
//
//  Find out what your system does with floating-point underflow by using
//  the experimental approach.
//

#include <stdio.h>
#include <float.h>

int main(void)
{
    float very_small = FLT_MIN;
    float small = 1e7;
    float underflow = very_small / small;
    printf("Decrement of %e by %e is %e\n",
           very_small, small, underflow);
    
    return 0;
}
