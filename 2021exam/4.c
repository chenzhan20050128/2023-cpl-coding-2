#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

long long *grid[2510][2510];
long long temp[2510][2510];
long long n, m;
long long q;
int main()
{
    scanf("%lld %lld", &n, &m);
    scanf("%lld", &q);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            grid[i][j] = (long long *)malloc(sizeof(long long));
            *(grid[i][j]) = i * m + j;
        }
    }
    long long x1, y1, x2, y2, x3, y3, x4, y4, a;
    long long sum = 0;
    while (q--)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &a);
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                temp[i - x1][j - y1] = *(grid[i][j]);
            }
        }
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                *(grid[i][j]) = *(grid[i - x1 + x3][j - y1 + y3]);
            }
        }
        for (int i = x3; i <= x4; i++)
        {
            for (int j = y3; j <= y4; j++)
            {
                *(grid[i][j]) = temp[i - x3][j - y3];
            }
        }
        sum = 0;
        for (int j = 1; j <= m; j++)
        {
            sum += *(grid[a][j]);
        }
        printf("%lld\n", sum);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            free(grid[i][j]);
        }
    }
    return 0;
}