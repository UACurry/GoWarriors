#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//月饼
//给定所有种类的库存量，总销价 以及市场的最大需求量
//试计算可以获得的最大收益是多少
//输入 月饼种类个数  市场需求
//      每个库存
//      总售价
#define MAX 100

struct mooncake
{
    double store; //库存
    double sell;  // 总售价
    double price; // 单价
} cake[MAX];

typedef struct mooncake mk;

bool cmp(mk a, mk b)
//按单价从高到底排序
{
    return a.price > b.price;
}

int main()
{
    int i;
    int n;    //种类
    double D; //总需求量
    scanf("%d %lf", &n, &D);
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &cake[i].store);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }
    sort(cake, cake + n, cmp); //按照降序排列
    double ans = 0;            //收益
    for (int i = 0; i < n; i++)
    {
        if (cake[i].store <= D)
        {
            D -= cake[i].store; //第i 种月饼全部卖出
            ans += cake[i].sell;
        }
        else
        {
            ans += cake[i].price * D;
            break;
        }
        printf("%lf", ans);
        return 0;
    }
}