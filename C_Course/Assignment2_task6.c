#include <stdio.h>
#include <stdlib.h>
#define YEAR 2017             //日历的年份
#define FD 7                  //该年的第一天为周几
int isleap(int year);         //判断闰年
void ShowCalendar(int month); //显示该月的日历
int main(void)
{
    int month;
    char choice;
    do
    {

        do
        {
            printf("Enter month in 2017 to display calendar (1-12):");
            fflush(stdin);
            scanf("%d", &month);
            if (month <= 12 && month >= 1)
            {
                ShowCalendar(month);
                break;
            }
            printf("ERROR- Enter month in range of (1-12)!\n");
        } while (month < 1 || month > 12);
        do
        {
            printf("Would you like to display another month (y/n) ?");
            fflush(stdin);
            scanf("%c", &choice);
            if (choice != 'y' && choice != 'n')
            {
                printf("ERROR- Please enter y/n!\n");
            }
        } while (choice != 'y' && choice != 'n');
    } while (choice != 'n');

    // system("pause");
    return 0;
}
int isleap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}
void ShowCalendar(int month)
{
    int i, count, sum = 0, status, year = YEAR;
    int days_of_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    status = isleap(year);
    if (status == 1)
    {
        days_of_month[2] = 29;
    }
    for (i = 0; i < month; i++)
    {
        sum += days_of_month[i];
    }
    count = (sum + FD) % 7;
    printf("***************************************************\n");
    printf("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n");
    for (i = 0; i < count; i++)
    {
        printf("\t");
    }
    for (i = 1; i <= days_of_month[month]; i++)
    {

        printf("%d\t", i);
        if ((i + count) % 7 == 0 || i == days_of_month[month])
        {
            printf("\n");
        }
    }
}
