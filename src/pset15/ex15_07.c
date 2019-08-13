/*
 *  pr_pset15_07.c
 *  Use the unsigned long variable that holds the following information:
 *      Font ID: A number in the range 0-255
 *      Font Size: A number in the range 0-127
 *      Alignment: A number in the range 0-2 (Left, Center and Right)
 *      Bold: Off (0) or on (1)
 *      Italic: Off (0) or on (1)
 *      Underline: Off (0) or on (1)
 *  Use it in a program that displays the font parameters and uses a looped
 *  menu to let the user change parameters. Use the bitwise operators to manage
 *  the information.
 *  Created by gres.cher on 08/10/19.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MENU_COLS       3
#define ID_MASK         0xFF
#define SIZE_MASK       0x7F00
#define SIZE_SHIFT      8
// Alignment options
#define ALIGN_LEFT      0x0
#define ALIGN_CENTER    0x8000
#define ALIGN_RIGHT     0x10000
#define ALIGN_MASK      0x18000
#define ALIGN_SHIFT     15
// Style options
#define STYLE_BOLD      0x20000
#define STYLE_ITALIC    0x40000
#define STYLE_UNDERLINE 0x80000
#define STYLE_MASK      0xE0000

// Define the font parameters type
typedef unsigned long font_p;

// Labels
const char * label_align = "lcr";
const char * label_mainmenu = "fsabiuq";

// Names for the menues
// The alignment menu item names
const char * name_align[] = {"left", "center", "right"};
// The main menu item names
const char * name_mainmenu[] = {
    "change font", "change size", "change alignment",
    "toggle bold", "toggle italic", "toggle underline",
    "quit"
};

// Functions
void eatline(void);
char getchoice(const char *);
unsigned short getnum(const unsigned short maxnum);
void print_menu(const char * name[], const char * labs, const int cols);
void print_retry(const char *);
void print_status(const font_p *);
bool set_align(font_p *);
bool set_fontid(font_p * pf);
bool set_fontsize(font_p * pf);
bool set_props(font_p *, char);
char user_prompt(font_p *);

int main(void)
{
    font_p font;
    char answer;

    // Initialize bits of the font
    font = 0x1;                  // Font ID is 1
    font |= (0xC << SIZE_SHIFT); // Font's size is 12
    font &= (~ALIGN_MASK);       // Alignment is set to the "left" value (0)
    font &= (~STYLE_MASK);       // All of the style parameters are toggle off

    do
    {
        answer = user_prompt(&font);
    }
    while (set_props(&font, answer));

    return 0;
}

// Skip the remaining input
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

// Get the user's answer and compare it with elements of the `labels`
// `labels` is the string with option letters
char getchoice(const char * labels)
{
    int ch;
    while ((ch = getchar()) != EOF)
    {
        // Skip preceding whitespace
        if (isspace(ch))
        {
            if (ch == '\n')
                print_retry(labels);
            continue;
        }
        eatline();
        // Convert to lowercase and check if answer matches
        ch = tolower(ch);
        if (strchr(labels, ch) != NULL)
            return ch;
        else
            print_retry(labels);
    }
    return ch;
}

// Get the short int and convert it to the specified range by the `maxnum` mask
unsigned short getnum(const unsigned short maxnum)
{
    unsigned short num;
    while (scanf("%hu", &num) != 1)
    {
        printf("Retry with integer (0-%d): ", maxnum);
        eatline();
    }
    eatline();
    num &= maxnum;
    return num;
}

// Print menu with item names and corresponding letter labels
void print_menu(const char * iname[], const char * labels, const int columns)
{
    int i = 0;
    while (*(labels + i) != '\0')
    {
        printf("%c)%-15s", labels[i], iname[i]);
        // If there are as many names as there should be columns in the line
        if (++i % columns == 0)
            putchar('\n');
    }
    // If the number of names in the last row is less than the number of columns
    if (i % columns != 0)
        putchar('\n');
}

// Print the retry request; use characters from the 'labels' string
void print_retry(const char * labels)
{
    printf("Please use keys <");
    while (*labels)
    {
        printf("%c%s", *labels, *(labels + 1) ? ", " : ">:\n");
        labels++;
    }
}

// Display the font parameters
void print_status(const font_p * pf)
{
    extern const char * name_align[];

    printf("  ID SIZE ALIGNMENT  B   I   U\n");
    // Font's id and size
    printf("%4lu", *pf & ID_MASK);
    printf("%5lu", (*pf & SIZE_MASK) >> SIZE_SHIFT);
    // Alignment
    printf("%8s", name_align[(*pf >> ALIGN_SHIFT) & 0x3]);
    // States of the style switches
    printf("%6s", (*pf & STYLE_BOLD) == STYLE_BOLD ? "on" : "off");
    printf("%4s", (*pf & STYLE_ITALIC) == STYLE_ITALIC ? "on" : "off");
    printf("%4s\n",
           (*pf & STYLE_UNDERLINE) == STYLE_UNDERLINE ? "on" : "off");
}

// Set the font's alignment; return false if function meets an incorrect input
bool set_align(font_p * pf)
{
    char answer;
    extern const char * label_align;
    extern const char * name_align[];

    *pf &= (~ALIGN_MASK);   // Reset alignment
    print_menu(name_align, label_align, MENU_COLS);
    answer = getchoice(label_align);
    switch (answer)
    {
        case 'l':  *pf |= ALIGN_LEFT; return true;
        case 'c':  *pf |= ALIGN_CENTER; return true;
        case 'r':  *pf |= ALIGN_RIGHT; return true;
        default :  fprintf(stderr, "Unknown menu input.\n"); return false;
    }
}

bool set_fontid(font_p * pf)
{
    unsigned short num;
    const static unsigned short maxnum = ID_MASK;

    printf("Enter font id(0-%d): ", maxnum);
    num = getnum(maxnum);
    *pf &= (~ID_MASK);
    *pf |= num;
    return true;
}

bool set_fontsize(font_p * pf)
{
    unsigned short num;
    const static unsigned short maxnum = (SIZE_MASK >> SIZE_SHIFT);

    printf("Enter font size(0-%d): ", maxnum);
    num = getnum(maxnum);
    *pf &= (~SIZE_MASK);
    *pf |= (num << SIZE_SHIFT);
    return true;
}

bool set_props(font_p * pf, char answer)
{
    switch (answer)
    {
        case 'f':
            return set_fontid(pf) ? true : false;

        case 's':
            return set_fontsize(pf) ? true : false;

        case 'a':
            return set_align(pf) ? true : false;

        case 'b':
            *pf ^= STYLE_BOLD; return true;

        case 'i':
            *pf ^= STYLE_ITALIC; return true;

        case 'u':
            *pf ^= STYLE_UNDERLINE; return true;

        case 'q':
            puts("Bye."); return false;

        default :
            fprintf(stderr, "Unknown menu input.\n"); return false;
    }
}

// Print the main menu and get the user's choice
char user_prompt(font_p * pf)
{
    extern const char * label_mainmenu;
    extern const char * name_mainmenu[];

    print_status(pf);
    print_menu(name_mainmenu, label_mainmenu, MENU_COLS);
    return getchoice(label_mainmenu);
}
