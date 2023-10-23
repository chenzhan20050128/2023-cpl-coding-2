#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int sta[129] = 0;
char stringlist[1010];
int main(){
    int n;int total = 0;
    scanf("%d",&n);
    getchar();
    for (int i = 1;i <= n;i++){
        scanf("%c",&stringlist[i]);
        if (sta[(int)(stringlist[i])] == 0){
            total ++;
        }
        sta[(int)(stringlist[i])] += 1;
    }



}