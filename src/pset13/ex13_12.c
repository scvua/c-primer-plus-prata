/*
 *  pr_pset13_12.c
 *  Create a text file consisting of 20 rows of 30 integers. The integers
 *  should be in the range 0–9 and be separated by spaces. The file is a
 *  digital representation of a picture, with the values 0 through 9
 *  representing increasing levels of darkness.
 *  Write a program that reads the contents of the file into a 20-by-30 array
 *  of ints. In a crude approach toward converting this digital representation
 *  to a picture, have the program use the values in this array to initialize
 *  a 20-by-31 array of chars, with a 0 value corresponding to a space
 *  character, a 1 value to the period character, and so on, with each larger
 *  number represented by a character that occupies more space. For example,
 *  you might use # to represent 9. The last character (the 31st) in each row
 *  should be a null character, making it an array of 20 strings. Have the
 *  program display the resulting picture (that is, print the strings) and also
 *  store the result in a text file.
 *  Created by gres.cher on 04/07/19.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARGNUM  2
#define LINES  20
#define SIZE   30
#define EXT ".pic"

char * addext(const char *s1, const char *s2);

int main(int argc, char *argv[])
{
    FILE *src, *dst;
    // For digits data from source file
    int digs[LINES][SIZE] = {0};
    // Strings of converted characters (to destination file)
    char strings[LINES][SIZE+1];
    // Name of destination file with add extension
    char *dst_fname;
    
    // Check whether number of arguments is correct
    if (argc != ARGNUM)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // Try to open source file
    if ((src = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Couldn't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    // Generate destination filename; create destination file
    if ((dst_fname = addext(argv[1], EXT)) != NULL)
    {
        if ((dst = fopen(dst_fname, "w")) == NULL)
        {
            fprintf(stderr, "Couldn't create %s\n", dst_fname);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "Couldn't create a destination file\n");
        exit(EXIT_FAILURE);
    }
    // Read the contents of the source file into an array of ints
    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (fscanf(src, "%d", &digs[i][j]) != 1)
                break;
        }
    }
    // Convert digit data to a character strings
    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            switch(digs[i][j])
            {
                case 1:
                    strings[i][j] = '.';
                    break;
                case 2:
                    strings[i][j] = '\'';
                    break;
                case 3:
                    strings[i][j] = ':';
                    break;
                case 4:
                    strings[i][j] = '~';
                    break;
                case 5:
                    strings[i][j] = '*';
                    break;
                case 6:
                    strings[i][j] = '=';
                    break;
                case 7:
                    strings[i][j] = '@';
                    break;
                case 8:
                    strings[i][j] = '%';
                    break;
                case 9:
                    strings[i][j] = '#';
                    break;
                default:
                    strings[i][j] = ' ';
                    break;
            }
        }
        strings[i][SIZE] = '\0';
    }
    // Display the resulting picture and store it into the destination file
    for (int i = 0; i < LINES; i++)
    {
        puts(strings[i]);
        fprintf(dst, "%s\n", strings[i]);
    }
    // Close destination file
    if (fclose(dst) != 0)
        printf("Error in closing file %s\n", dst_fname);
    // Free space that is allocated by addext() call
    free(dst_fname);
    
    return 0;
}
/*
 *  Get source filename and additional extension suffix.
 *  Allocate memory and form a new filename. Insert additional extension into
 *  the filename, or just append it if the source file has no extention.
 */
char * addext(const char *st, const char *ext)
{
    char *strset;
    unsigned int size, exlen;
    
    // Check whether each string has at least one character
    if (st[0] != '\0' && ext[0] != '\0')
    {
        exlen = (unsigned int) strlen(ext);
        // Calculate size of a new string; allocate space initialized with all zeros
        size = (unsigned int) strlen(st) + exlen + 1;
        strset = (char *) calloc(size, sizeof(char));
        strcpy(strset, st);
        // Check whether string has a period character
        for (int seek = size - 1 ; seek >= 0; seek--)
        {
            if (strset[seek] == '.')
            {
                // Shift original extension to the end of the filename
                for (int i = 0, lim = (int) strlen(strset + seek); i < lim; i++)
                {
                    strset[seek + exlen + i] = strset[seek + i];
                }
                // Insert additional extension into the string
                strncpy(&strset[seek], ext, exlen);
                return strset;
            }
            if (seek == 0)
            {
                // Append additional extension
                strcat(strset, ext);
                return strset;
            }
        }
    }
    return NULL;
}
