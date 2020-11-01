#include <stdio.h>
#include <stdlib.h>

//汉诺塔
void Hanoi_Tower(int n, char A, char B, char C)
{

    if (n == 1)
    {
        //递归出口
        printf("%c -> %c\n", A, C);
    }
    //把n-1块从A 通过C 放到B
    else
    {
        Hanoi_Tower(n - 1, A, C, B);
        printf("%c -> %c\n", A, C);  //把最大的先放到C
        Hanoi_Tower(n - 1, B, A, C); //把n-1通过A,放到C
    }
}

int main()
{
    Hanoi_Tower(7, 'A', 'B', 'C');
    system("pause");
    return 0;
}