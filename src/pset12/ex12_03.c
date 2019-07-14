/*
 *  pr_pset12_03.c
 *  Redesign the program pr_pset12_02 so that it uses only automatic variables.
 *  Created by gres.cher on 01/26/19.
 */

#include <stdio.h>
// Difine mode values
#define METRIC 0
#define US 1
// Define string shortenings
#define CONS_M "liters per 100 km."
#define CONS_US "miles per gallon."
#define DIST_M "kilometers"
#define DIST_US "miles"
#define FUEL_M "litres"
#define FUEL_US "gallons"
#define MODE_M "(metric) used."
#define MODE_US "(US) used."

int set_mode(int m, int c);
void get_info(float * d, float * f, int m);
void show_info(float d, float f, int m);

int main(void)
{
    float distance, fuel;
    int mode = METRIC;
    int choice;
    
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &choice);
    while (choice >= 0)
    {
        mode = set_mode(mode, choice);
        get_info(&distance, &fuel, mode);
        show_info(distance, fuel, mode);
        printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");
        scanf("%d", &choice);
    }
    printf("Done.\n");
    return 0;
}
// Set up interface mode; if `ch` doesn't match use previous mode
int set_mode(int mode, int ch)
{
    if (ch == 0)
        mode = METRIC;
    else if (ch == 1)
        mode = US;
    else
    {
        printf("Invalid mode specified. ");
        printf("Mode %d %s\n", mode, mode == US ? MODE_US : MODE_M);
    }
    return mode;
}
// Prompt the data according to the mode; store in 'distance' & 'fuel'
void get_info(float * dist, float * fuel, int mode)
{
    printf("Enter distance traveled in %s: ",
           mode == US ? DIST_US : DIST_M);
    scanf("%f", dist);
    printf("Enter fuel consumed in %s: ",
           mode == US ? FUEL_US : FUEL_M);
    scanf("%f", fuel);
}
// Calculate and display the result based on the mode setting
void show_info(float dist, float fuel, int mode)
{
    printf("Fuel consumption is ");
    if (mode == US)
        printf("%.4g %s\n", dist / fuel, CONS_US);
    else
        printf("%.4g %s\n", 100.0 * fuel / dist, CONS_M);
}
