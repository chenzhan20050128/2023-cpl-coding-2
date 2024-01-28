#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long result;
    long long temp;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            scanf("%lld", &result);
        }
        else
        {
            scanf("%lld", &temp);
            result = result ^ temp;
        }
    }
    printf("%lld %lld", result, 0);
    return 0;
}