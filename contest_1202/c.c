#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 100000007

typedef struct {
    char bracket;
    int weight;
} Bracket;

Bracket stack[100000];

void push(int *top, int value) {
    stack[++(*top)].weight = value;
}

int pop(int *top) {
    return stack[(*top)--].weight;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int k = 0; k < n; k++) {
        char s[100005];
        scanf("%s", s);

        int len = strlen(s);
        int top = -1;
        push(&top, 1);

        int result = 0;

        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                push(&top, 0);
            } else {
                if (top >= 1) {
                    int w = pop(&top) * pop(&top);
                    push(&top, w);
                } else {
                    top = 0;
                    i = len;
                }
            }
            result += stack[top].weight;
            result %= MOD;
        }

        printf("%d\n", result);
    }

    return 0;
}
