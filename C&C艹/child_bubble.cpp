#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

//题目 ： n 个小朋友 摸m个气球 老师规定 跳的矮的学生先摸  摸到的气球就被拿走
using namespace std;

const double EPSILON = 1e-6;

int num[105];

struct Student
{
    int a;  //小朋友跳的高度
    int id; //小朋友编号
};

int ans[100005]; //记录每个小朋友摘了多少
Student stu[100005];
int h[1005]; //气球的高度

//小朋友能摸到的高度 从低到高
bool cmp(Student a, Student b)
{
    return a.a < b.a;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].a;
        stu[i].id = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> h[i];
    }
    sort(stu, stu + n, cmp);
    sort(h, h + m);
    int p = 0; //因为对气球排序了 所以用来记录第几个气球
    for (int i = 0; i < n; i++)
    {
        //能摸到的条件
        while (p < m && h[p] <= stu[i].a)
        {
            ans[stu[i].id]++;
            p++;
        }
    }

    system("pause");
    return 0;
}