/*
 *  pr_pset12_09.c
 *  Program that asks you how many words you wish to enter. Then it has you
 *  enter the words, and then it displays the words. Use malloc() and the
 *  answer to the first question (the number of words) to create a dynamic
 *  array of the corresponding number of pointers-to-char.
 *  Created by gres.cher on 02/15/19.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void dispose(void);
char *getword(void);

int main(void)
{
    int max;
    char **words;

    printf("How many words do you wish to enter? ");
    while (scanf("%d", &max) == 1 && max > 0)
    {
        dispose();
        // Allocate space for `max` pointers-to-a-char
        words = (char **) malloc(max * sizeof(char *));
        // Collect input to words[]
        printf("Enter %d words now:\n", max);
        for (int i = 0; i < max; i++)
            words[i] = getword();
        // Display every word in a new line
        puts("Here are your words:");
        for (int i = 0; i < max; i++)
        {
            if (words[i])
                puts(words[i]);
        }
        // Free memory used by words[]
        for (int i = 0; i < max; i++)
            free(words[i]);
        free(words);
        printf("How many words? (0 to quit): ");
    }
    puts("Done.");
    return 0;
}
// Dispose of undesirable input
void dispose(void)
{
    while (getchar() != '\n')
        continue;
}
// Collect characters; return address of the string or NULL if there no input
char * getword(void)
{
    int ch;
    int count = 0;
    int size = 10;
    char * ptword;
    char buffer[size];

    // Skip preceding whitespace, if any
    while (isspace(ch = getchar()))
    {
        if (ch == '\n')
            return NULL;
    }
    // Collect the sequence of characters to buffer up to the first space char
    do
    {
        buffer[count++] = ch;
    }
    while (count < size && (ch = getchar()) != EOF && !isspace(ch));
    // If word is bigger than the buffer size dispose characters that left
    if (count == size)
    {
        while (!isspace(getchar()))
            continue;
    }
    // Allocate memory for the `count` elements + 1 for '\0' char
    ptword = (char *) malloc((count + 1) * sizeof(char));
    if (ptword)
    {
        int i;
        // Copy the buffer contents to the new string
        for (i = 0; i < count; i++)
            ptword[i] = buffer[i];
        ptword[i] = '\0';
    }
    return ptword;
}
