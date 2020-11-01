#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>

//如此定义一个链表

//第一个结构体  定义一个链表结点
typedef struct node
{

    int data;          //保存数据
    struct node *next; //指向下一个结点
} Node;

//一个链表包含一个头结点和一个尾结点
typedef struct
{
    Node *head;
    Node *tail;
} LinkedList; //新的数据写进来直接放在最后面

//创建一个链表
LinkedList *CreateList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

//插入到链表的尾部
void InsertList(LinkedList *list, int data)
{
    //生成一个新的链表结点
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    { //插在尾部
        list->tail->next = node;
        list->tail = node;
    }
}

void printList(LinkedList *list)
{
    Node *p = list->head;
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void reverseList(LinkedList *list)
{
    Node *pre = NULL;     //前一个结点
    Node *p = list->head; //最开始的结点
    Node *temp;           //用来表示下一个结点
    list->tail = p;       //头和尾倒过来,先让尾指着p
    while (p != NULL)
    {
        temp = p->next; //先定义，p是temp的下一个
        //把链断开
        p->next = pre; //这一步相当于把链表改变方向 本来是  -> 变成 <-
        pre = p;       //往右移动
        p = temp;
    }
    list->head = pre;
}

//带头结点的一个函数，当时没明白老师作业测试的
/*bool Delfirst(LinkedList *L,int X){
    Node *pre,*p;
    pre = L;
    p =pre->next;
    while(p != NULL && p->data != X){
        pre = p;
        p =p->next;
    }
    if(p!= NULL){
        pre->next = p->next;
        free(p);
        return true;  
    else
        return false;
}
*/

int main()
{

    LinkedList *list = CreateList();
    InsertList(list, 5);
    InsertList(list, 6);
    InsertList(list, 7);
    InsertList(list, 8);
    InsertList(list, 9);
    InsertList(list, 10);
    InsertList(list, 11);
    InsertList(list, 12);
    reverseList(list);
    printList(list);

    system("pause");
    return 0;
}