#include <stdio.h>
#include <time.h>


#define X 8
#define Y 8

//声明一个棋盘的全局变量，到处调用。默认初始化为0
int chess[X][V];


//查找马基于(x,y)的下一个位置,count = 8 马在一个位置有八种可以跳的方法
int nextXY(int *x,int *y,int count){

    switch(count){
        case 0:
            if(*x+2 <= X-1 && *y-1 >= 0 && chess[*x+2][*y-1] == 0){
                //向右上方跳，不能跳到棋盘外面
                //且没有被遍历过
                *x += 2;
                *y -= 1;
                return 1;//马就走向下一个
            }
            break;
        case 1:
            if(*x+2 <= X-1 && *y+1 <= Y-1 && chess[*x+2][*y-1] == 0){
                //向右上方跳，不能跳到棋盘外面
                //且没有被遍历过
                *x += 2;
                *y += 1;
                return 1;//马就走向下一个
            }
            break;
        case 2:
            if(*x+2 <= X-1 && *y-2 >= 0 && chess[*x+2][*y-1] == 0){
                //向右上方跳，不能跳到棋盘外面
                //且没有被遍历过
                *x += 2;
                *y += 1;
                return 1;//马就走向下一个
            }
            break;
        case 3:
            if(*x+2 <= X-1 && *y-1 >= 0 && chess[*x+2][*y-1] == 0){
                //向右上方跳，不能跳到棋盘外面
                //且没有被遍历过
                *x += 2;
                *y -= 1;
                return 1;//马就走向下一个
            }
            break;
        case 4:
            if(*x+2 <= X-1 && *y-1 >= 0 && chess[*x+2][*y-1] == 0){
                //向右上方跳，不能跳到棋盘外面
                //且没有被遍历过
                *x += 2;
                *y -= 1;
                return 1;//马就走向下一个
            }
            break;
        case 5:
            if(*x+2 <= X-1 && *y-1 >= 0 && chess[*x+2][*y-1] == 0){
                //向右上方跳，不能跳到棋盘外面
                //且没有被遍历过
                *x += 2;
                *y -= 1;
                return 1;//马就走向下一个
            }
            break;
        case 6:
            if(*x+2 <= X-1 && *y-1 >= 0 && chess[*x+2][*y-1] == 0){
                //向右上方跳，不能跳到棋盘外面
                //且没有被遍历过
                *x += 2;
                *y -= 1;
                return 1;//马就走向下一个
            }
            break;
        case 7:
            if(*x+2 >= 0 && *y+2 <= Y-1 && chess[*x-1][*y+2] == 0){
                //向右上方跳，不能跳到棋盘外面
                //且没有被遍历过
                *x += 2;
                *y -= 1;
                return 1;//马就走向下一个
            }
            break;
}


void Travel(int x,int y,int tag){
     
}


