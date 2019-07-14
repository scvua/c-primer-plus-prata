/*
 *  pr_pset13_11.c
 *  Search the file, print all lines containing the string.
 *  No lines are longer than 255 characters.
 *  Created by gres.cher on 03/24/19.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 81
#define LLEN 255

void copy_name(char * name, const char * st, const int lim);

int main(int argc, char **argv)
{
    FILE *fp;
    char line[LLEN];
    unsigned int nline = 0;
    char program_name[SLEN];
    char *seek_string;
    bool string_is_found = false;
    
    copy_name(program_name, argv[0], SLEN);
    if (argc < 3)
    {
        printf("Usage: ./%s string file\n", program_name);
        exit(EXIT_FAILURE);
    }
    // Open file with argv[2] address
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Couldn't open \"%s\"\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    // Search the file for seek_string
    seek_string = argv[1];
    while (fgets(line, LLEN, fp) != NULL)
    {
        nline++;
        if (strstr(line, seek_string) != NULL)
        {
            if (string_is_found == false)
            {	// At least there is one match with searched string
                string_is_found = true;
                printf("\"%s\" is found in these lines:\n", seek_string);
            }
            printf("%3d: %s", nline, line);
        }
    }
    if (!string_is_found)
        printf("There is no \"%s\" in the file.\n", seek_string);
    
    return 0;
}
// Copy name without address slashes
void copy_name(char * name, const char * st, const int lim)
{
    int next_after_slash = 0;
    int i = 0;
    
    // Find location of the last slash symbol
    for (i = 0; st[i] != '\0'; i++)
        if (st[i] == '/')
            next_after_slash = i + 1;
    // Copy string excluding any slash up to lim characters
    strncpy(name, &st[next_after_slash], lim-1);
    name[lim-1] = '\0';
}
