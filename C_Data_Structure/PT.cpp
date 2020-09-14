#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define TreeSize 100 //���н����Ŀ
typedef int TElemType;
typedef int Status;
/*˫�ױ�ʾ��---�洢���֮���˫�׹�ϵ*/
/*���ṹ*/
typedef struct PTNode
{
    TElemType data; //������
    int parent;     //˫����
} PTNode;
/*���ṹ*/
typedef struct
{
    PTNode nodes[TreeSize]; //�������
    int r, n;               //���ڵ���±�ͽڵ�����
} PTree;
/*���ӱ�ʾ��---�洢���֮��ĺ��ӹ�ϵ*/
/*���ӽ��*/
typedef struct CTNode
{
    int child;
    struct CTNode *next;
} * ChildPtr;
/*������*/
typedef struct
{
    TElemType data;
    ChildPtr firstchild;
} CTBox;
/*���ṹ*/
typedef struct
{
    CTBox nodes[TreeSize];
    int r, n; //������±ꡢ�ڵ�����
} CTree;
/*��˫�׵ĺ�������*/
/*���ӽ��*/
typedef struct CTNode
{
    int child;
    struct CTNode *next;
} * ChildPtr;
/*������*/
typedef struct
{
    TElemType data; //������
    int parent;     //˫����
    ChildPtr firstchild;
} CTBox;
/*���ṹ*/
typedef struct
{
    CTBox nodes[TreeSize];
    int r, n; //������±ꡢ�ڵ�����
} CTree;
/*����-�ֵܱ�ʾ��---�洢���֮��ĺ��Ӽ��ֵܹ�ϵ*/
/*���������ַ�������������ʾ�����洢��������ʵ�����������֮���ת��*/
/*���ṹ*/
typedef struct CSnode
{
    TElemType data;                          //������
    struct CSnode *firstchild, *nextsibling; //ָ���һ�����ӡ���һ���ֵ�
} CSNode, *CSTree;

/*�������Ĵ洢�ṹ*/
/*��������˳��洢�ṹ*/
#define Tree_Size 100 //�������н����Ŀ
typedef TElemType SqBiTree[TreeSize];
SqBiTree T;
/*����������ʽ�洢---��������*/
typedef struct BiTNode
{
    TElemType data; //������
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
/*����������ʽ�洢---��������*/
typedef struct TriTNode
{
    TElemType data; //������
    struct TriTNode *lchild, *rchild, *parent;
} TriTNode, *TriTree;

/*�������ĵݹ�����㷨*/
void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        printf("%d\t",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
/*������������н����������Ķ�������*/
Status CreatBiTree(BiTree &T)
{
    char ch;  //�������
    scanf("%c",&ch); //�����ַ�
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
/*ͳ�ƶ������е�Ҷ�ӽڵ�����*/
int LeafCount1(BiTree T)
{
    static int count; //ʹ�þֲ���̬����
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
/*������������*/
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
/*�������Ĳ�α����ǵݹ��㷨*/
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
/*���ı����㷨*/
/*
*ʹ�ú���-�ֵܱ�ʾ����Ϊ���Ĵ洢�ṹ����ͨ����Ӧ�������ı���ʵ�����ı���
*�ȸ�������<=>���������Ӧ�Ķ�����
*���������<=>���������Ӧ�Ķ�����
*/
/*
*���Ĳ�α���
*�ɲ��ö�������洢����������ʵ��
*/
/*ɭ�ֵı���*/