#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 2 * 1010 // 2*1000010
typedef struct node
{
    char c;
    struct node *prev, // 上一个节点
        *next,         // 下一个节点
        *last_same;    // 上一个大小写相同的节点
} node;

char query[maxn];
node *head = NULL;
node *bigtail = NULL;
node *smalltail = NULL;
node *tail = NULL;
int is_same(char a, char b)
{

    if ('a' <= a && a <= 'z')
    {
        if ('a' <= b && b <= 'z')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if ('a' <= b && b <= 'z')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
void add()
{
    int slen = strlen(query);
    for (int i = 0; i < slen; i++)
    {
        if (query[i] == 'm')
        {
            node *del = smalltail;

            // so del is small;
            if (del == head)
            {
                del->next->prev = NULL;
                // del->prev == NULL so it won't change;
                free(del);
                head = head->next;
                head->next->prev = NULL;
                smalltail->last_same = NULL;
                if (del == tail)
                {
                    tail = tail->prev;
                }
            }
            else
            {
                tail->last_same = del->last_same;
                del->next->prev = del->prev;
                del->prev->next = del->next;
                if (del == tail)
                {
                    tail = tail->prev;
                }
                smalltail = del->last_same;
                free(del);
            }
        }
        else if (query[i] == 'M')
        {
            node *del = bigtail;

            // so del is big;
            if (del == head)
            {
                del->next->prev = NULL;
                // del->prev == NULL so it won't change;
                free(del);
                head = head->next;
                head->next->prev = NULL;
                bigtail->last_same = NULL;
                if (del == tail)
                {
                    tail = tail->prev;
                }
            }
            else
            {
                tail->last_same = del->last_same;
                del->next->prev = del->prev;
                del->prev->next = del->next;
                if (del == tail)
                {
                    tail = tail->prev;
                }
                bigtail = del->last_same;
                free(del);
            }
        }
        else // to add;
        {
            if (head == NULL)
            {
                node *temp_node = (node *)malloc(sizeof(node));
                temp_node->c = query[i];
                temp_node->last_same = NULL;
                temp_node->next = NULL;
                temp_node->prev = NULL;
                head = temp_node;
                tail = temp_node;
                if ('a' <= temp_node->c && temp_node->c <= 'z')
                {
                    smalltail = temp_node;
                }
                else
                {
                    bigtail = temp_node;
                }
            }
            else
            {

                node *p = tail;
                node *temp_node = (node *)malloc(sizeof(node));
                temp_node->c = query[i];
                temp_node->next = NULL;
                temp_node->prev = p;
                p->next = temp_node; // restart and find lastsame;
                tail = temp_node;

                if ('a' <= temp_node->c && temp_node->c <= 'z')
                {
                    smalltail = temp_node;
                }
                else
                {
                    bigtail = temp_node;
                }

                while (is_same(p->c, temp_node->c) == 0 && p != NULL)
                {
                    p = p->prev;
                }
                if (p != NULL)
                {
                    temp_node->last_same = p;
                }
                else
                { // p is far from head; can not find;
                    temp_node->last_same = NULL;
                }
            }
        }
    }
}

void search(int k)
{
    node *p = tail;
    for (int i = 1; i <= k - 1 && p != NULL; i++)
    {
        p = p->prev;
    }
    if (p == NULL)
    {
        printf("error");
        // error
    }
    else
    {
        // now p is the last k'th node;
        while (p != NULL)
        {
            printf("%c", p->c);
        }
        printf("\n");
    }

    return;
}
int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%s", query);
        if (strcmp(query, "?") == 0)
        {
            int k;
            scanf("%d", &k);
            search(k);
        }
        else
        {
            add();
        }
    }
}