#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int l, r;
    int id;
    struct Node *prev, *next;
} Node;

int isExist[5005];
Node *head, *tail, mem[5005], *apply[5005];
int memCnt = 0, applyCnt = 0;

Node *createNode(int l, int r, int id)
{
    Node *node = &mem[memCnt++];
    node->l = l;
    node->r = r;
    node->id = id;
    node->prev = node->next = NULL;
    return node;
}

void insertNodeAfter(Node *pos, Node *node)
{
    node->next = pos->next;
    node->prev = pos;
    if (pos->next != NULL)
    {
        pos->next->prev = node;
    }
    pos->next = node;
    if (tail == pos)
    {
        tail = node;
    }
}

void eraseNode(Node *node)
{
    if (node == head)
    {
        head = node->next;
    }
    if (node == tail)
    {
        tail = node->prev;
    }
    if (node->prev)
    {
        node->prev->next = node->next;
    }
    if (node->next)
    {
        node->next->prev = node->prev;
    }
}

void mergeNode()
{
    Node *p = head;
    while (p != NULL)
    {
        if (p->next != NULL && p->r == p->next->l)
        {
            p->r = p->next->r;
            eraseNode(p->next);
        }
        else
        {
            p = p->next;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    int n;
    scanf("%d", &n);
    head = tail = createNode(0, n, -1);
    int opt;
    while (T--)
    {
        scanf("%d", &opt);
        if (opt == 1)
        {
            int size;
            scanf("%d", &size);
            Node *p = head;
            Node *newNode;
            while (p != NULL)
            {
                if (p->r - p->l >= size)
                {
                    newNode = createNode(p->l, p->l + size, applyCnt);
                    p->l += size;
                    insertNodeAfter(p->prev, newNode);
                    apply[applyCnt++] = newNode;
                    isExist[newNode->id] = 1;
                    printf("%d\n", newNode->l);
                    break;
                }
                p = p->next;
            }
            if (p == NULL)
            {
                printf("NULL\n");
            }
        }
        else if (opt == 2)
        {
            int id;
            scanf("%d", &id);
            if (isExist[id] == 0)
            {
                printf("ILLEGAL_ERASE_ARGUMENT\n");
                continue;
            }
            Node *delNode = apply[id];
            isExist[id] = 0;
            delNode->id = -1;
            mergeNode();
        }
        else if (opt == 3)
        {
            Node *p = head;
            while (p != NULL)
            {
                printf(" [%d, %d)", p->l, p->r);
                p = p->next;
            }
            printf("\n");
        }
    }
    return 0;
}