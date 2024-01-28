#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node
{
    int num;
    struct node *prev;
    struct node *next;
} node;
int main()
{
    node *head[1010];
    node *tail[1010];
    int cnt[1010];
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                node *new = (node *)malloc(sizeof(node));
                scanf("%d", new->num);
                new->next = NULL;
                new->prev = NULL;
                head[j] = new;
                tail[j] = new;
            }
            else
            {
                node *new = (node *)malloc(sizeof(node));
                scanf("%d", new->num);
                new->next = NULL;
                new->prev = tail[j];
                tail[j]->next = new;
                tail[j] = new;
            }
        }
    }
    for (int j = 1; j <= m; j++)
    {
        cnt[j] = n;
    }
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        node p;
        p.num = head[a]->num;
        p.next = NULL;
        p.prev = tail[b];
        tail[b]->next = &p;
        tail[b] = &p;
        node *temp = head[a];
        head[a] = head[a]->next;
        free(temp);
        cnt[a] -= 1;
        cnt[b] += 1;
    }
    int maxcnt = -2147483647;
    int maxidx = -1;
    for (int i = 1; i <= m; i++)
    {
        if (cnt[i] > maxcnt)
        {
            maxcnt = cnt[i];
            maxidx = i;
        }
    }
    for (int now_out = maxcnt; now_out >= 1; now_out--)
    {
        for (int j = 1; j <= m; j++)
        {
            if (cnt[j] >= now_out)
            {
                printf("%5d", tail[j]->num);
                tail[j] = tail[j]->prev;
            }
            else
            {
                continue;
            }
        }
        printf("\n");
    }
    return 0;
}