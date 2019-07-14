/*
 *  spacer.c -- insert spaces between characters
 *  Read in the text file, insert whitespaces and save the result as a file
 *  with a new name that contains the suffix ".spaced".
 *  Created by gres.cher on 4/2/19.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARG_NUM 2   // Command-line arguments
#define EXTENSION ".spaced"
char *preext(char * name, const int nlen, const char * ext);

int main(int argc, char *argv[])
{
    FILE *dst, *src;
    unsigned int name_len, ext_len;
    char *name;
    int ch;
    
    if (argc != ARG_NUM)
    {
        printf("Usage: %s [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // Open source file
    if ((src = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Couldn't open \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    // Allocate string for the filename of destination file
    ext_len = strlen(EXTENSION);
    name_len = (unsigned int) strlen(argv[1]) + ext_len + 1;
    name = (char *) calloc(name_len, sizeof(char));
    strcpy(name, argv[1]);
    // Add pre-extension into the name of destination file
    preext(name, name_len, EXTENSION);
    // Set up output file
    if ((dst = fopen(name, "wx")) == NULL)
    {
        fprintf(stderr, "Couldn't create \"%s\"\n", name);
        if ((dst = fopen(name, "r")) != NULL)
        {
            fprintf(stderr, "Such file already exists\n");
            fclose(dst);
        }
        exit(EXIT_FAILURE);
    }
    // Insert spaces between characters
    while ((ch = getc(src)) != EOF)
    {
        putc(ch, dst);
        if (ch != '\n')
            putc(' ', dst);
    }
    // Close destination file
    if (fclose(dst) != 0)
    {
        fprintf(stderr, "Error closing \"%s\"\n", name);
        exit(EXIT_FAILURE);
    }
    free(name);
    return 0;
}
// Insert the pre-extension into a filename; add it if filename has no extension
char *preext(char *name, int size, const char *subext)
{
    // How many characters are required to shift the extension
    unsigned int shift = (unsigned int) strlen(subext);
    // Check if there is enough space for adding the pre-extension
    if ((shift + (unsigned int) strlen(name) + 1) == size)
    {
        // Look for the beginning of an extension
        int seek = size;
        while (--seek >= 0)
        {
            if (name[seek] == '.')
            {	// Shift original extension to the end of filename
                strcpy(&name[seek + shift], &name[seek]);
                // Insert pre-extension
                strncpy(&name[seek], subext, shift);
                return name;
            }
            if (seek == 0)
            {	// Original filename has no extension
                strcat(name, subext);
                return name;
            }
        }
    }
    return NULL;
}
