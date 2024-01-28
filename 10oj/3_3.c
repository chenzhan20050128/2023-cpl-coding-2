#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义结构体，存储球队信息
typedef struct
{
    char name[21];  // 球队名
    double attack;  // 平均进攻评分
    double defense; // 平均防守评分
    double tactic;  // 平均战术组织评分
} Team;

// 比较进攻评分的函数，用于 qsort 的回调
int compare_attack(const void *a, const void *b)
{
    if ((*(Team *)b).attack - (*(Team *)a).attack > 0)
        return 1;
    else
        return -1;
}

// 比较防守评分的函数，用于 qsort 的回调
int compare_defense(const void *a, const void *b)
{
    if ((*(Team *)b).defense - (*(Team *)a).defense > 0)
        return 1;
    else
        return -1;
}

// 比较战术评分的函数，用于 qsort 的回调
int compare_tactic(const void *a, const void *b)
{
    if ((*(Team *)b).tactic - (*(Team *)a).tactic > 0)
        return 1;
    else
        return -1;
}

int main()
{
    int n, attack, defense, tactic;
    char player[21];
    scanf("%d", &n);
    getchar();
    Team teams[1100];

    // 读取并计算每队的平均评分
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &teams[i].name);
        

        int total_attack = 0, total_defense = 0, total_tactic = 0;
        for (int j = 0; j < 11; j++)
        {
            scanf("%s %d %d %d", player, &attack, &defense, &tactic);
            total_attack += attack;
            total_defense += defense;
            total_tactic += tactic;
        }
        getchar();

        teams[i].attack = total_attack / 11.0;
        teams[i].defense = total_defense / 11.0;
        teams[i].tactic = total_tactic / 11.0;
    }

    // 对平均进攻评分排序并输出
    qsort(teams, n, sizeof(Team), compare_attack);
    for (int i = 0; i < n; i++)
    {
        printf("%s", teams[i].name);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");

    // 对平均防守评分排序并输出
    qsort(teams, n, sizeof(Team), compare_defense);
    for (int i = 0; i < n; i++)
    {
        printf("%s", teams[i].name);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");

    // 对平均战术评分排序并输出
    qsort(teams, n, sizeof(Team), compare_tactic);
    for (int i = 0; i < n; i++)
    {
        printf("%s", teams[i].name);
        if (i != n - 1)
            printf(" ");
    }

    return 0;
}