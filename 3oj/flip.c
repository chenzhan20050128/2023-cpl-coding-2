#include<stdio.h>
int seq[2010] = {0};
void flip(int i){
    seq[i] = 1 - seq[i];
}
void operate(int i,int n){
    for (int j = i;j < n;j += i){
        flip(j);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1; i<= n;i++){
        operate(i,n);
    }
    for (int i = 1;i<=n;i++){
        if (seq[i] == 1)printf("%d ",i);
    }
}