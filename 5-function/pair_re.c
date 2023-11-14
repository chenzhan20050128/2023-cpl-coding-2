#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define maxn 1010 // 1000010
int a[maxn];
int b[maxn];
int n, m, t;
int minnum = 2147483647;
int min(int q, int w)
{
    if (q > w)
    {
        return w;
    }
    else
    {
        return q;
    }
}
void solve(int remain)
{
    int l = 0;
    int r = n - 1;
    int mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (remain - a[mid] > 0)
        {
            l = mid + 1;
            minnum = min(minnum, remain - a[mid]);
        }
        else if (remain - a[mid] == 0)
        {
            minnum = 0;
            return;
        }
        else
        {
            r = mid;
        }
    }
    mid = (l + r) / 2;
    if (remain - a[mid] >= 0)
    {
        minnum = min(minnum, remain - a[mid]);
        return;
    }
    else
    {
        return;
    }
}
int main()
{
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j <= m - 1; j++)
    {
        scanf("%d", &b[j]);
        solve(t - b[j]);
    }
    if (minnum == 2147483647)
    {
        printf("%d", -1);
    }
    else
    {
        printf("%d", minnum);
    }
    return 0;
}