#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int time1, time2,t, h, m;
    printf("���������ʱ�䣺");
    scanf("%d",&time1);
    printf("�����뵽��ʱ�䣺");
    scanf("%d",&time2);
    h = time2/100 - time1/100;
    m = time2%100 - time1%100;
    t = h*60  + m;
    h = t/60;
    m = t%60;
    printf("The train journey time is %d hrs %d mins.",h,m);
    system("pause");
}