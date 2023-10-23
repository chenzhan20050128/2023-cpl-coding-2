#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
char numbers[10010][25];
int tranfer_to_int(int lines)
{
    int minusflag = 0;
    int x = 0;
    for (int i = 24; i >= 0; i--)
    {
        if (numbers[lines][i] == '-')
        {
            minusflag = 1;
        }
        else if (isdigit(numbers[lines][i]))
        {
            x = x * 10 + (int)numbers[lines][i];
        }
        else
        {
            return 999999;
        }
    }
    if (minusflag == 1)
    {
        x = (-1) * x;
    }
    return x;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", numbers[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int x = tranfer_to_int(i);
        int radixflag = 0;
        if (x == 999999)
        {
            radixflag = 999999;
        }
        int temp[25] = {0};
        char number[25];
        int cnt = 0;
        while (x > 0)
        {
            cnt++;
            temp[cnt] = x % 3;
            x = x / 3;
        }
        for (int i = 1; i <= 24; i++)
        {
            if (temp[i] == 0)
            {
                number[i] = '0';
            }
            else if (temp[i] == 1)
            {
                number[i] = '1';
            }
            else if (temp[i] == 2)
            {
                number[i] = 'Z';
                temp[i + 1] += 1;
            }
            else if (temp[i] == 3)
            {
                number[i] = '0';
                temp[i + 1] += 1;
            }
            else
            {
                radixflag = 1;
                break;
            }
        }
        if (radixflag != 0)
        {
            printf("Radix Error%d\n", radixflag);
        }
        else
        {
            int print0flag = 0;
            for (int i = 24; i >= 0; i--)
            {
                if (number[i] == 0 && print0flag == 1)
                {
                    putchar('0');
                }
                else if (number[i] == 1)
                {
                    print0flag = 1;
                    putchar('1');
                }
                else if (number[i] == 'Z')
                {
                    print0flag = 1;
                    putchar('Z');
                }
                else
                {
                    printf("Radix Error");
                }
            }
        }
    }
    return 0;
}