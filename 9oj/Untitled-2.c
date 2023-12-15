#include <stdio.h>

int main()
{
    char mystring[10] = {"qwert\nyuop"};
    for (int i = 0; i <= 50; i++)
    {
        printf("%c", mystring[i]);
    }
    return 0;
}