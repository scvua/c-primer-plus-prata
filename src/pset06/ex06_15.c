//
//  pr_pset06_15:
//
//  Program that reads in a line of input and then prints the line
//  in reverse order.
//

#include <stdio.h>
#include <string.h>

#define SIZE 255

int main(void)
{
    char ch[SIZE];
    int i = 0;

    printf("Enter some input:\n");
    for (i = 1, ch[i-1] = '0'; ch[i-1] != '\n'; scanf("%c", &ch[i]), i++)
        ;

// Optional: replace '\n' by '\0' therefore ch[] becomes to string.
    ch[i-1] = '\0';

// Print reversed line.
    for (i = strlen(ch) -1; i > 0; i--)
        printf("%c", ch[i]);
    printf("\nDone\n");

    return 0;
}
