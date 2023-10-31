#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define maxn 1010
#define int_max 2147483647
char life[maxn];
char new_life[maxn];
int slen;
int what(int x)
{
    if (life[x] = '.')
    {
        int my = 'A';
        int dif = 'B';
        int cnt = 0;
        for (int i = x - 3; i <= x + 3; i++)
        {
            if (i >= 0 && i <= slen - 1)
            {
                if (life[i] == dif)
                {
                    break;
                }
                else if (life[i] == my)
                {
                    cnt++;
                }
            }
        }
        if (cnt >= 2 && cnt <= 4)
        {
            return my;
        }

        my = 'B';
        dif = 'A';
        cnt = 0;
        for (int i = x - 3; i <= x + 3; i++)
        {
            if (i >= 0 && i <= slen - 1 && i != x)
            {
                if (life[i] == dif)
                {
                    break;
                }
                else if (life[i] == my)
                {
                    cnt++;
                }
            }
        }
        if (cnt >= 2 && cnt <= 4)
        {
            return my;
        }

        return '.';
    }
    else if (life[x] == 'A')
    {
        int cnt = 0;
        for (int i = x - 3; i <= x + 3; i++)
        {
            if (i >= 0 && i <= slen - 1 && i != x)
            {
                if (life[i] == 'B')
                {
                    return '.';
                }
                else if (life[i] == 'A')
                {
                    cnt++;
                }
            }
        }
        if (cnt <= 1 || cnt >= 5)
        {
            return '.';
        }
        else
        {
            return 'A';
        }
    }
    else if (life[x] == 'B')
    {
        int cnt = 0;
        for (int i = x - 3; i <= x + 3; i++)
        {
            if (i >= 0 && i <= slen - 1 && i != x)
            {
                if (life[i] == 'A')
                {
                    return '.';
                }
                else if (life[i] == 'B')
                {
                    cnt++;
                }
            }
        }
        if (cnt <= 1 || cnt >= 5)
        {
            return '.';
        }
        else
        {
            return 'B';
        }
    }
}
int main()
{
    int n;
    scanf("%d\n", &n);
    memset(life, '.', sizeof(life));
    memset(new_life, '.', sizeof(new_life));
    scanf("%s", &life);
    slen = strlen(life);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= slen - 1; j++)
        {
            new_life[j] = what(j);
        }
        strncpy(life, new_life, slen);
    }
    for (int i = 0; i <= slen - 1; i++)
    {
        printf("%c", life[i]);
    }
    return 0;
}