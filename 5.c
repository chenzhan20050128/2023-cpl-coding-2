#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define maxn 1010 // 1000010
int grid[maxn][maxn];
// int sum[maxn];
int countzero[maxn];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        countzero[0] = 0;
        int maxpos = 0;
        int maxsum = -2147483648;
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &grid[i][j]);
            if (grid[i][j] == 0)
            {
                countzero[j] = countzero[j - 1] + 1;
            }
            else
            {
                countzero[j] = countzero[j - 1];
            }
            if (grid[i][j] >= maxsum)
            {
                maxsum = grid[i][j];
                maxpos = j;
            }
        }
        printf("%d %d\n", maxpos, maxpos - countzero[maxpos] - 1);
    }
    return 0;
}