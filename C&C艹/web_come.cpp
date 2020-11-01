#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

//访问网址  当输入 visit时  访问这个网址
//          当输入back时 回退
//          当输入forward 时 前进

string op, s;
//两个栈  用来存前面网址和后面网址
stack<string> st1, st2;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> op;
        if (op == "VISIT")
        {
            //输入网址
            cin >> s;
            //当要读入一个网址的时候  就要把前面存的 forward清空
            while (!st2.empty())
            {
                st2.pop();
            }
            st1.push(s);
        }
        else if (op == "BACK")
        {
            //这里的判断条件  意思是  当选择back时候 至少要保留一个网址 所以要求个数至少有两个 才能back 不然只有一个网址  没法back
            if (st1.size() <= 1)
            {
                cout << "false" << endl;
                continue;
            }
            else
            { //看不明白可以画图
                //将这个网址弹出 但是保留到st2中 这样就有了forward
                st2.push(st1.top());
                st1.pop();
            }
        }
        else
        //forward 网页前进
        {
            if (st2.empty())
            {
                cout << "false" << endl;
                continue;
            }
            else
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
        //输入当前处于的网页
        cout << st1.top() << endl;
    }

    system("pause");
    return 0;
}