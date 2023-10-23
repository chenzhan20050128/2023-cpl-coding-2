#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int numbers[10010];
int read()
{
    int a = 0, b = 1;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && (ch != '-'))
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        b = -1;
        ch = getchar();
    }
    if (ch == 'Z')
    {
        return 999999;
    }
    while (ch >= '0' && ch <= '9')
    {
        a = a * 10 + ch - '0';
        ch = getchar();
    }
    return a * b;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        numbers[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        int x = numbers[i];
        int radixflag = 0;
        if (x == 999999)
        {
            radixflag = 999999;
        }
        int temp[25] = {0};
        char number[25] = {'0'};
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
            printf("Radix Error\n", radixflag);
        }
        else
        {
            int print0flag = 0;
            for (int i = 24; i >= 1; i--)
            {
                if (number[i] == '0' && print0flag == 1)
                {
                    putchar('0');
                }
                else if (number[i] == '1')
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
        printf("\n");
    }
    return 0;
}