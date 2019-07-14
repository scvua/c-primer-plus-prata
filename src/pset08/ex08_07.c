/*
 * pr_pset08_07:
 *
 * Modify Programming Exercise 8 from Chapter 7 so that the menu choices
 * are labeled by characters instead of by numbers;
 * use q instead of 5 as the cue to terminate input.
 */

#include <stdio.h>
#include <ctype.h>

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
char get_first(void);           // Returns first non-whitespace character.

int main(void)
{
    int choice;

    headerprint();
    choice = get_first();
    while (choice != 'q' && choice != 'Q')
    {
        switch(choice)
        {
            case 'A':
            case 'a':   calculate(PAYRATE1);
                        break;
            case 'B':
            case 'b':   calculate(PAYRATE2);
                        break;
            case 'C':
            case 'c':   calculate(PAYRATE3);
                        break;
            case 'D':
            case 'd':   calculate(PAYRATE4);
                        break;
            default :   printf("Please, enter one of following letters\n"
                               "a, b, c, d (q to quit).\n");
                        break;
        }
        headerprint();
        choice = get_first();
    }
    printf("Bye.\n");

    return 0;
}

void headerprint()
{
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr\t\t\tb) $9.33/hr\n");
    printf("c) $10.00/hr\t\t\td) $11.20/hr\n");
    printf("q) quit\n");
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

char get_first(void)
{
    char ch;

    ch = getchar();
    while (isspace(ch))
        ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}
