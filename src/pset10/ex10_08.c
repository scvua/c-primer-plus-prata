/*
 * pr_pset10_08:
 *
 * Use a copy function from Programming Exercise 2 to copy the third through
 * fifth elements of a seven-element array into a three-element array.
 * The function itself need not be altered; just choose the right actual
 * arguments. (The actual arguments need not be an array name and array size.
 * They only have to be the address of an array element and a number of
 * elements to be processed.)
 */

#include <stdio.h>

#define SOURCE_SIZE 7
#define TARGET_SIZE 3

void copy_arr(double * source, double * target, int n);
void display(double ar[], int n);

int main(void)
{
    double source[SOURCE_SIZE] = {1.09, 30.06, 7.1, 25.03, 4.52, 3.5, 20.01};
    double target[TARGET_SIZE];

// Print source array.
    printf("The source array is:\n");
    display(source, SOURCE_SIZE);
    putchar('\n');

// Copy 3rd-5th elements to the target array.
    copy_arr(source+2, target, TARGET_SIZE);

// Print target array.
    printf("The target array is:\n");
    display(target, TARGET_SIZE);

    return 0;
}

void copy_arr(double * source, double * target, int n)
{
    for (int i = 0; i < n; i++)
        *(target + i) = *(source + i);
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
