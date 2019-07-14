/*
 * pr_pset07_09:
 *
 * Write a program that accepts a positive integer as input and then
 * displays all the prime numbers smaller than or equal to that number.
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Check if the num is prime number.
bool isprime(int num);

int main(void)
{
    int num;

    printf("Enter a positive integer (q to quit):\n");
    while (scanf("%d", &num) == 1)
    {
        if (num < 1)
        {
            printf("Please, enter an integer bigger than 0:\n");
            continue;
        }
        printf("Here's prime numbers that smaller than your number:\n");
        for (int i = 1; i <= num; i++)
        {
            if (isprime(i))
            {
                printf("%d ", i);
            }
        }
        printf("\n");
        printf("Enter a new value (q to quit):\n");
    }
    printf("Bye.\n");

    return 0;
}

bool isprime(int n)
{
    bool is_prime = true;

    for (int i = 2, root_n = (int) sqrt(n); i <= root_n; i++)
    {
        if (n % i == 0)
        {
            is_prime = false;
            break;
        }
    }

    return is_prime;
}
