/*
 *  pr_pset13_05.c -- appends files to a file
 *  Modification of listing 13.5 so that it uses a command-line interface
 *  instead of interactive interface.
 *  Created by gres.cher on 03/16/19.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
    FILE *fa, *fs;		// fa for append file, fs for source file
    int files = 0;		// number of files appended
    char file_app[SLEN];	// name of append file
    char file_src[SLEN];	// name of source file
    int ch;
    
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s SOURCE... DEST\n", argv[0]);
        fputs("Append SOURCE(s) to DEST\n", stdout);
        exit(EXIT_FAILURE);
    }
    strcpy(file_app, argv[argc-1]);
    if ((fa = fopen(file_app, "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < argc-1; i++)
    {
        strcpy(file_src, argv[i]);
        if (strcmp(file_src, file_app) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", file_src);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s\n", file_src);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s\n", file_app);
            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
        }
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", file_app);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);
    
    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];	// allocate once
    
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
    // Reset buffer contents
    for (int i = 0; i <= BUFSIZE; i++)
        temp[i] = 0;
}
