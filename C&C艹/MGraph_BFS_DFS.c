//用领接矩阵表示图
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//1817443032李欣
#define Max 100

typedef int WeightType;
typedef int DataType;
typedef int Vertex;

typedef struct GNode
{
    int Nv; //顶点数
    int Ne; //边数
    //二维数组存储图中边或者弧的信息
    WeightType G[Max][Max]; //二维数组，由图里面所有顶点的数量来决定，来存储图中边或者弧的信息
    DataType Data[Max];     //存储数据
} GNode, *PtrToGNode;       //指向该结点的指针，传一个指针方便

typedef PtrToGNode MGraph; //用领接矩阵存储图类型

typedef struct Queue
{
    int data[Max];
    int front;
    int rear;
} LinkQ;

void InitQueue(LinkQ **Q)
{
    (*Q)->front = (*Q)->rear = 0;
}

bool QueueFull(LinkQ *Q)
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
void EnQueue(LinkQ *Q, int i)
{
    if (!QueueFull(Q))
    {
        Q->data[Q->rear] = i;
        Q->rear = (Q->rear + 1) % Max; //指针后移
    }
}
bool QueueEmpty(LinkQ *Q)
{
    if (Q->front == Q->rear)
    {
        return true;
    }
    return false;
}
void DeQueue(LinkQ *Q, int *e)
{
    if (!QueueEmpty(Q))
    {
        *e = Q->data[Q->front];
        Q->front = (Q->front + 1) % Max;
    }
}

//初始化一个有VertexNum个顶点但没有边的图
MGraph CreateGraph(int VertexNum)
{
    MGraph Graph;
    Vertex V, W, M; //顶点类型 V，W

    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum; //把顶点给Nv
    Graph->Ne = 0;         //没有边的图

    printf("输入顶点的编号");
    for (M = 0; M < Graph->Nv; M++)
    {
        scanf("%d", &Graph->Data[M]);
    }

    //注意,这里的默认顶点编号从0开始，到Graph->Nv-1
    for (V = 0; V < Graph->Nv; V++)
        for (W = 0; W < Graph->Nv; W++)
            Graph->G[V][W] = 0; //没有边，则领接矩阵V，W都为0
    return Graph;
}

//有了结点，下面开始构造边

//向MGraph中插入边
typedef struct ENode
{
    //定义一个边结点
    Vertex V1, V2;     //一个顶点是出发点，一个顶点是终点
    WeightType Weight; //权重
} * PtrToENode;
//李欣
typedef PtrToENode Edge;

void InsertEdge(MGraph Graph, Edge E)
{
    //把相应的权重赋值给相应的领接矩阵的元素

    Graph->G[E->V1][E->V2] = E->Weight; // V1，V2赋值给权重

    //若是无向图，因为领接矩阵是一轴对称的
    // Graph->G[E->V2][E->V1] = E->Weight;
}

//完整的建立一个MGraph
MGraph BuildGraph()
{
    MGraph Graph; //声明一个图
    Edge E;
    int Nv, i;

    printf("请输入顶点数");
    scanf("%d", &Nv);        //不需要边数，就可以初始化一个图
    Graph = CreateGraph(Nv); //无边的图
    //这里非常秀操作，少一个变量哈哈哈哈哈
    printf("请输入边数");
    scanf("%d", &(Graph->Ne)); //再读边数
    if (Graph->Ne != 0)
    {
        E = (Edge)malloc(sizeof(struct ENode));
        for (i = 0; i < Graph->Ne; i++)
        {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight); //每一次循环把边的信息读进来
            InsertEdge(Graph, E);                          //调用函数插入边
        }
    }
    return Graph;
}

bool Visited[Max];
void for_DFS(MGraph Graph, int i)
{
    int j;
    Visited[i] = true;
    printf("%d", Graph->Data[i]);
    for (j = 0; j < Graph->Nv; j++)
    {
        if (Graph->G[i][j] != 0 && !Visited[j])
        {
            for_DFS(Graph, j);
        }
    }
}

void DFS(MGraph Graph, int m)
{
    int i;
    for (i = 0; i < Graph->Nv; i++)
    {
        Visited[i] = false;
    }
    for_DFS(Graph, m);
}

void BFS(MGraph Graph, int m)
{
    int i, j, p;
    LinkQ *Queue = (LinkQ *)malloc(sizeof(struct Queue));
    for (i = 0; i < Graph->Nv; i++)
    {
        Visited[i] = false;
    }
    InitQueue(&Queue);

    Visited[m] = true;
    printf("%d", Graph->Data[m]);
    EnQueue(Queue, m);

    while (!QueueEmpty(Queue))
    {
        DeQueue(Queue, &p);

        for (j = 0; j < Graph->Nv; j++)
        {
            //遍历下标为p的这一行
            if (Graph->G[p][j] != 0 && Visited[j] == false)
            {
                Visited[j] = true; //
                printf("%d", Graph->Data[j]);
                EnQueue(Queue, j);
            }
        }
    }
}

int main()
{
    MGraph graph;
    graph = BuildGraph();
    int i, j;
    for (i = 0; i < graph->Nv; i++)
    {
        for (j = 0; j < graph->Nv; j++)
        {
            printf("%d", graph->G[i][j]);
        }
        printf("\n");
    }
    BFS(graph, 4);
    system("pause");
    return 0;
}