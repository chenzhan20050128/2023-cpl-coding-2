#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d",&n);
    long long ans = pow(2,n) - 1;
    printf("%lld",ans);
    return 0;
}