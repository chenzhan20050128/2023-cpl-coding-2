#include <stdio.h>
#include <stdlib.h>
#define maxn 1000010
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int A[maxn];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < q; i++)
    {
        int query;
        scanf("%d", &query);
        int *result = (int *)bsearch(&query, A, n, sizeof(int), compare);
        if (result != NULL)
        {
            printf("%d\n", (int)(result - A));
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}
