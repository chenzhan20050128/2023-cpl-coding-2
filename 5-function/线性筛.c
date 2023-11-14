// 目标：应用线性筛法找到给定整数n以内的所有素数。（n不大于一亿）
#include <stdio.h>
int a[100000001] = {0}, p[50000000];
int main()
{
    int n, i, j, k = 0;
    scanf("%d", &n);
    for (i = 2; i <= n; i++)
    {
        if (a[i] == 0)
        {
            k++;
            p[k] = i;
            // printf("%d ",i);
        }
        for (j = 1; j <= k && i * p[j] <= n; j++)
        {
            a[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
    printf("共%d个素数\n", k);
    return 0;
}