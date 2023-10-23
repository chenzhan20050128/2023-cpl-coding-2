#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
char xiaoyou[10010][20];
char laibin[10010][20];

int cmp_birthday_xiaoyou(int i, int j) // i < j:+;i > j:-;i==j:0;
{
    int yeari = (int)xiaoyou[i][6] * 1000 + (int)xiaoyou[i][7] * 100 + (int)xiaoyou[i][8] + (int)xiaoyou[i][9];
    int yearj = (int)xiaoyou[j][6] * 1000 + (int)xiaoyou[j][7] * 100 + (int)xiaoyou[j][8] + (int)xiaoyou[j][9];
    int monthi = (int)xiaoyou[i][10] * 10 + (int)xiaoyou[i][11];
    int monthj = (int)xiaoyou[j][10] * 10 + (int)xiaoyou[j][11];
    int dayi = (int)xiaoyou[i][12] * 10 + (int)xiaoyou[i][13];
    int dayj = (int)xiaoyou[j][12] * 10 + (int)xiaoyou[j][13];
    if (yeari == yearj)
    {
        if (monthi == monthj)
        {
            if (dayi == dayj)
            {
                return 0;
            }
            else
            {
                return (dayj - dayi);
            }
        }
        else
        {
            return (monthj - monthi);
        }
    }
    else
    {
        return (yearj - yeari);
    }
}
int cmp_birthday_laibin(int i, int j) // i < j:+;i > j:-;i==j:0;
{
    int yeari = (int)laibin[i][6] * 1000 + (int)laibin[i][7] * 100 + (int)laibin[i][8] + (int)laibin[i][9];
    int yearj = (int)laibin[j][6] * 1000 + (int)laibin[j][7] * 100 + (int)laibin[j][8] + (int)laibin[j][9];
    int monthi = (int)laibin[i][10] * 10 + (int)laibin[i][11];
    int monthj = (int)laibin[j][10] * 10 + (int)laibin[j][11];
    int dayi = (int)laibin[i][12] * 10 + (int)laibin[i][13];
    int dayj = (int)laibin[j][12] * 10 + (int)laibin[j][13];
    if (yeari == yearj)
    {
        if (monthi == monthj)
        {
            if (dayi == dayj)
            {
                return 0;
            }
            else
            {
                return (dayj - dayi);
            }
        }
        else
        {
            return (monthj - monthi);
        }
    }
    else
    {
        return (yearj - yeari);
    }
}

int main()
{
    int xiaoyou_come = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", &xiaoyou[i]);
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", &laibin[i]);
        for (int j = 1; j <= n; j++)
        {
            int flag = 1;
            for (int k = 1; k <= 18; k++)
            {
                if (xiaoyou[j][k] != laibin[i][k])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                xiaoyou_come += 1;
            }
        }
    }
    if (xiaoyou_come > 0)
    {
        // todo
    }
}