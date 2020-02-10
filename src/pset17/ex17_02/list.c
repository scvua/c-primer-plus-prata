/*
 *  ex17_02: modification of 
 *  list.c -- functions supporting list operations 
 *  for the following definition of a list:
 *      
 *      typedef struct list 
 *      {
 *          Node * head;
 *          Node * end;
 *      } List;
 *
 *  Created by grescher on 02/10/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* local function prototype */
static void CopyToNode(Item item, Node * pnode);

/* interface function    */
/* set the list to empty */
void InitializeList(List * plist)
{
    plist->head = NULL;
    plist->end = NULL;
}

/* returns true if list is empty    */
bool ListIsEmpty(const List * plist)
{
    return (plist->head == NULL);
}

/* returns true if list is full     */
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;

    pt = (Node *) calloc(1, sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}

/* returns number of nodes  */
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = plist->head;     /* set to start of list */

    while (pnode != NULL)
    {
        count++;
        pnode = pnode->next;    /* set to next node     */
    }

    return count;
}

/* creates node to hold item and adds it to the end of  */
/* the list pointed to by plist (slow implementation)   */
bool AddItem(Item item, List * plist)
{
    Node * pnew;

    pnew = (Node *) calloc(1, sizeof(Node));
    if (pnew == NULL)
        return false;       /* quit function on failure */  //-->

    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (plist->head == NULL)    /* empty list so place  */
    {                           /* pnew at head of list */
        plist->head = pnew;
        plist->end = pnew;
    }
    else
    {
        plist->end->next = pnew;
        plist->end = pnew;   /* add pnew to end of list */
    }
    return true;
}

/* visit each node and execute function pointed to by pfun  */
void Traverse(const List * plist, void (* pfun)(Item item))
{
    Node * pnode = plist->head; /* set to start of list */

    while (pnode != NULL)
    {
        (*pfun)(pnode->item); /* apply function to item */
        pnode = pnode->next;  /* advance to next item   */
    }
}

/* free memory allocated by calloc() */
/* set list pointer to NULL          */
void EmptyTheList(List * plist)
{
    Node * psave;

    while (plist->head != NULL)
    {
        psave = plist->head->next; /* save address of next node */
        free(plist->head);         /* free current node         */
        plist->head = psave;       /* advance to next node      */
    }
}

/* local function definition  */
/* copies an item into a node */
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;     /* structure copy   */
}

