#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    long a;
    int b, sum = 0;
    printf("������һ����������");
    scanf("%ld", &a);
    while (a)
    {
        b = a % 10;
        b == 7 ? sum++ : sum;
        a = a / 10;
    }
    printf("������7�ĸ���Ϊ%d.", sum);
    system("pause");
    return 0;
}