/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* local function prototype */
static void copyToListNode(const ListItem *pi, ListNode *pnode);
static bool itemsIsEqual(const ListItem *i1, const ListItem *i2);
static ListNode *listItemSeek(const ListItem *pi, const List *plist);

/* interface functions      */

/* set the list to empty    */
void ListInit(List *plist)
{
    plist->front = NULL;
    plist->back = NULL;
    plist->len = 0;
}

/* returns true if list is empty */
bool ListIsEmpty(const List *plist)
{
    return (plist->front == NULL);
}

/* returns true if list is full */
bool ListIsFull(const List *plist)
{
    ListNode *pt;
    bool full;

    pt = (ListNode *) calloc(1, sizeof(ListNode));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}

/* returns number of nodes  */
unsigned int ListItemCount(const List *plist)
{
    return plist->len;
}

/* creates node to hold item and adds it to the end of  */
/* the list pointed to by plist (slow implementation)   */
bool ListAddItem(const ListItem *pi, List *plist)
{
    ListNode *pnew;

    pnew = (ListNode *) calloc(1, sizeof(ListNode));
    if (pnew == NULL)
        return false;   /* quit function on failure     */              //-->

    copyToListNode(pi, pnew);
    pnew->next = NULL;
    if (ListIsEmpty(plist)) /* empty list so place      */
    {                       /* pnew at head of list     */
        pnew->prev = NULL;
        plist->front = pnew;
        plist->back = pnew;
    }
    else                    /* add pnew to end          */
    {
        pnew->prev = plist->back;
        plist->back->next = pnew;
        plist->back = pnew;
    }
    plist->len++;
    return true;
}

bool ListRemoveItem(const ListItem *pi, List *plist)
{
    ListNode *temp;

    temp = listItemSeek(pi, plist);
    if (temp == NULL)
        return false;

    if (temp == plist->front)
    {
        plist->front = temp->next;
        plist->front->prev = NULL;
    }
    else if (temp == plist->back)
    {
        plist->back = temp->prev;
        plist->back->next = NULL;
    }
    else
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
    }
    free(temp);
    plist->len--;

    return true;
}

bool ListContainsItem(const ListItem *pi, const List *plist)
{
    return (listItemSeek(pi, plist) == NULL) ? false : true;
}

/* visit each node and execute function pointed to by pfun */
void ListTraverse(const List *plist, void (*pfun)(ListItem item))
{
    ListNode *pnode = plist->front; /* set to start of list */

    while (pnode != NULL)
    {
        (*pfun)(pnode->item); /* apply function to item */
        pnode = pnode->next;  /* advance to next item   */
    }
}

/* free memory allocated by calloc() */
/* set list pointer to NULL          */
void ListEmpty(List *plist)
{
    ListNode *psave;

    while (plist->front != NULL)
    {
        psave = plist->front->next; /* save address of next node */
        free(plist->front);         /* free current node         */
        plist->front = psave;       /* advance to next node      */
    }
    plist->back = NULL;
    plist->len = 0;
}

/* local function definition    */
/* copies an item into a node   */
static void copyToListNode(const ListItem *pi, ListNode *pnode)
{
    pnode->item = *pi; /* structure copy */
}

static bool itemsIsEqual(const ListItem *i1, const ListItem *i2)
{
    return (strcmp(i1->petkind, i2->petkind) == 0);
}

static ListNode *listItemSeek(const ListItem *pi, const List *plist)
{
    static ListNode *find = NULL;

    // Check if `find` already has an address of a list node from the previous
    // function call; if so compare item value of the node to pi
    if (find == NULL || !itemsIsEqual(pi, &find->item) )
    {
        find = plist->front;
        while (find != NULL && !itemsIsEqual(pi, &find->item))
            find = find->next;
    }
    return find;
}
