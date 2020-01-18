/*
 *  ex17_01a.c
 *  Modification of Listing 17.2 -- displays the movie list both in the
 *  original order and in reverse order.
 *  Linked-list definition is modified so that list can be traversed in
 *  both directions.
 *  Created by grescher on 01/18/20.
 */

#include <stdio.h>
#include <stdlib.h>         /* has the calloc prototype             */
#include <string.h>         /* has the strcpy prototype             */
#define TSIZE   45          /* size of array to hold title          */

struct film {
    char title[TSIZE];
    int rating;
    struct film * previous;   /* points to previous struct in list  */
    struct film * next;       /* points to next struct in list      */
};

void eatline(void);
void showfilm(const struct film * ps);
char * s_gets(char * st, int n);

int main(void)
{
    struct film * head = NULL;
    struct film * end, * prev, * current;
    char input[TSIZE];
    char choice;

/* Gather and store information             */
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) calloc(1, sizeof(struct film));
        if (current == NULL)
        {
            fprintf(stderr, "Unable to allocate memory!\n");
            exit(EXIT_FAILURE);
        }
        if (head == NULL)       /* first structure       */
        {
            head = current;
            current->previous = NULL;
        }
        else                    /* subsequent structures */
        {
            prev->next = current;
            current->previous = prev;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        eatline();
        puts("Enter next movie title (empty line to stop):");
        end = prev = current;
    }

/* Show list of movies                      */
    if (head == NULL)
        printf("No data entered. ");
    else
    {
        puts("Which order to show?");
        puts("[o]riginal, [r]eversed, [q]uit:");
        while ((choice = getchar()) != 'q')
        {
            if (choice == 'o')
            {
                puts("Here's the original list:");
                current = head;
                while (current != NULL)
                {
                    showfilm(current);
                    current = current->next;
                }
            }
            if (choice == 'r')
            {
                puts("Here's the reversed list:");
                current = end;
                while (current != NULL)
                {
                    showfilm(current);
                    current = current->previous;
                }
            }
            eatline();
            puts("Which order to show?");
            puts("[o]riginal, [r]eversed, [q]uit:");
        }
    }

/* Program done, so free allocated memory.  */
    while (head != NULL)
    {
        current = head->next;
        free(head);
        head = current;
    }
    printf("Bye!\n");

    return 0;
}

/* Dispose of rest of line      */
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

/* Print a film info            */
void showfilm(const struct film * ps)
{
    printf("Movie: %s  Rating: %d\n",
            ps->title, ps->rating);
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');    // look for newline
        if (find)                   // if the address is not NULL,
            *find = '\0';           // place a null character there
        else 
            eatline();
    }
    return ret_val;
}

