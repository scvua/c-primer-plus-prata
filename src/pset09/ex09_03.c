/*
 * pr_pset09_03:
 *
 * Write a function that takes three arguments: a character and two integers.
 * The character is to be printed. The first integer specifies the number of
 * times that the character is to be printed on a line, and the second integer
 * specifies the number of lines that are to be printed.
 * Write a program that makes use of this function.
 */

#include <stdio.h>
#include <ctype.h>

void printchar(char, int, int);

int main(void)
{
    char ch;
    int rows, columns;

    printf("Enter character to be printed;"
           "(newline to quit): ");
    while ((ch = getchar()) != '\n')
    {
        printf("Enter number of rows and columns: ");
        if (scanf("%d %d", &rows, &columns) != 2)
            break;
        printchar(ch, columns, rows);
        while (getchar() != '\n')
            continue;
        printf("Enter next character (newline to quit): ");
    }
    printf("Bye.\n");

    return 0;
}

void printchar(char c, int width, int lines)
{
    int row, col;

    for (row = 0; row < lines; row++)
    {
        for (col = 0; col < width; col++)
            putchar(c);
        putchar('\n');
    }
}
