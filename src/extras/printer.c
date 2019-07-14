/* printer -- print content of file with '\n' characters */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp;
    int ch;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Couldn't open the file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n')
            printf("\\n\n");
        else
            putchar(ch);
    }
    fclose(fp);

    return 0;
}
