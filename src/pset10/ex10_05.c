/*
 * pr_pset10_05:
 *
 * Write a function that returns the difference between the largest and
 * smallest elements of an array-of-double.
 * Test the function in a simple program.
 */

#include <stdio.h>
#define   SIZE   10

double difference(double ar[], int size, int * imin, int * imax);
// Print sequence of the array element values.
void print_ar(double ar[], int size);

int main(void)
{
    int imin = 0, imax = 0;
    double diff;
    double num[SIZE] = {5.6,45.17,3.09,9.4,13.09,88.36,83.1,56.8,101.01,7.0};

    printf("> Test of a function that returns the difference between \n"
           "> the largest and smallest elements of an array-of-double.\n\n");
    print_ar(num, SIZE);
    diff = difference(num,SIZE,&imin,&imax);
    printf("Difference between [%d] and [%d] elements is %g\n",
            imax, imin, diff);

    return 0;
}

double difference(double ar[], int size, int * imin, int * imax)
{
    double largest = ar[0], smallest = ar[0];

    for (int i = 0; i < size; i++)
    {
        if (ar[i] > largest)
        {
            largest = ar[i];
            *imax = i;
        }
        if (ar[i] < smallest)
        {
            smallest = ar[i];
            *imin = i;
        }
    }

    return largest - smallest;
}

void print_ar(double ar[], int size)
{
    printf("Values of an array-of-double:\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %.2f", ar[i]);
        if ((i + 1) != size)
            printf(";");
    }
    printf("\n");
}
