/*
 * pr_pset09_01:
 *
 * Devise a function called min(x,y) that returns the smaller
 * of two double values. Test the function with a simple driver.
 */

#include <stdio.h>

int min(int, int);

int main(void)
{
    int x, y;


    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    printf("%d is the smaller.\n", min(x, y));

    return 0;
}

int min(int n, int m)
{
    return (n < m) ? n : m;
}
