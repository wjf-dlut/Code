#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float data1, data2, result;
    char op;
    printf("����������a+b���������ʽ��");
    scanf("%f%c%f", &data1, &op, &data2);
    switch (op)
    {
    case '+':
        result = data1 + data2;
        break;
    case '-':
        result = data1 - data2;
        break;
    case '*':
        result = data1 * data2;
        break;
    case '/':
        result = data1 / data2;
    default:
        break;
    }
    printf("%.2f%c%.2f=%.2f", data1, op, data2, result);
    system("pause");
    return 0;
}