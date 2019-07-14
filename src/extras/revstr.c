/*
 *  revstr.c
 *
 *  Write a function that replaces the contents of a string with the string
 *  reversed. Test the function in a complete program that uses a loop
 *  to provide input values for feeding to the functions.
 *
 * 	Implementation of the pr_pset11_09.c revstr() function with a temporary
 *  VLA array.
 *  Created by gres.cher on 01/04/19.
 */

#include <stdio.h>
#define SIZE 61     // Maximum input line size

void header(int n);
char * mygets(char * s, int n);
void revstr(char * str);

int main(void)
{
    char input[SIZE];
    
    header(SIZE-1);
    while (mygets(input, SIZE))
    {
        printf("Initial string:  %s\n", input);
        revstr(input);
        printf("Reversed string: %s\n", input);
        puts("Enter new string (Enter to quit):");
    }
    puts("done");
    return 0;
}

// Output initial program info
void header(int lim)
{
    puts("*** Test the revstr() function ***");
    puts("It replaces the contents of a string with the string reversed\n");
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

// Replaces the contents of `str` with the string reversed; use of a VLA array
void revstr(char * str)
{
    int len = 0;
    // Calculate length of the string
    while (*(str + len))
        len++;
    // Check if the string has at least 2 characters therefore can be reversed
    if (len > 1)
    {
        char temp[len];
        // Copy elements of `str` into `temp`
        for (int i = 0; i < len; i++)
            temp[i] = str[i];
        // Replace initial `str` by reversed `temp`
        for (int i = 0; i < len; i++)
            str[i] = temp[len-1 - i];
    }
}
