#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int to_decimal(int jinzhi, int x)
{
    int result = 0;
    int cnt = 0;
    while (x > 0)
    {
        if (x%10 >= jinzhi){
            return -1;
        }
        result += (x % 10) * pow(jinzhi, cnt);
        cnt += 1;
        x /= 10;
    }
    return result;
}
int main()
{
    int q, w, e;
    scanf("%d %d %d", &q, &w, &e);
    int ans = 0;
    for (int jinzhi = 2; jinzhi <= 1000; jinzhi++)
    {
        if (to_decimal(jinzhi, q) * to_decimal(jinzhi, w) == to_decimal(jinzhi, e))
        {
            ans = jinzhi;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}