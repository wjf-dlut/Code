//演示与用户交互
#include<stdio.h>
#include<string.h> //提供strlen()函数原型
#define DENSITY 62.4 //人体密度
int main()
{
    float weight, volume;
    int size, letters;
    char name[40]; //name是一个可容纳40个字符的数组

    printf("Hi!What's your first name?\n");
    scanf("%s",name);
    printf("%s,what's your weight in pounds?\n",name);
    scanf("%f",&weight);
    size = sizeof name;
    letters = strlen(name);
    volume = weight /DENSITY;
    printf("Well,%s,your volume is %2.2f cubic feet.\n",name,volume);
    printf("Also,your first name has %d letters,\n",letters);
    printf("and we have %d bytes to store it.\n",size);

    getchar();
    getchar();
    // getchar();
    return 0;

}