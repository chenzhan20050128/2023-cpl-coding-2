#include<stdio.h>
#include <string.h>
int n;char s[2010];
void fill(char *s, int n) {
    int i, j;
    
    for (i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] == '?' && s[j] != "?") {
            s[i] = s[j];
        } else if (s[i] != "?" && s[j] == "?") {
            s[j] = s[i];
        }
    }
}
int main(){
    
    scanf("%d",&n);
    scanf("%s",&s);
    fill(s,n);
    printf("%s",s);
    return 0;
}