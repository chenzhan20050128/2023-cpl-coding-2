#include <stdio.h>
#include <math.h>

long long producenum(int n, int t)
{
    long long result = 0;
    for (int i = 1; i <= n; i++)
    {
        result += t * pow(10, i - 1);
    }
    return result;
}
int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += producenum(i, t);
    }
    printf("%lld", sum);
    return 0;
}