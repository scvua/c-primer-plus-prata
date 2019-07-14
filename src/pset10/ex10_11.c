/*
 * pr_pset10_11:
 *
 * Write a program that declares a 3×5 array of int and initializes it
 * to some values of your choice. Have the program print the values, double
 * all the values, and then display the new values. Write a function to do
 * the displaying and a second function to do the doubling. Have
 * the functions take the array name and the number of rows as arguments.
 */

#include <stdio.h>

#define ROWS 3
#define COLS 5

void display(int ar[][COLS], int row);
void doubler(int ar[][COLS], int row);

int main(void)
{
    int ar[ROWS][COLS] =
    {
        {4,56,32,6,12},
        {57,43,101,4,16},
        {3,55,43,21,28}
    };

    printf("Initialized array is:\n");
    display(ar, ROWS);
    printf("\n");
    doubler(ar, ROWS);
    printf("Array with doubled values is:\n");
    display(ar, ROWS);

    return 0;
}

void display(int ar[][COLS], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("%4d", ar[i][j]);
        printf("\n");
    }
}

void doubler(int ar[][COLS], int row)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < COLS; j++)
            ar[i][j] = 2 * ar[i][j];
}
