#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

char mine[110][110] = {'o'};
int cnt[110][110] = {0};
int vector[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int cnt_pos(int row, int col, int n)
{
    if (mine[row][col] == '*')
    {
        return -1;
    }
    int result = 0;
    int now_row;
    int now_col;
    for (int i = 0; i < 8; i++)
    {
        now_row = row + vector[i][0];
        now_col = col + vector[i][1];
        if (now_row >= 1 && now_row <= n && now_col >= 1 && now_col <= n) // 边界判断
        {
            if (mine[now_row][now_col] == '*')
            {
                result++;
            }
        }
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);

    // 处理输入
    getchar(); // 消耗换行符
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%c", &mine[i][j]);
        }
        getchar(); // 消耗换行符
    }

    // 统计地雷周围的数字
    int temp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            temp = cnt_pos(i, j, n);
            if (temp == -1)
            {
                printf("*");
            }
            else
            {
                printf("%d", temp);
            }
        }
        printf("\n");
    }
    return 0;
}