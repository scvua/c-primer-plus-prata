//
//  pr_pset06_18:
//
//  Professor Rabnud joined a social media group. Initially he had five
//  friends. He noticed that his friend count grew in the following fashion.
//  The first week one friend dropped out and the remaining number of friends
//  doubled. The second week two friends dropped out and the remaining number
//  of friends doubled. In general, in the Nth week, N friends dropped out
//  and the remaining number doubled. Write a program that computes and
//  displays the number of friends each week. The program should continue
//  until the count exceeds Dunbar’s number.
//

#include <stdio.h>

#define DUNBAR  150

int main(void)
{
    int week;
    int friends = 5;

    printf("Professor Rabnud joined social group with 5 friends.\n");
    for (week = 1; friends < DUNBAR; week++)
    {
        friends = (friends - week) * 2;
        printf("After %d week(s) he had %3d friends.\n",
                week, friends);
    }

    return 0;
}
