#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 200

typedef int QElemType;

typedef struct QNode
{
    QElemType Data[MAXSIZE];
    int front; //front 指向的是队列头一个元素的前面一个
    int rear;  //rear指向最后一个元素
} SQueue;

SQueue *InitQueue(SQueue *Q) /*初始化*/
{
    Q = (SQueue *)malloc(sizeof(SQueue));
    (Q)->front = 0;
    (Q)->rear = 0;
    return Q;
}

void INIT(SQueue **Q)
{
    (*Q)->front = 0;
    (*Q)->rear = 0;
}

int QueueLength(SQueue *Q)
{
    int length;
    length = ("%d\n", (Q->rear - Q->front + MAXSIZE) % MAXSIZE);
    return length;
}

bool QueueEmpty(SQueue *Q)
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

void AddQueue(SQueue *PtrQ, QElemType Item)
{
    if ((PtrQ->rear + 1) % MAXSIZE == PtrQ->front)
    {
        //判断rear是否和front处于数组的同一个位置
        printf("队列满");
        return;
    }
    else
    {
        PtrQ->rear = (PtrQ->rear + 1) % MAXSIZE;
        PtrQ->Data[PtrQ->rear] = Item; /*front指向的是前一个空元素，rear指向的是最后一个元素位置，而非后一个空位置*/
    }
}

void DeleteQueue(SQueue *Q)
{
    if (Q->rear == Q->front)
    {
        printf("队列空");
    }
    else
    {
        Q->front = (Q->front + 1) % MAXSIZE;
        printf("%d\n", Q->Data[Q->front]);
    }
}

int main()
{
    int j;
    int i;
    SQueue *Q;
    INIT(&Q);
    AddQueue(Q, 1);
    AddQueue(Q, 2);
    AddQueue(Q, 3);
    QueueEmpty(Q);
    printf("第一次出队\n");
    DeleteQueue(Q);
    AddQueue(Q, 4);
    AddQueue(Q, 5);
    AddQueue(Q, 6);
    j = QueueLength(Q);
    printf("第二次出队\n");
    for (i = 1; i <= j; i++)
    {
        DeleteQueue(Q);
    }
    system("pause");
    return 0;
}