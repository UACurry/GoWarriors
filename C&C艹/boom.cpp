#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

//炸弹爆炸
//如果一个炸弹被点燃  那么 他的行列都被点爆

char mat[1004][1004];
bool row[1004], col[1004]; //用来存储这一行 这一列是否被引爆过
int n, m;

void boom(int x, int y)
{
    //将这个坐标标记为引爆
    mat[x][y] = 0;
    //如果这行没被引爆 就引爆他
    if (!row[x])
    {
        row[x] = true;
        //将这一行的每一列引爆
        for (int i = 0; i < m; i++)
        {
            if (mat[x][i] == '1')
            {
                boom(x, i);
            }
        }
    }

    //同理 看这一列有没有被引爆
    if (!col[y])
    {
        col[y] = true;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][y] == '1')
            {
                boom(i, y);
            }
        }
    }
}
int ans;
int main()
{
    cin >> n >> m;
    //输入矩阵
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '1')
            {
                ans++;
                boom(i, j);
            }
        }
    }

    //输入需要人工引爆的次数
    cout << ans << endl;

    system("pause");
    return 0;
}