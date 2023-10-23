#include<stdio.h>
#include <math.h>

int main(){
    int max = 0;
    scanf("%d",&max);
    for (int number = 2; number <= max;number++){
        int is_prime = 1;

        for (int factor = 2;factor*factor <= number;factor ++){
            if(number % factor == 0){
                is_prime = 0;
                break;
            }
        }
        if (is_prime == 1){
            printf("%d ",number);
        }


    }
    return 0;

}