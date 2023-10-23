#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    char a;
    char b;
    scanf("%c %c",&a,&b);
    int sum = 0;
    sum += (int)a - 65;
    sum += (int)b - 65;
    if (sum / 26 > 0){
        printf("%c",(char)((sum / 26) + 65));
    }
    printf("%c",(char)((sum % 26) + 65));
    return 0;
}