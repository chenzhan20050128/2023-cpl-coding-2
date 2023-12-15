#include <stdio.h>
#include <math.h>
#include <ctype.h>
long long area_max;
int t;
int n;
int height[10010];
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
long long cal_area(int left_height, int right_height, int width)
{
    // printf("cal_area:%d %d %d %lld\n", left_height, right_height, width, min(left_height, right_height) * width);
    return min(left_height, right_height) * width;
}
void process(int left, int right)
{
    if (left >= right)
    {
        return;
    }
    area_max = max(area_max, cal_area(height[left], height[right], right - left));
    if (height[left + 1] > height[left] && height[right - 1] > height[right])
    {
        area_max = max(area_max, cal_area(height[left + 1], height[right], right - left - 1));
        area_max = max(area_max, cal_area(height[left], height[right - 1], right - left - 1));
        left += 1;
        right -= 1;
        process(left, right);
    }
    else if (height[left + 1] > height[left])
    {
        area_max = max(area_max, cal_area(height[left + 1], height[right], right - left - 1));
        left += 1;
        process(left, right);
    }
    else if (height[right - 1] > height[right])
    {
        area_max = max(area_max, cal_area(height[left], height[right - 1], right - left - 1));
        right -= 1;
        process(left, right);
    }
    else
    {
        area_max = max(area_max, cal_area(height[left + 1], height[right], right - left - 1));
        area_max = max(area_max, cal_area(height[left], height[right - 1], right - left - 1));
        left += 1;
        right -= 1;
        process(left, right);
    }
    return;
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
        int left = 1;
        int right = n;
        area_max = cal_area(height[left], height[right], right - left);
        process(left, right);
        printf("%lld\n", area_max);
    }
    return 0;
}