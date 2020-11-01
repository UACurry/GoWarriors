#include <stdlib.h>
#include <stdio.h>
//归并排序
//两段已经有顺序的数组

void merge(int arr[], int L, int M, int R)
{
    int left_size = M - L;
    int right_size = R - M + 1;
    int left_arr[left_size];
    int right_arr[right_size];
    int i, j, k;

    //填进左边的数组
    for (i = L; i < M; i++)
    {
        left_arr[i - L] = arr[i]; //left下标从0开始
    }
    //右边数组
    for (i = M; i <= R; i++)
    {
        right_arr[i - M] = arr[i];
    }

    i = 0;
    j = 0;
    k = L;

    while (i < left_size && j < right_size)
    {
        if (left_arr[i] < right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
            k++;
        }
    }

    while (i < left_size)
    {
        arr[k] = left_arr[i];
        i++;
        j++;
    }

    while (j < right_size)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

//没有顺序的话，就先分治 递归分治，相当于不断递归，直到他left或者right分开只有一个

void merge_sort(int arr[], int L, int R)
{
    //递归到 两段分别都只有一个数字
    if (L == R)
    {
        return;
    }
    else
    {
        int M = (L + R) / 2;
        merge_sort(arr, L, M);
        merge_sort(arr, M + 1, R); //经过这样 两个大段已经排好序
        merge(arr, L, M + 1, R);   //此时要特别注意M的位置，保证M位置前后统一  和前面函数M意义一致
    }
}

int main()
{
    int arr[] = {1, 4, 5, 2, 9, 3, 9, 6};
    merge_sort(arr, 0, 7);
    int i;
    for (i = 0; i < 8; i++)
    {
        printf("%d", arr[i]);
    }
    system("pause");
    return 0;
}