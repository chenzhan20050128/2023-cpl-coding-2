#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
char str10[30] = {'0'};
int main(){
    scanf("%s",&str10);
    for (int i = 0;i<=29;i++){
        printf("%c",str10[i]);
    }
    printf("\n");
    if (str10 == "0"){
        printf("shi0  ");  
    }
    printf("%s",str10);
    return 0;
}