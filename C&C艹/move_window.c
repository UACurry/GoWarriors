#include <stdio.h>
#include <stdlib.h>

//滑动窗口
int main()
{
    int arr[9] = {1, 1, 1, 9, 9, 1, 1, 1, 1};
    int k = 4;
    int sum[9]; // 求出来的 和数组  长度 = 数组长度
    int len[9]; //滑窗长度

    int loclen = 0;     //记录当前滑窗长度
    int locsum = 0;     //记录当前滑窗求和
    int startindex = 0; //记录滑窗起始位置

    for (int i = 0; i < 9; i++)
    {
        locsum = locsum + arr[i];
        if (locsum > k)
        {
            locsum = locsum - arr[startindex]; //把滑动窗口第一个数字减去
            startindex++;                      //窗口往前移动
            sum[i] = locsum;
            len[i] = loclen; //此时因为窗口减了一个 所以长度不变
        }
        else
        {
            sum[i] = locsum;
            loclen = loclen + 1;
            len[i] = loclen;
        }
    }

    printf("sum= ");
    for (int i = 0; i < 9; i++)
    {
        printf(" %d ", sum[i]);
    }

    printf("\nlen= ");
    for (int i = 0; i < 9; i++)
    {
        printf(" %d ", len[i]);
    }

    system("pause");
    return 0;
}