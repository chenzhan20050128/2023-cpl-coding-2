#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX_N 1000
#define MAX_M 1000
// 地图
int map[MAX_N][MAX_M];
int n, m, d;
// 旋转后的地图
int map_rotated[2 * MAX_N][2 * MAX_M];
int mrsum[2 * MAX_N][2 * MAX_M];
// 将地图和锤子一起向右旋转 45 度，多出来的格子的价值为 0
void rotate(int n, int m)
{
    for (int i = 0; i < n + m; i++)
        for (int j = 0; j < n + m; j++)
            map_rotated[i][j] = 0;

    for (int i = 0; i < n + m; i++)
        for (int j = 0; j < n + m; j++)
        {
            map_rotated[i + j][n - i + j - 1] = map[i][j];
        }
}
void derotate()
{
    int de[100][100];
    for (int i = 0; i < n + m; i++)
        for (int j = 0; j < n + m; j++)
            de[i][j] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            de[i][j] = map_rotated[(j - i + n - 1) / 2][(i + j + n - 1) / 2];
            printf("%d ", de[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void myprint()
{
    for (int i = 0; i < n + m; i++)
    {
        for (int j = 0; j < n + m; j++)
        {
            printf("%d ", map_rotated[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n + m; i++)
    {
        for (int j = 0; j < n + m; j++)
        {
            printf("%d ", mrsum[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
signed main()
{
    printf("hwllo\n");
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &map[i][j]);

    rotate(n, m);

    mrsum[0][0] = map_rotated[0][0];
    for (int i = 0; i < n + m; i++)
    {
        mrsum[i][0] = mrsum[i - 1][0] + map_rotated[i][0];
    }
    for (int j = 0; j < n + m; j++)
    {
        mrsum[0][j] = mrsum[0][j - 1] + map_rotated[0][j];
    }
    for (int i = 1; i < n + m; i++)
        for (int j = 1; j < n + m; j++)
            mrsum[i][j] = mrsum[i - 1][j] + mrsum[i][j - 1] - mrsum[i - 1][j - 1] + map_rotated[i][j];
    // myprint();
    // derotate();

    int maxsum = -2147483648;
    for (int i = 2 * d; i < n + m; i++)
    {
        for (int j = 2 * d; j < n + m; j++)
        {
            int sum = 0;
            if (i == 2 * d)
            {
                if (j == 2 * d)
                {
                    sum = mrsum[i][j];
                }
                else
                {
                    sum = mrsum[i][j] - mrsum[i][j - 2 * d - 1];
                }
            }
            else
            {
                if (j == 2 * d)
                {
                    sum = mrsum[i][j] - mrsum[i - 2 * d - 1][j];
                }
                else
                {
                    sum = mrsum[i][j] - mrsum[i - 2 * d - 1][j] - mrsum[i][j - 2 * d - 1] + mrsum[i - 2 * d - 1][j - 2 * d - 1];
                }
            }
            if (sum > maxsum && ((i + j) % 2 + n % 2 == 1)) // important!
            {
                maxsum = sum;
            }
        }
    }
    int answer[361000][2];
    int answer_cnt = 0;
    for (int i = 2 * d; i < n + m; i++)
    {
        for (int j = 2 * d; j < n + m; j++)
        {
            int sum = 0;
            if (i == 2 * d)
            {
                if (j == 2 * d)
                {
                    sum = mrsum[i][j];
                }
                else
                {
                    sum = mrsum[i][j] - mrsum[i][j - 2 * d - 1];
                }
            }
            else
            {
                if (j == 2 * d)
                {
                    sum = mrsum[i][j] - mrsum[i - 2 * d - 1][j];
                }
                else
                {
                    sum = mrsum[i][j] - mrsum[i - 2 * d - 1][j] - mrsum[i][j - 2 * d - 1] + mrsum[i - 2 * d - 1][j - 2 * d - 1];
                }
            }
            if (sum == maxsum && ((i + j) % 2 + n % 2 == 1))
            {
                answer_cnt++;
                int now_i = i - d;
                int now_j = j - d;
                answer[answer_cnt][0] = (now_i - now_j + n - 1) / 2;
                answer[answer_cnt][1] = (now_i + now_j - n + 1) / 2;
            }
        }
    }
    printf("%d %d\n", maxsum, answer_cnt);
    for (int i = 1; i <= answer_cnt; i++)
    {
        printf("%d %d\n", answer[i][0] + 1, answer[i][1] + 1);
    }
    return 0;
}