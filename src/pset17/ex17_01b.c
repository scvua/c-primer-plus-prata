/*
 *  ex17_01b.c
 *  Modification of Listing 17.2 -- displays the movie list both in the
 *  original order and in reverse order. The recursion use approach.
 *  Created by grescher on 01/17/20.
 */

#include <stdio.h>
#include <stdlib.h>     /* has the calloc prototype         */
#include <string.h>     /* has the strcpy prototype         */
#define TSIZE   45      /* size of array to hold title      */

struct film {
    char title[TSIZE];
    int rating;
    struct film * next;   /* points to next struct in list  */
};

void eatline(void);
void print_list(const struct film * ps);
void print_reversed_list(const struct film * ps);
char * s_gets(char * st, int n);

int main(void)
{
    struct film * head = NULL;
    struct film * prev, * current;
    char input[TSIZE];
    char choice;
    
/* Gather and store information             */
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) calloc(1, sizeof(struct film));
        if (current == NULL)
        {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        if (head == NULL)          /* first structure       */
            head = current;
        else                       /* subsequent structures */
            prev->next = current;
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>: ");
        scanf("%d", &current->rating);
        eatline();
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }
    
/* Show list of movies                      */
    if (head == NULL)
        printf("No data entered. ");
    else
    {
        puts("Which order to show?");
        puts("[o]riginal, [r]everse, [q]uit:");
        while ((choice = getchar()) != 'q')
        {
            if (choice == 'o')
            {
                printf("Here is the original movie list:\n");
                print_list(head);
            }
            if (choice == 'r')
            {
                printf("Here is the reversed movie list:\n");
                print_reversed_list(head);
            }
            eatline();
            puts("Which order to show?\n[o]riginal, [r]eversed, [q]uit:");
        }
    }
    
/* Program done, so free allocated memory   */
    current = head;
    while (head != NULL)
    {
        current = head;
        head = current->next;
        free(current);
    }
    printf("Bye!\n");
    
    return 0;
}

/* Skip the remaining input */
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

/* Recursion, prints the list in original order */
void print_list(const struct film * ps)
{
    if (ps != NULL)
    {
        printf("Movie: %s  Rating: %d\n",
                ps->title, ps->rating);
        print_list(ps->next);
    }
}

/* Recursion prints the list in reverse order   */
void print_reversed_list(const struct film * ps)
{
    if (ps != NULL)
    {
        print_reversed_list(ps->next);
        printf("Movie: %s  Rating: %d\n",
                ps->title, ps->rating);
    }
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
            eatline();
    }
    return ret_val;
}
