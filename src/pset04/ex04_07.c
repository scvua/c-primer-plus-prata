//
// pr_pset04_07:
//
// Write a program that sets a type double variable to 1.0/3.0 and a type float
// variable to 1.0/3.0. Display each result three times—once showing four digits
// to the right of the decimal, once showing 12 digits to the right of
// the decimal, and once showing 16 digits to the right of the decimal.
// Also have the program include float.h and display the values of FLT_DIG and
// DBL_DIG. Are the displayed values of 1.0/3.0 consistent with these values?
//

#include <stdio.h>
#include <float.h>

int main(void)
{
    double dub = 1.0 / 3.0;
    float flut = 1.0 / 3.0;

    printf("float precision = %d\n", FLT_DIG);
    printf("double precision = %d\n", DBL_DIG);
    printf("\t\t\t\bdouble\t\t\t\b\b\bfloat\n");
    printf("04-digits: %18.4f   %18.4f\n", dub, flut);
    printf("12-digits: %18.12f   %18.12f\n", dub, flut);
    printf("16-digits: %18.16f   %18.16f\n", dub, flut);

    return 0;
}
