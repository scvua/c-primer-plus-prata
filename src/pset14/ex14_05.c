/*
 *  pr_pset14_05.c
 * 
 *  Write a program that fits the following recipe:
 *  a. Externally define a name structure template with two members: a string
 *    to hold the first name and a string to hold the second name.
 *  b. Externally define a student structure template with three members:
 *    a name structure, a grade array to hold three floating-point scores,
 *    and a variable to hold the average of those three scores.
 *  c. Have the main() function declare an array of CSIZE (with CSIZE = 4)
 *    student structures and initialize the name portions to names of your choice.
 *    Use functions to perform the tasks described in parts d., e., f., and g.
 *  d. Interactively acquire scores for each student by prompting the user with
 *    a student name and a request for scores. Place the scores in the grade
 *    array portion of the appropriate structure. The required looping can be
 *    done in main() or in the function, as you prefer.
 *  e. Calculate the average score value for each structure and assign it
 *    to the proper member.
 *  f. Print the information in each structure.
 *  g. Print the class average for each of the numeric structure members.
 *
 *  Created by gres.cher on 04/27/19.
 */

#include <stdio.h>
#define CSIZE  4
#define GRADES 3

struct names {
    char * first;
    char * last;
};

struct student {
    struct names name;
    float grade[GRADES];
    float aver;
};

float avercalc(const struct student * pst);
void inscores(struct student * pst);
void printscores(const struct student * pst);

int main(void)
{
    struct student class[CSIZE] = {
        {{"Simon", "Posford"}},
        {{"Richard", "James"}},
        {{"Boris", "Blenn"}},
        {{"Mathew", "Jonson"}}
    };
    
    for (int i = 0; i < CSIZE; i++)
        inscores(&class[i]);
    
    for (int i = 0; i < CSIZE; i++)
        class[i].aver = avercalc(&class[i]);
    
    for (int i = 0; i < CSIZE; i++)
        printscores(&class[i]);
    
    return 0;
}

// Calculate and return the average score value for a student structure
float avercalc(const struct student * pst)
{
    float aver = 0.0;
    
    for (int i = 0; i < GRADES; i++)
        aver += pst->grade[i];
    aver /= (float) GRADES;
    
    return aver;
}

void inscores(struct student * pst)
{
    // Print names and the number of scores
    printf("Please, input %d scores for %s %s.\n",
           GRADES, pst->name.first, pst->name.last);
    // Input scores
    for (int i = 0; i < GRADES; i++)
        scanf("%f", &pst->grade[i]);
    // Dispose rest of the line
    while (getchar() != '\n')
        continue;
}

// Print the information in each structure
void printscores(const struct student * pst)
{
    // Print names
    printf("%s %s:\t", pst->name.first, pst->name.last);
    // Print scores
    for (int i = 0; i < GRADES; i++)
        printf("%.2f%s", pst->grade[i],
               i + 1 == GRADES ? "\t" : "  ");
    // Print average
    printf("avr: %.2f\n", pst->aver);
}
