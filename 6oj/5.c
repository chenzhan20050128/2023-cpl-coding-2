#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n, p;
int a[110];
// double dabs(double x)
// {
//     if (x < 0)
//     {
//         return (-1.0) * x;
//     }
//     else
//     {
//         return x;
//     }
// }
double f(double x)
{
    double result = 0;
    for (int i = 0; i <= n; i++)
    {
        result += (double)a[i] * pow(x, i);
    }
    if (p == 1)
    {
        return result;
    }
    else if (p == 2)
    {
        return pow(result, 2);
    }
    else if (p == -1)
    {
        return ((double)1) / result;
    }
    else if (p == -2)
    {
        return ((double)1) / (pow(result, 2));
    }
}
double simp(double a, double b)
{
    double result = 0;
    result += 4 * (f((a + b) / (double)2));
    result += f(a);
    result += f(b);
    result *= (b - a);
    result = result / (double)6;
    return result;
}
double cal(double l, double r, double bias)
{
    double mid = (l + r) / ((double)2);
    double sl = simp(l, mid);
    double sr = simp(mid, r);
    double s = simp(l, r);
    if (fabs(sl + sr - s) > 15 * bias)
    {
        // sl = cal(l, mid, bias / (double)2);
        // sr = cal(mid, r, bias / (double)2);
        return cal(l, mid, bias / ((double)2)) + cal(mid, r, bias / ((double)2));
    }
    return (sl + sr + (sl + sr - s) / ((double)15));
}
int main()
{
    scanf("%d %d", &n, &p);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    double a, b;
    scanf("%lf %lf", &a, &b);
    double ans = cal(a, b, 0.0001);
    printf("%lf", ans);
    return 0;
}