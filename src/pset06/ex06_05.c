//
//  pr_pset06_05:
//
// Have a program request the user to enter an uppercase letter. Use nested
// loops to produce a pyramid pattern like this:
//
//             A
//            ABA
//           ABCBA
//          ABCDCBA
//         ABCDEDCBA
//
// The pattern should extend to the character entered.
// For example, the preceding pattern would result from an input value of E.
// Hint: Use an outer loop to handle the rows. Use three inner loops in a row,
// one to handle the spaces, one for printing letters in ascending order,
// and one for printing letters in descending order. If your system doesn’t use
// ASCII or a similar system that represents letters in strict number order,
// see the suggestion in programming exercise 3.
//

#include <stdio.h>

#define ROWS 5

int main(void)
{
    char letter;

    printf("Enter an uppercase letter: ");
    scanf("%c", &letter);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = ROWS - i; j > 1; j--)
            printf(" ");
        for (int j = 0; j <= i; j++)
            printf("%c", letter + j);
        for (int j = i; j > 0; )
            printf("%c", letter + --j);
        printf("\n");
    }

    return 0;
}
