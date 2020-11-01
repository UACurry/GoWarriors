#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

long ans = 0;
int main()
{
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);

    //遍历 b 数组中得每个数
    int p = 0, q = 0;
    for (int i = 0; i < n; i++)
    {
        //考察哦 a 中 比 b小的
        while (p < n && a[p] < b[i])
        {
            p++;
        }
        //q是比b小的个数  n-q  就是 c 中 比 b大的
        while (q < n && c[q] <= b[i])
        {
            q++;
        }
        ans += p * (n - q);
    }

    cout << ans << endl;
    system("pause");
    return 0;
}