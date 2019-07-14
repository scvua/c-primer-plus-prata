/*
 *  pr_pset12_05.c
 *  Program that generates a list of 100 random numbers in the range 1-10 in
 *  sorted decreasing order.
 *  Created by gres.cher on 02/05/19.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE  100
#define NLINE 20

void display(int ar[], int lim);
void generate(int ar[], int lim, int max);
void sortlist(int ar[], int lim);

int main(void)
{
    int list[SIZE];
    
    // Randomise seed
    srand((unsigned int) time(0));
    // Generate and display an array
    puts("List of integers (initaial state):");
    generate(list, SIZE, 10);
    display(list, SIZE);
    // Sort an array and then display it
    puts("The list in sorted decreasing order:");
    sortlist(list, SIZE);
    display(list, SIZE);
    puts("Done.");
    
    return 0;
}
// Display contents of an array
void display(int ar[], int lim)
{
    for (int i = 0; i < lim; i++)
    {
        printf("%4d", ar[i]);
        // Print NLINE numbers in a line
        if (i % NLINE == NLINE - 1)
            putchar('\n');
    }
    putchar('\n');
}
// Fill in array with random numbers in the range [min-max]
void generate(int ar[], int lim, int max)
{
    for (int i = 0; i < lim; i++)
        ar[i] = rand() % max + 1;
}
// Sort an array in decreasing order
void sortlist(int ar[], int lim)
{
    int temp, top, seek;
    
    for (top = 0; top < lim; top++)
        for (seek = top + 1; seek < lim; seek++)
            if (ar[top] < ar[seek])
            {
                temp = ar[top];
                ar[top] = ar[seek];
                ar[seek] = temp;
            }
}
