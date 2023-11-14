#include <stdio.h>

#define MAX_N 100

int decompositions[MAX_N + 1][MAX_N + 1];

void printDecompositions(int n, int *decomposition, int pos)
{
    if (n == 0)
    {
        // 输出一个分解
        for (int i = 0; i < pos - 1; i++)
        {
            printf("%d+", decomposition[i]);
        }
        printf("%d\n", decomposition[pos - 1]);
        return;
    }

    int start = (pos == 0) ? 1 : decomposition[pos - 1];
    for (int i = start; i <= n; i++)
    {
        decomposition[pos] = i;
        printDecompositions(n - i, decomposition, pos + 1);
    }
}

int countDecompositions(int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (decompositions[n][0] != 0)
    {
        return decompositions[n][0];
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += countDecompositions(n - i);
    }

    decompositions[n][0] = count;
    return count;
}

int main()
{
    int n;
    printf("Enter a natural number: ");
    scanf("%d", &n);

    int decomposition[100];
    printf("All decompositions for %d are:\n", n);
    printDecompositions(n, decomposition, 0);

    int count = countDecompositions(n);
    printf("Total number of decompositions for %d is: %d\n", n, count);

    return 0;
}