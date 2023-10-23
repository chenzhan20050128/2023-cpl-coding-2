#include <stdio.h>
#include <string.h>
#include <math.h>
#define maxn 10010
char test_number[maxn][20];
int score[maxn][2];
int print_sorted_student(char grade,int n){
    
    for (int cnt = 1;cnt <= n;cnt++){//bouble sort;
        int last_same_grade = -1;
        for (int i = 1;i <= n;i++){
            if (test_number[i][0] = grade){
                if (last_same_grade == -1){
                    last_same_grade = i;
                }
                else {
                    if (test_number[i] > test_number[last_same_grade]){
                        int temp0 = score[i][0];
                        int temp1 = score[i][1];
                        score[i][0] = score[last_same_grade][0];
                        score[i][1] = score[last_same_grade][1];
                        score[last_same_grade][0] = temp0;
                        score[last_same_grade][1] = temp1;
                    }
                }
            }
        }
    }
    for (int i = 1;i<=n;i++){
        if (test_number[i][0] = grade){
            printf("%d ",score[])
        }
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);//n:考生人数  m:统计要求的个数. 
    for (int i = 1;i<=n;i++){
        scanf("%s",&test_number[i]);
        scanf("%d",&score[i][0]);
        score[i][1] = i;
    }
}