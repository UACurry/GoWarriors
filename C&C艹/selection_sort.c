#include <stdio.h>
#include <stdlib.h>
//选择排序

//先找到当前数组的最大值
//把最大的和最后一位交换
//再把前 n -1 找一个最大的 和 前n-1的最后一个交换
//1817443032李欣
int FindMaxIndex(int arr[], int n)
{
    int max = arr[0];
    int position = 0;
    int i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            position = i;
        }
    }
    return position;
}

void selection_sort(int arr[], int n)
{
    while (n > 1)
    {
        int position = FindMaxIndex(arr, n);
        int temp = arr[position];
        arr[position] = arr[n - 1]; //最大值和最后一个做交换
        arr[n - 1] = temp;
        n--; //最大已经在最后面了
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    selection_sort(arr, 10);

    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}