#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char argu[1010];
int argu_len;
int search(char c)
{
    int pos = 0;
    while (pos < argu_len)
    {
        if (argu[pos] == c)
        {
            return pos;
        }
        pos++;
    }
    if (pos == argu_len)
    {
        return -1;
    }
}
int main()
{
    scanf("%s", &argu);
    argu_len = strlen(argu);
    char program_name[1010] = {'\0'};
    scanf("%s", program_name);
    printf("%s", program_name);
    char command[1010];
    int command_len = 0;
    char ans[1010][1010];
    int ans_top = -1;
    int flag = 1;

    while (scanf("%s", command) > 0)
    {
        // printf("%s\n", command);
        command_len = strlen(command);
        if (command[0] == '-')
        {
            int pos = search(command[1]);
            if (pos == -1)
            {
                printf(": invalid option -- '%c'", command[1]);
                flag = 0;
                break;
            }
            else
            {
                if (argu[pos + 1] == ':')
                {
                    char content[1010];

                    if (scanf("%s", content) <= 0)
                    {
                        printf(": option requires an argument -- '%c'", command[1]);
                        flag = 0;
                        break;
                    }
                    else
                    {
                        ans_top++;
                        ans[ans_top][0] = command[1];
                        ans[ans_top][1] = '=';
                        int content_len = strlen(content);
                        for (int i = 0; i < content_len; i++)
                        {
                            ans[ans_top][2 + i] = content[i];
                        }
                        ans[ans_top][content_len + 2] = '\0';
                    }
                }
                else
                {
                    ans_top++;
                    ans[ans_top][0] = command[1];
                    ans[ans_top][1] = '\0';
                }
            }
        }
        else
        {
        }
    }
    // print
    if (flag)
    {
        for (int i = 0; i <= ans_top; i++)
        {
            printf("\n%s", ans[i]);
        }
    }
    return 0;
}