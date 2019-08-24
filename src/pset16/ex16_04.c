/*
 *  ex16_04.c
 *  The function that takes a `double` argument representing a desired time
 *  delay and then runs a loop until that amount of time has passed.
 *  Created by gres.cher on 08/24/19.
 */

#include "psets.h"
#include <stdio.h>
#include <time.h>

int delay(const double sec);

int main(void)
{
    double secs;

    puts("Enter number of seconds to wait:");
    while (scanf("%lf", &secs) == 1)
    {
        EATLINE();
        if (secs <= 0.0)
        {
            puts("Retry with a positive number:");
            continue;
        }
        if (delay(secs) == 0)
        {
            fprintf(stderr, "delay(): unexpected behaviour\n");
            break;
        }
        puts("\nEnter next value; (q to quit):");
    }
    puts("Bye.");

    return 0;
}

// Takes a number in seconds; runs a loop until that amount of time has passed
int delay(const double secs)
{
    double clock0, clock1, delta;

    if ((clock0 = (double)clock()) >= 0)
    {
        do
        {
            // Take a next clock value and calculate the current time difference
            if ((clock1 = (double) clock()) >= 0)
                delta = (clock1 - clock0) / (double) CLOCKS_PER_SEC;
            else
                return 0;
        }
        while (delta < secs);
        return 1;
    }
    else
        return 0;
}
