#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    //printf("%d %s %s\n", strcmp(*(const char **)a, *(const char **)b), *(const char **)a, *(const char **)b);
    return strcmp(*(const char **)a, *(const char **)b);
}

char **strsplit(char *str, char *delim)
{
    char **result = 0;
    int count = 0;
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
        int idx = 0;
        char *token = strtok(str, d);
        while (token)
        {
            *(result + idx++) = strdup(token);
            token = strtok(0, d);
        }
        *(result + idx) = 0;
    }

    return result;
}

int main()
{
    char str[110];
    char delim[2];
    scanf("%s", str);
    scanf("%s", delim);
    char **split_str = strsplit(str, delim);
    int count = 0;
    while (split_str[count] != NULL)
    {
        count++;
    }
    qsort(split_str, count, sizeof(char *), compare);
    for (int i = 0; strlen(split_str[i]) != 0; ++i)
    {
        printf("%s\n", split_str[i]);
        // free(split_str[i]);
    }
    // free(split_str);

    return 0;
}