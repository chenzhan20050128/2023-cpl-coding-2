#include<stdio.h>
#include <stdlib.h>
int temp;
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1;i<=n;i++){
        int m;
        scanf("%d",&m);
        int maxnum = 0;
        for (int j = 1;j <=m-1;j++){
            scanf("%d",&temp);
            if (temp > maxnum){
                maxnum = temp;
            } 
        }
        scanf("%d",&temp);
        if (maxnum <= temp){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }

    }
    return 0;
}