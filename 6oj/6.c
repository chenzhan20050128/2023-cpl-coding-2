#include <stdio.h>
#include <math.h>
#define maxn 10010

char grid[maxn][maxn];

// 绘制单个图案
void draw_alone(int row, int col)
{
    grid[row][col] = ' ';
    grid[row][col + 1] = '/';
    grid[row][col + 2] = '\\';
    grid[row][col + 3] = ' ';
    grid[row + 1][col] = '/';
    grid[row + 1][col + 1] = '_';
    grid[row + 1][col + 2] = '_';
    grid[row + 1][col + 3] = '\\';
}

// 递归绘制图案
void draw(int n, int row, int col)
{
    if (n == 1)
    {
        draw_alone(row, col); // 绘制单个图案
    }
    else if (n == 2)
    {
        draw(1, row, col + 2); // 绘制上方图案
        draw(1, row + 2, col); // 绘制左下方图案
        draw(1, row + 2, col + 4); // 绘制右下方图案
    }
    else
    {
        draw(n - 1, row, col + 4 * pow(2, n - 3)); // 绘制上方图案
        draw(n - 1, row + pow(2, n - 1), col); // 绘制左下方图案
        draw(n - 1, row + pow(2, n - 1), col + 4 * pow(2, n - 2)); // 绘制右下方图案
    }
}

int main()
{
    int n;
    scanf("%d", &n); // 输入绘制次数

    // 初始化 grid 数组
    for (int i = 0; i <= pow(2, n) - 1; i++)
    {
        for (int j = 0; j <= 4 * pow(2, n - 1) - 1; j++)
        {
            grid[i][j] = ' ';
        }
    }

    draw(n, 0, 0); // 调用绘制函数

    // 逐行打印 grid 数组
    for (int i = 0; i <= pow(2, n) - 1; i++)
    {
        for (int j = 0; j <= 4 * pow(2, n - 1) - 1; j++)
        {
            putchar(grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}