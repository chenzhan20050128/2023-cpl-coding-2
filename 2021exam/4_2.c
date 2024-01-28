#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node
{
    long long value;
    node *right;
    node *down;
} node;
node *grid[2510][2510];
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
            grid[i][j] = (node *)malloc(sizeof(node *));
            node temp;
            temp.value = i * m + j;
            *(grid[i][j]) = temp;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j <= m - 1)
            {
                grid[i][j]->right = grid[i][j + 1];
            }
            else
            {
                grid[i][j]->right = NULL;
            }
            if (i <= m - 1)
            {
                grid[i][j]->down = grid[i + 1][j];
            }
            else
            {
                grid[i][j]->down = NULL;
            }
        }
    }

    long long x1, y1, x2, y2, x3, y3, x4, y4, a;
    long long sum = 0;
    while (q--)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &a);

        // 1;
        for (int i = x1; i <= x2; i++)
        {
            grid[i][y1 - 1]->right = grid[i - x1 + x3][y3];
        }
        for (int i = y1; i <= y2; i++)
        {
            grid[x1 - 1][i]->down = grid[x3][i - y1 + y3];
        }
        // 2;
        for (int i = x1; i <= x2; i++)
        {
            grid[i][y2]->right = grid[i - x1 + x3][y4 + 1];
        }
        for (int i = y1; i <= y2; i++)
        {
            grid[x2][i]->down = grid[x4 + 1][i - y1 + y3];
        }
        // 3;
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