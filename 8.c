#include <stdio.h>

#define MAXN 1005

int count[MAXN], belong[MAXN][5005], score[MAXN], subtask[5005];
int answer[MAXN];

int main(int argc, char *argv[])
{
    int i, j, k, n;
    scanf("%d", &k);
    for (i = 1; i <= k; i++)
    {
        scanf("%d", &n);
        subtask[i] = n;
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &belong[i][j]);
        }
        scanf("%d", &score[i]);
    }
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &answer[i]);
        count[answer[i]]++;
    }
    long long total_score = 0;
    int max_count = 0, a_out = 0;
    for (i = 1; i <= k; i++)
    {
        int passed = 1;
        for (j = 1; j <= subtask[i]; j++)
        {
            if (count[answer[belong[i][j]]] != subtask[i])
            {
                passed = 0;
                break;
            }
        }
        if (passed)
        {
            total_score += score[i];
            if (count[answer[belong[i][1]]] > max_count)
            {
                max_count = count[answer[belong[i][1]]];
                a_out = answer[belong[i][1]];
            }
        }
    }
    printf("%lld\n%d\n", total_score, a_out);

    return 0;
}