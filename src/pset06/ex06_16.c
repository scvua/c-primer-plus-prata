//
//  pr_pset06_16:
//
//  Daphne invests $100 at 10% simple interest. (That is, every year,
//  the investment earns an interest equal to 10% of the original investment.)
//  Deirdre invests $100 at 5% interest compounded annually. (That is,
//  interest is 5% of the current balance, including previous addition
//  of interest.) Write a program that finds how many years it takes for
//  the value of Deirdre’s investment to exceed the value of Daphne’s
//  investment. Also show the two values at that time.
//

#include <stdio.h>

#define INTEREST_SIMPLE     10.0
#define INTEREST_COMPOUND   5.0
#define INVESTMENT          100.0

int main(void)
{
    int years;
    double daphne, deidre;
    double dap_interest = INTEREST_SIMPLE;
    double deid_interest = INTEREST_COMPOUND;

    printf("Daphne invests $100 at 10%% simple interest.\n");
    printf("Deirdre invests $100 at 5%% interest compounded annually.\n");

    for (years = 1, daphne = deidre = INVESTMENT; deidre <= daphne; years++)
    {
        daphne = daphne + INVESTMENT * dap_interest / 100.0;
        deidre = deidre + deidre * deid_interest / 100.0;
        // printf("[%2d]: %7.2lf %7.2lf\n", years, daphne, deidre);
    }
    printf("After %d years Deidre exceeded Daphne \
for the value of investments.\n", years);
    printf("Daphne: %.2lf\n", daphne);
    printf("Deidre: %.2lf\n", deidre);

    return 0;
}
