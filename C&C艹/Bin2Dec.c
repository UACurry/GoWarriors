#include <stdbool.h>
#include <stdio.h>
#include <math.h>


#define STACK_INIT_SIZE 20
#define DECRECENTMENT 10

typedef char ElemType;
typedef struct 
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;


void Initstack(sqStack *s)
{
   s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
   if (!s->base)
   {
       exit(0);
   }
   s->top = s->base;
   s->stacksize = STACK_INIT_SIZE;

}

void Push(sqStack *s,ElemType e)
{
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (ElemType *)realloc(s->base,(s->stacksize +DECRECENTMENT)*sizeof(ElemType));
        if (!s->base)
        {
            exit(0);
        }
        
    }
    

    *(s->top) = e;
    s->top++;

}

void Pop(sqStack *s,ElemType *e)
{
    if(s->top == s->base)
    {
        return;
    }
    *e = *--(s->top);

}

int StackLen(sqStack s)
{
    return(s.top - s.base);
}


int main()
{
    ElemType c;
    sqStack s;
    int len,i, sum = 0;

    printf("请输入二进制数，输入#表示结束\n");
    scanf("%c",&c);
    while (c!='#')
    {
        Push(&s,c);
        scanf("%c",&c);
    }

    getchar();

    len = StackLen(s);
    printf("栈的当前容量：%d\n",len);

    for ( i = 0; i < len; i++)
    {
        Pop(&s,&c);
        sum = sum +(c-48)*pow(2,i);

    }
    printf("转化为十进制数是：%d\n",sum);


    return 0;
}