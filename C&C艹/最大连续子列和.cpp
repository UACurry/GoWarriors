#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <cmath>
#include <queue>

using namespace std;

//最大连续子列和

const int inf = 0x7ffffff;
int num[101];

int main()
{
    int n;
    cin >> n;

    //输入一个数
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int ans = -inf;
    //如果全部都小于0 就给出一个最大值
    for (int i = 0; i < n; i++)
    {
        ans = max(num[i], ans);
    }

    //如果全部小于零 就输入最大的那个数
    if (ans <= 0)
    {
        cout << ans << endl;
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            //当加到小于零的时候 就可以把 sum 置为零
            if (sum + num[i] < 0)
            {
                sum = 0;
            }
            else
            {
                sum += num[i];
            }
            ans = max(sum, ans);
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}