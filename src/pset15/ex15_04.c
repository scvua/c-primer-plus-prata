/*
 *  pr_pset15_04.c
 *  bitison() -- the function that takes two int arguments: a value and a bit
 *  position. Return 1 if that particular bit position is 1, otherwise return 0.
 *  Created by gres.cher on 07/31/19.
 */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define BIT_IS_ON   "Bit #%d is \"on\"\n"
#define BIT_IS_OFF  "Bit #%d is \"off\"\n"

unsigned short bitison(int, int);
void exit_failure(void);
void print_bpos(int, unsigned short);
void print_bin(int, char, char);


int main(void)
{
    int nval;
    unsigned short nbit;

    printf("Enter a number: ");
    if (scanf("%d", &nval) != 1)
        exit_failure();
    printf("Enter bit position: ");
    if (scanf("%hd", &nbit) != 1)
        exit_failure();
    print_bpos(nval, nbit);
    if (bitison(nval, nbit))
        printf(BIT_IS_ON, nbit);
    else
        printf(BIT_IS_OFF, nbit);
    puts("Bye.");

    return 0;
}

// Check whether the bit at specified position is "on", if so return 1
unsigned short bitison(int num, int bpos)
{
    unsigned int mask = 0x1 << bpos;

    if ((num & mask) == mask)
        return 1;
    else
        return 0;
}

// Print error message and exit the program
void exit_failure(void)
{
    printf("An integer number was expected.\n");
    printf("Bye.\n");
    exit(EXIT_FAILURE);
}

// Print number as binary in the first row;
// Pinpoint the location of the bit position in the second row
void print_bpos(int num, unsigned short bpos)
{
    // Print the first row with the binary
    print_bin(num, '1', '0');
    putchar('\n');

    unsigned int bitplace = 0x1 << bpos;
    // Print the second row with the bit's position marker
    print_bin(bitplace, '^', ' ');
    putchar('\n');
}

// Output the number as binary with specific characters for "on" and "off" state
void print_bin(int num, char ch_on, char ch_off)
{
    // Initialize the mask with the single 1 in the high-order bit
    unsigned int mask = 0x1 << (CHAR_BIT * sizeof(int) - 1);

    for (int i = 0; mask > 0; mask >>= 1)
    {
        if ((num & mask) == mask)
            putchar(ch_on);
        else
            putchar(ch_off);
        // Brake the bits into groups of 4
        if (++i % 4 == 0 && mask != 0x1)
            putchar(' ');
    }
}
