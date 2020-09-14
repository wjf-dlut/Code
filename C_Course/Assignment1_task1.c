#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char c;
    printf("请输入一个大写字母：");
    scanf("%c", &c);
    while (c < 'A' || c > 'Z')
    {
        printf("\n您输入的不是大写字母，请重新输入:");
        fflush(stdin);
        scanf("%c", &c);
    }
    printf("\n转换后的小写字母为%c", c + 'a' - 'A');
    system("pause");
    return 0;
}