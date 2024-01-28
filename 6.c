#include <stdio.h>
#include <stdlib.h>
int dif_sig(int x, int y)
{
    if (x * y < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    int num[100010];
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &num[i]);
        if (i >= 1)
        {
            if (dif_sig(num[i - 1], num[i]))
            {
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}