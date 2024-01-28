#include <stdio.h>
#include <stdlib.h>

#define maxn 1000010

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int stack[maxn][]

    // Initialize each stack with respective values
    for (i = 1; i <= n; i++)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->value = i;
        new_node->next = NULL;
        stack[i] = new_node;
    }

    // Perform stack operations
    for (i = 1; i <= m; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        node *temp_node = stack[to];
        stack[to] = stack[from];
        stack[from] = NULL;
        node *current_node = stack[to];
        while (current_node->next != NULL)
        {
            current_node = current_node->next;
        }
        current_node->next = temp_node;
    }

    // Print stack contents
    for (i = 1; i <= n; i++)
    {
        if (stack[i] == NULL)
        {
            printf("0\n");
        }
        else
        {
            node *temp_node = stack[i], *prev_node = NULL;
            while (temp_node != NULL)
            {
                node *next_node = temp_node->next;
                temp_node->next = prev_node;
                prev_node = temp_node;
                temp_node = next_node;
            }
            temp_node = prev_node;
            while (temp_node != NULL)
            {
                printf("%d ", temp_node->value);
                temp_node = temp_node->next;
            }
            printf("\n");
        }
    }

    return 0;
}