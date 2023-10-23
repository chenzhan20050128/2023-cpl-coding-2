#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxn 1010
int distance[maxn];
int price[maxn];
int dp[maxn][maxn] = {99999999};
int minprice[maxn];

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
    int n, d;
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &distance[i]);
    }
    int theminprice = 99999999;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &price[i]);
        if (theminprice > price[i])
        {
            theminprice = price[i];
        }
        minprice[i] = theminprice;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        dp[i][i + 1] = ceil((double)(distance[i]) / (double)minprice[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 2; j <= n; j++)
        { // j>i
            for (int k = i + 1; k <= j - 1; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    printf("%d", dp[1][n]);
    return 0;
}
