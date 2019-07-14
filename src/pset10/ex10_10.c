/*
 * pr_pset10_10:
 *
 * Write a function that sets each element in an array to the sum of
 * the corresponding elements in two other arrays. That is, if array 1 has
 * the values 2, 4, 5, and 8 and array 2 has the values 1, 0, 4, and 6,
 * the function assigns array 3 the values 3, 4, 9, and 14. The function
 * should take three array names and an array size as arguments. Test
 * the function in a simple program.
 */

#include <stdio.h>
#define SIZE 12

void display(double ar[], int n);
void sumsar(double sar1[], double sar2[], double tar[], int n);

int main(void)
{
    double source1[SIZE] = {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4};
    double source2[SIZE] = {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3};
    double target[SIZE] = {0};

    printf("Initial state of target array is:\n");
    display(target, SIZE);
    putchar('\n');

    printf("The 1st source array is:\n");
    display(source1, SIZE);
    printf("The 2nd source array is:\n");
    display(source2, SIZE);
    putchar('\n');

    sumsar(source1, source2, target, SIZE);
    printf("Final state of target array is:\n");
    display(target, SIZE);

    return 0;
}

void display(double ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.1lf", ar[i]);
        if (i != (n - 1))
            printf(", ");
    }
    putchar('\n');
}

void sumsar(double sar1[], double sar2[], double tar[], int n)
{
    for (int i = 0; i < n; i++)
        tar[i] = sar1[i] + sar2[i];
}
