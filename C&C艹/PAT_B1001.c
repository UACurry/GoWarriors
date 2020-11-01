//害死人 不偿命 （3n+10
// n  偶数 砍一半  基数 把(3n+1)砍一半  最后为1
//算一下不超过1000 需要几步

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, step = 0;
    scanf("%d\n", &n);
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
            step++;
        }
        else
        {
            n = (3 * n + 1) / 2;
            step++;
        }
    }
    printf("%d\n", step);
    system("pause");
    return 0;
}