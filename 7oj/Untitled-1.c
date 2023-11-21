#include <stdio.h>
int num_bigger(int num)
{
    num = num - 1;
    int result = 0;
    while (num > 0)
    {
        result += 1;
        num /= 2;
    }
    return result;
}
int main()
{
    int num;
    scanf("%d", &num);
    printf("%d", num_bigger(num));
}