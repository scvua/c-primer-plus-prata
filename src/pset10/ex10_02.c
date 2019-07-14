/*
 * pr_pset10_02:
 *
 * Write a program that initializes an array-of-double and then copies
 * the contents of the array into three other arrays. (All four arrays should
 * be declared in the main program.) To make the first copy, use a function
 * with array notation. To make the second copy, use a function with pointer
 * notation and pointer incrementing. Have the first two functions take as
 * arguments the name of the target array, the name of the source array, and
 * the number of elements to be copied. Have the third function take as
 * arguments the name of the target, the name of the source, and a pointer
 * to the element following the last element of the source.
 */

#include <stdio.h>
#define SIZE 7

void copy_arr(double source[], double target[], int n);
void copy_ptr(double * source, double * target, int n);
void copy_ptrs(double * source_start, double * target, double * source_end);
void print_array(double ar[], int n);

int main(void)
{
    double source[SIZE] = {1.09, 30.06, 7.1, 25.03, 4.52, 3.5, 20.01};
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    printf("The source array is:\n");
    print_array(source, SIZE);

    printf("The target1 array is copied with copy_arr():\n");
    copy_arr(source, target1, SIZE);
    print_array(target1, SIZE);

    printf("The target2 array is copied with copy_ptr():\n");
    copy_ptr(source, target2, SIZE);
    print_array(target2, SIZE);

    printf("The target1 array is copied with copy_ptrs():\n");
    copy_ptrs(source, target3, source + SIZE);
    print_array(target3, SIZE);

    return 0;
}

// Function with array notation.
void copy_arr(double source[], double target[], int n)
{
    for (int i = 0; i < n; i++)
        target[i] = source[i];
}

// Function with a pointer notation and pointer incrementing.
void copy_ptr(double * source, double * target, int n)
{
    for (int i = 0; i < n; i++)
        *(target + i) = *(source + i);
}

void copy_ptrs(double * source_start, double * target, double * source_end)
{
    while (source_start < source_end)
    {
        *target = *source_start++;
        target++;
    }
}

void print_array(double ar[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%6g", ar[i]);
    printf("\n\n");
}
