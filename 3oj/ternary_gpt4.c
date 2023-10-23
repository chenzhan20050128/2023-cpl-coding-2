#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 21

void balance_ternary(int number)
{
    char buf[MAX_LEN], *ptr = buf + MAX_LEN - 1;
    int remainder;
    *ptr = '\0';

    do
    {
        remainder = number % 3;
        number /= 3;
        if (remainder < 0)
        {
            remainder += 3;
            number++;
        }
        *--ptr = "01Z"[remainder];
    } while (number != 0);

    printf("%s\n", ptr);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for (; n > 0; n--)
    {
        char buf[20];
        scanf("%s", buf);

        char *p = buf;
        int is_legal = 1;

        if (*p == '-')
        {
            p++;
        }

        for (; *p != '\0' && is_legal; p++)
        {
            if (!isdigit(*p))
            {
                is_legal = 0;
            }
        }

        if (is_legal)
        {
            int number = atoi(buf);
            balance_ternary(number);
        }
        else
        {
            printf("Radix Error\n");
        }
    }

    return 0;
}
