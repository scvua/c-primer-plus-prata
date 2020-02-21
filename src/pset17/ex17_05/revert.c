/*
 *  revert.c (ex17_05)
 *  Displays the string in reverse order.
 *  Input string, then push the characters of the string onto a stack,
 *  one by one, and then pop the characters from the stack and display them.
 *  Created by grescher on 02/21/20.
 */
#include "stack.h"
#include <stdio.h>
#include <string.h>

#define SLEN 81     /* length of the string */

char * s_gets(char * st, int n);

int main(void)
{
    char input[SLEN];
    char output[SLEN];
    int nframes;
    int i;
    Stack charStack;

    InitializeStack(&charStack);
    puts("Enter the string to revert:");
    while (s_gets(input, SLEN) != NULL && input[0] != '\0')
    {
    // Fill stack with input
        for (i = 0; input[i] != '\0'; i++)
        {   
            if (PushItem(input[i], &charStack) == false)
            {
                fprintf(stderr, "Problem allocating memory\n");
                break;                                          //-->   
            }
        }

    // Get a number of the stack frames
        nframes = StackItemCount(&charStack);
        
    // Empty stack to output
        for (i = 0; !StackIsEmpty(&charStack); i++)
        {
            if (PopItem(&output[i], &charStack) == false)
            {
                fprintf(stderr, "Can't read the frame\n");
                break;                                          //-->
            }
        }
        output[i] = '\0';       /* finalize output string   */
        
    // Print results
        puts("\nOriginal string:"); 
        puts(input);
        puts("Reverted string:");
        puts(output);
        printf("Stack has %d %s\n", nframes,
                nframes == 1 ? "frame" : "frames");
        puts("\nEnter a next string (empty line to quit):");
    }
    EmptyTheStack(&charStack);
    puts("Bye!");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

