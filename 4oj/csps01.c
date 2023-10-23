#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int alive[1010] = {1};
int main()
{
    int n;
    scanf("%d", &n);
    int remain = n;
    int ndie = -1;
    int count = 1;//第i天;

    while (remain > 0)
    {
        int i = 1;
        int cnt = 0;
        while (i <= n)
        {
            if (alive[i] == 1)
            {
                cnt++;
            }
            if (cnt == 2){
                alive[i] = 0;
                remain -= 1;
                if (i == n){
                    ndie = count; 
                }
                cnt = 0;
            }
            i++;
        }
        count += 1;
        printf("%d",count);
    }
    printf("%d %d",count,ndie);
    return 0;
}