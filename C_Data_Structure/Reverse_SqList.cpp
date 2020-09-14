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

typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

Status InitList_Sq(SqList &L);                      //创建空列表函数原型
Status Reverse_Sq(SqList &L);                       //将顺序表逆置函数原型
Status ListInsert_Sq(SqList &L, int i, ElemType e); //插入元素函数原型
Status ListTraverse_Sq(SqList L);                   //显示顺序表函数原型

int main(void)
{
    SqList L;
    ElemType e;
    char Choice_1;
    int i = 1, status;
    printf("是否创建空顺序表:");
    printf("Y.是\t N.否\n");
    scanf("%c", &Choice_1);
    fflush(stdin);
    while (Choice_1 != 'Y' && Choice_1 != 'N')
    {
        printf("请选择Y/N：");
        scanf("%c", &Choice_1);
        fflush(stdin);
    }
    if (Choice_1 == 'Y')
    {
        InitList_Sq(L);
        if (InitList_Sq(L) == OK)
        {
            printf("创建空顺序表成功\n");
            printf("请输入元素(任意字符结束输入)：");
            status = scanf("%d", &e);
            fflush(stdin);
            while (status == OK)
            {
                if (ListInsert_Sq(L, i, e) == OK)
                {
                    printf("插入成功，请输入元素(任意字符结束输入):");
                    status = scanf("%d", &e);
                    fflush(stdin);
                    i++;
                }
                else
                {
                    printf("插入失败.\n");
                    break;
                }
            }
            printf("顺序表中的元素为：");
            ListTraverse_Sq(L);
            Reverse_Sq(L);
            printf("逆置后的元素为：");
            ListTraverse_Sq(L);
        }
        else
        {
            printf("创建空顺序表失败\n");
        }
    }
    if (Choice_1 == 'N')
    {
        printf("Bye");
    }

    system("pause");
    return 0;
}

/*创建空顺序表L*/
Status InitList_Sq(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
    {
        exit(OVERFLOW);
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

/*将顺序表逆序*/
Status Reverse_Sq(SqList &L)
{
    ElemType *p, *q, temp;
    p = L.elem;
    q = L.elem + L.length - 1;
    while (p < q)
    {
        temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
    return OK;
}
/*在顺序表中按顺序插入元素*/
Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    ElemType *p, *q, *newbase;
    // if (i<1||i>L.length+1)
    // {
    //     return ERROR;
    // }
    if (L.length >= L.listsize)
    {
        newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
            exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    // p = &(L.elem[L.length-1]);
    q = &(L.elem[i - 1]);
    // for(;p>=q;p--)
    //     *(p+1)=*p;
    *q = e;
    ++L.length;
    return OK;
}
/*显示顺序表中的元素*/
Status ListTraverse_Sq(SqList L)
{
    int i = 0;
    if (!L.elem)
        return ERROR;
    while (i < L.length)
        printf("%d ", L.elem[i++]);
    printf("\n");
    return OK;
}