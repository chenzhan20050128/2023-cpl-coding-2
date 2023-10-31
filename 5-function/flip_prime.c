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

int flip_num(int num)
{
    int result = 0;
    while (num > 0)
    {
        result = result * 10 + (num % 10);
        num = num / 10;
    }
    return result;
}

int main()
{
    int ceil_num;
    int cnt = 0;
    scanf("%d", &ceil_num);
    for (int i = 2; i <= ceil_num; i++)
    {
        if (is_prime(i) && is_prime(flip_num(i)))
        {
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}