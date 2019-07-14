/*
 * pr_pset09_09:
 *
 * Improve the power() (Listing 6.20) so that it correctly handles negative
 * powers. Also, build into the function that 0 to any power other than 0
 * is 0 and that any number to the 0 power is 1.
 * (It should report that 0 to the 0 is undefined, then say it’s using
 * a value of 1.) Use a loop. Test the function in a program.
 */

#include <stdio.h>
#include <stdlib.h>

double power(double base, int exponent);

int main(void)
{
    double base, number;
    int exponent;

    printf("*** Test power() function with recursion. ***\n");
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
    double r_power;

    if (base == 0 && exponent == 0)
    {
        printf("Warning: 0 to 0 power is not a number.\n");
        return 1.0;
    }

    // Stop recursion.
    if (exponent == 0)
        return 1.0;

    // Recursion step.
    r_power = base * power(base, abs(exponent) - 1);

    if (exponent < 0)
        r_power = 1.0 / r_power;

    return r_power;
}
