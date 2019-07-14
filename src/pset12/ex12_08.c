/*
 *  pr_pset12_08.c
 *  Providing function definitions for make_array() and show_array().
 *  Created by gres.cher on 02/12/19.
 */

#include <stdio.h>
#include <stdlib.h>

int * make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
    int * pa;
    int size;
    int value;
    
    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}
// Allocate memory for an array of `elem` elements, set each value to `val`
int * make_array(int elem, int val)
{
    int * pti;
    
    pti = (int *) malloc(elem * sizeof(int));
    if (pti)
    {
        while (elem--)
            pti[elem] = val;
    }
    return pti;
}
// Display the contents, eight numbers to a line
void show_array(const int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%6d", ar[i]);
        if ((i+1) % 8 == 0 || i+1 == n)
            putchar('\n');
    }
}
