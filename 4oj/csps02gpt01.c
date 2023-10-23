#include <stdio.h>
#include <math.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    int v[n - 1];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &v[i]);
    }

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int total_cost = 0;

    for (int i = 0; i < n - 1; i++) {
        int distance = v[i];
        int required_fuel = ceil((double)distance / d);
        int current_cost = required_fuel * a[i];
        total_cost += current_cost;
    }

    printf("%d\n", total_cost);

    return 0;
}