/*
 *  mylib.h
 *  pr_pset14_02 -- version with a header file
 *  Created by gres.cher on 4/25/19.
 */

#define SIZE 21     // Size of the input string
#define LEAP 4      // Leap year
#define ALEN 3      // Length of a month abbreviation string

struct month {
    char name[10];
    char abbr[4];
    int days;
    int num;
};

// Check which month.num the string is; return 0 if string has no month info
int check_month(const char * s);

// Clear input line
void eatline(void);

// Get a string from standard input
char * mygets(char * st, int n);

// Convert string in lowercase; make first letter capital
void strconv(char * out, const char * in);
