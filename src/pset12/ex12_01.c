/*
 *  pr_pset12_01.c
 *  Rewrite the program in Listing 12.4 so that it does not use global
 *  variables
 *  Created by gres.cher on 01/23/19.
 */

#include <stdio.h>
int critic(void);

int main(void)
{
    int units = 0;
    
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        units = critic();
    printf("You must have looked it up!\n");
    
    return 0;
}

int critic(void)
{
    int try;
    
    printf("No luck, my friend. Try again.\n");
    scanf("%d", &try);
    return try;
}
