#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int dp[50][50];
typedef long long LL;
int main()
{
    dp[1][1] = 1;
    long long n;
    for (cin >> n; n != 0; n >>= 1)
    {
        cout << n;
        if (n != 1)
        {
            putchar(' ');
        }
        else
        {
            putchar('\n');
        }
    }

    cout << dp[0][0];
    system("pause");
    return 0;
}