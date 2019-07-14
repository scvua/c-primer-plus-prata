/*
 *  exfunc.h -- constants and declarations for exfunc.c
 *  Created by gres.cher on 2/8/19.
 */

#define MIN   1           // Value of the range minimum number
#define MAX   10          // Value of the range maximum number
#define RANGE (MAX-MIN+1) // How many numbers are in the range
#define NSEED 10          // Number of seed values
#define QTY   1000        // Quantity of random numbers per seed value

// Display array values
void display(const int ar[], int lim);

// Generates pseudorandom number
int rand1(void);

// Reset values of the array to all 0
void rstar(int ar[], int lim);

// Set the value of the rand1() seed
void srand1(unsigned int seed);
