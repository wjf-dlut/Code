#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    float real;
    scanf("%f", &real);
    if (real >= 0)
    {
        printf("The square root of %.1f is %.1f.", real, sqrt(real));
    }
    else
    {
        printf("该实数没有实数根。");
    }
    system("pause");
    return 0;
}