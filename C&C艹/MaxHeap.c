#include <stdio.h>
#include <stdlib.h>

#define MaxData  1000

typedef int ElementType;
//堆可以定义为一个结构，用数组来存储一个完全二叉树
typedef struct HeapStruct{
    ElementType *Elements; //存储堆元素数组的指针
    int Size; //当前堆元素个数
    int Capacity;//堆的最大容量
}*MaxHeap;

MaxHeap Create(int MaxSize){
    //创建容量为MaxSize的空的最大堆

    MaxHeap H =(MaxHeap)malloc(sizeof(struct HeapStrcut));//申请空间
    H->Elements = malloc((MaxSize+1) * sizeof(ElementType));//再申请一个数组的空间,希望的堆的容量，
    //下标为0 的地方不存放堆的元素
    H->Size = 0;
    H->Capacity =MaxSize;
    H->Elements[0] = MaxData;//哨兵

    return H;

}

void Insert(MaxHeap H,ElementType Item){
    //将元素item 插入到最大堆H
    int i;
    if(IsFull(H)){
        printf("最大堆已满");
        return;
    }
    i = ++H->Size;//堆不满，就把i指向堆最后一个元素的位置
    for( ;H->Elements[i/2] < Item;i/=2)//有哨兵，哨兵挡住，否则要加 i>1判断
        H->Elements[i] = H->Elements[i/2];//和父节点做比较，如果大则换过来，保持完全二叉树的有序性
    H->Elements[i] = Item; 
}

ElementType DeleteMax(MaxHeap H){
    //从最大堆H中取出值最大的元素，删除
    int Parent,Child;
    ElementType MaxItem, temp;
    if(IsEmpty(H)){
        printf("最大堆空");
        return;
    }
    MaxItem = H->Elements[1];//把要删的元素保存起来，就是堆的第一个
    //然后用最后一个元素来替换上来
    temp = H->Elements[H->Size];//最后一个元素
    H->Size--;
    //现在看temp该放在哪里
    for(Parent = 1;Parent*2 <= H->Size/*判别是否有左儿子*/;Parent=Child){
        //parent 就是将来要放的位置
        Child = Parent*2;//child指向左儿子
        if((Child != H->Size/*chld = size意味着只有左儿子，用来判别有没有右儿子*/) && (H->Elements[Child] < H->Elements[Child+1]))
            Child++;//将左右儿子中较大的结点返回为child
        if(temp >= H->Elements[Child])
            break;//说明找到合适的位置了
        else//左右儿子大的那个要上来
            H->Elements[Parent] = H->Elements[Child];

    }
    H->Elements[Parent] = temp;
    return MaxItem;
}