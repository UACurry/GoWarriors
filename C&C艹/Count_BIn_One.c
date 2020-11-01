//数一下一个二进制数里面有多少个1，最后返回1的个数
#include <stdio.h>
#include <stdlib.h>

//num表示一个十进制数
int countones(int num)
{
    int count = 0;
    while (num > 0)
    {
        if ((num & 1) == 1)
        {
            count++;
        }
        num = (num >> 1);
    }
    return count;
}

//更快的
int CountOnes2(int num)
{
    //定义过滤器
    int m_1 = 0x55555555;
    int m_2 = 0x33333333;
    int m_4 = 0x0F0F0F0F;
    int m_8 = 0x00FF00FF;
    int m_16 = 0x0000FFFF;

    int b = (num & m_1) + ((num >> 1) & m_1);
    int c = (b & m_2) + ((b >> 2) & m_2);
    int d = (c & m_4) + ((c >> 4) & m_4);
    int e = (d & m_8) + ((d >> 8) & m_8);
    int f = (e & m_16) + ((e >> 16) & m_16);

    return f;
}

int main()
{
    int count;
    count = CountOnes2(24);
    printf("%d\n", count);
    system("pause");
    return 0;
}