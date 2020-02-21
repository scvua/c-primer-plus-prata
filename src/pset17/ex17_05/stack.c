/* stack.c -- the Stack type implementation */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* local functions  */
static void CopyToFrame(Frame * pf, Item item);
static void CopyToItem(Item * pi, Frame * pf);

void InitializeStack(Stack * ps)
{
    ps->head = NULL;
    ps->items = 0;
}

bool StackIsEmpty(const Stack * ps)
{
    return (ps->head == NULL);
}

bool StackIsFull(const Stack * ps)
{
    Frame * tmp;
    bool full;

    tmp = (Frame *) calloc(1, sizeof(Frame));
    if (tmp == NULL)
        full = true;
    else
        full = false;
    free(tmp);
    return full;
}

int StackItemCount(const Stack * ps)
{
    return ps->items;
}

bool PushItem(Item item, Stack * ps)
{
    Frame * new_frame;

    if (StackIsFull(ps))
    {
        puts("Stack is full");
        return false;           /* early return             */  //-->
    }
    
    new_frame = (Frame *) calloc(1, sizeof(Frame));
    if (new_frame == NULL)
    {
        fprintf(stderr, "Memory allocation problem\n");
        return false;           /* early return             */  //-->
    }
    CopyToFrame(new_frame, item);

    if (ps->head == NULL)       /* case 1: stack is empty   */
        new_frame->next = NULL; /* new frame is stack head  */
    else                        /* case 2: not empty        */
        new_frame->next = ps->head; /* add frame to stack   */
    ps->head = new_frame;
    ps->items++;    

    return true;
}

bool PopItem(Item * pitem, Stack * ps)
{
    Frame * pt = ps->head;

    if (ps->head == NULL)
        return false;           /* early return             */  //-->
    CopyToItem(pitem, ps->head);
    ps->head = ps->head->next;
    free(pt);
    ps->items--;

    return true;
}

void EmptyTheStack(Stack * ps)
{
    Item temp;

    while (!StackIsEmpty(ps))
        PopItem(&temp, ps);
}

/* Local functions      */

static void CopyToFrame(Frame * pf, Item item)
{
    pf->item = item;
}

static void CopyToItem(Item * pi, Frame * pf)
{
    *pi = pf->item;
}
