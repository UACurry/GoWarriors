#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

//99乘法表
using namespace std;
vector<vector<int>> v2d;

int main()
{

    for (int i = 0; i < 9; i++)
    {
        v2d.push_back(vector<int>());
    }

    for (int i = 0; i < v2d.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            v2d[i].push_back((i + 1) * (j + 1));
        }
    }

    for (int i = 0; i < v2d.size(); i++)
    {
        for (int j = 0; j < v2d[i].size(); j++)
        {
            cout << i + 1 << " * " << j + 1 << " = " << v2d[i][j] << "\t";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}