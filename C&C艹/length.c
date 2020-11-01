#include<stdlib.h>
#include<stdio.h>

int main(void){
    int len = 0;

    printf("输入一段话");
    while (getchar() != '\n'){
    
        len++;
        }
        printf("长度为：%d\n",len);
    
        system("pause");
        return 0;
    
    
    
}