//
//  pr_pset11_02.c
//
//  Modify and test the function in exercise 1 (pr_pset11_01.c) so that it
//  stops after n characters or after the first blank, tab, or newline,
//  whichever comes first.
//  Don’t just use scanf().
//
//  Created by gres.cher on 10/9/18.
//

#include <stdio.h>
#define SIZE 14

int fetch(char * st, int lim);
void print_fetched(char * st, int length);
void print_header(int fetch_lim);

int main(void)
{
    char input[SIZE];
    int length;
    
    print_header(SIZE);
    while ((length = fetch(input, SIZE)) != 0 && input[0] != '\n')
        print_fetched(input, length);
    puts("done");
    return 0;
}

// Save up to `lim` characters from input; return number of saved characters
int fetch(char * st, int lim)
{
    int c, i;
    
    i = 0;
    while (i < lim && (c = getchar()) != EOF &&
           c != ' ' && c!= '\t' && c!='\n')
    {
        st[i] = c;
        i++;
    }
    
    return i;
}

// Print contents of the array of chars after fetch() call
void print_fetched(char * st, int length)
{
    for (; length; length--)
        putchar(*st++);
    putchar('\n');
}

// Output program info and tell user the number of input characters
void print_header(int lim)
{
    printf("Test the fetch() function. ");
    printf("It saves up to %d characters from input.\n", lim);
    printf("Enter a string (newline to quit):\n");
}
