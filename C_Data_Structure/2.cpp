#include<stdio.h>
#include<stdlib.h>

#define OK 1;
typedef char TElemType;
typedef int Status;

typedef struct BiTNode
{    TElemType data;
     struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


Status CreateBT(BiTree &T)                     //�Ӽ��������������������������ַ������ԡ�#������ս�㣩���������������
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

Status ExchangeBT(BiTree T)      //��Ƶݹ��㷨ʵ�ֶ����������н������Һ��ӽ�����
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

BiTree Search(BiTree T,char x)                    //����ֵΪx�Ľ��
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

void CountLeaf(BiTree T, int &count)              //ͳ��������Ҷ�ӽ�����Ŀ��
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
			
void DispBiTree(BiTree T, int level)          //����״��ӡ������
{
	int i=0;     
	if(T)
	{ DispBiTree(T->rchild,level+1);                  //��������������㣬������˳����������������
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
	  printf("����������������У�����������\n");
	  CreateBT(T);
	  printf("����״��ӡ������,���Ϊ\n");
	  DispBiTree(T,0);
	  printf("ͳ����ֵΪx�Ľ��Ϊ����������Ҷ�ӽ�����Ŀ\n");
	  printf("������Ҫͳ�Ƶ�ֵx\n");
	  fflush (stdin);
	  scanf("%c",&x);
	  TTree=Search(T,x);
	  CountLeaf(TTree,count);
	  printf("��ֵΪx�Ľ��Ϊ����������Ҷ�ӽ�����ĿΪ��%d\n",count);
	  printf("���������������н������Һ���\n");
	  ExchangeBT(T);
}