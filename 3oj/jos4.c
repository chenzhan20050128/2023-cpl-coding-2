#include <stdio.h>
#include <stdbool.h>
int josephusSurvivor(int n, int k) {
    bool alive[n];
    for (int i = 0; i < n; i++) {
        alive[i] = true;  // 初始化每个人都为存活状态
    }

    int remaining = n;  // 剩余存活的人数
    int current = 0;   // 当前报数的人的索引

    while (remaining > 1) {
        int count = 0;  // 当前报数的数目
        while (count < k) {
            if (alive[current]) {
                count++;
            }
            current = (current + 1) % n;
        }

        // 淘汰报出 k 的人
        alive[(current - 1 + n) % n] = false;  // 上一个报数的人淘汰
        remaining--;
    }

    // 找到最后一个存活的人的编号
    int survivor;
    for (int i = 0; i < n; i++) {
        if (alive[i]) {
            survivor = i + 1;  // 编号从 1 开始
            break;
        }
    }

    return survivor;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int lastSurvivor = josephusSurvivor(n, k);
    printf("%d\n", lastSurvivor);

    return 0;
}
