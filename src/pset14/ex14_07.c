/*
 *  pr_pset14_07.c
 *  Modify Listing 14.14 so that as each record is read from the file and shown
 *  to you, you are given the chance to delete the record or to modify its
 *  contents. If you delete the record, use the vacated array position for
 *  the next record to be read. To allow changing the existing contents, you’ll
 *  need to use the "r+b" mode instead of the "a+b" mode, and you’ll have to pay
 *  more attention to positioning the file pointer so that appended records
 *  don’t overwrite existing records. It’s simplest to make all changes in
 *  the data stored in program memory and then write the final set of
 *  information to the file. One approach to keeping track is to add a member
 *  to the book structure that indicates whether it is to be deleted.
 *  Created by gres.cher on 05/10/19.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FADDR "../../data/book.dat"
#define MAXTITL 60
#define MAXAUTL 40
#define MAXBKS  20              /* maximum number of books */

struct book {                   /* set up book template    */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void eatline(void);
void recedit(struct book *);
void retry(char * key);
char * mygets(char * st, const int n);
char getchoice(char * key);

int main(void)
{
    struct book library[MAXBKS]; // array of structures

    int count = 0;
    int index;
    FILE *pbooks;
    int size = sizeof (struct book);

    char choice;                 // user choice of action to apply to the record
    bool is_changed = false;     // flag that checked if any record is changed

    // Try to open file with records
    if ((pbooks = fopen(FADDR, "r+b")) == NULL)
    {
        printf("Couldn't find %s\nLet's create it\n", FADDR);
        if ((pbooks = fopen(FADDR, "w+b")) == NULL)
        {
            fprintf(stderr, "Can't create \"%s\" file\n", FADDR);
            exit(1);
        }
    }

    rewind(pbooks);            /* go to start of file      */
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if (count == 0 && is_changed == false)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title,
               library[count].author, library[count].value);
        // Prompt the user for choice
        printf("[N]ext line, (E)dit line, (D)elete line\n");
        choice = getchoice("NED");
        switch (choice)
        {
            case 'D':
                // Decrease count and next record will read into the same structure
                --count;
                is_changed = true;
                break;

            case 'E':
                recedit(&library[count]);
                is_changed = true;
                break;

            case 'N':
                break;
        }
        count++;
    }
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.\n", stderr);
        exit(2);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && mygets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        mygets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        eatline();                      /* clear input line  */
        is_changed = true;
        if (count < MAXBKS)
            puts("Enter the next title.");
    }

    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
        if (is_changed)
        {
            printf("Do you want to save changes? (y/n): ");
            choice = getchoice("YN");
            if (choice == 'Y')
            {
                // Close current version of file
                fclose(pbooks);
                // Try to trancate file to zero length
                if ((pbooks = fopen(FADDR, "w+b")) == NULL)
                {
                    fprintf(stderr, "Couldn't save file\n");
                    exit(EXIT_FAILURE);
                }
                // Copy entire array of records to the file from scratch
                fwrite(&library, size, count, pbooks);
            }
        }
    }
    else
        puts("No books? Too bad.\n");

    puts("Bye.\n");
    fclose(pbooks);

    return 0;
}

// Dismiss the rest of the input
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

// Edit structure
void recedit(struct book * pst)
{
    puts("Please enter the book title");
    mygets(pst->title, MAXTITL);
    puts("Now enter the author");
    mygets(pst->author, MAXAUTL);
    puts("Now enter the value: ");
    scanf("%f", &pst->value);
    eatline();
}

// Print the retry request; use characters from the 'key' string
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
char * mygets(char * st, const int n)
{
    int ch, i;

    for (i=0, ch=0; (i < n-1) && ((ch=getchar()) != EOF) && (ch != '\n'); i++)
        st[i] = ch;
    st[i] = '\0';
    if (ch != EOF && ch != '\n')
        while (getchar() != '\n')
            continue;
    if (i > 0)
        return st;
    else
        return NULL;
}

// Get the user's answer and compare it with elements of the `key`
// `key` is a string with option letters: "YN" for 'Y' and 'N' variants
char getchoice(char *key)
{
    char ans;

    while ((ans = getchar()) != EOF)
    {
        // Dismiss a forehead whitespaces if any
        if (isspace(ans))
        {
            if (ans == '\n')
                retry(key);
            continue;
        }
        // Convert to upper and check if answer matches
        ans = toupper(ans);
        eatline();
        if (strchr(key, ans))
            return ans;
        else
            retry(key);
    }
    return ans;
}
