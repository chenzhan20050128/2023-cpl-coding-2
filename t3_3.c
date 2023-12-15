#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int r, c;
char grid[5010][5010];
int arrow[9000010][3];
int arrow_top = -1;
int main()
{
    scanf("%d %d", &r, &c);
    getchar();
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            scanf("%c", &grid[i][j]);
            if (grid[i][j] != '.')
            {
                arrow_top++;
                arrow[arrow_top][0] = i;
                arrow[arrow_top][1] = j;
                arrow[arrow_top][2] = grid[i][j];
            }
        }
        getchar();
    }
    // for (int i = 0;i<=arrow_top;i++){
    //     printf("%d %d %c\n",arrow[i][0],arrow[i][1],arrow[i][2]);
    // }
    int answer = 0;
    int total_flag = 1;
    int find_flag = 0;
    for (int i = 0; i <= arrow_top && total_flag == 1; i++)
    {
        if (arrow[i][2] == 'R')
        {
            find_flag = 0;
            for (int j = 0; j <= arrow_top && find_flag == 0; j++)
            {
                if (i != j)
                {
                    if (arrow[i][0] == arrow[j][0] && arrow[j][1] > arrow[i][1])
                    {
                        find_flag = 1;
                    }
                }
            }
            if (find_flag == 0)
            {
                // find u
                for (int j = 0; j <= arrow_top && find_flag == 0; j++)
                {
                    if (i != j)
                    {
                        if (arrow[i][1] == arrow[j][1] && arrow[j][0] < arrow[i][0])
                        {
                            // grid[arrow[i][0]][arrow[i][1]] = 'U';
                            find_flag = 1;
                            answer++;
                        }
                    }
                }
                // find down
                for (int j = 0; j <= arrow_top && find_flag == 0; j++)
                {
                    if (i != j)
                    {
                        if (arrow[i][1] == arrow[j][1] && arrow[j][0] > arrow[i][0])
                        {
                            // grid[arrow[i][0]][arrow[i][1]] = 'D';
                            find_flag = 1;
                            answer++;
                        }
                    }
                }
                // find left;
                for (int j = 0; j <= arrow_top && find_flag == 0; j++)
                {
                    if (i != j)
                    {
                        if (arrow[i][0] == arrow[j][0] && arrow[j][1] < arrow[i][1])
                        {
                            // grid[arrow[i][0]][arrow[i][1]] = 'L';
                            find_flag = 1;
                            answer++;
                        }
                    }
                }
                if (find_flag == 0)
                {
                    total_flag = -1;
                }
            }
        }
        else if (arrow[i][2] == 'L')
        {
            find_flag = 0;

            for (int j = 0; j <= arrow_top && find_flag == 0; j++)
            {
                if (i != j)
                {
                    if (arrow[i][0] == arrow[j][0] && arrow[j][1] < arrow[i][1])
                    {
                        find_flag = 1;
                    }
                }
            }
            if (find_flag == 0)
            {
                // find u
                for (int j = 0; j <= arrow_top && find_flag == 0; j++)
                {
                    if (i != j)
                    {
                        if (arrow[i][1] == arrow[j][1] && arrow[j][0] < arrow[i][0])
                        {
                            grid[arrow[i][0]][arrow[i][1]] = 'U';
                            find_flag = 1;
                            answer++;
                        }
                    }
                }
                // find down
                for (int j = 0; j <= arrow_top && find_flag == 0; j++)
                {
                    if (i != j)
                    {
                        if (arrow[i][1] == arrow[j][1] && arrow[j][0] > arrow[i][0])
                        {
                            grid[arrow[i][0]][arrow[i][1]] = 'D';
                            find_flag = 1;
                            answer++;
                        }
                    }
                }
                // find right;
                for (int j = 0; j <= arrow_top && find_flag == 0; j++)
                {
                    if (i != j)
                    {
                        if (arrow[i][0] == arrow[j][0] && arrow[j][1] > arrow[i][1])
                        {
                            grid[arrow[i][0]][arrow[i][1]] = 'R';
                            find_flag = 1;
                            answer++;
                        }
                    }
                }
                if (find_flag == 0)
                {
                    total_flag = -1;
                }
            }
        }
        else if (arrow[i][2] == 'U')
        {
            find_flag = 0;

            for (int j = 0; j <= arrow_top && find_flag == 0; j++)
            {
                if (i != j)
                {
                    if (arrow[i][1] == arrow[j][1] && arrow[j][0] < arrow[i][0])
                    {
                        find_flag = 1;
                    }
                }
            }
            if (find_flag == 0)
            {
                // find right
                for (int j = 0; j <= arrow_top && find_flag == 0; j++)
                {
                    if (i != j)
                    {
                        if (arrow[i][0] == arrow[j][0] && arrow[j][1] > arrow[i][1])
                        {
                            grid[arrow[i][0]][arrow[i][1]] = 'R';
                            find_flag = 1;
                            answer++;
                        }
                    }
                }
                // find down
                for (int j = 0; j <= arrow_top && find_flag == 0; j++)
                {
                    if (i != j)
                    {
                        if (arrow[i][1] == arrow[j][1] && arrow[j][0] > arrow[i][0])
                        {
                            grid[arrow[i][0]][arrow[i][1]] = 'D';
                            find_flag = 1;
                            answer++;
                        }
                    }
                }
                // find left;
                for (int j = 0; j <= arrow_top && find_flag == 0; j++)
                {
                    if (i != j)
                    {
                        if (arrow[i][0] == arrow[j][0] && arrow[j][1] < arrow[i][1])
                        {
                            grid[arrow[i][0]][arrow[i][1]] = 'L';
                            find_flag = 1;
                            answer++;
                        }
                    }
                }
                if (find_flag == 0)
                {
                    total_flag = -1;
                }
            }
        }
        if (arrow[i][2] == 'D')
        {
            find_flag = 0;

            for (int j = 0; j <= arrow_top && find_flag == 0; j++)
            {
                if (i != j)
                {
                    if (arrow[i][1] == arrow[j][1] && arrow[j][0] > arrow[i][0])
                    {
                        find_flag = 1;
                    }
                }
            }
            if (find_flag == 0)
            {
                // find u
                for (int j = 0; j <= arrow_top && find_flag == 0; j++)
                {
                    if (i != j)
                    {
                        if (arrow[i][1] == arrow[j][1] && arrow[j][0] < arrow[i][0])
                        {
                            grid[arrow[i][0]][arrow[i][1]] = 'U';
                            find_flag = 1;
                            answer++;
                        }
                    }
                }
                // find right
                for (int j = 0; j <= arrow_top && find_flag == 0; j++)
                {
                    if (i != j)
                    {
                        if (arrow[i][0] == arrow[j][0] && arrow[j][1] > arrow[i][1])
                        {
                            grid[arrow[i][0]][arrow[i][1]] = 'R';
                            find_flag = 1;
                            answer++;
                        }
                    }
                }
                // find left;
                for (int j = 0; j <= arrow_top && find_flag == 0; j++)
                {
                    if (i != j)
                    {
                        if (arrow[i][0] == arrow[j][0] && arrow[j][1] < arrow[i][1])
                        {
                            grid[arrow[i][0]][arrow[i][1]] = 'L';
                            find_flag = 1;
                            answer++;
                        }
                    }
                }
                if (find_flag == 0)
                {
                    total_flag = -1;
                }
            }
        }
    }
    if (total_flag == -1)
    {
        printf("%d", -1);
    }
    else
    {
        printf("%d", answer);
    }
    return 0;
}