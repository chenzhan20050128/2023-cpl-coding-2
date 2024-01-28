#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define maxn 10010
int max(int a, int b)
{
    if (a > b)
        return a;
    else
    {
        return b;
    }
}
typedef struct num
{
    int detail[maxn];
    int highest;
} num;

num *str_to_num(char *s, int size)
{
    num *now = (num *)malloc(maxn * sizeof(num));
    now->highest = size - 1;
    for (int i = size - 1; i >= 0; i--)
    {
        now->detail[size - 1 - i] = s[i] - '0';
    }
    return now;
}

int compare(num *a, num *b)
{
    if (a->highest > b->highest)
    {
        return 1;
    }
    else if (a->highest < b->highest)
    {
        return -1;
    }
    else
    {
        for (int i = a->highest; i >= 0; i--)
        {
            if (a->detail[i] > b->detail[i])
            {
                return 1;
            }
            else if (a->detail[i] < b->detail[i])
            {
                return -1;
            }
        }
        return 0;
    }
}
void print_num(num *q)
{
    for (int i = q->highest; i >= 0; i--)
    {
        printf("%c", q->detail[i] + '0');
    }
    return;
}
num *add(num *a, num *b)
{
    num *c = (num *)malloc(maxn * sizeof(num));
    memset(c->detail, 0, sizeof(c->detail));
    for (int i = 0; i <= max(a->highest, b->highest); i++)
    {
        c->detail[i] += (a->detail[i] + b->detail[i]) % 10;
        c->detail[i + 1] += (a->detail[i] + b->detail[i]) / 10;
    }
    if (c->detail[max(a->highest, b->highest) + 1] > 0)
    {
        c->highest = max(a->highest, b->highest) + 1;
    }
    else
    {
        c->highest = max(a->highest, b->highest);
    }
    return c;
}

num *minus(num *a, num *b)
{
    num *c = (num *)malloc(sizeof(num));
    memset(c->detail, 0, sizeof(c->detail));
    for (int i = 0; i <= max(a->highest, b->highest); i++)
    {
        if (a->detail[i] + b->detail[i] < 0)
        {
            c->detail[i] += a->detail[i] - b->detail[i] + 10;
            a->detail[i + 1] -= 1;
        }
        else
        {
            c->detail[i] += a->detail[i] - b->detail[i];
        }
    }
    int temp = max(a->highest, b->highest);

    while (c->detail[temp] == 0)
    {
        temp--;
    }
    c->highest = temp;
    return c;
}

num *prod(num *a, num *b)
{
    num *c = (num *)malloc(sizeof(num));
    memset(c->detail, 0, sizeof(c->detail));
    for (int i = 0; i <= a->highest; i++)
    {
        for (int j = 0; j <= b->highest; j++)
        {
            c->detail[i + j] += a->detail[i] * b->detail[j];
        }
    }
    for (int i = 0; i <= a->highest + b->highest; i++)
    {
        if (c->detail[i] >= 10)
        {
            c->detail[i + 1] += c->detail[i] / 10;
            c->detail[i] = c->detail[i] % 10;
        }
    }
    int temp = a->highest + b->highest + 1;
    while (c->detail[temp] == 0)
    {
        temp--;
    }
    c->highest = temp;
    return c;
}

num *division(num *a, num *b)
{
    num *c = (num *)malloc(sizeof(num));
    num *d = (num *)malloc(sizeof(num));
    memset(c->detail, 0, sizeof(c->detail));
    for (int i = 0; i <= a->highest; i++)
        d->detail[i] = a->detail[a->highest - i];
    d->highest = a->highest;
    for (int i = a->highest; i >= 0; i--)
    {
        for (c->detail[i] = 0; compare(d, b) >= 0; c->detail[i]++)
        {
            d = minus(d, b);
        }
        if (i)
        {
            d->detail[i - 1] += d->detail[i] * 10;
            d->detail[i] = 0;
        }
    }
    int temp = a->highest + 1;
    while (c->detail[temp] == 0)
        temp--;
    c->highest = temp;
    return c;
}

int main()
{
    int q;
    scanf("%d", &q);
    getchar();
    char s[maxn];
    char op;
    while (q--)
    {
        scanf("%s", s);
        num *a = (num *)
            a = str_to_num(s, strlen(s));
        getchar();
        scanf("%c", &op);
        getchar();
        scanf("%s", s);
        num *b = str_to_num(s, strlen(s));
        // print_num(a);
        // printf(" %c ", op);
        // print_num(b);
        // printf("\n");
        num *temp;
        switch (op)
        {
        case '+':
            temp = add(a, b);
            print_num(temp);
            printf("\n");
            break;
        case '-':
            temp = minus(a, b);
            print_num(temp);
            printf("\n");
            break;
        case '*':
            temp = prod(a, b);
            print_num(temp);
            printf("\n");
            break;
        case '/':
            temp = division(a, b);
            print_num(temp);
            printf("\n");
            break;
        }
    }
    return 0;
}