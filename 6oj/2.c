#include <stdio.h>
#include <math.h>
int choice[110];
int main()
{
    choice[1] = 1;
    choice[2] = 2;
    choice[3] = 3;
    for (int i = 4; i <= 100; i++)
    {
        choice[i] = (choice[i - 2]) + 1 * (choice[i - 1]); // think that the condition of all shuzhe
    }
    int n;
    scanf("%d", &n);
    printf("%d", choice[n]);
    return 0;
}