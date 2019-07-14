/*
 *  pr_pset12_02a.c -- variables and functions
 *  Created by gres.cher on 01/26/19.
 */

#include <stdio.h>
#include "pr_pset12_02a.h"

int mode = METRIC;
static float consumpt;
static float distance;
static float fuel;

void set_mode(int m)
{
    if (m == 0)
        mode = METRIC;
    else if (m == 1)
        mode = US;
    else
    {
        // Notify user about mistake and which mode is set
        printf(INVALID);
        printf("%d %s\n", mode, mode == US ? MODE_US : MODE_M);
    }
}

void get_info(void)
{
    // Prompt for distance traveled
    printf("%s %s: ", DIST_PROMPT, mode == US ? DIST_US : DIST_M);
    scanf("%f", &distance);
    // Prompt for fuel consumed
    printf("%s %s: ", FUEL_PROMPT, mode == US ? FUEL_US : FUEL_M);
    scanf("%f", &fuel);
}

void show_info(void)
{
    if (mode == US)
        // Consumption in miles per gallon
        consumpt = distance / fuel;
    else
        // Consumption in litres per 100km
        consumpt = 100.0 * fuel / distance;
    printf("%s%.4g ", CONS_PRINT, consumpt);
    // Choose the corresponding mode string
    printf("%s\n", mode == US ? CONS_US : CONS_M);
}
