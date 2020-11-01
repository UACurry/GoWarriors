#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int ElementType; 

typedef struct LNode{
    ElementType Element[MAXSIZE];
    int Length;
}*List;

int SequentailSearch(List Tbl,ElementType K){

//设置哨兵的顺序查找
    int i;
    Tbl->Element[0] = K; //设置哨兵
    for(i = Tbl->Length;Tbl->Element[i] != K; i--)
        return i; //查找成功贼返回所在单元，不成功返回0
}

int BinarySearch(List Tbl,ElementType K){
    //在Tbl表种查找关键字为K的数据元素
    int left,right,mid,NoFound = -1;

    left = 1;//初始左边界
    right = Tbl->Length; //初始右边界
    while(left <= right){//左边界小于右边界，成立的条件，否则不符合
        mid = (left+right)/2; //计算中间元素坐标
        if(K < Tbl->Element[mid])
            right = mid -1;//调整右边界
        else if (K > Tbl->Element[mid])
            left = mid +1;
        else 
            return mid;
    }
    return NoFound;
}