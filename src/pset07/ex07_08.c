/*
 * pr_pset07_08:
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

#define HOURS_PER_WEEK  40
#define OVERTIME        1.5
#define PAYRATE1        8.75
#define PAYRATE2        9.33
#define PAYRATE3        10.0
#define PAYRATE4        11.2
#define TAX1            0.15
#define TAX2            0.2
#define TAX3            0.25
#define GROSS1          300.0
#define GROSS2          150.0
#define BASETAX1        GROSS1*TAX1             // $45.00
#define BASETAX2        BASETAX1+GROSS2*TAX2    // $75.00

void headerprint();             // Print header menu.
void calculate(float pay);      // Main calculation function.
float grossper(float p, int h); // Calculate gross pay.
float taxer(float gr_pay);      // Calculate taxes.

int main(void)
{
    int choice;

    headerprint();
    while (scanf("%d", &choice) && choice != 5)
    {
        switch(choice)
        {
            case 1  :   calculate(PAYRATE1);
                        break;
            case 2  :   calculate(PAYRATE2);
                        break;
            case 3  :   calculate(PAYRATE3);
                        break;
            case 4  :   calculate(PAYRATE4);
                        break;
            default :   printf("Please, enter one integer number (from 1 to 5).\n");
                        break;
        }
        headerprint();
    }
    printf("Bye.\n");

    return 0;
}

void headerprint()
{
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr\t\t\t2) $9.33/hr\n");
    printf("3) $10.00/hr\t\t\t4) $11.20/hr\n");
    printf("5) quit\n");
    printf("*****************************************************************\n");
}

void calculate(float pay_rate)
{
    int hours;
    float gross_pay, taxes, net_pay;

    printf("Enter numbers of hours worked in a week: ");
    while (scanf("%d", &hours) != 1)
    {
        printf("Please, try again. Enter one integer number: ");
    }
    gross_pay = grossper(pay_rate, hours);
    taxes = taxer(gross_pay);
    net_pay = gross_pay - taxes;
    printf("Gross pay: %.2f; taxes: %.2f; net pay: %.2f\n\n",
            gross_pay, taxes, net_pay);
}

float grossper(float pay_rate, int hours)
{
    int extra_hours;
    float gross_pay;

    extra_hours = hours - HOURS_PER_WEEK;
    if (extra_hours > 0)
    {
        gross_pay = (extra_hours * OVERTIME + HOURS_PER_WEEK) * pay_rate;
    }
    else
    {
        gross_pay = hours * pay_rate;
    }

    return gross_pay;
}

float taxer(float gross)
{
    float taxes;

    if (gross <= GROSS1)
    {
        taxes = gross * TAX1;
    }
    else if (gross <= (GROSS1 + GROSS2))
    {
        taxes = BASETAX1 + (gross - GROSS1) * TAX2;
    }
    else
    {
        taxes = BASETAX2 + (gross - GROSS1 - GROSS2) * TAX3;
    }

    return taxes;
}
