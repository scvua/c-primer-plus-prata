//
//  pr_pset06_09:
//
//  Modify exercise 8 so that it uses a function to return the value of
//  the calculation.
//

#include <stdio.h>

double division(double n, double m);

int main(void)
{
    double n, m;
    _Bool input_is_good;

    printf("Enter 2 fractal numbers ('q' to quit):\n");
    input_is_good = (scanf("%lf %lf", &n, &m) == 2);
    while (input_is_good)
    {
        printf("n-m/n*m is %.3e\n", division(n, m));
        printf("Enter 2 fractal numbers ('q' to quit):\n");
        input_is_good = (scanf("%lf %lf", &n, &m) == 2);
    }
    printf("Done.\n");

    return 0;
}

double division(double n, double m)
{
    return (n - m) / (n * m);
}
