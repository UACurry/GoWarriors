#include<stdio.h>
#include<stdlib.h>

int main(void){
    int i,n;
    printf("这是一个打印平方的程序\n");
    printf("输入你所想的值");
    scanf("%d", &n);

    /*i=1;
    while (i<=n)
    {
        printf("%10d%10d\n",i , i*i);
        i++;
    }*/
    for ( i = 0; i < n; i++){
        printf("%10d%10d",i,i*i);
    }
    
    system("pause");
    return 0;

}