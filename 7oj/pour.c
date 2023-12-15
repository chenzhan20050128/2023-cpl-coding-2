
#include <stdio.h>
#include <string.h>
#include <math.h>
int k;
int va;
int vb;
int vc;
int a, b, c;
int a0, b0, c0;
int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a > b ? b : a;
}
int solve(int remain, int now_a, int now_b, int now_c)
{
    if (remain == 0)
    {
        if (now_a == a0 && now_b == b0 && now_c == c0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int total = 0;
    total += solve(remain - 1, 0, min(vb, now_a + now_b), now_c);
    total += solve(remain - 1, 0, now_b, min(vc, now_a + now_c));
    total += solve(remain - 1, min(va, now_a + now_b), 0, now_c);
    total += solve(remain - 1, now_a, 0, min(vc, now_b + now_c));
    total += solve(remain - 1, min(va, now_a + now_c), now_b, 0);
    total += solve(remain - 1, now_a, min(vb, now_b + now_c), 0);
    if (total > 0)
    {
        return total;
    }
    else
    {
        return 0;
    }
}
int main()
{
    scanf("%d %d %d %d %d %d %d %d %d %d", &k, &va, &vb, &vc, &a, &b, &c, &a0, &b0, &c0);
    int sum;
    sum = solve(k, a, b, c);
    // printf("%d\n", sum);
    if (sum > 0)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}