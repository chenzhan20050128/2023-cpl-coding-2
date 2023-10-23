#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
char grid[60][60];
int visit[60][60]  = {0};
int path[10010][2];
int vector[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int nextmove(int x, int y, int n, int m)
{
    int flag = 0;
    int now_x;
    int now_y;
    for (int i = 0; i <= 3; i++)
    {
        now_x = x + vector[i][0];
        now_y = y + vector[i][1];
        if (now_x >= 1 && now_x <= n && now_y >= 1 && now_y <= m && !(visit[now_x][now_y]) && grid[now_x][now_y] == '#')
        {
            flag = 1;
            return i;
        }
    }
    if (flag == 0)
    {
        return -1;
    }
}

int main()
{
    int n, m;
    int step = 0;
    int x;
    int y;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &x, &y);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%c", &grid[i][j]);
        }
    }
    path[step][0] = x;
    path[step][1] = y;
    int nexti;
    while (nextmove(x, y, n, m) != -1)
    {
        nexti = nextmove(x, y, n, m);
        x = x + vector[nexti][0];
        y = y + vector[nexti][1];
        step++;
        visit[x][y] = 1;
        path[step][0] = x;
        path[step][1] = y;
    }
    printf("%d\n", step);
    for (int i = 0; i < step; i++)
    {
        printf("%d %d\n", path[i][0], path[i][1]);
    }
    return 0;
}
