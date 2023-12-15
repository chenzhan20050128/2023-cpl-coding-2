#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char ans[10010];
int ans_top = -1;

int is_reserved(char *thestring)
{
    char table[16][10] = {"const", "int", "float", "double", "long", "static", "void", "char", "extern", "return", "break", "enum", "struct", "typedef", "union", "goto"};
    for (int i = 0; i <= 15; i++)
    {
        if (strcmp(table[i], thestring) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int is_operator(char *thestring)
{
    char *stringArray[11]; // 指向一个字符串的数组

    char string0[] = "+";
    char string1[] = "-";
    char string2[] = "*";
    char string3[] = "/";
    char string4[] = "=";
    char string5[] = "==";
    char string6[] = "!=";
    char string7[] = ">=";
    char string8[] = "<=";
    char string9[] = ">";
    char string10[] = "<";
    stringArray[0] = string0;
    stringArray[1] = string1;
    stringArray[2] = string2;
    stringArray[3] = string3;
    stringArray[4] = string4;
    stringArray[5] = string5;
    stringArray[6] = string6;
    stringArray[7] = string7;
    stringArray[8] = string8;
    stringArray[9] = string9;
    stringArray[10] = string10;
    for (int i = 0; i <= 10; i++)
    {
        if (strcmp(stringArray[i], thestring) == 0)
        {
            // printf("is_operator:%s\n",stringArray[i]);
            return 1;
        }
        // printf("is_not_operator:%s\n",stringArray[i]);
    }
    return 0;
}
int is_variable(char *thestring)
{
    if (isdigit(thestring[0]))
    {
        return 0;
    }
    int thestring_len = strlen(thestring);
    for (int i = 0; i < thestring_len; i++)
    {
        if (isdigit(thestring[i]) || isalpha(thestring[i]) || thestring[i] == '_')
        {
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int is_integer(char *thestring)
{
    if (thestring[0] == '-')
    {
        return 0;
    }
    else
    {
        int thestring_len = strlen(thestring);
        int number_exist = 0;
        for (int i = 0; i < thestring_len; i++)
        {
            if (isdigit(thestring[i]))
            {
                number_exist = 1;
            }
            else
            {
                return 0;
            }
        }
        if (number_exist == 1)
        {
            return 1;
        }
    }
}
int is_float(char *thestring)
{
    int thestring_len = strlen(thestring);
    int float_cnt = 0;
    int number_exist = 0;
    for (int i = 0; i < thestring_len; i++)
    {
        if (isdigit(thestring[i]))
        {
            number_exist = 1;
        }
        else if (thestring[i] == '.')
        {
            float_cnt += 1;

            if (float_cnt >= 2)
            {
                return -1;
            }
        }
        else if (isalpha(thestring[i]))
        {

            return -1;
        }
    }
    if (float_cnt == 1 && number_exist == 1)
    {
        return 1;
    }
    else
    {

        return -1;
    }
}

void load_string(char *thestring)
{
    int thestring_len = strlen(thestring);
    for (int i = 0; i < thestring_len; i++)
    {
        ans_top++;
        ans[ans_top] = thestring[i];
    }
    return;
}
int process(char *mystring, int start, int end)
{
    char newstring[1010];
    // memcpy(mystring + start, newstring, end - start + 1);
    for (int i = start; i <= end; i++)
    {
        newstring[i - start] = mystring[i];
    }
    newstring[end - start + 1] = '\0';
    // printf("%s\n",newstring);
    // printf("now_ans:%s\n", ans);
    if (is_float(newstring) == 1)
    {
        load_string("float ");
        return 1;
    }
    else if (is_integer(newstring) == 1)
    {
        load_string("integer ");
        return 1;
    }
    else if (is_operator(newstring) == 1)
    {
        load_string("operator ");
        return 1;
    }
    else if (is_reserved(newstring) == 1)
    {
        load_string("reserved ");
        return 1;
    }
    else if (is_variable(newstring) == 1)
    {
        load_string("variable ");
        return 1;
    }
    else
    {
        // printf("ce: %s\n", newstring);
        return 0;
    }
}

int main()
{
    int flag = 1;
    char s[5050];
    char s_processed[5050];
    int position;
    // int debug_cnt = 0;
    while (scanf("%s", s) > 0 && flag)
    {
        // debug_cnt += 1;
        //  printf("%s\n", s);
        //   todo : find position.
        int find_flag = 0;
        int slen = strlen(s);
        int pos = 0;
        int sp_pos = 0;
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
        char *token = strtok(s_processed, " ");
        while (token != NULL)
        {
            strcpy(stemp, token);
            printf("%s\n", stemp); // debug;
            int stemplen = strlen(stemp);
            if (stemplen == 1 && stemp[0] == ';')
            {
                ans[ans_top] = '\n';
                ans[ans_top + 1] = '\0';
            }
            else
            {
                for (int i = 0; i < stemplen; i++)
                {
                    if (s[i] == ';')
                    {
                        position = i;
                        find_flag = 1;
                        break;
                    }
                }
                if (find_flag == 0)
                    flag = process(stemp, 0, strlen(stemp) - 1);
                else
                {
                    if (0 <= position - 1)
                    {
                        flag = process(stemp, 0, position - 1);
                    }

                    if (flag == 1)
                    {
                        ans[ans_top] = '\n';
                        ans[ans_top + 1] = '\0';
                        if (position + 1 < strlen(stemp) - 1)
                        {
                            process(stemp, position + 1, strlen(stemp) - 1);
                        }
                    }
                }
            }

            token = strtok(NULL, " ");
        }
    }
    // printf("finished:\n");
    if (flag == 1)
    {
        for (int i = 0; i <= ans_top - 1; i++)
        {
            printf("%c", ans[i]);
        }
    }
    else
    {
        printf("Compile Error");
    }
    return 0;
}