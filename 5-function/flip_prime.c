#include <stdio.h>
#include <math.h>

// 判断一个数是否是质数
int is_prime(int x)
{
    // 如果输入的数是0或者1，则不是质数
    if (x == 0 || x == 1)
    {
        return 0;
    }
    // 从2开始，遍历到x的平方根，如果x能被i整除，则不是质数
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    // 如果遍历完没有发现可以整除x的数，则x是质数
    return 1;
}

// 将一个数转换为反转数
int flip_num(int num)
{
    int result = 0;
    // 从个位开始，每次将个位数字添加到结果中
    while (num > 0)
    {
        result = result * 10 + (num % 10);
        num = num / 10;
    }
    return result;
}

int main()
{
    // 读取输入的数字
    int ceil_num;
    int cnt = 0;
    scanf("%d", &ceil_num);
    // 遍历2到ceil_num的数字，如果该数字是质数，并且它的反转数也是质数，则cnt加1
    for (int i = 2; i <= ceil_num; i++)
    {
        if (is_prime(i) && is_prime(flip_num(i)))
        {
            cnt++;
        }
    }
    // 输出cnt
    printf("%d", cnt);
    return 0;
}