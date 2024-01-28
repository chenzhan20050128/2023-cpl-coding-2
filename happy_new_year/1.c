#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    int Q, num;
    scanf("%d %d", &Q, &num);
    int buc[1010] = {0};
    int sum[1010] = {0};
    getchar();
    char query[10];
    int temp;
    for (int i = 1; i <= Q; i++)
    {
        scanf("%s", &query);
        if (strcmp(query, "Add") == 0)
        {
            scanf("%d", &temp);
            buc[temp - num] += 1;
            sum[999] = buc[999];
            for (int i = 998; i >= 0; i--)
            {
                sum[i] = sum[i + 1] + buc[i];
            }
        }
        else if (strcmp(query, "Query") == 0)
        {
            int k;
            scanf("%d", &k);
            // k -= 1;
            // int pos = 999;
            if (sum[0] < k)
            {
                printf("No Answer\n");
            }
            else
            {
                int l = 0;
                int r = 999;
                int m = (l + r) / 2;
                while (l <= r)
                {
                    m = (l + r) / 2;
                    if (sum[m] < k)
                    {
                        l = m - 1;
                    }
                    else if (sum[m] > k)
                    {
                        r = m + 1;
                    }
                    else
                    {
                        break;
                    }
                }
                printf("%d\n", m + num + 1);
            }
        }
        else
        {
            printf("%s\n", query);
        }
    }
    return 0;
}