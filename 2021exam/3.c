#include <stdio.h>
#include <math.h>
#include <string.h>
char grid[25][25] = {'\0'};
int in_range(int x, int y)
{
    return (1 <= x && x <= 20 && 1 <= y && y <= 20);
}
int flip(char q)
{
    if (q == '#')
    {
        return '*';
    }
    else if (q == '*')
    {
        return '#';
    }
}
int num_of_death4(int x, int y, char query)
{
    int sum = 0;
    int flag;
    // x+ y+
    flag = 1;
    for (int i = 0; i <= 3 && flag; i++)
    {
        if (in_range(x + i, y + i) && grid[x + i][y + i] == query)
        {
        }
        else
        {
            flag = 0;
        }
    }
    if (flag)
    {
        if (grid[x - 1][y - 1] == flip(query) && grid[x + 4][y + 4] != flip(query))
        {
            sum += 1;
        }
        else
        {
        }
    }
    // x+ y-
    flag = 1;
    for (int i = 0; i <= 3 && flag; i++)
    {
        if (in_range(x + i, y - i) && grid[x + i][y - i] == query)
        {
        }
        else
        {
            flag = 0;
        }
    }
    if (flag)
    {
        if (grid[x - 1][y + 1] == flip(query) && grid[x + 4][y - 4] != flip(query))
        {
            sum += 1;
        }
        else
        {
        }
    }
    // x= y+
    flag = 1;
    for (int i = 0; i <= 3 && flag; i++)
    {
        if (in_range(x, y + i) && grid[x][y + i] == query)
        {
        }
        else
        {
            flag = 0;
        }
    }
    if (flag)
    {
        if (grid[x][y - 1] == flip(query) && grid[x][y + 4] != flip(query))
        {
            sum += 1;
        }
        else
        {
        }
    }
    // x+ y=
    flag = 1;
    for (int i = 0; i <= 3 && flag; i++)
    {
        if (in_range(x + i, y) && grid[x + i][y] == query)
        {
        }
        else
        {
            flag = 0;
        }
    }
    if (flag)
    {
        if (grid[x - 1][y] == flip(query) && grid[x + 4][y] != flip(query))
        {
            sum += 1;
        }
        else
        {
        }
    }

    return sum;
}
int num_of_alive4(int x, int y, char query)
{
    int sum = 0;
    int flag;
    // x+ y+
    flag = 1;
    for (int i = 0; i <= 3 && flag; i++)
    {
        if (in_range(x + i, y + i) && grid[x + i][y + i] == query)
        {
        }
        else
        {
            flag = 0;
        }
    }
    if (flag)
    {
        if (in_range(x - 1, y - 1) && in_range(x + 4, y + 4) && grid[x - 1][y - 1] != flip(query) && grid[x + 4][y + 4] != flip(query))
        {
            sum += 1;
        }
        else
        {
        }
    }
    // x+ y-
    flag = 1;
    for (int i = 0; i <= 3 && flag; i++)
    {
        if (in_range(x + i, y - i) && grid[x + i][y - i] == query)
        {
        }
        else
        {
            flag = 0;
        }
    }
    if (flag)
    {
        if (in_range(x - 1, y + 1) && in_range(x + 4, y - 4) && grid[x - 1][y + 1] != flip(query) && grid[x + 4][y - 4] != flip(query))
        {
            sum += 1;
        }
        else
        {
        }
    }
    // x= y+
    flag = 1;
    for (int i = 0; i <= 3 && flag; i++)
    {
        if (in_range(x, y + i) && grid[x][y + i] == query)
        {
        }
        else
        {
            flag = 0;
        }
    }
    if (flag)
    {
        if (in_range(x, y - 1) && in_range(x, y + 4) && grid[x][y - 1] != flip(query) && grid[x][y + 4] != flip(query))
        {
            sum += 1;
        }
        else
        {
        }
    }
    // x+ y=
    flag = 1;
    for (int i = 0; i <= 3 && flag; i++)
    {
        if (in_range(x + i, y) && grid[x + i][y] == query)
        {
        }
        else
        {
            flag = 0;
        }
    }
    if (flag)
    {
        if (in_range(x - 1, y) && in_range(x + 4, y) && grid[x - 1][y] != flip(query) && grid[x + 4][y] != flip(query))
        {
            sum += 1;
        }
        else
        {
        }
    }

    return sum;
}
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        for (int i = 1; i <= 20; i++)
        {
            for (int j = 1; j <= 20; j++)
            {
                scanf("%c", &grid[i][j]);
            }
            getchar();
        }
        int black_death4 = 0;
        int black_alive4 = 0;
        int white_death4 = 0;
        int white_alive4 = 0;
        for (int i = 1; i <= 20; i++)
        {
            for (int j = 1; j <= 20; j++)
            {
                if (grid[i][j] == '_')
                {
                    continue;
                }
                else if (grid[i][j] == '#')
                {
                    black_death4 += num_of_death4(i, j, '#');
                    black_alive4 += num_of_alive4(i, j, '#');
                }
                else if (grid[i][j] == '*')
                {
                    white_death4 += num_of_death4(i, j, '*');
                    white_alive4 += num_of_alive4(i, j, '*');
                }
            }
        }
        //printf("\n%d %d %d %d\n", white_alive4, white_death4, black_alive4, black_death4);
        if (white_alive4 > 0 || white_death4 > 0)
        {
            printf("Lose\n");
        }
        else if (black_alive4 > 0 || black_death4 >= 2)
        {
            printf("Win\n");
        }
        else
        {
            printf("Not Sure\n");
        }
    }
    return 0;
}