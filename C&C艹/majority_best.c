//找出众数，众数超过一半
//优化过的
//时间复杂度O(n) ,空间O(1)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//规则  如果空栈  就入栈
//如果栈顶元素和要入栈的相等  就入栈
//其他情况 出栈
int majority_num(int nums[], int numsize)
{                  //不需要设置一个栈
    int cand;      //代表栈
    int count = 0; //代表栈顶

    int i;
    for (i = 0; i < numsize; i++)
    {
        if (count == 0)
        {
            //空栈
            cand = nums[i]; //入栈
            count++;
        }
        else if (cand == nums[i])
        {
            count++; //入栈
        }
        else
        {
            count--; //出栈
        }
    }
    return cand;
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