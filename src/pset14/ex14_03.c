/*
 *  pr_pset14_03.c
 *  Revise the book-listing program in Listing 14.2 so that it prints the book
 *  descriptions in the order entered, then alphabetized by title, and then in
 *  order of increased value.
 *  Created by gres.cher on 04/25/19.
 */

#include <stdio.h>
#include <string.h>

#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100    // maximum number of books

struct book {           // set up book template
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void printbook(struct book * pst[], int lim);
char * mygets(char * st, const int n);
void sort_title(struct book * pst[], int lim);
void sort_value(struct book * pst[], int lim);


int main(void)
{
    struct book library[MAXBKS]; // array of book structures
    struct book * plib[MAXBKS];  // array of pointers to structures of book type
    int count = 0;

    printf("Please enter the book title.\n");
    printf("Press [return] at the start of a line to stop.\n");
    while (count < MAXBKS && mygets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        mygets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count].value);
        plib[count] = &library[count];
        count++;
        while (getchar() != '\n')
            continue;			// clear input line
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0)
    {
        // Print the book descriptions in the order entered
        puts("Here is the list of your books (in the order entered):\n");
        printbook(plib, count);
        // Sort and print in the order alphabetized by title
        puts("\nHere is the list of your books (alphabetized by title):\n");
        sort_title(plib, count);
        printbook(plib, count);
        // Sort and print in the order of increased value
        puts("\nHere is the list of your books (order of increased value):\n");
        sort_value(plib, count);
        printbook(plib, count);
    }
    else
        printf("No books? Too bad.\n");

    return 0;
}

// Print contents of the structure
void printbook(struct book * pst[], int lim)
{
    for (int index = 0; index < lim; index++)
        printf("%s by %s: $%.2f\n", pst[index]->title,
               pst[index]->author, pst[index]->value);
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

// Sort contents of the structure by .title
void sort_title(struct book * pst[], int lim)
{
    int top, seek;
    struct book * temp;

    for (top = 0; top < lim; top++)
        for (seek = top + 1; seek < lim; seek++)
            if (strcmp(pst[top]->title, pst[seek]->title) > 0)
            {
                temp = pst[top];
                pst[top] = pst[seek];
                pst[seek] = temp;
            }
}

// Sort contents of the structure by .value
void sort_value(struct book * pst[], int lim)
{
    int top, seek;
    struct book * temp;

    for (top = 0; top < lim; top++)
        for (seek = top + 1; seek < lim; seek++)
            if (pst[top]->value > pst[seek]->value)
            {
                temp = pst[top];
                pst[top] = pst[seek];
                pst[seek] = temp;
            }
}
