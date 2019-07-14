/*
 *  pr_pset12_06.c
 *  Program that generates 1000 random numbers in the range 1-10 and prints how
 *  many times each number was produced for 10 different seed values.
 *  Version with functions from the book -- rand1() & srand1()
 *  Created by gres.cher on 02/08/19.
 */

#include "exfunc.h"
#include <stdio.h>

int main(void)
{
    int sums[RANGE];    // Array for the range of numbers MIN...MAX
    int num;
    
    // Print the table header
    printf("Here's results for %d seed values.\n", NSEED);
    printf("Seed");
    for (int i = MIN; i <= MAX; i++)
        printf("%5d", i);
    putchar('\n');
    // Generate random numbers and count them
    for (int i = 1; i <= NSEED; i++)
    {
        // Set next value of the seed
        srand1(i);
        // Reset the array of previous values
        rstar(sums, RANGE);
        printf("%3d:", i);
        // Generate QTY numbers in the range of MIN...MAX
        for (int r = 0; r < QTY; r++)
        {
            num = rand1() % RANGE + MIN;
            ++sums[num-MIN];
        }
        // Print results for the current seed
        display(sums, RANGE);
    }
    puts("Done.");
    return 0;
}
