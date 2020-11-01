#include<stdio.h>
#include<stdlib.h>

int main(void){
    int cmd;
    float balance = 0.0f,credit, debit;

    printf("存取款一体机");
    printf("指令：0 = 清空余额，1 =存钱， 2= 取钱， 3 = 显示余额，4 = 退出");
    for( ; ;)//无限循环
    {
        printf("输入指令");
        scanf("%d", &cmd);
        switch(cmd){
            case 0:
            balance = 0.0f;
            break;
            case 1:
            printf("请输入存款额度");
            scanf("%f",&debit);
            balance +=debit;
            break;
            case 2:
            printf("请输入取款额度");
            scanf("%f",&credit);
            balance -=credit;
            break;
            case 3:
            printf("当前的余额为：%f\n",balance);
            break;
            case 4:
            return 0;
            default:
            printf("指令：0 = 清空余额，1 =存钱， 2= 取钱， 3 = 显示余额，4 = 退出");
            break;
        }
    }

    system("pause");
    return  0;
}