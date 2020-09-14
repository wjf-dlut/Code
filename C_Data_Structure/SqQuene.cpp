#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE 01
#define OVERFLOW -2
#define MAXQSIZE 100 //最大队列长度
#define LISTINCREMENT 10
typedef int Status;
typedef int QElemType;

typedef struct
{
    QElemType *base; //存储空间基址
    int front;       //队头指针，若队列不空，指向对头元素
    int rear;        //队尾指针，若队列不空，指向队尾元素的下一个位置
} SqQuene;
 
 /*循环队列初始化*/
 Status InitQueue(SqQuene &Q)
 {
     Q.base = (QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
     if(!Q.base)
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
 }
 /*计算循环队列长度*/
 int QueueLength(SqQuene Q)
 {
    return(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
 }
 /*循环队列元素入队*/
 Status EnQueue(SqQuene &Q, QElemType e)
 {
    if((Q.rear+1)%MAXQSIZE==Q.front)
        return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return OK;
 }
 /*循环队列元素出队*/
 Status DeQueue(SqQuene &Q, QElemType &e)
 {
    if(Q.front == Q.rear)
        return ERROR;
    e= Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return OK;
 }