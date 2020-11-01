//灯神的
//合并两个有顺序的数组

#include <stdio.h>
#include <stdlib.h>

void merge(int num1[], int m, int num2[], int n)
{
    //m和 n代表数组长度
    int arr[] = (int *)malloc(sizeof(int) * (m + n));
    int i = 0; //指向num1
    int j = 0; //num2
    int k = 0; //指向arr
    while (i < m && j < n)
    {
        if (num1[i] < num2[j])
        {
            arr[k] = num1[i];
            i++;
        }
        else
        {
            arr[k] = num2[j];
        }
        k++;
    }
    //跳出循环 代表有一个数组完了
    while (i < m)
    {
        arr[k] = num1[i];
        i++;
        k++;
    }
    while (j < n)
    {
        arr[k] = num2[j];
        j++;
        k++;
    }
    //把arr放进num1
    for (i = 0; i < k; i++)
    {
        num1[i] = arr[i];
    }
}

void printArray()