#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    scanf("%d", &a);
    for (int i = 0; i <= 100; i++)
    {
        if ((int)(10 * (sqrt(i))) >= a)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
