#include<stdio.h>
int main(void)
{
    char ch;
    printf("please enter a character.\n");
    scanf("%c",&ch);
    printf("the code for %c is %d.\n",ch,ch);

    getchar();
    getchar();
    return 0;
}