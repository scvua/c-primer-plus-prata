//
//  pr_pset07_06:
//
//  Write a program that reads input up to # and reports the number of
//  times that the sequence ei occurs.
//

#include <stdio.h>
#include <stdbool.h>

#define STOP    '#'

int main(void)
{
    char c;
    int num_ei = 0;
    bool lchar_is_e = false;

    printf("Enter some text (# to quit):\n");
    while ((c = getchar()) != STOP)
    {
        if (c == 'e')
            lchar_is_e = true;
        else if (c == 'i' && lchar_is_e)
        {
            lchar_is_e = false;
            num_ei++;
        }
        else
            lchar_is_e = false;
    }
    printf("The sequence 'ei' occurs %d %s.\n",
            num_ei, num_ei == 1 ? "time" : "times");

    return 0;
}
