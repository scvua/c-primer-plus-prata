/*
 *  pr_pset14_11.c
 *
 *  Function transform(double src[], double trgt[], int lim, (* fp)) and its
 *  tests, using two functions from the math.h library and two suitable
 *  functions of your own devising as arguments of the transform().
 *
 *  Created by gres.cher on 07/17/19.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AR_COLS 8   // Number of columns when displaying the array
#define TESTS   4   // Number of tests of the transform() function to be done

void printar(double ar[], const int size, const int width);
double inverse(double d);
double tangent(double d);
void transform(double src[], double trg[], int size, double (*fp)(double));

// An array of pointers to functions that will be applied
double (* apply[TESTS])(double) = {sin, cos, tangent, inverse};
enum operations {SIN, COS, TAN, INV};
const char * fname[] = {"sin", "cos", "tangent", "inverse"};

int main(void)
{
    enum operations func;
    int size;           // Size of the arrays; user-defined
    double * ptsrc;     // Pointer to the source array of selected size
    double * pttrg;     // Pointer to the target array

    // Prompt the user for the size of the array
    printf("How many values do you want to process?\n");
    if (scanf("%d", &size) != 1)
    {
        puts("Number entered incorrectly. Program exit.");
        exit(EXIT_FAILURE);
    }
    // Allocate memory for the arrays of the chosen size
    ptsrc = (double *) calloc(size, sizeof(double));
    pttrg = (double *) calloc(size, sizeof(double));

    // Feed the source array with randomized values in a range of 0.00 - 359.99
    srand((unsigned int) time(0));
    for (int i = 0; i < size; i++)
        ptsrc[i] = (double)(rand() % 3600000) / 10000.0;
    // Print the source array
    puts("Here's the source array with initial values:");
    printar(ptsrc, size, AR_COLS);

    // Run test cycle of the transform() function
    for (func = SIN; func <= INV; func++)
    {
        transform(ptsrc, pttrg, size, (apply[func]));
        printf("\nResults of %s() function:\n", fname[func]);
        printar(pttrg, size, AR_COLS);
    }
    // Free allocated memory and quit
    free(ptsrc);
    free(pttrg);
    puts("Bye.");
    return 0;
}

// Print the contents of the array
void printar(double ar[], const int size, const int width)
{
    for (int i = 0; i < size; i++)
    {
        printf("%10.4f", ar[i]);
        if (i % width == width - 1)
            putchar('\n');
    }
    putchar('\n');
}

// Returns square of the initial value
double inverse(double d)
{
    return (1.0 / d);
}

// Returns tangent of the initial value
double tangent(double d)
{
    return (sin(d) / cos(d));
}

// Apply the indicated function to each element in the source array,
// placing the return value in the target array
void transform(double src[], double trg[], int size, double (*fp)(double))
{
    while (--size >= 0)
        trg[size] = (fp)(src[size]);
}
