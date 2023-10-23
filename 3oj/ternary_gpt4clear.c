#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 输出错误信息并返回
void printErrorAndReturn() {
    printf("Radix Error\n");
    return;
}

// 判断输入的字符串是否为合法的十进制数字
int isValidNumber(char* number) {
    int length = strlen(number);
    for (int i=0; i<length; i++) {
        if (!isdigit(number[i]) && number[i]!='-' && number[i]!='Z') {
            return 0;
        }
    }
    return 1;
}

// 将十进制数字转换为平衡三进制数字
void decimalToBalancedTernary(int decNumber) {
    int digits[22], index = 0;
    while (decNumber != 0) {
        int remainder = decNumber % 3;
        decNumber = decNumber / 3;
        if (remainder < 0) {
            remainder += 3;
            decNumber++;
        }
        digits[index++] = remainder;
    }
    if (index == 0) {
        printf("0\n");
    }
    else {
        for (int i=index-1; i>=0; i--) {
            if (digits[i] == 2) {
                printf("Z");
            }
            else {
                printf("%d", digits[i]);
            }
        }
        printf("\n");
    }
    return;
}

// 主函数
int main() {
    int n;
    scanf("%d", &n);
    while (n-- > 0) {
        char s[16];
        scanf("%s", s);
        if (isValidNumber(s)) {
            int number = atoi(s);
            decimalToBalancedTernary(number);
        }
        else {
            printErrorAndReturn();
        }
    }
    return 0;
}
