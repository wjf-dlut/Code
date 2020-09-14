/*线性表的动态存储顺序存储结构*/
#include <stdio.h>
#include <stdlib.h>
// #include<malloc.h>

#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10   //线性表存储空间的分配增量

typedef int ElemType; //元素类型
typedef struct
{
    ElemType *elem; //存储空间基址
    int length;     //长度
    int listsize;   //容量
} Sqlist;
/*申请长度为n的整型数组空间*/
void main(void)
{
    int *p, n;
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    free(p);
}
/*构造一个空顺序表L*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10   //线性表存储空间的分配增量

typedef int ElemType; //元素类型
typedef struct
{
    ElemType *elem; //存储空间基址
    int length;     //长度
    int listsize;   //容量
} SqList;

typedef int Status;
Status lnitList_Sq(SqList &L)
{
    //动态申请顺序表
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    //判断是否申请成功
    if (!L.elem)
        exit(OVERFLOW);
    //设置表长及容量
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}
/*在线性表L中查找是否存在数据元素e，返回第一个值与
e相同的元素的位序，若不存在则返回0*/
int LocationElem(Sqlist L, ElemType e)
{
    int i = 1;
    ElemType *p = L.elem;
    while (*p != e && i <= L.length)
    {
        i++;
        p++;
    }
    if (i <= L.length)
    {
        return i;
    }
    else
    {
        return 0;
    }
}
/*在线性表L的第i(1<=i<=i+1)个元素之前插入了一个新的元素e*/
Status ListInsert(SqList &L, int i, ElemType e)
{
    ElemType *p, *q, *newbase;
    //判断插入位置i是否合法
    if (i < 1 || i > L.length + 1)
    {
        return ERROR;
    }
    //若存储空间已满，则需增大
    if (L.length >= L.listsize)
    {
        newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
            exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }

    p = &(L.elem[L.length - 1]);
    q = &(L.elem[i - 1]);
    //元素后移
    for (; p >= q; p--)
        *(p + 1) = *p;
    //插入
    *q = e;
    // 线性表长度加1
    ++L.length;
    return OK;
}
/*将线性表L的第i个元素删除*/
Status ListDelete(SqList &L, int i, ElemType &e)
{
    ElemType *p, *q;
    //判断i是否合法
    if (i < 1 || i > L.length)
        return (ERROR);
    p = &(L.elem[i - 1]);      //记录删除位置
    e = *p;                    //记录被删除元素
    q = L.elem + L.length - 1; //记录表尾位置
    for (p++; p <= q; p++)     //元素前移
        *(p - 1) = *p;
    --L.length; //线性表长度-1
    return OK;
}
