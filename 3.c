#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    long long nn = pow(n, n);
    long long cnt = 0;
    for (long long i = 1; i <= nn; i++)
    {
        if (((i % k) % n == 0) && i % 10 == n)
        {
            cnt++;
        }
    }
    printf("%lld", cnt);
    return 0;
}