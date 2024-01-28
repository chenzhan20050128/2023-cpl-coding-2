#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char teamName[25];
    double avgAttack;
    double avgDefense;
    double avgTactics;
} Team;

int compareAttack(const void *a, const void *b)
{
    return ((Team *)b)->avgAttack - ((Team *)a)->avgAttack;
}

int compareDefense(const void *a, const void *b)
{
    return ((Team *)b)->avgDefense - ((Team *)a)->avgDefense;
}

int compareTactics(const void *a, const void *b)
{
    return ((Team *)b)->avgTactics - ((Team *)a)->avgTactics;
}

int main()
{
    int n;
    scanf("%d", &n);

    Team teams[1010];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", teams[i].teamName);

        double sumAttack = 0, sumDefense = 0, sumTactics = 0;
        for (int j = 0; j < 11; j++)
        {
            char player[25];
            int attack, defense, tactics;
            scanf("%s %d %d %d", player, &attack, &defense, &tactics);
            sumAttack += attack;
            sumDefense += defense;
            sumTactics += tactics;
        }

        teams[i].avgAttack = (double)sumAttack / 11;
        teams[i].avgDefense = (double)sumDefense / 11;
        teams[i].avgTactics = (double)sumTactics / 11;
    }

    qsort(teams, n, sizeof(Team), compareAttack);
    for (int i = 0; i < n; i++)
    {
        printf("%s ", teams[i].teamName);
    }
    printf("\n");

    qsort(teams, n, sizeof(Team), compareDefense);
    for (int i = 0; i < n; i++)
    {
        printf("%s ", teams[i].teamName);
    }
    printf("\n");

    qsort(teams, n, sizeof(Team), compareTactics);
    for (int i = 0; i < n; i++)
    {
        printf("%s ", teams[i].teamName);
    }
    printf("\n");

    return 0;
}