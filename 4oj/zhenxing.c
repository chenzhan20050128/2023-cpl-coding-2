#include <stdio.h>
#include <math.h>
int seq[2010] = {0};
int newseq[2010] = {0};
int cal(int l, int m, int r)
{
    if (l == 1 && m == 1 && r == 1)
    {
        return 0;
    }
    else if (l == 1 && m == 1 && r == 0)
    {
        return 1;
    }
    else if (l == 1 && m == 0 && r == 1)
    {
        return 1;
    }
    else if (l == 1 && m == 0 && r == 0)
    {
        return 0;
    }
    else if (l == 0 && m == 1 && r == 1)
    {
        return 1;
    }
    else if (l == 0 && m == 1 && r == 0)
    {
        return 1;
    }
    else if (l == 0 && m == 0 && r == 1)
    {
        return 1;
    }
    else if (l == 0 && m == 0 && r == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    //printf("%d %d",m,n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        seq[i] = (int)getchar()-48;
    }
    for (int i = 1; i <= m - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            newseq[j] = cal(seq[j - 1], seq[j], seq[j + 1]);
            printf("%d", newseq[j]);
        }
        printf("\n");
        for (int k = 1; k <= n; k++)
        {
            seq[k] = newseq[k];
        }
    }
    return 0;
}