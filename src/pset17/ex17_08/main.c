/*
 *  ex17_08:main.c
 *  Modify the Pet Club program so that all pets with the same name are stored
 *  in a list in the same node. When the user chooses to find a pet, 
 *  the program should request the pet name and then list all pets (along
 *  with their kinds) having that name.
 *  Created by grescher on 07/17/20.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void addPet(Tree *pt);
void dropPet(Tree *pt);
void showPets(const Tree *pt);
void findPet(const Tree *pt);
void printItem(Item item);
void uppercase(char *str);
char *s_gets(char *st, int n);

int main(void)
{
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 'a' :  addPet(&pets);
                        break;
            case 'l' :  showPets(&pets);
                        break;
            case 'f' :  findPet(&pets);
                        break;
            case 'n' :  printf("%d pets in club\n", TreeItemCount(&pets));
                        break;
            case 'd' :  dropPet(&pets);
                        break;
            default  :  puts("Switching error");
        }
    }
    DeleteAll(&pets);
    puts("Bye.");

    return 0;
}

char menu(void)
{
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')   /* discard rest of line */
            continue;
        ch = tolower(ch);
        if (strchr("alnfdq", ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q:");
        else
            break;
    }
    if (ch == EOF)      /* make EOF cause program to quit   */
        ch = 'q';

    return ch;
}

void addPet(Tree *pt)
{
    Item temp;

    if (TreeIsFull(pt))
        puts("No room in the club!");
    else
    {
        puts("Please enter name of pet:");
        s_gets(temp.petname, SLEN);
        puts("Please enter pet kind:");
        s_gets(temp.petkind, SLEN);
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp, pt);
    }
}

void showPets(const Tree *pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printItem);
}

void printItem(Item item)
{
    printf("Pet: %-19s Kind: %-19s\n", item.petname, item.petkind);
}

void findPet(const Tree *pt)
{
    Item temp;
    
    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;     /* quit function if tree is empty   */              //-->
    }


    puts("Please enter name of pet you wish to find:");
    s_gets(temp.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (InTree(&temp, pt))
        printf("is a member.\n");
    else 
        printf("is not a member.\n");
}

void dropPet(Tree *pt)
{
    Item temp;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;     /* quit function if tree is empty */
    }

    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (DeleteItem(&temp, pt))
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");
}

void uppercase(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');        // look for newline
        if (find)                       // if the address is not NULL,
            *find = '\0';               // place a null character there
        else
            while (getchar() != '\n')
                continue;               // dispose of rest of line
    }
    return ret_val;
}

