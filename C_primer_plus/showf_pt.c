#include<stdio.h>
int main(void)
{
    float about = 32000.0;
    double abet =2.13e9;
    long double dip = 5.32e-5;

    printf("%f can be written %e\n",about,about);
    printf("And it's %a in hexadecimal,powers of 2 notation\n",about);
    printf("%f can be written %e\n",abet,abet);
    printf("%Lf can be written %Le\n",dip,dip);

    getchar();
    return 0;

}