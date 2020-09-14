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
        printf("请输入数字编号选择操作(输入任意字符结束程序)：\n");
        printf("1.建立带头结点的单链表\n");
        printf("2.显示单链表\n");
        printf("3.在有序单链表中插入元素\n");
        printf("4.单链表就地逆置\n");
        printf("5.在有序单链表中删除所有值大于mink且小于maxk的元素\n");
        printf("请输入您选择的操作序号：");
        status = scanf("%d", &choice_1);
        fflush(stdin);

        switch (choice_1)
        {
        case 1:
            printf("请输入要建立的单链表中要包含的元素个数：");
            scanf("%d", &n);
            fflush(stdin);
            CreateList(L, n);
            printf("成功创建含有%d个元素的单链表：", n);
            PrintList(L);
            break;
        case 2:
            printf("单链表为：");
            PrintList(L);
            break;
        case 3:
            printf("请输入要在单链表中插入的元素值：");
            scanf("%d", &e);
            fflush(stdin);
            ListInsert(L, e);
            printf("当前单链表为：");
            PrintList(L);
            break;
        case 4:
            printf("逆置后的单链表为:");
            NizhiList(L);
            PrintList(L);
            break;
        case 5:
            printf("请输入mink:");
            scanf("%d", &mink);
            fflush(stdin);
            printf("请输入maxk:");
            scanf("%d", &maxk);
            fflush(stdin);
            DelList(L, mink, maxk);
            printf("执行操作后的单链表为：");
            PrintList(L);
        default:
            break;
        }
    } while (status);
}

/*建立带头结点的单链表*/
void CreateList(LinkList &L, int n)
{
    LinkList p, s;
    int i;
    L = (LinkList)malloc(sizeof(LNode));
    L->data = 0;
    L->link = NULL;
    s = L;
    printf("请按升序输入%d个数据:", n);
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->link = NULL;
        s->link = p;
        s = p;
    }
}

/*显示单链表*/
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

/*在有序单链表中插入元素x*/
Status ListInsert(LinkList L, ElemType e)
{
    LinkList p = L->link, q, pre;
    q = (LinkList)malloc(sizeof(LNode));
    q->data = e;
    pre = L;
   
    if (p->data < p->link->data)  //判断单链表是升序还是降序
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
        printf("不允许输入已有元素\n");
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
        printf("不允许输入已有元素\n");
    }
    return (ERROR);
}
/*单链表就地逆置*/
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
/*在有序单链表中删除所有值大于mink且小于maxk的元素*/
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