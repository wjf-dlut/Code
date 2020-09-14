#include<stdio.h>
int main(void)
{
    float weight;
    float value;

    printf("Are you worth...?\n");
    printf("Let's check it out.\n");
    printf("Please enter you weight in pound:");

    scanf("%f",&weight);
    value = 1700.0*weight*14.5833;
    printf("You weight in platinum is worth $%.2f.\n",value);
    printf("You are easily worth it!If platinum prices dorp,\n");
    printf("eat more to maintain your value.\n");


    getchar();
    getchar();

    
    return 0;
}