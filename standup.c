#include <stdio.h>


int val[100010];

int main() {
	int n;int ans = 0;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		scanf("%d", &val[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		if ((i - val[i - 1]) > ans)
			ans = (i - val[i - 1]);
		val[i] += val[i - 1];
	}
	printf("%d\n", ans);
	return 0;
}