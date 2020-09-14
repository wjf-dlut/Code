#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE 01
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int Status;
typedef int QElemType;

/*��㶨��*/
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
/*����������*/
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;
/*���ն���*/
Status InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(OVERFLOW);
    Q.front->next = NULL;
    return (OK);
}
/*���*/
Status EnQueue(LinkQueue &Q, QElemType &e)
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}
/*����*/
Status DeQueue(LinkQueue &Q, QElemType &e)
{
    QueuePtr p;
    if (Q.front == Q.rear)
        return ERROR;
    p = Q.front->next;
    e = p->data;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return OK;
}
