#include <stdio.h>
#include <stdlib.h>
//同时参考 move_zero.c

//如此的快速排序，使得在j左边的数字都比支点小，j到i中间的数字都比支点大
int partition(int arr[], int L, int R)
{
    int pivot = arr[R]; //拿一个支点，最后一个数字
    int i;
    int j = L;
    for (i = L; i < R; i++)
    {
        if (arr[i] < pivot)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;
        }
        else
        {
            continue; //相当于i++;
        }
    }
    //把支点移动到中间
    //这样把整个数组分成两段  左边比支点小 右边比支点大
    int temp = arr[j];
    arr[j] = arr[R];
    arr[R] = temp;
    return j; //返回中间支点的位置
}

void quick_sort(int arr[], int L, int R)
{
    if (L < R) //必须保证左端小于右端
    {
        int M = partition(arr, L, R); //拿到中间的下标
        quick_sort(arr, L, M - 1);
        quick_sort(arr, M + 1, R);
    }
}

int main()
{
    int arr[] = {1, 6, 3, 2, 9, 4, 2, 3, 4, 4, 7};
    quick_sort(arr, 0, 10);

    int i;
    for (i = 0; i < 11; i++)
    {
        printf("%d\n", arr[i]);
    }

    system("pause");
    return 0;
}