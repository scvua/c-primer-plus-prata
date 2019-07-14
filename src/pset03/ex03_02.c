//
//  pr_pset03_02.c
//
//  Write a program that asks you to enter an ASCII code value, such as 66,
//  and then prints the character having that ASCII code.
//

#include <stdio.h>

int main(void)
{
    short c;

    printf("Enter an ASCII code: ");
    scanf("%hd", &c);
    printf("%c\n", c);

    return 0;
}
