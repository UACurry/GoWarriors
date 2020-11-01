#include <iostream>
#include <algorithm>

using namespace std;

int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int y, m, d, k;
    cout << "请输入在一起的时间例如 2015 10 1" << endl;
    cin >> y >> m >> d;
    cout << "请输入天数纪念日" << endl;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        if ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0)
        {
            day[2] = 29;
        }
        else
        {
            day[2] = 28;
        }
        d++;
        //如果d++之后 天数超了当前月份的最大天数
        if (d == day[m] + 1)
        {
            d = 1;
            m++;
        }
        if (m == 13)
        {
            m = 1;
            y++;
        }
    }

    cout << "GDD的所选纪念日为:" << y << "-" << m << "-" << d << endl;
    system("pause");
    return 0;
}