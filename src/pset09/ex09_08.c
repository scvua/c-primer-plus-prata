/*
 * pr_pset09_08:
 *
 * Improve the power() (Listing 6.20) so that it correctly handles negative
 * powers. Also, build into the function that 0 to any power other than 0
 * is 0 and that any number to the 0 power is 1.
 * (It should report that 0 to the 0 is undefined, then say it’s using
 * a value of 1.) Use a loop. Test the function in a program.
 */

#include <stdio.h>
#include <stdbool.h>

double power(double base, int exponent);

int main(void)
{
    double base, number;
    int exponent;

    printf("*** Test power() function with loop. ***\n");
    printf("Enter a number and the power (q to quit): ");
    while (scanf("%lf %d", &base, &exponent) == 2)
    {
        number = power(base, exponent);
        if (base == 0 && exponent == 0)
            ;
        else
            printf("%g to the %d power is %g\n",
                base, exponent, number);
        printf("Enter next values (q to quit): ");
    }
    printf("Bye.\n");

    return 0;
}

double power(double base, int exponent)
{
    double power = 1;
    bool exponent_is_negative = false;

    if (base == 0 && exponent == 0)
    {
        printf("Warning: 0 to 0 power is not a number.\n");
        return 1;
    }
    else
    {
        if (exponent < 0)
        {
            exponent_is_negative = true;
            exponent = -exponent;
        }
        for (int i = 1; i <= exponent; i++)
            power *= base;
        if (exponent_is_negative)
            power = 1.0 / power;
    }

    return power;
}
