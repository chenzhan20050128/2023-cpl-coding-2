#include <stdio.h>
#include <string.h>
#define maxn 1010 // 100010
char name[maxn][25];
int target[maxn] = {-1};
int process()
{
    int fastpos = 0;
    int slowpos = 0;
    fastpos += 2;
    slowpos += 1;
    while (1)
    {
        if (fastpos == slowpos)
        {
        }
        else if (fastpos == -1 || slowpos == -1)
        {
            return -1;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        scanf("%s %d", name[i], &target[i]);
    }
    process();
}