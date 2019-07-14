//
//  pr_pset06_11:
//
//  Write a program that reads eight integers into an array and then prints
//  them in reverse order.
//

#include <stdio.h>

#define SIZE 8

int main(void)
{
    int num[SIZE];

    printf("Enter 8 integer numbers: ");
    for (int i = 0; i < SIZE; i++)
        scanf("%d", &num[i]);
    printf("Your numbers are:");
    for (int i = 0; i < SIZE; i++)
        printf(" %d", num[i]);
    printf("\n");
    printf("Reverse order is:");
    for (int i = SIZE-1; i >= 0; i--)
        printf(" %d", num[i]);
    printf("\n");

    return 0;
}
