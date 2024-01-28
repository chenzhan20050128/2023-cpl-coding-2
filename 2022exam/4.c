#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define b 200
#define maxn 2050 // 200050

typedef struct block
{
    int size;
    char list[b + 5];
    block *next;
} block;
void build_block()
{
    char input[maxn];
    scanf("%s",input);
    int slen = strlen(input);block *pre_block = NULL;

    for (int i = 0;(i+1) * b <= slen;i++){
        block temp;
        for (int j = 0;j<=b-1;j++){
            temp[]
        }
    }

    int flag = 1;
    
    while (flag){
        
        int i = 0;
        while (scanf("%c", temp.list[i]) > 0 && i <= b - 1)
        {
            i++;
        }

        pre_block->next = &temp;
        
    }
    
    
    return;
}
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    getchar();
    build_block();
}