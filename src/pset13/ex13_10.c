/*
 *  pr_pset13_10.c
 *  Open a text file. Ask the user to enter file position then print the part
 *  of the file starting at that position and proceed to the next newline
 *  character.
 *  Negative or nonnumeric input terminates the user-input loop.
 *  Created by gres.cher on 03/24/19.
 */

#include <stdio.h>
#include <stdlib.h>
#define SLEN 81

int main(void)
{
    FILE *fp;
    long fpos;
    char name[SLEN];
    char ch;
    
    puts("Enter name of destination file:");
    scanf("%80s", name);
    if ((fp = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Couldn't open \"%s\"\n", name);
        exit(EXIT_FAILURE);
    }
    
    printf("Enter file position (negative or nonnumeric to quit):\n");
    while (scanf("%ld", &fpos) == 1 && fpos >= 0)
    {
        // Clear input line
        while (getchar() != '\n')
            continue;
        // Go to the obtained file position and print line
        fseek(fp, fpos, SEEK_SET);
        while ((ch = getc(fp)) != EOF && ch != '\n')
            putchar(ch);
        putchar('\n');
        printf("Enter next file position: ");
    }
    puts("Done.");
    
    return 0;
}
