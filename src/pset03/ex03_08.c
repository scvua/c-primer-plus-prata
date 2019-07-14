//
//  pr_pset03_08.c
//
//  In the U.S. system of volume measurements, a pint is 2 cups,
//  a cup is 8 ounces, an ounce is 2 tablespoons, and
//  a tablespoon is 3 teaspoons.
//  Write a program that requests a volume in cups and that displays
//  the equivalent volumes in pints, ounces, tablespoons, and teaspoons.
//

#include <stdio.h>

int main(void)
{
    float pint, cup, ounce, tablespoon, teaspoon;

    printf("Enter number of cups: ");
    scanf("%f", &cup);

    pint = cup / 2;             // a pint is 2 cups
    ounce = cup * 8;            // a cup is 8 ounces
    tablespoon = ounce * 2;     // an ounce is 2 tablespoons
    teaspoon = tablespoon * 3;  // a table spoon is 3 teaspoons

    printf("In %.2f cups:\n", cup);
    printf("\t%7.2f pints;\n\t%7.2f ounces;\n", pint, ounce);
    printf("\t%7.2f tablespoons;\n\t%7.2f teaspoons.\n",
            tablespoon, teaspoon);

    return 0;
}
