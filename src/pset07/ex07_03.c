//
//  pr_pset07_03:
//
//  Write a program that reads integers until 0 is entered. After input
//  terminates, the program should report the total number of even integers
//  (excluding the 0) entered, the average value of the even integers,
//  the total number of odd integers entered, and the average value of
//  the odd integers.
//

#include <stdio.h>

int main(void)
{
    int num;
    int n_even, sum_even;
    int n_odd, sum_odd;
    float av_even, av_odd;

    n_even = sum_even = 0;
    n_odd = sum_odd = 0;
    av_even = av_odd = 0.0;
    printf("Enter a number (0 to end): ");
    while ((scanf("%d", &num) == 1) && (num != 0))
    {
        if (num % 2 == 0)
        {
            n_even++;
            sum_even += num;
        }
        else
        {
            n_odd++;
            sum_odd += num;
        }
        printf("Enter a number (0 to end): ");
    }
    if (n_even != 0)
    {
        av_even = (float) sum_even / n_even;
    }
    if (n_odd != 0)
    {
        av_odd = (float) sum_odd / n_odd;
    }
    printf("Total number of even integers = %d, average value = %.2f\n",
            n_even, av_even);
    printf("Total number of odd integers = %d, average value = %.2f\n",
            n_odd, av_odd);

    return 0;
}
