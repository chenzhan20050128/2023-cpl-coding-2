#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int compare(const void *a, const void *b)
{
    int ans = 0;
    if (*(int *)a > *(int *)b)
        ans = 1;
    if (*(int *)a < *(int *)b)
        ans = -1;
    return ans;
}

int n, q, arr[1000005], quiry;

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &quiry);
        long long tmp = &arr;
        if (bsearch(&quiry, arr, n, sizeof(int), compare))
            printf("%d\n", (long long)(bsearch(&quiry, arr, n, sizeof(int), compare) - tmp) / 4);
        else
            printf("-1\n");
    }
    return 0;
}