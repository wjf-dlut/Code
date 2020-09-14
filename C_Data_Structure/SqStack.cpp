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

/*���嶯̬˳��ջ*/
typedef int SElemType;
#define STACK_INIT_SIZE 100 //˳��ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT 10   //˳��ջ�洢�ռ�ķ�������
typedef struct
{
    SElemType *base; //�洢�ռ�Ļ�ַ��ջ��ָ��
    SElemType *top;  //ջ��ָ��
    int stacksize;   //��ǰ����Ĵ洢����
} SqStack;
/*˳��ջ�ṹ��ʼ��*/
Status InitStack(SqStack &S)
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}
/*ȡջ��Ԫ��*/
Status GetTop(SqStack S, SElemType &e)
{
    if (S.top == S.base) //�ж�ջ�Ƿ�Ϊ��
        return ERROR;
    e = *(S.top - 1);
    return OK;
}
/*Ԫ�س�ջ*/
Status Pop(SqStack &S, SElemType &e)
{
    if (S.top == S.base) //�ж�ջ�Ƿ�Ϊ��
        return ERROR;
    e = *--S.top;
    return OK;
}
/*Ԫ����ջ*/
Status Push(SqStack &S, SElemType e)
{
    if (S.top - S.base >= S.stacksize) //�ж��Ƿ�ջ��
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

/*��ջ*/
typedef struct SNode //��㶨��
{
    SElemType data;
    struct SNode *next;
} SNode, *StackPtr;

typedef struct //��ջ����
{
    StackPtr top;
} LinkStack;

/*��ջ�㷨*/
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
/*��ջ�㷨*/
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