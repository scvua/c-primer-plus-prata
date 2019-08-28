/*
 *  ex16_07.c
 *  Complete the program by providing the code
 *  for show_array() and new_d_array().
 *  Created by grescher on 08/28/19.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define NUM_IN_ROW 4

void show_array(const double ar[], int lim);
double * new_d_array(int n, ...);

int main(void)
{
    double * p1;
    double * p2;

    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);

    return 0;
}

void show_array(const double ar[], int lim)
{
    int i = 0;

    while (i < lim)
    {
        printf("%g  ", ar[i]);
        if (++i % NUM_IN_ROW == 0)
            putchar('\n');
    }
    if (i % NUM_IN_ROW != 0)
        putchar('\n');
}

// Allocate memory for an array of doubles with `n` elements;
// Return pointer to its first element
double * new_d_array(int n, ...)
{
    double * pd = (double *) calloc(n, sizeof(double));

    if (pd)                 // Memory allocated
    {
        va_list ap;

        va_start(ap, n);
        for (int i = 0; i < n; i++)
            pd[i] = va_arg(ap, double);
        va_end(ap);
        return pd;          // Return pointer to the first element of an array
    }
    else                    // pd = calloc() is failed
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

/*
 *  Here is the output:
 *
 *      1.2  2.3  3.4  4.5
 *      5.6
 *      100  20  8.08  -1890
 *      Program ended with exit code: 0
 */
