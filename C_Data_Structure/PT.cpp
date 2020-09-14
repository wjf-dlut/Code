#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define TreeSize 100 //树中结点数目
typedef int TElemType;
typedef int Status;
/*双亲表示法---存储结点之间的双亲关系*/
/*结点结构*/
typedef struct PTNode
{
    TElemType data; //数据域
    int parent;     //双亲域
} PTNode;
/*树结构*/
typedef struct
{
    PTNode nodes[TreeSize]; //结点数组
    int r, n;               //根节点的下标和节点总数
} PTree;
/*孩子表示法---存储结点之间的孩子关系*/
/*孩子结点*/
typedef struct CTNode
{
    int child;
    struct CTNode *next;
} * ChildPtr;
/*数组结点*/
typedef struct
{
    TElemType data;
    ChildPtr firstchild;
} CTBox;
/*树结构*/
typedef struct
{
    CTBox nodes[TreeSize];
    int r, n; //根结点下标、节点总数
} CTree;
/*带双亲的孩子链表*/
/*孩子结点*/
typedef struct CTNode
{
    int child;
    struct CTNode *next;
} * ChildPtr;
/*数组结点*/
typedef struct
{
    TElemType data; //数据域
    int parent;     //双亲域
    ChildPtr firstchild;
} CTBox;
/*树结构*/
typedef struct
{
    CTBox nodes[TreeSize];
    int r, n; //根结点下标、节点总数
} CTree;
/*孩子-兄弟表示法---存储结点之间的孩子及兄弟关系*/
/*将树用这种方法（二叉树表示法）存储，有助于实现树与二叉树之间的转换*/
/*结点结构*/
typedef struct CSnode
{
    TElemType data;                          //数据域
    struct CSnode *firstchild, *nextsibling; //指向第一个孩子、下一个兄弟
} CSNode, *CSTree;

/*二叉树的存储结构*/
/*二叉树的顺序存储结构*/
#define Tree_Size 100 //二叉树中结点数目
typedef TElemType SqBiTree[TreeSize];
SqBiTree T;
/*二叉树的链式存储---二叉链表*/
typedef struct BiTNode
{
    TElemType data; //数据域
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
/*二叉树的链式存储---三叉链表*/
typedef struct TriTNode
{
    TElemType data; //数据域
    struct TriTNode *lchild, *rchild, *parent;
} TriTNode, *TriTree;

/*二叉树的递归遍历算法*/
void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        printf("%d\t",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
/*按先序遍历序列建立二叉树的二叉链表*/
Status CreatBiTree(BiTree &T)
{
    char ch;  //定义变量
    scanf("%c",&ch); //接收字符
    if(ch==' ') T=NULL;
    else
    {
        T=(BiTNode*)malloc(sizeof(BiTNode));
        T->data = ch;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
     return OK;
}
/*统计二叉树中的叶子节点总数*/
int LeafCount1(BiTree T)
{
    static int count; //使用局部静态变量
    if(T)
    {
        if(T->lchild==NULL&&T->rchild==NULL)
            count++;
        else
        {
            count = LeafCount1(T->lchild);
            count = LeafCount1(T->rchild);
        }
    }
    return count;
}
int LeafCount2(BiTree T, int &count)
{
    if(T)
    {
        if(T->lchild==NULL&&T->rchild==NULL)
            count++;
        else
        {
            count = LeafCount2(T->lchild,count);
            count = LeafCount2(T->rchild,count);
        }
    }
}
/*求二叉树的深度*/
int Depth(BiTree T)
{
    int depth,depthleft,depthright;
    if (T==NULL)
    {
        depth = 0;
    }
    else
    {
        depthleft = Depth(T->lchild);
        depthright = Depth(T->rchild);
        depth = depthleft>depthright?depthleft + 1 :depthright+1;
    }
    return depth;
}
/*二叉树的层次遍历非递归算法*/
#define M 1
void LevelTrave(BiTree T)
{
    int f = 0, r =0;
    BiTree p, q[M];
    q[r++]=T;
    while (f<r)
    {
        p=q[f++];
        printf("%c\t",p->data);
        if(p->lchild)
            q[r++]=p->lchild;
        if(p->rchild)
            q[r++]=p->rchild;
        
    }
}
/*树的遍历算法*/
/*
*使用孩子-兄弟表示法作为树的存储结构，可通过对应二叉树的遍历实现树的遍历
*先根遍历树<=>先序遍历对应的二叉树
*后根遍历树<=>中序遍历对应的二叉树
*/
/*
*树的层次遍历
*可采用多重链表存储，借助队列实现
*/
/*森林的遍历*/