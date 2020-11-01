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

long long f[100][100];

//杨辉三角  将杨辉三角全部靠在左边  下面的数 =  上面两个数之和
void init()
{
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
            {
                f[i][j] = 1;
            }
            else
            {
                //规律的公式
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
            }
        }
    }
}
int main()
{
    init();
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= 4; i++)
    {
        cout << f[4][i];
    }
    cout << endl;

    cout << f[n][m] << endl;
    system("pause");
    return 0;
}