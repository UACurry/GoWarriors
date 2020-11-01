#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int sum = 0;
    int t;
    scanf("%d", &n);
    while (n > 0)
    {
        t = n % 10;
        sum += t;
        n = n / 10;
    }
    printf("%d\n", sum);
    system("pause");
    return 0;
}