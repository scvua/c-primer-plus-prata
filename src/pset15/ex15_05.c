/*
 *  pr_pset15_05.c
 *  rbits() -- the function that rotates the bits of an unsigned int by
 *  a specified number of bits to the left.
 *  Created by gres.cher on 08/02/19.
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void print_bin(const unsigned int num);
unsigned int rbits(unsigned int num, short nbits);

int main(void)
{
    unsigned int num = 0;
    short nbits;

    printf("Enter the unsigned integer: ");
    if (scanf("%u", &num) != 1)
        exit(EXIT_FAILURE);
    printf("Enter the number of bits to rotate: ");
    if (scanf("%hu", &nbits) != 1 || (nbits < 0 || nbits > 31))
        exit(EXIT_FAILURE);
    printf("Your number is: %u\n", num);
    print_bin(num);
    num = rbits(num, nbits);
    printf("\nNew number is:  %u\n", num);
    print_bin(num);

    puts("\nBye.");
    return 0;
}

// Print the binary string
void print_bin(const unsigned int num)
{
    // Initialize the mask with '1' in the high-order bit
    // For a 4-byte integer it will be 0x80000000
    unsigned int mask = 0x1 << (CHAR_BIT * sizeof(int) - 1);

    for (int i = 1; mask > 0; i++, mask >>= 1)
    {
        if ((num & mask) == mask)
            putchar('1');
        else
            putchar('0');
        // Brake the bits into groups of 4
        if (i % 4 == 0 && mask != 0x1)
            putchar(' ');
    }
}

// Rotates the bits of an unsigned int by a specified number of bits to the left
unsigned int rbits(unsigned int num, short nbits)
{
    unsigned int mask = 0x1 << (CHAR_BIT * sizeof(int) - 1);

    while (nbits--)
    {
        if ((num & mask) == mask)
        {
            // The high-order bit is 1
            num <<= 1;
            num |= 0x1;     // Change the low-order bit to 1
        }
        else
            // The high-order bit is 0
            num <<= 1;
    }
    return num;
}
