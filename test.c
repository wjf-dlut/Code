#include<stdio.h>
int main(void)
{
    int a = 123 ,b=321;
    a ^=b;
    b ^= a;
    a ^= b;
    printf("a=%d,b=%d",a,b);
}