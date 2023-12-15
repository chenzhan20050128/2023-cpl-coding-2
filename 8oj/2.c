#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char *s = (char *)malloc(100010 * sizeof(char));
    char *t = (char *)malloc(100010 * sizeof(char));
    scanf("%s", s);
    scanf("%s", t);
    int slen = strlen(s);
    int tlen = strlen(t);
    // printf("%d %d", slen, tlen);
    for (int i = 0; i <= slen - tlen; i++)
    {
        int flag = 1;
        int j = 0;
        while (flag && j < tlen)
        {
            if (*(s + i + j) != *(t + j))
            {
                flag = 0;
            }
            j++;
        }
        if (flag == 1)
        {
            printf("%d ", i);
        }
    }
    return 0;
}