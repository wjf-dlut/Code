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
typedef int ElemType;

//��������ṹ
typedef struct node
{
    ElemType data;     //������
    struct node *link; //ָ����
} LNode, *LinkList;

/*���ò���*/
// LinkList p;                          //����ָ��p
// p = (LinkList)malloc(sizeof(Lnode)); //�����½��
// free(p);                             //�ͷŽ��p
// p = L->link;                         //pָ��ͷ�ڵ�
// p = p->link;                         //p����ƶ�

/*���ҵ��������Ƿ����������Ϊe�Ľ�㣬�����򷵻ظýڵ��ָ�룻���򷵻�NULL*/
LinkList dlbcz(LinkList L, ElemType e)
{
    LinkList p = L->link;
    while (p != NULL && p->data != e)
    {
        p = p->link;
    }
    return (p);
}

/*���ң�ȡ�������е�i��Ԫ�ص�ֵ�������ڸ�Ԫ�أ���e������ֵ�����򷵻�ERROR*/
Status GetElem_L(LinkList L, int i, ElemType &e)
{
    LinkList p = L->link;
    int j = 1;
    while (p && j < i)
    {
        p = p->link;
        j++;
    }
    if (p == NULL || j > i)
    {
        return ERROR;
    }
    e = p->data;
    return OK;
}

/*���룺�ڵ�����L�ĵ�i��Ԫ��֮ǰ������Ԫ��e*/
Status ListInsert_L(LinkList L, int i, ElemType e)
{
    LinkList p = L, s;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->link;
        ++j;
    }
    if (p == NULL || j > i - 1)
    {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->link = p->link;
    p->link = s;
    return OK;
}
/*ɾ����ɾ��������L�ĵ�i�����*/
Status ListDeltete_L(LinkList L, int i, ElemType &e)
{
    LinkList p = L, q;
    int j = 0;
    while (p->link && j, i - 1)
    {
        p = p->link;
        ++j;
    }
    if (p->link == NULL || j > i - 1)
    {
        return ERROR;
    }
    q = p->link;
    p->link = q->link;
    e = q->data;
    free(q);
    return OK;
}
/*�͵��������򣺽�������L�еĽ�㰴�����������������Ҫ����ԭ�������޸�*/
void sh_sort(LinkList L)
{
    LinkList p = L->link,q=L->link->link,pre,u;
    p->link=NULL;
    while (q)
    {
        p=L->link;
        pre = L;
        while (p && p->data<q->data)
        {
            pre = p;
            p = p->link;
        }
        u  = q->link;
        pre->link = q;
        q->link = p;
        q = u;
    }
}
/*��̬��������������n�����ݣ�����������L*/
/*ͷ�巨*/
void Create_L1(LinkList &L, int n)
{
    LinkList p; int i;
    L=(LinkList)malloc(sizeof(LNode));
    L->data = 0;
    L->link = NULL;
    for(i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->link = L->link;
        L->link = p;
    }
}
/*β�巨*/
void Create_L2(LinkList &L, int n)
{
    LinkList p, s = L;
    int i;
    L = (LinkList)malloc(sizeof(LNode));
    L->data = 0;
    L->link = NULL;
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->link = NULL;
        s->link = p;
        s = p;
    }
}