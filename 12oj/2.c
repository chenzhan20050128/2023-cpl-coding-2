#include <stdio.h>
#include <math.h>
#include <limits.h>
int in_range(long long x)
{
    if (INT_MIN <= x && x <= INT_MAX)
    {
        return 1;
    }
    return 0;
}
int main()
{
    long long xl, xu, yl, yu;
    scanf("%lld%lld%lld%lld", &xl, &xu, &yl, &yu);
    if (in_range(xl * yl) && in_range(xl * yu) && in_range(xu * yl) && in_range(xu * yu))
    {
        printf("int");
    }
    else
    {
        printf("long long int");
    }
    return 0;
}