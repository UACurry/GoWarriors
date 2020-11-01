#include <stdio.h>
#include <stdlib.h>
//分成两段 已经排好顺序的  和 乱序的
//1817443032李欣
//把第n个数字插到前面
void insert(int arr[], int n)
{
    int key = arr[n];
    int i = n;
    while (arr[i - 1] > key)
    {
        arr[i] = arr[i - 1]; //把key前面较大的数字抄到i位置
        i--;
        if (i == 0)
        {
            break; //防止前面出界
        }
    }
    arr[i] = key; //把key放到该放的位置
}

void insert_sort(int arr[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    { //只有一个数字那么本身就是排好序的，所以从下标1开始
        insert(arr, i);
        printf("第%d次", i);
        for (j = 0; j < n; j++)
        {
            printf("%d", arr[j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printf("排序前:");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    insert_sort(arr, 10);
    printf("排序后:");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}