//把一个罗马数字转换成阿拉伯数字
//七个拉丁字母，没有0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 7

char digits[N] = {'I','V','X','L','C','D','M'};
int values[N] = {1,5,10,50,100,500,1000};

//将罗马数字转化为阿拉伯数字
int digitsToValues(char ch){
    int i;
    for(i=0;i<N;i++){
        if(digits[i] == ch){
            return values[i];
        }
    }
    return 0;
}

//找到一串罗马数字中最大的罗马数字的下标
int FindMaxindex(char str[],int L,int R){
    int max = digitsToValues(str[L]);
    int maxIndex = L;
    int i;
    for(i=0;i<=R;i++){
        int num = digitsToValues(str[i]);
        if(digitsToValues(str[i]) > max){
            max = num;
            maxIndex = i;
        }
    }
    return maxIndex;
}

//罗马数字转换为阿拉伯数字，用分而治之的思想
int romanToNumber(char str[],int L,int R){
    if(L=R){
        return digitsToValues(str[L]);
    }
    else if (L > R)
    {
        return 0;
    }
    else
    {
        int mi = FindMaxindex(str,L,R);
        int max = digitsToValues(str[mi]);
        int left = romanToNumber(str,L,mi-1);
        int right = romanToNumber(str,mi+1,R);
        return max - left + right;
    }
}