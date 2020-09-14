#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TreeSize 100 //���н����Ŀ
typedef char TElemType;
typedef int Status;

/*����������ʽ�洢---��������*/
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Status CreatBT(BiTree &T);
void ExchangeBT(BiTree T);
int CountLeaf(BiTree T, TElemType x, int &count);
void DispBiTree(BiTree T, int level);
void PreOrderTraverse(BiTree T);
BiTree SearchD(BiTree T, TElemType x);

int main(void)
{
    BiTree T, temp;
    TElemType x;
    int count = 0;
    printf("�밴����������������������ԡ�#������ս�㣩��\n");
    CreatBT(T);
    PreOrderTraverse(T);
    ExchangeBT(T);
    printf("\n�������Һ��Ӻ�Ķ���������������Ϊ��\n");
    PreOrderTraverse(T);
    printf("\n������Ҫͳ��Ҷ�����������ĸ�x:");
    fflush(stdin);
    scanf("%c", &x);
    temp = SearchD(T, x);
    CountLeaf(T, x, count);
    printf("��%cΪ����������Ҷ����Ϊ��%d", x, count);
    printf("\n����״��ӡ�Ķ�����Ϊ��\n");
    DispBiTree(T, 0);
    system("pause");
    return 0;
}

/*������������н����������Ķ�������*/
Status CreatBT(BiTree &T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        T = NULL;
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data = ch;
        CreatBT(T->lchild);
        CreatBT(T->rchild);
    }
    return OK;
}
/*�������Һ���*/
void ExchangeBT(BiTree T)
{
    BiTree temp;
    if (T)
    {
        temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
        ExchangeBT(T->lchild);
        ExchangeBT(T->rchild);
    }
}
/*��������Ϊx�Ľ��*/
BiTree SearchD(BiTree T, TElemType x)
{
    BiTree temp;
    if (T)
    {
        if (T->data == x)
            return T;
        temp = SearchD(T->lchild, x);
        if (temp == NULL)
            temp = SearchD(T->rchild, x);
        return temp;
    }
    return NULL;
}
/*��Ҷ��*/
int CountLeaf(BiTree T, TElemType x, int &count)
{
    // BiTree temp;
    // temp = SearchD(T, x);
    if (T)
    {
        if ((T->lchild == NULL) && (T->rchild == NULL))
            count++;
        CountLeaf(T->lchild, x, count);
        CountLeaf(T->rchild, x, count);
    }
}
/*����״��ӡ������*/
void DispBiTree(BiTree T, int level)
{
    int i;
    if (T)
    {
        DispBiTree(T->rchild, level + 1);
        for (i = 0; i < level; i++)
            printf("#");
        printf("%c\n", T->data);
        DispBiTree(T->lchild, level + 1);
    }
}
/*�������ĵݹ�����㷨*/
void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        printf("%c\t", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}