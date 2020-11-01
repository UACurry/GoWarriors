//与运算操作 将[a,b] 即a到b的每一个数字做与运算 得到最后的结果
#include <stdio.h>
#include <stdlib.h>

//这样的效率很低很低
int rangebitwiseAnd(int m, int n)
{
    int result = m;
    int i;
    for (i = m; i <= n; i++)
    {
        result = (result & i);
    }
    return result;
}

//算法的思路
//根据观察的得出 只要产生进位，则进位后面的与操作全为0

//寻找最高位  如果最高位1的位置不一样 那么直接为0
int msb(int m)
{
    int count = 0;
    while (m > 0)
    {
        //向右移位 高位补0  低位移除
        m = (m >> 1);
        count++;
    }
    //加的时候会多加一位
    return count - 1; //从 0 开始数
}

//可以把结果result 的第 i 位变成 1
int set_bit(int result, int i)
{
    //把  1  左移  i  个位置
    return (result | (1 << i));
}

//看下这个数字的第i位是多少
int get_bit(int m, int i)
{
    return ((m >> i) & 1);
}

int fast_Bit_And(int m, int n)
{ //求出m和n的最高位
    int msb_m = msb(m);
    int msb_n = msb(n);
    //如果最高位位置不在同一个位置
    if (msb_m != msb_n)
    {
        //贼与操作直接就是0
        return 0;
    }
    //否则的话先拿最高位出来
    int msb = msb_m;
    int result = 0;  //记录结果的
    while (msb >= 0) //不加等于  m=1 n=1出错
    {
        //将看下每个数字的第msb位
        //可以看出是 1 还是 0
        int x = get_bit(m, msb);
        int y = get_bit(n, msb);
        if (x != y)
        { //现在是最高位
            //如果他们的有一位不相等
            //直接返回  因为就相当于产生了进位 后面肯定全部为 0
            return result;
        }
        else if (x == y && x == 1)
        {
            //如果都等于1  就把result的msb位设置为1
            result = set_bit(result, msb);
        }
        //不断的减一
        msb--;
    }
    return result;
}

int main()
{

    printf("%d\n", fast_Bit_And(74, 78));
    system("pause");
    return 0;
}

//另一种好的方法
//  m  100 1010
//  n  100 1110
//  re 100 1000
// 可以发现 re <= m 则从 n 开始  把最右边的 1 变成 0
//看一下是否 小于等于  m