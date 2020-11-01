#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <map>
using namespace std;

//简单计算器
//读入中缀表达式 然后转为后缀表达式来计算

//规则 当前要进来的操作符 优先级 高于 栈顶操作符 压栈
//     当前要进来的操作符 优先级 低于或等于 栈顶  不断弹出  直到 要进来的操作符 优先级 高于栈顶操作符

//读入的为字符串
struct node
{
    double num; //操作数
    char op;    //操作符
    bool flag;  // true 表示操作数 ，false 表示操作符
};

string str;
stack<node> s;     //操作符栈
queue<node> q;     //后缀表达式序列
map<char, int> op; //设置操作符的优先级

//将中缀表达式 转化为  后缀表达式
void Change()
{
    double num;
    node temp;
    for (int i = 0; i < str.length();)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            //是字符串 所以即使是两位数 也是一位一位读
            //如果是数字的话
            temp.flag = true;          //标记为数字
            temp.num = str[i++] - '0'; //记录下来第一位数
            while (i < str.length() && str[i] >= '0' && str[i] <= '9')
            {
                //如果是两位数甚至三位数
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            q.push(temp); //将这个操作数压入后缀表达式队列
        }
        else
        {
            //如果是操作符
            temp.flag = false; //标记为操作符
            //根据规则进行操作符栈的压栈操作
            //此时 操作符栈顶元素 比 操作符高
            //就把栈顶弹出 到后缀表达式中
            while (!s.empty() && op[str[i]] <= op[s.top().op])
            {
                //不断弹出
                q.push(s.top()); //入队
                s.pop();
            }
            temp.op = str[i];
            s.push(temp); //把该操作符压入操作符栈
            i++;
        }
    }
    //如果操作符栈中还有操作符，就把它弹出到后缀表达式队列
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

//计算后缀表达式
double Cal()
{
    double temp1, temp2;
    node cur, temp;
    while (!q.empty())
    {
        //后缀表达式非空
        cur = q.front(); //记录队首元素
        q.pop();
        if (cur.flag == true)
        {
            //如果是操作数 直接压入栈
            s.push(cur);
        }
        else
        {
            //如果是操作符
            temp2 = s.top().num; //弹出第二操作数
            s.pop();
            temp1 = s.top().num; //弹出第一操作数
            s.pop();
            temp.flag = true; //临时记录操作数

            if (cur.op == '+')
            {
                temp.num = temp1 + temp2;
            }
            else if (cur.op == '-')
            {
                temp.num = temp1 - temp2;
            }
            else if (cur.op == '*')
            {
                temp.num = temp1 * temp2;
            }
            else
            {
                temp.num = temp1 / temp2; //除法
            }
            s.push(temp); //把该操作数压入栈
        }
    }

    //最后
    return s.top().num; // 栈顶元素就是最后的值
}

int main()
{
    op['+'] = op['-'] = 1; //设定操作符优先级
    op['*'] = op['/'] = 2;
    while (getline(cin, str), str != "0")
    {
        for (string::iterator it = str.end(); it != str.begin(); it--)
        {
            if (*it == ' ')
            {
                str.erase(it); //删除空格
            }
        }
        while (!s.empty())
        {
            s.pop(); //初始化栈
        }
        Change();
        printf("%.2f\n", Cal());

        return 0;
    }
}