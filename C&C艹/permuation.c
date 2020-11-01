#include <stdio.h>
#include <stdlib.h>

//全排列函数
//对一个数组做全排列

void printarray(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", A[i]);
    }
    printf("\n");
}

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void pre_mua(int A[], int p, int q)
{ //传入上界和下届

    if (p == q)
    {
        //只有一个数做全排列
        printarray(A, q + 1); //有q+1个数字 因为q是下标 长度大一位
    }
    else
    {
        int i;
        for (i = p; i <= q; i++)
        {
            swap(A, p, i); //把下一个数提到前面来
            pre_mua(A, p + 1, q);
            swap(A, p, i); //需要还原，保证不会有重复交换
        }
    }
}

int main()
{
    int arr[4] = {1, 2, 3, 4};
    pre_mua(arr, 0, 3);
    system("pause");
    return 0;
}