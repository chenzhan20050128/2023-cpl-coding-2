#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000100

typedef struct node
{
    char s[25];
    int next;
} Node;

Node graph[MAXN + 1];

int main()
{
    long long n, i, slow, fast;
    scanf("%lld", &n);
    for (int i = 0; i <= MAXN; i++)
    {
        graph[i].next = -1;
    }
    for (i = 1; i <= n; i++)
    {
        scanf("%s %d", graph[i].s, &graph[i].next);
    }
    slow = fast = 1;
    while (1)
    {
        if (graph[slow].next == -1 || graph[fast].next == -1 || graph[graph[fast].next].next == -1)
        {
            printf("%d", -1);
            return 0;
        }
        slow = graph[slow].next;
        fast = graph[graph[fast].next].next;
        if (slow == fast)
            break;
    }
    slow = 1;
    while (slow != fast)
    {
        slow = graph[slow].next;
        fast = graph[fast].next;
    }
    printf("%s", graph[slow].s);
    return 0;
}