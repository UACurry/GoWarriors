#include <stdio.h>
#include <stdlib.h>
//1817443032李欣
void Binary_Insert(int arr[], int n)
{
    int i, j;

    for (i = 1; i < n; i++)
    {
        int low = 0;
        int high = i - 1; //已经有序的最后一位
        int temp = arr[i];

        while (high >= low)
        {
            int mid = (low + high) / 2;
            if (arr[mid] > temp)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        } //循环结束 就找到插入位置了
        //插入 到 high +1 的位置
        //从有序的最后一位开始 往后移动
        for (j = i - 1; j > high; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[high + 1] = temp;
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
    Binary_Insert(arr, 10);
    printf("排序后:");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}