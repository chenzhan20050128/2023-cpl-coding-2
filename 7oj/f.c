#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int amount;
} Drink;

int compare(const void *a, const void *b)
{
    return ((Drink *)b)->value - ((Drink *)a)->value;
}

int main()
{
    int n, L;
    scanf("%d %d", &n, &L);

    Drink drinks[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &(drinks[i].value));
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &(drinks[i].amount));
    }

    qsort(drinks, n, sizeof(Drink), compare);

    int totalValue = 0;

    for (int i = 0; i < n; i++)
    {
        if (L == 0)
        {
            break;
        }
        int amount = drinks[i].amount;
        int value = drinks[i].value;
        int addAmount = (amount < L) ? amount : L;
        totalValue += addAmount * value;
        L -= addAmount;
    }

    printf("%d\n", totalValue);

    return 0;
}