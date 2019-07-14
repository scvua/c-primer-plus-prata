//
//  pr_pset06_04:
//
// Use nested loops to produce the following pattern:
//
//     A
//     BC
//     DEF
//     GHIJ
//     KLMNO
//     PQRSTU
// 
// If your system doesn’t encode letters in numeric order, see the suggestion
// in programming exercise 3.
//

#include <stdio.h>

#define ROWS 6

int main(void)
{
    char letter = 'A';

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%c", letter++);
        printf("\n");
    }

    return 0;
}
