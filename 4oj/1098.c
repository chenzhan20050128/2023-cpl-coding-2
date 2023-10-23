#include <stdio.h>
#include <math.h>
int a[110];
int b[110];
int main()
{
    int n;
    scanf("%d", &n);
    int mina = 2147483647;
    int maxb = -2147483647;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] < mina)
        {
            mina = a[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        if (b[i] > maxb)
        {
            maxb = b[i];
        }
    }

    if (mina > maxb)
    {
        printf("Yes %d", mina - maxb);
    }
    else
    {
        printf("No %d", maxb - mina + 1);
    }
    return 0;
}