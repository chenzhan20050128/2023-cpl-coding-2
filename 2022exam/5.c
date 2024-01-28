#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define maxn 2020 // 200020
int up(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}
int down(const void *a, const void *b)
{
    return *((int *)b) - *((int *)a);
}
int *merge(int a[], int b[], int cmp(const void *, const void *))
{
    int *c = (int *)malloc(maxn * 2 * sizeof(int));
    int alen = sizeof(a) / sizeof(a[0]);
    int blen = sizeof(b) / sizeof(b[0]);
    int *aptr = a;
    int *bptr = b;
    int *cptr = c;
    while (aptr < a + alen && bptr < b + blen)
    {
        if (cmp(aptr, bptr) > 0)
        {
            *cptr = *bptr;
            bptr++;
            cptr++;
        }
        else
        {
            *cptr = *aptr;
            aptr++;
            cptr++;
        }
    }
    if (aptr < a + alen)
    {
        while (aptr < a + alen)
        {
            *cptr = *aptr;
            aptr++;
            cptr++;
        }
    }
    else
    {
        while (bptr < b + blen)
        {
            *cptr = *bptr;
            bptr++;
            cptr++;
        }
    }
    return c;
}
int find_big_pos(int list[], int size)
{
    for (int i = 1; i <= size - 1; i++)
    {
        if (list[i] > list[i - 1] && list[i] > list[i + 1])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n,m;int num1[maxn];int num2[maxn];
    scanf("%d",&n);
    for (int i = 1;i<=n;i++){
        scanf("%d",num1[i]);
    }
    scanf("%d",&m);
    for (int i = 1;i<=m;i++){
        scanf("%d",num2[i]);
    }
    int num1pos = find_big_pos(num1,n);
    int num2pos = find_big_pos(num2,m);

    int num1temp[maxn];
    int num2temp[maxn];
    

}
