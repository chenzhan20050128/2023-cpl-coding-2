#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char *s = (char *)malloc(10010 * sizeof(char));
    while (scanf("%s", s) != EOF)
    {
        int slen = strlen(s);
        printf("%c", toupper(*(s + 0)));
        for (int i = 1; i < slen; i++)
        {
            printf("%c", tolower(*(s + i)));
        }
        printf(" ");
    }
    return 0;
}