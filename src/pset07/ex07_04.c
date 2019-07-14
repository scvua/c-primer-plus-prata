//
//  pr_pset07_04:
//
//  Using if else statements, write a program that reads input up to #,
//  replaces each period with an exclamation mark, replaces each exclamation
//  mark initially present with two exclamation marks, and reports at the end
//  the number of substitutions it has made.
//

#include <stdio.h>

#define END '#'

int main(void)
{
    char c;
    int n_periods, n_exmarks;

    n_periods = n_exmarks = 0;
    printf("Enter some text (# to quit):\n");
    while ((c = getchar()) != END)
    {
        if (c == '.')
        {
            n_periods++;
            printf("!");
        }
        else if (c == '!')
        {
            n_exmarks++;
            printf("!!");
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n%d periods and %d exclamation marks were substituted.\n",
            n_periods, n_exmarks);

    return 0;
}
