#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxn 100010 // 100010
int ans[maxn][2];
int numbers[maxn];
int maxi(int l, int r)
{
    int maxnum = -2147483647;
    int maxindex = -1;
    for (int i = l; i <= r; i++)
    {
        if (maxnum < numbers[i])
        {
            maxnum = numbers[i];
            maxindex = i;
        }
    }
    return maxindex;
}
void conduct(int l, int r)
{
    if (l == r)
    {
        ans[l][0] = l;
        ans[l][1] = l;
        return;
    }
    if (l > r)
    {
        return;
    }
    if (l + 1 == r)
    {
        if (numbers[l + 1] > numbers[l])
        {
            ans[l][0] = l;
            ans[l][1] = l;
            ans[l + 1][0] = l;
            ans[l + 1][1] = l + 1;
        }
        else
        {
            ans[l][0] = l;
            ans[l][1] = l + 1;
            ans[l + 1][0] = l + 1;
            ans[l + 1][1] = l + 1;
        }
        return;
    }
    int maxindex = maxi(l, r);
    ans[maxindex][0] = l;
    ans[maxindex][1] = r;
    conduct(l, maxindex - 1);
    conduct(maxindex + 1, r);
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &numbers[i]);
    }
    conduct(1, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}