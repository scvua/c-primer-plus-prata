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
        {"Fay", "Marvin"},
        {"Diane", "Selvin"},
        {"Camilla", "Rhodes"},
        {"Leo", "Marvin"},
        {"Boris", "Chuprynka"},
        {"Vladimir", "Smith"},
        {"Jean", "Holloway"},
        {"Will", "Bloom"},
        {"Diane", "Hart"},
        {"Allison", "Adams"},
        {"Jeffrey", "Beaumont"},
        {"Dorothy", "Vallens"},
        {"Frank", "Booth"},
        {"Sandy", "Williams"},
        {"Alice", "Howland"},
        {"Max", "Smith"},
        {"Julie", "Baker"},
        {"Francois", "Ferrand"},
        {"Maya", "Deren"},
        {"Ed", "Bloom"},
        {"James", "Cole"},
        {"Phil", "Groundhogday"},
        {"Bob", "Wiley"},
        {"Siggy", "Marvin"},
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
}

// sort by increasing value
int mycomp(const void * p1, const void * p2)
{
    const names_t * ps1 = (const names_t *) p1;
    const names_t * ps2 = (const names_t *) p2;

    int comp = strcmp(ps1->last, ps2->last);

    return comp ? comp : strcmp(ps1->first, ps2->first);
}
