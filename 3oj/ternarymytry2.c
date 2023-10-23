#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
char str10[30] = {'0'};
int int3[30] = {0};
char str3[30] = {'0'};
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int i = 0;i<=29;i++){
            str10[i] = '0';
            int3[i] = 0;
            str3[30] = '0';
        }
        scanf("%s", &str10);
        if (str10[0] == '0'){
            printf("0");
            printf("\n");
            continue;
        }
        int legal = 1;
        int rever = 1;
        int num = 0;
        for (int i = 0; i < strlen(str10); i++)
        {
            if ((isdigit(str10[i])) || str10[i] == '-')
            {
                if (i == 0 && str10[i] == '-')
                {
                    rever = -1;
                }
                num = 10 * num + (str10[i] - '0');
                if (rever == -1 && i == 0)
                {
                    num = 0;
                }
            }
            else
            {
                legal = 0;
            }
        }
        // printf("%d", num);
        int pos = 0;
        while (num > 0)
        {
            int3[pos] = (num % 3);
            num = num / 3;
            pos++;
        }
        int forward = 0;
        for (int i = 0; i <= 25; i++)
        {
            int3[i] = int3[i] + forward;
            forward = 0;
            if (int3[i] == 2)
            {
                forward = 1;
                str3[i] = 'Z';
            }
            else if (int3[i] == 3)
            {
                forward = 1;
                str3[i] = '0';
            }
            else if (int3[i] == 0)
            {
                str3[i] = '0';
            }
            else if (int3[i] == 1)
            {
                str3[i] = '1';
            }
            else
            {
                legal = 0;
            }
        }
        //printf("%s %s ", str10, str3);
        if (rever == -1)
        {
            for (int i = 0; i <= 25; i++)
            {
                if (str3[i] == '1')
                {
                    str3[i] = 'Z';
                }
                else if (str3[i] == 'Z')
                {
                    str3[i] = '1';
                }
            }
        }
        //printf("%s %s \n", str10, str3);
        if (legal == 1)
        {
            int could_print_0 = 0;
            for (int i = 25; i >= 0; i--)
            {
                if (could_print_0 == 1 && str3[i] == '0')
                {
                    printf("%c", '0');
                }
                else if (str3[i] != '0')
                {
                    could_print_0 = 1;
                    printf("%c", str3[i]);
                }
            }
        }
        else
        {
            printf("Radix Error");
        }
        printf("\n");
    }
    return 0;
}
