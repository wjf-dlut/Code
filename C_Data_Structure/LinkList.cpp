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

//单链表结点结构
typedef struct node
{
    ElemType data;     //数据域
    struct node *link; //指针域
} LNode, *LinkList;

/*常用操作*/
// LinkList p;                          //定义指针p
// p = (LinkList)malloc(sizeof(Lnode)); //生成新结点
// free(p);                             //释放结点p
// p = L->link;                         //p指向头节点
// p = p->link;                         //p向后移动

/*查找单链表中是否存在数据域为e的结点，若有则返回该节点的指针；否则返回NULL*/
LinkList dlbcz(LinkList L, ElemType e)
{
    LinkList p = L->link;
    while (p != NULL && p->data != e)
    {
        p = p->link;
    }
    return (p);
}

/*查找：取单链表中第i个元素的值，若存在该元素，用e返回其值；否则返回ERROR*/
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

/*插入：在单链表L的第i个元素之前插入新元素e*/
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
/*删除：删除单链表L的第i个结点*/
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
/*就地升序排序：将单链表L中的结点按数据域进行升序排序，要求在原链表上修改*/
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
/*动态建立单链表：输入n个数据，建立单链表L*/
/*头插法*/
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
/*尾插法*/
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