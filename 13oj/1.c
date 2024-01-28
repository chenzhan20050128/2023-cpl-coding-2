#include <stdio.h>
#include <stdlib.h>

#define maxn 1000010

typedef struct node
{
    int value;
    struct node *next;
} node;

node* top[maxn] = {0};

int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        node *now = (node*)malloc(sizeof(node));
        now->value = i;
        now->next = NULL;
        top[i] = now;
    }
    while(m--)
    {
        int from, to;
        scanf("%d %d",&from, &to);
        node *tmp = top[from]; // get the stack to move
        top[from] = NULL; // set the source stack to empty
        if(top[to]) // if destination stack is not empty
        {
            node *p = top[to]; // get destination stack
            while(p->next) p = p->next; // navigate to stack bottom
            p->next = tmp; // attach the stack to move
        } 
        else
        {
            top[to] = tmp; // if destination stack is empty, make it the stack to move
        }
    }
    for (i = 1; i <= n; i++)
    {
        //printf("Stack %d: ", i);
        if (top[i] == NULL)
        {
            printf("0\n");
        }
        else
        {
            node *now = top[i];
            while (now != NULL)
            {
                printf("%d ", now->value);
                now = now->next;
            }
            printf("\n");
        }
        // remember to free memory
        node *p = top[i], *tmp;
        while(p)
        {
            tmp = p;
            p = p->next;
            free(tmp);
        }
    }
    return 0;
}