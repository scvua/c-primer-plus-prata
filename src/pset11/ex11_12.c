/*
 *  pr_pset11_12.c
 *
 *  Write a program that reads in up to EOF and reports the number of words,
 *  the number of uppercase letters, the number of lowercase letters,
 *  the number of punctuation characters, and the number of digits.
 *
 *  Created by gres.cher on 01/10/19.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void print_header(void);
void print_result(int w, int u, int l, int p, int d);

int main(void)
{
    int ch;
    int nword = 0;          // Number of words
    int nupper = 0;         // Number of uppercase letters
    int nlower = 0;         // Number of lowercase letters
    int npunct = 0;         // Number of punctuation characters
    int ndigit = 0;         // Number of digits
    bool isword = false;    // Flag for sequence of characters without spaces
    
    print_header();
    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            nupper++;
        if (islower(ch))
            nlower++;
        if (ispunct(ch))
            npunct++;
        if (isdigit(ch))
            ndigit++;
        if (isspace(ch))
        {
            isword = false;
        }
        else if (!isword)
        {
            nword++;
            isword = true;
        }
    }
    print_result(nword, nupper, nlower, npunct, ndigit);
    return 0;
}

// Output initial program info
void print_header(void)
{
	puts("*** Program that counts characters and words ***\n");
	puts("Input some text below (EOF to quit):");
}

// Output program results
void print_result(int nw, int nu, int nl, int np, int nd)
{
	printf("      Words: %d\n", nw);
	printf("  Uppercase: %d\n", nu);
	printf("  Lowercase: %d\n", nl);
	printf("Punctuation: %d\n", np);
	printf("     Digits: %d\n", nd);
}

