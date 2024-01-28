int main()
{
    // 定义了三个数组用来存储两个输入的多项式（p1和p2）以及计算结果ans
    int p1[10010], p2[10010], ans[20030], j1, j2, flag;

    // 定义了name用来存储输入的多项式变数名，result用来存储输出的结果字符串，tmp用来临时存储数字转化为的字符串形式
    char name[15], result[1000005], tmp[15];

    memset(p1, 0, sizeof(p1)); // 数组初始化为0
    memset(p2, 0, sizeof(p2));
    memset(ans, 0, sizeof(ans));

    // 读取两个多项式的阶数
    scanf("%d%d", &j1, &j2);

    // 读取多项式的变数名
    scanf("%s", name);

    // 读取两个多项式的所有系数
    for (int i = j1; i >= 0; i--)
        scanf("%d", &p1[i]);
    for (int i = j2; i >= 0; i--)
        scanf("%d", &p2[i]);

    // 计算多项式相加的结果，存放到Ans
    for (int i = j1 > j2 ? j1 : j2; i >= 0; i--)
        ans[i] += p1[i] + p2[i];
    flag = 0;

    // 初始化结果字符串
    memset(result, '\0', sizeof(result));
    strcpy(result, "");

    // 格式化结果到result字符串
    for (int i = j1 > j2 ? j1 : j2; i >= 0; i--)
    {
        // 转换系数为字符串
        sprintf(tmp, "%d", ans[i]);
        if (ans[i] != 0)
        {
            if (flag == 0)
            {
                flag = 1;
                if (i == 0)
                {
                    strcat(result, tmp);
                    continue;
                }
                // 连接系数、变数名和 "^"
                strcat(result, ans[i] != 1 && ans[i] != -1 ? tmp : ans[i] == 1 ? ""
                                                                               : "-");
                strcat(result, i != 0 ? name : "");
                strcat(result, i != 1 && i != 0 ? "^" : "");

                // 连接幂次
                sprintf(tmp, "%d", i);
                strcat(result, i != 1 && i != 0 ? tmp : "");
                continue;
            }
            if (i == 0)
            {
                strcat(result, ans[i] > 0 ? "+" : "");
                strcat(result, tmp);
                continue;
            }

            // 连接 "+/-"、系数、变数名和 "^"
            strcat(result, ans[i] < 0 ? "" : "+");
            strcat(result, ans[i] != 1 && ans[i] != -1 ? tmp : ans[i] == 1 ? ""
                                                                           : "-");
            strcat(result, i != 0 ? name : "");
            strcat(result, i != 1 && i != 0 ? "^" 
            // 连接幂次
            sprintf(tmp, "%d", i);
            strcat(result, i != 1 && i != 0 ? tmp : "");
        }
    }

    // 输出结果
    printf("%s\n", result);

    // 下面的代码重复以上操作，实现了多项式相减以及相乘的操作，并将结果输出

    return 0;
}

#include <stdio.h>
#include <string.h>
int main()
{
    int p1[10010], p2[10010], ans[20030], j1, j2, flag;
    char name[15], result[1000005], tmp[15];
    memset(p1, 0, sizeof(p1));
    memset(p2, 0, sizeof(p2));
    memset(ans, 0, sizeof(ans));
    scanf("%d%d", &j1, &j2);
    scanf("%s", name);
    for (int i = j1; i >= 0; i--)
        scanf("%d", &p1[i]);
    for (int i = j2; i >= 0; i--)
        scanf("%d", &p2[i]);
    for (int i = j1 > j2 ? j1 : j2; i >= 0; i--)
        ans[i] += p1[i] + p2[i];
    flag = 0;
    memset(result, '\0', sizeof(result));
    strcpy(result, "");
    for (int i = j1 > j2 ? j1 : j2; i >= 0; i--)
    {
        sprintf(tmp, "%d", ans[i]);
        if (ans[i] != 0)
        {
            if (flag == 0)
            {
                flag = 1;
                if (i == 0)
                {
                    strcat(result, tmp);
                    continue;
                }
                strcat(result, ans[i] != 1 && ans[i] != -1 ? tmp : ans[i] == 1 ? ""
                                                                               : "-");
                strcat(result, i != 0 ? name : "");
                strcat(result, i != 1 && i != 0 ? "^" : "");
                sprintf(tmp, "%d", i);
                strcat(result, i != 1 && i != 0 ? tmp : "");
                continue;
            }
            if (i == 0)
            {
                strcat(result, ans[i] > 0 ? "+" : "");
                strcat(result, tmp);
                continue;
            }
            strcat(result, ans[i] < 0 ? "" : "+");
            strcat(result, ans[i] != 1 && ans[i] != -1 ? tmp : ans[i] == 1 ? ""
                                                                           : "-");
            strcat(result, i != 0 ? name : "");
            strcat(result, i != 1 && i != 0 ? "^" : "");
            sprintf(tmp, "%d", i);
            strcat(result, i != 1 && i != 0 ? tmp : "");
        }
    }
    printf("%s\n", result);
    memset(ans, 0, sizeof(ans));
    for (int i = j1 > j2 ? j1 : j2; i >= 0; i--)
        ans[i] += p1[i] - p2[i];
    flag = 0;
    memset(result, '\0', sizeof(result));
    strcpy(result, "");
    for (int i = j1 > j2 ? j1 : j2; i >= 0; i--)
    {
        sprintf(tmp, "%d", ans[i]);
        if (ans[i] != 0)
        {
            if (flag == 0)
            {
                flag = 1;
                if (i == 0)
                {
                    strcat(result, tmp);
                    continue;
                }
                strcat(result, ans[i] != 1 && ans[i] != -1 ? tmp : ans[i] == 1 ? ""
                                                                               : "-");
                strcat(result, i != 0 ? name : "");
                strcat(result, i != 1 && i != 0 ? "^" : "");
                sprintf(tmp, "%d", i);
                strcat(result, i != 1 && i != 0 ? tmp : "");
                continue;
            }
            if (i == 0)
            {
                strcat(result, ans[i] > 0 ? "+" : "");
                strcat(result, tmp);
                continue;
            }
            strcat(result, ans[i] < 0 ? "" : "+");
            strcat(result, ans[i] != 1 && ans[i] != -1 ? tmp : ans[i] == 1 ? ""
                                                                           : "-");
            strcat(result, i != 0 ? name : "");
            strcat(result, i != 1 && i != 0 ? "^" : "");
            sprintf(tmp, "%d", i);
            strcat(result, i != 1 && i != 0 ? tmp : "");
        }
    }
    printf("%s\n", result);
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i <= j1; i++)
        for (int j = 0; j <= j2; j++)
            ans[i + j] += p1[i] * p2[j];
    flag = 0;
    memset(result, '\0', sizeof(result));
    strcpy(result, "");
    for (int i = j1 + j2; i >= 0; i--)
    {
        sprintf(tmp, "%d", ans[i]);
        if (ans[i] != 0)
        {
            if (flag == 0)
            {
                flag = 1;
                if (i == 0)
                {
                    strcat(result, tmp);
                    continue;
                }
                strcat(result, ans[i] != 1 && ans[i] != -1 ? tmp : ans[i] == 1 ? ""
                                                                               : "-");
                strcat(result, i != 0 ? name : "");
                strcat(result, i != 1 && i != 0 ? "^" : "");
                sprintf(tmp, "%d", i);
                strcat(result, i != 1 && i != 0 ? tmp : "");
                continue;
            }
            if (i == 0)
            {
                strcat(result, ans[i] > 0 ? "+" : "");
                strcat(result, tmp);
                continue;
            }
            strcat(result, ans[i] < 0 ? "" : "+");
            strcat(result, ans[i] != 1 && ans[i] != -1 ? tmp : ans[i] == 1 ? ""
                                                                           : "-");
            strcat(result, i != 0 ? name : "");
            strcat(result, i != 1 && i != 0 ? "^" : "");
            sprintf(tmp, "%d", i);
            strcat(result, i != 1 && i != 0 ? tmp : "");
        }
    }
    printf("%s\n", result);
    return 0;
}