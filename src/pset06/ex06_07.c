//
//  pr_pset06_07:
//
//  Write a program that reads a single word into a character array and then
//  prints the word backward.
//  Hint: Use strlen() (Chapter 4) to compute the index of the last character
//  in the array.
//

#include <stdio.h>
#include <string.h>

#define SIZE 20

int main(void)
{
    int last_ch;
    char word[SIZE];

    printf("Type the word: ");
    scanf("%s", word);
    printf("Word backward: ");
    last_ch = strlen(word) - 1;
    for (int i = last_ch; i >= 0; i--)
        printf("%c", word[i]);
    printf("\n");

    return 0;
}
