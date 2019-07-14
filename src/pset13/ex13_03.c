/*
 *  pr_pset13_03.c
 *  A text file copy program that prompts the user to enter the name of src &
 *  dst files. It converts all text to uppercase to the output file.
 *  Created by gres.cher on 03/02/19.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 81

void cptoup(FILE *dst, FILE *src);
char *mygets(char *restrict st, const int n);

int main(void)
{
    int ch;
    char filename[SIZE];
    FILE *src, *dst;
    
    fputs("Enter the name of the source text file:\n", stdout);
    mygets(filename, SIZE);
    if ((src = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fputs("Enter the name of the destination file:\n", stdout);
    mygets(filename, SIZE);
    if ((dst = fopen(filename, "wx")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        if ((dst = fopen(filename, "r")) != NULL)
        {
            fprintf(stderr, "Such file already exists.\n");
            fclose(dst);
        }
        exit(EXIT_FAILURE);
    }
    // Copy text from src to dst file; convert all text as it's written to uppercase
    while ((ch = getc(src)) != EOF)
        putc(toupper(ch), dst);
    if (fclose(src) != 0 || fclose(dst) != 0)
        fprintf(stderr, "Error in closing files.\n");
    
    return 0;
}
// Get a string from standard input
char *mygets(char *restrict st, const int n)
{
    int ch, i;
    
    for (i=0, ch=0; (i < n-1) && ((ch=getc(stdin)) != EOF) && (ch != '\n'); i++)
        st[i] = ch;
    st[i] = '\0';
    if (ch != EOF && ch != '\n')
        while (getchar() != '\n')
            continue;
    if (i > 0)
        return st;
    else
        return NULL;
}
