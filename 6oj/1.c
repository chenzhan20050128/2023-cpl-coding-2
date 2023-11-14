#include <stdio.h>
#include <math.h>
#define int long long
int tri[110][110];
signed main()
{
    for (int i = 1; i <= 100; i++)
    {
        tri[i][1] = 1;
        tri[i][i] = 1;
    }
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 2; j <= i - 1; j++)
        {
            tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }
    }
    int a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", tri[a][b]);
    return 0;
}