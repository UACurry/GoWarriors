//希尔排序
#include <stdio.h>
#include <stdlib.h>
//1817443032李欣

void shell_sort(int arr[], int n)
{
    int i, j;
    int space; //表示间隔
    //第一步 分组
    for (space = n / 2; space > 0; space /= 2)
    {
        //组内排序
        for (i = 0; i < space; i++)
        {
            for (j = i + space; j < n; j += space)
            {
                if (arr[j] < arr[j - space])
                {
                    int temp = arr[j];
                    int k = j - space;
                    while (k >= 0 && arr[k] > temp)
                    {
                        arr[k + space] = arr[k]; //交换
                        k -= space;
                    }
                    arr[k + space] = temp;
                }
            }
        }
        for (i = 0; i < 10; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    int i;
    int n = 10;
    shell_sort(arr, 10);

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}