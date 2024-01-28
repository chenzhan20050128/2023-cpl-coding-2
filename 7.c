#include <stdio.h>
#include <string.h>

char str[2050][50]; // 改为二维数组
int num[2050];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    getchar(); // 加上此行是吸收多余的换行符
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str[i]);
        scanf("%d", &num[i]);
        getchar(); // 加上此行是吸收多余的换行符
    }
    char temp[5 * 10000 + 50];
    for (int i = 1; i <= k; i++)
    {
        int pos = 0;
        while ((temp[pos] = getchar()) != '\n') // 使用 getchar 直接赋值
        {
            // printf("%c", temp[pos]);
            pos++;
        }
        temp[pos] = '\0';
        int slen = strlen(temp);
        // printf("%s", temp);
        for (int j = 0; j < slen; j++)
        {
            if (temp[j] == '{')
            {
                j++;
                char from[50]; // 长度应与str数组的列数一致
                int top = 0;
                while (temp[j] != '}')
                {
                    from[top++] = temp[j++];
                }
                from[top] = '\0'; // 不要忘记在字符串末尾添加结束符
                for (int k = 1; k <= n; k++)
                {
                    if (strcmp(str[k], from) == 0)
                    {
                        printf("%d", num[k]); // 打印 num[k] 而不是 num[i]
                        break;
                    }
                }
            }
            else
            {
                printf("%c", temp[j]);
            }
        }
        printf("\n");
    }
    return 0;
}