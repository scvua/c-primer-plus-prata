/*
 *  filecopy.c -- getc() & putc() implementation of the exercise 13.2
 *  File-copy program that takes the original filename and the copy file from
 *  the command line.
 *  Created by gres.cher on 03/01/19.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *src_file, *dst_file;
    int ch;
    
    // Check command-line arguments
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s src-file dst-file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // Open source file
    if ((src_file = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    // Open destination file
    if ((dst_file = fopen(argv[2], "wbx")) == NULL)
    {
        fprintf(stderr, "Can't create %s\n", argv[2]);
        // Check if the file could be opened in the read mode
        if ((dst_file = fopen(argv[2], "rb")) != NULL)
        {
            fprintf(stderr, "Such file already exists.\n");
            fclose(dst_file);
        }
        exit(EXIT_FAILURE);
    }
    // Copy contents of src_file into dst_file
    while ((ch = getc(src_file)) != EOF)
        putc(ch, dst_file);
    // Close files
    if (fclose(src_file) != 0 || fclose(dst_file) != 0)
        fprintf(stderr, "Error in closing files.\n");
    else
        fputs("Done.\n", stdout);
    
    return 0;
}
