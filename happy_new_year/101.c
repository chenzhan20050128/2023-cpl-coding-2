#include <stdio.h>
#include <stdlib.h>

// 比较函数
int compare(const void *a, const void *b)
{
    const int *arrayA = *(const int **)a;
    const int *arrayB = *(const int **)b;
    return arrayA[1] - arrayB[1]; // 根据第二个关键字进行排序
}

int main()
{
    int array[5][2] = {{1, 5}, {3, 2}, {2, 8}, {4, 3}, {5, 1}};
    qsort(array, 5, sizeof(array[0]), compare); // 对二维列表按第二个关键字排序

    // 输出排序结果
    for (int i = 0; i < 5; i++)
    {
        printf("%d %d\n", array[i][0], array[i][1]);
    }

    return 0;
}