#include <stdio.h>
//双亲孩子表示法

#define Max 100

typedef char ElementType;

//孩子结点
typedef struct CTNode{

    int child;//孩子结点的下标
    struct CTNode *Next; //指向下一个孩子结点的指针
}*ChildPtr;


//表头结构 就是前面的根节点
typedef struct {
    ElementType Data;
    int Parent;//用数组的下标来表示父节点  
    ChildPtr firstchild;//指向第一个孩子的指针
}CTBox;

//把前面两个串起来，表示树结构
typedef struct{
    CTBox Node[Max];//定义一个数组  来表示所有
}Nodes;