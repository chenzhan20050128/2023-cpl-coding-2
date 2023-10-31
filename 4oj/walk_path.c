#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define maxn 55
#define int_max = 2147483647

char grid[maxn][maxn];
int visit[maxn][maxn] = {0};
int path[maxn * 10][2];
int vector[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, initx, inity;
int path_length = 0;
int next_move(int x, int y)
{
    for (int i = 0; i <= 3; i++)
    {
        int nowx = x + vector[i][0];
        int nowy = y + vector[i][1];
        if (1 <= x && x <= n && y >= 1 && y <= m && (visit[nowx][nowy] == 0) && (grid[nowx][nowy] == '#'))
        {
            return i;
        }
    }
    return -1;
}
int main()
{

    scanf("%d %d %d %d", &n, &m, &initx, &inity);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%c", &grid[i][j]);
        }
        getchar();
    }
    visit[initx][inity] = 1;
    int nowx = initx;
    int nowy = inity;
    int temp;
    path_length = 1;
    path[1][0] = initx;
    path[1][1] = inity;
    while (next_move(nowx, nowy) != -1)
    {
        temp = next_move(nowx, nowy);
        nowx = nowx + vector[temp][0];
        nowy = nowy + vector[temp][1];
        visit[nowx][nowy] = 1;
        path_length += 1;
        path[path_length][0] = nowx;
        path[path_length][1] = nowy;
    }
    printf("%d\n", path_length);
    for (int i = 1; i <= path_length; i++)
    {
        printf("%d %d\n", path[i][0], path[i][1]);
    }
    return 0;
}