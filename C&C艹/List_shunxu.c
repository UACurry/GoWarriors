#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int ElementType;
typedef struct LNode
{
    int Last;
    ElementType Data[MAXSIZE];
} L, *List;

List MakeEmpty()
{
    //初始化
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}

int Find(ElementType X, List PtrL)
{
    int i = 0;
    while (i <= PtrL->Last && PtrL->Data[i] != X)
    {
        i++;
    }
    if (i > PtrL->Last)
        return 0;
    else
        return i;
}

void Insert(ElementType X, int i, List PtrL) //插入到第i个位置，即插入到下标为i-1个元素的地方
{
    int j;
    if (PtrL->Last == MAXSIZE - 1)
    {
        //表空间已经满了，不能插入
        printf("表满");
        return;
    }

    if (i < 1 || i > PtrL->Last + 2)
    {
        //检查插入位置的合法性
        printf("位置不合法");
        return;
    }

    for (j = PtrL->Last; j >= i - 1; j--)
    {
        PtrL->Data[j + 1] = PtrL->Data[j];
    }
    PtrL->Data[i - 1] = X;
    PtrL->Last++; //Last仍然指向最后的元素
    return;
}

void Delete(int i, List PtrL) //删除第i个元素，即删除下标为i-1的元素
{
    int j;
    if (i < 1 || i > PtrL->Last + 1)
    {
        //检查空表及删除位置的合法性
        printf("不存在第%d个元素", i);
        return;
    }

    for (j = i; j <= PtrL->Last; j++)
    {
        PtrL->Data[j - 1] = PtrL->Data[j];
    }
    PtrL->Last--; //Last 仍指向最后的元素
    return;
}

int main()
{
    List PtrL;

    PtrL = MakeEmpty();

    Insert(1, 1, PtrL);
    int i;
    for (i = 0; i <= PtrL->Last; i++)
    {
        printf("%d", PtrL->Data[i]);
    }

    system("pause");
    return 0;
}