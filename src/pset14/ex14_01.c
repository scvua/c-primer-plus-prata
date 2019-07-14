/*
 *  pr_pset14_01.c
 *  Write a function that, when given the spelled-out name of the month,
 *  returns the total days in the year up to including that month.
 *  Created by gres.cher on 04/23/19.
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define SIZE 81

struct month {
    char name[10];
    char abbr[4];
    int days;
    int num;
};

struct month months[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

int daysCalc(const struct month * pst, const char * s);
void s_convert(char * t, const char * s);
char * mygets(char *restrict st, const int n);

int main(void)
{
    char input[SIZE];
    char test[SIZE];
    int days;
    
    puts("Enter a name of the month:");
    while (mygets(input, SIZE) != NULL && input[0] != '\0')
    {
        s_convert(test, input);
        if ((days = daysCalc(months, test)) != 0)
            printf("%d days.\n", days);
        else
            printf("\"%s\" is unknown month. Try again.\n", input);
        puts("Enter next name ([enter] to quit):");
    }
    puts("Done.");
    
    return 0;
}
// Calculate total days in the year up to st month
int daysCalc(const struct month * pst, const char * st)
{
    int tot = 0;
    int i = 0;
    // Compare each month name with st to find the corresponding month's indice
    while (strcmp(st, pst[i].name))
    {
        if (pst[i].num == 12)
            return 0;			// There is no month left to check
        i++;
    }
    // Find the sum of days
    while (i >= 0)
    {
        tot += pst[i--].days;
    }
    return tot;
}
// Transform and copy string; out string begins with a capital letter
void s_convert(char * out, const char * in)
{
    // Capitalize first letter
    if (*in != '\0')
        *out++ = toupper(*in++);
    // Convert to lowercase rest of the input string
    while (*in)
        *out++ = tolower(*in++);
    // Finalize output string with null character
    *out = '\0';
}

// Get a string from standard input
char * mygets(char *restrict st, const int n)
{
    int ch, i;
    
    for (i=0, ch=0; (i < n-1) && ((ch=getc(stdin)) != EOF) && (ch != '\n'); i++)
        st[i] = ch;
    st[i] = '\0';
    if (ch != EOF && ch != '\n')
        while (getchar() != '\n')
            continue;
    if (i > 0)
        return st;
    else
        return NULL;
}
