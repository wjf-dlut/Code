#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int a, n[4];
    int i , count=4;
    printf("������һ����λ����");
    scanf("%d", &a);
    for ( i = 0; i < count; i++)
    {
        n[3-i] = (a%10+9)%10;
        a = a/10;
    }
    a = n[2]*1000 + n[3]*100 +n[0]*10 +n[1];
    printf("���ܺ������Ϊ��%d",a);
    system("pause");
    return 0;
}