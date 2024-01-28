#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int main()
{
    char **strs = malloc(1000), *readin = calloc(1000, 1000), *dev = malloc(1);
    int num = 0;
    scanf("%s %c", readin, dev);
    *strs = strtok(readin, dev);
    while (*(strs + num))
        *(strs + ++num) = strtok(NULL, dev);
    qsort(strs, num, sizeof strs, cmp);
    for (int i = 0; i < num; i++)
        printf("%s\n", *(strs + i));
    free(readin);
    free(strs);
    free(dev);
    return 0;
}
