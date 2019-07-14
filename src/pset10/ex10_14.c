/*
 *  pr_pset10_14:
 *
 *  Write a program that prompts the user to enter three sets of five double
 *  numbers each. (You may assume the user responds correctly and doesn’t enter
 *  non-numeric data.) The program should accomplish all of the following:
 *      a. Store the information in a 3×5 array.
 *      b. Compute the average of each set of five values.
 *      c. Compute the average of all the values.
 *      d. Determine the largest value of the 15 values.
 *      e. Report the results.
 *  Each major task should be handled by a separate function using
 *  variable-length array function parameters.
 *
 *  Created by grescher on 12/22/18.
 */

#include <stdio.h>

#define COLS 3
#define ROWS 5

double armax(int row, int col, double ar[row][col]);
double avr_ar(double ar[], int col);
double avr_ar2d(int row, int col, double ar[row][col]);
void input_ar(int row, int col, double ar[row][col]);
void print_ar(int row, int col, double ar[row][col]);
void report(int row, int col, double ar[row][col]);

int main(void)
{
    double set[COLS][ROWS];

    input_ar(COLS, ROWS, set);
    report(COLS, ROWS, set);
    return 0;
}

// Determine the largest value of the array
double armax(int row, int col, double ar[row][col])
{
    double max = **ar;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (max < ar[i][j])
                max = ar[i][j];
    return max;
}

// Comput the average of the array
double avr_ar(double ar[], int col)
{
    double sum = 0.0L;

    for (int i = 0; i < col; i++)
        sum += ar[i];
    return sum / (double)col;
}

// Compute the average of the 2-dimension array
double avr_ar2d(int row, int col, double ar[row][col])
{
    double sum = 0.0L;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            sum += ar[i][j];
    return sum / (float)(row * col);
}

// Store information into an array
void input_ar(int row, int col, double ar[row][col])
{
    for (int i = 0; i < row; i++)
    {
        printf("Input %d doubles of the set#%d:\n", col, i+1);
        for (int j = 0; j < col; j++)
        {
            scanf("%lf", &ar[i][j]);
        }
    }
}

// Print contents of the 2d array
void print_ar(int row, int col, double ar[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%9.3lf", ar[i][j]);
        putchar('\n');
    }
}

// Report the results of the program
void report(int row, int col, double ar[row][col])
{
    // Output array values
    printf("You've entered ar[%d][%d]:\n", row, col);
    print_ar(row, col, ar);
    putchar('\n');

    // Print the average of each row
    for (int i = 0; i < row; i++)
        printf("Average of %d set: %lf\n", i+1, avr_ar(ar[i], col));

    // Print the average of all the values
    printf("Average of all the values: %lf\n\n", avr_ar2d(row, col, ar));

    // Print the largest value
    printf("The maximum value: %lf\n", armax(row, col, ar));
}
