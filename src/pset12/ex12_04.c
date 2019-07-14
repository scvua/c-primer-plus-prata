/*
 *  pr_pset12_04.c
 *  Function that returns the number of times it has been called.
 *  Created by gres.cher on 01/26/19.
 */

#include <stdio.h>

int counter(void);

int main(void)
{
    int lim;
    
    printf("*** Test the counter() function ***\n\n");
    printf("How many function calls do you want to be?\n");
    scanf("%d", &lim);
    for (int i = 0; i < lim; i++)
        printf("returned: %d\n", counter());
    puts("Bye.");
    return 0;
}

// Print current number of function calls then increase it by 1
int counter(void)
{
    // Create static variable with no linkage
    static int call = 0;
    
    printf("counter() has been called %d %s.\n", call,
           call == 1 ? "time" : "times");
    return ++call;
}
