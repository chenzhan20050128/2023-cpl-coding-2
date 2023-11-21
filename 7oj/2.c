#include <stdio.h>
#include <string.h>
#define maxn 100010 // 100010
char s[maxn];
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%s", &s);
        char my_stack[maxn];
        int top = -1;
        int flag = 1;
        int slen = strlen(s);
        for (int q = 0; q <= slen; q++)
        {
            my_stack[q] = '\0';
        }
        for (int j = 0; j <= slen; j++)
        {
            if (s[j] == '(')
            {
                top++;
                my_stack[top] = '(';
            }
            else if (s[j] == '[')
            {
                top++;
                my_stack[top] = '[';
            }
            else if (s[j] == '{')
            {
                top++;
                my_stack[top] = '{';
            }
            else if (s[j] == ')')
            {
                if (my_stack[top] == '(')
                {
                    my_stack[top] = '\0';
                    top--;
                }
                else
                {
                    flag = 0;
                    continue;
                }
            }
            else if (s[j] == ']')
            {
                if (my_stack[top] == '[')
                {
                    my_stack[top] = '\0';
                    top--;
                }
                else
                {
                    flag = 0;
                    continue;
                }
            }
            else if (s[j] == '}')
            {
                if (my_stack[top] == '{')
                {
                    my_stack[top] = '\0';
                    top--;
                }
                else
                {
                    flag = 0;
                    continue;
                }
            }
        }
        if (top > -1)
        {
            flag = 0;
        }
        if (flag)
        {
            printf("True\n");
        }
        else
        {
            printf("False\n");
        }
    }
}