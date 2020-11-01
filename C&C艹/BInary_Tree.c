#include <stdlib.h>
#include <stdio.h>

#define MaxSize 10

typedef int Position;
typedef char ElementType;

typedef struct TreeNode
{
    ElementType Data;       //数据
    struct TreeNode *Left;  //二叉树的左儿子
    struct TreeNode *Right; //二叉树的右儿子
} BinTNode, *BinTree;

//创建一颗二叉树
BinTree CreateBiTree(BinTree BT)
{
    char i;

    scanf("%c", &i);
    if (i == '#')
    {
        BT = NULL;
    }
    else
    {
        BT = (BinTNode *)malloc(sizeof(BinTNode));
        BT->Data = i;
        BT->Left = CreateBiTree(BT->Left);
        BT->Right = CreateBiTree(BT->Right);
    }

    return BT;
}

void visit(char i, int level)
{

    printf("%c位于%d层\n", i, level);
}

void PreOrderTraversal(BinTree BT, int level)
{ //先序遍历 1.先访问根结点，再先序左子树，再先序右子树
    if (BT)
    { //树进来看一下树空还是不空

        visit(BT->Data, level);
        //printf("%d",BT->Data);//先访问根结点
        PreOrderTraversal(BT->Left, level + 1);  //对左子树进行递归
        PreOrderTraversal(BT->Right, level + 1); //对右子树进行递归
    }
}
void InOrderTraversal(BinTree BT, int level)
{ //先序遍历 1.先访问根结点，再先序左子树，再先序右子树
    if (BT)
    { //树进来看一下树空还是不空

        //printf("%d",BT->Data);//先访问根结点
        InOrderTraversal(BT->Left, level + 1); //对左子树进行递归
        visit(BT->Data, level);
        InOrderTraversal(BT->Right, level + 1); //对右子树进行递归
    }
}

void LastOrderTraversal(BinTree BT, int level)
{ //先序遍历 1.先访问根结点，再先序左子树，再先序右子树
    if (BT)
    { //树进来看一下树空还是不空

        //printf("%d",BT->Data);//先访问根结点
        LastOrderTraversal(BT->Left, level + 1);  //对左子树进行递归
        LastOrderTraversal(BT->Right, level + 1); //对右子树进行递归
        visit(BT->Data, level);
    }
}

//叶子结点的个数
//1817443032李欣
int leaves_number(BinTree BT)
{
    int number;
    if (BT == NULL)
    {
        number = 0;
    }
    else if (BT->Left == NULL && BT->Right == NULL)
    {
        number = 1;
    }
    else
    {
        number = leaves_number(BT->Left) + leaves_number(BT->Right);
    }
    return number;
}

//输出子孙结点
//1817443032李欣
void print(BinTree node)
{
    if (node != NULL)
    {
        printf("%c", node->Data);
        print(node->Left);
        print(node->Right);
    }
}

void son_and_son(BinTree BT, char X)
{
    if (BT != NULL)
    {
        if (BT->Data == X)
        {
            if (BT->Left != NULL)
            {
                //all_left_son
                print(BT->Left);
            }
            if (BT->Right != NULL)
            {
                print(BT->Right);
            }
            return;
        }
    }
}

int main()
{
    //int level = 1;
    BinTree BT = NULL;
    BT = CreateBiTree(BT);
    //InOrderTraversal(BT,level);
    int number = 0;
    number = leaves_number(BT);
    printf("%d\n", number);
    son_and_son(BT, 'D');
    system("pause");
    return 0;
}
