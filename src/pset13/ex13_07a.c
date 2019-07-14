/*
 *  pr_pset13_07a.c
 *  Opens two files. Prints line 1 of the first file, line 1 of the second
 *  file, line 2 of the first file, line 2 of the second file, and so on, until
 *  the last line of the longer file (in terms of lines) is printed.
 *  Created by gres.cher on 03/23/19.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 81
#define LLEN 1024

void get_name(char * name, const char * st);

int main(int argc, char **argv)
{
    char program_name[SLEN], temp[LLEN];
    FILE *file1, *file2;
    
    // Copy program name without slashes
    get_name(program_name, argv[0]);
    if (argc < 3)
    {
        printf("Usage: %s file1 file2\n", program_name);
        exit(EXIT_FAILURE);
    }
    // Open files
    if ((file1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((file2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Could not open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    // Print line by line
    for (int line = 1; !feof(file1) || !feof(file2); line++)
    {
        if (fgets(temp, LLEN, file1) != NULL)
            fprintf(stdout, "1.%3d %s", line, temp);
        if (fgets(temp, LLEN, file2) != NULL)
            fprintf(stdout, "2.%3d %s", line, temp);
    }
    fclose(file1);
    fclose(file2);
    puts("Done");
    
    return 0;
}
// Copy name without the path slashes
void get_name(char * name, const char * st)
{
    int next_after_slash = 0;
    int i = 0;
    
    // Find location of the last slash symbol
    for (i = 0; st[i] != '\0'; i++)
        if (st[i] == '/')
            next_after_slash = i + 1;
    // Copy string excluding any slash
    strncpy(name, &st[next_after_slash], SLEN);
}
