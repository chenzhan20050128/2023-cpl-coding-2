#include <stdio.h>
#include <math.h>
#define maxn 10010

char grid[maxn][maxn];

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
void draw(int n, int row, int col)
{

    if (n == 1)
    {
        draw_alone(row, col);
    }
    else if (n == 2)
    {
        draw(1, row, col + 2);
        draw(1, row + 2, col);
        draw(1, row + 2, col + 4);
    }
    else
    {

        draw(n - 1, row, col + 4 * pow(2, n - 3));
        draw(n - 1, row + pow(2, n - 1), col);
        draw(n - 1, row + pow(2, n - 1), col + 4 * pow(2, n - 2));
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    // initialize the grid array;
    for (int i = 0; i <= pow(2, n) - 1; i++)
    {
        for (int j = 0; j <= 4 * pow(2, n - 1) - 1; j++)
        {
            grid[i][j] = ' ';
        }
    }
    // call the main function.
    draw(n, 0, 0);
    // print the array in turns.
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