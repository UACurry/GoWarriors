#include <iostream>
#include <cstring>
#include <algorithm>
//斐波那契额数列
using namespace std;
#define mod 1000000007
int f[100005];
int main()
{
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }

    cout << f[n] << endl;
    system("pause");
    return 0;
}