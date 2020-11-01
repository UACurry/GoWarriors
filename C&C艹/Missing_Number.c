//找出丢失的数
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int missingNumber(int nums[], int numSize)
{
    bool arr[] = (int *)malloc(sizeof(int) * (numSize + 1));
    int i;
    for (i = 0; i < numSize; i++)
    {
        arr[i] = false;
    }
    int id;
    for (i = 0; i < numSize; i++)
    {
        id = nums[i];
        arr[id] = true;
    }
    for (i = 0; i < numSize + 1; i++)
    {
        if (arr[i] == false)
        {
            return i;
        }
    }
    return 0;
}

int missingnumber_best(int nums[], int numSize)
{
    int sum = numSize * (numSize + 1) / 2;
    int i;
    for (i = 0; i < numSize; i++)
    {
        sum = sum - nums[i];
    }
    return sum;
}

int main()
{

    system("pause");
    return 0;
}