#include <stdio.h>

int matrix[110][110];
int result[110];

void move_and_fill(int fill, int row, int cnt, int n)
{
    for (int i = n - 1; i >= cnt; i--)
    {
        matrix[row][i] = matrix[row][i - cnt];
    }
    for (int i = 0; i < cnt; i++)
    {
        matrix[row][i] = fill;
    }
}

int main()
{
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int round = k;
    for (int i = 0; i < n; i += 2)
    {
        round = (round + 1) % k; // 计算每一行的平移位数
        move_and_fill(x, i, round, n);
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += matrix[j][i];
        }
        result[i] = sum;
        printf("%d ", result[i]);
    }

    return 0;
}