//
// pr_pset04_06:
//
// Write a program that requests the user’s first name and then the user’s
// last name. Have it print the entered names on one line and the number of
// letters in each name on the following line. Align each letter count with
// the end of the corresponding name, as in the following:
//
//     Melissa Honeybee
//           7        8
//
// Next, have it print the same information, but with the counts aligned with
// the beginning of each name.
//
//     Melissa Honeybee
//     7       8
// 

#include <stdio.h>
#include <string.h>

int main(void)
{
    char fname[20];
    char lname[30];
    int fwidth, lwidth;

    printf("Enter your first name: ");
    scanf("%s", fname);
    fwidth = strlen(fname);

    printf("Enter your last name: ");
    scanf("%s", lname);
    lwidth = strlen(lname);

    printf("%s %s\n", fname, lname);
    printf("%*d %*d\n", fwidth, fwidth, lwidth, lwidth);
    printf("\n");
    printf("%s %s\n", fname, lname);
    printf("%-*d %-*d\n", fwidth, fwidth, lwidth, lwidth);

    return 0;
}
