/* tree.c -- tree support functions */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* local data type */
typedef struct pair {
    Trnode *parent;
    Trnode *child;
} Pair;

/* prototype for local functions */
static Trnode *makeNode(const Item *pi);
static bool toLeft(const Item *i1, const Item *i2);
static bool toRight(const Item *i1, const Item *i2);
static void addNode(Trnode *new_node, Trnode *root);
static void inOrder(const Trnode *root, void (*pfun)(Item item));
static Pair seekItem(const Item *pi, const Tree *ptree);
static void deleteNode(Trnode **ptr);
static void deleteAllNodes(Trnode *ptr);

/* function definitions */
void InitializeTree(Tree *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
    if (ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree *ptree)
{
    if (ptree->size >= MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree *ptree)
{
    return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree)
{
    Trnode * new_node;

    if (TreeIsFull(ptree)) 
    {
        fprintf(stderr, "Tree is full\n");
        return false;                   /* early return             */  //-->
    }
    if (seekItem(pi, ptree).child != NULL)
    {
        fprintf(stderr, "Attempted to add duplicate item\n");
        return false;                   /* early return             */  //-->
    }
    new_node = makeNode(pi);            /* points to new node       */
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;                   /* early return             */  //-->
    }
    /* succeeded in creating a new node */
    ptree->size++;

    if (ptree->root == NULL)            /* case 1: tree is empty    */
        ptree->root = new_node;         /* new node is tree root    */
    else                                /* case 2: not empty        */
        addNode(new_node, ptree->root); /* add node to tree         */

    return true;                        /* successful return        */
}

bool InTree(const Item *pi, const Tree *ptree)
{
    return (seekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
    Pair look;

    look = seekItem(pi, ptree);
    if (look.child == NULL)
        return false;

    if (look.parent == NULL)            /* delete root item         */
        deleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        deleteNode(&look.parent->left);
    else
        deleteNode(&look.parent->right);
    ptree->size--;

    return true;
}

void Traverse(const Tree *ptree, void (*pfun)(Item item))
{
    if (ptree != NULL)
        inOrder(ptree->root, pfun);
}

void DeleteAll(Tree *ptree)
{
    if (ptree != NULL)
        deleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

/* local functions */
static void inOrder(const Trnode *root, void (*pfun)(Item item))
{
    if (root != NULL)
    {
        inOrder(root->left, pfun);
        (*pfun)(root->item);
        inOrder(root->right, pfun);
    }
}

static void deleteAllNodes(Trnode *root)
{
    Trnode *pright;

    if (root != NULL)
    {
        pright = root->right;
        deleteAllNodes(root->left);
        free(root);
        deleteAllNodes(pright);
    }
}

static void addNode(Trnode *new_node, Trnode *root)
{
    if (toLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)         /* empty subtree            */
            root->left = new_node;      /* so add node here         */
        else
            addNode(new_node, root->left);  /* else process subtree */
    }
    else if (toRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            addNode(new_node, root->right);
    }
    else                            /* should be no duplicates      */
    {
        fprintf(stderr, "location error in addNode()\n");
        exit(EXIT_FAILURE);
    }
}

static bool toLeft(const Item *i1, const Item *i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
        return true;
    else if (comp1 == 0 &&
            strcmp(i1->petkind, i2->petkind) < 0)
        return true;
    else
        return false;
}

static bool toRight(const Item *i1, const Item *i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
        return true;
    else if (comp1 == 0 &&
            strcmp(i1->petkind, i2->petkind) > 0)
        return true;
    else
        return false;
}

static Trnode *makeNode(const Item *pi)
{
    Trnode *new_node;

    new_node = (Trnode *) calloc(1, sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static Pair seekItem(const Item *pi, const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look;                    /* early return             */  //-->

    while (look.child != NULL)
    {
        if (toLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (toRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else        /* must be same if not to left or right         */
            break;  /* look.child is address of node with item      */
    }
    return look;                        /* successful return        */
}

static void deleteNode(Trnode **ptr)
/* ptr is address of parent member pointing to target node          */
{
    Trnode *temp;

    if ( (*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ( (*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else            /* deleted node has two children                */
    {
        /* find where to reattach right subtree */
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

