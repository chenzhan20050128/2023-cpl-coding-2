#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int factor[10010];
int is_beauty(int x){
    if (x == 0 || x == 1){
        return 0;
    }
    int cnt = 0;
    for (int i = 1;i<=(x / 2);i++){
        if(x % i == 0){
            cnt++;
            factor[cnt] = i;
        }
    }
    cnt ++;
    factor[cnt] = x;
    if (cnt < 4){
        return 0;
    }
    for (int a = 1;a <= cnt;a++){
        for (int b = 1;b <= cnt;b ++){
            for (int c = 1;c <= cnt;c++){
                for (int d = 1;d <= cnt;d++){
                    if (a != b && b != c && c != d && a != c && a != d && b != d){
                        int sum = 0;
                        sum += factor[a];
                        sum += factor[b];
                        sum += factor[c];
                        sum += factor[d];
                        if (x == sum){
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int main(){
    int k;
    scanf("%d",&k);
    int temp;
    for (int i = 1;i<=k;i++){
        scanf("%d",&temp);
        if (is_beauty(temp)){
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}