#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int L, K;
    scanf("%d %d", &L, &K);
    
    char N[1001];
    scanf("%s", N);
    
    int i, j;
    int found = 0;
    
    for (i = 0; i <= L - K; i++) {
        int num = 0;
        
        for (j = i; j < i + K; j++) {
            num = num * 10 + (N[j] - '0');
        }
        
        if (isPrime(num)) {
            printf("%d\n", num);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("404\n");
    }
    
    return 0;
}