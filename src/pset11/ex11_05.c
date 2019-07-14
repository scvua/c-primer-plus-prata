/*
 *  pr_pset11_05.c
 *
 *  Design and test a function that searches the string specified by the first
 *	function parameter for the first occurrence of a character specified by
 *	the second function parameter. Have the function return a pointer to
 *	the character if successful, and a null if the character is not found in
 *	the string.
 *	(This duplicates the way that the library strchr() function works.)
 *	Test the function in a complete program that uses a loop to provide input
 *	values for feeding to the function.
 *
 *  Created by gres.cher on 10/14/18.
 */

#include <stdio.h>

#define SIZE	21
#define ASK_CHAR "Enter char to look for: "

void checkstr(char * s, char * f);
int getnextch(char * s);
char *mygets(char * s, int n);
char *mystrchr(const char * s, int c);
void print_header(int n);

int main(void)
{
    char input[SIZE];
    
    print_header(SIZE-1);
    if (mygets(input, SIZE))
    {
        int ch;
        while ((ch = getnextch(ASK_CHAR)) != '\n')
            checkstr(input, mystrchr(input, ch));
    }
    puts("done");
    return 0;
}

// Print address of `f` and calculate its place in the string `st`
void checkstr(char * st, char * f)
{
    if (f)
    {
        printf("Character address: %p\n", f);
        printf("It's %ld place in the string.\n", (f-st)+1);
    }
    else
    {
        printf("Character is not found in the string.\n");
    }
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

// Search st for the first occurence of c; return ptr to st[i]=c else return 0
char *mystrchr(const char * st, int c)
{
    for (; *st; st++)
    {
        if (*st == c)
            return ((char *) st);
    }
    return NULL;
}

// Output program info
void print_header(int lim)
{
    printf("*** Test the mystrchr() function ***\n");
    printf("Enter the string up to %d characters. ", lim);
    printf("(Return to quit):\n");
}
