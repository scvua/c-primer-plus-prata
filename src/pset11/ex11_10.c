/*
 *  pr_pset11_10.c
 *
 *  Write a function that takes a string as an argument and removes the spaces
 *  from the string. Test it in a program that uses a loop to read lines until
 *  you enter an empty line. The program should apply the function to each input
 *  string and display the result.
 *
 *  Created by gres.cher on 01/04/19.
 */

#include <ctype.h>
#include <stdio.h>
#define SIZE 31     // Maximum input line size

void header(int n);
char * mygets(char * s, int n);
void printar(const char * s, int n);
void rmspaces(char * s);

int main(void)
{
    char input[SIZE];
    
    header(SIZE-1);
    while (mygets(input, SIZE))
    {
        rmspaces(input);
        puts(input);
        printf("Array view: ");
        printar(input, SIZE);
        puts("\nEnter new string (Enter to quit):");
    }
    puts("done");
    return 0;
}

// Output initial program info
void header(int lim)
{
    puts("*** Test the rmspaces() function ***");
    puts("It removes the spaces from the string\n");
    printf("Enter a string up to %d characters: \n", lim);
}

// Read string; return st address if st[] has at list one character
char * mygets(char * st, int lim)
{
    int c, i;
    
    for (i=0, c=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        st[i] = c;
    // Mark the end of the string and discard the rest of the line
    st[i] = '\0';
    if (c != '\n' && c != EOF)
        while (getchar() != '\n')
            continue;
    if (i > 0)
    /* String has more elements than '\0' character */
        return st;
    else
        return NULL;
}

// Print an array of chars, print escape sequences '\0' and '\t'
void printar(const char * str, int lim)
{
    for (int i = 0; i < lim; i++)
    {
        if (str[i] == '\t')
            printf("\\t");
        else if (str[i] == '\0')
            printf("\\0");
        else
            putchar(str[i]);
    }
    putchar('\n');
}

// Remove the spaces from the string
void rmspaces(char * str)
{
    int c, ns, i;
    
    for (i = 0, ns = 0; (c = str[i]) != '\0'; i++)
    {
        if (isspace(c))
        {
            ns++;
        }
        else
        {
            str[i - ns] = c;
        }
    }
    // Place null character at the end of the modified string
    str[i - ns] = '\0';
}
