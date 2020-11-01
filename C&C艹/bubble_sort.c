#include <stdio.h>
#include <stdlib.h>
//1817443032李欣
//一趟排序  把最大的放后面
void bubble(int arr[], int n)
{
    int i;
    int temp;
    for (i = 0; i < n - 1; i++)
    {
        //每次拿i和i+1做比较，所以只需到i
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}

//每次对前面的冒泡
void bubble_sort(int arr[], int n)
{
    int i;
    for (i = n; i >= 1; i--)
    {
        bubble(arr, i);
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int i;
    bubble_sort(arr, 10);
    for (i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}