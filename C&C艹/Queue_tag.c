#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//循环队列
typedef int ElemType;
typedef struct
{
    ElemType Data[20];
    int tag;
    int front;
    int rear;
} Queue;

//循环队列

Queue *InitQueue(Queue *Q) //队列初始化
{
    Q = (Queue *)malloc(sizeof(Queue));
    (Q)->front = 0;
    (Q)->rear = 0;
    (Q)->tag = 0;
    return Q;
}

bool EnQueue(Queue *Q, ElemType x)
{
    if (Q->tag == 1)
    {
        return false;
    }
    else
    {
        Q->Data[Q->rear] = x;
        Q->rear = (Q->rear + 1) % 20; //rear指针向后移一个位置，若到最后则转到数组头部
        if (Q->rear == Q->front)
        {
            Q->tag = 1; //队列满
        }
        return true;
    }
}

bool DeQueue(Queue *Q, int x)
{
    if (Q->front == Q->rear && Q->tag == 0)
    {
        return false;
    }
    else
    {
        x = Q->Data[Q->front];
        Q->front = (Q->front + 1) % 20; //front指针向后移一个位置，若到最后则转到数组头部
        if (Q->front == Q->rear)
        {
            Q->tag = 0; //队列空
        }
        return true;
    }
}

int main()
{
    Queue *queue;
    queue = InitQueue(queue);
    EnQueue(queue, 9);
    system("pause");
    return 0;
}
