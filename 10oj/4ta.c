#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b)) // 宏定义，求两个数的较大者
#define max(a,b) ((a) > (b) ? (a) : (b))


// 宏定义，用于创建新的多项式
#define newPoly(pname, p) \
    poly_t pname;         \
    pname.maxOrder = (p); \
    pname.coe = (int *)malloc(sizeof(int) * ((p) + 1));

#define maxLen 12 // 名称最大长度
char *name;       // 多项式项的名字

// 多项式的结构体定义
struct poly
{
    int maxOrder; // 项的最高次数
    int *coe;
};
typedef struct poly poly_t;

// 打印多项式中一项的函数
void printItem(int coe, int p)
{
    if (p == 0)
    {
        printf("%d", coe); // 最低次项，直接打印系数
        return;
    }
    if (coe != 1 && coe != -1)
        printf("%d", coe);
    else if (coe == -1)
        printf("-");    // 系数为-1，只打印负号
    printf("%s", name); // 打印多项式项的名字
    if (p > 1)
        printf("^%d", p); // 非1次项，需要打印次数
}

// 打印整个多项式的函数
void printPoly(poly_t P)
{
    for (int i = P.maxOrder; i >= 0; i--) // 从最高次项开始打印
    {
        int coe = P.coe[i];
        if (coe > 0 && i != P.maxOrder)
            printf("+"); // 不是最高次项，并且系数为正，需要打印加号
        else if (coe == 0)
            continue;      // 系数为0的项不打印
        printItem(coe, i); // 打印多项式的一项
    }
    printf("\n");
}

// 多项式加减的函数
void polyAddMinus(poly_t P1, poly_t P2, int add)
{
    // 新建一个多项式，最大次数为P1和P2中多项式的最大次数
    newPoly(P, max(P1.maxOrder, P2.maxOrder));
    for (int i = 0; i <= P.maxOrder; i++)
        P.coe[i] = (i <= P1.maxOrder ? P1.coe[i] : 0) +
                   (i <= P2.maxOrder ? P2.coe[i] : 0) * (add ? 1 : -1);
    printPoly(P); // 打印多项式
    free(P.coe);  // 释放内存
}

// 多项式乘法的函数
void polyMul(poly_t P1, poly_t P2)
{
    // 新建一个多项式，最大次数为P1和P2多项式次数之和
    newPoly(P, P1.maxOrder + P2.maxOrder);
    memset(P.coe, 0, sizeof(int) * (P.maxOrder + 1)); // 初始化为0
    for (int i = P1.maxOrder; i >= 0; i--)
        for (int j = P2.maxOrder; j >= 0; j--)
            P.coe[i + j] += P1.coe[i] * P2.coe[j]; // 所有项相乘，并将结果相加到对应次数的项上
    printPoly(P);
    free(P.coe); // 释放内存
}

int main(void)
{
    int p1, p2;
    name = (char *)malloc(sizeof(char) * maxLen);
    scanf("%d%d%s", &p1, &p2, name); // 输入多项式的最大次数和多项式的名字
    newPoly(P1, p1);
    newPoly(P2, p2);
    for (int i = p1; i >= 0; i--)
        scanf("%d", P1.coe + i); // 输入P1多项式各项的系数
    for (int i = p2; i >= 0; i--)
        scanf("%d", P2.coe + i); // 输入P2多项式各项的系数
    polyAddMinus(P1, P2, 1);     // 两个多项式相加并打印结果

    polyAddMinus(P1, P2, 0); // 两个多项式相减并打印结果
    polyMul(P1, P2);         // 两个多项式相乘并打印结果

    free(P1.coe); // 释放内存
    free(P2.coe); // 释放内存
    return 0;
}