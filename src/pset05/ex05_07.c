//
// pr_pset05_07:
//
// Write a program that requests a type double number and prints the value
// of the number cubed. Use a function of your own design to cube the value
// and print it.
// The main() program should pass the entered value to this function.
//

#include <stdio.h>

double cube(double n);

int main(void)
{
    double n;

    printf("Enter a double: ");
    scanf("%lf", &n);
    printf("Cubed double is: %lf\n", cube(n));

    return 0;
}

// Finds the value of the number cubed.
double cube(double n)
{
    return n * n * n;
}
