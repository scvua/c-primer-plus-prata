/*
 *  pr_pset13_09.c -- uses fprintf(), fscanf(), and rewind()
 *  Modification of lisdting 13.3 so that each word is numbered according to
 *  the order in which it was added to the list. When the program is run
 *  a second time, new word numbering resumes where the previous numbering
 *  left off.
 *  Created by gres.cher on 03/24/19.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX];
    int wordnum = 0;
    int ch;
    
    if ((fp = fopen("wordy.txt", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    // Go to the beginning of the file and check if there are lines
    fseek(fp, 0L, SEEK_SET);
    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n')
            // Try to get a number at the beginning of next line
            fscanf(fp, "%d", &wordnum);
    }
    // Input new words
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%3d %s\n", ++wordnum, words);
    
    puts("File contents:");
    rewind(fp);           /* go back to beginning of file */
    while (fgets(words, MAX, fp) != NULL)
        fputs(words, stdout);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    
    return 0;
}
