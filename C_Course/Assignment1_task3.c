#include<stdlib.h>
#include<stdio.h>
int main(void)
{
    float f,c;
    printf("请输入一个华氏温度：");
    scanf("%f",&f);
    c = 5/9.0*(f-32);
    printf("转换后的摄氏温度为：%.2f",c);
    system("pause");
    return 0;
}