//
//  pr_pset06_02:
//
// Use nested loops to produce the following pattern:
//
//     $
//     $$
//     $$$
//     $$$$
//     $$$$$
//

#include <stdio.h>
#define ROWS 5

int main(void)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("$");
        printf("\n");
    }

    return 0;
}
