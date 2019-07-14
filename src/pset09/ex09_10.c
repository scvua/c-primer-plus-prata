/*
 * pr_pset09_10:
 *
 * Generalize the to_binary() function of Listing 9.8 to a to_base_n()
 * function that takes a second argument in the range 2–10. It then should
 * print the number that is its first argument to the number base given
 * by the second argument.
 * For example, to_base_n(129,8) would display 201,
 * the base-8 equivalent of 129.
 * Test the function in a complete program.
 */

#include <stdio.h>

void to_base_n(long n, int b);

int main(void)
{
    long number;
    int base;

    printf("Enter an integer and the number base:\n");
    while (scanf("%ld %d", &number, &base) == 2)
    {
        printf("%d base equivalent: ", base);
        to_base_n(number, base);
        putchar('\n');
        printf("Enter new values (q to quit):\n");
    }
    printf("Done.\n");

    return 0;
}

void to_base_n(long number, int base)     /* recursive function */
{
    int rest;

    if (number < 0)
    {
        printf("-");
        number = -number;
    }
    rest = (int)(number % base);
    if (number >= base)
        to_base_n(number / base, base);
    printf("%d", rest);
}
