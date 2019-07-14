/*
 *  pr_pset13_01.c
 *  Modified Listing 13.1
 *  Created by gres.cher on 02/28/19.
 */

#include <stdio.h>
#include <stdlib.h> // exit() prototype
#define SIZE 81

char *mygets(char *st, int n);

int main(void)
{
    int ch;         // Place to store each character as read
    FILE *fp;       // File pointer
    unsigned long count;
    char file[SIZE];
    
    printf("Enter file address:\n");
    while (mygets(file, SIZE) != NULL && file[0] != '\0')
    {
        if ((fp = fopen(file, "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s\n", file);
            exit(EXIT_FAILURE);
        }
        for (count = 0; (ch = getc(fp)) != EOF; count++)
            putc(ch, stdout);   // same as putchar(ch);
        fclose(fp);
        fprintf(stdout, "File %s has %lu characters.\n", file, count);
        printf("Next file (empty line to quit):\n");
    }
    fputs("Bye!\n", stdout);
    return 0;
}

char *mygets(char *st, int n)
{
    int i = 0;
    int ch = 0;
    
    while (i < n - 1 && (ch = getc(stdin)) != EOF && ch != '\n')
        st[i++] = ch;
    st[i] = '\0';
    if (ch != EOF && ch != '\n')
        while (getchar() != '\n')
            continue;
    if (i > 0)
        return st;
    else
        return NULL;
}
