#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

char **strsplit(char *str, char *delim)
{
    char **result = 0;
    size_t count = 0;
    char *tmp = str;
    char *last_comma = 0;
    char d[2];
    d[0] = *delim;
    d[1] = 0;

    while (*tmp)
    {
        if (*delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (str + strlen(str) - 1);
    count++;

    result = malloc(sizeof(char *) * count);

    if (result)
    {
        size_t i = 0;
        char *token = strtok(str, d);
        while (token)
        {
            result[i++] = token;
            token = strtok(0, d);
        }
    }

    return result;
}

int main()
{
    char str[110];
    char delim[2];
    scanf("%s\n%s", str, delim);
    // scanf("%s", delim);

    char **split_str = strsplit(str, delim);

    int count = 0;
    while (split_str[count] != NULL)
    {
        count++;
    }

    qsort(split_str, count, sizeof(char *), compare);

    for (int i = 0; i < count; ++i)
    {
        printf("%s\n", split_str[i]);
    }

    for (int i = 0; i < count; ++i)
    {
        free(split_str[i]); // 释放每个分割后的字符串
    }
    free(split_str); // 释放字符串数组本身

    return 0;
}