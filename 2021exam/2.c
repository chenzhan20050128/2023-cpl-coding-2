#include <stdio.h>
#include <math.h>
#define maxn 1010 // 1000100
int num[maxn];
int n, q;
int query;
int check(int x)
{
    int l = 0;
    int r = n - 1;
    int m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (num[m] == x)
        {
            return m;
        }
        else if (num[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}
int main()
{

    scanf("%d %d", &n, &q);
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &num[i]);
    }
    for (int j = 1; j <= q; j++)
    {
        scanf("%d", &query);
        printf("%d\n", check(query));
    }
}