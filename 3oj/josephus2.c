#include<stdio.h>
#include <stdlib.h>
#include <math.h>

int next[510];
int main(){
    int n;int k;
    scanf("%d %d",&n,&k);
    for (int i = 1;i < n;i++){
        next[i] = i+1;
    }
    next[n] = 1;
    int cur = 1;
    int pre = n;
    while (next[pre] != -1){
        for (int j = 1;j<=k;j++){
            pre = cur;
            cur = next[cur];
        }
        //delete
        next[pre] = next[cur];
        next[cur] = -1;

    }
    printf("%d",pre);
    return 0;
}