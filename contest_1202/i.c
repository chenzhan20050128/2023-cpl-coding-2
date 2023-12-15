#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long dp[110];

void process(int x)
{
    long long  result = 0;
    if (x == 1 || x == 0){
        return ;
    }
    if (dp[x - 2] != 0)
    {
    }
    else
    {
        process(x - 2);
    }
    result += dp[x - 2];
    if (dp[x - 1] != 0)
    {
    }
    else
    {
        process(x - 1);
    }
    result += dp[x - 1];
    dp[x] = result;
    return;
}
int main()
{
    int n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    scanf("%d", &n);
    process(n);
    printf("%lld", dp[n]);
    return 0;
}