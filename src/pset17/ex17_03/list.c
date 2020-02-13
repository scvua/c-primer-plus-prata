/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* set the list to empty */
void InitializeList(List * plist)
{
    EmptyTheList(plist);
    plist->items = 0;
}

/* returns true if list is empty */
bool ListIsEmpty(const List * plist)
{
    return (plist->items == 0);
}

/* returns true if list is full */
bool ListIsFull(const List * plist)
{
    return (plist->items >= MAXSIZE);
}

/* returns number of nodes */
unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}

/* adds item to the end of the list and increases       */
/* the list items count by 1                            */
bool AddItem(Item item, List * plist)
{
    if (ListIsFull(plist))
        return false;       /* quit function on failure */      //-->
    
    plist->entries[plist->items] = item;
    plist->items++;
    return true;
}

/* visit each node and execute function pointed to by pfun */
void Traverse(const List * plist, void (* pfun)(Item item))
{
    for (int i = 0; i < plist->items; i++)
        (*pfun)(plist->entries[i]); /* apply function to item */
}

/* just set number of items to 0    */
void EmptyTheList(List * plist)
{
    plist->items = 0;
}

