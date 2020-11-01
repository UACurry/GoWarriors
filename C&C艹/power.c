#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//判断一个数字是不是二的乘方
bool isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }
    else if (n == 1)
    {
        return true;
    }
    else
    { //利用位操作 逻辑与运算
        //2 10
        //4 100
        // 8 1000
        // 16 10000
        if ((n & (n - 1)) == 0)
        {
            return true;
        }
        else
        {

            return false;
        }
    }
}

int main()
{
    printf("%d\n", isPowerOfTwo(2));
    printf("%d\n", isPowerOfTwo(32));
    printf("%d\n", isPowerOfTwo(64));
    printf("%d\n", isPowerOfTwo(34));
    system("pause");
    return 0;
}
