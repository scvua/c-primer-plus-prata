/*
 * pr_pset09_11:
 *
 * Write and test a Fibonacci() function that uses a loop instead of recursion
 * to calculate Fibonacci numbers.
 */

#include <stdio.h>

void fibonacci(int);

int main(void)
{
    int numbers;

    printf("Enter a number of the Fibonacci numbers to find: ");
    while (scanf("%d", &numbers) == 1)
    {
        if (numbers <= 0)
        {
            printf("Retry with positive integer: ");
            continue;
        }
        fibonacci(numbers);
        printf("Enter new value (q to quit): ");
    }
    printf("Done.\n");

    return 0;
}

void fibonacci(int sequence)
{
    for (int i = 0, sum = 0, number = 0; i < sequence; i++)
    {
        sum += number;
        number = sum - number;
        if (i == 1)
            sum = 1;
        printf("%d", sum);
        i + 1 < sequence ? printf(", ") : printf("\n");
    }
}
