//
//  pr_pset07_05:
//
//  Using switch statement, write a program that reads input up to #,
//  replaces each period with an exclamation mark, replaces each exclamation
//  mark initially present with two exclamation marks, and reports at the end
//  the number of substitutions it has made.
//

#include <stdio.h>

#define STOP    '#'

int main(void)
{
    char c;
    int n_subs = 0;

    printf("Enter some text (# to quit):\n");
    while ((c = getchar()) != STOP)
    {
        switch(c)
        {
            case '.' :  printf("!");
                        n_subs++;
                        break;
            case '!' :  printf("!!");
                        n_subs++;
                        break;
            default  :  printf("%c", c);
        }
    }
    printf("Program has made %d substitutions.\n", n_subs);

    return 0;
}
