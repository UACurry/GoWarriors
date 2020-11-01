#include <stdio.h>

int main(void){
    int num1,denom1,num2,denom2,result_num,result_denom;

    printf("first fraction:");
    scanf("%d/%d",&num1,&denom1);

    printf("second fraction:");
    scanf("%d/%d",&num2,&denom2);

    result_num = num1*denom2+num2*denom1;
    result_denom = denom1*denom2;
    printf("This is result %d/%d",result_num,result_denom);
    getchar();
    return 0;
}