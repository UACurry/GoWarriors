#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

//经典八皇后问题
//八皇后要求  每一列 和 每一行 以及 每条对角线 上  都不能有超过一个皇后
//求出有多少组解法

//前排提示  是否同意对角线的表达方式  可以发现  斜率为1 和 -1 的两种对角线  斜率为1 的对角线 行加列的 值为就是 0-7  斜率为-1  行减去列 值为负数

int ans = 0;                  //用来表示有多少种解法
bool col[10], x1[20], x2[20]; //分别表示列 1对角线 -1对角线 是否存在 皇后

bool check(int r, int i)
{
    return !col[i] && !x1[r + i] && !x2[r - i + 8];
}

void dfs(int r)
{
    //如果能dfs到8  那么之前肯定都是合法的 也就是说 0-7八个行都行
    if (r == 8)
    {
        ans++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        //如果 r 行 i 列可以放皇后
        if (check(r, i))
        {
            // + 8防止负坐标的访问
            col[i] = x1[r + i] = x2[r - i + 8] = true;
            dfs(r + 1);                                 //进入到下一行
            col[i] = x1[r + i] = x2[r - i + 8] = false; //要统计所有的情况 所以这里一定要取消
        }
    }
}

int main()
{
    ans = 0;

    dfs(0);
    cout << ans << endl;
    system("pause");
    return 0;
}