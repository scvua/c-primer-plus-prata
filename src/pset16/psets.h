/*
 *  psets.h
 *  A header file of preprocessor definitions (exercise 1 of the Problem Set 16)
 *  Created by gres.cher on 08/21/19.
 */

#ifndef PSETS_H
#define PSETS_H

#include <stdio.h>

// Skip the remaining input
#define EATLINE()   while(getchar() != '\n') continue

// The harmonic mean of two numbers (for ex16_02.c)
#define HRMEAN(X,Y) (2.0 / (1.0/(X) + 1.0/(Y)))

// The maximum of two values
#define MAX(X,Y)    ((X) > (Y) ? (X) : (Y))

// The minimum of two values
#define MIN(X,Y)    ((X) < (Y) ? (X) : (Y))

#endif /* PSETS_H */
