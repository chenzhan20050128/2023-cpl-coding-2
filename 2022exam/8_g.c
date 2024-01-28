#include <stdio.h>
#include <stdlib.h>

struct node
{
    int l, r, id;
    struct node *next;
} *head, *tail;

int idx = 1;

struct node *create(int l, int r)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->l = l;
    p->r = r;
    p->id = 0;
    p->next = NULL;
    return p;
}

void insert(struct node *ins)
{
    struct node *now, *nxt;
    for (now = head; now != NULL; now = now->next)
    {
        if (now->r >= ins->r)
        {
            break;
        }
    }
    if (now == NULL)
    {
        tail->next = ins;
        tail = ins;
    }
    else
    {
        ins->next = now->next;
        now->next = ins;
        do
        {
            if (ins->r >= ins->next->r)
            {
                nxt = ins->next;
                ins->next = nxt->next;
                free(nxt);
            }
            else
            {
                break;
            }
        } while (ins->next != NULL);
        for (now = head; now->next != ins; now = now->next)
            ;
        if (now->r >= ins->l)
        {
            now->r = ins->r;
            now->next = ins->next;
            free(ins);
        }
    }
}

void del(int id)
{
    struct node *now, *nxt;
    for (now = head; now != NULL; now = now->next)
    {
        if (now->id == id)
            break;
    }
    if (now == NULL)
    {
        printf("free fail\n");
        return;
    }
    nxt = create(now->l, now->r);
    now->id = 0;
    if (nxt->l < head->r)
        head->r = nxt->r;
    else
        insert(nxt);
    printf("free success\n");
}

void query()
{
    struct node *now;
    int flag = 0;
    for (now = head; now != NULL; now = now->next)
    {
        if (now->id == 0)
        {
            if (flag)
                putchar(' ');
            printf("[%d,%d)", now->l, now->r);
            flag = 1;
        }
    }
    if (!flag)
        printf("NULL");
    putchar('\n');
}

void apply(int x)
{
    struct node *now, *nxt;
    for (now = head; now != NULL; now = now->next)
    {
        if (now->id == 0 && now->r - now->l >= x)
            break;
    }
    if (now == NULL)
    {
        printf("malloc fail\n");
    }
    else
    {
        if (now->l + x == now->r)
        {
            now->id = idx;
            printf("%d\n", now->l);
        }
        else
        {
            nxt = create(now->l, now->l + x);
            nxt->id = idx;
            printf("%d\n", nxt->l);
            if (nxt->l < head->r)
            {
                head->l = nxt->r;
            }
            else
                insert(nxt);
        }
        ++idx;
    }
}

int main()
{
    int t, n, x, i;
    int opt;
    scanf("%d%d", &n, &x);
    head = tail = create(0, x);
    while (n--)
    {
        scanf("%d", &opt);
        if (opt == 1)
        {
            scanf("%d", &x);
            apply(x);
        }
        else if (opt == 2)
        {
            scanf("%d", &x);
            del(x);
        }
        else if (opt == 3)
        {
            query();
        }
    }
    return 0;
}