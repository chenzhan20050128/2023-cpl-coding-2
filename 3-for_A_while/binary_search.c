#include<stdio.h>
int numbers[10010];
bool check(int x){
    
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i= 0;i<=n-1;i++){
        scanf("%d",&numbers[i]);
    }
    int left=0;int right=n-1;
    int mid;
    while (left < right){
        mid = (left + right) / 2;
        if (check(mid)){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    if (left == right){
        printf("")
    }
}