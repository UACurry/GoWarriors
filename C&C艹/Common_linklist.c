#include <stdio.h>
#include <stdlib.h>
//交叉链表，求两个交叉链表的汇合点

typedef struct node
{
    int value;
    struct node *Next;
} Node;

int list_len(Node *list)
{

    Node *p = list;
    int length = 0;
    while (p != NULL)
    {
        ++length;
        p = p->Next;
    }
    return length;
}

//让长的那条链表往后移动差值个位置
//让长链表的第一个结点往后移动
Node *Move_first_node(Node *list, int offset)
{
    Node *p = list; //list的第一个结点
    int i;
    for (i = 0; i < offset; i++)
    {
        p = p->Next;
    }
    return p;
}

//找相同的点，两个链表的相汇聚的点
Node *Find_common_Node(Node *list1, Node *list2)
{
    int length1 = list_len(list1);
    int length2 = list_len(list2);
    Node *long_list = list1; //假设第一条链长
    Node *short_list = list2;
    if (length2 > length1)
    {
        long_list = list2;
        short_list = list1;
    }
    //求得两条链表长短的差值
    int offset = abs(length1 - length2);

    //将长链移动差值个位置后，相当于两条链表同一起点
    //p1 是长链  需要往后移动的
    Node *p1 = Move_first_node(long_list, offset);
    Node *p2 = short_list;
    while (p1 != NULL)
    {
        //一直往后移动 直到找到汇点
        if (p1 == p2)
        {
            return p1;
        }
        p1 = p1->Next;
        p2 = p2->Next;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    Node n1, n2, n3, n4, n5, n6, n7;
    n1.value = 1;
    n2.value = 2;
    n3.value = 3;
    n4.value = 4;
    n5.value = 5;
    n6.value = 6;
    n7.value = 7;

    n1.Next = &n2;
    n2.Next = &n3;
    n3.Next = &n4;
    n4.Next = &n5;
    n5.Next = &n6;
    n6.Next = NULL;
    n7.Next = &n4;

    Node *list1 = &n1;
    Node *list2 = &n7;
 
    int length1 = list_len(list1);
    int lenght2 = list_len(list2);

    printf("第一条链长度:%d\n", length1);
    printf("第二条链长度:%d\n", lenght2);

    Node *common_node = Find_common_Node(list1, list2);
    printf("汇点%d\n", common_node->value);
    system("pause");
    return 0;
}