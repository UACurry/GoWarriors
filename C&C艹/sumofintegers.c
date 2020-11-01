#include<stdlib.h>
#include<stdio.h>

int main(void){
    int n,sum = 0;
    printf("这是一个计算数列求和的\n");
    printf("请输入数字(用0结尾)");

    scanf("%d",&n);
    while (n!=0)
    {
        sum += n;
        scanf("%d",
        &n);
    }
    printf("总和是：%d\n",sum);
    system("pause");
    return 0;
}