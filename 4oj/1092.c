#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int sale[110][1010];
int store_max[1010];
int main()
{
    int n, m; // n:choices;m:citys;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &sale[i][j]);
        }
    }
    int maxsale = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= m; j++)
        {
            sum += sale[j][i];
        }
        sale[n + 1][i] = sum; // total of choices;
        if (maxsale < sale[n + 1][i])
        {
            maxsale = sale[n + 1][i];
        }
    }
    printf("%d\n", maxsale);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sale[n + 1][i] == maxsale)
        {
            cnt ++;
            store_max[cnt] = i;
        }
    }
    for (int i = 1;i<=cnt-1;i++){
        printf("%d",store_max[i]);
        printf(" ");
    }
    printf("%d",store_max[cnt]);
    return 0;
}