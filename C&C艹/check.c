#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int main(void){
    bool dight_seen[10] = {false};
    int dight;
    long n;

    printf("输入一个数字");
    scanf("%ld",&n);

    while (n>0)
    {
        dight = n % 10;
        if (dight_seen[dight])
            break;
        dight_seen[dight] = true;
        n /= 10;
        
    }
    if(n>0)
        printf("重复数字\n");
    else    
        printf("无重复数字\n");

    system("pause");
    return 0 ;
}