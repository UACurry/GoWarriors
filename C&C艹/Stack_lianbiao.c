#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//1817443032李欣
typedef int ElementType;
typedef struct SNode
{
    ElementType Data;
    struct SNode *Next;
} S, Stack;

Stack *CreateStack()
{
    /*构建一个空的堆栈,生成头结点*/
    Stack *S;
    S = (Stack *)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

void INIT(Stack **S)
{
    (*S)->Next = NULL;
}

int IsEmpty(Stack *S)
{ //判断堆栈S是否为空，若为空函数返回整数1，否则返回0
    return (S->Next == NULL);
}

void Push(Stack *S, ElementType item)
{ //将item,压入
    struct SNode *TmpCell;
    TmpCell = (Stack *)malloc(sizeof(struct SNode));
    TmpCell->Data = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

//注意，这里S是头结点，那么执行Push,Pop 时 都是在链表的头结点处进行 就压到头结点下一个和删除头结点下一个
ElementType Pop(Stack *S)
{
    Stack *FirstCell;
    int TopElem;
    if (IsEmpty(S))
    {
        printf("堆栈空");
        return 0;
    }
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Data; //要return一个东西，把Data赋值给一个变量
        free(FirstCell);
        return TopElem;
    }
}

void DestroyStack(Stack *S)
{                       //销毁链栈。
    Stack *pre = S;     //声明p的前驱指针pre指向头结点。
    Stack *p = S->Next; //p指针指向首结点。
    while (p)
    { //循环遍历链栈，逐个释放pre保存的结点。
        free(pre);
        pre = p;
        p = pre->Next;
    }
    free(pre); //释放最后一个结点。
}

int main()
{
    Stack *S;
    int TopElem;
    S = CreateStack();
    //INIT(&S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    int i;
    i = IsEmpty(S);
    Pop(S);
    Pop(S);
    Pop(S);
    Pop(S);
    Pop(S);
    system("pause");
    return 0;
}