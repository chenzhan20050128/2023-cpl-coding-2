#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int num;
    struct Node *next;
    struct Node *prev;
} Node;

int max(int x, int y)
{
    return x > y ? x : y;
}

Node *createNode(int num)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->num = num;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    Node *column_heads[1005] = {NULL};
    Node *column_tails[1005] = {NULL};
    int column_cnt[1005] = {0};
    int max_column_cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            scanf("%d", &num);
            Node *newNode = createNode(num);
            if (column_heads[j] == NULL)
            {
                column_heads[j] = newNode;
                column_tails[j] = newNode;
            }
            else
            {
                newNode->prev = column_tails[j];
                column_tails[j]->next = newNode;
                column_tails[j] = newNode;
            }
            column_cnt[j]++;
        }
    }

    while (q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        Node *moveNode = column_tails[a];
        if (column_tails[a]->prev != NULL)
        {
            column_tails[a]->prev->next = NULL;
        }
        else
        {
            column_heads[a] = NULL;
        }
        column_tails[a] = column_tails[a]->prev;
        column_cnt[a]--;
        if (column_heads[b] != NULL)
        {
            column_heads[b]->prev = moveNode;
        }
        else
        {
            column_tails[b] = moveNode;
        }
        column_cnt[b]++;
        moveNode->next = column_heads[b];
        moveNode->prev = NULL;
        column_heads[b] = moveNode;
        max_column_cnt = max(max_column_cnt, column_cnt[b]);
    }

    for (int i = max_column_cnt; i >= 1; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (column_cnt[j] >= i)
            {
                printf("%5d", column_heads[j]->num);
                column_heads[j] = column_heads[j]->next;
            }
            else
            {
                printf("     ");
            }
        }
        printf("\n");
    }

    return 0;
}