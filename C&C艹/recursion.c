#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//递归练习题
void move_p(int **p, int arr[])
{
    (*p) = &arr[1];
}

int findmax(int arr[], int n)
{
    int max;
    max = arr[1];
    int i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int re_findmax(int arr[], int L, int R)
{
    int max;
    if (L == R)
    {
        return arr[L];
    }
    else
    {
        int a = arr[L];
        int b = re_findmax(arr, L + 1, R);
        if (a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
}

//第二题
//求所有数字加起来多少
int sum_numbers(int arr[], int L, int R)
{
    int sum = 0;
    if (L == R)
    {
        //出口
        sum = arr[L];
        return sum;
    }
    else
    {
        sum = arr[L] + sum_numbers(arr, L + 1, R);
        return sum;
    }
}

//第三题
//冒泡排序
//一趟冒泡 可以把最大的数字放到最后  则把前面的东西在做冒泡
void bubble_sort(int arr[], int L, int R)
{
    if (L < R)
    {
        int i;
        //只需要到R-1
        //一趟冒泡
        for (i = L; i <= R - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        bubble_sort(arr, L, R - 1);
    }
}

//第四题
//辗转相除法 求最大公约数
/** a   b          r
 * 72 / 56 = 1.....16
 * 56 / 16 = 3.....8
 * 16 / 8 =  2.....0
 *  那么我们就发现 r = 0  b 就是最大公约数  这也是递归出口
 * 
**/
int gcd(int a, int b)
{
    int r = a % b; //余数
    if (r == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, r);
    }
}

int main()
{
    int arr[] = {1, 6, 3, 4, 5};
    int sum;
    bubble_sort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }
    system("pause");
    return 0;
}

