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

Status InitList_Sq(SqList &L);                      //�������б���ԭ��
Status Reverse_Sq(SqList &L);                       //��˳������ú���ԭ��
Status ListInsert_Sq(SqList &L, int i, ElemType e); //����Ԫ�غ���ԭ��
Status ListTraverse_Sq(SqList L);                   //��ʾ˳�����ԭ��

int main(void)
{
    SqList L;
    ElemType e;
    char Choice_1;
    int i = 1, status;
    printf("�Ƿ񴴽���˳���:");
    printf("Y.��\t N.��\n");
    scanf("%c", &Choice_1);
    fflush(stdin);
    while (Choice_1 != 'Y' && Choice_1 != 'N')
    {
        printf("��ѡ��Y/N��");
        scanf("%c", &Choice_1);
        fflush(stdin);
    }
    if (Choice_1 == 'Y')
    {
        InitList_Sq(L);
        if (InitList_Sq(L) == OK)
        {
            printf("������˳���ɹ�\n");
            printf("������Ԫ��(�����ַ���������)��");
            status = scanf("%d", &e);
            fflush(stdin);
            while (status == OK)
            {
                if (ListInsert_Sq(L, i, e) == OK)
                {
                    printf("����ɹ���������Ԫ��(�����ַ���������):");
                    status = scanf("%d", &e);
                    fflush(stdin);
                    i++;
                }
                else
                {
                    printf("����ʧ��.\n");
                    break;
                }
            }
            printf("˳����е�Ԫ��Ϊ��");
            ListTraverse_Sq(L);
            Reverse_Sq(L);
            printf("���ú��Ԫ��Ϊ��");
            ListTraverse_Sq(L);
        }
        else
        {
            printf("������˳���ʧ��\n");
        }
    }
    if (Choice_1 == 'N')
    {
        printf("Bye");
    }

    system("pause");
    return 0;
}

/*������˳���L*/
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

/*��˳�������*/
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
/*��˳����а�˳�����Ԫ��*/
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
/*��ʾ˳����е�Ԫ��*/
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