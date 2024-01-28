#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 10005
int n, Q, tot;
char mp[1005][1005], temp[1005];
int sum[1005], col[1005], que[100005];

void Turn(int o)
{
    memmove(temp + 1, col + 1, sizeof(int) * n);
    if (!o)
        for (int i = 1; i <= n; ++i)
            col[i] = sum[i] = 0, col[n - temp[i] + 1] = i;
    else
        for (int i = 1; i <= n; ++i)
            col[i] = sum[i] = 0, col[temp[n - i + 1] + 1] = i;
    for (int i = 1; i <= n; ++i)
        for (int j = n - col[i] + 1; j >= 1 && mp[j][i] == '1'; --j)
            sum[col[i]]++;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (j <= n - sum[i])
                mp[j][i] = '0';
            else
                mp[j][i] = '1';
}

int main()
{
    scanf("%d%d", &n, &Q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", mp[i] + 1);
        for (int j = 1; j <= n; ++j)
            sum[j] += (mp[i][j] == '1');
        col[i] = sum[i];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n - col[i]; ++j)
            mp[j][i] = '0';
    else mp[j][i] = '1';
    for (int i = 1; i <= Q; ++i)
    {
        char ch;
        int x, y;
        while (ch = getchar())
            if (ch == 'L' || ch == 'R')
                break;
        scanf("%d%d", &x, &y);
        Turn(ch == 'L');
        if (mp[x][y] == '0')
            que[++tot] = i;
        else
        {
            mp[x][y] = '0';
            sum[y]--;
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%s\n", mp[i] + 1);
    printf("%d\n", tot);
    return 0;
}