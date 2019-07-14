//
//  pr_pset06_06:
//
//  Write a program that prints a table with each line giving an integer,
//  its square, and its cube. Ask the user to input the lower and upper limits
//  for the table. Use a for loop.
//

#include <stdio.h>

int main(void)
{
    int lower, upper;

    printf("Enter lower number: ");
    scanf("%d", &lower);
    printf("Enter upper number: ");
    scanf("%d", &upper);
    printf("number  square     cube\n");

    for (int i = lower; i <= upper; i++)
        printf("%5d  %7d  %7d\n", i, i*i, i*i*i);

    return 0;
}
