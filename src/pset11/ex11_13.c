/*
 *  pr_pset11_13.c
 *  Program that echoes the command-line arguments in reverse word order.
 *
 *  Created by gres.cher on 01/11/19.
 */

#include <stdio.h>
#define NEW_ORDER   "Reversed word order: "
#define USAGE       "Usage: input any arguments"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        puts(USAGE);
    }
    else
    {
        printf("%s", NEW_ORDER);
        for (int i = argc-1; i > 0; i--)
            printf("%s ", argv[i]);
        putchar('\n');
    }
    return 0;
}
