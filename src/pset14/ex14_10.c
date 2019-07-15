/*
 *  pr_pset14_10.c
 *  Program that implements a menu by using an array of pointers to functions.
 *  Created by gres.cher on 07/15/19.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SIZE 4

void eatline(void);
char getfirst(void);
int getfloats(float *, float *);
char showmenu(void);
void showres(int, float, float);
float add(float, float);
float diff(float, float);
float divide(float, float);
float multiply(float, float);

int main(void)
{
    float a, b;

    puts("Enter two numbers ('q' to quit)");
    while (getfloats(&a, &b))
    {
        char choice;

        while ((choice = showmenu()) != 'n')
            showres(choice - 'a', a, b);
        puts("Enter next values ('q' to quit)");
    }
    puts("Bye.");
    return 0;
}

// Skip the remaining input
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

// Get the first char from the input; skip the preceding whitespace
char getfirst(void)
{
    char ch;
    // Skip the preceding whitespace
    while (isspace(ch = getchar()))
        if (ch == '\n')
            printf("Enter a non space character: ");
    eatline();
    return ch;
}

// Prompt the user for two float numbers
int getfloats(float * a, float * b)
{
    printf("First number: ");
    if (scanf("%f", a) == 0)
        return 0;
    eatline();

    printf("Second number: ");
    if (scanf("%f", b) == 0)
        return 0;
    eatline();

    return 1;
}

// Print the menu of operations; return the lowercase character
char showmenu(void)
{
    const int msize = 5;
    char ans;
    char * labels = "abcdn";

    char * line[msize] = {
        "calculate the amount",
        "calculate the difference",
        "make a division",
        "multiply",
        "input next values"
    };

    // Print the menu
    puts("Choose an arithmetic operation:");
    for (int i = 0; i < msize; i++)
        printf("  %c) %s\n", labels[i], line[i]);
    // Get answer and check whether it corresponds to one of the labels.
    ans = getfirst();
    ans = tolower(ans);
    while (strchr(labels, ans) == NULL)
    {
        // Print the retry prompt
        printf("Please enter <");
        for (int i = 0; i < msize; i++)
            printf("%c%s", labels[i], i + 1 != msize ? ", " : ">:\n");
        // Get new answer
        ans = tolower(getfirst());
    }
    return ans;
}

// Print formatted result of one of the arithmetic operations
void showres(int func_num, float a, float b)
{
    // An array of pointers to functions
    float (* pf[SIZE])(float, float) = {
        add,
        diff,
        divide,
        multiply
    };
    char sign[SIZE] = {'+', '-', '/', '*'};

    printf("%g %c %g = %g\t Function address: %p\n",
           a, sign[func_num], b, (pf[func_num])(a, b), pf[func_num]);
}

// Calculate the amount
float add(float a, float b)
{
    return (a + b);
}

// Calculate the difference
float diff(float a, float b)
{
    return (a - b);
}

// Make a division
float divide(float a, float b)
{
    return (a / b);
}

// Multiply
float multiply(float a, float b)
{
    return (a * b);
}
