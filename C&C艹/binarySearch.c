#include <stdio.h>
#include <stdlib.h>

//二分查找

int binarySearch(int arr[], int left, int right, int x)
{
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2; //如果序列靠后 可以使用 mid = left +（right-left)/2 防止溢出
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1; //查找失败
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    binarySearch(arr, 0, 9, 4);
    system("pause");
    return 0;
}