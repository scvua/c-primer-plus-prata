/*
 *  ex16_06.c
 *  Modification of the listing 16.17 so that it uses an array of struct names
 *  elements instead of an array of double.
 *  Created by gres.cher on 08/26/19.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM   40
#define SIZE  25

typedef struct {
    char first[NUM];
    char last[NUM];
} names_t;


void showarray(const names_t ar[], int lim);
int mycomp(const void * p1, const void * p2);

int main(void)
{
    names_t staff[SIZE] = {
        {"Alice", "Shvidiani"},
        {"Diane", "Selvin"},
        {"Camilla", "Rhodes"},
        {"Boris", "Chuprynka"},
        {"Max", "Smith"},
        {"Vladimir", "Smith"},
        {"Jean", "Holloway"},
        {"Diane", "Hart"},
        {"Allison", "Adams"},
        {"Jeffrey", "Beaumont"},
        {"Dorothy", "Vallens"},
        {"Frank", "Booth"},
        {"Sandy", "Williams"},
        {"Alice", "Howland"},
        {"Julie", "Baker"},
        {"Francois", "Ferrand"},
        {"Maya", "Deren"},
        {"Ed", "Bloom"},
        {"Will", "Bloom"},
        {"James", "Cole"},
        {"Bob", "Wiley"},
        {"Leo", "Marvin"},
        {"Fay", "Marvin"},
        {"Siggy", "Marvin"},
        {"Phil", "Groundhogday"},
    };

    puts("Random list: ");
    showarray(staff, SIZE);
    qsort(staff, SIZE, sizeof(names_t), mycomp);
    puts("\nSorted list:");
    showarray(staff, SIZE);
    return 0;
}

void showarray(const names_t ar[], int lim)
{
    for (size_t i = 0; i < lim; i++)
        printf("%s, %s\n", ar[i].last, ar[i].first);
    return;
}

// sort by increasing value
int mycomp(const void * p1, const void * p2)
{
    const names_t * ps1 = (const names_t *) p1;
    const names_t * ps2 = (const names_t *) p2;
    int comp;

    comp = strcmp(ps1->last, ps2->last);
    if (comp != 0)
        return comp;
    else
        return strcmp(ps1->first, ps2->first);
}
