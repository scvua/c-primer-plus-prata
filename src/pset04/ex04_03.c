//
// pr_pset04_03:
//
// Write a program that reads in a floating-point number and prints it first in
// decimal-point notation and then in exponential notation. Have the output use
// the following formats (the number of digits shown in the exponent may be
// different for your system):
//     a. The input is 21.3 or 2.1e+001.
//     b. The input is +21.290 or 2.129E+001.
//

#include <stdio.h>

int main(void)
{
    float num;

    printf("Enter a floating-point number: ");
    scanf("%g", &num);
    printf("Your number in decimal-point notation: %f\n", num);
    printf("Your number in exponental notation: %e\n", num);

    return 0;
}
