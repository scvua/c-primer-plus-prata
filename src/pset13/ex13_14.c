/*
 *  pr_pset13_14.c
 *  Add deglitching function to exercise 13_12. It should compare each value to
 *  its immediate neighbors to the left and right, above and below. If the
 *  value differs by more than 1 from each of its neghbors, replace the value
 *  with the average of the neighboring values. You should round the average to
 *  the nearest integer value.
 *  Created by gres.cher on 04/13/19.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARGNUM  2
#define EXT ".pic"

char * addext(const char *s1, const char *s2);
int average(float sum, int count);
void convert(const int rows, const int cols, char st[][cols+1], const int dig[][cols]);
void deglitch(int lines, int size, int ar[][size]);
int glitchck(const int d1, const int d2);
int heightchck(FILE * fp);
int	widthchck(FILE * fp);

int main(int argc, char *argv[])
{
    FILE *src, *dst;
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
    // Get dimensions of the source file
    const int lines = heightchck(src);
    const int size = widthchck(src);
    
    // Check whether source file has inappropriate dimensions
    if (lines == 0 || size == 0)
    {
        fprintf(stderr, "Source file has inappropriate dimensions\n");
        exit(EXIT_FAILURE);
    }
    // As the source is ok; generate destination filename and create the file
    dst_fname = addext(argv[1], EXT);
    if ((dst = fopen(dst_fname, "w")) == NULL)
    {
        fprintf(stderr, "Couldn't create destination file.\n");
        exit(EXIT_FAILURE);
    }
    
    // Set VLA for digits data from source file
    int digs[lines][size];
    // Set VLA for strings of converted characters (to destination file)
    char strings[lines][size+1];
    
    // Read the contents of the source file into an array of ints
    rewind(src);
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (fscanf(src, "%d", &digs[i][j]) != 1)
                break;
        }
    }
    // Run de-glitching function
    deglitch(lines, size, digs);
    // Convert digits to strings
    convert(lines, size, strings, digs);
    // Display the resulting picture and store it into the destination file
    for (int i = 0; i < lines; i++)
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
// Calculate average of counted values and round it to the nearest integer value
int average(float sum, int count)
{
    float aver = sum / (float) count;
    // If average has 5 tenths or more increase it by 1
    if (aver - (int) aver >= 0.5)
        aver++;
    // Because of casting to int the decimals will be ignored
    return (int)aver;
}
// Convert digit data to a character strings
void convert(const int rows, const int cols, char st[][cols+1], const int dig[][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            switch(dig[i][j])
            {
                case 1:
                    st[i][j] = '.';
                    break;
                case 2:
                    st[i][j] = '\'';
                    break;
                case 3:
                    st[i][j] = ':';
                    break;
                case 4:
                    st[i][j] = '~';
                    break;
                case 5:
                    st[i][j] = '*';
                    break;
                case 6:
                    st[i][j] = '=';
                    break;
                case 7:
                    st[i][j] = '@';
                    break;
                case 8:
                    st[i][j] = '%';
                    break;
                case 9:
                    st[i][j] = '#';
                    break;
                default:
                    st[i][j] = ' ';
                    break;
            }
        }
        // End up the row with a null character to make it string
        st[i][cols] = '\0';
    }
}
/*
 *  Compare each value to its immediate neighbors. If the value differs by more
 *  than 1 from each of its neighbors, replace the value with the average of the
 *  neighboring values (average to the nearest integer value).
 */
void deglitch(int rows, int cols, int ar[][cols])
{
    bool isglitched;
    int r, c, count;
    float sum;
    
    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < cols; c++)
        {
            isglitched = false;
            
            // Check if ar[r][c] differs by more than 1 from each of its neighbors
            if (r != 0 && !isglitched)
            {
                if (glitchck(ar[r][c], ar[r-1][c]))
                    isglitched = true;
            }
            if (r != rows - 1 && !isglitched)
            {
                if (glitchck(ar[r][c], ar[r+1][c]))
                    isglitched = true;
            }
            if (c != 0 && !isglitched)
            {
                if (glitchck(ar[r][c], ar[r][c-1]))
                    isglitched = true;
            }
            if (c != cols - 1 && !isglitched)
            {
                if (glitchck(ar[r][c], ar[r][c+1]))
                    isglitched = true;
            }
            
            if (isglitched)
            {
                // Replace ar[r][c] value with the average of its neighboring values
                count = 0;
                sum = 0.0;
                
                if (r != 0)
                {
                    count++;
                    sum += (float) ar[r-1][c];
                }
                if (r != rows - 1)
                {
                    count++;
                    sum += (float) ar[r+1][c];
                }
                if (c != 0)
                {
                    count++;
                    sum += (float) ar[r][c-1];
                }
                if (c != cols - 1)
                {
                    count++;
                    sum += (float) ar[r][c+1];
                }
                ar[r][c] = average(sum, count);
            }
        }
    }
}
// Check whether the difference between digits greater than 1
int glitchck(const int d1, const int d2)
{
    int diff = d1 - d2;
    if (diff < -1 || diff > 1)
        // Difference between d1 and d2 is bigger than 1
        return 1;
    else
        // Difference is 0 or 1
        return 0;
}
// Checks how many lines the file has (count newline characters)
int heightchck(FILE * fp)
{
    int ch;
    // Number of lines
    int lnum = 0;
    
    // Go to the beginning of the file
    rewind(fp);
    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n')
            lnum++;
    }
    return lnum;
}
/*
 * Check how many digits (columns) the line has. Compare every next line to the
 * first one.
 * If lines have the same length return number of columns else return 0
 */
int	widthchck(FILE * fp)
{
    int ch;
    // Number of columns in a file
    int cols = 0;
    
    // Go to the beginning of the file
    rewind(fp);
    // Check number of digits in the first line
    while ((ch = getc(fp)) != '\n')
    {
        if (isdigit(ch))
            cols++;
    }
    // Compare the number of digits in the next lines with the number of digits
    // in the first line
    for (int dnum = 0; (ch = getc(fp)) != EOF; )
    {
        if (isdigit(ch))
            dnum++;
        if (ch == '\n')
        {
            // Current line has the same number of digits as the first line
            if (dnum == cols)
            {
                // Reset dnum for the next line check
                dnum = 0;
            }
            else
                return 0;
        }
    }
    return cols;
}
