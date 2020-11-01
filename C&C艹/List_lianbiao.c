#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode
{
    ElementType Data;
    struct LNode *Next;
} L, *List;

List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Next = NULL;
    return L;
}

int Length(List PtrL)
{
    List p = PtrL->Next; //p指向链表的第一个结点
    int j = 0;           //计数器
    while (p)            //p指针不等于NULL
    {
        p = p->Next;
        j++;
    }
    return j;
}

List FindKth(int k, List PtrL) //查找第K个元素 //按序号查找
{
    List p = PtrL->Next; //设置P为链表的表头
    int i = 1;           //i代表第几个元素
    while (p != NULL && i < k)
    {                //链表不为空 且 还没找到第K个元素
        p = p->Next; //往后挪
        i++;
    } //循环退出来   两个条件有一个被破坏了
    if (i == k)
        return p; //找到了
    else
        return NULL;
}

List Find(ElementType X, List PtrL)
{ //按值查找

    //带头结点
    List p = PtrL->Next;              //p为链表的头
    while (p != NULL && p->Data != X) //表不空
        p = p->Next;
    return p;
}

List Insert(ElementType X, int i, List PtrL)
{

    List temp, pre;
    int cnt = 0; //头结点的序号为0
    pre = PtrL;  //pre指向头结点
    if (i < 0)
    {
        return 0;
    }
    while (pre && cnt < i - 1)
    {
        //查找第 i - 1 个结点p
        pre = pre->Next;
        cnt++;
    }
    if (pre == NULL || cnt != i - 1)
    {
        //pre == NULL 说明单链表长度大于了实际长度
        printf("错误");
        return 0;
    }
    else
    {
        temp = (List)malloc(sizeof(struct LNode));
        temp->Data = X;
        temp->Next = pre->Next;
        pre->Next = temp;
        return PtrL;
    }

    /*  这个方法是原来没有头结点的情况
    //在第i-1个结点后面插入一个值为X的新结点
    //先构造一个新的结点，用S指向
    //再找到链表的第i-1个结点，用P指向
    //然后修改指针，插入结点
    List p, s;
    if (i == 1)
    { //插在链表的头上
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = PtrL;
        return s; //返回新表的头指针，调用的时候用 PtrL = Insert()
    }
    p = FindKth(i - 1, PtrL); //查找第i-1个结点，找到要插入位置前面一个位置
    if (p == NULL)
    { //第i-1个结点不存在，不能插入
        printf("参数错误");
        return NULL;
    }
    else
    {
        s = (List)malloc(sizeof(struct LNode)); //申请
        s->Data = X;
        s->Next = p->Next; //插入在第i-1个结点后面
        p->Next = s;
        return PtrL;
    }
    */
}

List Delete(int i, List PtrL) //想删除第i个位置上面的结点
{
    List temp, pre;
    int cnt = 0; //代表头结点
    if (i <= 0)
    {
        return 0;
    }
    while (cnt < i - 1 && pre != NULL)
    {
        pre = pre->Next;
        cnt++;
    }
    if (pre == NULL || cnt != i - 1 || pre->Next == NULL)
    {
        //没有那么长 或者 后面就没有了
        return 0;
    }
    else
    {
        temp = pre->Next;
        pre->Next = temp->Next;
        free(temp);
        return PtrL;
    }
    /*  此方法是不带头结点的
    //先找到链表的第i-1个结点，用p指向
    //再用指针S指向要被删除的结点
    //修改指针，删除S所指的结点
    //释放
    List p, s;
    if (i == 1)
    {
        //删除头节点
        s = PtrL;
        if (PtrL != NULL)
            PtrL = PtrL->Next; //从链表种删除
        else                   //PtrL本身为空
            return NULL;
        free(s);
        return PtrL;
    }
    p = FindKth(i - 1, PtrL); //查找第i-1个结点
    if (p == NULL)
    {
        printf("第%d个结点不存在", i - 1);
        return NULL;
    }
    else if (p->Next == NULL)
    {
        printf("第%d个结点不存在", i);
        return NULL;
    }
    else
    {
        s = p->Next; //s指向第i个结点
        p->Next = s->Next;
        free(s);
        return PtrL;
    }
*/
}

int main()
{
    List PtrL;
    PtrL = MakeEmpty();
    PtrL = Insert(99, 1, PtrL);
    PtrL = Insert(92, 2, PtrL);
    printf("%d\n", PtrL->Next->Next->Data);

    system("pause");
    return 0;
}