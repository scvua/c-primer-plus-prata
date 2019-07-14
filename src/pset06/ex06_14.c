//
//  pr_pset06_14:
//
//  Program that creates two eight-element arrays of doubles
//  and uses a loop to let the user enter values for the eight elements
//  of the first array. Have the program set the elements of the second
//  array to the cumulative totals of the elements of the first array.
//

#include <stdio.h>

#define SIZE    8
#define INDENT  8,2

int main(void)
{
    double a[SIZE], b[SIZE];

// Prompt the user for elements of the firsr array.
    printf("Enter 8 numbers: ");
    for (int i = 0; i < SIZE; i++)
        scanf("%lf", &a[i]);

// Set elements of the second array.
    b[0] = a[0];
    for (int i = 1; i < SIZE; i++)
        b[i] = b[i-1] + a[i];

// Print results.
    printf("First array is: ");
    for (int i = 0; i < SIZE; i++)
        printf("%*.*lf", INDENT, a[i]);
    printf("\n");
    printf("Second array is:");
    for (int i = 0; i < SIZE; i++)
        printf("%*.*lf", INDENT, b[i]);
    printf("\n");

    return 0;
}
