#include<stdio.h>
#include<stdlib.h>

#define OK 1;
typedef char TElemType;
typedef int Status;

typedef struct BiTNode
{    TElemType data;
     struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


Status CreateBT(BiTree &T)                     //从键盘输入二叉树的先序遍历序列字符串（以”#”代表空结点），建立其二叉链表
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		T=NULL;
	else
	{  T=(BiTNode *)malloc(sizeof(BiTNode));
	    T->data=ch;
		CreateBT(T->lchild);
		CreateBT(T->rchild);
	}
	return OK;
}

Status ExchangeBT(BiTree T)      //设计递归算法实现二叉树中所有结点的左右孩子交换；
{    BiTree temp;
     if (T)
	 {  temp=T->lchild;
	    T->lchild =T->rchild;
		T->rchild=temp;
		ExchangeBT(T->lchild);
		ExchangeBT(T->rchild);
	 }
	 return OK;
}

BiTree Search(BiTree T,char x)                    //查找值为x的结点
{      BiTree TTree;
       if(T)
	   {   if(T->data==x)
	          return T ;
	   TTree=Search(T->lchild,x);
	   if(TTree==NULL)
		   TTree=Search(T->rchild,x);
	   return TTree;
	   }
	   return NULL;
}

void CountLeaf(BiTree T, int &count)              //统计子树中叶子结点的数目；
{  
    if(T)
	{
		if((T->lchild==NULL)&&(T->rchild==NULL))
			count++;
		else
			{CountLeaf(T->lchild,count);
		CountLeaf(T->rchild,count);}
		
	}
}
			
void DispBiTree(BiTree T, int level)          //按树状打印二叉树
{
	int i=0;     
	if(T)
	{ DispBiTree(T->rchild,level+1);                  //按右子树，根结点，左子树顺序遍历并按规则输出
	  for(;i<level;i++)
	  {  printf("#");}
	  printf("%c\n",T->data);
	  DispBiTree(T->lchild,level+1);
	}
}

main()
{     BiTree T,TTree;
	  char x;
	  int count=0;
	  printf("请输入先序遍历序列，建立二叉树\n");
	  CreateBT(T);
	  printf("按树状打印二叉树,结果为\n");
	  DispBiTree(T,0);
	  printf("统计以值为x的结点为根的子树中叶子结点的数目\n");
	  printf("请输入要统计的值x\n");
	  fflush (stdin);
	  scanf("%c",&x);
	  TTree=Search(T,x);
	  CountLeaf(TTree,count);
	  printf("以值为x的结点为根的子树中叶子结点的数目为：%d\n",count);
	  printf("交换二叉树中所有结点的左右孩子\n");
	  ExchangeBT(T);
}