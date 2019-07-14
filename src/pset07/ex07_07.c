/*
 * pr_pset07_07:
 *
 *  Write a program that requests the hours worked in a week and then prints
 *  the gross pay, the taxes, and the net pay. Assume the following:
 *      a. Basic pay rate = $10.00/hr
 *      b. Overtime (in excess of 40 hours) = time and a half
 *      c. Tax rate:    15% of the first $300
 *                      20% of the next $150
 *                      25% of the rest.
 */

#include <stdio.h>

#define PAY_RATE            10.0
#define HOURS_PER_WEEK      40
#define OVERTIME            1.5
#define TAXRATE1            0.15
#define TAXRATE2            0.2
#define TAXRATE3            0.25
#define GROSSPAY1           300.0
#define GROSSPAY2           150.0

int main(void)
{
    int hours, ex_hours;
    float gr_pay, taxes, n_pay;

    gr_pay = taxes = n_pay = 0.0;
    printf("Enter numbers of hours worked in a week:\n");
    scanf("%d", &hours);

    ex_hours = hours - HOURS_PER_WEEK;
    if (ex_hours > 0)
    {
        gr_pay = (ex_hours * OVERTIME + HOURS_PER_WEEK) * PAY_RATE;
    }
    else
    {
        gr_pay = hours * PAY_RATE;
    }

    if (gr_pay >= GROSSPAY1)  // bigger than 300
    {
        taxes = GROSSPAY1 * TAXRATE1;
        if ((gr_pay - GROSSPAY1) >= GROSSPAY2) // bigger than 150
        {
            taxes += GROSSPAY2 * TAXRATE2;
            if ((gr_pay - GROSSPAY1 - GROSSPAY2) > 0)
            {
                taxes += (gr_pay - GROSSPAY1 - GROSSPAY2) * TAXRATE3;
            }
        }
        else
        {
            taxes += (gr_pay - GROSSPAY1) * TAXRATE2;
        }
    }
    else
    {
        taxes = gr_pay * TAXRATE1;
    }
    n_pay = gr_pay - taxes;
    printf("Gross pay: %.2f; taxes: %.2f; net pay: %.2f\n",
            gr_pay, taxes, n_pay);

    return 0;
}
