#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct LNode
{
    int Data[MAX];
    int Last;
} * List;

List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

int Search(List L, int x)
{
    int i = 0;
    while (i <= L->Last && L->Data[i] != x)
    {
        i++;
    }
    if (L->Last < i)
    {
        printf("没找到");
        return -1; //没找到
    }
    else
    {
        return i;
    }
}

int main()
{
    List list;
    list = MakeEmpty();
    int i;
    int n = 10;
    int arr[] = {3, 6, 2, 10, 1, 8, 5, 7, 4, 9};
    for (i = 0; i < n; i++)
    {
        list->Data[i] = arr[i];
        list->Last++;
    }
    int pos;
    pos = Search(list, 5);
    printf("所在位置%d\n", pos);
    system("pause");
    return 0;
}
