//交换两颗子树
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *LChild;
    struct node *RChild;
} BTNode, *BinTree;

BinTree CreateTree(BTNode *BT)
{
    char i;

    scanf("%c", &i);
    if (i == "#")
    {
        BT = NULL;
    }
    else
    {
        BT = (BTNode *)malloc(sizeof(BTNode));
        BT->data = i;
        BT->LChild = CreateTree(BT->LChild);
        BT->RChild = CreateTree(BT->RChild);
    }
    return BT;
}

int leaves_number(BTNode *BT)
{
    int number;
    if (BT == NULL)
    {
        number = 0;
    }
    else if (BT->LChild == NULL && BT->RChild == NULL)
    {
        number = 1;
    }
    else
    {
        number = leaves_number(BT->LChild) + leaves_number(BT->RChild);
    }
    return number;
}

BinTree exchange_tree(BTNode *BT)
{
    BTNode *p;
    if (BT->LChild != NULL || BT->RChild != NULL)
    {
        p = BT->LChild;
        BT->LChild = BT->RChild;
        BT->RChild = p;
        BT->LChild = exchange_tree(BT->LChild);
        BT->RChild = exchange_tree(BT->RChild);
    }
    else
    {
        return 0;
    }
    return BT;
}