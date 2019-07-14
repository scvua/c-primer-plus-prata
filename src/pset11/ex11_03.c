//
//  pr_pset11_03.c
//
//  Design and test a function that reads the first word from a line of input
//  into an array and discards the rest of the line. It should skip over
//  leading whitespace. Define a word as a sequence of characters with
//  no blanks, tabs, or newlines in it. Use getchar(). Don’t just use scanf().
//
//  Created by gres.cher on 10/10/18.
//

#include <stdio.h>
#define SIZE 81

int getword(char * st);
void print_header(void);
void putword(char * st, int n);

int main(void)
{
    char input[SIZE];
    int length;
    
    print_header();
    while ((length = getword(input)) != 0) {
        putword(input, length);
    }
    puts("done");
    return 0;
}

// Save first word from input; return number of characters in word
int getword(char * st)
{
    int c;
    int i = 0;
    
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (c != ' ' && c != '\t')
        {
            st[i] = c;
            i++;
        }
        else if (i > 0)
        {
            // At the end of the word
            while (getchar() != '\n')
                continue;
            break;
        }
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
void print_header(void)
{
    printf("Test the getword() function. ");
    printf("It reads the first word from a line of input.\n");
    printf("Type some characters (Press Return at newline to quit):\n");
}
