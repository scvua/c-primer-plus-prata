//
//  pr_pset07_01:
//
//  Reads input until encountering the # character and then reports
//  the number of spaces read, the number of newline characters read,
//  and the number of all other characters read.
//

#include <stdio.h>
#include <ctype.h>      // for isspace()
#define STOP '#'
int main(void)
{
    char c;             // read in character
    long n_chars = 0L;  // number of characters
    int n_spaces = 0;   // number of spaces
    int n_lines = 0;    // number of newline characters

    printf("Enter text to analyze (# to stop input): \n");
    while ((c = getchar()) != STOP)
    {
        if (isspace(c))
        {
            if (c == '\n')
                n_lines++;
            else
                n_spaces++;
        }
        else
            n_chars++;
    }
    printf("spaces = %d, newlines = %d, other chars = %ld\n",
            n_spaces, n_lines, n_chars);

    return 0;
}
