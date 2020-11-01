
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct Node //链表的结构
{
    ElementType Data;
    struct Node *Next;
} DataNode;

typedef struct QNode
{
    //代表队列的结构
    struct Node *rear;
    struct Node *front;

} Queue;

Queue *InitQueue(Queue *Q)
{
    Q = (Queue *)malloc(sizeof(Queue));              //为链队列结点分配内存
    Q->front = (DataNode *)malloc(sizeof(DataNode)); //为数据结点分配内存
    if (Q->front != NULL)
    {
        Q->rear = Q->front;
        Q->front->Next = NULL; //带头结点的队列
        return Q;
    }
    else
    {
        return 0;
    }
}

bool QEmpty(Queue *Q)
{
    if (Q->front == Q->rear)
    {
        printf("队列空\n");
        return true;
    }
    else
    {
        printf("队列不空\n");
        return false;
    }
}

void AddQueue(Queue *Q, ElementType Item)
{
    DataNode *S = (DataNode *)malloc(sizeof(DataNode));
    if (!S) //存储分配失败
        exit(0);
    S->Data = Item; //入队在队尾
    S->Next = NULL;
    Q->rear->Next = S; //把新结点S赋值给原来队尾结点的后继
    Q->rear = S;       //把当前S结点设置为队尾结点 ，即始终要让rear指向队尾
}

bool DeleteQ(Queue *Q)
{
    struct Node *FrontCell;
    ElementType FrontElem;

    if (Q->front == Q->rear)
    { //front 和 rear 相当于头结点   front为空表示队列空，  rear 指向队列尾巴
        printf("队列空");
        return false;
    }
    FrontCell = Q->front->Next; //找到队列的头一个元素
    if (Q->front == Q->rear)
    { //若队列只有一个元素
        Q->front = Q->rear = NULL;
    }
    else
        Q->front->Next = FrontCell->Next; //把队列的第一个结点删除
    FrontElem = FrontCell->Data;
    free(FrontCell);
    printf("出队的元素是:%d\n", FrontElem);
}

int main()
{

    Queue *Q;
    Queue *queue;
    Q = InitQueue(queue);
    AddQueue(Q, 1);
    AddQueue(Q, 2);
    AddQueue(Q, 3);
    QEmpty(Q);
    DeleteQ(Q);
    AddQueue(Q, 4);
    AddQueue(Q, 5);
    AddQueue(Q, 6);
    system("pause");
    return 0;
}
