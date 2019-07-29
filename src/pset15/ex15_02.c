/*
 *  pr_pset15_02.c
 *  Program reads two binary strings as CL arguments and prints the results
 *  of applying the ~ operator to each number and the results of applying the
 *  &, |, and ^ operators to the pair. The results are shown as binary strings.
 *  Created by gres.cher on 07/29/19.
 */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N_ARGC  3
#define N_NUM   N_ARGC - 1  // Number of the numbers to process
#define N_OPER  3           // Number of operators

int bit_and(int, int);
int bit_or(int, int);
int bit_xor(int, int);
int bstoi(const char *);
bool isbinary(const char *);
void print_bin(const int num);
void print_not(const int num);
void print_res(int, int, int);

// Array of the pointer-to-operator-function to recall the chapter 14
int (* ofp[N_OPER])(int, int) = {bit_and, bit_or, bit_xor};
enum operator {and, or, xor};
char opersign[N_OPER] = {'&', '|', '^'};

int main(int argc, const char * argv[])
{
    // Check the number of command-line arguments
    if (argc != N_ARGC)
    {
        printf("Usage: %s [binary] [binary]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num[N_NUM];
    enum operator oper;

    // Check and assign binary strings from the command-line input
    for (int i = 1; i < argc; i++)
    {
        // Exit the program if the i-th string is not binary
        if (!isbinary(argv[i]))
        {
            printf("The string is not a binary: \"%s\"\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        else
        {
            // Assign value from the i-th CL-argument
            num[i-1] = bstoi(argv[i]);
        }
    }
    puts("Print the results of applying the ~ operator:");
    for (int i = 0; i < N_NUM; i++)
        print_not(num[i]);

    puts("Print the results of applying the &, |, and ^ operators:");
    for (oper = and; oper < N_OPER; oper++)
        print_res(oper, num[0], num[1]);

    puts("Bye.");
    return 0;
}

// Bitwise AND
int bit_and(int d1, int d2)
{
    return d1 & d2;
}

// Bitwise OR
int bit_or(int d1, int d2)
{
    return d1 | d2;
}

// Bitwise EXCLUSIVE OR
int bit_xor(int d1, int d2)
{
    return d1 ^ d2;
}

// Convert a binary string to a numberic value
int bstoi(const char * bst)
{
    int num;

    for (num = 0; *bst != '\0'; bst++)
    {
        num <<= 1;
        if (*bst == '1')
            num++;      // add 1 to the 0th bit
        else if (*bst != '0')
            break;
    }
    return num;
}

// Check whether the string consists from '0' and '1' only
bool isbinary(const char * st)
{
    while (*st)
    {
        if (*st != '0' && *st != '1')
            return false;
        st++;
    }
    return true;
}

// Print the binary string
void print_bin(const int num)
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

// Print the result of applying the ~ operator to a number
void print_not(const int num)
{
    printf("  ~(");
    print_bin(num);
    printf(")\n  = ");
    print_bin(~num);
    puts("\n");
}

// Print the result of applying the &, |, and ^ operators to the pair
void print_res(int oper, int n1, int n2)
{
    extern int (* ofp[N_OPER])(int, int);
    extern char opersign[N_OPER];

    printf("    ");
    print_bin(n1);
    printf("\n  %c ", opersign[oper]);
    print_bin(n2);
    printf("\n  = ");
    print_bin((ofp[oper])(n1, n2));
    puts("\n");
}
