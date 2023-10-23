#include <stdio.h>
#include <ctype.h>

void print_histogram(char c, int count) {
    for (int i = 0; i < count; i++) {
        printf("=");
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d\n", &n);

    char str[1001];
    fgets(str, sizeof(str), stdin);

    int count[52] = {0};

    for (int i = 0; i < n; i++) {
        char c = str[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                count[c - 'A' + 26]++;
            } else {
                count[c - 'a']++;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        char lowercase_c = 'a' + i;
        char uppercase_c = 'A' + i;
        int lowercase_count = count[i];
        int uppercase_count = count[i + 26];
        if (lowercase_count > 0 || uppercase_count > 0) {
            print_histogram(lowercase_c, lowercase_count);
            print_histogram(uppercase_c, uppercase_count);
            printf("--\n");
        }
    }

    return 0;
}