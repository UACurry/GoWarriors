#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <cmath>
#include <queue>
#include <fstream>

using namespace std;

set<string> A;
set<string> B;
set<string> C;

int a[] = {1, 2, 3};
int main()
{
    do
    {
        cout << a[0] << a[1] << a[2] << endl;

    } while (next_permutation(a, a + 3));

    system("pause");
    return 0;
}