/*
 * pr_pset08_05:
 *
 * Modify the guessing program of Listing 8.4 so that it uses a more
 * intelligent guessing strategy. For example, have the program initially
 * guess 50, and have it ask the user whether the guess is high, low, or
 * correct. If, say, the guess is low, have the next guess be halfway
 * between 50 and 100, that is, 75. If that guess is high, let the next guess
 * be halfway between 75 and 50, and so on.
 */

#include <stdio.h>

#define MIN 1
#define MAX 100

int main(void)
{
    int response;
    int n = MAX;
    int guess = MIN;

    printf("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf("Respond with:\ny. my guess is right;\n");
    printf("l. my guess is low;\nh. my guess is high.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((response = getchar()) != 'y')   // get response
    {
        if (response == 'h')
        {
            n /= (n > 1) ? 2 : 1;
            guess += n;
            printf("Well, then, is it %d?\n", guess);
        }
        else if (response == 'l')
        {
            n /= (n > 1) ? 2 : 1;
            guess -= (n < guess) ? n : 1 ;
            printf("Well, then, is it %d?\n", guess);
        }
        else
            printf("Sorry, I understand only y, l or h.\n");
        while (getchar() != '\n')
            continue;                       // skip rest of input line
    }
    printf("I knew I could do it!\n");

    return 0;
}
