/*
 * pr_pset09_07:
 *
 * Write a program that reads characters from the standard input to
 * end-of-file. For each character, have the program report whether it is
 * a letter. If it is a letter, also report its numerical location in
 * the alphabet. For example, c and C would both be letter 3. Incorporate
 * a function that takes a character as an argument and returns the numerical
 * location if the character is a letter and that returns –1 otherwise.
 */

#include <stdio.h>

int isletter(char);

int main(void)
{
    char ch;
    int num_loc;

    printf("Enter some text below:\n");
    while ((ch = getchar()) != EOF)
    {
        num_loc = isletter(ch);
        if (num_loc == -1)
        {
            if (ch == '\n')
                printf("'\\n'");
            else if (ch == '\t')
                printf("'\\t'");
            else
                printf("'%c'", ch);
            printf(" is not a letter.\n");
        }
        else
            printf("'%c' letter location: %d\n", ch, num_loc);
    }
    printf("Bye.\n");

    return 0;
}

int isletter(char c)
{
    int num_loc;    // Numerical location in the alphabet.

    if (c >= 'a' && c <= 'z')
        // islower(c)
        num_loc = c - 'a' + 1;
    else if (c >= 'A' && c <= 'Z')
        // isupper(c)
        num_loc = c - 'A' + 1;
    else
        num_loc = -1;

    return num_loc;
}
