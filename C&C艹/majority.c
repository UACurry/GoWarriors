//找出众数，众数超过一半
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//规则  如果空栈  就入栈
//如果栈顶元素和要入栈的相等  就入栈
//其他情况 出栈
int majority_num(int nums[], int numsize)
{
    int *Stack = (int *)malloc(sizeof(int) * numsize);
    int top = -1;

    int i;
    for (i = 0; i < numsize; i++)
    {
        if (top == -1)
        {
            //空栈
            Stack[++top] = nums[i]; //入栈
        }
        else if (Stack[top] == nums[i])
        {
            Stack[++top] = nums[i]; //入栈
        }
        else
        {
            top--; //出栈
        }
    }
    return Stack[0];
}

int main()
{
    //众数必须占一半以上
    int nums[] = {1, 1, 1, 1, 2, 4, 5, 6};
    int re = majority_num(nums, 8);
    printf("%d", re);

    system("pause");
    return 0;
}