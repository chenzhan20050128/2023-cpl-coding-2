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
        // 当前列加一，如果超出了边界，则重新开始计数
        nowcol = (nowcol + 1 + n) % n;
        // 当前行减一，如果超出了边界，则重新开始计数
        nowrow = (nowrow - 1 + n) % n;
        // 如果当前点被访问过，则跳过当前点，并重新开始计数
        if (visit[nowrow][nowcol] == 1)
        {
            nowcol = (nowcol - 1 + n) % n;
            nowrow = (nowrow + 1 + n) % n;
            nowrow = (nowrow + 1 + n) % n;
        }
        // if (visit[nowrow][nowcol] == 1)
        // {
        //   如果当前点被访问过，则报错
        //     printf("error");
        // }
        // 将当前点标记为已访问
        visit[nowrow][nowcol] = 1;
        // 计数加一
        cnt += 1;
        // 将当前点的值设置为计数
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