#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct LNode
{
    int Key;
} List;

void BinInsert(List L[], int x, int n)
{
    int low = 1, high = n;
    int flag = 1;
    int mid, pos, i;
    while (low <= high && flag)
    {
        mid = (low + high) / 2;
        if (x < L[mid].Key)
        {
            high = mid - 1;
        }
        else if (x > L[mid].Key)
        {
            low = mid + 1;
        }
        else
        {
            flag = 0;
        }
    }
    if (!flag)
    {
        pos = mid;
    }
    else
    {
        //没有这元素
        pos = low;
    }
    for (i = n; i >= pos; i--)
    {
        L[i + 1].Key = L[i].Key;
    }
    L[pos].Key = x;
}

int main()
{
    int i, n = 10;
    List L[MAX];
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 10}; //缺9
    for (i = 0; i < n - 1; i++)
    {
        L[i].Key = arr[i];
    }
    BinInsert(L, 9, 9);
    for (i = 0; i < n; i++)
    {
        printf("%d", L[i].Key);
    }
    system("pause");
    return 0;
}