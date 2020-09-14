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
    ElemType *base; //数组元素基地址
    int dim;        //数组维数
    int *bounds;    //数组维界基地址
    int *constants; //常数基地址，依据元素下标计算偏移量时使用
} Array;

typedef struct
{
    ElemType **base; //数组行指针数组基地址
    int row, column; //数组行列维数
} Array_2;
