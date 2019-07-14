/*
 * pr_pset08_04:
 *
 * Write a program that reads input as a stream of characters
 * until encountering EOF.
 * Have it report the average number of letters per word.
 * Don’t count whitespace as being letters in a word.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int ch;
    float let_per_word;
    long long n_letter = 0L;
    long long n_word = 0L;
    bool in_word = false;

    while ((ch = getchar()) != EOF)
    {
        if (isalnum(ch))
            n_letter++;
        if (isspace(ch))
        {
            in_word = false;
        }
        else if (!in_word && isalnum(ch))
        {
            in_word = true;
            n_word++;
        }
    }
    let_per_word = (float)n_letter / (float)n_word;
    printf("Average number of letters per word: %.f\n", let_per_word);

    return 0;
}
