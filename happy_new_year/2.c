#include <stdio.h>
#include <math.h>
int cal(char c)
{
    if ('A' <= c && c <= 'F')
    {
        return 10 + (c - 'A');
    }
    else
    {
        return (c - '0');
    }
}
int t(char high, char low)
{
    return (cal(high) * 16 + cal(low) * 1);
}
int t16(int num)
{
    if (num >= 10)
    {
        return 'A' + (num - 10);
    }
    else
    {
        return '0' + num;
    }
}
int main()
{
    int q;
    scanf("%d", &q);
    char s1[10], s2[10];
    while (q--)
    {
        scanf("%s", s1);
        scanf("%s", s2);
        int r = t(s1[1], s1[2]) + t(s2[1], s2[2]);
        int g = t(s1[3], s1[4]) + t(s2[3], s2[4]);
        int b = t(s1[5], s1[6]) + t(s2[5], s2[6]);
        char s3[10];
        s3[0] = '#';
        s3[1] = t16(r / 16);
        s3[2] = t16(r % 16);
        s3[3] = t16(g / 16);
        s3[4] = t16(g % 16);
        s3[5] = t16(b / 16);
        s3[6] = t16(b % 16);
        s3[7] = '\0';
        printf("%s\n", s3);
    }
    return 0;
}