
/*
void LevelOrderTraversal(BinTree BT)//层序遍历，通过用队列的方法，一层一层访问
{
    Queue Q；
    BinTree T;
    if(!BT)
    return; /*空树直接返回*/
    Q = CreatQueue(Maxsize);/*创建并初始化队列Q*/
    Add(Q,BT);
    while(!IsEmpty(Q)){
        T = Delete(Q);
        printf("",T->Data);
        if(T->Left)
        Add(Q,T->Left);
        if(T->Right)
        Add(Q,T->Right);
        
    }
}*/