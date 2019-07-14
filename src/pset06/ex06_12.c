//
//  pr_pset06_12:
//
//  Evaluate running total of the infinite series:
//    1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
//    1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...
//

#include <stdio.h>

int main(void)
{
    long long term;
    double num1, num2;

    printf("Enter the limit of terms \n(0 or negative value to quit): ");
    num1 = num2 = 0.0;
    scanf("%lld", &term);
    if (term > 0)
    {
        for (long long i = 1, k = -1; i <= term; i++)
        {
            num1 = num1 + 1.0 / (double) i;
            k = k * (-1);
            num2 = num2 + (k * 1.0) / (double) i;
        }
        printf("Running totals after %lld terms of\n", term);
        printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... series is %.12lf\n",
                num1);
        printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... series is %.12lf\n",
                num2);
    }
    printf("Done\n");

    return 0;
}
