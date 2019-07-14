/*
 * pr_pset08_06:
 *
 * Modify the get_first() function of Listing 8.8 so that it returns
 * the first non-whitespace character encountered.
 * Test it in a simple program.
 */

#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void)
{
    int ch;

    printf("Type some text starting with whitespace: \n");
    ch = get_first();
    printf("The first letter is '%c'.\n", ch);

    return 0;
}

char get_first(void)
{
    char ch;

    while (isspace(ch = getchar()))
    {
        if (ch == '\n')
            printf("Retry with non-whitespace character: ");
    }
    while (getchar() != '\n')
        continue;

    return ch;
}
