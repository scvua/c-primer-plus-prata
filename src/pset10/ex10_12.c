/*
 * pr_pset10_12:
 *
 * Rewrite the rain program in Listing 10.7 so that the main tasks are
 * performed by functions instead of in main().
 */

#include <stdio.h>

#define MONTHS 12   // number of months in a year
#define YEARS   5   // number of years of data

void display_months(const float ar[][MONTHS], int rows);
float display_years(const float ar[][MONTHS], int rows);

int main(void)
{
 // initializing rainfall data for 2010 - 2014
    const float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    float total;

    printf(" YEAR    RAINFALL  (inches)\n");
    total = display_years(rain, YEARS);
    printf("\nThe yearly average is %.1f inches.\n\n",
            total/YEARS);

    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  "
           "Nov  Dec\n");
    display_months(rain, YEARS);

    return 0;
}

void display_months(const float ar[][MONTHS], int rows)
{
    int year, month;
    float subtot;

    for (month = 0; month < MONTHS; month++)
    {
        for (year = 0, subtot = 0; year < rows; year++)
            subtot += ar[year][month];
        printf("%4.1f ", subtot);
    }
    printf("\n");
}

float display_years(const float ar[][MONTHS], int rows)
{
    int year, month;
    float subtot, total;

    for (year = 0, total = 0; year < rows; year++)
    {
        for (month = 0, subtot = 0; month < MONTHS; month++)
            subtot += ar[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot;
    }

    return total;
}
