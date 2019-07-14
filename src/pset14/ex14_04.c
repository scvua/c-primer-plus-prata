/*
 *  pr_pset14_04.c
 *
 *  Write a program that creates a structure template... Have the program print
 *  the data in this format
 *      Dribble, Flossie M. -- 302039823
 *  Only the intitial letter of the middle name is printed, and a period is
 *  added.
 *  Neither the initial nor the period should be printed if the middle name
 *  member is empty.
 *  a) Write a function to do the printing; pass the struct array to the function.
 *	b) Modify part a by passing the structure value instead of the address.
 *
 *  Created by gres.cher on 04/26/19.
 */

#include <stdio.h>
#define SIZE 5

struct names {
    char * first;
    char * middle;
    char * last;
};

struct secinfo {
    int secnum;
    struct names handle;
};

void printPersonA(const struct secinfo * pst);
void printPersonB(struct secinfo person);
void printInfoAll(const struct secinfo * pst, int lim);

int main(void)
{
    struct secinfo person[SIZE] = {
        {302039823, {"Eugene", "", "Atget"}},
        {281024314, {"Dmitry", "Sergeyevich", "Likhachov"}},
        {312034524, {"Julia", "", "Cameron"}},
        {274169877, {"Viktor", "Emil", "Frankl"}},
        {308515628, {"Olexandr", "Porfyrovych", "Arkhypenko"}}
    };
    puts("Print the contents with the for-loop and printPersonA():\n");
    for (int i = 0; i < SIZE; i++)
        printPersonA(&person[i]);
    puts("\nPrint the contents with the for-loop and printPersonB():\n");
    for (int i = 0; i < SIZE; i++)
        printPersonB(person[i]);
    puts("\nPrint the structure with printInfoAll():\n");
    printInfoAll(person, SIZE);
    puts("Done.");
    
    return 0;
}

void printPersonA(const struct secinfo * pst)
{
    printf("%s, %s ", pst->handle.first, pst->handle.last);
    // Check whether string with middle name is empty
    if (*pst->handle.middle)
        printf("%c. -- %d\n", *pst->handle.middle, pst->secnum);
    else
        printf("-- %d\n", pst->secnum);
}

void printPersonB(struct secinfo person)
{
    printf("%s, %s ", person.handle.first, person.handle.last);
    // Check whether string with middle name is empty
    if (person.handle.middle[0])
        printf("%c. -- %d\n", person.handle.middle[0], person.secnum);
    else
        printf("-- %d\n", person.secnum);
}

// Same as printPersonA() but prints all records of the array at one call
void printInfoAll(const struct secinfo * pst, int lim)
{
    for (int i = 0; i < lim; i++)
    {
        printf("%s, %s ", (pst+i)->handle.first, (pst+i)->handle.last);
        // Check whether string with middle name is empty
        if (*(pst+i)->handle.middle)
            printf("%c. -- %d\n", *(pst+i)->handle.middle, (pst+i)->secnum);
        else
            printf("-- %d\n", (pst+i)->secnum);
    }
}
