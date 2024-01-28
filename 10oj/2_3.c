#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 比较函数，用于 qsort 排序
int compare(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

// 分割字符串函数
char **strsplit(char *str, char *delim)
{
    char **result = NULL;
    int count = 0;
    char *token = strtok(str, delim); // 初始分割

    // 循环分割直到 str 为空
    while (token != NULL)
    {
        result = realloc(result, (count + 1) * sizeof(char *));
        result[count] = token;
        count++;
        token = strtok(NULL, delim);
    }

    // 添加一个 NULL，作为数组的结束标志
    result = realloc(result, (count + 1) * sizeof(char *));
    result[count] = NULL;

    return result;
}

int main()
{
    char str[1000];
    char delim[2];

    // 读取输入字符串和分割字符
    fgets(str, sizeof(str), stdin);
    fgets(delim, sizeof(delim), stdin);

    // 移除输入字符串中的换行符
    str[strcspn(str, "\n")] = 0;

    // 分割字符串
    char **result = strsplit(str, delim);

    // 统计分割后的字符串数量
    int count = 0;
    while (result[count] != NULL)
    {
        count++;
    }

    // 使用快速排序对分割后的字符串进行字典排序
    qsort(result, count, sizeof(char *), compare);

    // 输出排序后的结果
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", result[i]);
    }

    // 释放内存
    free(result);

    return 0;
}