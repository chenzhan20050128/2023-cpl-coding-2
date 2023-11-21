#include <stdio.h>
#define maxn 610

int n, m, d, num;
int mat[maxn][maxn], sum[maxn][maxn], ans[maxn][2];
long long maxx;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void check(int x, int y)
{
    // 求出三个等腰直角三角形的三个点
    int x1 = max(x - d, 1), y1 = max(y - d + x - x1, 1), x2 = max(y - d, 1), y2 = max(x - d + y - x2, 1);
    // 根据三个点和“二维前缀和”的递推式快速计算出锤子范围内的价格总和
    long long total = sum[x][y] - sum[x1 - 1][y] - sum[x][y1 - 1] + sum[x1 - 1][y1 - 1] - sum[x2 - 1][y2 - 1];

    if (total > maxx) // 如果当前点的价格之和大于最大价格，则更新总价格，更新坐标数组，并且重新计数
    {
        maxx = total;
        num = 1;
        ans[1][0] = x;
        ans[1][1] = y;
    }
    else if (total == maxx) // 如果和最大值相等，则增加坐标，并将当前坐标添加到数组中
    {
        ans[++num][0] = x;
        ans[num][1] = y;
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &mat[i + j][i - j + m]);
            sum[i + j][i - j + m] = sum[i + j - 1][i - j + m] + sum[i + j][i - j + m - 1] - sum[i + j - 1][i - j + m - 1] + mat[i + j][i - j + m]; // 二维前缀和
        }

    for (int i = 1; i <= n + m; i++) // 遍历所有可能的中心点
        for (int j = max(1, i - n); j <= min(m, i - 1); j++)
            check(i, j);

    printf("%lld %d\n", maxx, num);
    for (int i = 1; i <= num; i++)
        printf("%d %d\n", (ans[i][0] - ans[i][1] + m >> 1) + 1, (ans[i][0] + ans[i][1] - m >> 1) + 1); // 将坐标转换回原来的坐标
    return 0;
}