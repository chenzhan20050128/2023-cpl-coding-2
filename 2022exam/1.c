#include <stdio.h>
#include <stdlib.h>
#define maxn 1010 // 100010
int num[maxn];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int maxnum = -2147483647;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
            if (num[i] > maxnum && i < n)
            {
                maxnum = num[i];
            }
        }
        // scanf("%d", num[n]);
        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%d ", num[i]);
        // }
        // printf("\n");
        if (maxnum <= num[n])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}