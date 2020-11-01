#include <stdio.h>
#include <stdlib.h>

//线段树
//声明:带node的都是有关tree数组的下标 其他的都是arr的下标
#define Max_Len 1000

//tree数就是根就是左右结点的sum，并且把这颗树构造成满树
//node代表根节点，需要一个tree的数组
//start 和 end 都是arr数组的参数
void build_tree(int arr[], int tree[], int node, int start, int end)
{
    if (start == end)
    {
        //递归的出口
        //就要填arr数组上面的数字，也就是叶节点代表数组上面的数字
        tree[node] = arr[start];
    }
    else
    {
        //劈成两半，构造数
        int mid = (start + end) / 2;  //劈成两半的中间值
        int left_node = 2 * node + 1; //tree数组
        int right_node = 2 * node + 2;

        //递归调用，算出左节点和右节点的值
        build_tree(arr, tree, left_node, start, mid);
        build_tree(arr, tree, right_node, mid + 1, end);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

void update_tree(int arr[], int tree[], int node, int start, int end, int index, int val)
{
    if (start == end)
    {
        arr[index] = val;
        tree[node] = val;
    }
    else
    {
        //想把arr[index] = val
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1; //tree数组
        int right_node = 2 * node + 2;

        //确定改左分支还是右分支
        if (index >= start && index <= mid)
        {
            //左分支
            update_tree(arr, tree, left_node, start, mid, index, val);
        }
        else
        {
            update_tree(arr, tree, right_node, mid + 1, end, index, val);
        }
        //更新一下tree[node]
        tree[node] = tree[left_node] + tree[right_node];
    }
}

//query(L,R)计算arr一段里面的和
int query(int arr[], int tree[], int node, int start, int end, int L, int R)
{
    if (R < start || end < L)
    {
        //不在左边或者右边的范围
        return 0;
    }
    //这一步的出口避免的冗余的递归
    else if (L <= start && end <= R)
    {
        //此时也可以返回，因为tree数组已经算出来了
        return tree[node];
    }
    else if (start == end)
    {
        return tree[node];
    }
    else
    {
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1; //tree数组
        int right_node = 2 * node + 2;
        int sum_left = query(arr, tree, left_node, start, mid, L, R);
        int sum_right = query(arr, tree, right_node, mid + 1, end, L, R);
        return sum_left + sum_right;
    }
}

int main()
{

    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = 6;
    int tree[Max_Len] = {0}; //先把全部初始化为0

    build_tree(arr, tree, 0, 0, size - 1);
    system("pause");
    return 0;
}