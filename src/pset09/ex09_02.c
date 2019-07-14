/*
 * pr_pset09_02:
 *
 * Devise a function chline(ch,i,j) that prints the requested character
 * in columns i through j. Test it in a simple driver.
 */

#include <stdio.h>

void chline(char, int, int);

int main(void)
{
    char ch;
    int begin, end;

    printf("Enter character and two integers: ");
    while ((ch = getchar()) != '\n')
    {
        scanf("%d %d", &begin, &end);
        chline(ch, begin, end);
        while (getchar() != '\n')
            continue;
        printf("Enter next values (newline to quit): ");
    }
    printf("Bye.\n");

    return 0;
}

void chline(char c, int first, int last)
{
    for (int i = 0; i < first-1; i++)
        putchar(' ');
    for (; first <= last; first++)
        putchar(c);
    putchar('\n');
}
