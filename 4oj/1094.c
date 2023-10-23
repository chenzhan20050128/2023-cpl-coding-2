#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int numbers[1010];
long long is_prime(int x)
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
long long get_number(int k, int i)
{
    long long number = 0;
    for (int j = 0; j <= k - 1; j++)
    {
        number += numbers[i + j] * pow(10, k - j - 1);
    }
    return get_number;
}
int main()
{
    int l, k;
    scanf("%d %d\n", &l, &k);
    for (int i = 1; i <= l; i++)
    {
        numbers[i] = (int)getchar();
    }
    int flag = 0;
    for (int i = 1; i <= l - k; i++)
    {
        if (is_prime(get_number(k, i)))
        {
            flag = 1;
            // printf("%d\n", get_number(k,i));
            for (int q = 0; q <= k - 1; q++)
            {
                printf("%c", (char)numbers[i + q]);
            }
            break;
        }
    }
    if (flag == 0)
    {
        printf("404\n");
    }
    return 0;
}