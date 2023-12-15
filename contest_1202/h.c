#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int grid[1010][1010] = {0};
int visit[1010][1010] = {0};
int direction[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // up down left right.
int change_direction(int x)
{
    if (x == 3)
    {
        return 1;
    }
    else if (x == 1)
    {
        return 2;
    }
    else if (x == 2)
    {
        return 0;
    }
    else if (x == 0)
    {
        return 3;
    }
    else
    {
        printf("error\n");
    }
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
    int remain = m * n;
    int now_row = 1;
    int now_col = 0;
    int now_direction = 3;
    while (remain > 0)
    {
        now_row += direction[now_direction][0];
        now_col += direction[now_direction][1];
        if (now_col > n || now_row > m || now_col < 1 || now_row < 1 || visit[now_row][now_col] == 1)
        {
            now_row -= direction[now_direction][0];
            now_col -= direction[now_direction][1];
            now_direction = change_direction(now_direction);
        }
        else
        {
            visit[now_row][now_col] = 1;
            printf("%d ", grid[now_row][now_col]);
            remain -= 1;
        }
    }

    return 0;
}