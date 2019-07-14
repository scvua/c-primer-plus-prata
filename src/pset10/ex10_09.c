/*
 * pr_pset10_09:
 *
 * Write a program that initializes a two-dimensional 3×5 array-of-double
 * and uses a VLA-based function to copy it to a second two-dimensional array.
 * Also provide a VLA-based function to display the contents of the two arrays.
 * The two functions should be capable, in general, of processing arbitrary
 * N×M arrays. (If you don’t have access to a VLA-capable compiler, use
 * the traditional C approach of functions that can process an N×5 array).
 */

#include <stdio.h>

#define ROWS 3
#define COLS 5

void copy2d(int r, int c, double sar[r][c], double tar[r][c]);
void display(int r, int c, double ar[r][c]);

int main(void)
{
    double source[ROWS][COLS] =
    {
        {4.3,4.3,4.3,3.0,2.0},
        {8.5,8.2,1.2,1.6,2.4},
        {9.1,8.5,6.7,4.3,2.1}
    };
    double target[ROWS][COLS] = {{0.0}};

    printf("Source array is:\n");
    display(ROWS, COLS, source);
    printf("Target array before copying:\n");
    display(ROWS, COLS, target);

    copy2d(ROWS, COLS, source, target);

    printf("Target array after copying:\n");
    display(ROWS, COLS, target);

    return 0;
}

void copy2d(int r, int c, double sar[r][c], double tar[r][c])
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            tar[i][j] = sar[i][j];
}

void display(int r, int c, double ar[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%.1lf", ar[i][j]);
            if (j != (c - 1))
                printf(", ");
        }
        putchar('\n');
    }
    putchar('\n');
}
