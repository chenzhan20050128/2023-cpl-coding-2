#include <stdio.h>
#include <math.h>
int a[110][110];
int b[110][110];
int c[110][110] = {0};
int main()
{
    int m, n, p;
    int sum = 0;
    scanf("%d %d %d", &m, &n, &p);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]); // i ->m;j->n;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            scanf("%d", &b[i][j]); // i->n;j->p;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            sum = 0;
            for (int k = 1; k <= n; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
            printf("%d ", sum);
        }
        printf("\n");
    }
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= p; j++)
    //     {
    //         printf("%d ", c[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}