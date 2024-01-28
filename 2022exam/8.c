#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int l;
    int r;
    int is_allocated;
    struct node *next;
};
int main()
{
    int T;
    scanf("%d", &T);
    int n;
    scanf("%d", &n);
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->l = 0;
    head->r = n;
    head->next = NULL;
    head->is_allocated = 0;
    int opt;
    while (T--)
    {
        scanf("%d", &opt);
        if (opt == 1)
        {
            int size;
            scanf("%d", &size);
            struct node *p;
            p = head;
            while ((p->is_allocated == 1 || (p->r - p->l) < size) && p != NULL)
            {
                p = p->next;
            }
            if (p == NULL)
            {
                printf("malloc fail\n");
            }
            else
            {
                if (p->is_allocated == 0 && (p->r - p->l) >= size)
                {
                    if ((p->r - p->l) == size)
                    {
                        p->is_allocated = 1;
                        printf("%d\n", p->l);
                    }
                    else
                    {
                        if (p == head)
                        {
                            struct node *q = (struct node *)malloc(sizeof(struct node));
                            q->l = p->l;
                            q->r = p->l + size;
                            q->is_allocated = 1;
                            q->next = p;
                            head = q;
                            p->l = p->l + size;
                            printf("%d\n", q->l);
                        }
                        else
                        {
                            struct node *q = (struct node *)malloc(sizeof(struct node));
                            q->l = p->l;
                            q->r = p->l + size;
                            q->is_allocated = 1;
                            q->next = p;
                            p->l = p->l + size;
                            printf("%d\n", q->l);
                        }
                    }
                }
                else
                {
                    printf("hello\n");
                }
            }
        }
        else if (opt == 2)
        {
            int id;
            scanf("%d", &id);
            struct node *p;
            p = head;
            int find = 0;
            while (p != NULL && find == 0)
            {
                if (p->is_allocated == 1 && (p->r - p->l) == id)
                {
                    p->is_allocated = 0;
                    find = 1;
                    struct node *q;
                    q = p->next;
                    while (q != NULL && q->is_allocated == 0)
                    {
                        p->r = q->r;
                        p->next = q->next;
                        q = p->next;
                    }
                    printf("free success\n");
                }
                p = p->next;
            }
            if (find == 0)
            {
                printf("free fail\n");
            }
        }
        else if (opt == 3)
        {
            //[2,15)
            struct node *p;
            p = head;
            int find = 0;
            while (p != NULL)
            {
                if (p->is_allocated == 0)
                {
                    find = 1;
                    printf("[%d,%d) ", p->l, p->r);
                }
                p = p->next;
            }
            if (find == 0)
            {
                printf("NULL\n");
            }
        }
    }
    struct node *p;
    p = head;
    int temp;
    while (p != NULL)
    {
        free(p);
        p = p->next;
    }
    return 0;
}