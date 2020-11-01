#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vi;
    for (int i = 1; i <= 5; i++)
    {
        vi.push_back(i);
    }
    vector<int>::iterator it = vi.begin();
    vi.insert(it + 1, 9);
    int a = vi.size();
    for (int i = 0; i < a; i++)
    {
        printf("%d\n", *(it + i));
    }

    set<int> st;
    st.insert(100);
    st.insert(200);
    st.insert(300);
    st.erase(st.begin(), st.end());
    printf("%d\n", st.size());

    string str1 = "dawdd";
    string str2 = "dadada";
    //cin >> str1;
    //cin >> str2;
    cout << str1 << endl;
    cout << str2 << endl;
    //printf("%s", str1.c_str());

    string str3;
    str3 = str2 + str1;
    cout << str3 << endl;
    str1.erase(str1.begin(), str1.end() - 1);
    cout << str1 << endl;

    map<char, int> mp;

    mp['m'] = 20;
    mp['r'] = 30;
    mp.erase(mp.begin());
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        printf("%c %d\n", it->first, it->second);
    }

    queue<int> q;
    for (int i = 1; i <= 5; i++)
    {
        q.push(i); //压入 1 2 3 4 5
    }
    cout << q.front() << " " << q.back() << endl;
    for (int i = 0; i < 2; i++)
    {
        q.pop();
    }
    cout << q.front() << endl;

    priority_queue<int> pq;
    pq.push(3);
    pq.push(4);
    pq.push(1);
    printf("%d\n", pq.top());

    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(2);
    pq2.push(1);
    pq2.push(10);
    printf("%d\n", pq2.top());

    struct fruit
    {
        string name;
        int price;
    } f1, f2, f3;

    struct cmp
    {
        bool operator()(fruit f1, fruit f2)
        {
            return f1.price > f2.price;
        }
    }; //价格低的优先级高

    priority_queue<int, vector<int>, cmp> pq3;

    stack<int> s1;
    for (int i = 0; i <= 5; i++)
    {
        s1.push(i);
    }
    s1.pop();
    s1.pop();
    cout << s1.top() << endl;

    pair<string, int> p("ha", 5); //直接初始化的方法
    pair<string, int> p2;
    cout << p.first << " " << p.second << endl;
    //赋值方法1
    p2.first = "da";
    p2.second = 555;
    //赋值方法2
    p2 = make_pair("dwad", 23);
    //赋值方法3
    p2 = pair<string, int>("dawd", 32);

    //作为map的键值对来插入
    map<string, int> mp_pair;
    mp_pair.insert(make_pair("lixin", 20));
    mp_pair.insert(pair<string, int>("wawa", 222));
    for (map<string, int>::iterator it = mp_pair.begin(); it != mp_pair.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    int arr[3] = {10, 11, 12};
    reverse(arr, arr + 2);
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    string str5 = "abcdefg";
    reverse(str5.begin(), str5.end());
    for (int i = 0; i < str5.length(); i++)
    {
        cout << str5[i] << endl;
    }

    int arr1[10] = {1, 2, 3};
    do
    {
        cout << arr1[0] << " " << arr1[1] << " " << arr1[2] << endl;
    } while (next_permutation(arr1, arr1 + 3));

    fill(arr1, arr + 3, 2333);
    for (int i = 0; i < 3; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
