#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int tree[100010]; // 1000010
int main()
{
    int n;
    scanf("%d", &n);
    int tree_cnt = pow(2, n) - 1;
    for (int i = 0; i <= tree_cnt - 1; i++)
    {
        scanf("%d", &tree[i]);
    }
    long long sum = 0;
    int father;
    for (int i = pow(2, n) - pow(2, n - 1) - 1; i <= tree_cnt - 1; i++)
    {
        sum = 0;
        father = i;
        while (father >= 0)
        {
            sum += tree[father];
            if (father == 0)
            {
                break;
            }
            father = (father - 1) / 2;
        }
        printf("%lld ", sum);
    }
    return 0;
}