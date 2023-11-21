#include<stdio.h>
#include <stdlib.h>
int v[10010][2];

int compare(const void* a, const void* b) {
    const int* arr1 = *(const int**)a;
    const int* arr2 = *(const int**)b;
    return arr1[0] - arr2[0];
}
int main(){
    int n,l;
    scanf("%d %d",&n,&l);
    for (int i = 1;i<=n;i++){
        scanf("%d",v[i][0]);
    }
    for (int i = 1;i<=n;i++){
        scanf("%d",v[i][1]);
    }
    

}