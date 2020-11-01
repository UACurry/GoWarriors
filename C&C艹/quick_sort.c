#include <stdio.h>
#include <stdlib.h>
//1817443032李欣
int Adjust(int k[], int low, int high)
{ //返回调整后基数的位置

    //int i = low,j = high;
    int x = k[low]; //让第一个元素为第一个坑
    while (low < high)
    {

        //从右向左找小于X的数来填坑
        while (low < high && x <= k[high])
        {
            high--;
        }
        //跳出循环了，即while循环不成立x <= k[high]
        if (low >= high)
            break; //当low和high重合的时候就跳出最大的循环
        else
        {
            k[low] = k[high]; //这一步就是把小于x 的值放到左边
            low++;
        }

        //从左向右找大于X的数来填坑
        while (low < high && k[low] <= x)
        {
            low++;
        }
        //若跳出循环了
        if (low >= high)
            break;
        else
        {
            k[high] = k[low]; //将上一个while循环的坑补上
            high--;
        }
    }
    //退出循环后，用前面的X来天最后一个坑
    k[low] = x;
    return low;
}

void quick_sort(int k[], int low, int high)
{

    int mid;
    if (low >= high)
        return;
    else
    {
        mid = Adjust(k, low, high);
        quick_sort(k, low, mid - 1);
        quick_sort(k, mid + 1, high);
    }
}

int main()
{

    int i;
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    quick_sort(arr, 0, 9);
    printf("排序后的数组为:\n");
    for (i = 0; i < 10; i++)
        printf("%d,", arr[i]);
    printf("\n");
    system("pause");
    return 0;
}