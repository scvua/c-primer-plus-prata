/*
 *  ex08_02.c
 *  Write a program that reads input as a stream of characters until 
 *  encountering EOF. Have the program print each input character and its ASCII 
 *  decimal value. Note that characters preceding the space character in the 
 *  ASCII sequence are nonprinting characters. Treat them specially. 
 *  If the nonprinting character is a newline or tab, print \n or \t, 
 *  respectively. Otherwise, use control-character notation. For instance, ASCII 
 *  1 is Ctrl+A, which can be displayed as ^A. Note that the ASCII value for A 
 *  is the value for Ctrl+A plus 64. A similar relation holds for the other 
 *  nonprinting characters. Print 10 pairs per line, except start a fresh line 
 *  each time a newline character is encountered.
 *
 *  Created by grescher 07/29/20.
 */

#include <stdio.h>

#define PAIRS_IN_LINE 10
void printASCII(int c);

int main(void)
{
    int c;

    for (int i = 0; (c = getchar()) != EOF; i++) {
        printASCII(c);
        if (i == PAIRS_IN_LINE-1 || c == '\n')
        {
            i = 0;
            putchar('\n');
        }
    }
    if (c == EOF) {
        printf("\nEOF (%d) received. Bye.\n", EOF);
    }
    return 0;
}

void printASCII(int c)
{
    if (c == 0) {
        printf("%-4s:%4d", "NUL", c);
    } 
    else if (c < ' ') 
    {
        switch (c)
        {
            case '\n':
                printf("%4s:%4d", "\\n", c);
                break;
            case '\t':
                printf("%4s:%4d", "\\t", c);
                break;
            case '\b':
                printf("%4s:%4d", "\\b", c);
                break;
            case '\r':
                printf("%4s:%4d", "\\r", c);
                break;
            case '\v':
                printf("%4s:%4d", "\\v", c);
                break;
            case '\a':
                printf("%4s:%4d", "\\a", c);
                break;
            default:
                printf("  ^%c:%4d", c+64, c);
                break;
        } 
    }
    else if (c == 128)
    {
        printf("%-4s:%4d", "DEL", c);
    }
    else
        printf("   %c:%4d", c, c);
}
