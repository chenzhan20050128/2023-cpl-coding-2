#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxn 1010 // 1000010
int n, m, t;
int a[maxn];
int b[maxn];
int check(int minus, int idx)
{
    if (minus - a[idx] >= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int find_ans(int minus)
{
    int l = 1;
    int r = n;
    int mid = -1;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (check(minus, mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    if (l == r && check(minus, (l + r) / 2))
    {
        return (l + r) / 2;
    }
    else
    {
        return -1;
    }
}
int main()
{

    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }
    // a是单增
    int minans = 2147483647;
    int temp;
    for (int i = 1; i <= m; i++)
    {
        temp = find_ans(t - b[i]);
        if (temp != -1 && minans > t - b[i] - a[temp])
        {
            minans = t - b[i] - a[temp];
        }
    }
    if (minans != 2147483647)
    {
        printf("%d", minans);
    }
    else
    {
        printf("%d", -1);
    }

    return 0;
}