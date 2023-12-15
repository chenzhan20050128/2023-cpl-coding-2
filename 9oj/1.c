#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
void mystrcat(char *s1, char *s2)
{
    int s1len = strlen(s1);
    int s2len = strlen(s2);
    int minlen = min(s1len, s2len);
    int same = 0;
    for (int i = minlen; i >= 0; i--)
    {
        int j = 0;
        while (s1[s1len - i + j] == s2[j] && j < i)
        {
            j += 1;
        }
        if (s1[s1len - i + j] != s2[j] && j < i)
        {
        }
        else if (j == i)
        {
            same = j;
            break;
        }
    }
    printf("%s", s1);
    for (int i = same; i <= s2len - 1; i++)
    {
        printf("%c", s2[i]);
    }
    printf("\n");
    return;
}
int main()
{
    int t;
    scanf("%d", &t);
    char s1[1010];
    char s2[1010];
    for (int i = 1; i <= t; i++)
    {
        scanf("%s", &s1);
        scanf("%s", &s2);
        mystrcat(s1, s2);
    }
    return 0;
}