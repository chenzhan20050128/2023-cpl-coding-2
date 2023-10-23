#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int numbers[22];
int try_mol(int n)
{
    if (n / 1000 != 0)
    {
        return 10000;
    }
    else if (n / 100 != 0)
    {
        return 1000;
    }
    else if (n / 10 != 0)
    {
        return 100;
    }
    else if (n != 0)
    {
        return 10;
    }
    else
    {
        return -1;
    }
}
int check(int k)
{
    // int flag = 0;
    for (int n = 1; n <= 9; n++)
    {
        if ((int)(n * pow(k, 2)) % (try_mol(k)) == k)
        {
            // flag = 1;
            return n;
        }
    }
    return -1;
}

int main()
{
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &numbers[i]);
        int temp = check(numbers[i]);
        if (temp != -1)
        {
            printf("%d %d\n", temp, temp * numbers[i] * numbers[i]);
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}