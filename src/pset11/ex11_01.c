//
//  pr_pset11_01.c
//
//  Design and test a function that fetches the next n characters from input
//  (including blanks, tabs, and newlines), storing the results in an array
//  whose address is passed as an argument.
//
//  Created by gres.cher on 10/9/18.
//

#include <stdio.h>
#define SIZE 10

int fetch(char * st, int n);
void print_fetched(char * st, int n);
void print_header(int fetch_n);

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

// Save n characters from input to st; return number of saved characters
int fetch(char * st, int n)
{
    int c, i;
    
    for (i = 0; i < n && (c = getchar()) != EOF; i++)
        st[i] = c;
    
    return i;
}

// Print contents of the array of chars after fetch() call
void print_fetched(char * st, int n)
{
    for ( ; n; n--)
        putchar(*st++);
    putchar('\n');
}

// Output program info; n must be equal to the n parameter of fetch()
void print_header(int n)
{
    printf("Test the fetch() function. ");
    printf("It saves %d characters from input.\n", n);
    printf("Enter a string:\n");
}
