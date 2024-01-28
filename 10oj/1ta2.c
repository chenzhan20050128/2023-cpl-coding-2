#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}

int n, q, arr[1000005], quiry;

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    while (q--)
    {
        scanf("%d", &quiry);
        int ans = bsearch(&quiry, arr, n, sizeof(int), cmp);
        printf("%d\n", ans ? (ans - (int)&arr) / 4 : -1);
    }
    return 0;
}