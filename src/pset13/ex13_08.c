/*
 *  pr_pset13_08.c
 *  Program that takes as CL arguments a character and zero or more filenames.
 *  If no arguments follow the character, program reads the stdin. Otherwise,
 *  it opens each file in turn and report how many times the character appears
 *  in each file.
 *  Created by gres.cher on 03/23/19.
 */

#include <stdio.h>
#include <stdlib.h>

unsigned int counter(FILE * fp, const char find);

int main(int argc, char **argv)
{
    FILE *fp;
    char find_c;          // Value of character to find
    unsigned int nchars;  // Number of the character appears
    
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s [char] [file...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    find_c = argv[1][0];
    if (argc == 2)
    {
        // No arguments follow the character. Read standard input.
        printf("No file addresses were given. Read the standard input:\n");
        nchars = counter(stdin, find_c);
        fprintf(stdout, "[Standard input]: '%c' appears %u %s\n",
                find_c, nchars, nchars == 1 ? "time" : "times");
    }
    else
    {
        // Open each file from argv[2] up to argv[argc-1] addresses
        for (int i = 2; i < argc; i++)
        {
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Couldn't open the file %s\n", argv[i]);
                continue;
            }
            nchars = counter(fp, find_c);
            fprintf(stdout, "[%s]: '%c' appears %u %s\n", argv[i],
                    find_c, nchars, nchars == 1 ? "time" : "times");
            fclose(fp);
        }
    }
    return 0;
}
// Count how many times character is appeared in the file
unsigned int counter(FILE * fp, const char find)
{
    int ch;
    unsigned int count = 0L;
    
    while ((ch = getc(fp)) != EOF)
        if (ch == find)
            count++;
    return count;
}
