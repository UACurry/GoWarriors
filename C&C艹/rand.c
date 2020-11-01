#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//生成随机数

int main()
{
    int a, b;
    srand((unsigned)time(NULL));
    printf("%d", rand() % ((b - a + 1) + a)); //范围[a,b]
    system("pause");
    return 0;
}