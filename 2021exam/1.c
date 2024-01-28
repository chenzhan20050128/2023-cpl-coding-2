#include <stdio.h>
#include <math.h>

int num[1010];

int main()
{
    int t;
    int n, m;
    scanf("%d", &t);
    int x;
    int temp;
    int flag = 1;
    while (t--)
    {
        flag = 1;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
        }
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &x);
            temp = num[x];
            for (int i = x; i >= 2; i--)
            {
                num[i] = num[i - 1];
            }
            num[1] = temp;
        }
        // printf("---\n");
        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%d ", num[i]);
        // }
        // printf("\n---\n");
        for (int i = 1; i <= m - 1; i++)
        {
            if (num[i] <= num[i + 1])
            {
            }
            else
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            printf("I love C programming language\n");
        }
        else if (flag == 0)
        {
            printf("mayi is a good teacher\n");
        }
    }
}