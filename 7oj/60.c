#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int grid[650][650];
//int sum[650][650];
int n, m, d;
int maxvalue = -2147483647;
int answer[10010][2];
int answer_cnt = 0;
int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a > b ? b : a;
}

int cal_value(int row, int col)
{
    int value_sum = 0;
    for (int i = max(1, row - d); i <= min(n, row + d); i++)
    {
        for (int j = max(1, col - d); j <= min(m, col + d); j++)
        {
            if (abs(i - row) + abs(j - col) <= d)
            {
                value_sum += grid[i][j];
            }
        }
    }
    return value_sum;
}
int is_exist(int i, int j)
{
    if (i >= 1 && i <= n && j >= 1 && j <= m)
    {
        return 1;
    }
    return 0;
}
int move_right(int prev_value, int i, int j)
{
    int result = prev_value;
    int now_i = i - d;
    int now_j = j;
    for (int q = 0; q < d; q++)
    {
        if (is_exist(now_i + q, now_j - q))
        {
            result -= grid[now_i + q][now_j - q];
        }
        if (is_exist(now_i + q, 2 * j + 1 - now_j + q))
        {
            result += grid[now_i + q][2 * j + 1 - now_j + q];
        }
    }
    now_i = i;
    now_j = j - d;
    for (int q = 0; q <= d; q++)
    {
        if (is_exist(now_i + q, now_j + q))
        {
            result -= grid[now_i + q][now_j + q];
        }
        if (is_exist(now_i + q, 2 * j + 1 - now_j - q))
        {
            result += grid[now_i + q][2 * j + 1 - now_j - q];
        }
    }

    return result;
}

int move_left(int prev_value, int i, int j)
{
    int result = prev_value;
    int now_i = i - d;
    int now_j = j;
    for (int q = 0; q < d; q++)
    {
        if (is_exist(now_i + q, now_j + q))
        {
            result -= grid[now_i + q][now_j + q];
        }
        if (is_exist(now_i + q, 2 * j - 1 - now_j - q))
        {
            result += grid[now_i + q][2 * j - 1 - now_j - q];
        }
    }
    now_i = i;
    now_j = j + d;
    for (int q = 0; q <= d; q++)
    {
        if (is_exist(now_i + q, now_j - q))
        {
            result -= grid[now_i + q][now_j - q];
        }
        if (is_exist(now_i + q, 2 * j - 1 - now_j + q))
        {
            result += grid[now_i + q][2 * j - 1 - now_j + q];
        }
    }

    return result;
}

int move_down(int prev_value, int i, int j)
{
    int result = prev_value;
    int now_i = i - d;
    int now_j = j;
    for (int q = 0; q <= d; q++)
    {
        if (is_exist(now_i + q, now_j - q))
        {
            result -= grid[now_i + q][now_j - q];
        }
        if (is_exist(2 * i + 1 - now_i - q, now_j - q))
        {
            result += grid[2 * i + 1 - now_i - q][now_j - q];
        }
    }
    now_i = i - d;
    now_j = j;
    for (int q = 1; q <= d; q++)
    {
        if (is_exist(now_i + q, now_j + q))
        {
            result -= grid[now_i + q][now_j + q];
        }
        if (is_exist(2 * i + 1 - now_i - q, now_j + q))
        {
            result += grid[2 * i + 1 - now_i - q][now_j + q];
        }
    }

    return result;
}
void judge(int a, int i, int j)
{
    //sum[i][j] = a;
    if (a > maxvalue)
    {
        maxvalue = a;
        answer_cnt = 1;
        answer[answer_cnt][0] = i;
        answer[answer_cnt][1] = j;
    }
    else if (a == maxvalue)
    {
        answer_cnt++;
        answer[answer_cnt][0] = i;
        answer[answer_cnt][1] = j;
    }
}
// void printsum()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             printf("%d ", sum[i][j]);
//         }
//         printf("\n");
//     }
//     return;
// }
int main()
{
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    int a = cal_value(1, 1);
    judge(a, 1, 1);
    int i = 1;
    while (i <= n)
    {
        if (i > 1)
        {
            a = move_down(a, i - 1, 1);
            judge(a, i, 1);
        }

        for (int j = 2; j <= m; j++)
        {
            a = move_right(a, i, j - 1);
            judge(a, i, j);
        }
        i += 1;

        if (i <= n)
        {
            a = move_down(a, i - 1, m);
            judge(a, i, m);
            for (int j = m - 1; j >= 1; j--)
            {
                a = move_left(a, i, j + 1);
                judge(a, i, j);
            }
            i += 1;
        }
    }

    //printsum();
    printf("%d %d\n", maxvalue, answer_cnt);
    for (int i = 1; i <= answer_cnt; i++)
    {
        printf("%d %d\n", answer[i][0], answer[i][1]);
    }
    return 0;
}