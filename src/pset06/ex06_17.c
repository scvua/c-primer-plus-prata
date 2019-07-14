//
//  pr_pset06_17:
//
//  Chuckie Lucky won a million dollars (after taxes), which he places in
//  an account that earns 8% a year. On the last day of each year, Chuckie
//  withdraws $100,000. Write a program that finds out how many years it
//  takes for Chuckie to empty his account.
//

#include <stdio.h>

#define INTEREST        8.0

int main(void)
{
    double invest = 1000000.0;
    double withdraw = 100000.0;
    int years;

    printf("Chuckie Lucky won $%.2lf (after taxes).\n", invest);
    for (years = 0; invest > 0; ++years)
    {
        invest = invest + invest * INTEREST / 100.0 - withdraw;
        // printf("[%2d]: %12.2lf\n", years, invest);
    }
    printf("After %d years Chuckie emptied his account.\n", years);

    return 0;
}
