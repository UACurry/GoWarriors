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
int dp[1001], a[101], n;

int LIS()
{
    memset(dp, 0, sizeof(dp));
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    cout << LIS() << endl;

    system("pause");
    return 0;
}