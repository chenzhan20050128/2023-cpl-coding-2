#include <stdio.h>
#include <string.h>
void draw(int a, int b, int c)
{
    char grid[100][100];
    for (int i = 1; i <= 99; i++)
    {
        for (int j = 1; j <= 99; j++)
        {
            grid[i][j] = ' ';
        }
    }
    int col = 2 * b + 2 * a + 1;
    int row = 2 * b + 2 * c + 1;
    // draw the forward;
    for (int i = 2 * b + 1; i <= row; i++)
    {
        for (int j = 1; j <= 2 * a + 1; j++)
        {
            if (i % 2 == 1 && j % 2 == 1)
            {
                grid[i][j] = '+';
            }
            else if (i % 2 == 0 && j % 2 == 1)
            {
                grid[i][j] = '|';
            }
            else if (i % 2 == 1 && j % 2 == 0)
            {
                grid[i][j] = '-';
            }
        }
    }
    // draw the up;
    for (int i = 1; i <= 2 * b + 1; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (i % 2 == 1 && j % 2 == 1 && i + j >= 2 * (b + 1) && i + j <= 2 * (a + b + 1))
            {
                grid[i][j] = '+';
            }
            else if (i % 2 == 0 && j % 2 == 0 && i + j >= 2 * (b + 1) && i + j <= 2 * (a + b + 1))
            {
                grid[i][j] = '/';
            }
            else if (i % 2 == 1 && j % 2 == 0 && i + j >= 2 * (b + 1) && i + j < 2 * (a + b + 1))
            {
                grid[i][j] = '-';
            }
        }
    }
    // draw the right;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 2 * a + 1; j <= col; j++)
        {
            if (i % 2 == 1 && j % 2 == 1 && i + j >= 2 * (a + b + 1) && i + j <= 2 * (a + b + c + 1))
            {
                grid[i][j] = '+';
            }
            else if (i % 2 == 0 && j % 2 == 0 && i + j >= 2 * (a + b + 1) && i + j <= 2 * (a + b + c + 1))
            {
                grid[i][j] = '/';
            }
            else if (i % 2 == 0 && j % 2 == 1 && i + j >= 2 * (a + b + 1) && i + j <= 2 * (a + b + c + 1))
            {
                grid[i][j] = '|';
            }
        }
    }
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    
}
int main()
{
    int n;
    scanf("%d", &n);
    int a, b, c;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        draw(a, b, c);
    }
    return 0;
}