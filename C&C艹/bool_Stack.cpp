#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <stack>

using namespace std;

//给定一个 整数  n  在给一串小于1-n的序列 判断能否出栈

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0); //初始化 n个0
    for (int i = 0; i < n; i++)
    {
        //这里不能用push_back  因为 这样 就不是出栈的序列了  push_back中第一个输入的数 在 n-1的位置
        cin >> a[i];
    }

    stack<int> st;
    int cur = 1; //用来压入栈
    bool f = 1;  //用来判断是否能够出栈

    for (int i = 0; i < n; i++)
    {
        //三个判断条件 如果栈顶元素 不是 所要求的序列第一个  那么就压栈 直到是栈顶元素
        //当不满足循环的时候就会跳出循环
        while ((st.empty() || st.top() != a[i]) && cur <= n)
        {
            st.push(cur);
            cur++;
        }

        if (st.empty() || st.top() != a[i])
        {
            f = 0;
            break;
        }
        else
        {
            //当前栈顶和所求序列匹配
            st.pop();
        }
    }

    if (f)
    {
        cout << "legal" << endl;
    }
    else
    {
        cout << "illegal" << endl;
    }

    system("pause");
    return 0;
}