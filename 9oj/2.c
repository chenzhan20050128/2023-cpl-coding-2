#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char s1[1010];
char s2[1010];
int ds1, ds2;
int size;

int s1top = 0;
int s2top = 0;
int s3top = -1;
int s1len;
int s2len;
char s3[2050] = {'\0'};
int cnt;
int flag = 1;

void read()
{
    int fenhao = 0;
    char c;
    c = getchar();
    int temp = 0;
    char strtemp[1010] = {'\0'};
    int strtop = 0;
    while (c != '\n')
    {
        if (c == ';')
        {
            if (fenhao == 0)
            {

                for (int i = 0; i < strtop; i++)
                {
                    s1[i] = strtemp[i];
                }
                s1[strtop] = '\0';
                strtop = 0;
                strtemp[0] = '\0';
                temp = 0;
            }
            else if (fenhao == 1)
            {

                for (int i = 0; i < strtop; i++)
                {
                    s2[i] = strtemp[i];
                }
                s2[strtop] = '\0';
                strtop = 0;
                strtemp[0] = '\0';
                temp = 0;
            }
            else if (fenhao == 2)
            {
                ds1 = temp;
                temp = 0;
            }
            else if (fenhao == 3)
            {
                ds2 = temp;
                temp = 0;
            }
            else if (fenhao == 4)
            {
                size = temp;
                temp = 0;
            }
            fenhao += 1;
            temp = 0;
        }
        else
        {
            if (fenhao == 0)
            {
                strtemp[strtop] = c;
                strtemp[strtop + 1] = '\0';
                strtop++;
                temp = 0;
            }
            else if (fenhao == 1)
            {
                strtemp[strtop] = c;
                strtemp[strtop + 1] = '\0';
                strtop++;
                temp = 0;
            }
            else if (fenhao == 2)
            {
                temp = temp * 10 + (int)c - 48;
            }
            else if (fenhao == 3)
            {
                temp = temp * 10 + (int)c - 48;
            }
            else if (fenhao == 4)
            {
                temp = temp * 10 + (int)c - 48;
            }
        }
        c = getchar();
    }
    size = temp;
}
void interleaveString()
{
    s1top = 0;
    s2top = 0;
    s3top = -1;
    s1len = strlen(s1);
    s2len = strlen(s2);
    flag = 1;
    while (flag)
    {
        if (s3top + 2 >= size)
        {
            flag = 0;
        }
        cnt = 0;
        while (flag && cnt < ds1 && s1top < s1len)
        {
            s3top++;
            s3[s3top] = s1[s1top];
            cnt++;
            if (s3top + 2 >= size)
            {
                flag = 0;
            }
            s1top++;
        }
        if (s1top == s1len)
        {
            while (flag && s2top < s2len)
            {
                s3top++;

                s3[s3top] = s2[s2top];

                if (s3top + 2 >= size)
                {
                    flag = 0;
                }
                s2top++;
            }
        }
        cnt = 0;
        while (flag && cnt < ds2 && s2top < s2len)
        {
            s3top++;

            s3[s3top] = s2[s2top];
            cnt++;
            if (s3top + 2 >= size)
            {
                flag = 0;
            }
            s2top++;
        }

        if (s2top == s2len)
        {
            while (flag && s1top < s1len)
            {
                s3top++;

                s3[s3top] = s1[s1top];

                if (s3top + 2 >= size)
                {
                    flag = 0;
                }
                s1top++;
            }
        }
        if (s3top + 2 > size)
        {
            flag = 0;
        }
        if (s1top == s1len && s2top == s2len)
        {
            break;
        }
    }
    s3[size] = '\0';
    s3[s3top + 1] = '\0';
    printf("%s\n", s3);
}
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    for (int i = 1; i <= t; i++)
    {
        read();
        // printf("%s %s %d %d %d\n", s1, s2, ds1, ds2, size);
        interleaveString();
    }
    return 0;
}