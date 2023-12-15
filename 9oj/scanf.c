#include <stdio.h>
#include <string.h>

int main()
{
    char s[5050];
    char s_processed[5050];
    scanf("%s", s);
    int pos = 0;
    int sp_pos = 0;
    int slen = strlen(s);
    while (pos <= slen - 1)
    {
        s_processed[sp_pos] = s[pos];
        if (s[pos] == ';')
        {
            s_processed[sp_pos] = ' ';
            s_processed[sp_pos + 1] = ';';
            s_processed[sp_pos + 2] = ' ';
            pos += 1;
            sp_pos += 3;
        }
        else
        {
            s_processed[sp_pos] = s[pos];
            pos++;
            sp_pos++;
        }
    }
    s_processed[sp_pos + 1] = '\0';
    char stemp[5050];
    printf("%s\n%s\n", s, s_processed);
    char *token = strtok(s_processed, " ");
    while (token != NULL)
    {
        strcpy(stemp, token);
        printf("%s\n", stemp);
        token = strtok(NULL, " ");
    }
    return 0;
}