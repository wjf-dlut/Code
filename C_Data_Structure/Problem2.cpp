#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct node
{
    ElemType data;
    struct node *link;
} LNode, *LinkList;

void CreateList(LinkList &L, int n);
Status PrintList(LinkList L);
Status ListInsert(LinkList L, ElemType e);
void NizhiList(LinkList L);
Status DelList(LinkList &L, ElemType mink, ElemType maxk);

int main(void)
{
    int choice_1 = 0, n, status;
    LinkList L;
    ElemType e, mink, maxk;
    do
    {
        printf("\n********************************\n");
        printf("���������ֱ��ѡ�����(���������ַ���������)��\n");
        printf("1.������ͷ���ĵ�����\n");
        printf("2.��ʾ������\n");
        printf("3.�����������в���Ԫ��\n");
        printf("4.������͵�����\n");
        printf("5.������������ɾ������ֵ����mink��С��maxk��Ԫ��\n");
        printf("��������ѡ��Ĳ�����ţ�");
        status = scanf("%d", &choice_1);
        fflush(stdin);

        switch (choice_1)
        {
        case 1:
            printf("������Ҫ�����ĵ�������Ҫ������Ԫ�ظ�����");
            scanf("%d", &n);
            fflush(stdin);
            CreateList(L, n);
            printf("�ɹ���������%d��Ԫ�صĵ�����", n);
            PrintList(L);
            break;
        case 2:
            printf("������Ϊ��");
            PrintList(L);
            break;
        case 3:
            printf("������Ҫ�ڵ������в����Ԫ��ֵ��");
            scanf("%d", &e);
            fflush(stdin);
            ListInsert(L, e);
            printf("��ǰ������Ϊ��");
            PrintList(L);
            break;
        case 4:
            printf("���ú�ĵ�����Ϊ:");
            NizhiList(L);
            PrintList(L);
            break;
        case 5:
            printf("������mink:");
            scanf("%d", &mink);
            fflush(stdin);
            printf("������maxk:");
            scanf("%d", &maxk);
            fflush(stdin);
            DelList(L, mink, maxk);
            printf("ִ�в�����ĵ�����Ϊ��");
            PrintList(L);
        default:
            break;
        }
    } while (status);
}

/*������ͷ���ĵ�����*/
void CreateList(LinkList &L, int n)
{
    LinkList p, s;
    int i;
    L = (LinkList)malloc(sizeof(LNode));
    L->data = 0;
    L->link = NULL;
    s = L;
    printf("�밴��������%d������:", n);
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->link = NULL;
        s->link = p;
        s = p;
    }
}

/*��ʾ������*/
Status PrintList(LinkList L)
{
    LinkList p;
    p = L->link;
    printf("H->");
    while (p)
    {
        printf("%d", p->data);
        p = p->link;
        if (p)
        {
            printf("->");
        }
    }
    return OK;
}

/*�����������в���Ԫ��x*/
Status ListInsert(LinkList L, ElemType e)
{
    LinkList p = L->link, q, pre;
    q = (LinkList)malloc(sizeof(LNode));
    q->data = e;
    pre = L;
   
    if (p->data < p->link->data)  //�жϵ������������ǽ���
    {
        while (p && p->data < e)
        {
            pre = p;
            p = p->link;
        }
        if (!p ||e != p->data)
        {
            pre->link = q;
            q->link = p;
            return OK;
        }
        printf("��������������Ԫ��\n");
    }
    else
    {
        while (p && e < p->data)
        {
            pre = p;
            p = p->link;
        }
        if (!p ||e != p->data)
        {
            pre->link = q;
            q->link = p;
            return OK;
        }
        printf("��������������Ԫ��\n");
    }
    return (ERROR);
}
/*������͵�����*/
void NizhiList(LinkList L)
{
    LinkList p = L->link, q = L->link->link, pre, u;
    p->link = NULL;
    while (q)
    {
        p = L->link;
        pre = L;
        while (p && q->data < p->data)
        {
            pre = p;
            p = p->link;
        }
        u = q->link;
        pre->link = q;
        q->link = p;
        q = u;
    }
}
/*������������ɾ������ֵ����mink��С��maxk��Ԫ��*/
Status DelList(LinkList &L, ElemType mink, ElemType maxk)
{
    LinkList p = L, q = L->link, temp;
    while (q)
    {
        if (q->data <= mink || q->data >= maxk)
        {
            p->link = q;
            p = q;
            q = q->link;
        }
        else
        {
            temp= q;
            q = q->link;
            free(temp);
        }
    }
    return OK;
}