/*
 *  pr_pset15_06.c
 *  Design a bit-field structure that holds the following information:
 *      Font ID: A number in the range 0-255
 *      Font Size: A number in the range 0-127
 *      Alignment: A number in the range 0-2 (Left, Center and Right)
 *      Bold: Off (0) or on (1)
 *      Italic: Off (0) or on (1)
 *      Underline: Off (0) or on (1)
 *  Use this structure in a program that displays the font parameters and uses
 *  a looped menu to let the user change parameters.
 *  Created by gres.cher on 08/09/19.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENU_COLS     3
#define FONT_ID_MAX   255
#define FONT_SIZE_MAX 127

enum alignid {left, center, right};
enum stateid {off, on};

// Labels
const char * label_align = "lcr";
const char * label_mainmenu = "fsabiuq";

// Names
// The array with the alignment state names
const char * name_align[] = {"left", "center", "right"};
// The array with the names of the main menu
const char * name_mainmenu[] = {
    "change font", "change size", "change alignment",
    "toggle bold", "toggle italic", "toggle underline",
    "quit"
};
// The names of the toggle states
const char * state[] = {"off", "on"};

// Bit-field structure
struct font_param {
    unsigned int id         : 8;
    unsigned int size       : 7;
    unsigned int            : 1;
    unsigned int align      : 2;
    unsigned int            : 2;
    unsigned int is_bold    : 1;
    unsigned int is_italic  : 1;
    unsigned int is_unline  : 1;
    unsigned int            : 1;
};

// Functions
void eatline(void);
char getchoice(const char *);
void print_menu(const char * name[], const char * labs, const int cols);
void print_retry(const char *);
void print_status(const struct font_param *);
unsigned int scan_param(const int);

int main(void)
{
    struct font_param font = {1, 12, left, off, off, off};
    char choice = 0;

    print_menu(name_mainmenu, label_mainmenu, MENU_COLS);
    while ((choice = getchoice(label_mainmenu)) != 'q' && choice != EOF)
    {
        switch (choice)
        {
            case 'f':   // change font id
                printf("Enter font id (0-%d): ", FONT_ID_MAX);
                font.id = scan_param(FONT_ID_MAX);
                break;

            case 's':   // change font size
                printf("Enter font size (0-%d): ", FONT_SIZE_MAX);
                font.size = scan_param(FONT_SIZE_MAX);
                break;

            case 'a':   // change alignment
                print_menu(name_align, label_align, MENU_COLS);
                font.align = (unsigned int)(strchr(label_align, getchoice(label_align)) - label_align);
                break;

            case 'b':   // toggle bold
                font.is_bold = ~(font.is_bold);
                break;

            case 'i':   // toggle italic
                font.is_italic = ~(font.is_italic);
                break;

            case 'u':   // toggle underline
                font.is_unline = ~(font.is_unline);
                break;
        }
        print_status(&font);
        print_menu(name_mainmenu, label_mainmenu, MENU_COLS);
    }
    puts("Bye!");
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
void print_status(const struct font_param * font)
{
    extern const char * name_align[];
    extern const char * state[];

    printf("  ID SIZE ALIGNMENT  B   I   U\n");
    printf(" %3d  %3d  %6s   %3s %3s %3s\n",
           font->id, font->size, name_align[font->align], state[font->is_bold],
           state[font->is_italic], state[font->is_unline]);
}

// Scan parameter value and convert it to the specified range by the `lim` mask
unsigned int scan_param(const int lim)
{
    int num;
    while (scanf("%d", &num) != 1)
        printf("Retry with integer (0-%d): ", lim);
    eatline();
    num &= lim;
    return (unsigned int) num;
}
