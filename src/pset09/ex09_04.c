/*
 * pr_pset09_04:
 *
 * The harmonic mean of two numbers is obtained by taking the inverses of
 * the two numbers, averaging them, and taking the inverse of the result.
 * Write a function that takes two double arguments and returns the harmonic
 * mean of the two numbers.
 */

#include <stdio.h>

double harm(double, double);

int main(void)
{
    double n, m;

    printf("Enter two numbers (q to quit): ");
    while (scanf("%lf %lf", &n, &m) == 2)
    {
        printf("Harmonic mean of %g and %g is %g\n",
                n, m, harm(n,m));
        printf("Enter next values (q to quit): ");
    }
    printf("Bye.\n");

    return 0;
}

double harm(double n, double m)
{
    return 2.0 / (1.0/n + 1.0/m);
}
