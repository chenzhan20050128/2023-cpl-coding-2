#include <stdio.h>
#include <math.h>
#define maxn 1000010
#define int_max 2147483647
int is_sorted(int a[],int alen){
    int min = a[0];
    for (int i = 1;i<=alen-1;i++){
        if (a[i] < min){
            return 0;
        }
        else {
            min = a[i];
        }
    }
    return 1;
}
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // 交换数组元素
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // 更新指针位置
        start++;
        end--;
    }
}
int can_merge(int a[],int b[],int alen,int blen){//从0到n-1
    return ((is_sorted(a)) && (is_sorted(b)) && (a[alen-1] <= b[0]));
}
int numbers[maxn];
int dp[maxn][maxn] = {int_max};//dp[i][j] 是从i到j有序的最少操作次数;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for (int i = 1;i<=maxn;i++){
        for (int j = 1;j<=maxn;j++){

        }
    }

}