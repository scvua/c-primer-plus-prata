//
//  pr_pset06_13:
//
//  Program that creates an eight-element array of ints and sets
//  the elements to the first eight powers of 2
//  and then prints the values.
//

#include <stdio.h>

#define SIZE 8

int main(void)
{
    int num[SIZE];
    int i;

    num[0] = 2;
    for (i = 1; i <= SIZE; i++)
        num[i] = num[i-1] * 2;

    i = 0;
    do
    {
        printf("2^%d: %d\n", i+1, num[i]);
        i++;
    }
    while (i < SIZE);
    printf("Done\n");

    return 0;
}
