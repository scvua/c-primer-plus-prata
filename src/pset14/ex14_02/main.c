/*
 *  main.c
 *  ex14_02 -- version with a header file
 *
 *  Write a program that prompts the user to enter the day, month, and year.
 *  The month can be a month number, a month name, or a month abbreviation.
 *  The program then should return the total number of days in the year up
 *  through the given day. (Do take leap years in account.)
 *  Created by gres.cher on 04/25/19.
 */

#include "mylib.h"
#include <stdio.h>

int main(void)
{
    char input[SIZE];
    int day, month, year;
    int daystot;
    extern struct month months[12];

    printf("Enter the year (q to quit): ");
    while ((scanf("%d", &year)) == 1)
    {
        eatline();      // clear input line
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
