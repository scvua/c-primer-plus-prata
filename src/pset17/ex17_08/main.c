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
void findPet(const Tree *pt);
void showPets(const Tree *pt);
void printTreeItem(TreeItem item);
void printListItem(ListItem item);
void countAllPets(const Tree *pt);
void petCounter(TreeItem item);
void uppercase(char *str);
char *s_gets(char *st, int n);

static int numPets;

int main(void)
{
    Tree pets;
    char choice;

    TreeInit(&pets);
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
            case 'n' :  countAllPets(&pets);
                        break;
            case 'd' :  dropPet(&pets);
                        break;
            default  :  puts("Switching error");
        }
    }
    TreeEmpty(&pets);
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
    TreeItem tmpName;
    ListItem tmpKind;
    List *petkindList;

    if (TreeIsFull(pt))
    {
        puts("No room in the club!");
        return;                                                         //-->
    }
    puts("Please enter name of pet:");
    s_gets(tmpName.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(tmpKind.petkind, SLEN);
    uppercase(tmpName.petname);
    uppercase(tmpKind.petkind);

    if (!InTree(&tmpName, pt))
        TreeAddItem(&tmpName, pt);              /* the new pet name */
    petkindList = &TreeItemSearch(&tmpName, pt)->petkind; 
    if (!ListContainsItem(&tmpKind, petkindList))
        ListAddItem(&tmpKind, petkindList);     /* the new pet kind */
    else
        printf("%s the %s is already a member\n", 
                tmpName.petname, tmpKind.petkind);       
}

void dropPet(Tree *pt)
{
    TreeItem tmpName;
    ListItem tmpKind;
    List *petkindList;
    
    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;     /* quit function if tree is empty */                //-->
    }
    
    puts("Please enter name of pet you wish to delete:");
    s_gets(tmpName.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(tmpKind.petkind, SLEN);
    uppercase(tmpName.petname);
    uppercase(tmpKind.petkind);
    printf("%s the %s ", tmpName.petname, tmpKind.petkind);
    
    if (InTree(&tmpName, pt))
    {
        // Petname is in the tree, so look up for a kind in the tree item list
        petkindList = &TreeItemSearch(&tmpName, pt)->petkind;
        if (ListRemoveItem(&tmpKind, petkindList))
        {
            if (ListIsEmpty(petkindList)) // Last kind with the name is removed
                TreeDeleteItem(&tmpName, pt);             // so delete the name
            printf("is dropped from the club.\n");
            return; /* quit function if pet is successfully deleted */  //-->
        }
    }
    printf("is not a member.\n");
}

void findPet(const Tree *pt)
{
    TreeItem tmpName;
    ListItem tmpKind;
    List *petkindList;
    
    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;     /* quit function if tree is empty   */              //-->
    }
    
    puts("Please enter name of pet you wish to find:");
    s_gets(tmpName.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(tmpKind.petkind, SLEN);
    uppercase(tmpName.petname);
    uppercase(tmpKind.petkind);
    printf("%s the %s ", tmpName.petname, tmpKind.petkind);
    if (InTree(&tmpName, pt))
    {
        petkindList = &TreeItemSearch(&tmpName, pt)->petkind;
        if (ListContainsItem(&tmpKind, petkindList))
        {
            printf("is a member.\n");
            return;     /* quit function if pet is in a club */         //-->
        }
    }
    printf("is not a member.\n");
}

void showPets(const Tree *pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        TreeTraverse(pt, printTreeItem);
}

void printTreeItem(const TreeItem item)
{
    printf(" Pet: %-19s\n", item.petname);
    ListTraverse(&item.petkind, printListItem);
    puts("- - - - - - -");
}

void printListItem(const ListItem item)
{
    printf("Kind: %-19s\n", item.petkind);
}

void countAllPets(const Tree *pt)
{
    numPets = 0;
    TreeTraverse(pt, petCounter);
    printf("%d %s in club\n", numPets, numPets == 1 ? "pet" : "pets");
}

void petCounter(TreeItem item)
{
    numPets += item.petkind.len;
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

