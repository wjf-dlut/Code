#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char thisman;
    for ( thisman = 'A'; thisman <= 'D'; thisman++)
    {
        if ((thisman!='A')+(thisman=='C')+(thisman=='D')+(thisman!='D')==3)
        {
            printf("This man is %c.",thisman);
        } 
    }
system("pause");
return 0;
}