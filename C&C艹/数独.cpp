#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

//数独
char s[10][10];
bool f;
bool vx[10][10], vy[10][10], vv[10][10]; //vx 表示每一行能填吗  vy表示 每一列能填吗  vv表示3*3方格子能填吗
void dfs(int x, int y)
{
    if (f)
    {
        return;
    }
    //已经到头了 x到 9  那肯定有解了
    if (x == 9)
    {
        f = true;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (j != 8)
                {
                    cout << s[i][j];
                }
                else
                {
                    cout << s[i][j] << endl;
                }
            }
        }
        return;
    }
    //如果一行中 y遍历到头了  就到下一行去填写
    if (y == 9)
    {
        dfs(x + 1, 0);
        return;
    }

    //有些位置我们本来不用填
    //如果不是 * 号 就是已经填好了的
    if (s[x][y] != '*')
    {
        dfs(x, y + 1);
        return;
    }

    //填数
    for (int i = 1; i <= 9; i++)
    {
        //如果数字都没有被选用
        if (!vx[x][i] && !vy[y][i] && !vv[x / 3 * 3 + y / 3][i])
        {
            s[x][y] = '0' + i;
            vx[x][i] = true;
            vy[y][i] = true;
            vv[x / 3 * 3 + y / 3][i] = true;
            dfs(x, y + 1);
            //还原 回溯
            vx[x][i] = false;
            vy[y][i] = false;
            vv[x / 3 * 3 + y / 3][i] = false;
            s[x][y] = '*'; //将数字还原成*
        }
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> s[i][j];
        }
    }

    //先将给出的数组中  填写好的数字标记为true
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (s[i][j] = '*')
            {
                vx[i][s[i][j] - '0'] = true;
                vy[j][s[i][j] - '0'] = true;
                vv[i / 3 * 3 + j / 3][s[i][j] - '0'] = true;
            }
        }
    }

    //从坐标0，0 开始考虑
    dfs(0, 0);

    system("pause");
    return 0;
}