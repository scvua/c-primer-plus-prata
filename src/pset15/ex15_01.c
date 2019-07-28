/*
 *  pr_pset15_01.c
 *  Function that converts a binary string to a numberic value.
 *  Created by gres.cher on 07/28/19.
 */
#include <stdio.h>
#define SIZE 33
int bstoi(char * bst);
char * getbs(char * st, const int n);

int main(void)
{
    char bst[SIZE];

    puts("Enter binary and see them in decimal.");
    puts("Empty line terminates program.");
    while (getbs(bst, SIZE) != NULL && bst[0] != '\0')
        printf("%s is %d\n", bst, bstoi(bst));
    puts("Bye.");

    return 0;
}

// Convert a binary string to a numberic value
int bstoi(char * bst)
{
    int num;

    for (num = 0; *bst != '\0'; bst++)
    {
        num <<= 1;
        if (*bst == '1')
            num++;      // add 1 to the 0th bit
        else if (*bst != '0')
            break;
    }
    return num;
}

// Get a string of 0s and 1s from standard input
char * getbs(char * st, const int n)
{
    int ch = 0;
    int i = 0;

    while (i < n-1 && (ch=getchar()) != '\n')
    {
        if (ch == '0' || ch == '1')
            st[i++] = ch;
        else
        {
            fprintf(stderr, "[Input error]: '0' and '1' only.\n");
            // Reset the index so that the function returns NULL
            i = 0;
            break;
        }
    }
    st[i] = '\0';
    // Dispose of the rest of the line
    if (ch != '\n')
        while (getchar() != '\n')
            continue;
    if (i > 0)
        return st;
    else
        return NULL;
}
