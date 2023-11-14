#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int f[100005]; // 存储一开始读入的数组
int ans[100005];
int find(int x)
{
    if (f[x] == x)
    { // dosomething
        ans[x] = x;
        return x;
    }
    else
    {
        if (ans[x] != 0)
        {
            return ans[x]; // 记忆化搜索.
        }
        ans[x] = find(f[x]);
        return ans[x];
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &f[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        find(i);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}