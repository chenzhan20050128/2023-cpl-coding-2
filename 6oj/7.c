#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ans[1010];
void findDecomposition(int n, int min, int nFound)
{
    if (n == 0)
    {
        for (int i = 0; i < nFound; i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }
    if (n < min)
    {
        return;
    }
    for (int i = min; i <= n; i++)
    {
        ans[nFound] = i;
        findDecomposition(n - i, i, nFound + 1);
    }
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    findDecomposition(n, 1, 0);
    return 0;
}