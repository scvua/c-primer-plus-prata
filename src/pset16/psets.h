/*
 *  psets.h
 *  A header file of preprocessor definitions (exercise 1 of the Problem Set 16)
 *  Created by gres.cher on 08/21/19.
 */

#ifndef PSETS_H
#define PSETS_H

#include <math.h>
#include <stdio.h>

// Skip the remaining input
#define EATLINE()       while(getchar() != '\n') continue

// The harmonic mean of two numbers (used in ex16_02.c)
#define HRMEAN(X,Y)     (2.0 / (1.0/(X) + 1.0/(Y)))

// Conversions between radians and degrees (used in ex16_03.c)
#define DEG_TO_RAD(X)   ((X) * 4.0 * atan(1) / 180.0)
#define RAD_TO_DEG(X)   ((X) * 180.0 / (4.0 * atan(1)))

// The maximum and minimum of two values
#define MAX(X,Y)        ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y)        ((X) < (Y) ? (X) : (Y))

#endif /* PSETS_H */
