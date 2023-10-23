#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        sum = sum + i;
        printf("%d ", 2 * i);
    }
    printf("hello");
    return 0;
}