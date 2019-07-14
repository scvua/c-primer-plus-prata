/*
 * pr_pset09_06:
 *
 * Write and test a function that takes the addresses of three double
 * variables as arguments and that moves the value of the smallest variable
 * into the first variable, the middle value to the second variable, and the
 * largest value into the third variable.
 */

#include <stdio.h>

void sort(double * a, double * b, double * c);

int main(void)
{
    double a, b, c;

    printf("Enter 3 numbers: ");
    while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        printf("You entered:    %g %g %g\n", a, b, c);
        sort(&a, &b, &c);
        printf("Numbers sorted: %g %g %g\n", a, b, c);
        printf("Enter new values (q to quit): ");
    }
    printf("Bye.\n");

    return 0;
}

void sort(double * a, double * b, double * c)
{
    double temp;

    // Arrange two first numbers.
    if (*a > *b)
    {
        temp = *b;
        *b = *a;
        *a = temp;
    }
    // Arrange two last numbers.
    if (*b > *c)
    {
        temp = *c;
        *c = *b;
        *b = temp;
        // If first greater than second swap them.
        if (*a > *b)
        {
            temp = *b;
            *b = *a;
            *a = temp;
        }
    }
}
