/* tree.c -- tree support functions */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "tree.h"

/* local data type */
typedef struct pair {
    TreeNode *parent;
    TreeNode *child;
} Pair;

/* prototype for local functions */
static TreeNode *makeNode(const TreeItem *pi);
static bool toLeft(const TreeItem *i1, const TreeItem *i2);
static bool toRight(const TreeItem *i1, const TreeItem *i2);
static void addNode(TreeNode *new_node, TreeNode *root);
static void inOrder(const TreeNode *root, void (*pfun)(TreeItem item));
static Pair seekItem(const TreeItem *pi, const Tree *ptree);
static void deleteNode(TreeNode **ptr);
static void deleteAllNodes(TreeNode *ptr);

/* function definitions */
void TreeInit(Tree *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
    return (ptree->root == NULL);
}

bool TreeIsFull(const Tree *ptree)
{
    return (ptree->size >= MAXITEMS);
}

int TreeItemCount(const Tree *ptree)
{
    return ptree->size;
}

bool TreeAddItem(const TreeItem *pi, Tree *ptree)
{
    TreeNode * new_node;

    if (TreeIsFull(ptree)) 
    {
        fprintf(stderr, "Tree is full\n");
        return false;                   /* early return             */  //-->
    }
    if (InTree(pi, ptree))
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

bool InTree(const TreeItem *pi, const Tree *ptree)
{
    return (seekItem(pi, ptree).child == NULL) ? false : true;
}

TreeItem *TreeItemSearch(const TreeItem *pi, const Tree *ptree)
{
    return &seekItem(pi, ptree).child->item;
}

bool TreeDeleteItem(const TreeItem *pi, Tree *ptree)
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

void TreeTraverse(const Tree *ptree, void (*pfun)(TreeItem item))
{
    if (ptree != NULL)
        inOrder(ptree->root, pfun);
}

void TreeEmpty(Tree *ptree)
{
    if (ptree != NULL)
        deleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

/* local functions */
static void inOrder(const TreeNode *root, void (*pfun)(TreeItem item))
{
    if (root != NULL)
    {
        inOrder(root->left, pfun);
        (*pfun)(root->item);
        inOrder(root->right, pfun);
    }
}

static void deleteAllNodes(TreeNode *root)
{
    TreeNode *pright;

    if (root != NULL)
    {
        pright = root->right;
        deleteAllNodes(root->left);
        ListEmpty(&root->item.petkind);
        free(root);
        deleteAllNodes(pright);
    }
}

static void addNode(TreeNode *new_node, TreeNode *root)
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

static bool toLeft(const TreeItem *i1, const TreeItem *i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
        return true;
//    else if (comp1 == 0 &&
//            strcmp(i1->petkind, i2->petkind) < 0)
//        return true;
    else
        return false;
}

static bool toRight(const TreeItem *i1, const TreeItem *i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
        return true;
//    else if (comp1 == 0 &&
//            strcmp(i1->petkind, i2->petkind) > 0)
//        return true;
    else
        return false;
}

static TreeNode *makeNode(const TreeItem *pi)
{
    TreeNode *new_node;

    new_node = (TreeNode *) calloc(1, sizeof(TreeNode));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        ListInit(&new_node->item.petkind);
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static Pair seekItem(const TreeItem *pi, const Tree *ptree)
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

static void deleteNode(TreeNode **ptr)
/* ptr is address of parent member pointing to target node          */
{
    TreeNode *temp;

    if ( (*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        ListEmpty(&temp->item.petkind);
        free(temp);
    }
    else if ( (*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        ListEmpty(&temp->item.petkind);
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
        ListEmpty(&temp->item.petkind);
        free(temp);
    }
}

