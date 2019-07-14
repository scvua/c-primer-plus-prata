//  
//  pr_pset03_01a.c
//
//  Find out what your system does with integer overflow by using
//  the experimental approach.
//

#include <stdio.h>
#include <limits.h>

int main(void)
{
    int big = INT_MAX;
    
    printf("Sum of %d and %d is %d\n", 1, big, big + 1);
    printf("Increment of %d and %d is %d\n", 10, big, big * 10);
    printf("Increment of %d and %d is %d\n", 100, big, big * 100);
    return 0;
}
