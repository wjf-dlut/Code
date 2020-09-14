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
#define MAX_ARRAY_DIM 8

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType *base; //����Ԫ�ػ���ַ
    int dim;        //����ά��
    int *bounds;    //����ά�����ַ
    int *constants; //��������ַ������Ԫ���±����ƫ����ʱʹ��
} Array;

typedef struct
{
    ElemType **base; //������ָ���������ַ
    int row, column; //��������ά��
} Array_2;
