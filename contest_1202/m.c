#include <stdio.h>
int n;
int grid[200][200] = {0};
int sum[200][200] = {0};
void print_sum()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

int cal_sum(int i, int j, int k, int l)
{
    return sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
    sum[1][1] = grid[1][1];
    for (int i = 2; i <= n; i++)
    {
        sum[i][1] = sum[i - 1][1] + grid[i][1];
    }
    for (int j = 2; j <= n; j++)
    {
        sum[1][j] = sum[1][j - 1] + grid[1][j];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i][j];
        }
    }
    //print_sum();
    int max_area = -2147483648;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = i + 1; k <= n; k++)
            {
                for (int l = j + 1; l <= n; l++)
                {
                    if (cal_sum(i, j, k, l) > max_area)
                    {
                        max_area = cal_sum(i, j, k, l);
                        //printf("max:%d %d %d %d\n", i, j, k, l);
                    }
                    //printf("visited:%d %d %d %d : %d\n", i, j, k, l, cal_sum(i, j, k, l));
                }
            }
        }
    }
    printf("%d", max_area);
    return 0;
}