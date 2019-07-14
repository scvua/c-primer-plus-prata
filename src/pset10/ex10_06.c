/*
 * pr_pset10_06:
 *
 * Write a function that reverses the contents of an array of double
 * and test it in a simple program.
 */

#include <stdio.h>
#define   SIZE   10

void reverse(double ar[], int size);
// Print sequence of the array element values.
void display(double ar[], int size);

int main(void)
{
    double num[SIZE] = {5.6,45.17,3.09,9.4,13.09,88.36,83.1,56.8,101.01,7.0};

    printf("> Test of a function that reverses the contents \n"
           "> of an array-of-double.\n\n");
    printf("Values of an array before reverse:\n");
    display(num, SIZE);
    reverse(num, SIZE);
    printf("Values of an array after reverse:\n");
    display(num, SIZE);
    return 0;
}

void reverse(double ar[], int size)
{
    double rev[size];

    for (int i = 0; i < size; i++)
        rev[(size-1)-i] = ar[i];
    for (int i = 0; i < size; i++)
        ar[i] = rev[i];
}

void display(double ar[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %.2f", ar[i]);
        if ((i + 1) != size)
            printf(";");
    }
    printf("\n");
}
