#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

const int N = 1000;

//N代表层数  因为规定从第一层开始仍，所以开N+1
int f1[N + 1], f2[N + 1], f3[N + 1]; //手机数目为1，2，3,对应各层得测试次数

int main()
{
    //一部手机情况
    for (int i = 1; i <= N; i++)
    {
        f1[i] = i;
    }
    //考虑两部手机情况
    for (int i = 1; i <= N; i++)
    {
        int ans = INT_MAX;
        //从1开始尝试 1-i
        for (int j = 1; j <= i; j++)
        {
            //从j层开始仍第一个手机
            //两种情况 手机是好的 与 是坏的
            //求max
            int _max = 1 + max(f2[i - j], f1[j - 1]);
            ans = min(ans, _max);
        }
        f2[i] = ans;
    }

    //考虑三部手机
    for (int i = 1; i <= N; i++)
    {
        int ans = INT_MAX;
        //从1开始尝试 1-i
        for (int j = 1; j <= i; j++)
        {
            //从j层开始仍第一个手机
            //两种情况 手机是好的 与 是坏的
            //求max
            int _max = 1 + max(f3[i - j], f2[j - 1]);
            ans = min(ans, _max);
        }
        f3[i] = ans;
    }

    cout << f3[N] << endl;

    system("pause");
    return 0;
}