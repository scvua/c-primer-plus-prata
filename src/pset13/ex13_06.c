/*
 *  pr_pset13_06.c -- reduces your files by two-thirds
 *  Modification of listing 13.2 so that it prompts the user for the required
 *  information.
 *  Created by gres.cher on 03/16/19.
 */

#include <stdio.h>
#include <stdlib.h>   // for exit()
#include <string.h>
#define LEN 81

char *mygets(char *restrict st, const int n);

int main(void)
{
    FILE *in, *out;   // declare two FILE pointers
    int ch;
    char name[LEN];   // storage for output filename
    int count = 0;
    
    fputs("Enter the name of file to condense:\n", stdout);
    mygets(name, LEN);
    // set up input
    if ((in = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", name);
        exit(EXIT_FAILURE);
    }
    // set up output
    if (strlen(name) > LEN - 5)
        name[LEN - 5] = '\0';
    strcat(name, ".red");            // append .red
    if ((out = fopen(name, "w")) == NULL)
    {                       // open file for writing
        fprintf(stderr, "Can't create output file.\n");
        exit(EXIT_FAILURE);
    }
    // copy data
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);	// print every 3rd char
    // clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");
    
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
