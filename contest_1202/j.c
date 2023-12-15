#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxn 1010 // 100010
int alive[maxn];
int n;
int money = 0;
int previous_high;
int cal_remain()
{
    int cnt = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (alive[i] == 1)
        {
            cnt++;
        }
    }
    return cnt;
}
void process()
{

    int remain = cal_remain();
    int m = 0;
    int position = 0;
    while (remain > 1)
    {
        if (alive[position] == 1)
        {
            m++;
        }
        position = (position + 1) % (previous_high + 1);
        if (m == 2)
        {
            m = 0;
            alive[(position + previous_high) % (previous_high + 1)] = 0;
            remain -= 1;
        }
    }
    int survive;
    for (int i = 0; i < n; i++)
    {
        if (alive[i])
        {
            survive = i;
        }
    }
    // todo ：static the 1 money
    money += previous_high - survive;
    if (previous_high == survive)
    {
        // finish;
        money += 2 * (survive + 1);
        return;
    }
    else
    {
        previous_high = survive;
        for (int i = 0; i <= survive; i++)
        {
            alive[i] = 1;
        }
        process();
    }
    return;
}
int main()
{
    scanf("%d", &n);
    previous_high = n - 1;
    process();
    printf("%d", money);
    return 0;
}