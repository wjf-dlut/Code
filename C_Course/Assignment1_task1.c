#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char c;
    printf("������һ����д��ĸ��");
    scanf("%c", &c);
    while (c < 'A' || c > 'Z')
    {
        printf("\n������Ĳ��Ǵ�д��ĸ������������:");
        fflush(stdin);
        scanf("%c", &c);
    }
    printf("\nת�����Сд��ĸΪ%c", c + 'a' - 'A');
    system("pause");
    return 0;
}