/*  
 *  main.c -- driver program for ex17_06
 *  Created by grescher on 03/22/20.
 */
#include "bsearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE   100      /* size of the array    */

void EatLine(void);
void InitializeArray(int * ar, const int size);
void PrintArray(int * ar, const int size, const int columns);
void SortArray(int * ar, const int size);

int main(void)
{
    int num[SIZE];
    int seek;

    // Randomize seed
    srand((unsigned int) time(0));
    // Initialize and sort the example array
    InitializeArray(num, SIZE);
    SortArray(num, SIZE);
    puts("Here's an example array:");
    PrintArray(num, SIZE, 10);
    // Test the exercise function
    puts("Input an integer to look up (0-99):");
    while (scanf("%d", &seek) == 1)
    {
        EatLine();
        if (BinSearch(num, SIZE, seek) == 1)
            printf("%d is in the array.\n", seek);
        else
            printf("%d is not in the array.\n", seek);
        puts("Input next integer to look up (q to quit):");
    }
    puts("Bye!");

    return 0;
}

/* Dispose of rest of a line   */
void EatLine(void)
{
    while (getchar() != '\n')
        continue;
}

/* initialize the array with random values of the range */
/* from 0 up to the value of the size parameter         */
void InitializeArray(int * ar, const int size)
{
    for (int i = 0; i < size; i++)
        ar[i] = rand() % size;
}

/* print an array elements */
void PrintArray(int * ar, const int size, const int columns)
{
    int index = 0;

    while (index < size)
    {
        printf("%6d", *(ar + index));
        if (index % columns == columns - 1)
            putchar('\n');
        index++;
    }
    if (index % columns != 0)
        putchar('\n');
}

/* sort array with selection sort algorithm */
void SortArray(int * ar, const int size)
{
    int top, seek;
    int tmp;

    for (top = 0; top < size; top++)
        for (seek = top + 1; seek < size; seek++)
            if (ar[seek] < ar[top])
            {
                tmp = ar[top];
                ar[top] = ar[seek];
                ar[seek] = tmp;
            }
}
