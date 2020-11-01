//并查集
#include <stdio.h>
#include <stdlib.h>

#define Vertex 6 //设置顶点的数量

//将parent数组全部置换为-1
void init(int parent[], int rank[])
{
    int i;
    for (i = 0; i < Vertex; i++)
    {
        parent[i] = -1;
        rank[i] = 0;
    }
}

int find_root(int x, int parent[])
{
    //假设这个x就是根结点
    int x_root = x;
    while (parent[x_root] != -1)
    {
        x_root = parent[x_root]; //一直寻找父结点
    }
    return x_root;
}

//函数的返回值  返回 1 表示能够union 返回9，合并失败
//合并的两个点在同一个集合里面，表示合并失败
int union_root(int x, int y, int parent[], int rank[])
{
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    if (x_root == y_root)
    {
        //合并失败，两个在同一个集合
        return 0;
    }
    else
    {
        //把x_root 的父节点设置为y
        //parent[x_root] = y_root;
        if (rank[x_root] > rank[y_root])
        {
            //此时树的高度不变
            parent[y_root] = x_root;
        }
        else if (rank[y_root] > rank[x_root])
        {
            parent[x_root] = y_root;
        }
        else
        {
            parent[x_root] = y_root;
            rank[y_root]++;
        }
        return 1;
    }
}

int main()
{
    int parent[Vertex] = {0};
    //设置一个rank数组用来表示树高
    //从而达到平衡树的目的
    int rank[Vertex] = {0};
    int edges[6][2] = {
        {0, 1}, {1, 2}, {1, 3}, {5, 4}, {3, 4}, {2, 5}};
    init(parent, rank);

    int i;
    for (i = 0; i < 6; i++)
    { //拿每条边对应的两个结点
        int x = edges[i][0];
        int y = edges[i][1];
        if (union_root(x, y, parent, rank) == 0)
        {
            printf("有环\n");
            system("pause");
            exit(0);
        }
    }
    printf("无环\n");
    system("pause");
    return 0;
}