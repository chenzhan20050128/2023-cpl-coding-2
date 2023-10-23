#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define maxn 1010
int used[128] = {0};
char a[maxn];
char b[maxn];
int read_a()
{
    char temp;
    int cnt = 0;
    scanf("%c", &temp);
    while (temp != '\n')
    {
        cnt++;
        a[cnt] = temp;
        scanf("%c", &temp);
    }
    return cnt;
}
int read_b()
{
    char temp;
    int cnt = 0;
    scanf("%c", &temp);
    while (temp != '\n')
    {
        cnt++;
        b[cnt] = temp;
        scanf("%c", &temp);
    }
    return cnt;
}
int main()
{
    int la = read_a();
    int lb = read_b();
    for (int i = 0; i < la; i++)
    {
        if (used[(int)a[i]] == 0)
        {
            used[(int)a[i]] = 1;
            printf("%c", a[i]);
        }
    }
    for (int i = 0; i < lb; i++)
    {
        if (used[(int)b[i]] == 0)
        {
            used[(int)b[i]] = 1;
            printf("%c", b[i]);
        }
    }

    return 0;
}