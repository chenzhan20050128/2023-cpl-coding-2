#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int seq[2010];
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &seq[i]);
    }
    int max = 0;
    int max_idx = -1;
    int head_index = n;
    while (seq[head_index] >= max)
    {
        max = seq[head_index];
        max_idx = head_index;
        head_index -= 1;
    }

    int min = 2147483647;
    int min_idx = -1;
    int now_index = head_index + 1;
    while (now_index <= n)
    {
        if (min > seq[now_index] && seq[now_index] > seq[head_index])
        {
            min = seq[now_index];
            min_idx = now_index;
        }
        now_index += 1;
    }
    swap(&seq[min_idx], &seq[head_index]);
    for (int i = head_index + 1, j = n; i < j; i++, j--)
    {
        swap(&seq[i], &seq[j]);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", seq[i]);
    }
    return 0;
}