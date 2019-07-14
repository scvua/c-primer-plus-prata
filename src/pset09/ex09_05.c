/*
 * pr_pset09_05:
 *
 * Write and test a function called larger_of() that replaces the contents
 * of two double variables with the maximum of the two values.
 * For example, larger_of(x,y) would reset both x and y to the larger
 * of the two.
 */

#include <stdio.h>
#include <stdbool.h>

// Prompt user with name of variable
double get_num(char c);
// Main function which replaces values of variables
void larger_of(double * u, double * v);

int main(void)
{
    double x, y;

    x = get_num('x');
    y = get_num('y');
    printf("Was x = %g and y = %g\n", x, y);
    larger_of(&x, &y);
    printf("Now x = %g and y = %g\n", x, y);
    printf("Bye.\n");

    return 0;
}

double get_num(char c)
{
    char retry;
    double num;

    printf("Enter %c: ", c);
    while (scanf("%lf", &num) != 1)
    {
        while ((retry = getchar()) != '\n')
            putchar(retry);
        printf(" is not a number.\n");
        printf("Retry: ");
    }

    return num;
}

void larger_of(double * u, double * v)
{
    if (*u > *v)
        *v = *u;
    else
        *u = *v;
}
