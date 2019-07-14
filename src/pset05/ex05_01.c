//
// pr_pset05_01:
//
// Write a program that converts time in minutes to time in hours and minutes.
// Use #define or const to create a symbolic constant for 60. Use a while loop
// to allow the user to enter values repeatedly and terminate the loop if
// a value for the time of 0 or less is entered.
//

#include <stdio.h>

#define MINH 60

int main(void)
{
    int min, hours;

    printf("This program converts minutes to hours and ");
    printf("minutes.\n");
    printf("Just enter the number of minutes.\n");
    printf("Enter 0 to end the program.\n");

    scanf("%d", &min);
    while (min > 0)
    {
        printf("%d min is ", min);
        hours = min / MINH;
        min = min % MINH;
        printf("%d h, %d min.\n", hours, min);
        printf("Next input?\n");
        scanf("%d", &min);
    }
    printf("Done!\n");

    return 0;
}
