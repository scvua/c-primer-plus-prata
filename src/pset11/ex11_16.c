/*
 *  pr_pset11_16.c
 *  Read input utinl EOF and echo it to the display. Recognize and implement
 *  the following command-line arguments:
 *    -p  Print input as is
 *    -u  Map input to all uppercase
 *    -l  Map input to all lowercase
 *  If there no command-line arguments the program behave as if the -p argument
 *  had been used.
 *
 *  Created by gres.cher on 01/21/19.
 */

#include <ctype.h>
#include <stdio.h>
#define ILLEGAL "./pr_pset11_16: illegal option -- %c\n"
#define USAGE   "usage: ./pr_pset11_16 [-l | -p | -u]"

char keycheck(int n, char *st[]);
void output(char key);
void printdef(void);
void printerr(char key);
void printlow(void);
void printup(void);

int main(int argc, char *argv[])
{
    char key;
    
    key = keycheck(argc, argv);
    output(key);
    
    return 0;
}
// Check input arguments for option flags; return code of an option
char keycheck(int n, char *st[])
{
    // If there's no aditional arguments return default 'p'
    if (n == 1)
        return 'p';
    // Check if st[1] is option (it begins with '-')
    if (n > 1 && st[1][0] == '-')
        // Return option character
        return st[1][1];
    else
        // Invalid option declaration
        return 0;
}
// Choose which type of the program output to use; in other case run printerr()
void output(char key)
{
    switch(key)
    {
        case 'p':
            printdef();
            break;
            
        case 'u':
            printup();
            break;
        
        case 'l':
            printlow();
            break;
        
        // If key doesn't match print error message
        default:
            printerr(key);
    }
}
// Print input as is
void printdef(void)
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}
// Print error message
void printerr(char key)
{
    if (key != 0)
        // Print message about illegal option character
        printf(ILLEGAL, key);
    puts(USAGE);
}
// Print input to all lowercase
void printlow(void)
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(tolower(c));
}
// Print input to all uppercase
void printup(void)
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(toupper(c));
}
