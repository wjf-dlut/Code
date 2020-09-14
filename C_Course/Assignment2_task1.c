#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n[4], temp, i, j, count = 4;
    printf("请输入4个整数：");
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &n[i]);
    }
    for (j = 1; j < 4; j++)
    {
        for (i = 0; i < 4 - j; i++)
        {
            if (n[i] > n[i + 1])
            {
                temp = n[i];
                n[i] = n[i + 1];
                n[i + 1] = temp;
            }
        }
    }
    printf("四个整数按从小到大排列后为：");
    for (i = 0; i < 4; i++)
    {
        printf("%d ", n[i]);
    }
    system("pause");
    return 0;
}