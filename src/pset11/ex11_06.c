/*
 *  pr_pset11_06.c:
 *
 *  Write a function called is_within() that takes a character and a string
 *  pointer as its two function parameters. Have the function return a nonzero
 *  value (true) if the character is in the string and zero (false) otherwise.
 *  Test the function in a complete program that uses a loop to provide input
 *  values for feeding to the function.
 *
 *  Created by gres.cher on 10/15/18.
 */

#include <stdio.h>

#define SIZE        21
#define ASK_CHAR    "Enter char to check: "

int getnextch(char * s);
int is_within(int c, const char * s);
char *mygets(char * s, int n);
void print_header(int n);
void print_result(char c, int n);

int main(void)
{
    char input[SIZE];
    
    print_header(SIZE-1);
    if (mygets(input, SIZE))
    {
        int ch;
        while ((ch = getnextch(ASK_CHAR)) != '\n')
            print_result(ch, is_within(ch, input));
    }
    puts("done");
    return 0;
}

// Prints st and return the first character of the input line
int getnextch(char * s)
{
    int ch;
    
    fputs(s, stdout);
    if ((ch = getchar()) == EOF)
        ch = '\n';
    else if (ch != '\n')
        while (getchar() != '\n')
            continue;
    return ch;
}

// If char `c` is within string `st` return its position number
int is_within(int c, const char * st)
{
    for (int i = 0; ; i++)
    {
        if (st[i] == c)
            return (i + 1);
        if (st[i] == '\0')
            return 0;
    }
}

// Read string; return st address if st[] has at list one character
char *mygets(char * st, int lim)
{
    char *ret_val = NULL;
    int c, i;
    
    for (i=0, c=0; i<lim-1 && (c=getchar())!=EOF && c!='\n' && c!='\0'; i++)
        st[i] = c;
    // Mark the end of the string and discard the rest of the line
    if (c == '\n')
        st[i] = '\0';
    else
    {
        st[i] = '\0';
        if (c != EOF)
            while (getchar() != '\n')
                continue;
    }
    if (i > 0)
    /* String has more than '\0' element */
        ret_val = st;
    return ret_val;
}

// Output program info
void print_header(int lim)
{
    printf("*** Test the is_within() function ***\n");
    printf("Enter the string up to %d characters. ", lim);
    printf("(Return to quit):\n");
}

// Print position of `c` if is_within() has >=1 value
void print_result(char c, int n)
{
    if (n)
        printf("\'%c\' is on position %d in the string.\n", c, n);
    else
        printf("\'%c\' is not in the string.\n", c);
}
