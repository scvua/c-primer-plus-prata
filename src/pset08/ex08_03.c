/*
 * pr_pset08_03:
 *
 * Write a program that reads input as a stream of characters
 * until encountering EOF.
 * Have it report the number of uppercase letters, the number of
 * lowercase letters, and the number of other characters in the input.
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    long n_upper = 0L;          /* Uppercase number */
    long long n_lower = 0L;     /* Lowercase number */
    long n_other = 0L;          /* Other characters number */

    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            n_upper++;
        else if (islower(ch))
            n_lower++;
        else
            n_other++;
    }
    printf("Uppercase: %ld; Lowercase: %lld; Other chars: %ld\n",
            n_upper, n_lower, n_other);

    return 0;
}
