#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <process.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TURE 1
#define FAULSE 0

typedef int Status;
typedef char SElemType;
typedef char ElemType;
typedef struct
{ //定义栈结构
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

Status InitStack(SqStack &S) //建立空栈
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base)
        exit(OVERFLOW);
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S, SElemType e) //入栈
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e) //出栈
{
    if (S.top == S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}

Status GPop(SqStack S, SElemType e) //读取栈顶元素
{
    if (S.top == S.base)
        return ERROR;
    e = *(S.top - 1);
    return OK;
}

Status Direct(char last[], SElemType ch) //当前字符是操作数，直接发送给后缀式
{
    char *p;
    p = last;
    while (*p != '\0')
        p++;
    *p = ch;
    *(p + 1) = '\0'; //给结尾附上结束符
    return 0;
}

void Add(char string[]) //给输入的表达式附上“#”
{
    char *p;
    p = string;
    while (*p != '\0')
        ++p;
    *p = '#';
    *(p + 1) = '\0'; //给结尾附上结束符
}

Status Judge(char ch) //判断优先级
{
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '(' || ch == ')')
        return -1;
    else
        return -2;
}

void add(char last[])
{
    char *k;
    k = last;
    while (*k != '#')
        k++;
    *k = '\0';
}

Status E(SqStack S)
{
    if (S.top == S.base)
        return TURE;
    else
        return FAULSE;
}

void Trans(char string[], char last[]) //变换表达式
{
    char *p, ch, e;
    p = string;
    ch = *p;
    SqStack S;
    InitStack(S);
    Push(S, '#');
    while (!E(S))
    {
        if (ch >= 'a' && ch <= 'z')
            Direct(last, ch);
        else
        {
            switch (ch)
            {
            case '(':
                Push(S, ch);
                break;
            case ')':
                Pop(S, e);
                while (e != '(')
                {
                    Direct(last, e);
                    Pop(S, e);
                }
                break;
            default:
                if (ch == '#')
                    while (!E(S))
                    {
                        Pop(S, e);
                        Direct(last, e);
                    }
                else
                {
                    GPop(S, e);
                    while (Judge(e) >= Judge(ch))
                    {
                        Pop(S, e);
                        Direct(last, e);
                        GPop(S, e);
                    }
                    Push(S, ch);
                }
                break;
            }
        }
        if (ch != '#')
            ch = *++p;
    }
}

int main()
{
    char last[100], string[100];
    last[0] = '\0';
    printf("请输入表达式:\n");
    gets(string);
    Add(string);
    Trans(string, last);
    add(last);
    printf("所输入的表达式，其后缀表达式为：%s\n", last);
    return 0;
}
