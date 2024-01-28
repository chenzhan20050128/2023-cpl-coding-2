#include <stdio.h>
#include <string.h>

// 这两个数组用来存储每个多项式阶的系数
int tempa[10010], tempb[10010];
int a[10010], b[10010], c[20020];

int main()
{
    int p1, p2, len;
    char s[11];
    // 获得输入
    scanf("%d%d", &p1, &p2);
    getchar();
    scanf("%s", s);
    // 获取第一个多项式的系数
    for (int i = p1; i >= 0; i--)
    {
        scanf("%d", &tempa[i]);
    }
    // 获得第二个多项式的系数
    for (int i = p2; i >= 0; i--)
    {
        scanf("%d", &tempb[i]);
    }
    // 对系数进行添加和减法，并重新分配它们
    for (int i = 0; i <= p2; i++)
    {
        a[i] = tempa[i] + tempb[i];
        b[i] = tempa[i] - tempb[i];
    }
    for (int i = 0; i <= p1; i++)
    {
        for (int j = 0; j <= p2; j++)
        {
            c[i + j] = tempa[i] * tempb[j];
        }
    }
    // print add;
    int firstflag = 0;
    for (int i = p1; i >= 0; i--)
    {
        if (a[i] > 0)
        {
            if (firstflag == 0)
            {
                firstflag = 1;
                if (a[i] == 1)
                {
                    printf("%s^%d", s, i);
                }
                else
                {
                    printf("%d%s^%d", a[i], s, i);
                }
            }
            else
            {
                if (a[i] == 1)
                {
                    printf("+%s^%d", s, i);
                }
                else
                {
                    printf("+%d%s^%d", a[i], s, i);
                }
            }
        }
        else if (a[i] == 0)
        {
            // no print;
        }
        else if (a[i] < 0)
        {
            if (firstflag == 0)
            {
                firstflag = 1;
            }
            if (a[i] == -1)
            {
                printf("%s^%d", s, i);
            }
            else
            {
                printf("%d%s^%d", a[i], s, i);
            }
        }
    }

    printf("\n");

    // print minus;
    firstflag = 0;
    for (int i = p2; i >= 0; i--)
    {
        if (b[i] > 0)
        {
            if (firstflag == 0)
            {
                firstflag = 1;
                if (b[i] == 1)
                {
                    printf("%s^%d", s, i);
                }
                else
                {
                    printf("%d%s^%d", b[i], s, i);
                }
            }
            else
            {
                if (b[i] == 1)
                {
                    printf("+%s^%d", s, i);
                }
                else
                {
                    printf("+%d%s^%d", b[i], s, i);
                }
            }
        }
        else if (b[i] == 0)
        {
            // no print;
        }
        else if (b[i] < 0)
        {
            if (firstflag == 0)
            {
                firstflag = 1;
            }
            if (b[i] == -1)
            {
                printf("%s^%d", s, i);
            }
            else
            {
                printf("%d%s^%d", b[i], s, i);
            }
        }
    }

    printf("\n");

    // print product
    firstflag = 0;
    for (int i = p1 + p2; i >= 0; i--)
    {
        if (c[i] > 0)
        {
            if (firstflag == 0)
            {
                firstflag = 1;
                if (b[i] == 1)
                {
                    printf("%s^%d", s, i);
                }
                else
                {
                    printf("%d%s^%d", c[i], s, i);
                }
            }
            else
            {
                if (c[i] == 1)
                {
                    printf("+%s^%d", s, i);
                }
                else
                {
                    printf("+%d%s^%d", b[i], s, i);
                }
            }
        }
        else if (c[i] == 0)
        {
            // no print;
        }
        else if (c[i] < 0)
        {
            if (firstflag == 0)
            {
                firstflag = 1;
            }
            if (c[i] == -1)
            {
                printf("%s^%d", s, i);
            }
            else
            {
                printf("%d%s^%d", b[i], s, i);
            }
        }
    }

    return 0;
}