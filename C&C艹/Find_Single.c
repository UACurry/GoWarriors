//给一个数组 其他数字都出现了两次
//找出那个只有一个的数字
#include <stdio.h>
#include <stdlib.h>

//涉及到异或
//a^b^a = b  相同的会被抵消掉
int signal_number(int nums[], int numSize)
{
    int k = nums[0];
    int i;
    for (i = 1; i < numSize; i++)
    {
        k = (k ^ nums[i]);
    }
    return k;
}

int main()
{
    int num[5] = {1, 2, 1, 2, 5};
    int k;
    k = signal_number(num, 5);
    printf("%d", k);
    system("pause");
    return 0;
}