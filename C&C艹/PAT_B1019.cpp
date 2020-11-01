#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <algorithm>
using namespace std;

//数字黑洞
//戈丁一个各位数字不完全相同的四位正整数 ，把四个数字按非递增排序 ，再按非递减排序 然后 第一个减去第二个
//很快就会等于6174
//eg a = 6767   7766 - 6677 = 1098  9810 - 0189 = 9621
bool cmp(int a, int b)
{
    return a > b; //递减排序
}

void to_array(int n, int num[])
{
    //将n的每一位都存到num数组
    for (int i = 0; i < 4; i++)
    {
        num[i] = n % 10; //四位数 每一位存进去
        n /= 10;
    }
}

int to_number(int num[])
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum = sum * 10 + num[i];
    }
    return sum;
}
int main()
{
    //Min  Max 分别表示递增和递减后得到的最小值与最大值
    int n, Min, Max;
    scanf("%d", &n);
    int num[5];

    while (1)
    {
        to_array(n, num);
        sort(num, num + 4); //从小到大排序
        Min = to_number(num);
        sort(num, num + 4, cmp); //从大到小
        Max = to_number(num);
        n = Max - Min; //得到下一个数
        printf("%d - %d = %d\n", Max, Min, n);
        if (n == 0 || n == 6174)
        {
            break;
        }
    }
    system("pause");
    return 0;
}
