//堆排序

#include <stdio.h>
#include <stdlib.h>
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//结点序号从上往下，从左往右

//n代表有几个结点，i表示对哪个结点做堆排序
//这种方法是下面的子堆是排好序的，所以自顶向下
//只有顶部没有排好
//从第i个结点开始 heapify  那么 i 就是parent 结点
void heapify(int tree[], int n, int i)
{
    //递归的出口
    if (i >= n)
    {
        return;
    }

    int c1 = 2 * i + 1; //左儿子下标
    int c2 = 2 * i + 2; //右儿子下标
    //从三个结点里面找出最大值
    int max = i; //假设i是最大值
    if (c1 < n && tree[c1] > tree[max])
    { //保证c1 和 c2 不会出界
        //也就是不存在左右儿子
        max = c1;
    }
    if (c2 < n && tree[c2] > tree[max])
    {
        max = c2;
    }
    //不满足最大堆的要求
    if (max != i)
    {
        swap(tree, max, i);
        //第 max 位置截至递归
        heapify(tree, n, max); //递归
    }
}

//如果是乱序的
//n为结点个数
//那么就从底层开始往上做heapify
void heap_build(int tree[], int n)
{
    int last_node = n - 1;            //最后一个结点下标
    int parent = (last_node - 1) / 2; //父亲
    int i;
    //因为父节点序号是依次递减的
    for (i = parent; i >= 0; i--)
    {
        //对上面每一个结点做一次heapify
        heapify(tree, n, i);
    }
}

//从小到大排起来
//思路 首先 经过heap_build 后  最大的结点肯定在最上面
//  那么  就把最大的结点和最后一个结点做交换
// 此时 交换后 肯定不满足 父节点比子节点大
// 那么 对此时最上面的做一次heapify 就又符合要求了
//  如此循环 最后从小到大输出
void heap_sort(int tree[], int n)
{
    heap_build(tree, n); //成功构建一个堆
    int i;
    int last_node = n - 1;
    for (i = last_node; i >= 0; i--)
    {
        swap(tree, i, 0); //交换根 和 最后 一个  根就是第0个
        //砍掉 换过去的 最大的结点怎么实现呢
        // i  就代表当前结点个数
        heapify(tree, i, 0); //i刚好可以代表n的数量，因为再不断砍断
    }
}

int main()
{
    int tree[] = {2, 5, 3, 1, 10, 4};
    int n = 6;
    heap_sort(tree, n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\n", tree[i]);
    }

    system("pause");
    return 0;
}