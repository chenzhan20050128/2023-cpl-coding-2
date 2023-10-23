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
    move_and_fill(x,0,3,n);
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}