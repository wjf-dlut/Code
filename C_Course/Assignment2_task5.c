#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    long a;
    int b, sum = 0;
    printf("请输入一个正整数：");
    scanf("%ld", &a);
    while (a)
    {
        b = a % 10;
        b == 7 ? sum++ : sum;
        a = a / 10;
    }
    printf("数据中7的个数为%d.", sum);
    system("pause");
    return 0;
}