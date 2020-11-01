/*给出一个集合，以及一个测试数，
求给集合的子集的和是否等于该数（如：给出 7 10 11 20 9，
以及需要等于的数16，则输出ture，给出15则输出false）*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*用一个二维数组来保存结果，避免重复过程。
如下图，填完后输出右下角值（opt[n-1][key])
(key值为5，p数组：10，5，2，7，9）*/

int solve_dp(int *p,int n,int key){

    int i,j;

}


int main(){

    int arr[] = {1,2,4,1,7,8,3};

    int max;
    max = DP(arr,6);
    printf("%d",max);
    system("pause");
    return 0;
}