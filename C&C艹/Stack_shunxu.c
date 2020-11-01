#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

//1817443032 李欣
typedef int ElementType;
typedef struct SNode
{
    ElementType Data[MAXSIZE];
    int Top;
} Stack;

void InitStack(Stack **PtrS)
{
    //这里用二级指针，或者自己再定义一个结构体，或者返回指针
    //初始化
    (*PtrS)->Top = -1;
}

Stack *InitStack_anonther(Stack *S)
{
    S = (Stack *)malloc(sizeof(struct SNode));
    S->Top = -1;
    return S;
}

bool IsEmpty(Stack *S)
{
    return (S->Top == -1);
}

bool IsFull(Stack *S)
{
    return (S->Top == MAXSIZE - 1);
}

bool Push(Stack *PtrS, ElementType item) //用数组表示堆栈时，Top = 0 表示第一个元素
//用Top =-1 表示堆栈空
{
    if (PtrS->Top == MAXSIZE - 1)
    {
        printf("堆栈满");
        return false;
    }
    else
    {
        PtrS->Data[++(PtrS->Top)] = item;
        return true;
    }
}

bool Pop(Stack *PtrS, ElementType *e)
{
    if (PtrS->Top == -1)
    {
        printf("堆栈空");
        return false;
    }
    else
    {
        *e = PtrS->Data[PtrS->Top];
        PtrS->Top--;
        return true;
    }
}

bool GetTop(Stack *S, int *e)
{ //取出栈顶元素。
    if (IsEmpty(S))
    {
        return false; //如果栈为空，则不能取出栈顶元素。
    }
    *e = S->Data[S->Top]; //用e取出栈顶元素。
    printf("栈顶元素:%d\n", *e);
    return true;
}

bool go_back_string(char str[])
{
    ElementType e;
    int i;
    Stack *S;
    InitStack(&S);
    //初始化
    for (i = 0; str[i] != '\0'; i++)
    {
        Push(S, str[i]);
    }
    //比较栈中元素和字符串
    for (i = 0; str[i] != '\0'; i++)
    {
        Pop(S, &e);
        if (str[i] != e)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int e;
    Stack *S;
    InitStack(&S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    IsEmpty(S);
    GetTop(S, &e);
    Pop(S, &e);
    Pop(S, &e);
    Pop(S, &e);
    Pop(S, &e);
    Pop(S, &e);
    system("pause");
    return 0;
}

/*
typedef struct DStack{
    ElementType Data[MAXSIZE];
    int Top1;  //堆栈1 的栈顶指针
    int Top2;  //堆栈2 的栈顶指针
}S;

S.Top1 = -1;
S.Top2 = MAXSIZE;

void Push_Double(struct DStack *Ptrs,ElementType item,int Tag){
    //Tag作为区分两个堆栈的标志,取值1和2
    if(Ptrs->Top2 - Ptrs->Top1 == 1){
        printf("堆栈满");
        return;
    }
    if(Tag == 1)
        Ptrs->Data[++(Ptrs->Top1)] = item;
    else
        Ptrs->Data[--(Ptrs->Top2)] = item;
}

ElementType Pop_Double(struct DStack *Ptrs,int Tag){
    if(Tag == 1){
        if (Ptrs->Top1 == -1)//堆栈1空
        {
            printf("堆栈1空");
            return NULL;
        }else{
            return Ptrs->Data[(Ptrs->Top1)--];
        }
    }else{
        if(Ptrs->Top2 == MAXSIZE){
            printf("堆栈空");
            return NULL;
        }else{
            return Ptrs->Data[(Ptrs->Top2)++];
        }
    }
}

*/