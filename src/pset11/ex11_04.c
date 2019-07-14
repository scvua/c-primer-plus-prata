//
//  pr_pset11_04.c
//
//  Design and test a function that accepts a second parameter specifying
//  the maximum number of characters that can be read and it reads the first
//  word from a line of input into an array and discards the rest of the line.
//  It should skip over leading whitespace. Define a word as a sequence of
//  characters with no blanks, tabs, or newlines in it.
//  Use getchar(). Don’t just use scanf().
//
//  Created by gres.cher on 10/10/18.
//

#include <stdio.h>
#define SIZE 10

int getword(char * st, int lim);
void print_header(int lim);
void putword(char * st, int n);

int main(void)
{
    char input[SIZE];
    int length;
    
    print_header(SIZE);
    while ((length = getword(input, SIZE)) != 0) {
        putword(input, length);
    }
    puts("done");
    return 0;
}

// Save first word from input; return number of characters in word
int getword(char * st, int lim)
{
    int c, i;
    
    i = 0;
    if (lim > i)
    {
        // Skip the heading whitespace and save the word up to lim
        while (i < lim && (c = getchar()) != EOF && c != '\n')
        {
            if (c != ' ' && c != '\t')
            {
                st[i] = c;
                i++;
            }
            else if (i > 0)
            {
                break;
            }
        }
        // `if (lim > i)` was true -> c has some value; discard rest of line
        if (c != '\n' && c != EOF)
            while (getchar() != '\n')
                continue;
    }
    return i;
}

// Print contents of the array of chars after getword() call
void putword(char * st, int n)
{
    while (n > 0) {
        putchar(*st++);
        n--;
    }
    putchar('\n');
}

// Output program info
void print_header(int lim)
{
    printf("Test the getword() function.\n");
    printf("It skips leading whitespace and it saves up to %d characters.\n",
           lim);
    printf("Type some characters (Press Return at newline to quit):\n");
}

