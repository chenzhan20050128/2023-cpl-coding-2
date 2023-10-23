#include <stdio.h>
#include <math.h>
int matrix[110][110];
int result[110];
void move_and_fill(int fill, int row, int cnt, int n)
{
    for (int i = n - cnt - 1; i >= 0; i--)
    {
        matrix[row][i + cnt] = matrix[row][i];
    }
    for (int i = 0; i <= cnt - 1; i++)
    {
        matrix[row][i] = fill;
    }
}
int main()
{
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int round = k;
    for (int i = 0; i <= n - 1; i += 2)
    {
        round = (round + 1) % k;
        move_and_fill(x, i, round, n);
    }

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }



    int sum = 0;
    for (int j = 0; j <= n - 2; j++)
    {
        sum = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            sum += matrix[i][j];
        }
        result[j] = sum;
        printf("%d ", result[j]);
    }
    sum = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        sum += matrix[i][n - 1];
    }
    result[n - 1] = sum;
    printf("%d", result[n - 1]);

    return 0;
}