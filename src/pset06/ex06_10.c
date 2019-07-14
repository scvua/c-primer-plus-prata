//
//  pr_pset06_10:
//
//  Write a program that requests lower and upper integer limits, calculates
//  the sum of all the integer squares from the square of the lower limit
//  to the square of the upper limit, and displays the answer.
//  The program should then continue to prompt for limits and display answers
//  until the user enters an upper limit that is equal to or less than
//  the lower limit. A sample run should look something like this:
//
//    Enter lower and upper integer limits: 5 9
//    The sums of the squares from 25 to 81 is 255 Enter next set of limits: 3 25
//    The sums of the squares from 9 to 625 is 5520 Enter next set of limits: 5 5
//    Done
//

#include <stdio.h>

int squares(int lower, int upper);

int main(void)
{
    int lower, upper;
    _Bool input_is_fine;

    printf("Enter lower and upper integer limits: ");
    input_is_fine = (scanf("%d %d", &lower, &upper) == 2);
    while (input_is_fine)
    {
        printf("The sums of the squares from %d to %d is %d\n",
                lower * lower, upper * upper, squares(lower, upper));
        printf("Enter lower and upper integer limits: ");
        input_is_fine = (scanf("%d %d", &lower, &upper) == 2);
    }
    printf("Done\n");

    return 0;
}

int squares(int lower, int upper)
{
    int sum = 0;

    for ( ; lower <= upper; lower++)
        sum = sum + lower * lower;

    return sum;
}
