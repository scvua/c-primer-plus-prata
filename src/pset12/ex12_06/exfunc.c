/*
 *  exfunc.c -- exercise 12.6 management functions
 *  Created by gres.cher on 2/8/19.
 */

#include "exfunc.h"
#include <stdio.h>

static unsigned long int next = 1;

void display(const int ar[], int lim)
{
    for (int i = 0; i < lim; i++)
        printf("%5d", ar[i]);
    putchar('\n');
}

int rand1(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next/65536) % 32768;
}

void rstar(int ar[], int lim)
{
    while (lim--)
        ar[lim] = 0;
}

void srand1(unsigned int seed)
{
    next = seed;
}
