#include<stdio.h>
#include<stdlib.h>

#define N 10

int main(void)
{
    int a[N], i;

    printf("输入%d数字",N);
    for ( i = 0; i < N; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("倒置数组");
    for ( i = N - 1; i >= 0; i--)
    {
        printf("%d",a[i]);
        printf("\n");
    }
    printf("\n");
    system("pause");
    return 0 ;
    

}