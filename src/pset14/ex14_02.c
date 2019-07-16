/*
 *  pr_pset14_02.c -- version in one file
 *  Write a program that prompts the user to enter the day, month, and year.
 *  The month can be a month number, a month name, or a month abbreviation.
 *  The program then should return the total number of days in the year up
 *  through the given day. (Do take leap years in account.)
 *  Created by gres.cher on 04/25/19.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 21     // Size of the input string
#define LEAP 4      // Leap year
#define ALEN 3      // Length of a month abbreviation string

struct month {
    char name[10];
    char abbr[4];
    int days;
    int num;
};

struct month months[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

int check_month(const char * s);
void eatline(void);
char * mygets(char * st, const int n);
void strconv(char * out, const char * in);

int main(void)
{
    char input[SIZE];
    int day, month, year;
    int daystot;

    printf("Enter the year (q to quit): ");
    while ((scanf("%d", &year)) == 1)
    {
        eatline();		// clear input line
        // Check whether the 'year' is a leap year
        if (year % LEAP == 0)
            months[1].days = 29;
        else
            months[1].days = 28;
        // Input month
        printf("Enter the month (number / name / abbreviation): ");
        if (mygets(input, SIZE) == NULL || input[0] == '\0')
        {
            puts("You have not entered anything. Let's try again.");
            printf("Enter the year (q to quit): ");
            continue;
        }
        // Check whether the input is a month info
        if ((month = check_month(input)) == 0)
        {
            printf("\"%s\" is unknown month. Try again.\n", input);
            printf("Enter the year (q to quit): ");
            continue;
        }
        // Input day; check whether it is in the proper range of numbers
        printf("Enter the day: ");
        while ((scanf("%d", &day)) == 1 &&
               (day < 1 || day > months[month-1].days))
        {
            eatline();	// clear input line
            printf("%s has %d days. Please, enter a number from 1 to %d\n",
                   months[month-1].name, months[month-1].days, months[month-1].days);
        }
        // Calculate and print total days
        daystot = 0;
        for (int i = 0; i < month-1; i++)
            daystot += months[i].days;
        daystot += day;
        printf("There is %d %s up to %s %d, %d\n", daystot,
               daystot == 1 ? "day" : "days", months[month-1].name, day, year);
        // Prompt the user for new values
        printf("Enter the year (q to quit): ");
    }
    puts("Done.");

    return 0;
}

// Check which month.num the string is; return 0 if string has no month info
int check_month(const char * st)
{
    extern struct month months[12];
    int mon;
    unsigned int slen;
    char temp[SIZE];

    // Check whether a string contains whitespace in beforehand; omit it
    while (*st != '\0' && isspace(*st))
        st++;
    // Check what type is the first char of the string
    if (isdigit(*st))
    {
        // The string begins with a digit
        // Convert string to number and check if it is in range 1-12 months
        mon = atoi(st);
        if (mon > 0 && mon <= 12)
            return mon;
        else
            return 0;
    }
    else if (isalpha(*st) && (slen = (unsigned int) strlen(st)) >= ALEN)
    {
        // The string begins with a letter and it has sufficient length
        mon = 0;
        // Capitalize the first char and make the rest in lowercase
        strconv(temp, st);
        // Check whether the string is abbreviation or full month name
        if (slen == ALEN)
        {
            // Abbreviation case
            while (mon < 12 && strncmp(months[mon].abbr, temp, ALEN))
                mon++;
        }
        else
        {
            // Name case
            while (mon < 12 && strcmp(months[mon].name, temp))
                mon++;
        }
        if (mon == 12)
            return 0;	// no match were found
        else
            return (++mon);
    }
    else
        // The string begins with the inappropriate character
        return 0;
}

// Clear input line
void eatline(void)
{
    while (getchar() != '\n')
        continue;
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

// Convert string in lowercase; make first letter capital
void strconv(char * out, const char * in)
{
    // Capitalize first letter
    if (*in != '\0')
        *out++ = toupper(*in++);
    // Convert to lowercase rest of the input string
    while (*in)
        *out++ = tolower(*in++);
    // Finalize output string with null character
    *out = '\0';
}
