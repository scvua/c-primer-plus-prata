/*
 *  pr_pset11_15.c
 *  An implementation of atoi()
 *
 *  Created by gres.cher on 01/12/19.
 */

#include <stdio.h>
#define SIZE 21
#define NUM_FALSE " is equal to 0"
#define NUM_TRUE  "Your number: "
#define THE_END   "Done."

int atoi(const char * s);
char *mygets(char * s, int n);
void print_header(int n);

int main(void)
{
    char input[SIZE];
    int n;

    print_header(SIZE-1);
    while (mygets(input, SIZE))
    {
        n = atoi(input);
        if (n != 0)
            printf("%s%d\n", NUM_TRUE, n);
        else
            printf("`%s`%s\n", input, NUM_FALSE);
        puts("Input new string (Enter key to quit): ");
    }
    puts(THE_END);
    return 0;
}

// Convert alphanumeric to integer; return 0 if the input is not a pure number
int atoi(const char * s)
{
    int n = 0;
    _Bool is_negative = 0;

    for (int i = 0; s[i]; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            // Increase the number value to add next digit
            n *= 10;
            n += s[i] - '0';
            // Check if there is a minus character preceding the number
            if (i > 0 && n > 0 && n < 10 && s[i-1] == '-')
                is_negative = 1;
        }
        else if (n > 0)
            // Number characters are no longer present
            break;
    }
    if (is_negative)
        n = 0 - n;
    return n;
}

// Read string; return st address if st[] has at list one character
char * mygets(char *st, int lim)
{
    int c, i;

    for (i=0, c=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        st[i] = c;
    // Mark the end of the string and discard the rest of the line
    st[i] = '\0';
    if (c != '\n' && c != EOF)
        while (getchar() != '\n')
            continue;
    /* Check if string has more elements than '\0' character */
    if (i > 0)
        return st;
    else
        return NULL;
}

// Print program info and prompt the user for input
void print_header(int lim)
{
    puts("*** Program tests the implementation of an atoi() function ***\n");
    printf("Input string up to %d characters:\n", lim);
}
