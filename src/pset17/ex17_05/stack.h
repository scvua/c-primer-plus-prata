/* stack.h -- interface for a stack */
#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

/* INSERT ITEM TYPE HERE */
typedef char Item;

typedef struct frame
{
    Item item;
    struct frame * next;
} Frame;

typedef struct stack
{
    Frame * head;
    int items;
} Stack;

/* operation:       initialize the stack                        */
/* preconditions:   ps points to a stack                        */
/* postconditions:  the stack is initialized to being empty     */
void InitializeStack(Stack * ps);

/* operation:       determine if stack is empty                 */
/* preconditions:   ps points to an initialized stack           */
/* postconditions:  returns True if stack is empty, else False  */
bool StackIsEmpty(const Stack * ps);

/* operation:       determine is stack is full                  */
/* preconditions:   ps points to an initialized stack           */
/* postconditions:  returns True if stack is full, else False   */
bool StackIsFull(const Stack * ps);

/* operation:       determine number of items in stack          */
/* preconditions:   ps points to an initialized stack           */
/* postconditions:  returns number of items in stack            */
int StackItemCount(const Stack * ps);

/* operation:       add item onto the top of the stack          */
/* preconditions:   ps points to previously initialized stack   */
/*                  item is to be placed onto the top of stack  */
/* postconditions:  if possible, function adds item onto the    */
/*                  top of stack and returns True; otherwise    */
/*                  the function returns False                  */
bool PushItem(Item item, Stack * ps);

/* operation:       remove item from the top of the stack       */
/* preconditions:   ps points to previously initialized stack   */
/* postconditions:  if stack is not empty, item at top of stack */
/*                  is copied to *pitem and deleted from stack, */
/*                  and function returns True; if the operation */
/*                  empties the stack, the stack is reset to    */
/*                  empty.                                      */ 
/*                  If the stack is empty to begin with stack   */
/*                  is unchanged and the function retruns False */
bool PopItem(Item * pitem, Stack * ps);

/* operation:       empty the stack                             */
/* preconditions:   ps points to previously initialized stack   */
/* postconditions:  the stack is empty                          */
void EmptyTheStack(Stack * ps);

#endif  /* _STACK_H_  */
