/*
 * pr_pset10_03:
 *
 * Write a function that returns the largest value stored in an array-of-int.
 * Test the function in a simple program.
 */

#include <stdio.h>
#define SIZE    10

int largest_int();

int main(void)
{
    int digit[SIZE] = {15,23,2,1,16,83,44,67,23,95};

    printf("*** Test of a largest_int() function ***\n");
    printf("The array elements are:");
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %d", *(digit+i));
        if ((i+1) != SIZE)
            printf(",");
    }
    printf("\nLargest element is: %d\n", largest_int(digit,SIZE));
    printf("Done.\n");

    return 0;
}

int largest_int(int ar[], int n)
{
    int largest = 0;

    for (int i = 0; i < n; i++)
        if (ar[i] > largest)
            largest = ar[i];

    return largest;
}
