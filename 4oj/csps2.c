#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxn 1010
int distance[maxn];
int price[maxn];
int dp[maxn][maxn] = {99999999};
int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &distance[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &price[i]);
    }
    for (int i = 1;i<=n;i++){
        dp[i][i] = 0;
    }
    for (int i = 1;i<=n-1;i++){
        dp[i][i+1] = distance[i] / price[i];
    }
    for(int i = 1;i<=n;i++){
        for (int j = i+1;j<=n;j++){//j>i
            dp[i][j] = 
        }
    }
}