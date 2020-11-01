#include <stdio.h>

int MaxSubseqSum ( int A [],int N)
{
    int MaxSum,ThisSum;
    int i;
    
    MaxSum = ThisSum = 0;
    for(i= 0;i<N;i++){
        ThisSum += A[i];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
        
    }
    return MaxSum;


}