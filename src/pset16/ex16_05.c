/*
 *  ex16_05.c
 *  The function that takes as arguments the name of an array of type int
 *  elements, the size of an array, and a value representing the number of
 *  picks. The function then should select the indicated number of items at
 *  random from the array and prints them. No array element is to be picked more
 *  than once.
 *  Created by gres.cher on 08/25/19.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randpick(const int * ar, const int size, int npicks);

int main(void)
{
    int size;

    puts("Enter the size of an array: ");
    if (scanf("%d", &size) == 1 && size > 0)
    {
        int * ar;
        int npicks;

        ar = calloc(size, sizeof(int));
        for (int i = 0; i < size; i++)
            ar[i] = i + 1;
        printf("Enter amount of the elements to peak;\n(1-%d): ", size);
        while (scanf("%d", &npicks) == 1 && npicks > 0 && npicks <= size)
        {
            puts("Picked elements:");
            randpick(ar, size, npicks);
            puts("Enter next amount (q to quit):");
        }
        free(ar);
    }
    puts("Bye.");

    return 0;
}

void randpick(const int * ar, const int size, int npicks)
{
    static bool first_fcall = true;
    bool * is_picked;

    // On the first function call set the random seed
    if (first_fcall)
    {
        srand((unsigned int) time(0));
        first_fcall = false;
    }
    // Allocate the array with the element statuses; initialized with all zeros
    is_picked = calloc(size, sizeof(bool));
    for (int i = 0, pick; i < npicks; i++)
    {
        do
            pick = rand() % size;
        while (is_picked[pick]);
        printf("%d ", ar[pick]);
        is_picked[pick] = true;
    }
    free(is_picked);
    putchar('\n');
}
