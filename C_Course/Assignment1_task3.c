#include<stdlib.h>
#include<stdio.h>
int main(void)
{
    float f,c;
    printf("������һ�������¶ȣ�");
    scanf("%f",&f);
    c = 5/9.0*(f-32);
    printf("ת����������¶�Ϊ��%.2f",c);
    system("pause");
    return 0;
}