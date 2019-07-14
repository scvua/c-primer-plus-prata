/*
 * pr_pset10_07:
 *
 * Write a program that initializes a two-dimensional array-of-double and
 * uses one of the copy functions from exercise 2 to copy it to a second
 * two-dimensional array.
 * (Because a two-dimensional array is an array of arrays,
 * a one-dimensional copy function can be used with each subarray.)
 */

#include <stdio.h>

#define ROWS 5
#define COLS 12

void copy_arr(double source[], double target[], int n);
void display(double ar[], int n);

int main(void)
{
    double source[ROWS][COLS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    double target[ROWS][COLS];

// Print source array.
    printf("The source array is:\n");
    for (int i = 0; i < ROWS; i++)
        display(source[i], COLS);
    putchar('\n');

// Copy source array to the target array.
    for (int i = 0; i < ROWS; i++)
        copy_arr(source[i], target[i], COLS);

// Print target array.
    printf("The target array is:\n");
    for (int i = 0; i < ROWS; i++)
        display(target[i], COLS);

    return 0;
}

void copy_arr(double source[], double target[], int n)
{
    for (int i = 0; i < n; i++)
        target[i] = source[i];
}

void display(double ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%g", ar[i]);
        if (i != (n - 1))
            printf(", ");
    }
    putchar('\n');
}
