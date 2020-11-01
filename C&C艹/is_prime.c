//判断质数  以及求质因子
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//自己笔记本上面有笔记 可以查阅

//判断是不是素数
bool is_prime(int n)
{
    int i;
    if (n == 1)
    {
        return false;
    }
    int sqr = (int)sqrt(1.0 * n); //根号n
    for (i = 2; i <= sqr; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

#define Max 100000
int prime[Max], pNum = 0;
void Find_prime()
{
    //求素数表
    int i;
    for (i = 1; i < Max; i++)
    {
        if (is_prime(i) == true)
        {
            prime[pNum] = i; //装入表里面
            pNum++;
        }
    }
}

struct factor
{
    int x, cnt; // x 为质因子 ，cnt为其个数
} fac[10];

int main()
{
    int i;
    Find_prime();
    int n, num = 0; //num 为 n的不同质因子的个数 就是有几个质因子
    scanf("%d", &n);
    if (n == 1)
    {
        printf(" 1 = 1"); //特殊情况 1的质因子
    }
    else
    {
        printf("%d", n);
        int sqr = (int)sqrt(1.0 * n);
        //枚举根号n以内的质因子
        for (i = 0; i < pNum && prime[i] <= sqr; i++)
        {
            //没有超过质数的个数 且 在根号n范围内
            if (n % prime[i] == 0)
            {
                //如果 prime[i] 是一个质因子
                fac[num].x = prime[i]; //记录
                fac[num].cnt = 0;
                while (n % prime[i] == 0)
                {
                    //计算有几个这样的质因子
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++; //不同质因子个数加一
            }
            if (n == 1)
                break; //及时退出
        }
        if (n != 1)
        {
            //无法被根号n以内的质因子除尽
            fac[num].x = n; //那就只有一个大于根号n 的因子
            fac[num].cnt = 1;
            num++;
        }

        //输出
        for (i = 0; i < num; i++)
        {
            if (i > 0)
            {
                printf("*");
            }
            printf("%d", fac[i].x);
            if (fac[i].cnt > 1)
            {
                printf("^%d", fac[i].cnt);
            }
        }
    }
    return 0;
}