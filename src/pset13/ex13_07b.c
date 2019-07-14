/*
 *  pr_pset13_07b.c
 *  Opens two files. Prints line 1 of the first file, line 1 of the second
 *  file, line 2 of the first file, line 2 of the second file, and so on, until
 *  the last line of the longer file (in terms of lines) is printed.
 *  Lines with the same line number are printed on the same line.
 *  Created by gres.cher on 03/23/19.
 */

#include <stdio.h>
#include <stdlib.h>
#define SLEN 81
#define LLEN 1024

char *mygets(char *restrict st, const int n, FILE * fp);

int main(void)
{
    FILE *file1, *file2;
    char temp[LLEN];
    char name[SLEN];
    
    // Open files
    puts("Enter the name of the first file:");
    if (mygets(name, SLEN, stdin) == NULL || (file1 = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Couldn't open file %s\n", name);
        exit(EXIT_FAILURE);
    }
    puts("Enter the name of the second file:");
    if (mygets(name, SLEN, stdin) == NULL || (file2 = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Couldn't open %s\n", name);
        exit(EXIT_FAILURE);
    }
    // Print lines
    for (int line = 1; !feof(file1) || !feof(file2); line++)
    {
        fprintf(stdout, "%3d", line);
        if (s_gets(temp, LLEN, file1) != NULL)
            fprintf(stdout, " %s ", temp);
        if (s_gets(temp, LLEN, file2) != NULL)
            fprintf(stdout, " %s ", temp);
        fputc('\n', stdout);
    }
    fclose(file1);
    fclose(file2);
    puts("Done.");
    
    return 0;
}
// Get a string from fp
char *mygets(char *restrict st, const int n, FILE * fp)
{
    int ch, i;
    
    for (i=0, ch=0; (i < n-1) && ((ch=getc(fp)) != EOF) && (ch != '\n'); i++)
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
