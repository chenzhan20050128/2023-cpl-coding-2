#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    char s[1010];
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int now_x = a;
    int now_y = b;
    int now_z = c;
    scanf("%s", &s);
    int slen = strlen(s);
    int point_x = 0;
    int point_y = 0;
    for (int i = 0; i < slen; i++)
    {
        if (s[i] == 'W')
        {
            point_x -= now_z;
            swap(&now_x, &now_z);
        }
        else if (s[i] == 'S')
        {
            point_x += now_x;
            swap(&now_x, &now_z);
        }
        else if (s[i] == 'A')
        {
            point_y -= now_z;
            swap(&now_y, &now_z);
        }
        else if (s[i] == 'D')
        {
            point_y += now_y;
            swap(&now_y, &now_z);
        }
    }
    printf("%d %d %d %d", point_x, point_x + now_x, point_y, point_y + now_y);
    return 0;
}