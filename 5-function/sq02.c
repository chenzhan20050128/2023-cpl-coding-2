#include <stdio.h>
#include <math.h>
int grid[1010][1010];
int visit[1010][1010]; // from 0 start;
int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int nowcol = n / 2;
    int nowrow = 0;
    visit[nowrow][nowcol] = 1;
    cnt += 1;
    grid[nowrow][nowcol] = cnt;
    while (cnt < n * n)
    {
        nowcol = (nowcol + 1 + n) % n;
        nowrow = (nowrow - 1 + n) % n;
        if (visit[nowrow][nowcol] == 1)
        {
            nowcol = (nowcol - 1 + n) % n;
            nowrow = (nowrow + 1 + n) % n;
            nowrow = (nowrow + 1 + n) % n;
        }
        // if (visit[nowrow][nowcol] == 1)
        // {
        //     printf("error");
        // }
        visit[nowrow][nowcol] = 1;
        cnt += 1;
        grid[nowrow][nowcol] = cnt;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}