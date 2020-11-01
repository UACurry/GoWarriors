#include <stdio.h>
#include <stdlib.h>

// 给若干个数字  0 -9 任意排列且全部使用
//使得目标最小 且0不能做首位
//每一行给出十个非负整数
//顺序表示 0 ， 1 ，2 ，3 .。。。的个数

int main()
{
    int count[10]; //记录 0 -9 的个数
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &count[i]);
    }
    for (int i = 1; i < 10; i++)
    {
        //从1 -9 选择 count 不为0的最小数字
        if (count[i] > 0)
        {
            printf("%d", i);
            count[i]--;
            break; //找到一个就退出 这是作为首位的
        }
    }
    for (int i = 0; i < 10; i++)
    {
        //从 0 -9 输出对应个数的数字
        //j 则表示数  count[i]有多少个
        for (int j = 0; j < count[i]; j++)
        {
            printf("%d", i);
        }
    }
    system("pause");
    return 0;
}