/*
 *  ex16_02.c
 *  The program that tests the macro “function” of the harmonic mean operation.
 *  Created by gres.cher on 08/23/19.
 */

#include "psets.h"  // header file with the harmonic mean macro function
#include <stdio.h>

int main(void)
{
    double x, y, result;

    puts("Enter two numbers:");
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        // Skip the remaining input
        EATLINE();
        // Calculate the harmonic mean
        result = HRMEAN(x, y);
        printf("The harmonic mean of %g and %g:\n%g\n", x, y, result);
        // And once more for the complex expressions
        result = HRMEAN(x+y, x+y*x);
        printf("The harmonic mean of %g and %g:\n%g\n",
               x+y, x+y*x, result);
        puts("\nEnter next values; (q to quit):");
    }
    puts("Bye.");

    return 0;
}
