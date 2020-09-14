#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE 01
#define OVERFLOW -2
#define MAXQSIZE 100 //�����г���
#define LISTINCREMENT 10
typedef int Status;
typedef int QElemType;

typedef struct
{
    QElemType *base; //�洢�ռ��ַ
    int front;       //��ͷָ�룬�����в��գ�ָ���ͷԪ��
    int rear;        //��βָ�룬�����в��գ�ָ���βԪ�ص���һ��λ��
} SqQuene;
 
 /*ѭ�����г�ʼ��*/
 Status InitQueue(SqQuene &Q)
 {
     Q.base = (QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
     if(!Q.base)
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
 }
 /*����ѭ�����г���*/
 int QueueLength(SqQuene Q)
 {
    return(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
 }
 /*ѭ������Ԫ�����*/
 Status EnQueue(SqQuene &Q, QElemType e)
 {
    if((Q.rear+1)%MAXQSIZE==Q.front)
        return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return OK;
 }
 /*ѭ������Ԫ�س���*/
 Status DeQueue(SqQuene &Q, QElemType &e)
 {
    if(Q.front == Q.rear)
        return ERROR;
    e= Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return OK;
 }