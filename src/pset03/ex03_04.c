//
//  pr_pset03_04.c
//
//  Write a program that reads in a floating-point number and prints it first
//  in decimal-point notation, then in exponential notation, and then,
//  if your system supports it, p notation.
//

#include <stdio.h>

int main(void)
{
    float f_num;

    printf("Enter a floating-point value: ");
    scanf("%f", &f_num);
    printf("fixed-point notation: %f\n", f_num);
    printf("exponential notation: %e\n", f_num);
    printf("p notation: %a\n", f_num);

    return 0;
}
