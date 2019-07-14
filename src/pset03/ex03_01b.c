//
//  pr_pset03_01b.c
//
//  Find out what your system does with floating-point overflow by using
//  the experimental approach.
//

#include <stdio.h>
#include <float.h>

int main(void)
{
    float big = FLT_MAX;
    float small = 1.01f;
    float overflow = big * small;
    
    printf("Increment of %e by %e is %e\n",
           big, small, overflow);
    
    return 0;
}
