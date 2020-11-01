#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct LNode
{
    int Key;
} List;

int Search(List L[], int k, int i, int n)
{
    if (i >= n)
    {
        return -1;
    }
    else if (L[i].Key == k)
    {
        return i;
    }
    else
    {
        Search(L, k, i + 1, n);
    }
}
