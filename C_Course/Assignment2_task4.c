#include <stdio.h>
#include <stdlib.h>
double f(double x);
int main(void)
{
    double x1, x2, x;
    printf("Please input the lower and upper boundaries:");
    scanf("%lf%lf", &x1, &x2);
    while (f(x1) * f(x2) >= 0)
    {
        printf("No root in this boundary!\nPlease input the lower and upper boundaries:");
        fflush(stdin);
        scanf("%lf%lf", &x1, &x2);
    }
    do
    {
        x = (x1 + x2) / 2;
        if (f(x) == 0)
        {
            printf("The root is %.2lf.");
        }
        else if (f(x) * f(x1) < 0)
        {
            x2 = x;
        }
        else
        {
            x1 = x;
        }
    } while (abs(f(x)) > 1e-2);
    printf("The root is %.2lf.", x);
    system("pause");
    return 0;
}
double f(double x)
{
    return (2 * x * x * x - 4 * x * x + 3 * x - 6);
}