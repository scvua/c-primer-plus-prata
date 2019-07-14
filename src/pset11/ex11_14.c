/*
 *  pr_pset11_14.c
 *  A power-law program that works on a command-line basis. The first argument
 *  should be the type `double` number to be raised to a certain power,
 *  and the second argument should be the integer power.
 *
 *  Created by gres.cher on 01/12/19.
 */

#include <stdio.h>
#include <stdlib.h>

double power(double b, int n);

int main(int argc, char *argv[])
{
    int n;
    double base;
    
    if (argc != 3)
    {
        puts("Usage: ./pr_pset11_14 %f %d");
    }
    else
    {
        base = atof(argv[1]);
        n = atoi(argv[2]);
        // Print value of `base` in parentheses if base is a negative number
        if (base < 0)
        {
            putchar('(');
            printf("%.12g", base);
            putchar(')');
        }
        else
            printf("%.12g", base);
        printf("^%d = %.12g\n", n, power(base, n));
    }
    
    return 0;
}

// Return n-th power of base
double power(double base, int n)
{
    double p = 1.0L;
    
    if (n < 0)
    {
        while (n++)
            p = p * base;
        p = 1 / p;
    }
    else
    {
        while (n--)
            p = p * base;
    }
    return p;
}

