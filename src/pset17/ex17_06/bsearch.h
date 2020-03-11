/* bsearch.h -- the bunary search function */
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
