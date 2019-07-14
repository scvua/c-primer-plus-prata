/*
 *  pr_pset11_11.c
 *
 *  Write a program that reads in up to 10 strings or to EOF, whichever comes
 *  first. Have it offer the user a menu with five choices:
 *   1. Print the original list of strings
 *   2. Print the strings in ASCII collating sequence
 *   3. Print the strings in order of increasing length
 *   4. Print the strings in order of the length of the first word in the string
 *   5. Quit
 *  Have the menu recycle until the user enters the quit request.
 *
 *  Created by gres.cher on 01/06/19.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SIZE 81       // Maximum input line size
#define LIM  10       // Maximum number of strings

#define END_MSG       "Done"
#define NO_WHITESPACE "Retry with non-whitespace character: "
#define RETRY_CHOICE  "Please respond with 1, 2, 3, 4 or q: "
#define SORTED_HEAD   "\nHere's the sorted list:\n"

int getchoice(void);
char get_first(void);
void print_header(int);
void print_menu(void);
void print_str(char *s[], int n);
char *mygets(char *s, int n);
void sortstr(int n, char *s[], int lim);
void sort_addr(char *s[], int n);
void sort_ascii(char *s[], int n);
void sort_strlen(char *s[], int n);
void sort_wlen(char *s[], int n);
void swap_st(char *s1[], char *s2[]);
int wlen(char *s);

int main(void)
{
    int choice;
    int count = 0;
    char input[LIM][SIZE];
    char *ptstr[LIM];
    
    print_header(LIM);
    // Input the list of strings
    while (count < LIM && mygets(input[count], SIZE))
    {
        ptstr[count] = input[count];
        count++;
    }
    // Choose soting option and print the sorted list
    while ((choice = getchoice()))
    {
        sort_ascii(ptstr, count);
        sortstr(choice, ptstr, count);
        print_str(ptstr, count);
    }
    puts(END_MSG);
    return 0;
}

// Print menu of options and return number of choice; 0 if choice is to quit
int getchoice(void)
{
    int ch;
    
    print_menu();
    ch = get_first();
    while (ch != 'q' && ch != 'Q' && ch != EOF && (ch < '1' || ch > '4'))
    {
        printf(RETRY_CHOICE);
        ch = get_first();
    }
    // Convert choice to an int number
    if (ch >= '1' && ch <= '4')
        ch = ch - '0';
    else
        ch = 0;
    return ch;
}

// Return first input character; skip preceding whitespace
char get_first(void)
{
    char ch;
    
    while (isspace(ch = getchar()) && ch != EOF)
        if (ch == '\n')
            printf(NO_WHITESPACE);
    // Discard the end of the line
    if (ch != EOF)
        while (getchar() != '\n')
            continue;
    
    return ch;
}

// Output initial program info
void print_header(int lim)
{
    puts("*** Test sorting functions ***\n");
    printf("Input up to %d lines.\n", lim);
    puts("To stop, press the Enter key at line's start.");
}

// Output menu with the list of sorting variations
void print_menu(void)
{
    puts("\nHere's how you can print your list of strings.");
    puts("1) Original list of strings");
    puts("2) ASCII collating sequence");
    puts("3) Order of increasing length");
    puts("4) Order of the length of the first word in the string\n");
    printf("Enter the number of your choice ('q' to quit): ");
}

// Output list of strings
void print_str(char *s[], int lim)
{
    puts(SORTED_HEAD);
    for (int i = 0; i < lim; i++)
        puts(s[i]);
}

// Read string; return st address if st[] has at list one character
char * mygets(char *st, int lim)
{
    int c, i;
    
    for (i=0, c=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        st[i] = c;
    // Mark the end of the string and discard the rest of the line
    st[i] = '\0';
    if (c != '\n' && c != EOF)
        while (getchar() != '\n')
            continue;
    /* Check if string has more elements than '\0' character */
    if (i > 0)
        return st;
    else
        return NULL;
}

// Choose the method of sorting by the choice number; apply it to the array
void sortstr(int n, char *ptst[], int lim)
{
    switch(n)
    {
            // Original list of strings
        case 1:
            sort_addr(ptst, lim);
            break;
            // ASCII collating sequence
        case 2:
            sort_ascii(ptst, lim);
            break;
            // Order of increasing length
        case 3:
            sort_strlen(ptst, lim);
            break;
            // Order of the length of the first word in the string
        case 4:
            sort_wlen(ptst, lim);
            break;
    }
}

// Sort pointers in order of increasing their values (get initial sequence)
void sort_addr(char *ptst[], int lim)
{
    for (int top = 0; top < lim; top++)
        for (int seek = top + 1; seek < lim; seek++)
            if (ptst[top] > ptst[seek])
                swap_st(&ptst[top], &ptst[seek]);
}

// Sort pointers in ASCII collating sequence of the strings
void sort_ascii(char *ptst[], int lim)
{
    int top, seek;
    
    for (top = 0; top < lim; top++)
        for (seek = top + 1; seek < lim; seek++)
            if (strcmp(ptst[top], ptst[seek]) > 0)
                swap_st(&ptst[top], &ptst[seek]);
}

// Sort pointers in order of increasing length of the strings
void sort_strlen(char *ptst[], int lim)
{
    for (int top = 0; top < lim; top++)
        for (int seek = top + 1; seek < lim; seek++)
            if (strlen(ptst[top]) > strlen(ptst[seek]))
                swap_st(&ptst[top], &ptst[seek]);
}

// Sort pointers in order of the length of the first word in the string
void sort_wlen(char *ptst[], int lim)
{
    for (int top = 0; top < lim; top++)
        for (int seek = top + 1; seek < lim; seek++)
            if (wlen(ptst[top]) > wlen(ptst[seek]))
                swap_st(&ptst[top], &ptst[seek]);
}

// Interchange pointers to strings between themselves
void swap_st(char *s1[], char *s2[])
{
    char *tmp;
    
    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

// Determine the length of the first word in a string
int wlen(char *s)
{
    int len;
    
    for (len = 0; !isspace(*s) && *s != '\0'; len++)
        s++;
    return len;
}
