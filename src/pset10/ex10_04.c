/*
 * pr_pset10_04:
 *
 * Write a function that returns the index of the largest value stored in
 * an array-of-double. Test the function in a simple program.
 */

#include <stdio.h>
#define   SIZE   7

int l_index(double ar[], int size);

int main(void)
{
    double num[SIZE] = {5.6,45.17,3.09,9.44,13.09,88.36,83.14};

    printf("> Test of a function that returns the index\n"
           "> of largest value stored in an array-of-double.\n");
    printf("Indexes of array:           ");
    for (int i = 0; i < SIZE; i++)
        printf("    [%d]", i);
    printf("\nValues of an array-of-double:");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%6g", num[i]);
        if ((i + 1) != SIZE)
            printf(";");
    }
    printf("\nValue of [%d] element is the largest.\n", l_index(num,SIZE));

    return 0;
}

int l_index(double ar[], int size)
{
    int index;
    double largest = 0.0L;

    for (int i = 0; i < size; i++)
    {
        if (ar[i] > largest)
        {
            largest = ar[i];
            index = i;
        }
    }

    return index;
}
