#include <stdio.h>
#include <math.h>
#include <ctype.h>
// 使用单调栈；
long long area_max;
int t;
int n;
int height[10010];
int right_max[10010];
int right_stack[10010];
int rst_top = -1;
int left_max[10010];
int left_stack[10010];
int lst_top = -1;
long long cal_area(int left_height, int right_height, int width)
{
    // printf("cal_area:%d %d %d %lld\n", left_height, right_height, width, min(left_height, right_height) * width);
    return min(left_height, right_height) * width;
}
int main()
{

    scanf("%d", &t);

    for (int q = 1; q <= t; q++)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &height[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (lst_top == -1)
            {
                lst_top++;
                left_stack[lst_top] = i;
                left_max[i] = -1;
            }
            else if (left_stack[lst_top] < height[i])
            {
            }
            else if (left_stack[lst_top] >= height[i])
            {
            }
        }
    }
    return 0;
}