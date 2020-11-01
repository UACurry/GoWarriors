#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//1817443032李欣
#define MaxVertexNum 100
#define Max 10

typedef int WeightType; //权值
typedef int DataType;
typedef int VertexType; //顶点的 数据类型

typedef struct AdjVNode
{
    int AdjV;              //领接点下标，因为是链表，所有指向下一个结点就好
    WeightType Weight;     //边的权重
    struct AdjVNode *Next; //链表指向下一个结点的指针
} AdjNode, *PtrToAdjVNode;

//第一步
//创造一个一维数组，每个DAta存放每个顶点，first表示他的第一个领接点
typedef struct VNode         //领接表头
{                            //头节点包含一个指针，指向边结点
    PtrToAdjVNode FirstEdge; //第一条边，总是指向第一条边
    VertexType Data;         //顶点数据
} AdjList[Max];              //领接表的类型是一个数组，数组的大小就是有多少个顶点

typedef struct GNode
{              //图
    int Nv;    //顶点数
    int Ne;    //边数
    AdjList G; //领接表
} * PtrToGNode;

typedef PtrToGNode LGraph;

typedef struct Queue
{
    //定义一个循环队列吧 暂时这么想
    int data[Max];
    int front;
    int rear; //队尾指向最后一个元素的下一个元素
} Queue, *AdjQueue;

void InitQueue(Queue **Q)
{
    (*Q)->front = (*Q)->rear = 0;
}

bool QueueFull(Queue *Q)
{
    if ((Q->rear + 1) % Max == Q->front)
    {
        return true; //队列满了
    }
    else
    {
        return false;
    }
}

bool QueueEmpty(Queue *Q)
{
    if (Q->front == Q->rear)
    {
        return true;
    }
    return false;
}

void EnQueue(Queue *Q, int i)
{
    if (!QueueFull(Q))
    {
        Q->data[Q->rear] = i;
        Q->rear = (Q->rear + 1) % Max; //指针后移
    }
}

void DeQueue(Queue *Q, int *e)
{
    if (!QueueEmpty(Q))
    {
        *e = Q->data[Q->front];
        Q->front = (Q->front + 1) % Max;
    }
}

//初始化没有边的图
LGraph CreateGraph(int VertexNum)
{
    LGraph Graph;
    VertexType V; //顶点类型 V，W

    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum; //把顶点给Nv
    Graph->Ne = 0;         //没有边的图

    //指针为空，表示没有边
    //注意,这里的默认顶点编号从0开始，到Graph->Nv-1
    printf("输入顶点的编号");
    for (V = 0; V < Graph->Nv; V++)
    {
        scanf("%d", &Graph->G[V].Data);
        Graph->G[V].FirstEdge = NULL; //第一条边都等于空
    }
    return Graph;
}

typedef struct ENode
{
    //定义一个边结点
    VertexType V1, V2; //一个顶点是出发点，一个顶点是终点
    WeightType Weight; //权重
} * PtrToENode;

typedef PtrToENode Edge;

void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;

    //为V2建立新的领接点
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    //把V2插入V1的表头,头插法
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    //无向图 复制上面，交换V1，V2
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    int Nv, i;
    printf("请输入顶点数");
    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);
    printf("请输入边数");
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0)
    {
        printf("请输入结点和权重");
        for (i = 0; i < Graph->Ne; i++)
        {
            E = (Edge)malloc(sizeof(struct ENode));
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }
    return Graph;
}

//下面操作一手BFS
//思路就是从初试位置顶点开始，遍历所有的领接顶点将其加入队列，当一个顶点的所有领接点都遍历完了之后就把该顶点出队列
bool Visited[Max];
void BFS(LGraph Graph, int m)
{ //m是表示从第几个顶点开始
    int i;
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    for (i = 0; i < Graph->Nv; i++)
    {
        Visited[i] = false;
    }
    InitQueue(&Q);
    Visited[m] = true;
    printf("%d", Graph->G[m].Data);
    EnQueue(Q, m);

    while (!QueueEmpty(Q))
    {
        DeQueue(Q, &i);                     //这里不断修改i的值 把出队的值赋给i
        AdjNode *e = Graph->G[i].FirstEdge; //i 顶点的领接链表的第一个

        while (e)
        {
            //e存在时 ，把e的所有领接点加入队列，也就是遍历i的所有领接点
            if (Visited[e->AdjV] == false)
            {
                //e表示结点的下标
                Visited[e->AdjV] = true;
                printf("%d", Graph->G[e->AdjV].Data);
                EnQueue(Q, e->AdjV); //将该结点入队
            }
            e = e->Next; //遍历下一个领接点
        }
    }
}

//DFS
//这里用栈的话是最好的选择  但是太长了代码
void for_DFS(LGraph Graph, int i)
{
    AdjNode *p;
    Visited[i] = true; //访问过了
    printf("%d", Graph->G[i].Data);
    p = Graph->G[i].FirstEdge; //让p指向边表的第一个结点
    while (p)
    {
        if (Visited[p->AdjV] == false)
        {
            //对为访问的领接点递归调用
            for_DFS(Graph, p->AdjV); //这里的递归就相当于栈的作用
        }
        p = p->Next;
    }
}

void DFS(LGraph Graph, int m)
{
    int i;
    for (i = 0; i < Graph->Nv; i++)
    {
        Visited[i] = false;
    }
    for_DFS(Graph, m);
}
int main()
{
    LGraph Graph;
    Graph = BuildGraph();
    VertexType V;
    PtrToAdjVNode tmp;
    for (V = 0; V < Graph->Nv; V++)
    {
        //每个顶点都是一个链表
        tmp = Graph->G[V].FirstEdge;
        printf("%d->", V);
        while (tmp)
        {
            printf("%d[%d]->", tmp->AdjV, tmp->Weight);
            tmp = tmp->Next; //指向下一个
        }
        printf("\n");
    }
    printf("BFS的结果说是:");
    BFS(Graph, 4);
    printf("\n");
    printf("DFS的结果说是:");
    DFS(Graph, 4);
    system("pause");
    return 0;
}
