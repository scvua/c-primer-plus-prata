/*
 *  mylib.c
 *  pr_pset14_02 -- version with a header file
 *  Created by gres.cher on 4/25/19.
 */

#include <ctype.h>
#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int check_month(const char * st)
{
    extern struct month months[12];
    int mon;
    unsigned int slen;
    char temp[SIZE];
    
    // Check whether a string contains whitespace in beforehand; omit it
    while (*st != '\0' && isspace(*st))
        st++;
    // Check what type is the first char of the string
    if (isdigit(*st))
    {
        // The string begins with a digit
        // Convert string to number and check if it is in range 1-12 months
        mon = atoi(st);
        if (mon > 0 && mon <= 12)
            return mon;
        else
            return 0;
    }
    else if (isalpha(*st) && (slen = (unsigned int) strlen(st)) >= ALEN)
    {
        // The string begins with a letter and it has sufficient length
        mon = 0;
        // Capitalize the first char and make the rest in lowercase
        strconv(temp, st);
        // Check whether the string is abbreviation or full month name
        if (slen == ALEN)
        {
            // Abbreviation case
            while (mon < 12 && strncmp(months[mon].abbr, temp, ALEN))
                mon++;
        }
        else
        {
            // Name case
            while (mon < 12 && strcmp(months[mon].name, temp))
                mon++;
        }
        if (mon == 12)
            return 0;	// no match were found
        else
            return (++mon);
    }
    else
        // The string begins with the inappropriate character
        return 0;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

char * mygets(char * st, int n)
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

void strconv(char * out, const char * in)
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
