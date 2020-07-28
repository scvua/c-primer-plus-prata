/* list.h -- header file for a simple list type */
#ifndef _LIST_H_
#define _LIST_H_
#include <stdbool.h>    /* C99 feature          */

/* program-specific declarations */

#define SLEN   20  /* Size of ListItem strings */
typedef struct listItem
{
    char petkind[SLEN];
} ListItem;

/* general type definitions     */

typedef struct listNode
{
    ListItem item;
    struct listNode *next;
    struct listNode *prev;
} ListNode;

typedef struct list
{
    ListNode *front;
    ListNode *back;
    unsigned int len;
} List;

/* function prototypes  */

/* operation:       initialize a list                           */
/* preconditions:   plist points to a list                      */
/* postconditions:  the list is initialized to empty            */
void ListInit(List *plist);

/* operation:       determine if list is empty                  */
/* preconditions:   plist points to an initialized list         */
/* postconditions:  function returns True if list is empty      */
/*                  and returns False otherwise                 */
bool ListIsEmpty(const List *plist);

/* operation:       determine if list is full                   */
/* preconditions:   plist points to an initialized list         */
/* postconditions:  function returns True if list is full       */
/*                  and returns False otherwise                 */
bool ListIsFull(const List *plist);

/* operation:       determine number of items in list           */
/* preconditions:   plist points to an initialized list         */
/* postconditions:  function returns number of items in list    */
unsigned int ListItemCount(const List *plist);

/* operation:       add item to end of list                     */
/* preconditions:   pi points an item to be added to list       */
/*                  plist points to an initialized list         */
/* postconditions:  if possible, function adds item to end      */
/*                  of list and returns True; otherwise the     */
/*                  function returns False                      */
bool ListAddItem(const ListItem *pi, List *plist);

/* operation:       remove item from the list                   */
/* preconditions:   pi points to an item to be removed from list*/
/*                  plist points to an initialized list         */
/* postconditions:  if list is not empty, function searches the */
/*                  list for item and, if the item is in list,  */
/*                  deletes it and returns True; otherwise the  */
/*                  function returns False                      */
bool ListRemoveItem(const ListItem *pi, List *plist);

/* operation:       find an item in list                        */
/* preconditions:   pi points to an item                        */
/*                  plist points to an initialized list         */
/* postconditions:  function returns True if item is in         */
/*                  list and returns False otherwise            */
bool ListContainsItem(const ListItem *pi, const List *plist);

/* operation:       apply a function to each item in list       */
/* preconditions:   plist points to an initialized list         */
/*                  pfun points to a function that takes an     */
/*                  Item argument and has no return value       */
/* postconditions:  the function pointed to by pfun is          */
/*                  executed once for each item in the list     */
void ListTraverse(const List *plist, void (*pfun)(ListItem item));

/* operation:       free allocated memory, if any               */
/* preconditions:   plist points to an initialized list         */
/* postconditions:  any memory allocated for the list is freed  */
/*                  and the list is set to empty                */
void ListEmpty(List *plist);

#endif  /* _LIST_H_ */
