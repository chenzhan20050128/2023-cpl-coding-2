/*这段代码是用来实现两个多项式(称为ef[0]和ef[1])的加减乘运算并打印出来。

期间定义了printx函数用以按照规则打印出对应的未知数部分；
printeff函数用以按照规则打印出对应的系数部分。

主程序部分中，首先接收两个多项式的最高次数和未知数的名称；
然后按照从高到低的顺序接收多项式的每一项的系数；
最后分别进行加减乘运算并输出。在实现运算并输出的过程中，
通过对暂存变量(如tmp)的判断来确定是否需要输出，
同时根据当前项在多项式中的位置确定输出格式，
ishigh变量用来记录被输出的最高次幂，当输出了这一项后，
ishigh被置为-1，表示最高次幂已输出；当tmp为0时，表示当前项不需要输出
，i--之后继续循环；当tmp不为0时，说明当前项系数非0并且需要输出，
调用printeff和printx函数输出当前项系数和未知数部分，输出完毕后，
令ishigh=-1，表示最高项已经输出，缩小问题规模；当i==0时，
说明所有项均已考虑完毕，结束循环。
* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 多项式系数
int ef[2][10004];

// 打印x的pwer次幂
void printx(char *x, int pwer)
{
    if (pwer == 0)
        return;
    if (pwer == 1)
    {
        printf("%s", x);
    }
    if (pwer > 1)
    {
        printf("%s^%d", x, pwer);
    }
}

// 打印系数，ishigh判断是否为最高项，islow判断是否为常数项
void printeff(int x, int ishigh, int islow)
{
    if (ishigh) // 为最高项，且系数为1的时候，不打印1
    {
        if (x == 1 || x == -1) // 系数为1和-1的时候，只打印"-"，正号不打印
        {
            printf("-");
        }
        else
        {
            printf("%d", x); // 其他情况直接打印系数
        }
        return;
    }
    if (islow) // 系数为0的时候，直接打印系数
    {
        if (x >= 0)
            printf("+");
        printf("%d", x);
        return;
    }
    {
        if (x >= 0)
            printf("+");
        if (x == 1)
        {
            ;
        }
        else if (x == -1)
        {
            printf("-");
        }
        else
        {
            printf("%d", x);
        }
    }
}

int main() // 主函数
{
    int ps[2]; // 两个多项式最高次幂
    scanf("%d %d", &ps[0], &ps[1]);
    char x[12]; // 多项式变量名称
    scanf(" %s", x);
    for (int j = 0; j <= 1; j++)
    {
        for (int i = 0; i <= ps[j]; i++)
        {
            scanf("%d", &ef[j][ps[j] - i]); // 获取多项式系数
        }
    }
    int mx = ps[0] > ps[1] ? ps[0] : ps[1]; // 获取两个多项式次数的最大值
    int ishigh = mx;
    for (int i = mx; i >= 0; i--)
    {
        int tmp = ef[0][i] + ef[1][i]; // 加法主体
        if (tmp)
        {
            printeff(tmp, (i == ishigh) ? 1 : 0, (i == 0) ? 1 : 0);
            ishigh = -1;
            printx(x, i);
        }
        else
        {
            ishigh--;
        }
    }
    puts("");

    ishigh = mx;
    for (int i = mx; i >= 0; i--)
    {
        int tmp = ef[0][i] - ef[1][i]; // 减法主体
        if (tmp)
        {
            printeff(tmp, (i == ishigh) ? 1 : 0, (i == 0) ? 1 : 0);
            ishigh = -1;
            printx(x, i);
        }
        else
        {
            ishigh--;
        }
    }
    puts("");

    ishigh = ps[0] + ps[1];
    for (int i = ps[0] + ps[1]; i >= 0; i--)
    {
        int tmp = 0;
        for (int j = 0; j <= i && j <= ps[0]; j++)
        {
            if (i - j <= ps[1])
                tmp += ef[0][j] * ef[1][i - j]; // 乘法主体
        }
        if (tmp)
        {
            printeff(tmp, (i == ishigh) ? 1 : 0, (i == 0) ? 1 : 0);
            ishigh = -1;
            printx(x, i);
        }
        else
        {
            ishigh--;
        }
    }
}