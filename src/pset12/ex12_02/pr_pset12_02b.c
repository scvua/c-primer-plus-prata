/*
 *  pr_pset12_02b.c -- compile with pr_pset12_02a.c
 *  Program calculates gasoline consumption (metric and US measure systems)
 *  
 *  This source is part of the problem exercise. Solution is in the
 *  implementation of files 'pr_pset12_02a.c' and 'pr_pset12_02a.h'
 */

#include <stdio.h>
#include "pr_pset12_02a.h"

int main(void)
{
    int mode;
    
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}
