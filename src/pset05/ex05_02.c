//
// pr_pset05_02:
//
// Write a program that asks for an integer and then prints all the integers
// from (and including) that value up to (and including) a value larger by 10.
// (That is, if the input is 5, the output runs from 5 to 15.)
// Be sure to separate each output value by a space or tab or newline.
//

#include <stdio.h>

#define DELTA 10

int main(void)
{
    int n, condition;

    printf("Enter the integer: ");
    scanf("%d", &n);
    condition = n + DELTA;

    printf("%d  ", n);
    while (n++ < condition)
    {
        printf("%d  ", n);
    }
    printf("\n");

    return 0;
}
