/* 
 *  bsearch.h -- solution for ex17_06
 *  Write the function that uses the binary search technique. 
 *  The function returns the value 1 if the integer is in the array, 
 *  and 0 if it isn't.
 *  Created by grescher on 02/25/2020.
 */
#ifndef _BSEARCH_H_
#define _BSEARCH_H_

/* operation:       search for integer in the sorted array          */
/* preconditions:   ar is the name of an array of sorted integers   */
/*                  size - number of elements of the array          */
/*                  trg is an integer to seek                       */
/* postconditions:  returns the value 1 if the trg is in the        */
/*                  array, and 0 if it isn't                        */
int BinSearch(int * ar, const int size, const int trg);

#endif  /* _BSEARCH_H_   */
