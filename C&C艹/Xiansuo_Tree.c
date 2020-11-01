#include <stdio.h>
#include <stdlib.h>

//线索二叉树

//用中序遍历，每隔一个就会有一个叶节点
typedef char Elemtype;

//线索存储标志位
//link{0}.表示指向左右孩子的指针
//Thread{1},表示指向前驱后继的线索
typedef enum{Link,Thread} PointerTag;

typedef struct Xiansuo_Node{

    char Data;
    struct Xiansuo_Tree *LChild,*RChild;
    PointerTag Ltag;//标志
    PointerTag Rtag;//标志
}BiThrNode,*BiThrTree;

//创建二叉树，规定用户前序遍历输入
BiThrTree CreateBiTree(BiThrTree BT){
    char i;

    scanf("%c",&i);
    if(i =='#' ){
        BT = NULL;
    }
    else{
        BT = (BiThrNode *)malloc(sizeof(BiThrNode));
        BT->Data = i;
        BT->Ltag = Link;//如果是叶子结点，就是0， 如果不是，再在后面修改
        BT->Rtag = Link;
        BT->LChild = CreateBiTree(BT->LChild);
        BT->RChild = CreateBiTree(BT->RChild);

    }
    
    return BT;
}

BiThrTree Pre;

//中序遍历
void InOrder(BiThrTree BT){

    if(BT){
        InOrder(BT->LChild);

        //结点处理
        if(!(BT->LChild)){//如果结点没有左孩子，设置Ltag为Threa，并且把Lchild 指向刚刚访问的结点
        
            BT->Ltag = Thread;
            BT->LChild = Pre;
        }

        InOrder(BT->RChild);
    }
}
