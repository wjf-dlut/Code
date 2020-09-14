#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int n;
    float i, j, sum = 0, t;
    printf("请输入正整数n：");
    scanf("%d", &n);
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1, t = 1; j <= i; j++)
        {
            t *= j;
        }

        sum += (1 / t);
        printf("1/%.0f!+", i);
    }
    printf("\b=%.4f", sum);
    system("pause");
    return 0;
}