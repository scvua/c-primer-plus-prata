//
//  pr_pset07_02:
//
//  Write a program that reads input until encountering #.
//  Have the program print each input character and its ASCII decimal code.
//  Print eight character-code pairs per line. Suggestion: Use a character
//  count and the modulus operator (%) to print a newline character for every
//  eight cycles of the loop.
//

#include <stdio.h>

#define STOP    '#'
#define COLUMNS 8

int main(void)
{
    char c;
    int count;

    count = 0;
    printf("Enter some input (# to quit):\n");
    while ((c = getchar()) != STOP)
    {
        count++;
        printf("\'%c\' = %3d   ", c, c);
        if (!(count % COLUMNS))
        {
            printf("\n");
        }
    }

    return 0;
}
