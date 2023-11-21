#include <stdio.h>
#include <string.h>
char my_stack[100010]; // change!!!
int main()
{

    int top = -1;
    int q;
    scanf("%d", &q);
    char option[50];
    for (int i = 1; i <= q; i++)
    {
        scanf("%s", &option);
        // printf("%s\n", option);
        if (strcmp(option, "push") == 0)
        {
            char c[10];
            scanf("%s", c);
            top++;
            my_stack[top] = c[0];
        }
        else if (strcmp(option, "pop") == 0)
        {
            if (top == -1)
            {
                printf("Empty\n");
            }
            else
            {
                // printf("%c\n", my_stack[top]);
                top -= 1;
            }
        }
        else if (strcmp(option, "top") == 0)
        {
            if (top == -1)
            {
                printf("Empty\n");
            }
            else
            {
                printf("%c\n", my_stack[top]);
            }
        }
        else if (strcmp(option, "print") == 0)
        {
            if (top == -1)
            {
                printf("Empty\n");
            }
            else
            {
                for (int i = top; i >= 0; i--)
                {
                    printf("| %c |\n", my_stack[i]);
                }
                printf("|===|\n");
            }
        }
    }
    return 0;
}