#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int num;
    struct Node *next;
} Node;

Node *createNode(int num)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    Node *colHeads[1001] = {0};
    Node *colTails[1001] = {0};
    int colCount[1001] = {0};
    int maxColCount = 0;
    Node dummyHead;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            scanf("%d", &num);

            Node *newNode = createNode(num);
            if (colHeads[j] == NULL)
            {
                colHeads[j] = newNode;
                colTails[j] = newNode;
            }
            else
            {
                colTails[j]->next = newNode;
                colTails[j] = newNode;
            }
            colCount[j]++;
            if (colCount[j] > maxColCount)
            {
                maxColCount = colCount[j];
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        from--;
        to--;

        Node *moveNode = colTails[from];
        if (colTails[from] == colHeads[from])
        {
            colTails[from] = NULL;
            colHeads[from] = NULL;
        }
        else
        {
            Node *iter = colHeads[from];
            while (iter->next != colTails[from])
            {
                iter = iter->next;
            }
            iter->next = NULL;
            colTails[from] = iter;
        }
        colCount[from]--;

        moveNode->next = colHeads[to];
        colHeads[to] = moveNode;
        colCount[to]++;
        if (colCount[to] > maxColCount)
        {
            maxColCount = colCount[to];
        }
    }

    for (int i = maxColCount; i >= 1; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (colCount[j] >= i)
            {
                printf("%5d", colHeads[j]->num);
                colHeads[j] = colHeads[j]->next;
                colCount[j]--;
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