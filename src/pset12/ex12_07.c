/*
 *  pr_pset12_07.c
 *  Program that behaves like the modification of listing 12.13. Prompts number
 *  of sets, dice and sides; prints result. Repeat until the 'q' key is
 *  pressed.
 *  Created by gres.cher on 02/11/19.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_n_dice(int dice, int sides);

int main(void)
{
    int sets, sides, dice;
    
    srand((unsigned int) time(0));
    printf("Enter the number of sets; enter the q to stop: ");
    while (scanf("%d", &sets) == 1)
    {
        printf("How many sides and how many dice? ");
        while (scanf("%d %d", &sides, &dice) != 2 || sides < 2 || dice < 1)
        {
            while (getchar() != '\n')
                continue;	// Dispose of bad input
            if (dice < 1)
                printf("You need at least 1 die. ");
            else if (sides < 2)
                printf("You need at least 2 sides. ");
            else
                printf("Input isn't match. ");
            printf("Try again with 2 integers: ");
        }
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (int i = 0; i < sets; i++)
        {
            // Print result of a roll
            printf("%4d", roll_n_dice(dice, sides));
            // Display results: 10 numbers to a line
            if ((i+1) % 10 == 0 || i+1 == sets)
                putchar('\n');
        }
        printf("How many sets? Enter q to stop: ");
    }
    puts("Bye.");
    return 0;
}
// Calculate total of dice rolls
int roll_n_dice(int dice, int sides)
{
    int total = 0;
    
    while (dice--)
        total += rand() % sides + 1;
    return total;
}
