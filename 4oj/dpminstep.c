#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define maxn 1010
int dp[maxn][maxn] = {0};
int min(int x, int y){
    if(x > y){
        return y;
    }
    else {
        return x;
    }
}
int main()
{

    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    x2 = x2 - x1;
    x3 = x3 - x1;
    x1 = 0;
    if (x2 < 0)
    {
        x2 = (-1) * x2;
        x3 = (-1) * x3;
    }
    y2 = y2 - y1;
    y3 = y3 - y1;
    y1 = 0;
    if (y2 < 0)
    {
        y2 = (-1) * y2;
        y3 = (-1) * y3;
    }
    dp[0][0] = 0;
    for (int i = 0; i <= x2; i++)
    {
        for (int j = 0; j <= y2; j++)
        {
            if (i == 0 && j != 0 && (i != x3 && j != y3))
            {
                dp[i][j] = dp[i - 1][j] + 1;
                continue;
            }
            if (j == 0 && i != 0 && (i != x3 && j != y3))
            {
                dp[i][j] = dp[i][j - 1] + 1;
                continue;
            }
            if ((i != x3 && j != y3))
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    printf("%d", dp[x2][y2]);
    return 0;
}