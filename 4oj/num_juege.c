#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int initnums[10][10];
int judge[10];
int judge_complete(int num1, int num2, int num3, int num4, int num5, int num6, int num7, int num8, int num9)
{
    for (int i = 1; i <= 9; i++)
    {
        judge[i] = 0;
    }
    judge[num1] = 1;
    judge[num2] = 1;
    judge[num3] = 1;
    judge[num4] = 1;
    judge[num5] = 1;
    judge[num6] = 1;
    judge[num7] = 1;
    judge[num8] = 1;
    judge[num9] = 1;
    int flag = 1;
    for (int i = 1; i <= 9; i++)
    {
        if (judge[i] == 0)
        {
            flag = 0;
            return 0;
        }
    }
    if (flag == 1)
    {
        return 1;
    }
}
int main()
{
    int global_flag = 1;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            scanf("%d", &initnums[i][j]);
        }
        
    }
    for (int i = 1; i <= 9; i++)
    {
        int a = judge_complete(initnums[i][1], initnums[i][2], initnums[i][3], initnums[i][4], initnums[i][5], initnums[i][6], initnums[i][7], initnums[i][8], initnums[i][9]);
        if (a == 0)
        {
            global_flag = 0;

            break;
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        int a = judge_complete(initnums[1][i], initnums[2][i], initnums[3][i], initnums[4][i], initnums[5][i], initnums[6][i], initnums[7][i], initnums[8][i], initnums[9][i]);
        if (a == 0)
        {
            global_flag = 0;

            break;
        }
    }
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            int a = judge_complete(initnums[3 * i + 1][3 * j + 1], initnums[3 * i + 2][3 * j + 1], initnums[3 * i + 3][3 * j + 1], initnums[3 * i + 1][3 * j + 2], initnums[3 * i + 2][3 * j + 2], initnums[3 * i + 3][3 * j + 2], initnums[3 * i + 1][3 * j + 3], initnums[3 * i + 2][3 * j + 3], initnums[3 * i + 3][3 * j + 3]);
            if (a == 0)
            {
                global_flag = 0;

                break;
            }
        }
    }
    if (global_flag == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}