/*
 * pr_pset10_13:
 *
 * Write a program that prompts the user to enter three sets of five double
 * numbers each. (You may assume the user responds correctly and doesn’t enter
 * non-numeric data.) The program should accomplish all of the following:
 *      a. Store the information in a 3×5 array.
 *      b. Compute the average of each set of five values.
 *      c. Compute the average of all the values.
 *      d. Determine the largest value of the 15 values.
 *      e. Report the results.
 * Each major task should be handled by a separate function using
 * the traditional C approach to handling arrays.
 */

#include <stdio.h>

#define SETS     3
#define SET_SIZE 5

void store_data(double ar[], int);
double set_aver(double ar[], int);
double tot_aver(double ar[][SET_SIZE], int);
double largest(double ar[][SET_SIZE], int);
void display(double ar[][SET_SIZE], int);

int main(void)
{
    double ar[SETS][SET_SIZE];

    printf("Enter three sets of five numbers each.\n");
    for (int i = 0; i < SETS; i++)
    {
        printf("Enter %d values for set %d: ", SET_SIZE, i + 1);
        store_data(ar[i], SET_SIZE);
    }
    printf("\nYour array is:\n");
    display(ar, SETS);

    for (int i = 0; i < SETS; i++)
        printf("Average of %d set values: %.2lf\n",
                i + 1, set_aver(ar[i], SET_SIZE));
    printf("Average of all values is %.2lf\n",
            tot_aver(ar,SETS));
    printf("The largest value is %.2lf\n",
            largest(ar,SETS));

    return 0;
}

// Store the information in a one-dimensional array.
void store_data(double ar[], int size)
{
    char c;

    for (int i = 0; i < size; i++)
    {
        while (scanf("%lf", &ar[i]) != 1)
        {
            while ((c = getchar()) != '\n')
                putchar(c);
            printf(" is not a number.\nRetry: ");
        }
    }
}

// Compute the average of set values.
double set_aver(double ar[], int size)
{
    double average;
    double total = 0.0L;

    for (int i = 0; i < size; i++)
        total += ar[i];
    average = total / size;

    return average;
}

// Compute the average of all the values.
double tot_aver(double ar[][SET_SIZE], int rows)
{
    double average;
    double total = 0.0L;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < SET_SIZE; j++)
            total += ar[i][j];

    average = total / (double)(rows * SET_SIZE);

    return average;
}

// Determine the largest value of all array values.
double largest(double ar[][SET_SIZE], int rows)
{
    double big_num;

    big_num = ar[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < SET_SIZE; j++)
            if (big_num < ar[i][j])
                big_num = ar[i][j];

    return big_num;
}

// Show two-dimensional array.
void display(double ar[][SET_SIZE], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < SET_SIZE; j++)
            printf("%5g ", ar[i][j]);
        printf("\n");
    }
    printf("\n");
}
