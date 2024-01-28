#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 250000 // 250000
int main()
{
    int t;
    int slen;
    char init_s[maxn];
    char tran_s[maxn];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &slen);
        getchar();
        scanf("%s", init_s);
        scanf("%s", tran_s);
        int used[100] = {0};
        int flag = 1;
        int i = 0;
        int j = strlen(tran_s) - 1;
        while (i < j && flag)
        {
            if (tran_s[i] != tran_s[j])
            {
                flag = 0;
            }
            else
            {
                i++;
                j--;
            }
        }
        if (flag)
        {
            i = 0;
            j = slen - 1;
            while (i < j)
            {
                if (init_s[i] == '?' && init_s[j] == '?')
                {
                }
                else if (init_s[i] == '?' && init_s[j] != '?')
                {
                    init_s[i] = init_s[j];
                }
                else if (init_s[i] != '?' && init_s[j] == '?')
                {
                    init_s[j] = init_s[i];
                }
                else
                {
                }
                i++;
                j--;
            }
            int ptr_init = 0;
            int ptr_tran = 0;
            while (ptr_init <= (slen + 1) / 2 && flag)
            {
                if (init_s[ptr_init] == '?')
                {
                    int temp = 0;
                    temp = (tran_s[ptr_tran] - '0') * 10 + (tran_s[ptr_tran + 1] - '0');
                    if (used[temp] > 0)
                    {
                        flag = 0;
                    }
                    else
                    {
                        used[temp] += 1;
                        ptr_init += 1;
                        ptr_tran += 2;
                    }
                }
                else
                {
                    ptr_init++;
                    ptr_tran++;
                }
            }
        }
        if (flag == 1)
        {
            printf("Correct.\n");
        }
        else
        {
            printf("Wrong Answer!\n");
        }
    }
    return 0;
}
