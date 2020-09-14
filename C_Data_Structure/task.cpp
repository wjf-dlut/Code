#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TreeSize 100 //树中结点数目
typedef char TElemType;
typedef int Status;

/*二叉树的链式存储---二叉链表*/
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
    printf("请按照先序序列输入二叉树（以”#”代表空结点）：\n");
    CreatBT(T);
    PreOrderTraverse(T);
    ExchangeBT(T);
    printf("\n交换左右孩子后的二叉树的先序序列为：\n");
    PreOrderTraverse(T);
    printf("\n请输入要统计叶子数的子树的根x:");
    fflush(stdin);
    scanf("%c", &x);
    temp = SearchD(T, x);
    CountLeaf(T, x, count);
    printf("以%c为根的子树的叶子数为：%d", x, count);
    printf("\n按树状打印的二叉树为：\n");
    DispBiTree(T, 0);
    system("pause");
    return 0;
}

/*按先序遍历序列建立二叉树的二叉链表*/
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
/*交换左右孩子*/
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
/*找数据域为x的结点*/
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
/*数叶子*/
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
/*按树状打印二叉树*/
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
/*二叉树的递归遍历算法*/
void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        printf("%c\t", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}