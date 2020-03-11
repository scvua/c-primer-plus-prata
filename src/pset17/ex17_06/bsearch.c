/* bsearch.c -- the binary search function implementation */
#include "bsearch.h"

int BinSearch(int * ar, const int size, const int trg)
{
    int find = 0;

    if (size > 0)
    // At least there is one number to compare with
    {
        int seek;
        // Determine the midpoint of array
        seek = (0 + size - 1) / 2;

        // Check whether target number is in the array
        if (ar[seek] == trg)
            find = 1;
        else if (ar[seek] > trg)
        // Search in the first half of array
            find = BinSearch(ar, seek, trg);
        else
        // Search in the last half of array
            find = BinSearch( &ar[seek + 1], size - 1 - seek, trg );
    }
    return find;
}
