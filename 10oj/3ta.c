
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义一个存储足球队信息的结构体
typedef struct
{
    char name[21];
    char player_name[21];
    int atk;
    int def;
    int tac;
} Team;

// 定义比较攻击力的函数
int atk_cmp(const void *a, const void *b)
{
    return ((Team *)b)->atk - ((Team *)a)->atk;
}

// 定义比较防御力的函数
int def_cmp(const void *a, const void *b)
{
    return ((Team *)b)->def - ((Team *)a)->def;
}

// 定义比较战术的函数
int tac_cmp(const void *a, const void *b)
{
    return ((Team *)b)->tac - ((Team *)a)->tac;
}

// 创建一个函数指针数组，使得函数可以作为参数
int (*team_cmp[3])(const void *, const void *) = {*atk_cmp, *def_cmp, *tac_cmp};

Team team[1000]; // 定义一个足球队数组。

int main(void)
{
    int N;                      // 定义一个变量用来存储足球队的个数。
    scanf("%d", &N);            // 等待输入队伍数量
    for (int i = 0; i < N; i++) // 循环接收输入，读取足球队的信息。

    // 循环中先读取足球队名，然后再循环读取队员的名字、攻击力、防御力和战术，此处的设计可能是为了测试方便
    {
        scanf("%s", team[i].name);
        for (int j = 0; j < 11; j++)
        {
            char name[21];
            int a, d, t;
            scanf("%s%d%d%d", name, &a, &d, &t);
            team[i].atk += a;
            team[i].def += d;
            team[i].tac += t;
        }
    }
    // 根据攻击力、防御力和战术进行排序
    for (int i = 0; i < 3; i++)
    {
        qsort(team, N, sizeof(Team), team_cmp[i]);
        // 打印各足球队名称
        for (int j = 0; j < N; j++)
            printf("%s%c", team[j].name, " \n"[j == N - 1]);
    }
}