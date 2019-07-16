/*
 *  pr_pset14_09.c
 *
 *  Colossus Airlines (from exercise 8) acquires a second plane (same capacity)
 *  and expands its service to four flights daily (Flights 102, 311, 444, and
 *  519). Expand the program to handle four flights. Have a top-level menu that
 *  offers a choice of flights and the option to quit. Selecting a particular
 *  flight should then bring up a menu similar to that of exercise 8. However,
 *  one new item should be added: confirming a seat assignment. Also, the quit
 *  choice should be replaced with the choice of exiting to the top-level menu.
 *  Each display should indicate which flight is currently being handled. Also,
 *  the seat assignment display should indicate the confirmation status.
 *
 *  I decided that the program will create a separate file for each flight.
 *  This approach will allow the program to be flexible and make it easy to add
 *  new flights without losing previosly saved data. It will also be easy to
 *  maintain if the number of seats in a new flight begins to differ.
 *
 *  Created by gres.cher on 06/26/19.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLIGHTS    4    // number of flights
#define SEATS     12    // number of seats for a flight
#define SLEN      16    // maximum length for a name string
#define ADDRLEN   81    // length of the string with the file address
// Address of the directory with data files
#define DB_DIR  "../../data/flights/"

typedef unsigned char byte;
enum seats {empty, taken, confirmed};

struct seat {
    unsigned short seat_id;	// the number of a seat
    enum seats status;      // shows if the seat is assigned or empty
    char lname[SLEN];       // the last name of a passenger
    char fname[SLEN];       // the first name of a passenger
};

// Numbers of all flights
const int flight_num[FLIGHTS] = {
    102, 311, 444, 519
};

void assignDel(struct seat * pst, const int lim);
void assignSet(struct seat * pst, const int lim);
char choiceGet(const char * st);
void choiceRetry(const char * st);
void confirmSet(struct seat * pst, const int lim);
int countSeats(const struct seat * pst, int lim, enum seats n);
void eatLine(void);
int getFlightNum(void);
void listFlight(struct seat * pst[], const int lim);
void listSeats(const struct seat * pst, const int lim, enum seats n);
void menuFlight(const int num, const int seats);
char menuSeats(const char * st);
void srtLName(struct seat *pst[], const int lim);
char * mygets(char * st, const int n);

int main(void)
{
    int choice;

    puts("Colossus Airlaines");
    while ((choice = getFlightNum()) != 0)
        menuFlight(choice, SEATS);
    puts("Bye");
    return 0;
}

// Delete assignment of a seat
void assignDel(struct seat * pst, const int lim)
{
    int id;
    char choice;

    // Print full list of taken seats
    printf("List of taken seats:\n");
    for (int i = 0; i < lim; i++)
        if (pst[i].status == taken)
            printf("%2d: %s, %s\n", pst[i].seat_id, pst[i].lname, pst[i].fname);
    // Get the user's respond
    printf("Enter the number of the seat to be cancelled: ");
    while (scanf("%d", &id) != 1
           || id < 1 || id > lim || pst[id-1].status != taken)
    {
        // A non-digit number was input, seat is empty, or incorrect number
        // Print short list of taken seats
        printf("Use a number from the list:\n");
        listSeats(pst, SEATS, taken);
        eatLine();
    }
    eatLine();
    // Print info about seat and passenger to drop
    printf("%s %s to be cancelled for seat %d\n",
           pst[id-1].fname, pst[id-1].lname, pst[id-1].seat_id);
    printf("[d]elete, [a]bort: ");
    if ((choice = choiceGet("da")) == 'd')
    {
        // Save data to main structure
        pst[id-1].status = empty;
        printf("Passenger dropped\n");
    }
    else
        printf("Passenger retained\n");
}

// Assign a passenger to a seat; if seat is assigned prompt for reassignment
void assignSet(struct seat * pst, const int lim)
{
    struct seat tmp = { .status = taken };
    int id;
    char choice;

    // Prompt the user for the number of a seat
    printf("List of available seats:\n");
    listSeats(pst, SEATS, empty);
    printf("Which seat to assign?: ");
    while (scanf("%d", &id) != 1 || (id < 1 || id > lim))
    {
        printf("Please use a number from the list:\n");
        listSeats(pst, SEATS, empty);
        eatLine();
    }
    eatLine();
    tmp.seat_id = id;

    // Check whether the seat is taken; if so suggest to reassign
    if (pst[id-1].status == taken)
    {
        printf("Seat %d is assigned to %s %s.\n",
               id, pst[id-1].fname, pst[id-1].lname);
        printf("[r]eassign, [a]bort: ");
        if ((choice = choiceGet("ra")) == 'a')
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
    while ((choice = choiceGet("sec")) == 'e');
    // Save data to main structure
    if (choice == 's')
    {
        pst[id-1] = tmp;
        printf("Assignment saved\n");
    }
}

// Get the user's answer and compare it with elements of the `labels`
// `labels` is the string with option letters
char choiceGet(const char * labels)
{
    char ans;

    while ((ans = getchar()) != EOF)
    {
        // Dismiss a forehead whitespaces if any
        if (isspace(ans))
        {
            if (ans == '\n')
                choiceRetry(labels);
            continue;
        }
        // Convert to upper and check if answer matches
        ans = tolower(ans);
        eatLine();
        if (strchr(labels, ans))
            return ans;
        else
            choiceRetry(labels);
    }
    return ans;
}

// Print the retry request; use characters from the 'labels' string
void choiceRetry(const char * labels)
{
    printf("Please use keys <");
    for (int i = 0; labels[i] != '\0'; i++)
        printf("%c%s", labels[i], labels[i+1] == '\0' ? ">\n" : ", ");
}

// Confirm assignment of a seat; return if the seat is empty or confirmed
void confirmSet(struct seat * pst, const int lim)
{
    int id;
    char choice;

    puts("List of assigned seats:");
    listSeats(pst, lim, taken);
    printf("Which seat to confirm?: ");
    while ((scanf("%d", &id) != 1) || id < 1 || id > lim)
    {
        puts("Please use a number from the list:");
        listSeats(pst, SEATS, taken);
        eatLine();
    }
    eatLine();
    switch (pst[id-1].status)
    {
        case empty:
            printf("Seat %d is empty\n", id);
            break;

        case confirmed:
            printf("Seat %d is already confirmed\n", id);
            break;

        case taken:
            printf("Seat %d: %s %s is going to be confirmed\n", id,
                   pst[id-1].fname, pst[id-1].lname);
            puts("[s]ave, [a]bort");
            if ((choice = choiceGet("sa")) == 's')
            {
                pst[id-1].status = confirmed;
                printf("The assignment of the seat %d is confirmed\n", id);
            }
            break;
    }
    return;
}

// Calculate the number of seats with the given status
int countSeats(const struct seat * pst, int lim, enum seats status)
{
    int sum = 0;
    while (lim > 0)
        if (pst[--lim].status == status)
            sum++;
    return sum;
}

// Dismiss the rest of the input
void eatLine(void)
{
    while (getchar() != '\n')
        continue;
}

// Prompt the user with the list of the flight numbers; retry if an entered
// number is incorrect.
// Return the flight number or 0 if the user had chosen to quit the menu
int getFlightNum(void)
{
    extern const int flight_num[FLIGHTS];
    int choice = 0;
    int i;

    puts("List of available flights:");
    for (i = 0; i < FLIGHTS; i++)
        printf("%4d%s", flight_num[i], i+1 != FLIGHTS ? " " : "\n");
    puts("Input the flight number (q to quit):");
    while (scanf("%d", &choice) == 1)
    {
        eatLine();
        // Check whether the choice is equal to one of the flight numbers
        for (i = 0; i < FLIGHTS; i++)
            if (choice == flight_num[i])
                return choice;
        // The choice is a number but it's not the flight number
        printf("There's no such flight: %d\n", choice);
        puts("Retry with one of these flight numbers:");
        for (i = 0; i < FLIGHTS; i++)
            printf("%4d%s", flight_num[i], i+1 != FLIGHTS ? " " : "\n");
        puts("Input the number (q to quit):");
    }
    // The user has made a letter input
    return 0;
}

// Output alphabetical list
void listFlight(struct seat * pst[], const int lim)
{
    // Check whether there is any assigned seat
    if (countSeats(*pst, lim, empty) != lim)
    {
        // Print list of assigned seats with a passenger's name
        for (int i = 0; i < lim; i++)
        {
            if (pst[i]->status != empty)
                printf("%2d: %s, %s%s",
                       pst[i]->seat_id, pst[i]->lname, pst[i]->fname,
                       pst[i]->status == confirmed ? " (confirmed)\n" : "\n");
        }
    }
    else
        printf("All seats are empty\n");
}

// Open/create a file with the flight data; prompt the user with menuSeats()
// Do the corresponding actions; save the data file on exit
void menuFlight(const int flight_num, const int seats_num)
{
    struct seat flight[seats_num];
    struct seat * pst[seats_num];	// for a sorting functions use
    char file_addr[ADDRLEN];
    FILE *fp;
    size_t size = sizeof(struct seat);
    char choice;

    // Generate filename
    sprintf(file_addr, "%sflight_%03d.dat", DB_DIR, flight_num);

    // Open the datafile; if it's absent, initialize new structure
    if ((fp = fopen(file_addr, "r")) != NULL)
    {
        if (fread(&flight, size, seats_num, fp) != seats_num)
        {
            fprintf(stderr, "Can't read the data\n");
            exit(EXIT_FAILURE);
        }
        fclose(fp);
    }
    else
    {
        for (int i = 0; i < seats_num; i++)
        {
            flight[i].seat_id = i + 1;
            flight[i].status = empty;
        }
    }

    for (int i = 0; i < seats_num; i++)
        pst[i] = &flight[i];
    printf("FLIGHT %d\n", flight_num);
    while ((choice = menuSeats("nelacdr")) != 'r')
    {
        printf("Flight %d:\n", flight_num);
        switch (choice)
        {
            case 'n':	// show number of empty seats
                printf("The number of empty seats: %d of %d\n",
                       countSeats(flight, seats_num, empty), seats_num);
                break;

            case 'e':	// show list of empty seats
                listSeats(flight, seats_num, empty);
                break;

            case 'l':	// show alphabetical list of seats (by last name)
                srtLName(pst, seats_num);
                listFlight(pst, seats_num);
                break;

            case 'a':	// assign a customer to a seat
                if (countSeats(flight, seats_num, empty) != 0)
                    assignSet(flight, seats_num);
                else
                    printf("All seats are taken\n");
                break;

            case 'c':   // confirm a seat assignment
                if (countSeats(flight, seats_num, empty) != 0)
                {
                    if (countSeats(flight, seats_num, confirmed) != seats_num)
                        confirmSet(flight, seats_num);
                    else
                        printf("All assignments are confirmed\n");
                }
                else
                    printf("There's nothing to confirm\n");
                break;

            case 'd':	// delete a seat assignment
                if (countSeats(flight, seats_num, taken) != 0)
                    assignDel(flight, seats_num);
                else
                    printf("There's nothing to delete\n");
                break;
        }
    }
    // Save data into file
    if ((fp = fopen(file_addr, "w")) != NULL)
    {
        if (fwrite(&flight, size, seats_num, fp) != seats_num)
            fprintf(stderr, "Can't save the data :(\n");
        fclose(fp);
    }
    else
    {
        fprintf(stderr, "Can't save the data :(\n");
        exit(EXIT_FAILURE);
    }
}

// Output the list of seats (defined by status)
void listSeats(const struct seat * pst, const int lim, enum seats status)
{
    if (countSeats(pst, lim, status) != 0)
    {
        for (int i = 0; i < lim; i++)
            if (pst[i].status == status)
                printf(" %d", pst[i].seat_id);
        putchar('\n');
    }
    else
    {
        switch (status)
        {
            case empty:
                puts("All seats are taken");
                break;

            case taken:
                if (countSeats(pst, lim, empty) == lim)
                    puts("All seats are empty");
                else
                    puts("All of the seat assignments are confirmed");
                break;

            case confirmed:
                if (countSeats(pst, lim, empty) == lim)
                    puts("All seats are empty");
                else
                    puts("There's no confirmed assignments");
                break;
        }
    }
}

// Print the menu; return the character (yields by getchoice() call)
char menuSeats(const char * label)
{
    const int msize = 7;

    char * line[msize] = {
        "Show number of empty seats",
        "Show list of empty seats",
        "Show alphabetical list of seats",
        "Assign a customer to a seat assignment",
        "Confirm a seat assignment",
        "Delete a seat assignment",
        "Return to the previous menu"
    };

    puts("To choose a function, enter its letter label:");
    for (int i = 0; i < msize; i++)
        printf("%c) %s\n", label[i], line[i]);

    return choiceGet(label);
}

// Sort array of pointers-to-structure by lname
void srtLName(struct seat * pst[], const int lim)
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
