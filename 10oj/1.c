#include <stdio.h>
#include <stdlib.h>
#define maxn 1010 // 1000010
int num[maxn];
int *cmp_int(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b)
    {
        return (int *)-1;
    }
    else if (*(int *)a > *(int *)b)
    {
        return (int *)1;
    }
    else
    {
        return (int *)0;
    }
}
int main()
{
    int n, q;
    int temp;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &temp);
        int *res = (int *)bsearch(&temp, num, n, sizeof(num[0]), cmp_int);
        if (res != NULL)
        {
            printf("%d\n", *res);
        }
        else
        {
            printf("%d\n", -1);
        }
    }
}