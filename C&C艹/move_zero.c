#include <stdio.h>
#include <stdlib.h>

//将数组中  0元素 移动到数组的最后面
void move_zero1(int arr[], int n)
{
    int zero = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            //如果不是 0  就往前面挪
            arr[i - zero] = arr[i];
        }
        else
            zero++;
    }

    for (i = n - zero; i < n; i++)
    {
        arr[i] = 0;
    }
}

void move_zero2(int arr[], int n)
{
    //分成三段 第一段 已经走过的了 确定不是0
    //第二段  全是0  j指向第一个0元素
    //第三段 还没走过  i指向还没走过的第一个
    int j = 0;
    int i;
    for (i = 0; i < n; i++)
    { //不管怎样i都++
        if (arr[i] != 0)
        {
            //第 i 不是 0   交换 arr[i] 和  arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++; //i也在循环里面++了   当条件不符合，就i++,但j没动
            //这样就形成了一开始我们想要的结果
        }
        else
        {
            continue; //相当于i++；
        }
    }
} //可以拿来快速排序

int main()
{

    int arr[8] = {1, 7, 0, 2, 3, 0, 4, 8};
    move_zero2(arr, 8);

    int i;
    for (i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    system("pause");
    return 0;
}