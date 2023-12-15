#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void printMap(int bombMap[32][32], int findMap[32][32], int maxx, int maxy, int visible)
{
    for (int i = 0; i <= maxy; i++)
    {
        if (i == 0)
            printf("  ");
        else if (i < 10)
            printf("%d ", i);
        else
            printf("%c ", i - 10 + 'a');
    }
    printf("\n");
    for (int i = 1; i <= maxx; i++)
    {
        if (i < 10)
            printf("%d ", i);
        else
            printf("%c ", i - 10 + 'a');
        for (int j = 1; j <= maxy; j++)
        {
            if (visible || findMap[i][j] == 1)
            {
                if (bombMap[i][j] == 9)
                    printf("* ");
                else if (bombMap[i][j] == 0)
                    printf("  ");
                else
                    printf("%d ", bombMap[i][j]);
            }
            else if (findMap[i][j] == 2)
                printf("! ");
            else
                printf("? ");
        }
        if (i < 10)
            printf("%d ", i);
        else
            printf("%c ", i - 10 + 'a');
        printf("\n");
    }
    for (int i = 0; i <= maxy; i++)
    {
        if (i == 0)
            printf("  ");
        else if (i < 10)
            printf("%d ", i);
        else
            printf("%c ", i - 10 + 'a');
    }
    printf("\n");
}
void initMap(int bombMap[32][32], int maxx, int maxy, int totalBomb)
{
    int cnt = 0, x = 0, y = 0;
    const int v8[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            bombMap[i][j] = 0;
        }
    }
    while (cnt < totalBomb)
    {
        x = rand() % maxx + 1;
        y = rand() % maxy + 1;
        if (!bombMap[x][y])
        {
            bombMap[x][y] = 9;
            cnt++;
        }
    }
    for (int i = 1; i <= maxx; i++)
    {
        for (int j = 1; j <= maxy; j++)
        {
            if (bombMap[i][j] == 9)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (bombMap[i + v8[k][0]][j + v8[k][1]] != 9)
                    {
                        bombMap[i + v8[k][0]][j + v8[k][1]]++;
                    }
                }
            }
        }
    }
}
int checkXY(int x, int y, int maxx, int maxy)
{
    return x > 0 && y > 0 && x <= maxx && y <= maxy;
}
int inXY(char in[10])
{
    int x, y;
    if (in[0] >= '0' && in[0] <= '9')
        return in[0] - '0';
    else if (in[0] >= 'a' && in[0] <= 'z')
        return in[0] - 'a' + 10;
    else if (in[0] >= 'A' && in[0] <= 'Z')
        return in[0] - 'A' + 10;
    else
        return 114514;
}
int inputXY(int maxx, int maxy)
{
    char inx[10], iny[10], inmethod[10];
    int x, y;
    printf("Input row & col & c(clear)/f(flag): ");
    scanf("%s %s %s", inx, iny, inmethod);
    x = inXY(inx);
    y = inXY(iny);
    // printf("%d %d\n", x, y);
    while (!checkXY(x, y, maxx, maxy) || (inmethod[0] != 'c' && inmethod[0] != 'f'))
    {
        printf("Illegal number! Please input again: ");
        scanf("%s %s %s", inx, iny, inmethod);
        x = inXY(inx);
        y = inXY(iny);
    }
    // printf("100x+y: %d", x * 100 + y + (inmethod[0] == 'f' ? 10000 : 0));
    return x * 100 + y + (inmethod[0] == 'f' ? 10000 : 0);
}
int checkClear(int bombMap[32][32], int findMap[32][32], int x, int y, int maxx, int maxy)
{
    int cnt = 0;
    const int v8[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    for (int i = 0; i < 8; i++)
    {
        if (findMap[x + v8[i][0]][y + v8[i][1]] == 2)
            cnt++;
    }
    if (cnt == bombMap[x][y])
        return 1;
    else
        return 0;
}
int discover(int bombMap[32][32], int findMap[32][32], int x, int y, int maxx, int maxy)
{
    int cnt = 0;
    const int v8[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    if (checkXY(x, y, maxx, maxy) && findMap[x][y] == 0)
    {
        findMap[x][y] = 1;
        cnt++;
        if (bombMap[x][y] == 9)
        {
            return -1;
        }
        else if (bombMap[x][y] == 0)
        {
            for (int k = 0; k < 8; k++)
            {
                if (checkXY(x + v8[k][0], y + v8[k][1], maxx, maxy))
                    cnt += discover(bombMap, findMap, x + v8[k][0], y + v8[k][1], maxx, maxy);
            }
        }
    }
    return cnt;
}
int main()
{
    int curtime = time(NULL);
    srand(curtime);
    printf("%d\n", curtime);
    // printf("%d %d %d\n", rand(), rand(), rand());

    int bombMap[32][32] = {0}, findMap[32][32] = {0}, totalBomb = 10, maxx = 10, maxy = 10, cnt = 0, x = 0, y = 0, tmp, end = 0, method = 0;
    const int v8[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    char difficulty[10];

    printf("Input difficulty (easy/normal/hard): ");
    scanf("%s", difficulty);
    if (difficulty[0] == 'h')
    {
        maxx = 16;
        maxy = 30;
        totalBomb = 99;
    }
    else if (difficulty[0] == 'n')
    {
        maxx = 16;
        maxy = 16;
        totalBomb = 40;
    }
    printMap(bombMap, findMap, maxx, maxy, 0);

    tmp = inputXY(maxx, maxy);
    x = tmp / 100 % 100;
    y = tmp % 100;

    initMap(bombMap, maxx, maxy, totalBomb);
    while (bombMap[x][y] != 0)
    {
        initMap(bombMap, maxx, maxy, totalBomb);
    }
    cnt += discover(bombMap, findMap, x, y, maxx, maxy);
    system("cls");
    printMap(bombMap, findMap, maxx, maxy, 0);

    while (!end && cnt < maxx * maxy - totalBomb)
    {
        tmp = inputXY(maxx, maxy);
        x = tmp / 100 % 100;
        y = tmp % 100;
        method = tmp / 10000;
        // printf("%d %d\n", x, y);
        if (method)
        {
            if (findMap[x][y] == 0)
                findMap[x][y] = 2;
            else if (findMap[x][y] == 2)
                findMap[x][y] = 0;
        }
        else
        {
            if (findMap[x][y] == 0)
            {
                tmp = discover(bombMap, findMap, x, y, maxx, maxy);
                if (tmp == -1)
                {
                    end = 1;
                }
                else
                    cnt += tmp;
            }
            else if (findMap[x][y] == 1)
            {
                if (checkClear(bombMap, findMap, x, y, maxx, maxy))
                {
                    for (int k = 0; k < 8; k++)
                    {
                        tmp = discover(bombMap, findMap, x + v8[k][0], y + v8[k][1], maxx, maxy);
                        if (tmp == -1)
                        {
                            end = 1;
                            // break;
                        }
                        else
                            cnt += tmp;
                    }
                }
            }
        }
        system("cls");
        printMap(bombMap, findMap, maxx, maxy, 0);
    }

    printf(end ? "Game over!\n" : "You win!\n");
    printMap(bombMap, findMap, maxx, maxy, 1);
    printf("Press ENTER to exit.");
    system("pause");
    return 0;
}