/*
 *  pr_pset11_07.c
 *  Stephen Prata. C Primer Plus. Chapter 11, exercise 7.
 *
 *  The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1,
 *  truncating s2 or padding it with extra null characters as necessary.
 *  The target string may not be null-terminated if the length of s2 is n
 *  or more. The function returns s1.
 *  Write your own version of this function; call it mystrncpy().
 *  Test the function in a complete program that uses a loop to provide input
 *  values for feeding to the function.
 *
 *  Created by gres.cher on 10/30/18.
 */

#include <stdio.h>

#define SIZE      20
#define STR_INIT  "Initial string."

int getnum(const char * s);
char * mygets(char * s, int n);
char * mystrncpy(char * s1, const char * s2, int n);
void print_char(const char * s, int n);
void print_header(const char * s);
void print_prompt(int n);

int main(void)
{
    int n;
    char tar[SIZE] = STR_INIT;  // Target string
    char src[SIZE];             // Source string
    
    print_header(tar);
    print_prompt(SIZE);
    while (mygets(src, SIZE))
    {
        n = getnum("Enter the number of characters to copy: ");
        printf("\nThe target string's address: %p\n", mystrncpy(tar, src, n));
        printf("The target array of chars has a new value:\n");
        print_char(tar, SIZE);
        printf("\n\n");
        print_prompt(SIZE);
    }
    puts("done");
    return 0;
}

// Print st to prompt user; read integer from input
int getnum(const char * st)
{
    int n;
    
    printf("%s", st);
    while ((scanf("%d", &n)) != 1)
    {
        // Dispose of non-integer input
        scanf("%*s");
        printf("Retry with integer: ");
    }
    // Skip over next characters, including newline
    while (getchar() != '\n')
        continue;
    return n;
}

// Read string; return st address if st[] has at list one character
char * mygets(char * st, int lim)
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

// Copies exactly n characters from s2 to s1
char * mystrncpy(char * s1, const char * s2, int n)
{
    while (n > 0)
    {
        if (*s2)
            *s1++ = *s2++;
        else
            // Length of s2 is less than n
            *s1++ = '\0';
        n--;
    }
    return s1;
}

// Print array of characters; print "\\0" instead of '\0'
void print_char(const char * s, int lim)
{
    for (int i = 0; i < lim; i++) {
        if (s[i] != '\0')
            putchar(s[i]);
        else
            printf("\\0");
    }
}

// Output initial program info
void print_header(const char * st)
{
    printf("*** Test the mystrncpy() function ***\n\n");
    printf("Initial target string's value: \n%s\n\n", st);
}

// Prompt the user for next value
void print_prompt(int lim)
{
    printf("Enter the source string up to %d characters. ", lim);
    printf("(Return to quit):\n");
}
