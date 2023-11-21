#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int grid[650][650];
int n, m, d;
int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a > b ? b : a;
}
int myabs(int x)
{
    if (x >= 0)
    {
        return x;
    }
    else
    {
        return (-1) * x;
    }
}
int cal_value(int row, int col)
{
    int value_sum = 0;
    for (int i = max(1, row - d); i <= min(n, row + d); i++)
    {
        for (int j = max(1, col - d); j <= min(m, col + d); j++)
        {
            if (myabs(i - row) + myabs(j - col) <= d)
            {
                value_sum += grid[i][j];
            }
        }
    }
    return value_sum;
}
int main()
{
    // 80 scores;
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    int maxvalue = -2147483647;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (cal_value(i, j) > maxvalue)
            {
                maxvalue = cal_value(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (cal_value(i, j) == maxvalue)
            {
                answer_cnt += 1;
                answer[answer_cnt][0] = i;
                answer[answer_cnt][1] = j;
            }
        }
    }
    
    return 0;
}