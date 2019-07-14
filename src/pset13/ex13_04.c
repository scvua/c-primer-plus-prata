/*
 *  pr_pset13_04.c
 *  Sequentially displays onscreen all the files listed in the command line.
 *  Created by gres.cher on 03/02/19.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch;
    long long count = 0L;
    
    if (argc == 1)
    {
        fprintf(stderr, "Usage: %s file1 file2 ... fileN\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < argc; count = 0, i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        fprintf(stdout, "-> %s contents:\n", argv[i]);
        while ((ch = getc(fp)) != EOF)
        {
            putchar(ch);
            count++;
        }
        putchar('\n');
        fprintf(stdout, "-> %lld symbols is printed.\n\n", count);
        fclose(fp);
    }
    puts("That's all!");
    return 0;
}
