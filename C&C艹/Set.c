//集合的运算
//可以用树结构来表示集合，树的每个结点代表一个集合元素

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef int ElementType;
typedef int SetName; //默认用根结点的下标作为集合的名称
typedef ElementType SetType[MaxSize];//集合的类型，定义为一个数组


/*typedef struct {
    ElementType Data;
    int Parent;
}*/

SetName Find(SetType S,ElementType X){
    //X不需要扫描整个数组来找到X,X直接就是数组的下标
    //S[x] 存的 就是 X的父结点  根结点为-1
    /*for( ;S[X] >= 0;X = S[X])//一直往上找，找到根结点   
        return X;*/
    if(S[X]<0)//带路径压缩的Find函数，将路径上的所有结点都指向父结点，如果需要多次调，就很有优势
        return X;//尾递归
    else 
        return S[X] = Find(S,S[X]);//先找到根，再把根变成X的父节点，再返回根

}

void Union(SetType S, SetName Root1,SetName Root2){
    //默认R1 和R2是不同集合的根节点
    //S[Root] = -树高
    if(S[Root2] < S[Root1])   //因为是负数,集合里面R2的高度大于R1的高度 
        S[Root1] = Root2;
    else{
        if(S[Root1] == S[Root2]) //两者等高
            S[Root1]--;//树高加一 
        S[Root2] = Root1;//最后结果存在R1里面
    }

} 


void Input_connection(SetType S){
    ElementType u,v;
    SetName Root1,Root2;
    scanf("%d %d\n",&u,&v);
    Root1 = Find(S,u-1);//机器是从1-N编号，而数组从下标0开始
    Root2 = Find(S,v-1);
    if(Root1 != Root2)
        Union(S,Root1,Root2);
}

void Check_connection(SetType S)
{
    ElementType u,v;
    SetName Root1,Root2;
    scanf("%d %d\n",&u,&v);
    Root1 = Find(S,u-1);//机器是从1-N编号，而数组从下标0开始
    Root2 = Find(S,v-1);
    if(Root1 == Root2)
        printf("已经连通了\n");
    else 
        printf("NO\n");

}

void Check_network(SetType S,int n)
{
    int i,counter = 0;
    for(i=0;i<n;i++){
        if(S[i] < 0)
            //小于0 就是一个父结点
            counter++;
    }
    if(counter == 1)
        printf("网络是联通的\n");
    else
        printf("No,have %d\n",counter);
}
void Initialization(SetType S,int n){
    int i;
    for(i = 0;i<n;i++){
        S[i] = -1;//做集合的初始化
    }

}

int main(){
    SetType S;//需要一个集合
    int n;//集合里面元素的个数
    char in;//读指令，第一个字符指令命名为in
    scanf("%d\n",&n);//读进来个数
    Initialization(S,n);//把集合S做一个初始化，把S里面的每一个元素都定义成-1
    do{
        scanf("%c",&in);
        switch(in){
            case 'I': Input_connection(S);//把两台需要连接的连一根网线
                break;
            case 'C': Check_connection(S);//检查是否连接
                break;
            case 's': Check_network(S,n);//检查网络的连通性，数一下看下多少个根节点
                break;
        }

    }while(in != 'S');
    return 0;

}
