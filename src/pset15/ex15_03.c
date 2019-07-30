/*
 *  pr_pset15_03.c
 *  The function that takes an int argument and returns the number of "on" bits
 *  in the argument.
 *  Created by gres.cher on 07/30/19.
 */
#include <limits.h>
#include <stdio.h>

int countones(int num);
void print_bin(int num);

int main(void)
{
    int num, n_on;

    printf("Enter a number ('q' to quit): ");
    while (scanf("%d", &num) == 1)
    {
        print_bin(num);
        n_on = countones(num);
        printf("\ncontains %d %s that are \"on\"\n",
               n_on, n_on == 1 ? "bit" : "bits");
        printf("Enter next value: ");
    }
    puts("Bye.");

    return 0;
}

// Count the number of "on" bits in the argument.
int countones(int num)
{
    // Initialize the mask with '1' in the high-order bit
    // For a 4-byte integer it will be 0x80000000
    unsigned int mask = 0x1 << (CHAR_BIT * sizeof(int) - 1);
    int count;

    for (count = 0; mask > 0; mask >>= 1)
        if ((num & mask) == mask)
            count++;
    return count;
}

// Print the binary string (the `for` loop version is in the ex15_02.c)
void print_bin(int num)
{
    unsigned int mask = 0x1 << (CHAR_BIT * sizeof(int) - 1);
    int i = 0;

    while (mask > 0)
    {
        if ((num & mask) == mask)
            putchar('1');
        else
            putchar('0');
        mask >>= 1;
        // Brake the bits into groups of 4
        if (++i % 4 == 0 && mask != 0x0)
            putchar(' ');
    }
}
