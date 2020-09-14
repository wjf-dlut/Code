#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int SElemType;
typedef int Status;

/*定义动态顺序栈*/
typedef int SElemType;
#define STACK_INIT_SIZE 100 //顺序栈存储空间的初始分配量
#define STACKINCREMENT 10   //顺序栈存储空间的分配增量
typedef struct
{
    SElemType *base; //存储空间的基址，栈底指针
    SElemType *top;  //栈顶指针
    int stacksize;   //当前分配的存储容量
} SqStack;
/*顺序栈结构初始化*/
Status InitStack(SqStack &S)
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}
/*取栈顶元素*/
Status GetTop(SqStack S, SElemType &e)
{
    if (S.top == S.base) //判断栈是否为空
        return ERROR;
    e = *(S.top - 1);
    return OK;
}
/*元素出栈*/
Status Pop(SqStack &S, SElemType &e)
{
    if (S.top == S.base) //判断栈是否为空
        return ERROR;
    e = *--S.top;
    return OK;
}
/*元素入栈*/
Status Push(SqStack &S, SElemType e)
{
    if (S.top - S.base >= S.stacksize) //判断是否栈满
    {
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

/*链栈*/
typedef struct SNode //结点定义
{
    SElemType data;
    struct SNode *next;
} SNode, *StackPtr;

typedef struct //链栈定义
{
    StackPtr top;
} LinkStack;

/*入栈算法*/
Status Push(LinkStack &S, SElemType e)
{
    SNode *p;
    p = (StackPtr)malloc(sizeof(SNode));
    if (!p)
        return ERROR;
    p->data = e;
    p->next = S.top;
    S.top = p;
    return OK;
}
/*出栈算法*/
Status Pop(LinkStack &S, SElemType &e)
{
    SNode *p;
    if(S.top==NULL)
        return ERROR;
    p=S.top;
    e=p->data;
    S.top=p->next;
    free(p);
    return OK;
}