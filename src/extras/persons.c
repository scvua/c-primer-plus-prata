/*
 *  persons.c
 *  Test program for exercise 14.7. Print contents of the file line-by-line.
 *  After each line prompt the user to edit or delete it.
 *  Uses tmpfile() function and the save file menu.
 *  Created by gres.cher on 5/9/19.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30

struct person {
    int id;
    char name[SIZE];
};

void eatline(void);
char getchoice(char *key);
void printfile(FILE * fp);
void retry(char *key);
char * mygets(char * restrict st, const int n);

int main(int argc, char *argv[])
{
    char choice;
    int count = 0;
    FILE *file, *tmp;
    bool file_is_changed = false;
    struct person emp;
    size_t size_emp = sizeof(struct person);
    
    // Check the number of arguments and try to open file
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s [file]\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((file = fopen(argv[1], "r+b")) == NULL)
    {
        fprintf(stderr, "%s doesn't exist\n", argv[1]);
        fprintf(stderr, "Creating a new file\n");
        if ((file = fopen(argv[1], "w+b")) == NULL)
        {
            fprintf(stderr, "Couldn't create %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    if ((tmp = tmpfile()) == NULL)
    {
        fprintf(stderr, "Couldn't create a temporary file\n");
        exit(EXIT_FAILURE);
    }
    
    // Print contents of the file line by line; ask the user for action
    rewind(file);
    while ((fread(&emp, size_emp, 1, file)) == 1)
    {
        if (count == 0)
            printf("Contents of the file:\n");
        printf("%2d %s\n", emp.id, emp.name);
        printf("[N]ext line, (E)dit line, (D)elete line\n");
        switch (choice = getchoice("NED"))
        {
                // Next line: copy line to the tmpfile without changes
            case 'N':
                fwrite(&emp, size_emp, 1, tmp);
                break;
                
                // Edit line: change and then copy the line to the tmpfile
            case 'E':
                printf("Input a person's name: ");
                mygets(emp.name, SIZE);
                printf("Input a person id: ");
                while (scanf("%d", &emp.id) != 1 || emp.id < 1)
                    printf("Please, retry with a positive number: ");
                eatline();
                // Write data to a temporary file
                fwrite(&emp, size_emp, 1, tmp);
                if (!file_is_changed)
                    file_is_changed = true;
                break;
                
                // Delete line: skip line from copying it to the tmpfile
            case 'D':
                if (!file_is_changed)
                    file_is_changed = true;
                break;
        }
        count++;
    }
    
    // Close the original file; keep working with a temporary file
    fclose(file);
    // Input new data lines
    printf("Input a person's name ([return] to quit):\n");
    while (mygets(emp.name, SIZE) != 0 && emp.name[0] != '\0')
    {
        // Prompt for id
        printf("Input a person id:\n");
        while (scanf("%d", &emp.id) != 1 || emp.id < 1)
            printf("Please, retry with a positive number: ");
        eatline();
        // Write data to file
        fwrite(&emp, size_emp, 1, tmp);
        // Prompt the user for next value
        if (!file_is_changed)
            file_is_changed = true;
        printf("Input next person's name:\n");
    }
    
    // Print contents of the temporary file
    rewind(tmp);
    printfile(tmp);
    // Prompt the user for saving changes
    printf("Do you want to save changes?\n[Y]es/[N]o: ");
    switch (choice = getchoice("YN"))
    {
        case 'Y':
            // Try to trancate file to zero length
            if ((file = fopen(argv[1], "w+b")) == NULL)
            {
                fprintf(stderr, "Couldn't save file\n");
                exit(EXIT_FAILURE);
            }
            rewind(tmp);
            while ((fread(&emp, size_emp, 1, tmp)) == 1)
                fwrite(&emp, size_emp, 1, file);
            fclose(file);
            
        case 'N':
            fclose(tmp);
            break;
    }
    // Finish program execution
    printf("Done.\n");
    
    return 0;
}

// Dismiss the rest of the input
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

// Get char from the input; transform it into upper case and compare to the key
char getchoice(char *key)
{
    char ch;
    
    while ((ch = getchar()) != EOF)
    {
        // Skip forehead whitespace
        if (isspace(ch))
        {
            // Print a retry request at the end of an input line
            if (ch == '\n')
                retry(key);
            continue;
        }
        ch = toupper(ch);
        eatline();
        if (strchr(key, ch) == NULL)
            retry(key);
        else
            return ch;
    }
    return ch;
}

// Print contents of the file
void printfile(FILE * fp)
{
    struct person tmp;
    int count = 0;
    size_t size = sizeof (struct person);
    
    while (fread(&tmp, size, 1, fp) == 1)
    {
        if (count == 0)
        {
            printf("Current contents of the file:\n");
            printf("id\tName\n");
        }
        printf("%2d\t%s\n", tmp.id, tmp.name);
        count++;
    }
}

// Print the retry request with the list of proper variants (of key string)
void retry(char * key)
{
    bool is_last;
    
    printf("Please use");
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (key[i + 1] == '\0')
            is_last = true;
        else
            is_last = false;
        printf("%s", is_last ? " or " : " ");
        putchar(key[i]);
        printf("%s", is_last ? ":\n" : ",");
    }
}

// Get a string from standard input
char * mygets(char *restrict st, const int n)
{
    int ch, i;
    
    for (i=ch=0; (i < n-1) && ((ch=getchar()) != EOF) && (ch != '\n'); i++)
        st[i] = ch;
    st[i] = '\0';
    if (ch != EOF && ch != '\n')
        eatline();
    if (i > 0)
        return st;
    else
        return NULL;
}
