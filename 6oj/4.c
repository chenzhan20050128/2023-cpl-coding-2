#include <stdio.h>
#include <stdlib.h>
#define maxn 1010 // 100010
#define int_max 2147483647
int numbers[maxn];
int bigleft[maxn];
int bigright[maxn]; // 使用单调栈;
int nowmin = 2147483647;
int nowmax = -2147483647;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &numbers[i]);
    }
    // process bigright;
    for (int i = 1; i <= n; i++)
    {
        bigright[i] = n + 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (nowmin > numbers[i])
        {
            continue;
        }
        else
        { // nowmin < numbers[i] the question baozheng not appear == condition;
            int j = i - 1;
            while (j >= 1 && numbers[j] <= numbers[i])
            {
                bigright[j] = i;
            }
            nowmin = int_max;
        }
    }
    // process bigleft;
    for (int i = 1; i <= n; i++)
    {
        bigleft[i] = 0;
    }

    for (int i = n; i >= 1; i--)
    {
        if (nowmax > numbers[i])
        {
            continue;
        }
        else
        {
            int j = i + 1;
            while (j <= n && numbers[j] <= numbers[i])
            {
                bigleft[j] = i;
            }
            nowmax = (-1) * int_max;
        }
    }

    // print the answer
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", bigleft[i] + 1, bigright[i] - 1);
    }
    return 0;
}