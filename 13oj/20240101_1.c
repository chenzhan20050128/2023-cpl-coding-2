#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxn 1010
int grid[maxn][maxn] = {0};
int tempgrid[maxn][maxn] = {0};
int n, q;

void my_print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
void fall()
{
    for (int j = 1; j <= n; j++)
    {
        int cnt1 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (grid[i][j] == 1)
            {
                cnt1++;
            }
        }
        for (int i = n; i >= 1; i--)
        {
            if (n + 1 - i <= cnt1)
            {
                grid[i][j] == 1;
            }
            else
            {
                grid[i][j] == 0;
            }
        }
    }
    my_print();
    return;
}
void right()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            tempgrid[j][n + 1 - i] = grid[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            grid[i][j] = tempgrid[i][j];
        }
    }
    my_print();
    return;
}
void left()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            tempgrid[n + 1 - j][i] = grid[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            grid[i][j] = tempgrid[i][j];
        }
    }
    my_print();
    return;
}
int main()
{

    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
    fall();
    char op;
    int row, col;
    int cnt = 0;
    while (q--)
    {
        scanf("%c", &op);
        if (op == 'R')
        {
            scanf("%d %d", &row, &col);
            right();
            fall();
            if (grid[row][col] == 0)
            {
                cnt++;
            }
            else
            {
                grid[row][col] = 0;
                fall();
            }
        }
        else if (op == 'L')
        {
            scanf("%d %d", &row, &col);
            left();
            fall();
            if (grid[row][col] == 0)
            {
                cnt++;
            }
            else
            {
                grid[row][col] = 0;
                fall();
            }
        }
        else
        {
            printf("%c:error\n", op);
        }
        getchar();
    }

    // print;
    my_print();
    printf("%d", cnt);
    return 0;
}