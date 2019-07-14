/*
 *  pr_pset13_02.c -- fread() & fwrite() implementation
 *  File-copy program that takes the original filename and the copy file from
 *  the command line.
 *  Created by gres.cher on 03/01/19.
 */

#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024
void cpfile(FILE *dst, FILE *src);

int main(int argc, char *argv[])
{
    FILE *src_file, *dst_file;
    
    // Check command-line arguments
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s [src] [dst]\n", argv[0]);
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
    // Create buffer for destination file
    if (setvbuf(dst_file, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fprintf(stderr, "Can't create an output buffer.\n");
        exit(EXIT_FAILURE);
    }
    cpfile(dst_file, src_file);
    // Close files
    if (fclose(src_file) != 0 || fclose(dst_file) != 0)
        fprintf(stderr, "Error in closing files.\n");
    else
        fputs("Done.\n", stdout);
    
    return 0;
}
// Copy contents of src file into dst file
void cpfile(FILE *dst, FILE *src)
{
    size_t bytes;
    static char temp[BUFSIZE];
    
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, src)) > 0)
        fwrite(temp, sizeof(char), bytes, dst);
}
