/*
 *  pr_pset14_08.c
 *
 *  The Colossus Airlines fleet consists of one plane with a seating capacity
 *  of 12. It makes one flight daily. Write a seating reservation program with
 *  the following features:
 *
 *  a. The program uses an array of 12 structures. Each structure should hold a
 *     seat identification number, a marker that indicates whether the seat is
 *     assigned, the last name of the seat holder, and the first name of the
 *     seat holder.
 *  b. The program displays the following menu:
 *         To choose a function, enter its letter label:
 *         a) Show number of empty seats
 *         b) Show list of empty seats
 *         c) Show alphabetical list of seats
 *         d) Assign a customer to a seat assignment
 *         e) Delete a seat assignment
 *         f) Quit
 *  c. The program successfully executes the promises of its menu. Choices d)
 *     and e) require additional input, and each should enable the user to abort
 *     an entry.
 *  d. After executing a particular function, the program shows the menu again,
 *     except for choice f).
 *  e. Data is saved in a file between runs. When the program is restarted, it
 *     it first loads the data, if any, from the file.
 *
 *  Created by gres.cher on 05/11/19.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_ADDR "../../data/flight.dat"
#define SEATS	  12
#define SLEN      16
#define EMPTY      0
#define TAKEN      1
#define MENU_SIZE  6

typedef unsigned char byte;

struct seat {
    unsigned short seat_id;
    unsigned short status;
    char lname[SLEN];
    char fname[SLEN];
};

void eatline(void);
char getmenu(const char * st);
char getchoice(const char * st);
void retry(const char * st);
int empties(const struct seat * pst, int lim);
void list_seats(const struct seat * pst, int lim, unsigned short n);
void list_flight(struct seat * pst[], const int lim);
void srtlname(struct seat *pst[], const int lim);
void assign_set(struct seat * pst, const int lim);
void assign_del(struct seat * pst, const int lim);
char * mygets(char * st, const int n);

int main(void)
{
    struct seat flight[SEATS];
    struct seat * pst[SEATS];   // for a sorting functions use
    FILE *fp;
    size_t size = sizeof(struct seat);
    char choice;

    // Open the datafile; if it's absent, initialize new structure
    if ((fp = fopen(FILE_ADDR, "r")) != NULL)
    {
        if (fread(&flight, size, SEATS, fp) != SEATS)
        {
            fprintf(stderr, "Can't read the data\n");
            exit(EXIT_FAILURE);
        }
        fclose(fp);
    }
    else
    {
        for (int i = 0; i < SEATS; i++)
        {
            flight[i].seat_id = i + 1;
            flight[i].status = EMPTY;
        }
    }

    for (int i = 0; i < SEATS; i++)
        pst[i] = &flight[i];

    while ((choice = getmenu("neladq")) != 'q')
    {
        switch (choice)
        {
            case 'n':   // show number of empty seats
                printf("The number of empty seats: %d\n",
                       empties(flight, SEATS));
                break;

            case 'e':   // show list of empty seats
                list_seats(flight, SEATS, EMPTY);
                break;

            case 'l':   // show alphabetical list of seats (by last name)
                srtlname(pst, SEATS);
                list_flight(pst, SEATS);
                break;

            case 'a':   // assign a customer to a seat
                if (empties(flight, SEATS) != 0)
                    assign_set(flight, SEATS);
                else
                    printf("All seats are taken\n");
                break;

            case 'd':   // delete a seat assignment
                if (empties(flight, SEATS) != SEATS)
                    assign_del(flight, SEATS);
                else
                    printf("There's nothing to delete\n");
                break;
        }
    }

    // Save data into file
    if ((fp = fopen(FILE_ADDR, "w")) != NULL)
    {
        if (fwrite(&flight, size, SEATS, fp) != SEATS)
            fprintf(stderr, "Can't save the data :(\n");
        fclose(fp);
    }
    else
        fprintf(stderr, "Can't save the data :(\n");
    puts("Bye.");

    return 0;
}

// Dismiss the rest of the input
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

// Print the menu; return the character (yields by getchoice() call)
char getmenu(const char * label)
{
    char * line[MENU_SIZE] = {
        "Show number of empty seats",
        "Show list of empty seats",
        "Show alphabetical list of seats",
        "Assign a customer to a seat assignment",
        "Delete a seat assignment",
        "Quit"
    };

    puts("To choose a function, enter its letter label:");
    for (int i = 0; i < MENU_SIZE; i++)
        printf("%c) %s\n", label[i], line[i]);

    return getchoice(label);
}

// Get the user's answer and compare it with elements of the `labels`
// `labels` is the string with option letters
char getchoice(const char * labels)
{
    char ans;

    while ((ans = getchar()) != EOF)
    {
        // Dismiss a forehead whitespaces if any
        if (isspace(ans))
        {
            if (ans == '\n')
                retry(labels);
            continue;
        }
        // Convert to lowercase and check if answer matches
        ans = tolower(ans);
        eatline();
        if (strchr(labels, ans))
            return ans;
        else
            retry(labels);
    }
    return ans;
}

// Print the retry request; use characters from the 'labels' string
void retry(const char * labels)
{
    printf("Please use keys <");
    for (int i = 0; labels[i] != '\0'; i++)
        printf("%c%s", labels[i], labels[i+1] == '\0' ? ">\n" : ", ");
}

// Calculate the number of empty seats
int empties(const struct seat * pst, int lim)
{
    int sum = 0;

    for (int i = 0; i < lim; i++)
        if (pst[i].status == EMPTY)
            sum++;
    return sum;
}

// Output the list of seats (defined by status)
void list_seats(const struct seat * pst, int lim, unsigned short status)
{
    if (empties(pst, lim) != (status * lim))
    {
        for (int i = 0; i < lim; i++)
            if (pst[i].status == status)
                printf(" %d", pst[i].seat_id);
        putchar('\n');
    }
    else
        printf("All seats are %s\n", status == EMPTY ? "assigned" : "empty");
}

// Output list
void list_flight(struct seat * pst[], const int lim)
{
    if (empties(*pst, lim) != lim)
    {
        for (int i = 0; i < lim; i++)
        {
            if (pst[i]->status == TAKEN)
                printf("%2d: %s, %s\n",
                       pst[i]->seat_id, pst[i]->lname, pst[i]->fname);
        }
    }
    else
        printf("All seats are empty\n");
}

// Sort array of pointers-to-structure by lname
void srtlname(struct seat * pst[], const int lim)
{
    struct seat * tmp;

    for (int top = 0; top < lim; top++)
        for (int seek = top + 1; seek < lim; seek++)
            if (strcmp(pst[top]->lname, pst[seek]->lname) > 0)
            {
                tmp = pst[top];
                pst[top] = pst[seek];
                pst[seek] = tmp;
            }
}

// Assign a passenger to a seat; if seat is assigned prompt for reassignment
void assign_set(struct seat * pst, const int lim)
{
    struct seat tmp = { .status = TAKEN };
    int id;
    char choice;

    // Prompt the user for the number of a seat
    printf("List of available seats:\n");
    list_seats(pst, SEATS, EMPTY);
    printf("Which seat to assign?: ");
    while (scanf("%d", &id) != 1 || (id < 1 || id > lim))
    {
        printf("Please use a number from the list:\n");
        list_seats(pst, SEATS, EMPTY);
        eatline();
    }
    eatline();
    tmp.seat_id = id;

    // Check whether the seat is taken; if so suggest to reassign
    if (pst[id-1].status == TAKEN)
    {
        printf("Seat %d is assigned to %s %s.\n",
               id, pst[id-1].fname, pst[id-1].lname);
        printf("[r]eassign, [a]bort: ");
        if ((choice = getchoice("ra")) == 'a')
            return;
    }

    // Save names to the temporary structure and prompt for next action
    do
    {
        printf("Enter a first name: ");
        mygets(tmp.fname, SLEN);
        printf("Enter a last name:  ");
        mygets(tmp.lname, SLEN);
        printf("%s %s assigned to seat %d\n",
               tmp.fname, tmp.lname, tmp.seat_id);
        printf("[s]ave, [e]dit, [c]ancel: ");
    }
    while ((choice = getchoice("sec")) == 'e');
    // Save data to main structure
    if (choice == 's')
        pst[id-1] = tmp;
}

// Delete assignment
void assign_del(struct seat * pst, const int lim)
{
    int id;
    char choice;

    // Print full list of taken seats
    printf("List of taken seats:\n");
    for (int i = 0; i < lim; i++)
        if (pst[i].status == TAKEN)
            printf("%2d: %s, %s\n", pst[i].seat_id, pst[i].lname, pst[i].fname);
    // Get the user's respond
    printf("Enter the number of the seat to be cancelled: ");
    while (scanf("%d", &id) != 1
           || id < 1 || id > lim || pst[id-1].status != TAKEN)
    {
        // A non-digit number was input, seat is empty, or incorrect number
        // Print short list of taken seats
        printf("Use a number from the list:\n");
        list_seats(pst, SEATS, TAKEN);
        eatline();
    }
    eatline();
    // Print info about seat and passenger to drop
    printf("%s %s to be cancelled for seat %d\n",
           pst[id-1].fname, pst[id-1].lname, pst[id-1].seat_id);
    printf("[d]elete, [a]bort: ");
    if ((choice = getchoice("da")) == 'd')
    {
        // Save data to main structure
        pst[id-1].status = EMPTY;
        printf("Passenger dropped\n");
    }
    else
        printf("Passenger retained\n");
}

// Get a string from standard input
char * mygets(char * st, const int n)
{
    int ch, i;

    for (i=ch=0; (i < n-1) && ((ch=getchar()) != EOF) && (ch != '\n'); i++)
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
