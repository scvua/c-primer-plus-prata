//
//  pr_pset06_01:
//
//  Write a program that creates an array with 26 elements and stores the 26
//  lowercase letters in it. Also have it show the array contents.
//

#include <stdio.h>

#define SIZE 26
#define CHAR 'a'

int main(void)
{
    char alpha[SIZE];

    for (int i = 0; i < SIZE; i++)
        alpha[i] = CHAR + i;

    printf("The alpha[] array elements are:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%c ", alpha[i]);
    printf("\n");

    return 0;
}
