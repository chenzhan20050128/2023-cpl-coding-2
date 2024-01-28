#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 3050
char str[maxn][maxn];
char *cal_minstr(char *s, int slen)
{
    char *result = (char *)malloc(sizeof(char) * maxn);
    int bu[26] = {0};
    for (int i = 0; i < slen; i++)
    {
        bu[s[i] - 'a']++;
    }
    int now_minchar = 0;
    for (int i = 0; i < slen; i++)
    {
        while (bu[now_minchar] == 0)
        {
            now_minchar += 1;
        }
        result[i] = 'a' + now_minchar;
        bu[now_minchar] -= 1;
    }
    result[slen] = '\0';
    return result;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m - 1; j++)
        {
            scanf("%c", str[i][j]);
        }
        str[i][m] = '\0';
        getchar();
    }
    for (int i = 1; i <= n; i++)
    {
        char *result = cal_minstr(s, strlen(s));
        printf("%s", result);
        free(result);
    }
    
}