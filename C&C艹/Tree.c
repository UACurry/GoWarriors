#include <stdlib.h>
#include <stdio.h>

#define MaxSize 10

typedef int Position;
typedef int ElementType;

typedef struct SNode
{
    ElementType Data;
    struct SNode *Next;
} * Stack;

typedef struct QNode
{
    //代表队列的结构
    struct Node *rear;
    struct Node *front;

} * Queue;



//1817443032李欣
typedef struct TreeNode
{
    ElementType Data;       //数据
    struct TreeNode *Left;  //二叉树的左儿子
    struct TreeNode *Right; //二叉树的右儿子
} BinTNode, *BinTree;

//创建一颗二叉树
CreateBiTree(BinTree T)
{
    int i;

    scanf("%d", &i);
    if (i == '#')
    {
        T = NULL;
    }
    else
    {
        T = (BinTNode *)malloc(sizeof(BinTNode));
        T->Data = i;
        CreateBiTree(T->Left);
        CreateBiTree(T->Right);
    }
}

void PreOrderTraversal(BinTree BT)
{ //先序遍历 1.先访问根结点，再先序左子树，再先序右子树
    if (BT)
    {                                 //树进来看一下树空还是不空
        printf("%d", BT->Data);       //先访问根结点
        PreOrderTraversal(BT->Left);  //对左子树进行递归
        PreOrderTraversal(BT->Right); //对右子树进行递归
    }
}

//1817443032李欣
void InOrderTraversal(BinTree BT)
{ //中序遍历
    if (BT)
    {                                 //树进来看一下树空还是不空
        MidOrderTraversal(BT->Left);  //对左子树进行递归
        printf("%d", BT->Data);       //先访问根结点
        MidOrderTraversal(BT->Right); //对右子树进行递归
    }
}

void PostOrderTraversal(BinTree BT)
{ //后序遍历
    if (BT)
    {                                  //树进来看一下树空还是不空
        PostOrderTraversal(BT->Left);  //对左子树进行递归
        PostOrderTraversal(BT->Right); //对右子树进行递归
        printf("%d", BT->Data);        //先访问根结点
    }
}
//1817443032李欣
void InOrderTraversal(BinTree BT) //中序遍历，非递归
//遇到一个结点把他压栈，然后一直遍历左子树，直到没有左子树
//左子树遍历完后，从栈顶弹出结点并访问它
//遍历右子树
{
    BinTree T = BT;
    Stack S = CreatStack(MaxSize); /*创建并初始化堆栈*/
    while (T || !IsEmpty(S))
    { //T树不空 或者堆栈S不空
        while (T)
        { /*一直向左并沿途结点压入堆栈*/
            /*先序printf("%d",T->Data);*/
            Push(S, T);
            T = T->Left; //一直往左边走
        }
        if (!IsEmpty(S))
        {               //循环结束后，堆栈取一个元素
            T = Pop(S); /*结点弹出*/
            printf("%d", T->Data);
            T = T->Right; //转向右子树，回到大循环
        }
    }
}

/*
void LevelOrderTraversal(BinTree BT)//层序遍历，通过用队列的方法，一层一层访问
{
    Queue Q;
    BinTree T;
    if(!BT)
    return; //空树直接返回
    Q = CreatQueue(MaxSize);//创建并初始化队列Q
    AddQueue(Q,BT);//把根结点放到队列里面去
    while(!IsEmpty(Q)){
        T =  DeleteQ(Q);//第一件事情，从队列里面抛出一个元素
        printf("%d",T->Data);//显示抛出的Data
        if(T->Left)//把抛出元素的左右儿子放进去
        AddQueue(Q,T->Left)
        if(T->Right)
        AddQueue(Q,T->Right);
        
    }
}
*/

//求树的叶结点，在先序遍历前加个判断，左右子树都为空了if判断。则输出结点数据

//求二叉树高度，递归左子树和右子树，return 子树高的+1 = 树高

//二叉搜索树   左子树所有结点值都比根节点小，右子树所有结点值都比根节点大

BinTree Find(ElementType X, BinTree BST) //循环做
{
    while (BST)
    {
        if (X > BST->Data)
            BST = BST->Right; //数据大，在右子树中查找
        else if (X < BST->Data)
            BST = BST->Left;
        else //X==Bst->Data
            return (BST);
    }
    return 0;
}

BinTree FindMin(BinTree BST) //最小值一定在左子树
{
    if (!BST)
        return 0;        /*空二叉树*/
    else if (!BST->Left) /*左边已经空了，已经是最小值了*/
        return BST;
    else
        return FindMin(BST->Left); /*递归*/
}

BinTree FinMax(BinTree BST)
{
    if (BST)
        while (BST->Right)
            BST = BST->Right;
    return BST;
}

BinTree Insert(ElementType X, BinTree BST)
{
    if (!BST)
    {
        /*若原树为空，生成并返回一个结点的二叉搜索树*/
        BST = (BinTree)malloc(sizeof(struct TreeNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else
    { //开始找要插入元素的位置
        if (X < BST->Data)
            BST->Left = Insert(X, BST->Left); /*递归插入子树*/
        else if (X > BST->Data)
            BST->Right = Insert(X, BST->Right); //递归右子树
    }
    return BST;
}

BinTree Delete(ElementType X, BinTree BST)
{
    BinTree Tmp;
    if (!BST)
        printf("要删除的元素未找到"); //树是空的
    else if (X < BST->Data)
    {
        BST->Left = Delete(X, BST->Left);
    } //左子树递归删除
    else if (X > BST->Data)
        BST->Right = Delete(X, BST->Right);
    else
    { /*找到要删除的结点*/
        if (BST->Left && BST->Right)
        {
            /*被删除结点有左右两个子节点*/
            //1用右子树的最小值替代
            //2用左子树的最大值替代
            Tmp = FindMin(BST->Right);                  /*在右子树中找到最小的元素填充删除结点*/
            BST->Data = Tmp->Data;                      //右子树里的最小值覆盖掉想删除的元素
            BST->Right = Delete(BST->Data, BST->Right); /*右指数结点删掉*/
        }
        else
        {
            /*只有一个或无子节点*/
            Tmp = BST;
            if (!BST->Left) /*有右节点*/
                BST = BST->Right;
            else if (!BST->Right) //有左孩子
                BST = BST->Left;
            free(Tmp);
        }
    }
    return BST;
}