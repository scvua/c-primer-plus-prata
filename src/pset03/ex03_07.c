//
//  pr_pset03_07.c
//
//  There are 2.54 centimeters to the inch.
//  Write a program that asks you to enter your height in inches and
//  then displays your height in centimeters. Or, if you prefer, ask for
//  the height in centimeters and convert that to inches.
//

#include <stdio.h>

int main(void)
{
    const float cm_in_inch = 2.54;
    float height_cm, height_in;
    
    // Ask the user for input
    printf("Enter your height in centimeters: ");
    scanf("%f", &height_cm);
    // Convert centimeters to inches
    height_in = height_cm / cm_in_inch;
    // Print results
    printf("Your height is %.2f inches\n", height_in);
    
    return 0;
}
