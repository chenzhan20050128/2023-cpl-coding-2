#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

char grid[60][60];
int visit[60][60] = {0};
int path[10010][2];
int vector[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int nextmove(int x, int y, int n, int m, int possible_moves[])
{
    int num_moves = 0;
    for (int i = 0; i < 4; i++)
    {
        int now_x = x + vector[i][0];
        int now_y = y + vector[i][1];
        if (now_x >= 1 && now_x <= n && now_y >= 1 && now_y <= m && !(visit[now_x][now_y]) && grid[now_x][now_y] == '#')
        {
            possible_moves[num_moves] = i;
            num_moves++;
        }
    }
    return num_moves;
}

int main()
{
    int n, m;
    int step = 0;
    int x, y;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &x, &y);

    // Read grid characters
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf(" %c", &grid[i][j]);
        }
    }
    path[step][0] = x;
    path[step][1] = y;

    int next_possible_moves[4];
    int num_possible_moves = 0;

    while ((num_possible_moves = nextmove(x, y, n, m, next_possible_moves)) > 0)
    {
        int nexti = next_possible_moves[0];
        x = x + vector[nexti][0];
        y = y + vector[nexti][1];
        visit[x][y] = 1;
        step++;
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