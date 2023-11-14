#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define int long long
int to_decimal(int jinzhi, int x)
{
    int result = 0;
    int cnt = 0;
    while (x > 0)
    {
        if (x % 10 >= jinzhi)
        {
            return -1;
        }
        result += (x % 10) * pow(jinzhi, cnt);
        cnt += 1;
        x /= 10;
    }
    return result;
}
signed main()
{
    int q, w, e;
    scanf("%lld %lld %lld", &q, &w, &e);
    int ans = 0;
    for (int jinzhi = 2; jinzhi <= 1000; jinzhi++)
    {
        if (to_decimal(jinzhi, q) == -1 || to_decimal(jinzhi, w) == -1 || to_decimal(jinzhi, e) == -1)
        {
            continue;
        }
        else if (to_decimal(jinzhi, q) * to_decimal(jinzhi, w) == to_decimal(jinzhi, e))
        {
            ans = jinzhi;
            break;
        }
    }
    printf("%lld", ans);
    return 0;
}