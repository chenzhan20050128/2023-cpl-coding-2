#include <stdio.h>
#include <math.h>

int is_prime(int x)
{
    if (x == 0 || x == 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int is_sex_prime(int x)
{
    return (is_prime(x) && is_prime(x + 6));
}

int main()
{
    int n;
    scanf("%d", &n);
    if (is_prime(n) && is_prime(n - 6))
    {
        printf("Yes\n%d", n - 6);
    }
    else if (is_prime(n) && is_prime(n + 6))
    {
        printf("Yes\n%d", n + 6);
    }
    else
    {
        int x = n + 1;
        while (!(is_sex_prime(x)))
        {
            x++;
        }
        printf("No\n%d", x);
    }
}