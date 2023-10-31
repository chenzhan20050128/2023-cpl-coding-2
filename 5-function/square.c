#include <stdio.h>
#include <math.h>
int grid[1010][1010];
int visit[1010][1010];
int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int nowx = n / 2 + 1;
    int nowy = 1;
    visit[nowx][nowy] = 1;
    while (cnt <= n * n)
    {
        nowx = (nowx + 1) % n;
        nowy = (nowy + 1) % n;
        if (visit[nowx][nowy] == 1)
        {
            nowx = (nowx - 1 + n) % n;
            nowy = (nowy - 2 + n) % n;
        }
        if (visit[nowx][nowy] == 1)
        {
            printf("error");
        }
        visit[nowx][nowy] = 1;
        cnt += 1;
        grid[nowx][nowy] = cnt;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", grid[i][j]);
        }
    }
    return 0;
}