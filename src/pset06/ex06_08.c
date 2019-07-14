//
//  pr_pset06_08:
//
//  Write a program that requests two floating-point numbers and prints
//  the value of their difference divided by their product. Have the program
//  loop through pairs of input values until the user enters nonnumeric input.
//

#include <stdio.h>

double division(double n, double m);

int main(void)
{
    double n, m;

    printf("Enter 2 fractal numbers ('q' to quit):\n");
    while (scanf("%lf %lf", &n, &m) == 2)
    {
        printf("n-m/n*m is %.3e\n", (n-m)/(n*m));
        printf("Enter 2 fractal numbers ('q' to quit):\n");
    }
    printf("Done.\n");

    return 0;
}
