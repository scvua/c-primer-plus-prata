/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* local function prototype */
static void copyToListNode(ListItem item, ListNode *pnode);

/* interface functions      */

/* set the list to empty    */
void ListInit(List *plist)
{
    *plist = NULL;
}

/* returns true if list is empty */
bool ListIsEmpty(const List *plist)
{
    if (*plist == NULL)
        return true;
    else
        return false;
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
    unsigned int count = 0;
    ListNode *pnode = *plist;   /* set to start of list */

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;    /* set to next node     */
    }
    return count;
}

/* creates node to hold item and adds it to the end of  */
/* the list pointed to by plist (slow implementation)   */
bool ListAddItem(ListItem item, List *plist)
{
    ListNode *pnew;
    ListNode *scan = *plist;

    pnew = (ListNode *) calloc(1, sizeof(ListNode));
    if (pnew == NULL)
        return false;   /* quit function on failure     */              //-->

    copyToListNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL)       /* empty list so place      */
        *plist = pnew;      /* pnew at head of list     */
    else
    {
        while (scan->next != NULL)
            scan = scan->next;  /* find end of list     */
        scan->next = pnew;      /* add pnew to end      */
    }
    return true;
}

/* visit each node and execute function pointed to by pfun */
void ListTraverse(const List *plist, void (*pfun)(ListItem item))
{
    ListNode *pnode = *plist;   /* set to start of list */

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

    while (*plist != NULL)
    {
        psave = (*plist)->next; /* save address of next node */
        free(*plist);           /* free current node         */
        *plist = psave;         /* advance to next node      */
    }
}

/* local function definition    */
/* copies an item into a node   */
static void copyToListNode(ListItem item, ListNode *pnode)
{
    pnode->item = item; /* structure copy */
}

