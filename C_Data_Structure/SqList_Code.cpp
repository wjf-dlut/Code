/*���Ա�Ķ�̬�洢˳��洢�ṹ*/
#include <stdio.h>
#include <stdlib.h>
// #include<malloc.h>

#define LIST_INIT_SIZE 100 //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10   //���Ա�洢�ռ�ķ�������

typedef int ElemType; //Ԫ������
typedef struct
{
    ElemType *elem; //�洢�ռ��ַ
    int length;     //����
    int listsize;   //����
} Sqlist;
/*���볤��Ϊn����������ռ�*/
void main(void)
{
    int *p, n;
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    free(p);
}
/*����һ����˳���L*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100 //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10   //���Ա�洢�ռ�ķ�������

typedef int ElemType; //Ԫ������
typedef struct
{
    ElemType *elem; //�洢�ռ��ַ
    int length;     //����
    int listsize;   //����
} SqList;

typedef int Status;
Status lnitList_Sq(SqList &L)
{
    //��̬����˳���
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    //�ж��Ƿ�����ɹ�
    if (!L.elem)
        exit(OVERFLOW);
    //���ñ�������
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}
/*�����Ա�L�в����Ƿ��������Ԫ��e�����ص�һ��ֵ��
e��ͬ��Ԫ�ص�λ�����������򷵻�0*/
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
/*�����Ա�L�ĵ�i(1<=i<=i+1)��Ԫ��֮ǰ������һ���µ�Ԫ��e*/
Status ListInsert(SqList &L, int i, ElemType e)
{
    ElemType *p, *q, *newbase;
    //�жϲ���λ��i�Ƿ�Ϸ�
    if (i < 1 || i > L.length + 1)
    {
        return ERROR;
    }
    //���洢�ռ���������������
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
    //Ԫ�غ���
    for (; p >= q; p--)
        *(p + 1) = *p;
    //����
    *q = e;
    // ���Ա��ȼ�1
    ++L.length;
    return OK;
}
/*�����Ա�L�ĵ�i��Ԫ��ɾ��*/
Status ListDelete(SqList &L, int i, ElemType &e)
{
    ElemType *p, *q;
    //�ж�i�Ƿ�Ϸ�
    if (i < 1 || i > L.length)
        return (ERROR);
    p = &(L.elem[i - 1]);      //��¼ɾ��λ��
    e = *p;                    //��¼��ɾ��Ԫ��
    q = L.elem + L.length - 1; //��¼��βλ��
    for (p++; p <= q; p++)     //Ԫ��ǰ��
        *(p - 1) = *p;
    --L.length; //���Ա���-1
    return OK;
}
