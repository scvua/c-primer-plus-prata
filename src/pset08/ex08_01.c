/*
 * pr_pset08_01:
 *
 * Devise a program that counts the number of characters in its
 * input up to the end of file.
 */

#include <stdio.h>

int main(void)
{
    int ch;
    long count = 0;

    while ((ch = getchar()) != EOF)
    {
        count++;
    }
    printf("Number of characters in input: %ld\n", count);

    return 0;
}
