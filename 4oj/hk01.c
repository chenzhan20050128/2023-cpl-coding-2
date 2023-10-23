#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define int_max 2147483647
#define maxn 5000010
int numbers[15];
int dp[maxn] = {int_max};
int min(int x, int y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}
int main()
{
    int y, n, m;
    scanf("%d %d %d", &y, &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = min(dp[i], 1);
    }
    for (int i = n + 1; i <= y; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                if (numbers[k] * j == i && (dp[i] > dp[j] + 1))
                {
                    dp[i] = dp[j] + 1;
                }
            }
            for (int k = 1; k <= n; k++)
            {
                dp[i] = min(dp[i], dp[i - k] + 1);
            }
        }
    }
    printf("%d", dp[y]);
    return 0;
}