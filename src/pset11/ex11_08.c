/*
 *  pr_pset11_08.c
 *
 *  Write a function called string_in() that takes two string pointers as
 *  arguments. If the second string is contained in the first string, have
 *  the function return the address at which the contained string begins.
 *  For instance, string_in("hats", "at") would return the address of
 *  the `a` in `hats`. Otherwise, have the function return the null pointer.
 *  Test the function in a complete program that uses a loop to provide
 *  input values for feeding to the function.
 *
 *  Created by gres.cher on 01/02/19.
 */

#include <stdio.h>
#define SIZE 80     // Maximum input line size

void header(const char * s);
char * mygets(char * s, int n);
char * string_in(const char * s1, const char * s2);

int main(void)
{
    char container[SIZE];
    char str[SIZE];
    char *ptr;
    
    header(container);
    puts("Enter new container (Return to quit):");
    while (mygets(container, SIZE))
    {
        printf("String for search (Return to set new container): ");
        while (mygets(str, SIZE))
        {
            if ((ptr = string_in(container, str)))
                printf("Starts at %2ld element, address: %p\n",
                       ptr - container + 1, ptr);
            else
                puts("String is not in container. Try again.");
            
            printf("Next search (Return to set a new container): ");
        }
        puts("Enter new container (Return to quit):");
    }
    puts("done");
    return 0;
}

// Output initial program info
void header(const char * st)
{
    printf("*** Test the string_in() function ***\n\n");
    printf("Address of the container string: %p\n", st);
}

// Read string; return st address if st[] has at list one character
char * mygets(char * st, int lim)
{
    int c, i;
    
    for (i=0, c=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        st[i] = c;
    // Mark the end of the string and discard the rest of the line
    st[i] = '\0';
    if (c != '\n' && c != EOF)
        while (getchar() != '\n')
            continue;
    if (i > 0)
    /* String has more elements than '\0' character */
        return st;
    else
        return NULL;
}

// If `str` is contained in `cont` return the address at which the contained
// string begins. Otherwise, return the null pointer
char * string_in(const char * cont, const char * str)
{
    while (*cont)
    {
        if (*cont == *str)
        {
            // `i` preserves current `cont` for case of possible mismatch
            // with `str+i` elements
            int i = 1;
            while (*(cont+i) == *(str+i))
            {
                if (*(cont+i) == '\0')
                    // Container has no characters left but `str` still has
                    return NULL;
                i++;
            }
            if (*(str+i) == '\0')
                // All elements of `str` are matched
                return (char *)cont;
        }
        cont++;
    }
    return NULL;
}
