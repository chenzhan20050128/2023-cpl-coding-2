#include <stdio.h>
#define MAXN 10005
#define max(a, b) ((a) > (b) ? (a) : (b)) // 定义求最大值的宏

int p1, p2, P1[MAXN], P2[MAXN]; // 定义两个多项式的最高阶数和两个数组来存放多项式系数
char n[15];                     // 定义字符数组来存放未知数的名字

// 打印函数，把每项的系数和最高阶数作为参数
void Print(int coef, int p, int max)
{
    // 如果系数为0，则直接返回
    if (coef == 0)
        return;

    // 如果系数为正，且当前的阶数不是最大的，那么打印一个加号
    if (coef > 0 && p != max)
        printf("+");

    // 如果当前阶数为0，那么就直接打印该系数，然后返回
    if (p == 0)
    {
        printf("%d", coef);
        return;
    }

    // 如果当前阶数为1，根据系数的大小来打印
    if (p == 1)
    {
        
    }

    // 如果当前阶数不为0或1，根据系数的大小来打印
    if (coef == 1)
    {
        ...
    }
    if (coef == -1)
    {
        ...
    }
    printf("%d%s^%d", coef, n, p);
}

// 主函数
int main()
{
    // 输入两个多项式的阶数和未知数
    scanf("%d%d%s", &p1, &p2, n);

    // 输入两个多项式的系数
    for (int i = p1; i >= 0; i--)
    {
        scanf("%d", &P1[i]);
    }
    for (int i = p2; i >= 0; i--)
    {
        scanf("%d", &P2[i]);
    }

    // 进行加法运算并打印结果
    for (int i = max(p1, p2); i >= 0; i--)
    {
        Print(P1[i] + P2[i], i, max(p1, p2));
    }
    printf("\n");

    // 进行减法运算并打印结果
    for (int i = max(p1, p2); i >= 0; i--)
    {
        Print(P1[i] - P2[i], i, max(p1, p2));
    }
    printf("\n");

    // 进行乘法运算并打印结果
    for (int i = p1 + p2; i >= 0; i--)
    {
        ...
    }
    return 0;
}