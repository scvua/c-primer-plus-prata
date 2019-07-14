//
// pr_pset05_09:
// temp.c -- calculates Celsius and Kelvin temperatures
//
// Write a program that requests the user to enter a Fahrenheit temperature.
// The program should read the temperature as a type double number and pass it
// as an argument to a user-supplied function called Temperatures().
// This function should calculate the Celsius equivalent and the Kelvin
// equivalent and display all three temperatures with a precision of two places
// to the right of the decimal. It should identify each value with
// the temperature scale it represents. Here is the formula for converting
// Fahrenheit to Celsius:
//
//    Celsius = 5.0 / 9.0 * (Fahrenheit - 32.0)
//
// The Kelvin scale, commonly used in science, is a scale in which 0 represents
// absolute zero, the lower limit to possible temperatures. Here is the formula
// for converting Celsius to Kelvin:
//
//    Kelvin = Celsius + 273.16
//
// The Temperatures() function should use const to create symbolic
// representations of the three constants that appear in the conversions.
// The main() function should use a loop to allow the user to enter temperatures
// repeatedly, stopping when a q or other nonnumeric value is entered.
// Use the fact that scanf() returns the number of items read, so it will return
// 1 if it reads a number, but it won’t return 1 if the user enters q.
// The == operator tests for equality, so you can use it to compare the return
// value of scanf() with 1.
//

#include <stdio.h>

#define C_TO_K      273.16
#define FAHR_TO_C   5.0 / 9.0
#define DEGREES     32.0

void temperature(double fahr);

int main(void)
{
    double fahr;
    int test;

    printf("Enter temperature in Fahrenheit: ");
    test = scanf("%lf", &fahr);
    while (test > 0)
    {
        temperature(fahr);
        printf("Enter temperature in Fahrenheit ('q' to quit): ");
        test = scanf("%lf", &fahr);
    }
    printf("Done\n");

    return 0;
}

void temperature(double fahr)
{
    double cels, kelv;

    cels = FAHR_TO_C * (fahr - DEGREES);
    kelv = cels + C_TO_K;
    printf("%.2lfºF is %.2lfºC or %.2lfºK\n", fahr, cels, kelv);
}
