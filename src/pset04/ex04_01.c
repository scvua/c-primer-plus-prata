//
// pr_pset04_01:
//
// Write a program that asks for your first name, your last name, and then
// prints the names in the format last, first.
//

#include <stdio.h>

int main(void)
{
    char first[20], last[30];

    printf("Enter your first and last name:\n");
    scanf("%s %s", first, last);
    printf("Look, I changed something:\n");
    printf("%s %s\n", last, first);

    return 0;
}
