/*
 *  ex17_07: main.c
 *  Write a program that opens and reads a text file and records how many times
 *  each word occurs in the file. Use a binary search tree modified to store
 *  both a word and the number of times it occurs. After the program has read
 *  the file, it should offer a menu with three choices:
 *   1. List all the words along with the number of occurrences.
 *   2. Let you enter the word, with the program reporting how many times
 *      the word occured in the file.
 *   3. Quit
 *  Created by grescher on 04/10/20.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

char * getword(char * st, int n, FILE * fp);
void lowercase(char * st);
bool wordisnew(char * st, Tree * ptree);
bool addword(char * st, Tree * ptree);
void wordcount(char * st, Tree * ptree);
char showmenu(void);
void printall(Tree * ptree);
void printword(Tree * ptree);
void wordinfo(Item item);

int main(int argc, const char * argv[])
{
    const char * filename;
    FILE * fp;
    Tree words;
    char input[SLEN];
    char choice;
    
    // Check whether comman-line arguments contain filename
    if (argc < 2)
    {
        fprintf(stderr, "Usage: ./wordcount <file>\n");
        exit(EXIT_FAILURE);
    }
    else
        filename = *(argv + 1);
    
    // Try to open the file
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "[%s]: Can't open file for read.\n", filename);
        exit(EXIT_FAILURE);
    }
    
    InitializeTree(&words);
   
    // Read the file contents into the tree
    while (getword(input, SLEN, fp) != NULL)
    {
        lowercase(input);
        // Check whether word occurs for the first time
        if (wordisnew(input, &words))
            addword(input, &words);
        else
            wordcount(input, &words);
    }
    printf("\"%s\": the file was read successfully.\n", filename);
    printf("%d words were found.\n", TreeItemCount(&words));
    
    // Print the menu and prompt the user to make a choice
    while ((choice = showmenu()) != 'q')
    {
        switch (choice)
        {
            // List all the words along with the number of occurrences
            case 'a' :  printall(&words);
                        break;
            // Print one word with number of times the word occured
            case 'w' :  printword(&words);
                        break;
            default  :  puts("Switching error");
        }
    }
    
    DeleteAll(&words);
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    puts("Bye!");
    
    return 0;
}

// Get word out of file; word may have an apostrophe or a hyphen
// in itself, but no digits and double hyphens
char * getword(char * st, int n, FILE * fp)
{
    int ch = EOF;           // current character
    int prev_ch = EOF;      // previous character
    int i = 0;              // string index
    bool inword = false;    // first letter indicator

    for (int lim = n-1; i<lim && (ch=getc(fp)) != EOF; prev_ch = ch)
    {
        if (isalpha(ch))
        {
            // Check whether ch is the first letter of a word
            if (!inword)
                inword = true;
        }
        // Skip word if it contains any digit
        else if (isdigit(ch))
        {
            // Reset word status and dispose of rest of the current word
            i = 0;
            inword = false;
            while (!isspace(getc(fp)))
                continue;
            continue;
        }
        else
        {
            // Skip preceding whitespaces if any
            if (!inword)
                continue;
            
            // Case for hyphenated words and compound words
            if (ch == '\'' || ch == '-')
            {
                if (!isalpha(prev_ch))
                {
                    // Previous character isn't a letter
                    // delete previous apostrophe or hyphen character
                    i--;
                    break;                                              //-->
                }
            }
            else
                break;  // End of the word                              //-->
        }
        st[i++] = ch;
    }
    if (ch == EOF && i == 0)
        return NULL;        // Quit function on the file end            //-->
    st[i] = '\0';
    
    return st;
}

// Convert string to lower case
void lowercase(char * st)
{
    while (*st != '\0')
    {
        *st = tolower(*st);
        st++;
    }   
}

// Check whether the word is new and it's not in the tree
bool wordisnew(char * st, Tree * ptree)
{
    Item temp;

    temp.word = st;
    temp.count = 0;

    return (InTree(&temp, ptree) == NULL);
}

// Add new word to the tree
bool addword(char * st, Tree * ptree)
{
    Item new_item;
    char * new_word;

    new_word = (char *) calloc(strlen(st) + 1, sizeof(char));
    if (new_word == NULL)
    {
        fprintf(stderr, "Couldn't create word \'%s\' in a tree", st);
        return false;                                                   //-->
    }
    if (!strcpy(new_word, st))
        return false;                                                   //-->
    new_item.word = new_word;
    new_item.count = 1;

    return AddItem(&new_item, ptree);
}

// Word is in the tree; increase word's counter by 1
void wordcount(char * st, Tree * ptree)
{
    Item temp;
    Trnode * find;

    temp.word = st;
    temp.count = 0;

    find = InTree(&temp, ptree);
    if (find != NULL)
    {
        find->item.count++;
    }
}

char showmenu(void)
{
    int choice;

    puts("Enter the letter corresponding to your choice:");
    puts("a) list all the words");
    puts("w) one word report");
    puts("q) quit");

    while ((choice = getchar()) != EOF)
    {
        // Skip preceding whitespace if any
        if (!isalpha(choice))
            continue;
        // Dispose of rest of line
        while (getchar() != '\n')
            continue;
        choice = tolower(choice);
        if (!strchr("awq", choice))
            puts("Please enter a, w, or q:");
        else
            break;
    }
    // Make EOF cause program to quit
    if (choice == EOF)
        choice = 'q';
        
    return (char) choice;
}

// Print all tree
void printall(Tree * ptree)
{
    puts("Here's all the words I've read:");
    puts("Count\tWord\n");
    Traverse(ptree, wordinfo);
}

// Prompt the user for the word; print its info
void printword(Tree * ptree)
{
    char input[SLEN];
    Item tempItem;
    Trnode * pNode;

    // Prompt the user
    do {
        puts("Please, enter the word:");
    }
    while (getword(input, SLEN, stdin) == NULL);
    // Fill up a temporary Item for search
    tempItem.word = input;
    tempItem.count = 0;
    // Search for the word
    if ((pNode = InTree(&tempItem, ptree)) != NULL)
    {
        printf("Count\tWord\n");
        wordinfo(pNode->item);
    }
    else
        printf("%s: Word is not in the tree.\n", input);
}

// Print word with the number of occurances
void wordinfo(Item item)
{
    printf("%4d\t%s\n", item.count, item.word);
}
